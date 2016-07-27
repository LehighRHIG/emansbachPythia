
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
    TClonesArray *Background = new TClonesArray("TLorentzVector");
    TBranch* bBackground = tree->GetBranch("Background");
    bBackground->SetAddress(&Background);
    bparticles->SetAddress(&particles);
    TClonesArray *BackJets = new TClonesArray("TLorentzVector");
    TBranch* bBackJets = tree->GetBranch("backgroundjets_R020_ptmin0");
    bBackJets->SetAddress(&BackJets);
    TClonesArray *ComboJets = new TClonesArray("TLorentzVector");
    TBranch* bComboJets = tree->GetBranch("combojets_R020_ptmin0");
    bComboJets->SetAddress(&ComboJets);
    
    Double_t R=0.2;
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
    
    //Background Histograms
    TH1F* hpT = new TH1F("hpT","",100,0,20);
    TH1F* hPhi = new TH1F("hPhi","",20,0,2*TMath::Pi());
    TH1F* hEta = new TH1F("hEta","",20,-1.5,1.5);
    //hpT->GetYaxis()->SetTitleOffset(1.8);
    
    TH1F* backjetpT = new TH1F("backjetpT","backjetpT",100,0,50);
    TH1F* backjetPhi = new TH1F("backjetPhi","backjetPhi",20,0,2*TMath::Pi());
    TH1F* backjetEta = new TH1F("backjetEta","backjetEta",20,-1.5,1.5);
    
    TH1F* combojetpT = new TH1F("combojetpT","combojetpT",100,0,50);
    TH1F* combojetPhi = new TH1F("combojetPhi","combojetPhi",20,0,2*TMath::Pi());
    TH1F* combojetEta = new TH1F("combojetEta","combojetEta",20,-1.5,1.5);
    
    //
    
    
    Int_t entries = tree->GetEntries();
    Double_t trigmin = 12.5;
    Double_t trigmax = 20.0;
    Double_t assocmin=4.0;
    Double_t assocmax=8.0;
    Double_t doublepi= 2*TMath::Pi();
    Double_t pi= TMath::Pi();
    histname="deltphieta";
    Int_t binsize= 50;
    TH3F *jethist= new TH3F("jethist","jetphist",50,-1,1,50,0,doublepi/2,100,0,50);
    jethist->SetXTitle("eta");
    jethist->SetYTitle("phi");
    jethist->SetZTitle("pT");
    
    TH3F *gammahist= new TH3F("gammahist","gammaphist",50,-1,1,50,0,doublepi/2,100,0,50);
    gammahist->SetXTitle("eta");
    gammahist->SetYTitle("phi");
    gammahist->SetZTitle("pT");
    
    TH3F *parthist= new TH3F("parthist","parthist",50,-1,1,50,0,doublepi/2,100,0,50);
    parthist->SetXTitle("eta");
    parthist->SetYTitle("phi");
    parthist->SetZTitle("pT");
    
    TH3F *leadjethist= new TH3F("leadjethist","leadjethist",50,-1,1,50,0,doublepi/2,100,0,50);
    leadjethist->SetXTitle("eta");
    leadjethist->SetYTitle("phi");
    leadjethist->SetZTitle("pT");
    
    TH2F *deltphigjet= new TH2F("deltphigjet","deltphigjet",60,0,60,50,0,doublepi);
    deltphigjet->SetXTitle("jet pt");
    deltphigjet->SetYTitle("deltphi");
    
    TH1F *deltphigleadjet= new TH1F("deltphigleadjet","deltphigleadjet",50,0,doublepi);
    deltphigleadjet->SetXTitle("dphi");
    deltphigleadjet->SetYTitle("counts");
    
    TH1F *deltphigq= new TH1F("deltphigq","deltphigq",50,0,doublepi);
    deltphigq->SetXTitle("dphi");
    deltphigq->SetYTitle("counts");
    
    TH3F *jetcuthist= new TH3F("jetcuthist","jetcuthist",50,-1,1,50,0,doublepi/2,100,0,50);
    jetcuthist->SetXTitle("eta");
    jetcuthist->SetYTitle("phi");
    jetcuthist->SetZTitle("pT");
    
    TH3F *leadjetcuthist= new TH3F("leadjetcuthist","leadjetcuthist",50,-1,1,50,0,doublepi/2,100,0,50);
    leadjetcuthist->SetXTitle("eta");
    leadjetcuthist->SetYTitle("phi");
    leadjetcuthist->SetZTitle("pT");
    
    TH2F *xjghist= new TH2F("xjghist","xjghist",120,0,60,50,0,2);
    xjghist->SetXTitle("Jet pT");
    xjghist->SetYTitle("xjg");
    
    TH1F *jphihist= new TH1F("jphihist","jphihist",50,0,50);
    jphihist->SetXTitle("phi");
    jphihist->SetYTitle("counts");
    Int_t count=0;
    Int_t overeta=0;
    Int_t undereta=0;
    Int_t othercount=0;
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
        bBackground->GetEntry(iev);
        bBackJets->GetEntry(iev);
        bComboJets->GetEntry(iev);
        
        //loop over final state particles
        Int_t nparticles = particles->GetEntriesFast();
        Int_t njets=Jets->GetEntriesFast();
        Int_t nhardparton=HardPartons->GetEntriesFast();
        Int_t nBackground=Background->GetEntriesFast();
        Int_t nBackgroundjets=BackJets->GetEntriesFast();
        Int_t nCombojets= ComboJets->GetEntriesFast();
        Double_t leadpT=-1;
        Double_t leadeta=0;
        Double_t leadphi=0;
        Double_t rangept=0;
        Double_t xjg=0;
        Double_t gapt=-1;
        Double_t gaphi=0;
        Double_t gaeta=0;
        Double_t othereta=0;
        Int_t i=0;
        Int_t j=1;
        //for(int i=0;i<nhardparton;i++){
            TLorentzVector* hpartoni=(TLorentzVector*)HardPartons->At(i);
            TParameter<int>* namei = (TParameter<int> *)HardPartonNames->At(i);
            Int_t partonnamei=namei->GetVal();
            TLorentzVector* hpartonj=(TLorentzVector*)HardPartons->At(j);
            TParameter<int>* namej = (TParameter<int> *)HardPartonNames->At(j);
            Int_t partonnamej=namej->GetVal();
            if(((partonnamei==22)&&(partonnamej!=22))||((partonnamei==22)&&(partonnamej==22)&&(hpartoni->Pt()>(hpartonj->Pt())))){
                gapt=hpartoni->Pt();
                gaphi=hpartoni->Phi();
                gaeta= hpartoni->Eta();
                if((fabs(gaeta)<1)&&(fabs(hpartonj->Eta())>1)){
                    count++;
                    for(int q=0;q<njets;q++){
                        TLorentzVector* jet=(TLorentzVector*)Jets->At(q);
                        Double_t jphi=jet->Phi();
                        Double_t jeta=jet->Eta();
                        Double_t jpt=jet->Pt();
                        if((jpt>leadpT)&&(fabs(gaphi-jphi)>(pi/2.0))&&(fabs(gaphi-jphi)<((3.0*pi)/2.0))){
                            leadpT=jpt;
                            leadeta=jeta;
                            leadphi=jphi;
                            
                        }
                    }
                }
                if(((fabs(leadeta)+R)<1))
                    rangept=leadpT;
            }
            else if(((partonnamej==22)&&(partonnamei!=22))||((partonnamei==22)&&(partonnamej==22)&&(hpartonj->Pt()>hpartoni->Pt()))){
                gapt=hpartonj->Pt();
                gaphi=hpartonj->Phi();
                gaeta= hpartonj->Eta();
                if((fabs(gaeta)<1)&&(fabs(hpartoni->Eta())>1)){
                    count++;
                    for(int q=0;q<njets;q++){
                        TLorentzVector* jet=(TLorentzVector*)Jets->At(q);
                        Double_t jphi=jet->Phi();
                        Double_t jeta=jet->Eta();
                        Double_t jpt=jet->Pt();
                        if(((fabs(jeta)+R)<1)&&(jpt>leadpT)&&(fabs(gaphi-jphi)>(pi/2.0))&&(fabs(gaphi-jphi)<((3.0*pi)/2.0))){
                            leadpT=jpt;
                            leadeta=jeta;
                            leadphi=jphi;
                        }
                    }
                }
                if(((fabs(leadeta)+R)<1))
                    rangept=leadpT;
            }

        if((rangept>0)&&(gapt>0)){
            xjg=(rangept/gapt);
            xjghist->Fill(rangept,xjg);
        }
        
        for(int i=0;i<nBackground;i++){
            TLorentzVector* backparticle=(TLorentzVector*)Background->At(i);
            hpT->Fill(backparticle->Pt());
            hEta->Fill(backparticle->Eta());
            hPhi->Fill(backparticle->Phi());
        }
        for(int i=0;i<nBackgroundjets;i++){
           TLorentzVector* backjet=(TLorentzVector*)BackJets->At(i);
            backjetpT->Fill(backjet->Pt());
            backjetEta->Fill(backjet->Eta());
            backjetPhi->Fill(backjet->Phi());
        }
        for(int i=0;i<nCombojets;i++){
            TLorentzVector* combojet=(TLorentzVector*)ComboJets->At(i);
            combojetpT->Fill(combojet->Pt());
            combojetEta->Fill(combojet->Eta());
            combojetPhi->Fill(combojet->Phi());
        }
        
       /*     else if((i!=0)&&(partonname==22)&&(hparton->Pt()>gapt)){
                gapt=hparton->Pt();
                gaphi=hparton->Phi();
                gaeta= hparton->Eta();
            }
            else if(partonname!=22){
                othereta= hparton->Eta();
            }
        }*/
        for(int j=0;j<njets;j++){
            TLorentzVector* jet=(TLorentzVector*)Jets->At(j);
            jethist->Fill(jet->Eta(),jet->Phi(),jet->Pt());
        }

       /* if(fabs(gaeta)>1)
            overeta++;
        if(fabs(gaeta)<=1){
            undereta++;
            if(fabs(othereta)<1)
                othercount++;
        }*/
        
        
        /*for(int i=0;i<njets;i++){
            TLorentzVector* jet=(TLorentzVector*)Jets->At(i);
            jethist->Fill(jet->Eta(),fabs(jet->Phi()),jet->Pt());
            if((jet->Pt())>leadpT){
                leadpT= jet->Pt();
                leadeta= jet->Eta();
                leadphi= fabs(jet->Phi());
            }
        }
        Double_t gapt=0;
        Double_t gaphi=0;
        Double_t gaeta=0;
        for(int i=0;i<nhardparton;i++){
            TLorentzVector* hparton=(TLorentzVector*)HardPartons->At(i);
            TParameter<int>* name = (TParameter<int> *)HardPartonNames->At(i);
            Int_t partonname=name->GetVal();
            if(partonname==22){
                gammahist->Fill(hparton->Eta(),fabs(hparton->Phi()),hparton->Pt());
                count++;
                Double_t gphi=hparton->Phi();
                Double_t geta=hparton->Eta();
                Double_t gpt=hparton->Pt();
                deltphigleadjet->Fill(fabs(hparton->Phi()-leadphi));
                for(int j=0;j<njets;j++){
                    TLorentzVector* jetz=(TLorentzVector*)Jets->At(j);
                    Double_t p=fabs(hparton->Phi()-jetz->Phi());
                    if(p>pi)
                        p=doublepi-p;
                    deltphigjet->Fill(jetz->Pt(),p);
                    Double_t jphi=jetz->Phi();
                    Double_t jeta=jetz->Eta();
                    Double_t jpt=jetz->Pt();
                    if((fabs(gphi-jphi)>(pi/2.0))&&(fabs(gphi-jphi)<(3.0*pi/4.0)))
                        jetcuthist->Fill(jetz->Eta(),jetz->Phi(),jetz->Pt());
                }
                
                
               for(int k=0;k<nhardparton;k++){
                    TLorentzVector* quark=(TLorentzVector*)HardPartons->At(k);
                    TParameter<int>* qname = (TParameter<int> *)HardPartonNames->At(k);
                    Int_t quarkname=qname->GetVal();
                    if((quarkname!=22)&&(quarkname!=21))
                        deltphigq->Fill(fabs(hparton->Phi()-quark->Phi()));
                        
                }
            }
            if((i==0)&&(partonname==22)){
                gapt=hparton->Pt();
                gaphi=hparton->Phi();
                gaeta= hparton->Eta();
            }
            else if((i!=0)&&(partonname==22)&&(hparton->Pt()>gapt)){
                    gapt=hparton->Pt();
                    gaphi=hparton->Phi();
                    gaeta= hparton->Eta();
            }
        }
        if((fabs(gaphi-leadphi)>(pi/2.0))&&(fabs(gaphi-leadphi)<(3.0*pi/4.0))){
            leadjetcuthist->Fill(leadeta,leadphi,leadpT);
            xjg=(leadpT/gapt);
            xjghist->Fill(leadpT,xjg);
        }
        for(int i=0;i<nparticles;i++){
            TLorentzVector* particle=(TLorentzVector*)particles->At(i);
            parthist->Fill(particle->Eta(),fabs(particle->Phi()),particle->Pt());
        }
        leadjethist->Fill(leadeta,leadphi,leadpT);*/
    }
    
    cout<<count<<endl;
    
    TFile *file1 = TFile::Open(OutFileName.Data(),"RECREATE");
    jethist->Write();
    gammahist->Write();
    parthist->Write();
    leadjethist->Write();
    deltphigjet->Write();
    deltphigleadjet->Write();
    deltphigq->Write();
    jetcuthist->Write();
    leadjetcuthist->Write();
    xjghist->Write();
    jphihist->Write();
    hPhi->Write();
    hpT->Write();
    hEta->Write();
    backjetpT->Write();
    backjetEta->Write();
    backjetPhi->Write();
    combojetpT->Write();
    combojetEta->Write();
    combojetPhi->Write();
}
