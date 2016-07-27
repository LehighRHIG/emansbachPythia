void phietacorrelation(TString infile = "histos.root"){
    set_plot_style();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    TH2* array[16];
    TFile *_file0 = TFile::Open("histone.root");
    TH2* deltphione = (TH2*)gROOT->FindObject("deltphieta");
    array[0]= deltphione;
    
    TFile *_file1 = TFile::Open("histtwo.root");
    TH2* deltphitwo = (TH2*)gROOT->FindObject("deltphieta");
    array[1]= deltphitwo;

    TFile *_file2 = TFile::Open("histthree.root");
    TH2* deltphithree = (TH2*)gROOT->FindObject("deltphieta");
    array[2]= deltphithree;
    
    TFile *_file3 = TFile::Open("histfour.root");
    TH2* deltphifour = (TH2*)gROOT->FindObject("deltphieta");
    array[3]= deltphifour;
    
    TFile *_file4 = TFile::Open("histfive.root");
    TH2* deltphifive = (TH2*)gROOT->FindObject("deltphieta");
    array[4]= deltphifive;

    TFile *_file5 = TFile::Open("histsix.root");
    TH2* deltphisix = (TH2*)gROOT->FindObject("deltphieta");
    array[5]= deltphisix;
    
    TFile *_file6 = TFile::Open("histseven.root");
    TH2* deltphiseven = (TH2*)gROOT->FindObject("deltphieta");
    array[6]= deltphiseven;
    
    TFile *_file7 = TFile::Open("histeight.root");
    TH2* deltphieight = (TH2*)gROOT->FindObject("deltphieta");
    array[7]= deltphieight;
    
    TFile *_file8 = TFile::Open("histnine.root");
    TH2* deltphinine = (TH2*)gROOT->FindObject("deltphieta");
    array[8]= deltphinine;

    TFile *_file9 = TFile::Open("histten.root");
    TH2* deltphiten = (TH2*)gROOT->FindObject("deltphieta");
    array[9]= deltphiten;

    TFile *_file10 = TFile::Open("histeleven.root");
    TH2* deltphieleven = (TH2*)gROOT->FindObject("deltphieta");
    array[10]= deltphieleven;

    TFile *_file11 = TFile::Open("histtwelve.root");
    TH2* deltphitwelve = (TH2*)gROOT->FindObject("deltphieta");
    array[11]= deltphitwelve;

    TFile *_file12 = TFile::Open("histthirteen.root");
    TH2* deltphithirteen = (TH2*)gROOT->FindObject("deltphieta");
    array[12]= deltphithirteen;

    TFile *_file13 = TFile::Open("histfourteen.root");
    TH2* deltphifourteen = (TH2*)gROOT->FindObject("deltphieta");
    array[13]= deltphifourteen;

    TFile *_file14 = TFile::Open("histfifteen.root");
    TH2* deltphififteen = (TH2*)gROOT->FindObject("deltphieta");
    array[14]= deltphififteen;

    TFile *_file15 = TFile::Open("histsixteen.root");
    TH2* deltphisixteen = (TH2*)gROOT->FindObject("deltphieta");
    array[15]= deltphisixteen;
    
    TCanvas* c1 = new TCanvas("c1","",2000,2000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c1->Divide(4,4);
    for(int i=0;i<4;i++){
        c1->cd(i+1);
        array[i]->Draw("lego");
        array[i]->GetYaxis()->SetRangeUser(-2, 2);
        array[i]->GetZaxis()->SetRangeUser(0, 25e-6);
        array[i]->GetXaxis()->SetLabelOffset(999);
        array[i]->GetXaxis()->SetLabelSize(0);
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.0);
        gPad->SetTopMargin(0.0);
        gPad->SetBottomMargin(0.0);
         if(i==0){
            TLegend* leg = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg,.05);
            leg->SetHeader("pt_trig:2.5-3.0 Gev");
            leg->AddEntry(array[0],"pt_assoc:0.5-1.0 Gev","D");
            leg->Draw();
        }
        else if(i==1){
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetHeader("pt_trig:3.0-4.0 Gev");
            leg2->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==2){
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("pt_trig:4.0-6.0 Gev");
            leg3->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==3){
            TLegend* leg4 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg4,.05);
            leg4->SetHeader("pt_trig:6.0-10.0 Gev");
            leg4->Draw();
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
    }
    for(int i=4;i<8;i++){
        c1->cd(i+1);
        array[i]->Draw("lego");
        array[i]->GetYaxis()->SetRangeUser(-2, 2);
        array[i]->GetZaxis()->SetRangeUser(0, 25e-6);
        array[i]->GetXaxis()->SetLabelOffset(999);
        array[i]->GetXaxis()->SetLabelSize(0);
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.0);
        gPad->SetTopMargin(0.0);
        gPad->SetBottomMargin(0.0);
        if(i>4){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==4){
            TLegend* leg5 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("pt_assoc:1.0-1.5 Gev");
            leg5->Draw();
        }
        
    }
    for(int i=8;i<12;i++){
        c1->cd(i+1);
        array[i]->Draw("lego");
        array[i]->GetYaxis()->SetRangeUser(-2, 2);
        array[i]->GetZaxis()->SetRangeUser(0, 25e-6);
        array[i]->GetXaxis()->SetLabelOffset(999);
        array[i]->GetXaxis()->SetLabelSize(0);
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.0);
        gPad->SetTopMargin(0.0);
        gPad->SetBottomMargin(0.0);
        if(i>8){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==8){
            TLegend* leg6 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg6,.05);
            leg6->SetHeader("pt_assoc:1.5-2.5 Gev");
            leg6->Draw();
        }
    }
    for(int i=12;i<16;i++){
        c1->cd(i+1);
        array[i]->Draw("lego");
        array[i]->GetYaxis()->SetRangeUser(-2,2);
        array[i]->GetZaxis()->SetRangeUser(0, 25e-6);
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.0);
        gPad->SetTopMargin(0.0);
        gPad->SetBottomMargin(0.1);
        if(i>12){
            array[i]->GetYaxis()->SetLabelOffset(999);
            array[i]->GetYaxis()->SetLabelSize(0);
        }
        else if(i==12){
            TLegend* leg7 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg7,.05);
            leg7->SetHeader("pt_assoc:2.5-4.0 Gev");
            leg7->Draw();
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










