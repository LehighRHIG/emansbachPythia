void xjg(TString infile = "histos.root"){
    set_plot_style();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    TH2* array[30];
    TFile *_file0 = TFile::Open("plots.root");
    TH2* xjgjetone = (TH2*)gROOT->FindObject("j5p2c");
    array[0]= xjgjetone;
    
    TFile *_file1 = TFile::Open("plots.root");
    TH2* xjgjettwo = (TH2*)gROOT->FindObject("j5p3c");
    array[1]= xjgjettwo;

    TFile *_file2 = TFile::Open("plots.root");
    TH2* xjgjetthree = (TH2*)gROOT->FindObject("j5p4c");
    array[2]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("plots.root");
    TH2* xjgjetfour = (TH2*)gROOT->FindObject("j15p2");
    array[3]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("plots.root");
    TH2* xjgjetfive = (TH2*)gROOT->FindObject("j15p3");
    array[4]= xjgjetfive;

    TFile *_file5 = TFile::Open("plots.root");
    TH2* xjgjetsix = (TH2*)gROOT->FindObject("j15p4");
    array[5]= xjgjetsix;
    
    TFile *_file6 = TFile::Open("plots.root");
    TH2* xjgjetseven = (TH2*)gROOT->FindObject("j25p2");
    array[6]= xjgjetseven;
    
    TFile *_file7 = TFile::Open("plots.root");
    TH2* xjgjeteight = (TH2*)gROOT->FindObject("j25p3");
    array[7]= xjgjeteight;
    
    TFile *_file8 = TFile::Open("plots.root");
    TH2* xjgjetnine = (TH2*)gROOT->FindObject("j25p4");
    array[8]= xjgjetnine;
    
    TFile *_file0 = TFile::Open("plots.root");
    TH2* xjgjetonea = (TH2*)gROOT->FindObject("j35p2");
    array[9]= xjgjetonea;
    
    TFile *_file1 = TFile::Open("plots.root");
    TH2* xjgjettwoa = (TH2*)gROOT->FindObject("j35p3");
    array[10]= xjgjettwoa;
    
    TFile *_file2 = TFile::Open("plots.root");
    TH2* xjgjetthreea = (TH2*)gROOT->FindObject("j35p4");
    array[11]= xjgjetthreea;
    
    TFile *_file3 = TFile::Open("plots.root");
    TH2* xjgjetfoura = (TH2*)gROOT->FindObject("j45p2");
    array[12]= xjgjetfoura;
    
    TFile *_file4 = TFile::Open("plots.root");
    TH2* xjgjetfivea = (TH2*)gROOT->FindObject("j45p3");
    array[13]= xjgjetfivea;
    
    TFile *_file5 = TFile::Open("plots.root");
    TH2* xjgjetsixa = (TH2*)gROOT->FindObject("j45p4");
    array[14]= xjgjetsixa;
    
    
    TCanvas* c1 = new TCanvas("c1","",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c1->Divide(3,5);
    for(int i=0;i<15;i++){
        c1->cd(i+1);
        array[i]->Draw("colz");
        gPad->SetLogz();
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.1);
        gPad->SetTopMargin(0.1);
        gPad->SetBottomMargin(0.1);
        if(i==0){
            TLegend* leg = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg,.05);
            leg->SetHeader("Ptmin=5 GeV");
            leg->AddEntry("array[0]","R=0.2","");
            leg->AddEntry("array[0]","PYTHIA jets","");
            leg->Draw();
             array[i]->GetXaxis()->SetLabelOffset(999);
             array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==1){
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetHeader("R=0.3");
            leg2->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==2){
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
            leg3->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==3){
            TLegend* leg4 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg4,.05);
            leg4->SetHeader("Ptmin=15 GeV");
            leg4->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==4){
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==5){
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==6){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=25 GeV");
            leg5->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==7){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==8){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==9){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=35 GeV");
            leg5->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==10){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==11){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==12){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=45 GeV");
            leg5->Draw();
        }
        else if(i==13){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==14){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }

    }
    TFile *_file0 = TFile::Open("plots.root");
    TH2* xjgjetone = (TH2*)gROOT->FindObject("s5p2c");
    array[15]= xjgjetone;
    
    TFile *_file1 = TFile::Open("plots.root");
    TH2* xjgjettwo = (TH2*)gROOT->FindObject("s5p3c");
    array[16]= xjgjettwo;
    
    TFile *_file2 = TFile::Open("plots.root");
    TH2* xjgjetthree = (TH2*)gROOT->FindObject("s5p4c");
    array[17]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("plots.root");
    TH2* xjgjetfour = (TH2*)gROOT->FindObject("s15p2");
    array[18]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("plots.root");
    TH2* xjgjetfive = (TH2*)gROOT->FindObject("s15p3");
    array[19]= xjgjetfive;
    
    TFile *_file5 = TFile::Open("plots.root");
    TH2* xjgjetsix = (TH2*)gROOT->FindObject("s15p4");
    array[20]= xjgjetsix;
    
    TFile *_file6 = TFile::Open("plots.root");
    TH2* xjgjetseven = (TH2*)gROOT->FindObject("s25p2");
    array[21]= xjgjetseven;
    
    TFile *_file7 = TFile::Open("plots.root");
    TH2* xjgjeteight = (TH2*)gROOT->FindObject("s25p3");
    array[22]= xjgjeteight;
    
    TFile *_file8 = TFile::Open("plots.root");
    TH2* xjgjetnine = (TH2*)gROOT->FindObject("s25p4");
    array[23]= xjgjetnine;
    TFile *_file0 = TFile::Open("plots.root");
    TH2* xjgjetone = (TH2*)gROOT->FindObject("s35p2");
    array[24]= xjgjetone;
    
    TFile *_file1 = TFile::Open("plots.root");
    TH2* xjgjettwo = (TH2*)gROOT->FindObject("s35p3");
    array[25]= xjgjettwo;
    
    TFile *_file2 = TFile::Open("plots.root");
    TH2* xjgjetthree = (TH2*)gROOT->FindObject("s35p4");
    array[26]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("plots.root");
    TH2* xjgjetfour = (TH2*)gROOT->FindObject("s45p2");
    array[27]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("plots.root");
    TH2* xjgjetfive = (TH2*)gROOT->FindObject("s45p3");
    array[28]= xjgjetfive;
    
    TFile *_file5 = TFile::Open("plots.root");
    TH2* xjgjetsix = (TH2*)gROOT->FindObject("s45p4");
    array[29]= xjgjetsix;
    
    TCanvas* c2 = new TCanvas("c2","",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c2->Divide(3,5);
    for(int i=15;i<30;i++){
        c2->cd(i-14);
        array[i]->Draw("colz");
        gPad->SetLogz();
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.1);
        gPad->SetTopMargin(0.1);
        gPad->SetBottomMargin(0.1);
        if(i==15){
            TLegend* leg = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg,.05);
            leg->SetHeader("Ptmin=5 GeV");
            leg->AddEntry("array[0]","R=0.2","");
            leg->AddEntry("array[0]","PYTHIA+Background-rho jets","");
            leg->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==16){
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetHeader("R=0.3");
            leg2->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==17){
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
            leg3->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==18){
            TLegend* leg4 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg4,.05);
            leg4->SetHeader("Ptmin=15 GeV");
            leg4->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==19){
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==20){
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==21){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=25 GeV");
            leg5->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==22){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==23){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==24){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=35 GeV");
            leg5->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==25){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==26){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==27){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=45 GeV");
            leg5->Draw();
        }
        else if(i==28){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==29){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        
    }
    
    TCanvas *c3= new TCanvas("c3","",1000,1000);
    TH1* Projection[30];
    for(int i=0;i<30;i++){
        Projection[i]=array[i]->ProjectionY("Projection[i]",1,-1);
        cout<<Projection[i]->GetRMS(1)<<endl;
        //cout<<Projection[i]->GetMean()<<endl;
    }
    Double_t jpt5[3]={0.469616,0.528041,0.566678};
    Double_t jpt15[3]={0.558344,0.627056,0.641796};
    Double_t jpt25[3]={0.6521,0.710176,0.719287};
    Double_t jpt35[3]={0.701202,0.753099,0.757408};
    Double_t jpt45[3]={0.742131,0.792112,0.806184};
    Double_t spt5[3]={1.48234,1.84229,2.01481};
    Double_t spt15[3]={0.791799,1.03743,1.40563};
    Double_t spt25[3]={0.789079,0.960571,1.19934};
    Double_t spt35[3]={0.800267,0.936557,1.11452};
    Double_t spt45[3]={0.812847,0.924594,1.06669};
    Double_t ejpt5[3]={.215,.280,.349};
    Double_t ejpt15[3]={.278,.263,.225};
    Double_t ejpt25[3]={.227,.174,.157};
    Double_t ejpt35[3]={.167,.128,.114};
    Double_t ejpt45[3]={.127,.106,.009};
    Double_t espt5[3]={.379,.540,.733};
    Double_t espt15[3]={.205,.255,.318};
    Double_t espt25[3]={.222,.228,.251};
    Double_t espt35[3]={.180,.176,.198};
    Double_t espt45[3]={.145,.147,.159};
    Double_t count[3]={0.2,0.3,0.4};
    Double_t ex[3]={0,0,0};
    TGraphErrors *f = new TGraphErrors(3,count,jpt5,ex,ejpt5);
    f->GetYaxis()->SetRangeUser(0,3);
    f->SetMarkerStyle(23);
    f->SetMarkerSize(2);
    f->SetMarkerColor(kAzure);
    f->SetLineColor(kAzure);
    f->GetYaxis()->SetTitle("Mean XJG");
    f->GetXaxis()->SetTitle("Jet Radius");
    f->Draw("APsame");
    TGraphErrors *g = new TGraphErrors(3,count,jpt15,ex,ejpt15);
    //g->GetYaxis()->SetRangeUser(0,2);
    g->SetMarkerStyle(23);
    g->SetMarkerSize(2);
    g->SetMarkerColor(kMagenta);
    g->SetLineColor(kMagenta);
    g->Draw("Psame");
    TGraphErrors *h = new TGraphErrors(3,count,jpt25,ex,ejpt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    h->SetMarkerStyle(23);
    h->SetMarkerSize(2);
    h->SetMarkerColor(kRed);
    h->SetLineColor(kRed);
    h->Draw("P");
    TGraphErrors *w = new TGraphErrors(3,count,jpt35,ex,ejpt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    w->SetMarkerStyle(23);
    w->SetMarkerSize(2);
    w->SetMarkerColor(kOrange);
    w->SetLineColor(kOrange);
    w->Draw("P");
    TGraphErrors *q = new TGraphErrors(3,count,jpt45,ex,ejpt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    q->SetMarkerStyle(23);
    q->SetMarkerSize(2);
    q->SetMarkerColor(kGreen);
    q->SetLineColor(kGreen);
    q->Draw("P");
    TGraphErrors *j = new TGraphErrors(3,count,spt5,ex,espt5);
    //h->GetYaxis()->SetRangeUser(0,2);
    j->SetMarkerStyle(28);
    j->SetMarkerSize(2);
    j->SetMarkerColor(kAzure);
    j->SetLineColor(kAzure);
    j->Draw("P");
    TGraphErrors *k = new TGraphErrors(3,count,spt15,ex,espt15);
    //h->GetYaxis()->SetRangeUser(0,2);
    k->SetMarkerStyle(28);
    k->SetMarkerSize(2);
    k->SetMarkerColor(kMagenta);
    k->SetLineColor(kMagenta);
    k->Draw("P");
    TGraphErrors *l = new TGraphErrors(3,count,spt25,ex,espt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    l->SetMarkerStyle(28);
    l->SetMarkerSize(2);
    l->SetMarkerColor(kRed);
    l->SetLineColor(kRed);
    l->Draw("P");
    TGraphErrors *r = new TGraphErrors(3,count,spt35,ex,espt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    r->SetMarkerStyle(28);
    r->SetMarkerSize(2);
    r->SetMarkerColor(kOrange);
    r->SetLineColor(kOrange);
    r->Draw("P");
    TGraphErrors *y = new TGraphErrors(3,count,spt45,ex,espt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    y->SetMarkerStyle(28);
    y->SetMarkerSize(2);
    y->SetMarkerColor(kGreen);
    y->SetLineColor(kGreen);
    y->Draw("P");
    TLegend* leg6 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg6,.03);
    leg6->SetTextColor(kAzure);
    leg6->AddEntry("f","ptmin=5 GeV","");
    leg6->Draw();
    TLegend* leg7 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg7,.03);
    leg7->SetTextColor(kMagenta);
    leg7->AddEntry("f","ptmin=15 GeV","");
    leg7->Draw();
    TLegend* leg8 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg8,.03);
    leg8->SetTextColor(kRed);
    leg8->AddEntry("f","ptmin=25 GeV","");
    leg8->Draw();
    TLegend* leg10 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg10,.03);
    leg10->SetTextColor(kOrange);
    leg10->AddEntry("f","ptmin=35 GeV","");
    leg10->Draw();
    TLegend* leg11 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg11,.03);
    leg11->SetTextColor(kGreen);
    leg11->AddEntry("f","ptmin=45 GeV","");
    leg11->Draw();
    TLegend* leg9 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg9,.03);
    leg9->AddEntry("f","PYTHIA","P");
    leg9->AddEntry("y","PYTHIA-Rho","P");
    leg9->Draw();

    TCanvas *c4= new TCanvas("c4","",1000,1000);
    
    TGraph*f1 = new TGraph(3,count,ejpt5);
    f1->GetYaxis()->SetRangeUser(0,1);
    f1->SetMarkerStyle(23);
    f1->SetMarkerSize(2);
    f1->SetMarkerColor(kAzure);
    f1->SetLineColor(kAzure);
    f1->GetYaxis()->SetTitle("Sigma");
    f1->GetXaxis()->SetTitle("Jet Radius");
    f1->Draw("APsame");
    TGraph *g1 = new TGraph(3,count,ejpt15);
    //g->GetYaxis()->SetRangeUser(0,2);
    g1->SetMarkerStyle(23);
    g1->SetMarkerSize(2);
    g1->SetMarkerColor(kMagenta);
    g1->SetLineColor(kMagenta);
    g1->Draw("P");
    TGraph *h1 = new TGraph(3,count,ejpt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    h1->SetMarkerStyle(23);
    h1->SetMarkerSize(2);
    h1->SetMarkerColor(kRed);
    h1->SetLineColor(kRed);
    h1->Draw("P");
    TGraph *w1 = new TGraph(3,count,ejpt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    w1->SetMarkerStyle(23);
    w1->SetMarkerSize(2);
    w1->SetMarkerColor(kOrange);
    w1->SetLineColor(kOrange);
    w1->Draw("P");
    TGraph *q1 = new TGraph(3,count,ejpt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    q1->SetMarkerStyle(23);
    q1->SetMarkerSize(2);
    q1->SetMarkerColor(kGreen);
    q1->SetLineColor(kGreen);
    q1->Draw("P");
    TGraph *j1 = new TGraph(3,count,espt5);
    //h->GetYaxis()->SetRangeUser(0,2);
    j1->SetMarkerStyle(28);
    j1->SetMarkerSize(2);
    j1->SetMarkerColor(kAzure);
    j1->SetLineColor(kAzure);
    j1->Draw("P");
    TGraph *k1 = new TGraph(3,count,espt15);
    //h->GetYaxis()->SetRangeUser(0,2);
    k1->SetMarkerStyle(28);
    k1->SetMarkerSize(2);
    k1->SetMarkerColor(kMagenta);
    k1->SetLineColor(kMagenta);
    k1->Draw("P");
    TGraph *l1 = new TGraph(3,count,espt25);
    //h->GetYaxis()->SetRangeUser(0,2);
    l1->SetMarkerStyle(28);
    l1->SetMarkerSize(2);
    l1->SetMarkerColor(kRed);
    l1->SetLineColor(kRed);
    l1->Draw("P");
    TGraph *r1 = new TGraph(3,count,espt35);
    //g->GetYaxis()->SetRangeUser(0,2);
    r1->SetMarkerStyle(28);
    r1->SetMarkerSize(2);
    r1->SetMarkerColor(kOrange);
    r1->SetLineColor(kOrange);
    r1->Draw("P");
    TGraph *y1 = new TGraph(3,count,espt45);
    //h->GetYaxis()->SetRangeUser(0,2);
    y1->SetMarkerStyle(28);
    y1->SetMarkerSize(2);
    y1->SetMarkerColor(kGreen);
    y1->SetLineColor(kGreen);
    y1->Draw("P");
    TLegend* leg6 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg6,.03);
    leg6->SetTextColor(kAzure);
    leg6->AddEntry("f","ptmin=5 GeV","");
    leg6->Draw();
    TLegend* leg7 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg7,.03);
    leg7->SetTextColor(kMagenta);
    leg7->AddEntry("f","ptmin=15 GeV","");
    leg7->Draw();
    TLegend* leg8 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg8,.03);
    leg8->SetTextColor(kRed);
    leg8->AddEntry("f","ptmin=25 GeV","");
    leg8->Draw();
    TLegend* leg10 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg10,.03);
    leg10->SetTextColor(kOrange);
    leg10->AddEntry("f","ptmin=35 GeV","");
    leg10->Draw();
    TLegend* leg11 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg11,.03);
    leg11->SetTextColor(kGreen);
    leg11->AddEntry("f","ptmin=45 GeV","");
    leg11->Draw();
    TLegend* leg9 = new TLegend(0.7,0.8,0.85,0.85);
    SetLeg(leg9,.03);
    leg9->AddEntry("f","PYTHIA","P");
    leg9->AddEntry("y","PYTHIA-Rho","P");
    leg9->Draw();

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










