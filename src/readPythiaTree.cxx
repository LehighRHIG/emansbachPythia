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
    const char *defaults[7] = {"readPythiaTree","test.root","in","2","150","jets","mixedevent"};
    if ( argc==1 ) {
        argv=defaults;
        argc=8;
    }

    TString InFileName = argv[1];
    cout<<"In file is "<<InFileName.Data()<<endl;
    
    TString InFileName2 = argv[6];
    cout<<"In file is "<<InFileName2.Data()<<endl;
    
    TString OutFileName = argv[2];
    if (OutFileName == "in"){
        OutFileName = InFileName;
        OutFileName.Append(".jets.root");
    }
    cout<<"Out file is "<<OutFileName.Data()<<endl;
    
    float ptconsmin = atof(argv[4])/1000.; //constiuent cut
    cout<<"min pt cut = "<<ptconsmin<<endl;
    
    //names for branches
    TString jetname = argv[5];
    jetname.Append("_R0");
    jetname.Append(argv[3]);
    jetname.Append("0_ptmin");
    jetname.Append(argv[4]);
    
    TString backjet="background";
    backjet.Append(argv[5]);
    backjet.Append("_R0");
    backjet.Append(argv[3]);
    backjet.Append("0_ptmin");
    backjet.Append(argv[4]);
    
    TString combo="combo";
    combo.Append(argv[5]);
    combo.Append("_R0");
    combo.Append(argv[3]);
    combo.Append("0_ptmin");
    combo.Append(argv[4]);
    
    TString jetarea="jetarea";
    jetarea.Append(argv[5]);
    jetarea.Append("_R0");
    jetarea.Append(argv[3]);
    jetarea.Append("0_ptmin");
    jetarea.Append(argv[4]);
    
    TString backjetarea="backjetarea";
    backjetarea.Append(argv[5]);
    backjetarea.Append("_R0");
    backjetarea.Append(argv[3]);
    backjetarea.Append("0_ptmin");
    backjetarea.Append(argv[4]);
    
    TString combojetarea="combojetarea";
    combojetarea.Append(argv[5]);
    combojetarea.Append("_R0");
    combojetarea.Append(argv[3]);
    combojetarea.Append("0_ptmin");
    combojetarea.Append(argv[4]);
    
    TString sub="sub";
    sub.Append(argv[5]);
    sub.Append("_R0");
    sub.Append(argv[3]);
    sub.Append("0_ptmin");
    sub.Append(argv[4]);
    
    TString mixs="mix";
    
    float radius = atof(argv[3])/10.;
    cout<<"R = "<<radius<<endl;
    cout<<"Jet name = "<<jetname.Data()<<endl;
    cout<<"Background jet name = "<<backjet.Data()<<endl;
    cout<<"Combination jet name= "<<combo.Data()<<endl;
    cout<<"jet area name= "<<jetarea<<endl;
    cout<<"backjet area name= "<<backjetarea<<endl;
    cout<<"combojet area name= "<<combojetarea<<endl;
    cout<<"sub file= "<<sub<<endl;
    
    
    TFile *_file3 = TFile::Open(InFileName2);
    TTree* mix = (TTree*)gROOT->FindObject("mixed");
    TClonesArray *mixed = new TClonesArray("TLorentzVector");
    TBranch* bmixed = mix->GetBranch("mixone");
    bmixed->SetAddress(&mixed);
    
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
    //TClonesArray *comboparticles = new TClonesArray("TLorentzVector");
    //TBranch* bcomboparticles = tree->GetBranch("Combination");
    //bcomboparticles->SetAddress(&comboparticles);
    
    //open output file
    TFile *file1 = TFile::Open(OutFileName.Data(),"RECREATE");
    Int_t entries = tree->GetEntries();
    cout<<"Entries = "<<entries<<endl;
    
    //copy existing tree
    TTree* newtree = tree->CloneTree(0);
    //Make new branch for jet collection
    TClonesArray *jetsclone = new TClonesArray("TLorentzVector");
    newtree->Branch(jetname.Data(),&jetsclone);
    TClonesArray *backjets = new TClonesArray("TLorentzVector");
    newtree->Branch(backjet.Data(),&backjets);
    TClonesArray *combojets = new TClonesArray("TLorentzVector");
    newtree->Branch(combo.Data(),&combojets);
    TClonesArray *jetsarea= new TClonesArray("TParameter<double>");
    newtree->Branch(jetarea.Data(),&jetsarea);
    TClonesArray *backgroundarea= new TClonesArray("TParameter<double>");
    newtree->Branch(backjetarea.Data(),&backgroundarea);
    TClonesArray *combojetsarea= new TClonesArray("TParameter<double>");
    newtree->Branch(combojetarea.Data(),&combojetsarea);
    TClonesArray *jetssub = new TClonesArray("TLorentzVector");
    newtree->Branch(sub.Data(),&jetssub);
    TClonesArray *mixedspeccombo = new TClonesArray("TParameter<double>");
    newtree->Branch("speccombo",&mixedspeccombo);
   
    //mixed event branches adn tree
    TTree* mixedtree  = new TTree("mixed","mixed event");
    TClonesArray *mixedsubjet = new TClonesArray("TLorentzVector");
    mixedtree->Branch(mixs.Data(),&mixedsubjet);
    TClonesArray *mixedspec = new TClonesArray("TParameter<double>");
    mixedtree->Branch("spec",&mixedspec);
    TClonesArray *mixedjets = new TClonesArray("TLorentzVector");
    mixedtree->Branch("mixedjets",&mixedjets);

    
    //Create the collection of pseudo jets to be used in jet finding
    vector<PseudoJet> particles_jets;
    vector<PseudoJet> backparticles_jets;
    vector<PseudoJet> combo_jets;
    vector<PseudoJet> subtracted_jets;
    vector<PseudoJet> mixed_jets;
    vector<PseudoJet> msub_jets;
    vector<PseudoJet> comselect_jets;
    //Define background and signal jets
    JetDefinition jet_def(antikt_algorithm, radius);
    JetDefinition kt_def(kt_algorithm, radius);
    
    //Some specifications for ghost particles
    double ghost_maxrap = 1.5;
    GhostedAreaSpec area_spec(ghost_maxrap);
    AreaDefinition area_def(active_area, area_spec);
    AreaDefinition area_def_bkgd(active_area_explicit_ghosts, GhostedAreaSpec(ghost_maxrap));
    Int_t jetcount=0;
    Int_t backcount=0;
    Int_t comcount=0;
    
    //background condidtions
    Selector selector = SelectorAbsRapMax(1.0) * (!SelectorNHardest(2));
    
    
    //FOR MIXED EVENT
    //make background and subtractor
    JetMedianBackgroundEstimator mixback(selector ,kt_def,area_def_bkgd);
    Subtractor mixedsub(&mixback);
    
    for(int ev=0;ev<50;ev++){
        if (ev % 5 == 0)
            cout<<"Event "<<ev<<endl;
        mixed_jets.clear();
        msub_jets.clear();
        mix->GetEntry(ev);
        bmixed->GetEntry(ev);
        Int_t mtrk=mixed->GetEntriesFast();
        //cout<<mtrk<<endl;
        for(int i=0;i<mtrk;i++){
            TLorentzVector* m = (TLorentzVector*)mixed->At(i);
            if (m->Pt()< ptconsmin)
                continue;
            mixed_jets.push_back( PseudoJet(m->X(),m->Y(),m->Z(),m->E()));
        }
        mixback.set_particles(mixed_jets);
        Double_t rhom=mixback.rho();
        Double_t sigmam=mixback.sigma();
        ClusterSequenceArea ms(mixed_jets, jet_def, area_def);
        vector<PseudoJet> mjets = sorted_by_pt(ms.inclusive_jets());
        Int_t accJets=0;
        for (unsigned i = 0; i < mjets.size(); i++){
            TLorentzVector* d = new TLorentzVector(mjets[i].px(),mjets[i].py(),mjets[i].pz(),mjets[i].E());
            new ((*mixedjets)[accJets]) TLorentzVector(*d);
            accJets++;
            delete d;
        }
        msub_jets=mixedsub(mjets);
        accJets=0;
        for (unsigned i = 0; i < msub_jets.size(); i++){
        //if (fabs(jets[i].eta())>1)
        //  continue;
            TLorentzVector* e = new TLorentzVector(msub_jets[i].px(),msub_jets[i].py(),msub_jets[i].pz(),msub_jets[i].E());
            new ((*mixedsubjet)[accJets]) TLorentzVector(*e);
            accJets++;
            delete e;
        }
        double marea=0;
        TParameter<double> ptspec;
        for(int j=0;j<mjets.size();j++){
            marea=mjets[j].area();
            ptspec.SetVal((mjets[j].E())-(mixback.rho(mjets[j])*marea));
        //cout<<((mjets[j].E())-(mixback.rho(mjets[j])*marea))<<endl;
            new ((*mixedspec)[j]) TParameter<double> (ptspec);
            ptspec.Clear();
        }
        mixedtree->Fill();
        mjets.clear();
    }
    mixedtree->Write();
    
    
    //FOR ACTUAL EVENT
    //make background and subtractor 
    JetMedianBackgroundEstimator bgrest(selector ,kt_def,area_def_bkgd);
    Subtractor subtractor(&bgrest);
    
    for (Int_t iev = 0;iev<entries;iev++){
        if (iev % 1000 == 0)
            cout<<"Event "<<iev<<endl;
        //Loop over events;
        //First clear all the collections for nice memory management
        particles_jets.clear();
        jetsclone->Clear();
        backparticles_jets.clear();
        backjets->Clear();
        combojets->Clear();
        combo_jets.clear();
        jetsarea->Clear();
        backgroundarea->Clear();
        subtracted_jets.clear();
        jetssub->Clear();
        combojetsarea->Clear();
        comselect_jets.clear();
        
        //Load current event
        tree->GetEntry(iev);
        bparticles->GetEntry(iev);
        bBackground->GetEntry(iev);
        //bcomboparticles->GetEntry(iev);
        
        Int_t ntrk = particles->GetEntriesFast();
        Int_t nbtrk= backparticles->GetEntriesFast();
        //Int_t nctrk= comboparticles->GetEntriesFast();
        for (int itrk = 0;itrk<nbtrk;itrk++){
            //Loop over tracks and push them into the vector of pseudo vectors
            TLorentzVector* b = (TLorentzVector*)backparticles->At(itrk);
            if (b->Pt()< ptconsmin)
                continue;
            //backparticles_jets.push_back( PseudoJet(b->X(),b->Y(),b->Z(),b->E()));
            combo_jets.push_back( PseudoJet(b->X(),b->Y(),b->Z(),b->E()));
        }
        ClusterSequenceArea bs(backparticles_jets, jet_def, area_def);
        vector<PseudoJet> groundjets = sorted_by_pt(bs.inclusive_jets());
        bgrest.set_particles(backparticles_jets);
        //Double_t rho=bgrest.rho();
        //Double_t sigma=bgrest.sigma();
        int accJets=0;
        TParameter<double> backareaR;
        for (unsigned i = 0; i < groundjets.size(); i++) {
            //if (fabs(jets[i].eta())>1)
            //  continue;
            TLorentzVector* f = new TLorentzVector(groundjets[i].px(),groundjets[i].py(),groundjets[i].pz(),groundjets[i].E());
            new ((*backjets)[accJets]) TLorentzVector(*f);
            backareaR.SetVal(groundjets[i].area());
            new ((*backgroundarea)[accJets]) TParameter<double> (backareaR);
            accJets++;
            delete f;
            backareaR.Clear();
        }
        for (int itrk = 0;itrk<ntrk;itrk++){
            //Loop over tracks and push them into the vector of pseudo vectors
            TLorentzVector* t = (TLorentzVector*)particles->At(itrk);
            if (t->Pt()< ptconsmin)
                continue;
            particles_jets.push_back( PseudoJet(t->X(),t->Y(),t->Z(),t->E()));
            combo_jets.push_back( PseudoJet(t->X(),t->Y(),t->Z(),t->E()));
        }
        //run jet finder
        ClusterSequenceArea cs(particles_jets, jet_def, area_def);
        vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());
        Int_t aaccJets = 0;
        TParameter<double> areaR;
        for (unsigned i = 0; i < jets.size(); i++) {
            //if (fabs(jets[i].eta())>1)
            //  continue;
            TLorentzVector* j = new TLorentzVector(jets[i].px(),jets[i].py(),jets[i].pz(),jets[i].E());
            new ((*jetsclone)[aaccJets]) TLorentzVector(*j);
            areaR.SetVal(jets[i].area());
            new ((*jetsarea)[aaccJets]) TParameter<double> (areaR);
            aaccJets++;
            delete j;
            areaR.Clear();
        }
        ClusterSequenceArea coms(combo_jets, jet_def, area_def);
        bgrest.set_particles(combo_jets);
        Double_t rho=bgrest.rho();
        Double_t sigma=bgrest.sigma();
        vector<PseudoJet> comjets = sorted_by_pt(coms.inclusive_jets());
        for(int j=0;j<comjets.size();j++){
            if(comjets[j].E()>1)
                comselect_jets.push_back(comjets[j]);
        }
    
        /*Int_t cjet=0;
        Int_t areajet=0;
        TParameter<double> comboareaR;
        for (unsigned i = 0; i < comjets.size(); i++) {
            //if (fabs(jets[i].eta())>1)
            //  continue;
                TLorentzVector* c = new TLorentzVector(comjets[i].px(),comjets[i].py(),comjets[i].pz(),comjets[i].E());
            if(c->Pt()>1){
                comboareaR.SetVal(comjets[i].area());
                new ((*combojets)[cjet]) TLorentzVector(*c);
                new ((*combojetsarea)[areajet]) TParameter<double> (comboareaR);
                cjet++;
                areajet++;
                delete c;
            }
           // comboareaR.Clear();
        }*/
        aaccJets=0;
        subtracted_jets=subtractor(comjets);
        for (unsigned i = 0; i < subtracted_jets.size(); i++) {
            //if (fabs(jets[i].eta())>1)
            //  continue;
            TLorentzVector* t = new TLorentzVector(subtracted_jets[i].px(),subtracted_jets[i].py(),subtracted_jets[i].pz(),subtracted_jets[i].E());
            new ((*jetssub)[aaccJets]) TLorentzVector(*t);
            aaccJets++;
            delete t;
        }
        double carea=0;
        TParameter<double> cptspec;
        for(int j=0;j<comselect_jets.size();j++){
            carea=comjets[j].area();
            cptspec.SetVal((comselect_jets[j].E())-(bgrest.rho(comselect_jets[j])*carea));
            //cout<<((mjets[j].E())-(mixback.rho(mjets[j])*marea))<<endl;
            new ((*mixedspeccombo)[j]) TParameter<double> (cptspec);
            cptspec.Clear();
        }

        //cout<<cjet<<endl;
        //cout<<areajet<<endl;
        newtree->Fill();
    }
    newtree->Write();
    return 0;


}
