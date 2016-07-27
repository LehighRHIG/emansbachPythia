
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
    
    //TString jetspecs= "reekjed: " ;
    //jetspecs.Append()
    
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
    TH1F* hHardPartonspT = new TH1F(histname,histname,20,0,100);
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
    histname="hParticlesEtaPhipT";
    TH2F* hParticlesEtaPhipT= new TH2F(histname,histname,50,-1,1,50,-6.2,6.2);

    //Jet histograms
    histname="JetpT";
    TH1F* JetpT = new TH1F(histname,histname,50,-5,45);
    histname = "JetEtaPhi";
    TH2F* JetEtaPhi = new TH2F(histname,histname,100,-1,1,100,-6.3,6.3);
    histname= "JetPhiCount";
    TH1F* JetPhiCount= new TH1F(histname,histname,160,-4,4);
    histname="JetEtaCount";
    TH1F* JetEtaCount= new TH1F(histname,histname,80,-2,2);
    histname="JetEtaPhipT";
    TH2F* JetEtaPhipT= new TH2F(histname,histname,50,-1,1,50,-6.2,6.2);
    
    
    histname="deltR";
    TH2F *deltR=new TH2F(histname,histname,50,0,50,50,0,.2);
    deltR->SetXTitle("jet pt");
    deltR->SetYTitle("dR of highest pt parton");
    deltR->SetZTitle("counts");
    TH1F *photonpT= new TH1F("photonpT","photonpT",50,0,50);
    Int_t entries = tree->GetEntries();
    Double_t doublepi= 2*TMath::Pi();
    for(Int_t iev = 0;iev<entries;iev++){
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
        Int_t njets=Jets->GetEntriesFast();
        Int_t nhardpartons = HardPartons->GetEntriesFast();
        for(int i=0;i<njets;i++){
            TLorentzVector* jet=(TLorentzVector*)Jets->At(i);
            JetpT->Fill(jet->Pt());
            JetEtaPhi->Fill(jet->Eta(),jet->Phi());
            JetPhiCount->Fill(jet->Phi());
            JetEtaCount->Fill(jet->Eta());
            JetEtaPhipT->Fill(jet->Eta(),jet->Phi());
            Double_t jetpt= jet->Pt();
            Double_t jetphi= jet->Phi();
            Double_t jeteta= jet->Eta();
            Double_t highest=-1;
            Double_t dR=-1;
            for(int ip = 0; ip<nparticles;ip++){
                //Find each particle
                TLorentzVector* particle = (TLorentzVector*)particles->At(ip);
                Double_t ipt=particle->Pt();
                Double_t iphi=particle->Phi();
                Double_t ieta=particle->Eta();
                Double_t radius=0;
                Double_t dphi=0;
                if((jetphi-iphi)>(doublepi-1))
                    dphi=jetphi-iphi-doublepi;
                else if((jetphi-iphi)<-1)
                    dphi=(jetphi-iphi+doublepi);
                else{
                    dphi=jetphi-iphi;
                }
                radius=sqrt((TMath::Power(dphi,2))+TMath::Power(jeteta-ieta,2));
                if(radius<=.2){
                    if(ipt>highest){
                        highest=ipt;
                        dR=radius;
                    }
                }
            }
            //cout<<dR<<endl;
            Double_t partonhighest=-1;
            Double_t partondR=-1;
            for(int p=0;p<nhardpartons;p++){
                TLorentzVector* parton = (TLorentzVector*)HardPartons->At(p);
                Double_t ppt=parton->Pt();
                Double_t pphi=parton->Phi();
                Double_t peta=parton->Eta();
                Double_t pR=0;
                Double_t pdphi=0;
                if((jetphi-pphi)>(doublepi-1))
                    pdphi=jetphi-pphi-doublepi;
                else if((jetphi-pphi)<-1)
                    pdphi=(jetphi-pphi+doublepi);
                else{
                    pdphi=jetphi-pphi;
                }
                pR=sqrt(TMath::Power(pdphi,2)+TMath::Power(jeteta-peta,2));
                if(pR<=.2){
                    if(ppt>partonhighest){
                        partonhighest=ppt;
                        partondR=pR;
                    }
                }
                
            }
           // cout<<partondR<<endl;
            deltR->Fill(jetpt,partondR);
        }
    }

            
            
    //end of event loop
    deltR->Sumw2();
   // deltphieta->Scale(1.0/(binsize*count*binsize));


    TFile *file1 = TFile::Open(OutFileName.Data(),"RECREATE");

    hHardPartonspT->Write();
    hHardPartonsName->Write();
    hParticlepT->Write();
    hParticleEtaPhi->Write();
    deltR->Write();
    JetpT->Write();
    JetEtaPhi->Write();
    JetPhiCount->Write();
    JetEtaCount->Write();
    hParticlesEtaPhipT->Write();
    JetEtaPhipT->Write();
    photonpT->Write();
}
