#include "Pythia.h"

#include <iostream>
#include <string>
#include <sstream>

#include "TROOT.h"
#include "TMath.h"
#include "TString.h"
#include "TObjString.h"
#include "TFile.h"
#include "TH1.h"
#include "TTree.h"
#include "TF1.h"
#include "TLorentzVector.h"
#include "TClonesArray.h"
#include "TParameter.h"
#include "TRandom.h"
#include "TRandom3.h"

using namespace std;
using namespace Pythia8;


int ReturnPdgValue(string name){
        
        //TString InFileName = argv[1];
        //cout<<"In file is "<<InFileName.Data()<<endl;
    //Function gives convenient particle names
    int particlenumber = -1000;
    if (name == "d")
        particlenumber = 1;
    if (name == "u")
        particlenumber = 2;
    if (name == "s")
        particlenumber = 3;
    if (name == "c")
        particlenumber = 4;
    if (name == "b")
        particlenumber = 5;
    if (name == "dbar")
        particlenumber = -1;
    if (name == "ubar")
        particlenumber = -2;
    if (name == "sbar")
        particlenumber = -3;
    if (name == "cbar")
        particlenumber = -4;
    if (name == "bbar")
        particlenumber = -5;
    if (name == "g")
        particlenumber = 21;
    if (name == "gamma")
        particlenumber = 22;
    if(name=="e+")
        particlenumber= 30;
    if(name=="e-")
        particlenumber= 31;
    if(name=="pi0")
        particlenumber= 32;
    
    return particlenumber;
}

