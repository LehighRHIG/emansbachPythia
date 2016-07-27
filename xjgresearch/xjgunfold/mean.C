void mean(TString infile = "histos.root"){
    set_plot_style();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    
    
    TH1* array[30];
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* xjgjetone = (TH1*)gROOT->FindObject("unfold5p2");
    array[0]= xjgjetone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* xjgjettwo = (TH1*)gROOT->FindObject("unfold5p3");
    array[1]= xjgjettwo;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* xjgjetthree = (TH1*)gROOT->FindObject("unfold5p4");
    array[2]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* xjgjetfour = (TH1*)gROOT->FindObject("unfold10p2");
    array[3]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* xjgjetfive = (TH1*)gROOT->FindObject("unfold10p3");
    array[4]= xjgjetfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* xjgjetsix = (TH1*)gROOT->FindObject("unfold10p4");
    array[5]= xjgjetsix;
    
    TFile *_file6 = TFile::Open("unfoldplots.root");
    TH1* xjgjetseven = (TH1*)gROOT->FindObject("unfold15p2");
    array[6]= xjgjetseven;
    
    TFile *_file7 = TFile::Open("unfoldplots.root");
    TH1* xjgjeteight = (TH1*)gROOT->FindObject("unfold15p3");
    array[7]= xjgjeteight;
    
    TFile *_file8 = TFile::Open("unfoldplots.root");
    TH1* xjgjetnine = (TH1*)gROOT->FindObject("unfold15p4");
    array[8]= xjgjetnine;
    
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* xjgjetonea = (TH1*)gROOT->FindObject("unfold20p2");
    array[9]= xjgjetonea;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* xjgjettwoa = (TH1*)gROOT->FindObject("unfold20p3");
    array[10]= xjgjettwoa;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* xjgjetthreea = (TH1*)gROOT->FindObject("unfold20p4");
    array[11]= xjgjetthreea;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* xjgjetfoura = (TH1*)gROOT->FindObject("unfold25p2");
    array[12]= xjgjetfoura;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* xjgjetfivea = (TH1*)gROOT->FindObject("unfold25p3");
    array[13]= xjgjetfivea;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* xjgjetsixa = (TH1*)gROOT->FindObject("unfold25p4");
    array[14]= xjgjetsixa;
    
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* xjgjetone = (TH1*)gROOT->FindObject("unfold30p2");
    array[15]= xjgjetone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* xjgjettwo = (TH1*)gROOT->FindObject("unfold30p3");
    array[16]= xjgjettwo;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* xjgjetthree = (TH1*)gROOT->FindObject("unfold30p4");
    array[17]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* xjgjetfour = (TH1*)gROOT->FindObject("unfold35p2");
    array[18]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* xjgjetfive = (TH1*)gROOT->FindObject("unfold35p3");
    array[19]= xjgjetfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* xjgjetsix = (TH1*)gROOT->FindObject("unfold35p4");
    array[20]= xjgjetsix;
    
    TFile *_file6 = TFile::Open("unfoldplots.root");
    TH1* xjgjetseven = (TH1*)gROOT->FindObject("unfold40p2");
    array[21]= xjgjetseven;
    
    TFile *_file7 = TFile::Open("unfoldplots.root");
    TH1* xjgjeteight = (TH1*)gROOT->FindObject("unfold40p3");
    array[22]= xjgjeteight;
    
    TFile *_file8 = TFile::Open("unfoldplots.root");
    TH1* xjgjetnine = (TH1*)gROOT->FindObject("unfold40p4");
    array[23]= xjgjetnine;
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* xjgjetone = (TH1*)gROOT->FindObject("unfold45p2");
    array[24]= xjgjetone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* xjgjettwo = (TH1*)gROOT->FindObject("unfold45p3");
    array[25]= xjgjettwo;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* xjgjetthree = (TH1*)gROOT->FindObject("unfold45p4");
    array[26]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* xjgjetfour = (TH1*)gROOT->FindObject("unfold50p2");
    array[27]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* xjgjetfive = (TH1*)gROOT->FindObject("unfold50p3");
    array[28]= xjgjetfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* xjgjetsix = (TH1*)gROOT->FindObject("unfold50p4");
    array[29]= xjgjetsix;
    Double_t upt5[3];
    Double_t upt10[3];
    Double_t upt15[3];
    Double_t upt20[3];
    Double_t upt25[3];
    Double_t upt30[3];
    Double_t upt35[3];
    Double_t upt40[3];
    Double_t upt45[3];
    Double_t upt50[3];
    for(int i=0;i<3;i++)
        upt5[i]=array[i]->GetMean();
    for(int i=3;i<6;i++)
        upt10[i-3]=array[i]->GetMean();
    for(int i=6;i<9;i++)
        upt15[i-6]=array[i]->GetMean();
    for(int i=9;i<12;i++)
        upt20[i-9]=array[i]->GetMean();
    for(int i=12;i<15;i++)
        upt25[i-12]=array[i]->GetMean();
    for(int i=15;i<18;i++)
        upt30[i-15]=array[i]->GetMean();
    for(int i=18;i<21;i++)
        upt35[i-18]=array[i]->GetMean();
    for(int i=21;i<24;i++)
        upt40[i-21]=array[i]->GetMean();
    for(int i=24;i<27;i++)
        upt45[i-24]=array[i]->GetMean();
    for(int i=27;i<30;i++)
        upt50[i-27]=array[i]->GetMean();
    
    Double_t eupt5[3];
    Double_t eupt10[3];
    Double_t eupt15[3];
    Double_t eupt20[3];
    Double_t eupt25[3];
    Double_t eupt30[3];
    Double_t eupt35[3];
    Double_t eupt40[3];
    Double_t eupt45[3];
    Double_t eupt50[3];
    for(int i=0;i<3;i++)
        eupt5[i]=array[i]->GetRMS();
    for(int i=3;i<6;i++)
        eupt10[i-3]=array[i]->GetRMS();
    for(int i=6;i<9;i++)
        eupt15[i-6]=array[i]->GetRMS();
    for(int i=9;i<12;i++)
        eupt20[i-9]=array[i]->GetRMS();
    for(int i=12;i<15;i++)
        eupt25[i-12]=array[i]->GetRMS();
    for(int i=15;i<18;i++)
        eupt30[i-15]=array[i]->GetRMS();
    for(int i=18;i<21;i++)
        eupt35[i-18]=array[i]->GetRMS();
    for(int i=21;i<24;i++)
        eupt40[i-21]=array[i]->GetRMS();
    for(int i=24;i<27;i++)
        eupt45[i-24]=array[i]->GetRMS();
    for(int i=27;i<30;i++)
        eupt50[i-27]=array[i]->GetRMS();
TCanvas *c3= new TCanvas("c3","",1000,1000);
    Double_t jpt5[3]={0.469616,0.528041,0.566678};
    Double_t jpt15[3]={0.558344,0.627056,0.641796};
    Double_t jpt25[3]={0.6521,0.710176,0.719287};
    Double_t jpt35[3]={0.701202,0.753099,0.757408};
    Double_t jpt45[3]={0.742131,0.792112,0.806184};
    Double_t spt5[3]={1.09789,1.40334,1.90479};
    Double_t spt15[3]={0.648738,0.805447,1.05616};
    Double_t spt25[3]={0.699613,0.815683,0.985538};
    Double_t spt35[3]={0.735253,0.831829,0.95974};
    Double_t spt45[3]={0.760689,0.841417,0.946005};
    Double_t ejpt5[3]={0.243201,0.287315,0.330208};
    Double_t ejpt15[3]={0.264054,0.302826,0.342976};
    Double_t ejpt25[3]={0.254102,0.277335,0.316553};
    Double_t ejpt35[3]={0.234616,0.249164,0.287426};
    Double_t ejpt45[3]={0.207817,0.211231,0.238832};
    Double_t espt5[3]={0.331098,0.443326,0.52885};
    Double_t espt15[3]={0.228333,0.260963,0.307121};
    Double_t espt25[3]={0.23027,0.235426,0.248455};
    Double_t espt35[3]={0.218582,0.211284,0.215638};
    Double_t espt45[3]={0.202461,0.19085,0.191792};
    Double_t jpt10[3]={0.496099,0.577304,0.604262};
    Double_t jpt20[3]={0.61097,0.674566,0.681365};
    Double_t jpt30[3]={0.681712,0.734251,0.744046};
    Double_t jpt40[3]={0.728408,0.780619,0.792677};
    Double_t jpt50[3]={0.75418,0.804495,0.815444};
    Double_t spt10[3]={0.701405,0.892986,1.24353};
    Double_t spt20[3]={0.673904,0.80738,1.00034};
    Double_t spt30[3]={0.724249,0.826071,0.969782};
    Double_t spt40[3]={0.751304,0.838823,0.952558};
    Double_t spt50[3]={0.769957,0.84622,0.942272};
    Double_t ejpt10[3]={0.255846,0.299941,0.337053};
    Double_t ejpt20[3]={0.259329,0.291999,0.332003};
    Double_t ejpt30[3]={0.246683,0.266093,0.298417};
    Double_t ejpt40[3]={0.2144,0.223676,0.255009};
    Double_t ejpt50[3]={0.198518,0.194969,0.226226};
    Double_t espt10[3]={0.220521,0.286525,0.367507};
    Double_t espt20[3]={0.233455,0.251319,0.280164};
    Double_t espt30[3]={0.225364,0.219934,0.227235};
    Double_t espt40[3]={0.205521,0.197867,0.201941};
    Double_t espt50[3]={0.196179,0.185749,0.184484};
    Double_t count[3]={0.18,0.28,0.38};
    Double_t count2[3]={0.19,0.29,0.39};
    Double_t count3[3]={.2,.3,.4};
    Double_t count4[3]={.21,.31,.41};
    Double_t count5[3]={.22,.32,.42};
    Double_t range[3]={.15,.45,.3};
    Double_t ex[3]={0,0,0};
    
    TCanvas* c3 = new TCanvas("c3","",1000,1000);
    TGraphErrors *blank=new TGraphErrors(3,range,ex,ex,ex);
    blank->GetYaxis()->SetRangeUser(0,1.5);
    blank->GetYaxis()->SetTitle("mean X_{J#gamma}");
    blank->GetXaxis()->SetTitle("Jet Radius");
    blank->Draw();
    TGraphErrors *f = new TGraphErrors(3,count,jpt5,ex,ejpt5);
    f->GetYaxis()->SetRangeUser(0,3);
    f->GetXaxis()->SetRangeUser(.15,.42);
    f->SetMarkerStyle(23);
    f->SetMarkerSize(2);
    f->SetMarkerColor(kAzure);
    f->SetLineColor(kAzure);
    f->GetYaxis()->SetTitle("Mean XJG");
    f->GetXaxis()->SetTitle("Jet Radius");
    f->Draw("P");
    TGraphErrors *fe = new TGraphErrors(3,count2,jpt10,ex,ejpt10);
    fe->GetYaxis()->SetRangeUser(0,3);
    fe->GetXaxis()->SetRangeUser(.15,.45);
    fe->SetMarkerStyle(23);
    fe->SetMarkerSize(2);
    fe->SetMarkerColor(kAzure+2);
    fe->SetLineColor(kAzure+2);
    fe->GetYaxis()->SetTitle("Mean XJG");
    fe->GetXaxis()->SetTitle("Jet Radius");
    fe->Draw("P");
    TGraphErrors *g = new TGraphErrors(3,count3,jpt15,ex,ejpt15);
    //g->GetYaxis()->SetRangeUser(0,2);
    g->SetMarkerStyle(23);
    g->SetMarkerSize(2);
    g->SetMarkerColor(kMagenta);
    g->SetLineColor(kMagenta);
    g->Draw("P");
    TGraphErrors *ge = new TGraphErrors(3,count4,jpt20,ex,ejpt20);
    //g->GetYaxis()->SetRangeUser(0,2);
    ge->SetMarkerStyle(23);
    ge->SetMarkerSize(2);
    ge->SetMarkerColor(kMagenta+2);
    ge->SetLineColor(kMagenta+2);
    ge->Draw("P");
    TGraphErrors *h = new TGraphErrors(3,count5,jpt25,ex,ejpt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    h->SetMarkerStyle(23);
    h->SetMarkerSize(2);
    h->SetMarkerColor(kRed);
    h->SetLineColor(kRed);
    h->Draw("P");
    TGraphErrors *he = new TGraphErrors(3,count,jpt30,ex,ejpt30);
    //h->GetYaxis()->SetRangeUser(0,2);
    he->SetMarkerStyle(23);
    he->SetMarkerSize(2);
    he->SetMarkerColor(kRed+2);
    he->SetLineColor(kRed+2);
    he->Draw("P");
    TGraphErrors *w = new TGraphErrors(3,count2,jpt35,ex,ejpt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    w->SetMarkerStyle(23);
    w->SetMarkerSize(2);
    w->SetMarkerColor(kOrange);
    w->SetLineColor(kOrange);
    w->Draw("P");
    TGraphErrors *we = new TGraphErrors(3,count3,jpt40,ex,ejpt40);
    //g->GetYaxis()->SetRangeUser(0,2);
    we->SetMarkerStyle(23);
    we->SetMarkerSize(2);
    we->SetMarkerColor(kOrange+2);
    we->SetLineColor(kOrange+2);
    we->Draw("P");
    TGraphErrors *q = new TGraphErrors(3,count4,jpt45,ex,ejpt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    q->SetMarkerStyle(23);
    q->SetMarkerSize(2);
    q->SetMarkerColor(kGreen);
    q->SetLineColor(kGreen);
    q->Draw("P");
    TGraphErrors *qe = new TGraphErrors(3,count5,jpt50,ex,ejpt50);
    //h->GetYaxis()->SetRangeUser(0,2);
    qe->SetMarkerStyle(23);
    qe->SetMarkerSize(2);
    qe->SetMarkerColor(kGreen+2);
    qe->SetLineColor(kGreen+2);
    qe->Draw("P");
    TGraphErrors *j = new TGraphErrors(3,count,spt5,ex,espt5);
    //h->GetYaxis()->SetRangeUser(0,2);
    j->SetMarkerStyle(28);
    j->SetMarkerSize(2);
    j->SetMarkerColor(kAzure);
    j->SetLineColor(kAzure);
    j->Draw("P");
    TGraphErrors *je = new TGraphErrors(3,count2,spt10,ex,espt10);
    //h->GetYaxis()->SetRangeUser(0,2);
    je->SetMarkerStyle(28);
    je->SetMarkerSize(2);
    je->SetMarkerColor(kAzure+2);
    je->SetLineColor(kAzure+2);
    je->Draw("P");
    TGraphErrors *k = new TGraphErrors(3,count3,spt15,ex,espt15);
    //h->GetYaxis()->SetRangeUser(0,2);
    k->SetMarkerStyle(28);
    k->SetMarkerSize(2);
    k->SetMarkerColor(kMagenta);
    k->SetLineColor(kMagenta);
    k->Draw("P");
    TGraphErrors *ke = new TGraphErrors(3,count4,spt20,ex,espt20);
    //h->GetYaxis()->SetRangeUser(0,2);
    ke->SetMarkerStyle(28);
    ke->SetMarkerSize(2);
    ke->SetMarkerColor(kMagenta+2);
    ke->SetLineColor(kMagenta+2);
    ke->Draw("P");
    TGraphErrors *l = new TGraphErrors(3,count5,spt25,ex,espt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    l->SetMarkerStyle(28);
    l->SetMarkerSize(2);
    l->SetMarkerColor(kRed);
    l->SetLineColor(kRed);
    l->Draw("P");
    TGraphErrors *le = new TGraphErrors(3,count,spt30,ex,espt30);
    //h->GetYaxis()->SetRangeUser(0,2);
    le->SetMarkerStyle(28);
    le->SetMarkerSize(2);
    le->SetMarkerColor(kRed+2);
    le->SetLineColor(kRed+2);
    le->Draw("P");
    TGraphErrors *r = new TGraphErrors(3,count2,spt35,ex,espt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    r->SetMarkerStyle(28);
    r->SetMarkerSize(2);
    r->SetMarkerColor(kOrange);
    r->SetLineColor(kOrange);
    r->Draw("P");
    TGraphErrors *re = new TGraphErrors(3,count3,spt40,ex,espt40);
    //g->GetYaxis()->SetRangeUser(0,2);
    re->SetMarkerStyle(28);
    re->SetMarkerSize(2);
    re->SetMarkerColor(kOrange+2);
    re->SetLineColor(kOrange+2);
    re->Draw("P");
    TGraphErrors *y = new TGraphErrors(3,count4,spt45,ex,espt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    y->SetMarkerStyle(28);
    y->SetMarkerSize(2);
    y->SetMarkerColor(kGreen);
    y->SetLineColor(kGreen);
    y->Draw("P");
    TGraphErrors *ye = new TGraphErrors(3,count5,spt50,ex,espt50);
    //h->GetYaxis()->SetRangeUser(0,2);
    ye->SetMarkerStyle(28);
    ye->SetMarkerSize(2);
    ye->SetMarkerColor(kGreen+2);
    ye->SetLineColor(kGreen+2);
    ye->Draw("P");
    TGraphErrors *uj = new TGraphErrors(3,count,upt5,ex,eupt5);
    //h->GetYaxis()->SetRangeUser(0,2);
    uj->SetMarkerStyle(30);
    uj->SetMarkerSize(2);
    uj->SetMarkerColor(kAzure);
    uj->SetLineColor(kAzure);
    uj->Draw("P");
    TGraphErrors *uje = new TGraphErrors(3,count2,upt10,ex,eupt10);
    //h->GetYaxis()->SetRangeUser(0,2);
    uje->SetMarkerStyle(30);
    uje->SetMarkerSize(2);
    uje->SetMarkerColor(kAzure+2);
    uje->SetLineColor(kAzure+2);
    uje->Draw("P");
    TGraphErrors *uk = new TGraphErrors(3,count3,upt15,ex,eupt15);
    //h->GetYaxis()->SetRangeUser(0,2);
    uk->SetMarkerStyle(30);
    uk->SetMarkerSize(2);
    uk->SetMarkerColor(kMagenta);
    uk->SetLineColor(kMagenta);
    uk->Draw("P");
    TGraphErrors *uke = new TGraphErrors(3,count4,upt20,ex,eupt20);
    //h->GetYaxis()->SetRangeUser(0,2);
    uke->SetMarkerStyle(30);
    uke->SetMarkerSize(2);
    uke->SetMarkerColor(kMagenta+2);
    uke->SetLineColor(kMagenta+2);
    uke->Draw("P");
    TGraphErrors *ul = new TGraphErrors(3,count5,upt25,ex,eupt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    ul->SetMarkerStyle(30);
    ul->SetMarkerSize(2);
    ul->SetMarkerColor(kRed);
    ul->SetLineColor(kRed);
    ul->Draw("P");
    TGraphErrors *ule = new TGraphErrors(3,count,upt30,ex,eupt30);
    //h->GetYaxis()->SetRangeUser(0,2);
    ule->SetMarkerStyle(30);
    ule->SetMarkerSize(2);
    ule->SetMarkerColor(kRed+2);
    ule->SetLineColor(kRed+2);
    ule->Draw("P");
    TGraphErrors *ur = new TGraphErrors(3,count2,upt35,ex,eupt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    ur->SetMarkerStyle(30);
    ur->SetMarkerSize(2);
    ur->SetMarkerColor(kOrange);
    ur->SetLineColor(kOrange);
    ur->Draw("P");
    TGraphErrors *ure = new TGraphErrors(3,count3,upt40,ex,eupt40);
    //g->GetYaxis()->SetRangeUser(0,2);
    ure->SetMarkerStyle(30);
    ure->SetMarkerSize(2);
    ure->SetMarkerColor(kOrange+2);
    ure->SetLineColor(kOrange+2);
    ure->Draw("P");
    TGraphErrors *uy = new TGraphErrors(3,count4,upt45,ex,eupt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    uy->SetMarkerStyle(30);
    uy->SetMarkerSize(2);
    uy->SetMarkerColor(kGreen);
    uy->SetLineColor(kGreen);
    uy->Draw("P");
    TGraphErrors *uye = new TGraphErrors(3,count5,upt50,ex,eupt50);
    //h->GetYaxis()->SetRangeUser(0,2);
    uye->SetMarkerStyle(30);
    uye->SetMarkerSize(2);
    uye->SetMarkerColor(kGreen+2);
    uye->SetLineColor(kGreen+2);
    uye->Draw("P");
    TLegend* leg9 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg9,.03);
    leg9->AddEntry(fe,"PYTHIA","P");
    leg9->AddEntry(ye,"PYTHIA-#rhoA","P");
    leg9->AddEntry(ure,"Unfolded","P");
    leg9->AddEntry(f,"5 GeV","l");
    leg9->AddEntry(fe,"10 GeV","l");
    leg9->AddEntry(g,"15 GeV","l");
    leg9->AddEntry(ge,"20 GeV","l");
    leg9->AddEntry(h,"25 GeV","l");
    leg9->AddEntry(he,"30 GeV","l");
    leg9->AddEntry(w,"35 GeV","l");
    leg9->AddEntry(we,"40 GeV","l");
    leg9->AddEntry(q,"45 GeV","l");
    leg9->AddEntry(qe,"50 GeV","l");
    leg9->Draw();

    
//Effeciency plots using % error to quantify how well the subtractor and unfolding do numerically
    
    Double_t perupt5[3];
    Double_t perupt10[3];
    Double_t perupt15[3];
    Double_t perupt20[3];
    Double_t perupt25[3];
    Double_t perupt30[3];
    Double_t perupt35[3];
    Double_t perupt40[3];
    Double_t perupt45[3];
    Double_t perupt50[3];
    Double_t eperupt5[3];
    Double_t eperupt10[3];
    Double_t eperupt15[3];
    Double_t eperupt20[3];
    Double_t eperupt25[3];
    Double_t eperupt30[3];
    Double_t eperupt35[3];
    Double_t eperupt40[3];
    Double_t eperupt45[3];
    Double_t eperupt50[3];
    
    for(int i=0;i<3;i++)
        perupt5[i]=(fabs(jpt5[i]-upt5[i])/jpt5[i])*100;
    for(int i=0;i<3;i++)
        perupt10[i]=(fabs(jpt10[i]-upt10[i])/jpt10[i])*100;
    for(int i=0;i<3;i++)
        perupt15[i]=(fabs(jpt15[i]-upt15[i])/jpt15[i])*100;
    for(int i=0;i<3;i++)
        perupt20[i]=(fabs(jpt20[i]-upt20[i])/jpt20[i])*100;
    for(int i=0;i<3;i++)
        perupt25[i]=(fabs(jpt25[i]-upt25[i])/jpt25[i])*100;
    for(int i=0;i<3;i++)
        perupt30[i]=(fabs(jpt30[i]-upt30[i])/jpt30[i])*100;
    for(int i=0;i<3;i++)
        perupt35[i]=(fabs(jpt35[i]-upt35[i])/jpt35[i])*100;
    for(int i=0;i<3;i++)
        perupt40[i]=(fabs(jpt40[i]-upt40[i])/jpt40[i])*100;
    for(int i=0;i<3;i++)
        perupt45[i]=(fabs(jpt45[i]-upt45[i])/jpt45[i])*100;
    for(int i=0;i<3;i++)
        perupt50[i]=(fabs(jpt50[i]-upt50[i])/jpt50[i])*100;
    
    for(int i=0;i<3;i++)
        eperupt5[i]=TMath::Power((((eupt5[i]*eupt5[i])+(ejpt5[i]*ejpt5[i]))/(perupt5[i]*perupt5[i]))+((ejpt5[i]*ejpt5[i])/(jpt5[i]*jpt5[i])),0.5)*perupt5[i];
    for(int i=0;i<3;i++)
        eperupt10[i]=TMath::Power((((eupt10[i]*eupt10[i])+(ejpt10[i]*ejpt10[i]))/(perupt10[i]*perupt10[i]))+((ejpt10[i]*ejpt10[i])/(jpt10[i]*jpt10[i])),0.5)*perupt10[i];
    for(int i=0;i<3;i++)
        eperupt15[i]=TMath::Power((((eupt15[i]*eupt15[i])+(ejpt15[i]*ejpt15[i]))/(perupt15[i]*perupt15[i]))+((ejpt15[i]*ejpt15[i])/(jpt15[i]*jpt15[i])),0.5)*perupt15[i];
    for(int i=0;i<3;i++)
        eperupt20[i]=TMath::Power((((eupt20[i]*eupt20[i])+(ejpt20[i]*ejpt20[i]))/(perupt20[i]*perupt20[i]))+((ejpt20[i]*ejpt20[i])/(jpt20[i]*jpt20[i])),0.5)*perupt20[i];
    for(int i=0;i<3;i++)
        eperupt25[i]=TMath::Power((((eupt25[i]*eupt25[i])+(ejpt25[i]*ejpt25[i]))/(perupt25[i]*perupt25[i]))+((ejpt25[i]*ejpt25[i])/(jpt25[i]*jpt25[i])),0.5)*perupt25[i];
    for(int i=0;i<3;i++)
        eperupt30[i]=TMath::Power((((eupt30[i]*eupt30[i])+(ejpt30[i]*ejpt30[i]))/(perupt30[i]*perupt30[i]))+((ejpt30[i]*ejpt30[i])/(jpt30[i]*jpt30[i])),0.5)*perupt30[i];
    for(int i=0;i<3;i++)
        eperupt35[i]=TMath::Power((((eupt35[i]*eupt35[i])+(ejpt35[i]*ejpt35[i]))/(perupt35[i]*perupt35[i]))+((ejpt35[i]*ejpt35[i])/(jpt35[i]*jpt35[i])),0.5)*perupt35[i];
    for(int i=0;i<3;i++)
        eperupt40[i]=TMath::Power((((eupt40[i]*eupt40[i])+(ejpt40[i]*ejpt40[i]))/(perupt40[i]*perupt40[i]))+((ejpt40[i]*ejpt40[i])/(jpt40[i]*jpt40[i])),0.5)*perupt40[i];
    for(int i=0;i<3;i++)
        eperupt45[i]=TMath::Power((((eupt45[i]*eupt45[i])+(ejpt45[i]*ejpt45[i]))/(perupt45[i]*perupt45[i]))+((ejpt45[i]*ejpt45[i])/(jpt45[i]*jpt45[i])),0.5)*perupt45[i];
    for(int i=0;i<3;i++)
        eperupt50[i]=TMath::Power((((eupt50[i]*eupt50[i])+(ejpt50[i]*ejpt50[i]))/(perupt50[i]*perupt50[i]))+((ejpt50[i]*ejpt50[i])/(jpt50[i]*jpt50[i])),0.5)*perupt50[i];
    
    Double_t perspt5[3];
    Double_t perspt10[3];
    Double_t perspt15[3];
    Double_t perspt20[3];
    Double_t perspt25[3];
    Double_t perspt30[3];
    Double_t perspt35[3];
    Double_t perspt40[3];
    Double_t perspt45[3];
    Double_t perspt50[3];
    Double_t eperspt5[3];
    Double_t eperspt10[3];
    Double_t eperspt15[3];
    Double_t eperspt20[3];
    Double_t eperspt25[3];
    Double_t eperspt30[3];
    Double_t eperspt35[3];
    Double_t eperspt40[3];
    Double_t eperspt45[3];
    Double_t eperspt50[3];
    
    for(int i=0;i<3;i++)
        perspt5[i]=(fabs(jpt5[i]-spt5[i])/spt5[i])*100;
    for(int i=0;i<3;i++)
        perspt10[i]=(fabs(jpt10[i]-spt10[i])/spt10[i])*100;
    for(int i=0;i<3;i++)
        perspt15[i]=(fabs(jpt15[i]-spt15[i])/spt15[i])*100;
    for(int i=0;i<3;i++)
        perspt20[i]=(fabs(jpt20[i]-spt20[i])/spt20[i])*100;
    for(int i=0;i<3;i++)
        perspt25[i]=(fabs(jpt25[i]-spt25[i])/spt25[i])*100;
    for(int i=0;i<3;i++)
        perspt30[i]=(fabs(jpt30[i]-spt30[i])/spt30[i])*100;
    for(int i=0;i<3;i++)
        perspt35[i]=(fabs(jpt35[i]-spt35[i])/spt35[i])*100;
    for(int i=0;i<3;i++)
        perspt40[i]=(fabs(jpt40[i]-spt40[i])/spt40[i])*100;
    for(int i=0;i<3;i++)
        perspt45[i]=(fabs(jpt45[i]-spt45[i])/spt45[i])*100;
    for(int i=0;i<3;i++)
        perspt50[i]=(fabs(jpt50[i]-spt50[i])/spt50[i])*100;
    
    for(int i=0;i<3;i++)
        eperspt5[i]=TMath::Power((((espt5[i]*espt5[i])+(ejpt5[i]*ejpt5[i]))/(perspt5[i]*perspt5[i]))+((ejpt5[i]*ejpt5[i])/(jpt5[i]*jpt5[i])),0.5)*perspt5[i];
    for(int i=0;i<3;i++)
        eperspt10[i]=TMath::Power((((espt10[i]*espt10[i])+(ejpt10[i]*ejpt10[i]))/(perspt10[i]*perspt10[i]))+((ejpt10[i]*ejpt10[i])/(jpt10[i]*jpt10[i])),0.5)*perspt10[i];
    for(int i=0;i<3;i++)
        eperspt15[i]=TMath::Power((((espt15[i]*espt15[i])+(ejpt15[i]*ejpt15[i]))/(perspt15[i]*perspt15[i]))+((ejpt15[i]*ejpt15[i])/(jpt15[i]*jpt15[i])),0.5)*perspt15[i];
    for(int i=0;i<3;i++)
        eperspt20[i]=TMath::Power((((espt20[i]*espt20[i])+(ejpt20[i]*ejpt20[i]))/(perspt20[i]*perspt20[i]))+((ejpt20[i]*ejpt20[i])/(jpt20[i]*jpt20[i])),0.5)*perspt20[i];
    for(int i=0;i<3;i++)
        eperspt25[i]=TMath::Power((((espt25[i]*espt25[i])+(ejpt25[i]*ejpt25[i]))/(perspt25[i]*perspt25[i]))+((ejpt25[i]*ejpt25[i])/(jpt25[i]*jpt25[i])),0.5)*perspt25[i];
    for(int i=0;i<3;i++)
        eperspt30[i]=TMath::Power((((espt30[i]*espt30[i])+(ejpt30[i]*ejpt30[i]))/(perspt30[i]*perspt30[i]))+((ejpt30[i]*ejpt30[i])/(jpt30[i]*jpt30[i])),0.5)*perspt30[i];
    for(int i=0;i<3;i++)
        eperspt35[i]=TMath::Power((((espt35[i]*espt35[i])+(ejpt35[i]*ejpt35[i]))/(perspt35[i]*perspt35[i]))+((ejpt35[i]*ejpt35[i])/(jpt35[i]*jpt35[i])),0.5)*perspt35[i];
    for(int i=0;i<3;i++)
        eperspt40[i]=TMath::Power((((espt40[i]*espt40[i])+(ejpt40[i]*ejpt40[i]))/(perspt40[i]*perspt40[i]))+((ejpt40[i]*ejpt40[i])/(jpt40[i]*jpt40[i])),0.5)*perspt40[i];
    for(int i=0;i<3;i++)
        eperspt45[i]=TMath::Power((((espt45[i]*espt45[i])+(ejpt45[i]*ejpt45[i]))/(perspt45[i]*perspt45[i]))+((ejpt45[i]*ejpt45[i])/(jpt45[i]*jpt45[i])),0.5)*perspt45[i];
    for(int i=0;i<3;i++)
        eperspt50[i]=TMath::Power((((espt50[i]*espt50[i])+(ejpt50[i]*ejpt50[i]))/(perspt50[i]*perspt50[i]))+((ejpt50[i]*ejpt50[i])/(jpt50[i]*jpt50[i])),0.5)*perspt50[i];
    
    
    TCanvas* c7 = new TCanvas("c7","",1000,1000);
    TGraphErrors *blank=new TGraphErrors(3,range,ex,ex,ex);
    blank->GetYaxis()->SetRangeUser(0,150);
    blank->GetYaxis()->SetTitle("% error");
    blank->GetXaxis()->SetTitle("Jet Radius");
    blank->Draw();
    TGraphErrors *uj = new TGraphErrors(3,count,perupt5,ex,eperupt5);
    //h->GetYaxis()->SetRangeUser(0,2);
    uj->SetMarkerStyle(30);
    uj->SetMarkerSize(2);
    uj->SetMarkerColor(kAzure);
    uj->SetLineColor(kAzure);
    uj->Draw("P");
    TGraphErrors *uje = new TGraphErrors(3,count2,perupt10,ex,eperupt10);
    //h->GetYaxis()->SetRangeUser(0,2);
    uje->SetMarkerStyle(30);
    uje->SetMarkerSize(2);
    uje->SetMarkerColor(kAzure+2);
    uje->SetLineColor(kAzure+2);
    uje->Draw("P");
    TGraphErrors *uk = new TGraphErrors(3,count3,perupt15,ex,eperupt15);
    //h->GetYaxis()->SetRangeUser(0,2);
    uk->SetMarkerStyle(30);
    uk->SetMarkerSize(2);
    uk->SetMarkerColor(kMagenta);
    uk->SetLineColor(kMagenta);
    uk->Draw("P");
    TGraphErrors *uke = new TGraphErrors(3,count4,perupt20,ex,eperupt20);
    //h->GetYaxis()->SetRangeUser(0,2);
    uke->SetMarkerStyle(30);
    uke->SetMarkerSize(2);
    uke->SetMarkerColor(kMagenta+2);
    uke->SetLineColor(kMagenta+2);
    uke->Draw("P");
    TGraphErrors *ul = new TGraphErrors(3,count5,perupt25,ex,eperupt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    ul->SetMarkerStyle(30);
    ul->SetMarkerSize(2);
    ul->SetMarkerColor(kRed);
    ul->SetLineColor(kRed);
    ul->Draw("P");
    TGraphErrors *ule = new TGraphErrors(3,count,perupt30,ex,eperupt30);
    //h->GetYaxis()->SetRangeUser(0,2);
    ule->SetMarkerStyle(30);
    ule->SetMarkerSize(2);
    ule->SetMarkerColor(kRed+2);
    ule->SetLineColor(kRed+2);
    ule->Draw("P");
    TGraphErrors *ur = new TGraphErrors(3,count2,perupt35,ex,eperupt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    ur->SetMarkerStyle(30);
    ur->SetMarkerSize(2);
    ur->SetMarkerColor(kOrange);
    ur->SetLineColor(kOrange);
    ur->Draw("P");
    TGraphErrors *ure = new TGraphErrors(3,count3,perupt40,ex,eperupt40);
    //g->GetYaxis()->SetRangeUser(0,2);
    ure->SetMarkerStyle(30);
    ure->SetMarkerSize(2);
    ure->SetMarkerColor(kOrange+2);
    ure->SetLineColor(kOrange+2);
    ure->Draw("P");
    TGraphErrors *uy = new TGraphErrors(3,count4,perupt45,ex,eperupt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    uy->SetMarkerStyle(30);
    uy->SetMarkerSize(2);
    uy->SetMarkerColor(kGreen);
    uy->SetLineColor(kGreen);
    uy->Draw("P");
    TGraphErrors *uye = new TGraphErrors(3,count5,perupt50,ex,eperupt50);
    //h->GetYaxis()->SetRangeUser(0,2);
    uye->SetMarkerStyle(30);
    uye->SetMarkerSize(2);
    uye->SetMarkerColor(kGreen+2);
    uye->SetLineColor(kGreen+2);
    uye->Draw("P");
    TGraphErrors *j = new TGraphErrors(3,count,perspt5,ex,eperspt5);
    //h->GetYaxis()->SetRangeUser(0,2);
    j->SetMarkerStyle(28);
    j->SetMarkerSize(2);
    j->SetMarkerColor(kAzure);
    j->SetLineColor(kAzure);
    j->Draw("P");
    TGraphErrors *je = new TGraphErrors(3,count2,perspt10,ex,eperspt10);
    //h->GetYaxis()->SetRangeUser(0,2);
    je->SetMarkerStyle(28);
    je->SetMarkerSize(2);
    je->SetMarkerColor(kAzure+2);
    je->SetLineColor(kAzure+2);
    je->Draw("P");
    TGraphErrors *k = new TGraphErrors(3,count3,perspt15,ex,eperspt15);
    //h->GetYaxis()->SetRangeUser(0,2);
    k->SetMarkerStyle(28);
    k->SetMarkerSize(2);
    k->SetMarkerColor(kMagenta);
    k->SetLineColor(kMagenta);
    k->Draw("P");
    TGraphErrors *ke = new TGraphErrors(3,count4,perspt20,ex,eperspt20);
    //h->GetYaxis()->SetRangeUser(0,2);
    ke->SetMarkerStyle(28);
    ke->SetMarkerSize(2);
    ke->SetMarkerColor(kMagenta+2);
    ke->SetLineColor(kMagenta+2);
    ke->Draw("P");
    TGraphErrors *l = new TGraphErrors(3,count5,perspt25,ex,eperspt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    l->SetMarkerStyle(28);
    l->SetMarkerSize(2);
    l->SetMarkerColor(kRed);
    l->SetLineColor(kRed);
    l->Draw("P");
    TGraphErrors *le = new TGraphErrors(3,count,perspt30,ex,eperspt30);
    //h->GetYaxis()->SetRangeUser(0,2);
    le->SetMarkerStyle(28);
    le->SetMarkerSize(2);
    le->SetMarkerColor(kRed+2);
    le->SetLineColor(kRed+2);
    le->Draw("P");
    TGraphErrors *r = new TGraphErrors(3,count2,perspt35,ex,eperspt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    r->SetMarkerStyle(28);
    r->SetMarkerSize(2);
    r->SetMarkerColor(kOrange);
    r->SetLineColor(kOrange);
    r->Draw("P");
    TGraphErrors *re = new TGraphErrors(3,count3,perspt40,ex,eperspt40);
    //g->GetYaxis()->SetRangeUser(0,2);
    re->SetMarkerStyle(28);
    re->SetMarkerSize(2);
    re->SetMarkerColor(kOrange+2);
    re->SetLineColor(kOrange+2);
    re->Draw("P");
    TGraphErrors *y = new TGraphErrors(3,count4,perspt45,ex,eperspt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    y->SetMarkerStyle(28);
    y->SetMarkerSize(2);
    y->SetMarkerColor(kGreen);
    y->SetLineColor(kGreen);
    y->Draw("P");
    TGraphErrors *ye = new TGraphErrors(3,count5,perspt50,ex,eperspt50);
    //h->GetYaxis()->SetRangeUser(0,2);
    ye->SetMarkerStyle(28);
    ye->SetMarkerSize(2);
    ye->SetMarkerColor(kGreen+2);
    ye->SetLineColor(kGreen+2);
    ye->Draw("P");
    TLegend* leg9 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg9,.03);
    leg9->AddEntry(ye,"PYTHIA-#rhoA","P");
    //leg9->AddEntry(ure,"Unfolded","P");
    leg9->AddEntry(f,"5 GeV","l");
    leg9->AddEntry(fe,"10 GeV","l");
    leg9->AddEntry(g,"15 GeV","l");
    leg9->AddEntry(ge,"20 GeV","l");
    leg9->AddEntry(h,"25 GeV","l");
    leg9->AddEntry(he,"30 GeV","l");
    leg9->AddEntry(w,"35 GeV","l");
    leg9->AddEntry(we,"40 GeV","l");
    leg9->AddEntry(q,"45 GeV","l");
    leg9->AddEntry(qe,"50 GeV","l");
    leg9->Draw();
    
    double submeanone=0;
    /*for(int i=0;i<1;i++)
        submeanone+=perupt5[i];
    for(int i=0;i<1;i++)
        submeanone+=perupt10[i];
    for(int i=0;i<1;i++)*/
        submeanone+=eperupt15[i];
    for(int i=0;i<1;i++)
        submeanone+=eperupt20[i];
    for(int i=0;i<1;i++)
        submeanone+=eperupt25[i];
    for(int i=0;i<1;i++)
        submeanone+=eperupt30[i];
    for(int i=0;i<1;i++)
        submeanone+=eperupt35[i];
    for(int i=0;i<1;i++)
        submeanone+=eperupt40[i];
    for(int i=0;i<1;i++)
        submeanone+=eperupt45[i];
    for(int i=0;i<1;i++)
        submeanone+=eperupt50[i];
        
    cout<<submeanone/8<<endl;
    
    double submeantwo=0;
    /*for(int i=1;i<2;i++)
        submeantwo+=perupt5[i];
    for(int i=1;i<2;i++)
        submeantwo+=perupt10[i];
    for(int i=1;i<2;i++)*/
        submeantwo+=eperupt15[i];
    for(int i=1;i<2;i++)
        submeantwo+=eperupt20[i];
    for(int i=1;i<2;i++)
        submeantwo+=eperupt25[i];
    for(int i=1;i<2;i++)
        submeantwo+=eperupt30[i];
    for(int i=1;i<2;i++)
        submeantwo+=eperupt35[i];
    for(int i=1;i<2;i++)
        submeantwo+=eperupt40[i];
    for(int i=1;i<2;i++)
        submeantwo+=eperupt45[i];
    for(int i=1;i<2;i++)
        submeantwo+=eperupt50[i];
    
    cout<<submeantwo/8<<endl;
    
    double submeanthree=0;
    /*for(int i=2;i<3;i++)
        submeanthree+=perupt5[i];
    for(int i=2;i<3;i++)
        submeanthree+=perupt10[i];
    for(int i=2;i<3;i++)*/
        submeanthree+=eperupt15[i];
    for(int i=2;i<3;i++)
        submeanthree+=eperupt20[i];
    for(int i=2;i<3;i++)
        submeanthree+=eperupt25[i];
    for(int i=2;i<3;i++)
        submeanthree+=eperupt30[i];
    for(int i=2;i<3;i++)
        submeanthree+=eperupt35[i];
    for(int i=2;i<3;i++)
        submeanthree+=eperupt40[i];
    for(int i=2;i<3;i++)
        submeanthree+=eperupt45[i];
    for(int i=2;i<3;i++)
        submeanthree+=eperupt50[i];
    
    cout<<submeanthree/8<<endl;
    
    
}

void set_plot_style()
{
    const Int_t NRGBs = 5;
    const Int_t NCont = 255;
    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
}

void SetLeg(TLegend* l,float txtsize=0.03){
    l->SetBorderSize(0);
    l->SetFillColor(0);
    l->SetTextSize(txtsize);
}










