void xjgmean(){
    set_plot_style();
    
    Int_t n= 6;
    Double_t count[6]={0.1,0.2,0.3,0.4,0.7,1.0};
    Double_t fifteen[6]={.30,.65,.70,.875,.92,.95};
    Double_t fex[6]={0,0,0,0,0,0};
    Double_t fey[6]={.23,.28,.31,.32,.33,.34};
    Double_t thirty[6]={.518,.83,.87,.925,.975,1.0};
    Double_t tex[6]={0,0,0,0,0,0};
    Double_t tey[6]={.228,.23,.22,.212,.201,.20};
    TGraphErrors *t=new TGraphErrors(n,count,thirty,tex,tey);
    TGraphErrors *f=new TGraphErrors(n,count,fifteen,fex,fey);
    t->SetTitle("Mean XJG For Varying R");
    t->GetXaxis()->SetTitle("R");
    t->GetYaxis()->SetTitle("Mean XJG");
    t->SetLineColor(kBlue);
    t->SetMarkerSize(1);
    t->SetMarkerColor(kBlue);
    t->Draw("A*");
    f->SetLineColor(kRed);
    f->SetMarkerSize(1);
    f->SetMarkerColor(kRed);
    f->Draw("same*");
    TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
    SetLeg(leg2,.04);
    leg2->SetHeader("");
    leg2->AddEntry(t,"30 GeV","l");
    leg2->AddEntry(f,"15 GeV","l");
    leg2->Draw();


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










