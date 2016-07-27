void sigma(){
    set_plot_style();

    
    
    
    Int_t n=4;
    Double_t count[4]={.75,1.25,2.0,3.25};
    Double_t gsig[4]={5.548e-1,3.993e-1,3.084e-1,2.253e-1};
    Double_t gx[4]={.25,.25,.5,.75};
    Double_t gerror[4]={7.91e-3,6.763e-3,5.12e-3,5.18e-3};
    Double_t qx[4]={.25,.25,.5,.75};
    Double_t qsig[4]={5.567e-1,3.559e-1,2.279e-1,1.662e-1};
    Double_t qerror[4]={1.054e-3,8.39e-3,5.477e-3,4.086e-3};
    TGraphErrors *gluoncount=new TGraphErrors(n,count,gsig,gx,gerror);
    TGraphErrors *quarkcount=new TGraphErrors(n,count,qsig,qx,qerror);
    quarkcount->SetTitle("Distribution Width");
    quarkcount->GetXaxis()->SetTitle("Associated Particle Energy(GeV)");
    quarkcount->GetYaxis()->SetTitle("Sigma from Gaussian Fit");
    quarkcount->GetYaxis()->SetRange(0,.6);
    quarkcount->SetLineColor(kRed);
    quarkcount->Draw("AP");
    gluoncount->SetLineColor(kBlue);
    gluoncount->Draw("sameP");
    

    
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



