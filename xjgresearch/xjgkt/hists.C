void hists(TString infile = "histos.root"){
    set_plot_style();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    TH2* array[30];
    TFile *_file0 = TFile::Open("plots.root");
    TH2* xjgjetone = (TH2*)gROOT->FindObject("j5p2");
    array[0]= xjgjetone;
    
    TFile *_file1 = TFile::Open("plots.root");
    TH2* xjgjettwo = (TH2*)gROOT->FindObject("j5p3");
    array[1]= xjgjettwo;

    TFile *_file2 = TFile::Open("plots.root");
    TH2* xjgjetthree = (TH2*)gROOT->FindObject("j5p4");
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
    
    TFile *_file0 = TFile::Open("plots.root");
    TH2* xjgjetone = (TH2*)gROOT->FindObject("s5p2");
    array[15]= xjgjetone;
    
    TFile *_file1 = TFile::Open("plots.root");
    TH2* xjgjettwo = (TH2*)gROOT->FindObject("s5p3");
    array[16]= xjgjettwo;
    
    TFile *_file2 = TFile::Open("plots.root");
    TH2* xjgjetthree = (TH2*)gROOT->FindObject("s5p4");
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
    c2->Divide(3,1);
    for(int i=0;i<3;i++){
        c2->cd(i+1);
        //array[i]->Draw("colz");
        gPad->SetLogz();
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.1);
        gPad->SetTopMargin(0.1);
        gPad->SetBottomMargin(0.1);
        if(i==0){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->GetXaxis()->SetTitle("X_{J#gamma}");
            f->GetXaxis()->SetTitleSize(.15);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg,.05);
            leg->SetHeader("P_{T,min}=5 GeV");
            leg->AddEntry("array[i]","R=0.2","");
            leg->AddEntry("f","PYTHIA ","l");
            leg->AddEntry("g","PYTHIA-#rhoA","l");
            leg->SetTextSize(.1);
            leg->Draw();
        }
        else if(i==1){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetTextSize(.1);
            leg2->SetHeader("R=0.3");
            leg2->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==2){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
            leg3->SetTextSize(.1);
            leg3->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
    }
    TCanvas* c3 = new TCanvas("c3","",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c3->Divide(3,1);
    for(int i=12;i<15;i++){
        c3->cd(i-11);
        //array[i]->Draw("colz");
        gPad->SetLogz();
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.1);
        gPad->SetTopMargin(0.1);
        gPad->SetBottomMargin(0.1);
        if(i==12){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->GetXaxis()->SetTitle("X_{J#gamma}");
            //f->GetXaxis()->SetTitleSize(.1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg,.05);
            leg->SetHeader("P_{T,min}=45 GeV");
            leg->AddEntry("array[i]","R=0.2","");
            leg->AddEntry("f","PYTHIA ","l");
            leg->AddEntry("g","PYTHIA-#rhoA","l");
            leg->SetTextSize(.1);
            leg->Draw();
        }
        else if(i==13){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
                        f->GetXaxis()->SetTitle("X_{J#gamma}");
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetTextSize(.1);
            leg2->SetHeader("R=0.3");
            leg2->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==14){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
                        f->GetXaxis()->SetTitle("X_{J#gamma}");
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
            leg3->SetTextSize(.1);
            leg3->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
    }
    
    
    
    
    TCanvas* c1 = new TCanvas("c1","",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c1->Divide(3,5);
    for(int i=0;i<15;i++){
        c1->cd(i+1);
        //array[i]->Draw("colz");
        gPad->SetLogz();
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.1);
        gPad->SetTopMargin(0.1);
        gPad->SetBottomMargin(0.1);
        array[i]->GetXaxis()->SetTitle("X_{J#gamma}");
        array[i]->GetXaxis()->SetTitleSize(.15);
        if(i==0){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg,.05);
            leg->SetHeader("P_{T,min}=5 GeV");
            leg->AddEntry("array[i]","R=0.2","");
            leg->AddEntry("f","PYTHIA ","l");
            leg->AddEntry("g","PYTHIA-#rhoA","l");
            leg->SetTextSize(.1);
            leg->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==1){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetTextSize(.1);
            leg2->SetHeader("R=0.3");
            leg2->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==2){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
            leg3->SetTextSize(.1);
            leg3->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==3){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg4 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg4,.05);
            leg4->SetHeader("Ptmin=15 GeV");
            leg4->SetTextSize(.1);
            leg4->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==4){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==5){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==6){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetTextSize(.1);
            leg5->SetHeader("Ptmin=25 GeV");
            leg5->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==7){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==8){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==9){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=35 GeV");
            leg5->SetTextSize(.1);
            leg5->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==10){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==11){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==12){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=45 GeV");
            leg5->SetTextSize(.1);
            leg5->Draw();
        }
        else if(i==13){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==14){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }

    }
    TCanvas* c2 = new TCanvas("c2","",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c2->Divide(3,1);
    for(int i=0;i<3;i++){
        c2->cd(i+1);
        //array[i]->Draw("colz");
        gPad->SetLogz();
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.1);
        gPad->SetTopMargin(0.1);
        gPad->SetBottomMargin(0.1);
        array[i]->GetXaxis()->SetTitle("X_{J#gamma}");
        array[i]->GetXaxis()->SetTitleSize(.15);
        if(i==0){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg,.05);
            leg->SetHeader("Ptmin=5 GeV");
            leg->AddEntry("array[i]","R=0.2","");
            leg->AddEntry("f","PYTHIA ","l");
            leg->AddEntry("g","PYTHIA-#rhoA","l");
            leg->SetTextSize(.1);
            leg->Draw();
        }
        else if(i==1){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetTextSize(.1);
            leg2->SetHeader("R=0.3");
            leg2->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==2){
            TH1 *f= new TH1D("f","",30,0,3);
            f=array[i]->ProjectionY("f",1,-1);
            f->Draw();
            TH1 *g= new TH1D("g","",30,0,3);
            g=array[i+15]->ProjectionY("g",1,-1);
            g->SetLineColor(kRed);
            g->Draw("same");
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
            leg3->SetTextSize(.1);
            leg3->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
    }
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