Int_t main(int argc, const char** argv) {

  // Set up output file
    const char *defaults[2] = {"PythiaTree","50"};
    if ( argc==1 ) {
        argv=defaults;
        argc=2;
    }
  TFile * fout = new TFile("pytest15.root","recreate");
    
    // Generator. Shorthand for event (use FastJet3 and Pythia8 interface!!!)
    //------------------------------------------------------------------------
    
    //Choose collision energies
    Float_t ptHatMin=atof(argv[1]);
    Float_t ptHatMax=500.0;
    
    //Points to location of Pythia 8
    Pythia pythia("/Users/emansbach/pythia8219/share/Pythia8/xmldoc");
    Event& event = pythia.event;

    // Process selection.
    pythia.readString("Beams:eCM = 200.");
    //pythia.readString("HardQCD:all = on");
    pythia.readString("HadronLevel:Decay = on");
    pythia.readString("PartonLevel:ISR = on");
    pythia.readString("PartonLevel:FSR = on");
    //pythia.readString("PromptPhoton:qg2qgamma = on"); // turn on prompt photons
    pythia.readString("PromptPhoton:all = on");
    
    stringstream numbf(stringstream::app|stringstream::in|stringstream::out);
    numbf.setf(ios::fixed, ios::floatfield);
    numbf.setf(ios::showpoint);
    numbf.precision(1);
    numbf.str("PhaseSpace:pTHatMin = "); numbf << ptHatMin;
    string pmin=numbf.str();
    numbf.str("PhaseSpace:pTHatMax = "); numbf << ptHatMax;
    string pmax=numbf.str();
    
    cout<<pmin<<endl;
    cout<<pmax<<endl;
    
    pythia.readString(pmin);
    pythia.readString(pmax);
    // No event record printout.
    pythia.readString("Next:numberShowInfo = 1");
    pythia.readString("Next:numberShowProcess = 1");
    pythia.readString("Next:numberShowEvent = 1");
    
    // LHC initialization.
    //pythia.init(2212, 2212,5020.);
    // pythia.init(2212, 2212,2760.);
    
    // RHIC initialization.
//    pythia.init(2212, 2212,200.);
    pythia.init();
    
    // Set up tree
    // -----------
    static const Int_t kmaxT=5000; // Max # of particles per event

    TTree* tree  = new TTree("tree","Some pythia jets");
    TClonesArray Particles("TLorentzVector",kmaxT);
    tree->Branch("Particles", &Particles);
    TClonesArray Background("TLorentzVector",kmaxT);
    tree->Branch("Background", &Background);
    TClonesArray ReconstructedParticles("TLorentzVector",kmaxT);
    tree->Branch("ReconstructedParticles",&ReconstructedParticles);
    TClonesArray ReconTower("TParameter<int>",kmaxT);
    tree->Branch("ReconTower",&ReconTower);
    TClonesArray ReconEtaTower("TParameter<int>",kmaxT);
    tree->Branch("ReconEtaTower",&ReconEtaTower);
    TClonesArray ReconPhiTower("TParameter<int>",kmaxT);
    tree->Branch("ReconPhiTower",&ReconPhiTower);
    TClonesArray ReconNames("TParameter<int>",kmaxT);
    tree->Branch("ReconNames", &ReconNames);
  //  TClonesArray Combination("TLorentzVector",kmaxT);
   // tree->Branch("Combination", &Combination);

    
    // The original outgoing hard partons, status -23
    TClonesArray HardPartons("TLorentzVector",kmaxT);
    tree->Branch("HardPartons", &HardPartons);
    TClonesArray HardPartonNames("TParameter<int>",kmaxT);
    tree->Branch("HardPartonNames", &HardPartonNames);
    
    // Generate events
    //We use a do-while loop rather than a for loop because we may wish to
    //select a certain type of event.  So we want to be able to set the number
    //of selected events (nEvent)
    int nEv = 0;
    Int_t nEvent = 5000;
    TRandom3* random = new TRandom3;
    random->SetSeed(5000);
    Double_t pi=TMath::Pi();
    do {
        if (!pythia.next()) continue;
        
        Particles.Clear();
        ReconstructedParticles.Clear();
        HardPartons.Clear();
        HardPartonNames.Clear();
        ReconTower.Clear();
        ReconEtaTower.Clear();
        ReconPhiTower.Clear();
        ReconNames.Clear();
        
        // Grab particles
        int fkTrack=0;
        int fkHard=0;
        int fkPhoton = 0;
        
        int recontrack=0;
        
        int Ntracks = 1000;
        float pT0 = 0.500;
        int trackcount=0;
        
        for (int nP = 0; nP<event.size() ; ++nP ){
            
            if ( nP<3 )continue;      // 0, 1, 2: total event and beams
            
            Particle& particle = event[nP];
            // Save hardest partons (initial partons)
            // --------------------
            
            if ( particle.status()==-23 ){
                Vec4 pv = particle.p();
                TParameter<int> namenumber;
                namenumber.SetVal(ReturnPdgValue(particle.name().data()));
                new ( HardPartons[fkHard]) TLorentzVector ( pv.px(), pv.py(), pv.pz(), pv.e() ) ;
                new ( HardPartonNames[fkHard]) TParameter<int> (namenumber);
                fkHard++;
                /*TLorentzVector* p=new TLorentzVector();
                p->SetPxPyPzE( pv.px(), pv.py(), pv.pz(), pv.e() );
                if((particle.name()=="gamma")&&(fabs(p->Eta())<1)){
                    new( ReconstructedParticles[recontrack]) TLorentzVector(*p);
                    TParameter<int> tower;
                    TParameter<int> etower;
                    TParameter<int> ptower;
                    int x=600000;
                    int y=-1;
                    if(p->Eta()==-1){
                        x=1;
                        y= ceil(((60*(p->Phi()))/pi)+60);
                    }
                    else if(p->Phi()==(pi*-1)){
                        y=1;
                        x= ceil((20*(p->Eta()))+20);
                    }
                    else{
                        x= ceil((20*(p->Eta()))+20);
                        y= ceil(((60*(p->Phi()))/pi)+60);
                    }
                    tower.SetVal(x+((y-1)*40));
                    etower.SetVal(x);
                    ptower.SetVal(y);
                    new ( ReconTower[recontrack]) TParameter<int> (tower);
                    new ( ReconEtaTower[recontrack]) TParameter<int> (etower);
                    new ( ReconPhiTower[recontrack]) TParameter<int> (ptower);
                    new ( ReconNames[recontrack]) TParameter<int> (namenumber);
                    recontrack++;
                }*/
            }
            
            //Next save final state particles
            if ( !particle.isFinal() ) continue;
            
            // skip neutrinos
            if ( !particle.name().compare(0, 3, "nu_") ) continue;
            
            // skip neutral particles we can't see
            //if ( particle.name() == "K_L0"  ) continue;
            //if ( particle.name() == "n0"    ) continue;
            //if ( particle.name() == "nbar0" ) continue;
            
            /*if (
                particle.name() != "e+"    &&
                particle.name() != "e-"    &&
                particle.name() != "mu+"   &&
                particle.name() != "mu-"   &&
                particle.name() != "pi+"   &&
                particle.name() != "pi-"   &&
                particle.name() != "K+"    &&
                particle.name() != "K-"    &&
                particle.name() != "p+"    &&
                particle.name() != "pbar-" &&
                particle.name() != "gamma"
                )
                cout << particle.name() << endl;*/
                
                Vec4 pv = particle.p();
            
            
            // some preselections to cut down size and simulate STAR
            if ( pv.pT() < 0.2 ) continue;
            if ( fabs(pv.eta()) > 1.0 ) continue;
            TLorentzVector* p=new TLorentzVector();
            p->SetPxPyPzE( pv.px(), pv.py(), pv.pz(), pv.e() );
            new ( Particles[fkTrack] ) TLorentzVector (*p) ;
            //new ( Combination[fkTrack]) TLorentzVector ( pv.px(), pv.py(), pv.pz(), pv.e() ) ;
            
            
            //Code to Simlate STAR resolution and efficiency
           /* double eff=random->Rndm();
            if(fabs(p->Eta())<1){
                if((particle.name()=="gamma")||(particle.name()=="pi0")){
                    new( ReconstructedParticles[recontrack]) TLorentzVector(*p);
                    TParameter<int> tower;
                    TParameter<int> etower;
                    TParameter<int> ptower;
                    int x=600000;
                    int y=-1;
                    if(p->Eta()==-1){
                        x=1;
                        y= ceil(((60*(p->Phi()))/pi)+60);
                    }
                    else if(p->Phi()==(pi*-1)){
                        y=1;
                        x= ceil((20*(p->Eta()))+20);
                    }
                    else{
                        x= ceil((20*(p->Eta()))+20);
                        y= ceil(((60*(p->Phi()))/pi)+60);
                    }
                    tower.SetVal(x+((y-1)*40));
                    etower.SetVal(x);
                    ptower.SetVal(y);
                    new ( ReconTower[recontrack]) TParameter<int> (tower);
                    new ( ReconEtaTower[recontrack]) TParameter<int> (etower);
                    new ( ReconPhiTower[recontrack]) TParameter<int> (ptower);
                    TParameter<int> reconnumber;
                    reconnumber.SetVal(ReturnPdgValue(particle.name().data()));
                    new ( ReconNames[recontrack]) TParameter<int> (reconnumber);
                    recontrack++;
                    
                }
                if((particle.name()=="e+")||(particle.name()=="e-")){
                    if(eff<.8){
                    new( ReconstructedParticles[recontrack]) TLorentzVector(*p);
                    TParameter<int> tower;
                    TParameter<int> etower;
                    TParameter<int> ptower;
                    int x=600000;
                    int y=-1;
                    if(p->Eta()==-1){
                        x=1;
                        y= ceil(((60*(p->Phi()))/pi)+60);
                    }
                    else if(p->Phi()==(pi*-1)){
                        y=1;
                        x= ceil((20*(p->Eta()))+20);
                    }
                    else{
                        x= ceil((20*(p->Eta()))+20);
                        y= ceil(((60*(p->Phi()))/pi)+60);
                    }
                    tower.SetVal(x+((y-1)*40));
                    etower.SetVal(x);
                    ptower.SetVal(y);
                    new ( ReconTower[recontrack]) TParameter<int> (tower);
                    new ( ReconEtaTower[recontrack]) TParameter<int> (etower);
                    new ( ReconPhiTower[recontrack]) TParameter<int> (ptower);
                    TParameter<int> reconnumber;
                    reconnumber.SetVal(ReturnPdgValue(particle.name().data()));
                    new ( ReconNames[recontrack]) TParameter<int> (reconnumber);
                    recontrack++;
                    }
                }
               /* else{
                    if(eff<.8){
                    double ptres=random->Gaus(0,0.6);
                    double newpt;
                    newpt=(p->Pt())+((p->Pt())*ptres);
                    TLorentzVector* r = new TLorentzVector();
                    r->SetPtEtaPhiM(newpt,p->Eta(),p->Phi(),pv.e());
                    new( ReconstructedParticles[recontrack]) TLorentzVector(*r);
                    TParameter<int> tower;
                    TParameter<int> etower;
                    TParameter<int> ptower;
                    int x=600000;
                    int y=-1;
                    if(p->Eta()==-1){
                        x=1;
                        y= ceil(((60*(p->Phi()))/pi)+60);
                    }
                    else if(p->Phi()==0){
                        y=1;
                        x= ceil((20*(p->Eta()))+20);
                    }
                    else{
                        x= ceil((20*(p->Eta()))+20);
                        y= ceil(((60*(p->Phi()))/pi)+60);
                    }
                    tower.SetVal(x+((y-1)*40));
                    etower.SetVal(x);
                    ptower.SetVal(y);
                    new ( ReconTower[recontrack]) TParameter<int> (tower);
                    new ( ReconEtaTower[recontrack]) TParameter<int> (etower);
                    new ( ReconPhiTower[recontrack]) TParameter<int> (ptower);
                    recontrack++;
                    }
                }*/
            }
        
        
            
            ++fkTrack;
            trackcount++;
        }
        /*double rand; double pT; double phi; double eta;
            for (int i = 0;i<Ntracks;i++){
                rand = random->Rndm();
                pT = -pT0*log(1 - rand);
                while(pT<.2) {
                    rand = random->Rndm();
                    pT = -pT0*log(1 - rand);
                }
               // hpT->Fill(pT);
                rand = random->Rndm();
                phi = TMath::Pi()*2.*rand;
               // hPhi->Fill(phi);
                rand = random->Rndm();
                eta = 2*(rand-0.5);
                //hEta->Fill(eta);
                TLorentzVector* t = new TLorentzVector();
                t->SetPtEtaPhiM(pT,eta,phi,0);
                new ( Background[i]) TLorentzVector(*t);
                //new ( Combination[trackcount+i]) TLorentzVector ( *t ) ;
            }
        */
        tree->Fill();
        
        ++nEv;
    } while (nEv<nEvent);
//    pythia.statistics();
    fout->Write();
    fout->Close();
    
    return 0;
}

