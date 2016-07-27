
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
    const char *defaults[5] = {"readPythiaTree","test.root","in","error1","error2"};
    if ( argc==1 ) {
        argv=defaults;
        argc=3;
    }
    TString InFileName = argv[1];
    cout<<"In file is "<<InFileName.Data()<<endl;
    
    TString OutFileName = argv[2];
    cout<<"Out file is "<<OutFileName.Data()<<endl;
    
    TString jetaddress="jets_R0";
    jetaddress.Append(argv[4]);
    jetaddress.Append("0_ptmin0");
    TString subjetaddress="subjets_R0";
    subjetaddress.Append(argv[4]);
    subjetaddress.Append("0_ptmin0");
    //TString jetspecs= "reekjed: " ;
    //jetspecs.Append()
    
    //find trees
    TFile *_file0 = TFile::Open(InFileName); //read tree
    TTree* tree = (TTree*)gROOT->FindObject("tree");
    TTree* treea = (TTree*)gROOT->FindObject("mixed");
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
    TBranch* bJets = tree->GetBranch(jetaddress);
    bJets->SetAddress(&Jets);
    TClonesArray *subJets = new TClonesArray("TLorentzVector");
    TBranch* bsubJets = tree->GetBranch(subjetaddress);
    bsubJets->SetAddress(&subJets);
    
    //reads in radius and ptmin contraints
    Double_t R= atof(argv[4])/10.;
    
    Double_t ptmin=atof(argv[3]);
    Double_t ptmax=atof(argv[3])+5;
    
    //mixed event branches
    TClonesArray *mixsubjets = new TClonesArray("TLorentzVector");
    TBranch* bmixsubjets = treea->GetBranch("mix");
    bmixsubjets->SetAddress(&mixsubjets);
    TClonesArray *mixspec = new TClonesArray("TParameter<double>");
    TBranch* bmixspec = treea->GetBranch("spec");
    bmixspec->SetAddress(&mixspec);
    TClonesArray *combospec = new TClonesArray("TParameter<double>");
    TBranch* bcombospec = tree->GetBranch("speccombo");
    bcombospec->SetAddress(&combospec);
    TClonesArray *mixjets = new TClonesArray("TLorentzVector");
    TBranch* bmixjets = treea->GetBranch("mixedjets");
    bmixjets->SetAddress(&mixjets);
    
    
    
    TString jetstring="j";
    jetstring.Append(argv[3]);
    jetstring.Append("p");
    jetstring.Append(argv[4]);
    
    TString subjetstring="s";
    subjetstring.Append(argv[3]);
    subjetstring.Append("p");
    subjetstring.Append(argv[4]);
    
    TString mptspec="m";
    mptspec.Append(argv[3]);
    mptspec.Append("p");
    mptspec.Append(argv[4]);
    
    TString cptspec="c";
    cptspec.Append(argv[3]);
    cptspec.Append("p");
    cptspec.Append(argv[4]);

    TString mixstring="mixxjg";
    mixstring.Append(argv[3]);
    mixstring.Append("p");
    mixstring.Append(argv[4]);
    
    TString submixstring="submixxjg";
    submixstring.Append(argv[3]);
    submixstring.Append("p");
    submixstring.Append(argv[4]);
    
    //read in branches
    
    //TClonesArray *Background = new TClonesArray("TLorentzVector");
    //TBranch* bBackground = tree->GetBranch("Background");
    //bBackground->SetAddress(&Background);
    TClonesArray *BackJets = new TClonesArray("TLorentzVector");
    TBranch* bBackJets = tree->GetBranch("backgroundjets_R020_ptmin0");
    bBackJets->SetAddress(&BackJets);
    /*TClonesArray *ComboJets = new TClonesArray("TLorentzVector");
    TBranch* bComboJets = tree->GetBranch("combojets_R020_ptmin0");
    bComboJets->SetAddress(&ComboJets);*/
    /*TClonesArray *jetarea = new TClonesArray("TParameter<double>");
    TBranch* bjetarea = tree->GetBranch("jetareajets_R040_ptmin0");
    bjetarea->SetAddress(&jetarea);
    TClonesArray *backjetarea = new TClonesArray("TParameter<double>");
    TBranch* bbackjetarea = tree->GetBranch("backjetareajets_R040_ptmin0");
    bbackjetarea->SetAddress(&backjetarea);
    TClonesArray *combojetarea = new TClonesArray("TParameter<double>");
    TBranch* bcombojetarea = tree->GetBranch("combojetareajets_R040_ptmin0");
    bcombojetarea->SetAddress(&combojetarea);*/

    
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
    
    //various hists used in my analysis.
    
    Double_t doublepi= 2*TMath::Pi();
    Double_t pi= TMath::Pi();
    histname="deltphieta";
    Int_t binsize= 50;
    
    TH3F *jethist= new TH3F("jethist","jethist",50,-1,1,50,pi*-1,pi,75,0,75);
    jethist->SetXTitle("Eta");
    jethist->SetYTitle("Phi");
    jethist->SetZTitle("Pt");
    
    TH3F *subjethist= new TH3F("subjethist","subjethist",50,-1,1,50,pi*-1,pi,75,0,75);
    subjethist->SetXTitle("Eta");
    subjethist->SetYTitle("Phi");
    subjethist->SetZTitle("Pt");
    
    TH3F *backhist= new TH3F("backhist","backhist",50,-1,1,50,pi*-1,pi,25,0,50);
    backhist->SetXTitle("Eta");
    backhist->SetYTitle("Phi");
    backhist->SetZTitle("Pt");
    
    TH2F *xjghist= new TH2F("xjghist","xjghist",160,0,80,62,0,2.5);
    xjghist->SetXTitle("Jet pT");
    xjghist->SetYTitle("xjg");
    
    TH2F *subxjghist= new TH2F("subxjghist","subxjghist",160,0,80,75,0,3);
    subxjghist->SetXTitle("Jet pT");
    subxjghist->SetYTitle("xjg");
    
    TH2F *mixxjghist= new TH2F("mixxjghist","mixxjghist",160,0,80,62,0,2.5);
    mixxjghist->SetXTitle("Jet pT");
    mixxjghist->SetYTitle("xjg");
    
    TH2F *submixxjghist= new TH2F("submixxjghist","submixxjghist",160,0,80,75,0,3);
    submixxjghist->SetXTitle("Jet pT");
    submixxjghist->SetYTitle("xjg");
    
    TH2F *jetdraw= new TH2F("jetdraw","jetdraw",20,-1,1,30,0,pi);
    jetdraw->SetXTitle("#eta");
    jetdraw->SetYTitle("#phi");
    
    TH1F* mixedptspec = new TH1F("mixedptspec","mixedptspec",150,-50,100);
    TH1F* comboptspec = new TH1F("comboptspec","comboptspec",150,-50,100);
    
    TH2F *xjgsubxjg= new TH2F("xjgsubxjg","xjgsubxjg",45,0,1.5,45,0,1.5);
    xjgsubxjg->SetXTitle("xjg");
    xjgsubxjg->SetYTitle("subxjg");
    
    TH1 *gammaprob= new TH1F("gammaprob","gammaprob",1,ptmin,ptmax);
    
    TH1 *gammaeta= new TH1F("gammaeta","gammaeta",20,-2,2);
    
    TH1 *partonprob= new TH1F("partonprob","partonprob1",1,ptmin,ptmax);
    
    TH1 *partontot= new TH1F("partontot","partontot",40,-2,2);
    TH1 *gammatot= new TH1F("gammatot","gammatot",40,-2,2);
    TH1 *jettot= new TH1F("jettot","jettot",40,-2,2);
    
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
         */
        
        
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
    
    TFile *file1 = TFile::Open(OutFileName.Data(),"UPDATE");

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
