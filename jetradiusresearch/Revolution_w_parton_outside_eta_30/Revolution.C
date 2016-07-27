void Revolution(TString infile = "histos.root"){
    set_plot_style();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    TH2* array[16];
    TFile *_file0 = TFile::Open("pone.root");
    TH2* xjgjetone = (TH2*)gROOT->FindObject("xjghist");
    array[0]= xjgjetone;
    
    TFile *_file1 = TFile::Open("ptwo.root");
    TH2* xjgjettwo = (TH2*)gROOT->FindObject("xjghist");
    array[1]= xjgjettwo;

    TFile *_file2 = TFile::Open("pthree.root");
    TH2* xjgjetthree = (TH2*)gROOT->FindObject("xjghist");
    array[2]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("pfour.root");
    TH2* xjgjetfour = (TH2*)gROOT->FindObject("xjghist");
    array[3]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("pseven.root");
    TH2* xjgjetfive = (TH2*)gROOT->FindObject("xjghist");
    array[4]= xjgjetfive;

    TFile *_file5 = TFile::Open("one.root");
    TH2* xjgjetsix = (TH2*)gROOT->FindObject("xjghist");
    array[5]= xjgjetsix;
    
    /*TFile *_file6 = TFile::Open("histseven.root");
    TH2* xjgjetseven = (TH2*)gROOT->FindObject("xjgjet");
    array[6]= xjgjetseven;
    
    TFile *_file7 = TFile::Open("histeight.root");
    TH2* xjgjeteight = (TH2*)gROOT->FindObject("xjgjet");
    array[7]= xjgjeteight;
    
    TFile *_file8 = TFile::Open("histnine.root");
    TH2* xjgjetnine = (TH2*)gROOT->FindObject("xjgjet");
    array[8]= xjgjetnine;

    TFile *_file9 = TFile::Open("histten.root");
    TH2* xjgjetten = (TH2*)gROOT->FindObject("xjgjet");
    array[9]= xjgjetten;

    TFile *_file10 = TFile::Open("histeleven.root");
    TH2* xjgjeteleven = (TH2*)gROOT->FindObject("xjgjet");
    array[10]= xjgjeteleven;

    TFile *_file11 = TFile::Open("histtwelve.root");
    TH2* xjgjettwelve = (TH2*)gROOT->FindObject("xjgjet");
    array[11]= xjgjettwelve;

    TFile *_file12 = TFile::Open("histthirteen.root");
    TH2* xjgjetthirteen = (TH2*)gROOT->FindObject("xjgjet");
    array[12]= xjgjetthirteen;

    TFile *_file13 = TFile::Open("histfourteen.root");
    TH2* xjgjetfourteen = (TH2*)gROOT->FindObject("xjgjet");
    array[13]= xjgjetfourteen;

    TFile *_file14 = TFile::Open("histfifteen.root");
    TH2* xjgjetfifteen = (TH2*)gROOT->FindObject("xjgjet");
    array[14]= xjgjetfifteen;

    TFile *_file15 = TFile::Open("histsixteen.root");
    TH2* xjgjetsixteen = (TH2*)gROOT->FindObject("xjgjet");
    array[15]= xjgjetsixteen;*/
    
    TCanvas* c1 = new TCanvas("c1","",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c1->Divide(3,2);
    for(int i=0;i<6;i++){
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
            leg->SetHeader("R=0.1");
            leg->Draw();
             array[i]->GetXaxis()->SetLabelOffset(999);
             array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==1){
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetHeader("R=0.2");
            leg2->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==2){
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.3");
            leg3->Draw();
            array[i]->GetXaxis()->SetLabelOffset(999);
            array[i]->GetXaxis()->SetLabelSize(0);
        }
        else if(i==3){
            TLegend* leg4 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg4,.05);
            leg4->SetHeader("R=0.4");
            leg4->Draw();
        }
        else if(i==4){
            TLegend* leg5 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("R=0.7");
            leg5->Draw();
        }
        else if(i==5){
            TLegend* leg6 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg6,.05);
            leg6->SetHeader("R=1.0");
            leg6->Draw();
        }

    }
    TCanvas* c2 = new TCanvas("c2","XJG Distribution",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c2->Divide(3,2);
    c2->cd(1);
    TH1 *f=array[0]->ProjectionY("f",1,-1);
    f->Draw();
    leg->Draw();
    Double_t r=f->GetMean();
    cout<<r<<endl;
    r=f->GetRMS();
    cout<<r<<endl;
    r=f->Integral();
    cout<<r<<endl;
    
    c2->cd(2);
    TH1 *g=array[1]->ProjectionY("g",1,-1);
    g->Draw();
    leg2->Draw();
    r=g->GetMean();
    cout<<r<<endl;
    r=g->GetRMS();
    cout<<r<<endl;
    r=g->Integral();
    cout<<r<<endl;

    
    c2->cd(3);
    TH1 *h=array[2]->ProjectionY("h",1,-1);
    h->Draw();
    leg3->Draw();
    r=h->GetMean();
    cout<<r<<endl;
    r=h->GetRMS();
    cout<<r<<endl;
    r=h->Integral();
    cout<<r<<endl;

    
    c2->cd(4);
    TH1 *j=array[3]->ProjectionY("j",1,-1);
    j->Draw();
    leg4->Draw();
    r=j->GetMean();
    cout<<r<<endl;
    r=j->GetRMS();
    cout<<r<<endl;
    r=j->Integral();
    cout<<r<<endl;

    
    c2->cd(5);
    TH1 *k=array[4]->ProjectionY("k",1,-1);
    k->Draw();
    leg5->Draw();
    r=k->GetMean();
    cout<<r<<endl;
    r=k->GetRMS();
    cout<<r<<endl;
    r=k->Integral();
    cout<<r<<endl;
    k->Fit("gaus","I","I",0.8,1.2);
    TF1 *fit4 = (TF1*)k->GetFunction("gaus");
    
    c2->cd(6);
    TH1 *l=array[5]->ProjectionY("l",1,-1);
    l->Draw();
    leg6->Draw();
    r=l->GetMean();
    cout<<r<<endl;
    r=l->GetRMS();
    cout<<r<<endl;
    r=l->Integral();
    cout<<r<<endl;
    
    TFile *file1 = TFile::Open("Background30.root","RECREATE");
    f->Write();
    g->Write();
    h->Write();
    j->Write();
    k->Write();
    l->Write();
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










