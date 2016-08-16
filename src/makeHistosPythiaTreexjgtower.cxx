
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
#include "TRandom3.h"
#include <iostream>
#include <cmath>
#include <TMath.h>
#include <exception>
#include "RooUnfoldResponse.h"
#include "RooUnfoldBayes.h"

using namespace std;

int main(int argc, const char** argv)
{
    const char *defaults[6] = {"readPythiaTree","test.root","in","error1","error2","error3"};
    if ( argc==1 ) {
        argv=defaults;
        argc=3;
    }
    TString InFileName = argv[1];
    cout<<"In file is "<<InFileName.Data()<<endl;
    
    TString FileName = argv[2];
    cout<<"In file is "<<FileName.Data()<<endl;
    
    TString OutFileName = argv[3];
    cout<<"Out file is "<<OutFileName.Data()<<endl;
    
    TString jetaddress="jets_R0";
    jetaddress.Append(argv[5]);
    jetaddress.Append("0_ptmin0");
    TString subjetaddress="subjets_R0";
    subjetaddress.Append(argv[5]);
    subjetaddress.Append("0_ptmin0");
    //TString jetspecs= "reekjed: " ;
    //jetspecs.Append()
    
    //find trees
    TFile *_file0 = TFile::Open(InFileName); //read tree
    TTree* towertree = (TTree*)gROOT->FindObject("towertree");
    
    //branches
    TClonesArray *towerjets = new TClonesArray("TLorentzVector");
    TBranch* btowerjets = towertree->GetBranch("towerjets");
    btowerjets->SetAddress(&towerjets);
    
    _file0->Close();
   
    
    //tree
    TFile *_file1 = TFile::Open(FileName);
    TTree* tree = (TTree*)gROOT->FindObject("tree");
    
    //branches
    TClonesArray *reconparticles = new TClonesArray("TLorentzVector");
    TBranch* breconparticles = tree->GetBranch("ReconstructedParticles");
    breconparticles->SetAddress(&reconparticles);
    TClonesArray *EtaTower = new TClonesArray("TParameter<int>");
    TBranch* bEtaTower = tree->GetBranch("ReconEtaTower");
    bEtaTower->SetAddress(&EtaTower);
    TClonesArray *PhiTower = new TClonesArray("TParameter<int>");
    TBranch* bPhiTower = tree->GetBranch("ReconPhiTower");
    bPhiTower->SetAddress(&PhiTower);
    TClonesArray *ReconName = new TClonesArray("TParameter<int>");
    TBranch* bReconName = tree->GetBranch("ReconNames");
    bReconName->SetAddress(&ReconName);
    _file1->Close();
    //read collections, NEED TO READ IN TREES FROM ORIGINAL PYTHIA TREE ALSO TO GET PHOTON!!!

    
    //reads in radius and ptmin contraints
    Double_t R= atof(argv[5])/10.;
    
    Double_t ptmin=atof(argv[4]);
    Double_t ptmax=atof(argv[4])+5;

    
    //histograms
    
    
    
    
    Int_t entries = tree->GetEntries();
    cout<<entries<<endl;
    
    //fill mixed event hists
    TRandom3 *rmd= new TRandom3;
    rmd->SetSeed(100);
    for(int ev=0;ev<50;ev++){
        if (ev % 5 == 0)
            cout<<"Event "<<ev<<endl;
        treea->GetEntry(ev);
        bmixjets->GetEntry(ev);
        Int_t nmixjets=mixjets->GetEntriesFast();
        bmixsubjets->GetEntry(ev);
        Int_t nmixsubjets=mixsubjets->GetEntriesFast();
        bmixspec->GetEntry(ev);
        Int_t nmixspec=mixspec->GetEntriesFast();
        for(int i=0;i<nmixspec;i++){
            TParameter<double>* name = (TParameter<double> *)mixspec->At(i);
            Double_t speci=name->GetVal();
            mixedptspec->Fill(speci);
        }
        Double_t rand=0;
        rand = rmd->Rndm();
        Double_t mphi = TMath::Pi()*2.*rand;
        Double_t selectpt=-1;
        Double_t selecteta=0;
        Double_t selectphi=0;
        Double_t subselectpt=-1;
        Double_t subselecteta=0;
        Double_t subselectphi=0;
        Double_t mixrangept=-1;
        Double_t submixrangept=-1;
        Double_t phpt= atof(argv[3]);
        Double_t mixxjg=0;
        Double_t submixxjg=0;
        for(int q=0;q<nmixjets;q++){
            TLorentzVector* mjet=(TLorentzVector*)mixjets->At(q);
            Double_t mjphi=mjet->Phi();
            Double_t mjeta=mjet->Eta();
            Double_t mjpt=mjet->Pt();
            if((mjpt>selectpt)&&(fabs(mphi-mjphi)>(pi/2.0))&&(fabs(mphi-mjphi)<((3.0*pi)/2.0))){
                selectpt=mjpt;
                selecteta=mjeta;
                selectphi=mjphi;
                
            }
        }
        for(int q=0;q<nmixsubjets;q++){
            TLorentzVector* smjet=(TLorentzVector*)mixsubjets->At(q);
            Double_t smjphi=smjet->Phi();
            Double_t smjeta=smjet->Eta();
            Double_t smjpt=smjet->Pt();
            if((smjpt>subselectpt)&&(fabs(mphi-smjphi)>(pi/2.0))&&(fabs(mphi-smjphi)<((3.0*pi)/2.0))){
                subselectpt=smjpt;
                subselecteta=smjeta;
                subselectphi=smjphi;
                
            }
        }
        if(((fabs(selecteta)+R)<1))
            mixrangept=selectpt;
        if(((fabs(subselecteta)+R)<1))
            submixrangept=subselectpt;
        
        if(mixrangept>0){
            mixxjg=(mixrangept/phpt);
            mixxjghist->Fill(mixrangept,mixxjg);
        }
        if(submixrangept>0){
            submixxjg=(submixrangept/phpt);
            submixxjghist->Fill(submixrangept,submixxjg);
        }
    }
    
    
    //fill event hists
    for (Int_t iev = 0;iev<10;iev++){
        //Looping over number of events
    
        if (iev % 1000 == 0)
            cout<<"Event "<<iev<<endl;
        
        //Get all the particles in the event
        tree->GetEntry(iev);
        bHardPartons->GetEntry(iev);
        bHardPartonNames->GetEntry(iev);
        bparticles->GetEntry(iev);
        bJets->GetEntry(iev);
        bsubJets->GetEntry(iev);
        bcombospec->GetEntry(iev);
       // bBackground->GetEntry(iev);
        bBackJets->GetEntry(iev);
       // bComboJets->GetEntry(iev);
        //bjetarea->GetEntry(iev);
        //bbackjetarea->GetEntry(iev);
        //bcombojetarea->GetEntry(iev);*/
       
        
        //loop over final state particles
        Int_t nparticles = particles->GetEntriesFast();
        Int_t nHardPartonNames=HardPartonNames->GetEntriesFast();
        Int_t njets=Jets->GetEntriesFast();
        Int_t nhardparton=HardPartons->GetEntriesFast();
        Int_t nsubjets= subJets->GetEntriesFast();
        Int_t ncombospec=combospec->GetEntriesFast();
       // Int_t nBackground=Background->GetEntriesFast();
        Int_t nBackgroundjets=BackJets->GetEntriesFast();
       // Int_t nCombojets= ComboJets->GetEntriesFast();
        //Int_t njetarea=jetarea->GetEntriesFast();
        //Int_t nbackjetarea=backjetarea->GetEntriesFast();
        //Int_t ncombojetarea=combojetarea->GetEntriesFast();*/
       // cout<<nCombojets<<endl;
        //cout<<ncombojetarea<<endl;
        
        
        //script to get total efficiency
        Double_t leadpT=-1;
        Double_t leadeta=0;
        Double_t leadphi=0;
        Double_t rangept=0;
        Double_t xjg=0;
        Double_t gapt=-1;
        Double_t gaphi=0;
        Double_t gaeta=0;
        Double_t subleadpT=-1;
        Double_t subleadeta=0;
        Double_t subleadphi=0;
        Double_t subrangept=0;
        Double_t subxjg=0;
        Int_t f=0;
        Int_t s=1;
        
        Double_t radius=0;
        Double_t lowradius=100;
        Double_t photonpt=0;
        Double_t jeteta=0;
        Double_t jetpt=0;
        /*for(int i=0;i<nhardparton;i++){
             TLorentzVector* hpartoni=(TLorentzVector*)HardPartons->At(i);
             TParameter<int>* namei = (TParameter<int> *)HardPartonNames->At(i);
             Int_t partonnamei=namei->GetVal();
            if(partonnamei==22){
                if((hpartoni->Pt()>ptmin)&&(hpartoni->Pt()<ptmax)){
                    hardpartoncount++;
                    gammatot->Fill(hpartoni->Eta());
                    if(fabs(hpartoni->Eta())<1){
                        if(i==0){
                            TLorentzVector* hpartonj=(TLorentzVector*)HardPartons->At(1);
                            TParameter<int>* namej = (TParameter<int> *)HardPartonNames->At(1);
                            Int_t partonnamej=namej->GetVal();
                            if(partonnamej!=22)
                                partontot->Fill(hpartonj->Eta());
                            if((partonnamej!=22)&&((fabs(hpartonj->Eta())+R)<1)){
                                for(int k=0;k<njets;k++){
                                    TLorentzVector* jet=(TLorentzVector*)Jets->At(k);
                                    radius=sqrt(TMath::Power(((hpartonj->Eta()-jet->Eta())),2)+(TMath::Power(((hpartonj->Phi()-jet->Phi())),2)));
                                    if(radius<lowradius){
                                        lowradius=radius;
                                        photonpt=hpartoni->Pt();
                                        jeteta= jet->Eta();
                                        jetpt=jet->Pt();
                                    }
                                }
                               jettot->Fill(jeteta);
                            }
                        }
                        if(i==1){
                            TLorentzVector* hpartonj=(TLorentzVector*)HardPartons->At(0);
                            TParameter<int>* namej = (TParameter<int> *)HardPartonNames->At(0);
                            Int_t partonnamej=namej->GetVal();
                            if(partonnamej!=22)
                                partontot->Fill(hpartonj->Eta());
                            if((partonnamej!=22)&&((fabs(hpartonj->Eta())+R)<1)){
                                for(int k=0;k<njets;k++){
                                    TLorentzVector* jet=(TLorentzVector*)Jets->At(k);
                                    radius=sqrt(TMath::Power(((hpartonj->Eta()-jet->Eta())),2)+(TMath::Power(((hpartonj->Phi()-jet->Phi())),2)));
                                    if(radius<lowradius){
                                        lowradius=radius;
                                        photonpt=hpartoni->Pt();
                                        jeteta= jet->Eta();
                                        jetpt=jet->Pt();
                                    }
                                }
                                      jettot->Fill(jeteta);
                            }
                        }
                    }
                }
            }
        }
    
    
    jettot->Sumw2();
    //jetprob->Scale(1.0/(partoncount1));
    gammatot->Sumw2();
    //gammaprob->Scale(1.0/(hardpartoncount));
    partontot->Sumw2();
    //partonprob->Scale(1.0/(gammacount));
  */
        for(int q=0;q<njets;q++){
            TLorentzVector* jet=(TLorentzVector*)Jets->At(q);
            Double_t jphi=jet->Phi();
            Double_t jeta=jet->Eta();
            Double_t jpt=jet->Pt();
            int weight= ceil(jpt);
            for(int p=0;p<weight;p++)
                jetdraw->Fill(jeta,jphi);
        }
        for(int q=0;q<nBackgroundjets;q++){
            TLorentzVector* jet=(TLorentzVector*)BackJets->At(q);
            Double_t jphi=jet->Phi();
            Double_t jeta=jet->Eta();
            Double_t jpt=jet->Pt();
            int weight= ceil(jpt);
            for(int p=0;p<weight;p++)
                jetdraw->Fill(jeta,jphi);
        }
         
        
        
        //script to determine xjg
        leadpT=-1;
        leadeta=0;
        leadphi=0;
        rangept=0;
        xjg=0;
        gapt=-1;
        gaphi=0;
        gaeta=0;
        subleadpT=-1;
        subleadeta=0;
        subleadphi=0;
        subxjg=0;
        f=0;
        s=1;
        
        radius=0;
        lowradius=100;
        photonpt=0;
        jetpt=0;
        //for(int i=0;i<nhardparton;i++){
            TLorentzVector* hpartoni=(TLorentzVector*)HardPartons->At(f);
            TParameter<int>* namei = (TParameter<int> *)HardPartonNames->At(f);
            Int_t partonnamei=namei->GetVal();
            TLorentzVector* hpartonj=(TLorentzVector*)HardPartons->At(s);
            TParameter<int>* namej = (TParameter<int> *)HardPartonNames->At(s);
            Int_t partonnamej=namej->GetVal();
            if(((partonnamei==22)&&(partonnamej!=22))||((partonnamei==22)&&(partonnamej==22)&&(hpartoni->Pt()>(hpartonj->Pt())))){
                gapt=hpartoni->Pt();
                gaphi=hpartoni->Phi();
                gaeta= hpartoni->Eta();
                if((fabs(gaeta)<1)&&(fabs(hpartonj->Eta())<1)){
                    //count++;
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
                    for(int q=0;q<nsubjets;q++){
                        TLorentzVector* jet=(TLorentzVector*)subJets->At(q);
                        Double_t subjphi=jet->Phi();
                        Double_t subjeta=jet->Eta();
                        Double_t subjpt=jet->Pt();
                        if((subjpt>subleadpT)&&(fabs(gaphi-subjphi)>(pi/2.0))&&(fabs(gaphi-subjphi)<((3.0*pi)/2.0))){
                            subleadpT=subjpt;
                            subleadeta=subjeta;
                            subleadphi=subjphi;
                            
                        }
                    }
                }
                if(((fabs(leadeta)+R)<1))
                    rangept=leadpT;
                if(((fabs(subleadeta)+R)<1))
                    subrangept=subleadpT;
            }
            else if(((partonnamej==22)&&(partonnamei!=22))||((partonnamei==22)&&(partonnamej==22)&&(hpartonj->Pt()>hpartoni->Pt()))){
                gapt=hpartonj->Pt();
                gaphi=hpartonj->Phi();
                gaeta= hpartonj->Eta();
                if((fabs(gaeta)<1)&&(fabs(hpartoni->Eta())<1)){
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
                    for(int q=0;q<nsubjets;q++){
                        TLorentzVector* jet=(TLorentzVector*)subJets->At(q);
                        Double_t subjphi=jet->Phi();
                        Double_t subjeta=jet->Eta();
                        Double_t subjpt=jet->Pt();
                        if((subjpt>subleadpT)&&(fabs(gaphi-subjphi)>(pi/2.0))&&(fabs(gaphi-subjphi)<((3.0*pi)/2.0))){
                            subleadpT=subjpt;
                            subleadeta=subjeta;
                            subleadphi=subjphi;
                            
                        }
                    }
                }
                if(((fabs(leadeta)+R)<1))
                    rangept=leadpT;
                if(((fabs(subleadeta)+R)<1))
                    subrangept=subleadpT;
            }

        if((rangept>0)&&(gapt>0)){
            xjg=(rangept/gapt);
            xjghist->Fill(rangept,xjg);
        }
        if((subrangept>0)&&(gapt>0)){
            subxjg=(subrangept/gapt);
            subxjghist->Fill(subrangept,subxjg);
        }
        if((xjg>0)||(subxjg>0))
            xjgsubxjg->Fill(xjg,subxjg);
        for(int i=0;i<ncombospec;i++){
            TParameter<double>* cpts = (TParameter<double> *)combospec->At(i);
            Int_t valc=cpts->GetVal();
            comboptspec->Fill(valc);
        }
        
    }

    
    
/*
        Double_t jarea=0;
        for(int i=0;i<njetarea;i++){
            TParameter<double>* jetaRea= (TParameter<double> *)jetarea->At(i);
            jarea=jetaRea->GetVal();
            //cout<<jarea<<endl;
            jetareadistr->Fill(jarea);
        }
        Double_t barea=0;
        for(int i=0;i<nbackjetarea;i++){
            TParameter<double>* backjetaRea= (TParameter<double> *)backjetarea->At(i);
            barea=backjetaRea->GetVal();
            //cout<<jarea<<endl;
            backjetareadistr->Fill(barea);
        }
        Double_t carea=0;
        for(int i=0;i<ncombojetarea;i++){
            TParameter<double>* combojetaRea= (TParameter<double> *)combojetarea->At(i);
            carea=combojetaRea->GetVal();
            //cout<<carea<<endl;
            //cout<<jarea<<endl;
            combojetareadistr->Fill(carea);
        }
        */
    
    //cout<<count<<endl;
    
    //rename some hists
    xjghist->SetName(jetstring);
    subxjghist->SetName(subjetstring);
    comboptspec->SetName(cptspec);
    mixedptspec->SetName(mptspec);
    mixxjghist->SetName(mixstring);
    submixxjghist->SetName(submixstring);
    
    
    //create and write outfile, updates rn but can change to rewrite 
    
    TFile *file1 = TFile::Open(OutFileName.Data(),"RECREATE");

    xjghist->Write();
    jetdraw->Write();
    //hReco->Write();
   // subxjghist->Write();
    //xjgsubxjg->Write();
    //jetareadistr->Write();
    //backjetareadistr->Write();
    //combojetareadistr->Write();
    //jettot->Write();
    //gammatot->Write();
   // partontot->Write();
   // jethist->Write();
   // subjethist->Write();
    //mixedptspec->Write();
    //comboptspec->Write();
    //mixxjghist->Write();
    //submixxjghist->Write();
    //hTrue->Write();
    //hMeas->Write();
   // backhist->Write();
    file1->Close();
    
  /*  TString fout= "pythiaandsub1gevcut";
    TFile *file2 = TFile::Open(fout.Data(),"Update");
    subxjghist->Write();
    xjghist->Write();*/

    
}
