#include "TSystem.h"
#include "TROOT.h"
#include "Tfile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TClonesArray.h"
#include "TBranch.h"
#include "TLorentzVector.h"
#include "TParameter.h"
#include "TRandom3.h"
#include <iostream>
#include <cmath>
#include <exception>
#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"
#include "fastjet/ClusterSequenceArea.hh"
#include "fastjet/ClusterSequenceActiveArea.hh"
#include "fastjet/Selector.hh"
#include "fastjet/tools/JetMedianBackgroundEstimator.hh"
#include "fastjet/tools/Subtractor.hh"
#include "fastjet/tools/GridMedianBackgroundEstimator.hh"

using namespace fastjet;
using namespace std;


int main(int argc, const char** argv)
{
    const char *defaults[2] = {"mixed","test.root"};
    if ( argc==1 ) {
        argv=defaults;
        argc=8;
    }

    TString InFileName = argv[1];
    cout<<"In file is "<<InFileName.Data()<<endl;
    
    TString OutFileName = argv[2];
    if (OutFileName == "in"){
        OutFileName = InFileName;
        OutFileName.Append(".jets.root");
    }
    cout<<"Out file is "<<OutFileName.Data()<<endl;
    
    TFile *_file0 = TFile::Open(InFileName);
    
    
    //read tree
    TTree* tree = (TTree*)gROOT->FindObject("tree");
    //tree->Print();
    //read collections
    TClonesArray *particles = new TClonesArray("TLorentzVector");
    TBranch* bparticles = tree->GetBranch("Particles");
    bparticles->SetAddress(&particles);
    TClonesArray *backparticles = new TClonesArray("TLorentzVector");
    TBranch* bBackground = tree->GetBranch("Background");
    bBackground->SetAddress(&backparticles);

    //open output file
    TFile *fout = TFile::Open(OutFileName.Data(),"RECREATE");
    Int_t entries = tree->GetEntries();
    cout<<"Entries = "<<entries<<endl;
    
    //Make new tree
     TTree* mixed  = new TTree("mixed","mixed event");
    //Make new branch for jet collection

    TClonesArray mixedone("TLorentzVector",5000);
    mixed->Branch("mixone", &mixedone);
    
    Int_t nev=0;
    Int_t nevent=50;
    TRandom3* rdm= new TRandom3;
    rdm->SetSeed(41896);

    while(nev<nevent){
        Int_t seed=rdm->Integer(10000);
        TRandom3* num= new TRandom3;
        num->SetSeed(seed);
        if(nev%5==0)
            cout<<nev<<endl;
        int place=0;
    for (Int_t i = 0;i<1052;i++){
        if(i>999){
            Int_t rev=num->Integer(5000);
            tree->GetEntry(rev);
            bparticles->GetEntry(rev);
            Int_t ntrk=particles->GetEntriesFast();
            if(ntrk>0){
                Int_t rtrk=num->Integer(ntrk);
                TLorentzVector* m = (TLorentzVector*)particles->At(rtrk);
                if(m->Pt()>2){
                    int divide= ceil(m->Pt());
                    double mult= num->Integer(divide);
                    for (int f=1;f<=mult;f++){
                        TLorentzVector* d= new TLorentzVector();
                        double r;
                        r=num->Rndm();
                        double phid = TMath::Pi()*2.*r;
                        d->SetPtEtaPhiM((m->Pt()/mult),m->Eta(),phid,0);
                        new ( mixedone[place]) TLorentzVector ( *d ) ;
                        place++;
                    }
                }
                else{
                    new ( mixedone[place]) TLorentzVector ( *m ) ;
                    place++;
                
                }
            }
        }
        if(i<1000){
            double rand; double pT; double phi; double eta;
            double pT0=0.5000;
                rand = num->Rndm();
                pT = -pT0*log(1 - rand);
                while(pT<.2) {
                    rand = num->Rndm();
                    pT = -pT0*log(1 - rand);
                }
                // hpT->Fill(pT);
                rand = num->Rndm();
                phi = TMath::Pi()*2.*rand;
                // hPhi->Fill(phi);
                rand = num->Rndm();
                eta = 2*(rand-0.5);
                //hEta->Fill(eta);
                TLorentzVector* t = new TLorentzVector();
                t->SetPtEtaPhiM(pT,eta,phi,0);
                new ( mixedone[place]) TLorentzVector(*t);
            place++;
                //new ( Combination[trackcount+i]) TLorentzVector ( *t ) ;
        }

            /*Int_t rev=num->Integer(5000);
            tree->GetEntry(rev);
            bBackground->GetEntry(rev);
            Int_t ftrk=backparticles->GetEntriesFast();
            if(ftrk>0){
                Int_t atrk=num->Integer(ftrk);
                TLorentzVector* m = (TLorentzVector*)backparticles->At(atrk);
                new ( mixedone[i]) TLorentzVector ( *m ) ;
            }*/
    
    }
    mixed->Fill();
    nev++;
    }
    mixed->Write();
    fout->Write();
    fout->Close();
    return 0;


}
