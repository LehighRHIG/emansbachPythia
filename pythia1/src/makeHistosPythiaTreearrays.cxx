
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

    Int_t summ= 0;
    Int_t entries = tree->GetEntries();
    /*
    for (Int_t iev = 0;iev<entries;iev++){
        //Looping over number of events
        if (iev % 1000 == 0)
            cout<<"Event "<<iev<<endl;
        
        //Get all the particles in the event
        tree->GetEntry(iev);
        bHardPartons->GetEntry(iev);
        bHardPartonNames->GetEntry(iev);
        bparticles->GetEntry(iev);
        
        //loop over final state particles
        Int_t nparticles = particles->GetEntriesFast();
        cout<<nparticles<<endl;
        summ=summ + nparticles;
    
    } */
    //cout<<summ<<endl;
   // initialize arrays
    Double_t momentum[entries][100];
    Double_t angle[entries][100];
    Int_t r=0;
    for (Int_t iev = 0;iev<entries;iev++){
        //Looping over number of events
        if (iev % 1000 == 0)
            cout<<"Event "<<iev<<endl;
        
        //Get all the particles in the event
        tree->GetEntry(iev);
        bHardPartons->GetEntry(iev);
        bHardPartonNames->GetEntry(iev);
        bparticles->GetEntry(iev);
        
        //loop over final state particles
         Int_t nparticles = particles->GetEntriesFast();
        for (int ip = 0; ip<nparticles;ip++){
            //Find each particle
            TLorentzVector* particle = (TLorentzVector*)particles->At(ip);
            
            //Fill arrays
            momentum[iev][ip]=particle->Pt();
            angle[iev][ip]=particle->Phi();
            
            //Manipulate particles and fill histograms
            hParticlepT->Fill(particle->Pt());
            hParticleEtaPhi->Fill(particle->Eta(),particle->Phi());
          //  hParticlesPhiCount->Fill(particle->Phi());
            //hParticlesEtaCount->Fill(particle->Eta());
        }
        r=r+nparticles;
        
    } //end of event loop
    
/////////////////Faster code////////////////////////////////////////////////////////////////////
    Double_t trigmin = 2.5;
    Double_t trigmax = 3.0;
    Double_t assocmin=2.5;
    Double_t assocmax=4.0;
    Double_t doublepi= 2*TMath::Pi();
    histname="deltphi";
    Int_t binsize= 50;
    Double_t count=0.0;
    TH1F *deltphi= new TH1F(histname,"trig:2.5-3.0 Gev, assoc:2.5-4.0 Gev",binsize,-1,doublepi-1);
    deltphi->SetXTitle("dphi");
    deltphi->SetYTitle("normalized counts");
    for(int i=0;i<entries;i++){
        for(int k=0;k<100;k++){
        if((momentum[i][k]<trigmax)&&(momentum[i][k]>trigmin)){
            for(int j=0;j<100;j++){
                if((momentum[i][j]<assocmax)&&(momentum[i][j]>assocmin)&&(k!=j)){
                    if((angle[i][k]-angle[i][j])< -1)
                        deltphi->Fill(angle[i][k]-angle[i][j]+doublepi);
                    else if((angle[i][k]-angle[i][j])>(doublepi-1))
                        deltphi->Fill(angle[i][k]-angle[i][j]-doublepi);
                    else{
                        deltphi->Fill(angle[i][k]-angle[i][j]);
                    }
                    
                }
            }
            count++;
        }
    }
    }
    deltphi->Scale(1.0/(binsize*count));
    cout<<count<<endl;
    
////Explicit code//////////////////////////////////////////////////////////////////////////////////
  /*  //Code to select triggers and loop through data looking for trigger particles
    Double_t trigmin = 6.0;
    Double_t trigmax = 10.0;
    Int_t count=0;
    for(int i=0;i<summ;i++){
        if((momentum[i]<trigmax)&&(momentum[i]>trigmin)){
            count++;
        }
    }
    Double_t trigptarray[count];
    Double_t triganglearray[count];
    Int_t j=0;
    for(int i=0;i<summ;i++){
        if((momentum[i]<trigmax)&&(momentum[i]>trigmin)){
            trigptarray[j]=momentum[i];
            triganglearray[j]=angle[i];
            j++;
        }
    }

    //Code to select associated particles and loop through data looking for assoc particles
    Double_t assocmin=2.5;
    Double_t assocmax=4.0;
    Int_t counts=0;
    for(int i=0;i<summ;i++){
        if((momentum[i]<assocmax)&&(momentum[i]>assocmin)){
            counts++;
        }
    }
    Double_t assocptarray[counts];
    Double_t assocanglearray[counts];
    Int_t k=0;
    for(int i=0;i<summ;i++) {
        if((momentum[i]<assocmax)&&(momentum[i]>assocmin)){
            assocptarray[k]=momentum[i];
            assocanglearray[k]=angle[i];
            k++;
        }
    }

    //Code to measure deltaphi between trigger particles and the associated particles
    Int_t number= count*counts;
    Double_t dphi[number];
    Double_t doublepi= 2*TMath::Pi();
    Int_t binsize= 25;
    histname="deltphi";
    TH1F *deltphi= new TH1F(histname,histname,binsize,-1,doublepi-1);
    Int_t p=0;
    for(int i=0;i<count;i++){
        for(int j=0;j<counts;j++){
            if((triganglearray[i]-assocanglearray[j])<-1){
                Double_t ang = triganglearray[i]-assocanglearray[j]+doublepi;
                deltphi->Fill(ang);
            }
            else if((triganglearray[i]-assocanglearray[j])>(-1+doublepi)){
                Double_t angs = triganglearray[i]-assocanglearray[j]-doublepi;
                deltphi->Fill(angs);
            }
            else {
                deltphi->Fill(triganglearray[i]-assocanglearray[j]);
            }
        }
    }
    
    
    //test loop of dphi arrray, something wrong? The values are being recorded but I can't use them, too many values
    //for(int i=0;i<number;i++){
      //  cout<<dphi[i]<<endl;
    //}
    //Code to create histogram of deltaphi vs counts

  
    //MEEED TO FIX THE ILLEGAL INSTRUCTION ERROR!!! HOW TO TAKE ARRAY ADN PUT IT IN HISTOGRAM FORM? there are over 22 million points to put into the histogram. May be too much.
//////////////////////////////////////////////////////////////////////////////////////////////// */

    TFile *file1 = TFile::Open(OutFileName.Data(),"RECREATE");

    hHardPartonspT->Write();
    hHardPartonsName->Write();
    hParticlepT->Write();
    hParticleEtaPhi->Write();
    deltphi->Write();

}
