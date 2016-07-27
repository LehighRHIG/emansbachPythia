void Revolutionwcuts15(TString infile = "histos.root"){
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
    
    TH1* Background[16];
    TFile *_file6 = TFile::Open("Background.root");
    TH1* xjgjetseven = (TH1*)gROOT->FindObject("f");
    Background[0]= xjgjetseven;
    
    TFile *_file7 = TFile::Open("Background.root");
    TH1* xjgjeteight = (TH1*)gROOT->FindObject("g");
    Background[1]= xjgjeteight;
    
    TFile *_file8 = TFile::Open("Background.root");
    TH1* xjgjetnine = (TH1*)gROOT->FindObject("h");
    Background[2]= xjgjetnine;
    
    TFile *_file9 = TFile::Open("Background.root");
    TH1* xjgjetten = (TH1*)gROOT->FindObject("j");
    Background[3]= xjgjetten;
    
    TFile *_file10 = TFile::Open("Background.root");
    TH1* xjgjeteleven = (TH1*)gROOT->FindObject("k");
    Background[4]= xjgjeteleven;
    
    TFile *_file11 = TFile::Open("Background.root");
    TH1* xjgjettwelve = (TH1*)gROOT->FindObject("l");
    Background[5]= xjgjettwelve;
    
    /*

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
    gPad->SetRightMargin(0.15);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c1->Divide(3,2);
    for(int i=0;i<6;i++){
        c1->cd(i+1);
        array[i]->Draw("colz");
        gPad->SetLogz();
        gPad->SetLeftMargin(0.12);
        gPad->SetRightMargin(0.12);
        gPad->SetTopMargin(0.12);
        gPad->SetBottomMargin(0.12);
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
    Background[0]->SetLineColor(kRed);
    Double_t projheight=f->GetBinContent(1);
    Double_t backheight=Background[0]->GetBinContent(1);
    Double_t scalar=(projheight/backheight);
    Background[0]->Scale(scalar);
    Background[0]->Draw("same");
    leg->Draw();
    /*Double_t r=f->GetMean();
    cout<<r<<endl;
    r=f->GetRMS();
    cout<<r<<endl;
    r=f->Integral();
    cout<<r<<endl;*/

    
    c2->cd(2);
    TH1 *g=array[1]->ProjectionY("g",1,-1);
    g->Draw();
    Background[1]->SetLineColor(kRed);
    projheight=g->GetBinContent(1);
    backheight=Background[1]->GetBinContent(1);
    scalar=(projheight/backheight);
    Background[1]->Scale(scalar);
    Background[1]->Draw("same");
    leg2->Draw();
    /*r=g->GetMean();
    cout<<r<<endl;
    r=g->GetRMS();
    cout<<r<<endl;
    r=g->Integral();
    cout<<r<<endl;*/

    
    c2->cd(3);
    TH1 *h=array[2]->ProjectionY("h",1,-1);
    h->Draw();
    Background[2]->SetLineColor(kRed);
    projheight=h->GetBinContent(1);
    backheight=Background[2]->GetBinContent(1);
    scalar=(projheight/backheight);
    Background[2]->Scale(scalar);
    Background[2]->Draw("same");
    leg3->Draw();
    /*r=h->GetMean();
    cout<<r<<endl;
    r=h->GetRMS();
    cout<<r<<endl;
    r=h->Integral();
    cout<<r<<endl;*/

    
    c2->cd(4);
    TH1 *j=array[3]->ProjectionY("j",1,-1);
    j->Draw();
    Background[3]->SetLineColor(kRed);
    projheight=j->GetBinContent(1);
    backheight=Background[3]->GetBinContent(1);
    scalar=(projheight/backheight);
    Background[3]->Scale(scalar);
    Background[3]->Draw("same");
    leg4->Draw();
    /*r=j->GetMean();
    cout<<r<<endl;
    r=j->GetRMS();
    cout<<r<<endl;
    r=j->Integral();
    cout<<r<<endl;*/

    
    c2->cd(5);
    TH1 *k=array[4]->ProjectionY("k",1,-1);
    k->Draw();
    Background[4]->SetLineColor(kRed);
    projheight=k->GetBinContent(1);
    backheight=Background[4]->GetBinContent(1);
    scalar=(projheight/backheight);
    Background[4]->Scale(scalar);
    Background[4]->Draw("same");
    leg5->Draw();
    /*r=k->GetMean();
    cout<<r<<endl;
    r=k->GetRMS();
    cout<<r<<endl;
    r=k->Integral();
    cout<<r<<endl;
    k->Fit("gaus","I","I",0.6,1.4);
    TF1 *fit4 = (TF1*)k->GetFunction("gaus");*/
    
    c2->cd(6);
    TH1 *l=array[5]->ProjectionY("l",1,-1);
    l->Draw();
    Background[5]->SetLineColor(kRed);
    projheight=l->GetBinContent(1);
    backheight=Background[5]->GetBinContent(1);
    /*scalar=(projheight/backheight);
    Background[5]->Scale(scalar);*/
    Background[5]->Draw("same");
    leg6->Draw();
    /*r=l->GetMean();
    cout<<r<<endl;
    r=l->GetRMS();
    cout<<r<<endl;
    r=l->Integral();
    cout<<r<<endl;*/
    
    TCanvas* c3 = new TCanvas("c3","XJG Distribution Subtracted Background",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c3->Divide(3,2);
    
    c3->cd(1);
    TH1F *z=new TH1F("test","test",50,0,2);
    test->Add(f);
    test->Add(Background[0],-1);
    Double_t count=test->Integral(1,-1);
    test->Scale(1.0/(count*50.0));
    test->GetYaxis()->SetRangeUser(0,.004);
    test->Draw();
    leg->Draw();
    
    c3->cd(2);
    TH1F *test1=new TH1F("test1","test1",50,0,2);
    test1->Add(g);
    test1->Add(Background[1],-1);
    count=test1->Integral(1,-1);
    test1->Scale(1.0/(count*50.0));
    test1->GetYaxis()->SetRangeUser(0,.004);
    test1->Draw();
    leg2->Draw();
    
    c3->cd(3);
    TH1F *test2=new TH1F("test2","test2",50,0,2);
    test2->Add(h);
    test2->Add(Background[2],-1);
    count=test2->Integral(1,-1);
    test2->Scale(1.0/(count*50.0));
    test2->GetYaxis()->SetRangeUser(0,.004);
    test2->Draw();
    leg3->Draw();
    
    c3->cd(4);
    TH1F *test3=new TH1F("test3","test3",50,0,2);
    test3->Add(j);
    test3->Add(Background[3],-1);
    count=test3->Integral(1,-1);
    test3->Scale(1.0/(count*50.0));
    test3->GetYaxis()->SetRangeUser(0,.004);
    test3->Draw();
    leg4->Draw();
    
    c3->cd(5);
    TH1F *test4=new TH1F("test4","test4",50,0,2);
    test4->Add(k);
    test4->Add(Background[4],-1);
    count=test4->Integral(1,-1);
    test4->Scale(1.0/(count*50.0));
    test4->GetYaxis()->SetRangeUser(0,.004);
    test4->Draw();
    leg5->Draw();
    
    c3->cd(6);
    TH1F *test5=new TH1F("test5","test5",50,0,2);
    test5->Add(l);
    test5->Add(Background[5],-1);
    count=test5->Integral(1,-1);
    //test5->Scale(1.0/(count*50.0));
    test5->GetYaxis()->SetRangeUser(0,.004);
    test5->Draw();
    leg6->Draw();
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










