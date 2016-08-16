
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
#include <TGraph.h>

using namespace std;

int main(int argc, const char** argv)
{
    const char *defaults[3] = {"readPythiaTree","test.root","in"};
    if ( argc==1 ) {
        argv=defaults;
        argc=3;
    }
    TString InFileName = argv[1];
    cout<<"In file is "<<InFileName.Data()<<endl;
    
    TString OutFileName = argv[2];
    cout<<"Out file is "<<OutFileName.Data()<<endl;
    

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
    TClonesArray *Tower = new TClonesArray("TParameter<int>");
    TBranch* bTower = tree->GetBranch("ReconTower");
    bTower->SetAddress(&Tower);
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
    
        TFile * fout = new TFile("towervectors.root","recreate");
    
    //Create new tree and branch for lorentz vectors for fastjet
    TTree* towertree  = new TTree("towertree","Tower Tracks for FastJet");
    TClonesArray TowerTracks("TLorentzVector",5000);
    towertree->Branch("TowerTracks", &TowerTracks);
    
    
    //TClonesArray *Background = new TClonesArray("TLorentzVector");
    //TBranch* bBackground = tree->GetBranch("Background");
    //bBackground->SetAddress(&Background);
    
    Double_t doublepi= 2*TMath::Pi();
    Double_t pi= TMath::Pi();
    
    TH1F *towerhist= new TH1F("towerhist","towerhist",4800,0,4800);
    towerhist->GetYaxis()->SetTitle("Tower Energy (GeV)");
    towerhist->GetXaxis()->SetTitle("Tower");
    
    TH2F *etaphi= new TH2F("etaphi","etaphi",40,-1,1,120,pi*-1,pi);
    etaphi->GetYaxis()->SetTitle("Phi");
    etaphi->GetXaxis()->SetTitle("Eta");
    
    TH1F *towerhistres= new TH1F("towerhistres","towerhistres",4800,0,4800);
    towerhistres->GetYaxis()->SetTitle("Tower Energy (GeV)");
    towerhistres->GetXaxis()->SetTitle("Tower");
    
    TH2F *etaphires= new TH2F("etaphires","etaphires",40,-1,1,120,pi*-1,pi);
    etaphires->GetYaxis()->SetTitle("Phi");
    etaphires->GetXaxis()->SetTitle("Eta");
    
    Int_t entries = tree->GetEntries();
    cout<<entries<<endl;
    //fill event hists
    //538-539

    for (Int_t iev =0;iev<entries;iev++){
        int count=0;
        int scount=0;
        TowerTracks.Clear();
        //Looping over number of events
        if (iev % 1000 == 0)
            cout<<"Event "<<iev<<endl;
        //Get all the particles in the event
        tree->GetEntry(iev);
        bHardPartons->GetEntry(iev);
        bHardPartonNames->GetEntry(iev);
        bparticles->GetEntry(iev);
        bTower->GetEntry(iev);
        breconparticles->GetEntry(iev);
        bEtaTower->GetEntry(iev);
        bPhiTower->GetEntry(iev);
        bReconName->GetEntry(iev);
       
        int track=0;
        TowerTracks.Clear();
        //loop over final state particles
        Int_t nparticles = particles->GetEntriesFast();
        Int_t nHardPartonNames=HardPartonNames->GetEntriesFast();
        Int_t nhardparton=HardPartons->GetEntriesFast();
        Int_t nreconparticles=reconparticles->GetEntriesFast();
        Double_t placearray[4801];
        for(int i=0;i<4801;i++)
            placearray[i]=0;
        Double_t eparray[41][121];
        for(int i=0;i<41;i++){
            for(int j=0;j<121;j++)
                eparray[i][j]=0;
        }
        Double_t tres[4801];
        cout<<nreconparticles<<endl;
        for(int i=0;i<nreconparticles;i++){
            
            
            TParameter<int>* source = (TParameter<int> *)Tower->At(i);
            Int_t tnumber=source->GetVal();
            if(tnumber<0) continue;
            TLorentzVector* rp=(TLorentzVector*)reconparticles->At(i);
            if(rp->E()==0) continue;
            double sum=towerhist->GetBinContent(tnumber);
            double increase=placearray[tnumber];
            placearray[tnumber]=increase+rp->E();
            if(placearray[tnumber]>0)
            towerhist->SetBinContent(tnumber,sum+placearray[tnumber]);
            source->Clear();
            
            
            
            
            TParameter<int>* teta = (TParameter<int> *)EtaTower->At(i);
            Int_t tetanumber=teta->GetVal();
            if(tetanumber<0) continue;
            TParameter<int>* tphi = (TParameter<int> *)PhiTower->At(i);
            Int_t tphinumber=tphi->GetVal();
            if(tphinumber<0) continue;
            double epsum=etaphi->GetBinContent(tetanumber,tphinumber);
            double epincrease=eparray[tetanumber][tphinumber];
            eparray[tetanumber][tphinumber]=epincrease+rp->E();
            etaphi->SetBinContent(tetanumber,tphinumber,epsum+eparray[tetanumber][tphinumber]);
            teta->Clear();
            tphi->Clear();
        }
        TRandom3* random = new TRandom3;
        random->SetSeed(5000);
        for(int i=1;i<4801;i++){
            double res=placearray[i];
            if(res>0) {
            res=res+(res*(random->Gaus(0,((.14/sqrt(res))+.015))));
            double newe=towerhistres->GetBinContent(i);
            newe=newe+res;
            towerhistres->SetBinContent(i,newe);
            }
        }
        int heta=-10;
        int hphi=-10;
        double etalocation=-11;
        double philocation=-11;
        double highest=0;
        for(int i=1;i<41;i++){
            for(int j=1;j<121;j++){
                double res=eparray[i][j];
                if (res>0) {
                    if(res>highest){
                        if(i>20)
                            etalocation=((i-20)/20.0)-.025;
                        else{
                            etalocation=((i-20)/20.0)+.025;
                        }
                    }
                    if(res>highest){
                        if(j>60)
                            philocation=(((j-60)*pi)/60)-.026;
                        else if(j<=60){
                            philocation=(((j-60)*pi)/60)+.026;
                        highest=res;
                        heta=i;
                        hphi=j;
                        }
                    }
                    res=res+(res*(random->Gaus(0,((.14/sqrt(res))+.015))));
                    double newe=etaphires->GetBinContent(i,j);
                    newe=newe+res;
                    etaphires->SetBinContent(i,j,newe);
                }
            }
        }
                        //FIRST CYCLE THROUGH AND FIND IF ANY TOWER WITHING RADIUS OF 0.2 A,D HAS MORE THAN HALF ENERGY AS HIGHEST. IF NOT, RECORD THE TOWERS AS LORENTZVECTORS AND CHECK IF THEY ARE ELECTRON OR POSITRON OR NOT
        
        //problem is on event 100, eta values are not being determined correctly
        int fail=0;
        for(int i=1;i<41;i++){
            for(int j=1;j<121;j++){
                 if((eparray[i][j]>0) && (eparray[i][j]!=highest)){
                    double testel=0;
                    double testpl=0;
                    if(i>20)
                        testel=((i-20)/20.0)-.025;
                    if(i<=20)
                        testel=((i-20)/20.0)+.025;
                    if(j>60)
                        testpl=(((j-60)*pi)/60)-.026;
                    if(j<=60)
                        testpl=(((j-60)*pi)/60)+.026;
                    double radius= sqrt(TMath::Power(etalocation-testel,2)+TMath::Power(philocation-testpl,2));
                     //cout<<radius<<endl;
                     if((radius<0.2)&&(eparray[i][j]>(highest/2))){
                         fail++;
                     }
                 }
            }
        }
        cout<<fail<<endl;
        if(fail==0){
        for(int i=1;i<41;i++){
            for(int j=1;j<121;j++){
                if((i==heta)&&(j==hphi)){
                    double pzz=(eparray[i][j]*sinh(etalocation));
                    double ptt=sqrt(TMath::Power(eparray[i][j],2)-TMath::Power(pzz,2));
                    double pxx=ptt*cos(philocation);
                    double pyy=ptt*sin(philocation);
                    TLorentzVector* p=new TLorentzVector();
                    p->SetPxPyPzE( pxx, pyy, pzz, eparray[i][j] );
                    new ( TowerTracks[track] ) TLorentzVector (*p);
                    track++;
                    scount++;
                }//if
                else if((eparray[i][j]>0) && (eparray[i][j]!=highest)){
                    double testel=0;
                    double testpl=0;
                    if(i>20)
                        testel=((i-20)/20.0)-.025;
                    if(i<=20)
                        testel=((i-20)/20.0)+.025;
                    if(j>60)
                        testpl=(((j-60)*pi)/60)-.026;
                    if(j<=60)
                        testpl=(((j-60)*pi)/60)+.026;
            
                    bool lv=true;
                    for(int n=0;n<nreconparticles;n++){
                        TLorentzVector* recon=(TLorentzVector*)reconparticles->At(n);
                        Double_t rpeta=recon->Eta();
                        Double_t rpphi=recon->Phi();
                        TParameter<int>* name = (TParameter<int> *)ReconName->At(n);
                        Int_t rname=name->GetVal();
                        if(((rname==30)||(rname==31))&&(rpeta<(testel+.025))&&(rpeta>(testel-.025))&&(rpphi<(testpl+.026))&&(rpphi>(testpl-.026))){
                            TLorentzVector* p=new TLorentzVector();
                            p->SetPxPyPzE( recon->Px(), recon->Py(), recon->Pz(), recon->E() );
                            new ( TowerTracks[track] ) TLorentzVector (*p);
                            track++;
                            scount++;
                            lv=false;
                        } //if
                    }//for
                        if(lv){
                            double pzz=(eparray[i][j]*sinh(testel));
                            double ptt=sqrt(TMath::Power(eparray[i][j],2)-TMath::Power(pzz,2));
                            double pxx=ptt*cos(testpl);
                            double pyy=ptt*sin(testpl);
                            TLorentzVector* p=new TLorentzVector();
                            p->SetPxPyPzE( pxx, pyy, pzz, eparray[i][j] );
                            new ( TowerTracks[track] ) TLorentzVector (*p);
                            track++;
                            scount++;
                            
                        }//if
                }//if
            }//for
        }//for
        }//if
        cout<<scount<<endl;
                            towertree->Fill();
    }


    //cout<<count<<endl;
    cout<<"Event "<<5000<<endl;
    towertree->Write();
    fout->Write();
    fout->Close();

    
    /*TFile *file1 = TFile::Open(OutFileName.Data(),"RECREATE");
    towerhist->Write();
    etaphi->Write();
    towerhistres->Write();
    etaphires->Write();*/
    

    
}
