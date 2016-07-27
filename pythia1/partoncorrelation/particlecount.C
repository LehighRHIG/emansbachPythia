void particlecount(){
    set_plot_style();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(1);



    Int_t n=4;
    Double_t count[4]={.75,1.25,2.0,3.25};
    Double_t gcount[4]={11863.0,4818.0,3908.0,1923.0};
    Double_t gx[4]={.25,.25,.5,.75};
    Double_t gerror[4]={501,297,244,144};
    Double_t qx[4]={.25,.25,.5,.75};
    Double_t qerror[4]={426,243,205,128};
    Double_t qcount[4]={8487,3387,2985,1797};
    TGraphErrors *gluoncount=new TGraphErrors(n,count,gcount,gx,gerror);
    TCanvas *c1= new TCanvas("c1","Raw Particle Count",1);
    gluoncount->SetTitle("Raw Particle Count");
    gluoncount->GetXaxis()->SetTitle("Associated Particle Energy(GeV)");
    gluoncount->GetYaxis()->SetTitle("Particle Counts");
    gluoncount->SetLineColor(kBlue);
    gluoncount->Draw("AP");
    
    TGraphErrors *quarkcount=new TGraphErrors(n,count,qcount,qx,qerror);
    quarkcount->SetLineColor(kRed);
    quarkcount->Draw("sameP");


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










