
#include "TSystem.h"
#include "TROOT.h"
#include "Tfile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TClonesArray.h"
#include "TBranch.h"
#include "TLorentzVector.h"
#include "TParameter.h"
#include <iostream>
#include <cmath>
#include <TMath.h>
#include <exception>

using namespace std;

int main(int argc, const char** argv)
{
    const char *defaults[6] = {"readPythiaTree","test.root","in"};
    if ( argc==1 ) {
        argv=defaults;
        argc=3;
    }
    TString InFileName = argv[1];
    cout<<"In file is "<<InFileName.Data()<<endl;
    
    TString OutFileName = argv[2];
    cout<<"Out file is "<<OutFileName.Data()<<endl;
    
    TFile *_file0 = TFile::Open(InFileName); //read tree
    TTree* tree = (TTree*)gROOT->FindObject("tree");
    
    //read collections
    TClonesArray *HardPartons = new TClonesArray("TLorentzVector");
    TBranch* bHardPartons = tree->GetBranch("HardPartons");
    bHardPartons->SetAddress(&HardPartons);
    TClonesArray *HardPartonNames = new TClonesArray("TParameter<int>");
    TBranch* bHardPartonNames = tree->GetBranch("HardPartonNames");
    bHardPartonNames->SetAddress(&HardPartonNames);
    TClonesArray *particles = new TClonesArray("TLorentzVector");
    TBranch* bparticles = tree->GetBranch("Particles");
    bparticles->SetAddress(&particles);
    TClonesArray *Jets = new TClonesArray("TLorentzVector");
    TBranch* bJets = tree->GetBranch("jets_R020_ptmin0");
    bJets->SetAddress(&Jets);
    
    //First create the histograms that will be filled with >> command
    TString histname("hHardPartonspT");
    TH1F* hHardPartonspT = new TH1F(histname,histname,16,3,7);
    histname.Prepend("sqrt(HardPartons.fP.fX*HardPartons.fP.fX+HardPartons.fP.fY*HardPartons.fP.fY)>>");
    tree->Draw(histname);
    histname = "hHardPartonsName";
    TH1F* hHardPartonsName = new TH1F(histname,histname,40,-9.5,30.5);
    histname.Prepend("HardPartonNames.fVal>>");
    tree->Draw(histname);
    
    //Next book the histograms that will be filled event by event
    histname = "hParticlepT";
    TH1F* hParticlepT = new TH1F(histname,histname,20,-5,15);
    histname = "hParticleEtaPhi";
    TH2F* hParticleEtaPhi = new TH2F(histname,histname,100,-1,1,100,-6.2,6.2);
    histname= "hParticlesPhiCount";
    TH1F* hParticlesPhiCount= new TH1F(histname,histname,160,-4,4);
    histname="hParticlesEtaCount";
    TH1F* hParticlesEtaCount= new TH1F(histname,histname,80,-2,2);

    Int_t entries = tree->GetEntries();
    //Double_t trigmin = 6.0;
    //Double_t trigmax = 10.0;
    Double_t doublepi= 2*TMath::Pi();
    Double_t pi= TMath::Pi();
    Int_t binsize= 50;
    TH1F *photonpT= new TH1F("photonpT","photonpT",binsize,0,50);
    TH2F *xjghist= new TH2F("xjghist","xjghist",binsize,0,25,binsize,0,2);
    xjghist->SetXTitle("jet pt");
    xjghist->SetYTitle("xjg");
    TH2F *xjgjet= new TH2F("xjgjet","xjgjet",120,0,60,binsize,0,2);
    xjgjet->SetXTitle("jet pt");
    xjgjet->SetYTitle("xjg");
    TH2F *xjgjetall= new TH2F("xjgjetall","xjgjetall",120,0,60,binsize,0,2);
    xjgjetall->SetXTitle("jet pt");
    xjgjetall->SetYTitle("xjg");
    TH2F *gammaloc= new TH2F("gammaloc","gammaloc",50,-1,1,50,-1,doublepi-1);
    gammaloc->SetXTitle("eta");
    gammaloc->SetYTitle("phi");
    TH2F *partloc= new TH2F("partloc","partloc",50,-1,1,50,-1,doublepi-1);
    partloc->SetXTitle("eta");
    partloc->SetYTitle("phi");
    Double_t count=0;
    TH1F *gammajetphi= new TH1F("gammajetphi","gammajetphi",50,pi/2,(3*pi)/2);
    gammajetphi->SetXTitle("dphi");
    Double_t angcount=0;
    TH1F *jetpt= new TH1F("jetpt","jetpt",120,0,60);
    for (Int_t iev = 0;iev<entries;iev++){
        //Looping over number of events
        if (iev % 1000 == 0)
            cout<<"Event "<<iev<<endl;
        
        //Get all the particles in the event
        tree->GetEntry(iev);
        bHardPartons->GetEntry(iev);
        bHardPartonNames->GetEntry(iev);
        bparticles->GetEntry(iev);
        bJets->GetEntry(iev);
        
        //loop over final state particles
        Int_t nparticles = particles->GetEntriesFast();
        Int_t nhardpartons = HardPartons->GetEntriesFast();
        Int_t njets=Jets->GetEntriesFast();
        Double_t xjg=0;
        Double_t xjetg=0;
        Double_t gpt=0;
        Double_t gphi=0;
        Double_t geta=0;
        for (int ip = 0; ip<nhardpartons;ip++){
            //Find each particle
            TLorentzVector* hardparton = (TLorentzVector*)HardPartons->At(ip);
            TParameter<int>* name = (TParameter<int> *)HardPartonNames->At(ip);
            Int_t partonname=name->GetVal();
            if((ip==0)&&(partonname==22)){
                gpt=hardparton->Pt();
                gphi=hardparton->Phi();
                geta= hardparton->Eta();
            }
            else if((ip!=0)&&(partonname==22)){
                TParameter<int>* namez = (TParameter<int> *)HardPartonNames->At(ip-1);
                Int_t part=namez->GetVal();
                if(part!=22){
                    gpt=hardparton->Pt();
                    gphi=hardparton->Phi();
                    geta= hardparton->Eta();
                }
            }
                
        }
        if(gphi>(doublepi-1))
            gammaloc->Fill(geta,gphi-doublepi);
        if(gphi<-1)
            gammaloc->Fill(geta,gphi+doublepi);
        else{
            gammaloc->Fill(geta,gphi);
        }
        //cout<<gpt<<endl;
        Double_t highpT=0;
        for(int i=0;i<nparticles;i++){
            TLorentzVector* particle = (TLorentzVector*)particles->At(i);
            Double_t ppT= particle->Pt();
            Double_t pphi=particle->Phi();
            Double_t peta=particle->Eta();
            Double_t dphi=0;
            if((gphi-pphi)>(doublepi-1))
                dphi=gphi-pphi-doublepi;
            else if((gphi-pphi)<-1)
                dphi=(gphi-pphi+doublepi);
            else{
                dphi=gphi-pphi;
            }
            Double_t radius=0;
            radius=sqrt((TMath::Power(dphi,2))+TMath::Power(geta-peta,2));
            if(radius<.2){
                if(pphi>(doublepi-1))
                    partloc->Fill(peta,pphi-doublepi);
                if(pphi<-1)
                    partloc->Fill(peta,pphi+doublepi);
                else{
                    partloc->Fill(peta,pphi);
                }
                count++;
            }
            if((ppT>highpT)&&((TMath::Abs(gphi-pphi))>(pi/2))&&((TMath::Abs(gphi-pphi))<((3*pi)/2)))
                highpT=ppT;
            
        }
        Double_t highjet=0;
        for(int i=0;i<njets;i++){
           TLorentzVector* jets = (TLorentzVector*)particles->At(i);
            Double_t jpT= jets->Pt();
            Double_t jphi=jets->Phi();
            jetpt->Fill(jpT);
            Double_t xjetgall=0;
            if(((fabs(gphi-jphi))>(pi/2.0))&&((fabs(gphi-jphi))<((3.0*pi)/2))){
                xjetgall=(jpT/gpt);
                xjgjetall->Fill(jpT,xjetgall);
                
            }
            if((jpT>highjet)&&((fabs(gphi-jphi))>(pi/2))&&((fabs(gphi-jphi))<((3*pi)/2)))
                highjet=jpT;
            if(((TMath::Abs(gphi-jphi))>(pi/2))&&((TMath::Abs(gphi-jphi))<((3*pi)/2))){
                gammajetphi->Fill(gphi-jphi);
                angcount++;
            }
        }
        //cout<<highpT<<endl;
        xjg=(highpT/gpt);
        xjghist->Fill(highpT,xjg);
        xjetg=(highjet/gpt);
        xjgjet->Fill(highjet,xjetg);
    }
    gammaloc->Scale(1.0/2500);
    partloc->Scale(1.0/(2500*count));
    gammajetphi->Scale(1.0/(50*angcount));

    TFile *file1 = TFile::Open(OutFileName.Data(),"RECREATE");

    photonpT->Write();
    //xjghist->Write();
    xjgjet->Write();
    xjgjetall->Write();
    gammaloc->Write();
    partloc->Write();
    gammajetphi->Write();
    jetpt->Write();
    

}
