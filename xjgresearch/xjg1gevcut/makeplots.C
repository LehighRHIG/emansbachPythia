void makeplots(TString infile = "histos.root"){
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
    
    
    
    TH1* carray[30];
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* cone = (TH1*)gROOT->FindObject("True5p2");
    carray[0]= cone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("True5p3");
    carray[1]= ctwo;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* cthree = (TH1*)gROOT->FindObject("True5p4");
    carray[2]= cthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* cfour = (TH1*)gROOT->FindObject("True10p2");
    carray[3]= cfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* cfive = (TH1*)gROOT->FindObject("True10p3");
    carray[4]= cfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* csix = (TH1*)gROOT->FindObject("True10p4");
    carray[5]= csix;
    
    TFile *_file6 = TFile::Open("unfoldplots.root");
    TH1* cseven = (TH1*)gROOT->FindObject("True15p2");
    carray[6]= cseven;
    
    TFile *_file7 = TFile::Open("unfoldplots.root");
    TH1* ceight = (TH1*)gROOT->FindObject("True15p3");
    carray[7]= ceight;
    
    TFile *_file8 = TFile::Open("unfoldplots.root");
    TH1* cnine = (TH1*)gROOT->FindObject("True15p4");
    carray[8]= cnine;
    
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* conea = (TH1*)gROOT->FindObject("True20p2");
    carray[9]= conea;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* ctwoa = (TH1*)gROOT->FindObject("True20p3");
    carray[10]= ctwoa;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* cthreea = (TH1*)gROOT->FindObject("True20p4");
    carray[11]= cthreea;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* cfoura = (TH1*)gROOT->FindObject("True25p2");
    carray[12]= cfoura;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* cfivea = (TH1*)gROOT->FindObject("True25p3");
    carray[13]= cfivea;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* csixa = (TH1*)gROOT->FindObject("True25p4");
    carray[14]= csixa;
    
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* cone = (TH1*)gROOT->FindObject("True30p2");
    carray[15]= cone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("True30p3");
    carray[16]= ctwo;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* cthree = (TH1*)gROOT->FindObject("True30p4");
    carray[17]= cthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* cfour = (TH1*)gROOT->FindObject("True35p2");
    carray[18]= cfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* cfive = (TH1*)gROOT->FindObject("True35p3");
    carray[19]= cfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* csix = (TH1*)gROOT->FindObject("True35p4");
    carray[20]= csix;
    
    TFile *_file6 = TFile::Open("unfoldplots.root");
    TH1* cseven = (TH1*)gROOT->FindObject("True40p2");
    carray[21]= cseven;
    
    TFile *_file7 = TFile::Open("unfoldplots.root");
    TH1* ceight = (TH1*)gROOT->FindObject("True40p3");
    carray[22]= ceight;
    
    TFile *_file8 = TFile::Open("unfoldplots.root");
    TH1* cnine = (TH1*)gROOT->FindObject("True40p4");
    carray[23]= cnine;
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* cone = (TH1*)gROOT->FindObject("True45p2");
    carray[24]= cone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("True45p3");
    carray[25]= ctwo;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* cthree = (TH1*)gROOT->FindObject("True45p4");
    carray[26]= cthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* cfour = (TH1*)gROOT->FindObject("True50p2");
    carray[27]= cfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* cfive = (TH1*)gROOT->FindObject("True50p3");
    carray[28]= cfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* csix = (TH1*)gROOT->FindObject("True50p4");
    carray[29]= csix;
    
    TCanvas* c3 = new TCanvas("c3","",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c3->Divide(3,5);
    for(int i=0;i<15;i++){
        c3->cd(i+1);
        carray[i]->Draw();
        carray[i]->GetYaxis()->SetTitle("counts");
        carray[i]->GetXaxis()->SetTitle("x_{J#gamma}");
        carray[i]->GetYaxis()->SetTitleSize(.15);
        carray[i]->GetXaxis()->SetTitleSize(.15);
        gPad->SetLogy();
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.1);
        gPad->SetTopMargin(0.1);
        gPad->SetBottomMargin(0.1);
        if(i==0){
            TLegend* leg = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg,.05);
            leg->SetHeader("Ptmin=5 GeV");
            leg->AddEntry("array[0]","R=0.2","");
            leg->AddEntry("array[0]","combined tracks","");
            leg->SetTextSize(.15);
            leg->Draw();
        }
        else if(i==1){
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetHeader("R=0.3");
            leg2->AddEntry(array[0],"unfolded","l");
            leg2->AddEntry(carray[0],"pythia","l");
            leg2->SetTextSize(.15);
            leg2->Draw();
        }
        else if(i==2){
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
                        leg3->SetTextSize(.15);
            leg3->Draw();
        }
        else if(i==3){
            TLegend* leg4 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg4,.05);
            leg4->SetHeader("Ptmin=10 GeV");
                        leg4->SetTextSize(.15);
            leg4->Draw();
        }
        else if(i==6){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=15 GeV");
                        leg5->SetTextSize(.15);
            leg5->Draw();
        }
        else if(i==9){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=20 GeV");
                        leg5->SetTextSize(.15);
            leg5->Draw();
        }
        else if(i==12){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=25 GeV");
                        leg5->SetTextSize(.15);
            leg5->Draw();
        }
        //*scale= ((carray[i]->Integral(0,50))/(array[i]->Integral(0,50)));
        //array[i]->Scale(scale);
        array[i]->SetLineColor(kRed);
        array[i]->Draw("same");
        //cout<<scale<<endl;
    }
    
    TCanvas* c4 = new TCanvas("c4","",1000,1000);
    
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c4->Divide(3,5);
    for(int i=15;i<30;i++){
        c4->cd(i-14);
        carray[i]->Draw();
        gPad->SetLogy();
        gPad->SetLeftMargin(0.1);
        gPad->SetRightMargin(0.1);
        gPad->SetTopMargin(0.1);
        gPad->SetBottomMargin(0.1);
        if(i==15){
            TLegend* leg6 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg6,.05);
            leg6->SetHeader("Ptmin=30 GeV");
            leg6->AddEntry("array[15]","R=0.2","");
            leg6->AddEntry("array[15]","unfolded","");
                        leg6->SetTextSize(.15);
            leg6->Draw();
        }
        else if(i==16){
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetHeader("R=0.3");
            leg2->AddEntry(array[0],"unfolded","l");
            leg2->AddEntry(carray[0],"pythia","l");
                        leg2->SetTextSize(.15);
            leg2->Draw();
        }
        else if(i==17){
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
                        leg3->SetTextSize(.15);
            leg3->Draw();
        }
        else if(i==18){
            TLegend* leg7 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg7,.05);
            leg7->SetHeader("Ptmin=35 GeV");
                        leg7->SetTextSize(.15);
            leg7->Draw();
        }
        else if(i==21){
            TLegend* leg8 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg8,.05);
            leg8->SetHeader("Ptmin=40 GeV");
                        leg8->SetTextSize(.15);
            leg8->Draw();
        }
        else if(i==24){
            TLegend* leg9 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg9,.05);
            leg9->SetHeader("Ptmin=45 GeV");
                        leg9->SetTextSize(.15);
            leg9->Draw();
        }
        else if(i==27){
            TLegend* leg10 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg10,.05);
            leg10->SetHeader("Ptmin=50 GeV");
                        leg10->SetTextSize(.15);
            leg10->Draw();
        }
        //scale= ((carray[i]->Integral(0,50))/(array[i]->Integral(0,50)));
        //array[i]->Scale(scale);
        array[i]->SetLineColor(kRed);
        array[i]->Draw("same");
        //cout<<scale<<endl;
    }
  
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
        eupt5[i]=array[i]->GetRMS(1);
    for(int i=3;i<6;i++)
        eupt10[i-3]=array[i]->GetRMS(1);
    for(int i=6;i<9;i++)
        eupt15[i-6]=array[i]->GetRMS(1);
    for(int i=9;i<12;i++)
        eupt20[i-9]=array[i]->GetRMS(1);
    for(int i=12;i<15;i++)
        eupt25[i-12]=array[i]->GetRMS(1);
    for(int i=15;i<18;i++)
        eupt30[i-15]=array[i]->GetRMS(1);
    for(int i=18;i<21;i++)
        eupt35[i-18]=array[i]->GetRMS(1);
    for(int i=21;i<24;i++)
        eupt40[i-21]=array[i]->GetRMS(1);
    for(int i=24;i<27;i++)
        eupt45[i-24]=array[i]->GetRMS(1);
    for(int i=27;i<30;i++)
        eupt50[i-27]=array[i]->GetRMS(1);
    
    
    TH1* sarray[30];
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* cone = (TH1*)gROOT->FindObject("Meas5p2");
    sarray[0]= cone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("Meas5p3");
    sarray[1]= ctwo;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* cthree = (TH1*)gROOT->FindObject("Meas5p4");
    sarray[2]= cthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* cfour = (TH1*)gROOT->FindObject("Meas10p2");
    sarray[3]= cfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* cfive = (TH1*)gROOT->FindObject("Meas10p3");
    sarray[4]= cfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* csix = (TH1*)gROOT->FindObject("Meas10p4");
    sarray[5]= csix;
    
    TFile *_file6 = TFile::Open("unfoldplots.root");
    TH1* cseven = (TH1*)gROOT->FindObject("Meas15p2");
    sarray[6]= cseven;
    
    TFile *_file7 = TFile::Open("unfoldplots.root");
    TH1* ceight = (TH1*)gROOT->FindObject("Meas15p3");
    sarray[7]= ceight;
    
    TFile *_file8 = TFile::Open("unfoldplots.root");
    TH1* cnine = (TH1*)gROOT->FindObject("Meas15p4");
    sarray[8]= cnine;
    
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* conea = (TH1*)gROOT->FindObject("Meas20p2");
    sarray[9]= conea;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* ctwoa = (TH1*)gROOT->FindObject("Meas20p3");
    sarray[10]= ctwoa;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* cthreea = (TH1*)gROOT->FindObject("Meas20p4");
    sarray[11]= cthreea;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* cfoura = (TH1*)gROOT->FindObject("Meas25p2");
    sarray[12]= cfoura;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* cfivea = (TH1*)gROOT->FindObject("Meas25p3");
    sarray[13]= cfivea;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* csixa = (TH1*)gROOT->FindObject("Meas25p4");
    sarray[14]= csixa;
    
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* cone = (TH1*)gROOT->FindObject("Meas30p2");
    sarray[15]= cone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("Meas30p3");
    sarray[16]= ctwo;

    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* cthree = (TH1*)gROOT->FindObject("Meas30p4");
    sarray[17]= cthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* cfour = (TH1*)gROOT->FindObject("Meas35p2");
    sarray[18]= cfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* cfive = (TH1*)gROOT->FindObject("Meas35p3");
    sarray[19]= cfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* csix = (TH1*)gROOT->FindObject("Meas35p4");
    sarray[20]= csix;
    
    TFile *_file6 = TFile::Open("unfoldplots.root");
    TH1* cseven = (TH1*)gROOT->FindObject("Meas40p2");
    sarray[21]= cseven;
    
    TFile *_file7 = TFile::Open("unfoldplots.root");
    TH1* ceight = (TH1*)gROOT->FindObject("Meas40p3");
    sarray[22]= ceight;
    
    TFile *_file8 = TFile::Open("unfoldplots.root");
    TH1* cnine = (TH1*)gROOT->FindObject("Meas40p4");
    sarray[23]= cnine;
    TFile *_file0 = TFile::Open("unfoldplots.root");
    TH1* cone = (TH1*)gROOT->FindObject("Meas45p2");
    sarray[24]= cone;
    
    TFile *_file1 = TFile::Open("unfoldplots.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("Meas45p3");
    sarray[25]= ctwo;
    
    TFile *_file2 = TFile::Open("unfoldplots.root");
    TH1* cthree = (TH1*)gROOT->FindObject("Meas45p4");
    sarray[26]= cthree;
    
    TFile *_file3 = TFile::Open("unfoldplots.root");
    TH1* cfour = (TH1*)gROOT->FindObject("Meas50p2");
    sarray[27]= cfour;
    
    TFile *_file4 = TFile::Open("unfoldplots.root");
    TH1* cfive = (TH1*)gROOT->FindObject("Meas50p3");
    sarray[28]= cfive;
    
    TFile *_file5 = TFile::Open("unfoldplots.root");
    TH1* csix = (TH1*)gROOT->FindObject("Meas50p4");
    sarray[29]= csix;
    
    Double_t jpt5[3];
    Double_t jpt10[3];
    Double_t jpt15[3];
    Double_t jpt20[3];
    Double_t jpt25[3];
    Double_t jpt30[3];
    Double_t jpt35[3];
    Double_t jpt40[3];
    Double_t jpt45[3];
    Double_t jpt50[3];
    for(int i=0;i<3;i++)
        jpt5[i]=carray[i]->GetMean();
    for(int i=3;i<6;i++)
        jpt10[i-3]=carray[i]->GetMean();
    for(int i=6;i<9;i++)
        jpt15[i-6]=carray[i]->GetMean();
    for(int i=9;i<12;i++)
        jpt20[i-9]=carray[i]->GetMean();
    for(int i=12;i<15;i++)
        jpt25[i-12]=carray[i]->GetMean();
    for(int i=15;i<18;i++)
        jpt30[i-15]=carray[i]->GetMean();
    for(int i=18;i<21;i++)
        jpt35[i-18]=carray[i]->GetMean();
    for(int i=21;i<24;i++)
        jpt40[i-21]=carray[i]->GetMean();
    for(int i=24;i<27;i++)
        jpt45[i-24]=carray[i]->GetMean();
    for(int i=27;i<30;i++)
        jpt50[i-27]=carray[i]->GetMean();
    
    Double_t ejpt5[3];
    Double_t ejpt10[3];
    Double_t ejpt15[3];
    Double_t ejpt20[3];
    Double_t ejpt25[3];
    Double_t ejpt30[3];
    Double_t ejpt35[3];
    Double_t ejpt40[3];
    Double_t ejpt45[3];
    Double_t ejpt50[3];
    for(int i=0;i<3;i++)
        ejpt5[i]=carray[i]->GetRMS(1);
    for(int i=3;i<6;i++)
        ejpt10[i-3]=carray[i]->GetRMS(1);
    for(int i=6;i<9;i++)
        ejpt15[i-6]=carray[i]->GetRMS(1);
    for(int i=9;i<12;i++)
        ejpt20[i-9]=carray[i]->GetRMS(1);
    for(int i=12;i<15;i++)
        ejpt25[i-12]=carray[i]->GetRMS(1);
    for(int i=15;i<18;i++)
        ejpt30[i-15]=carray[i]->GetRMS(1);
    for(int i=18;i<21;i++)
        ejpt35[i-18]=carray[i]->GetRMS(1);
    for(int i=21;i<24;i++)
        ejpt40[i-21]=carray[i]->GetRMS(1);
    for(int i=24;i<27;i++)
        ejpt45[i-24]=carray[i]->GetRMS(1);
    for(int i=27;i<30;i++)
        ejpt50[i-27]=carray[i]->GetRMS(1);
    
    Double_t spt5[3];
    Double_t spt10[3];
    Double_t spt15[3];
    Double_t spt20[3];
    Double_t spt25[3];
    Double_t spt30[3];
    Double_t spt35[3];
    Double_t spt40[3];
    Double_t spt45[3];
    Double_t spt50[3];
    for(int i=0;i<3;i++)
        spt5[i]=sarray[i]->GetMean();
    for(int i=3;i<6;i++)
        spt10[i-3]=sarray[i]->GetMean();
    for(int i=6;i<9;i++)
        spt15[i-6]=sarray[i]->GetMean();
    for(int i=9;i<12;i++)
        spt20[i-9]=sarray[i]->GetMean();
    for(int i=12;i<15;i++)
        spt25[i-12]=sarray[i]->GetMean();
    for(int i=15;i<18;i++)
        spt30[i-15]=sarray[i]->GetMean();
    for(int i=18;i<21;i++)
        spt35[i-18]=sarray[i]->GetMean();
    for(int i=21;i<24;i++)
        spt40[i-21]=sarray[i]->GetMean();
    for(int i=24;i<27;i++)
        spt45[i-24]=sarray[i]->GetMean();
    for(int i=27;i<30;i++)
        spt50[i-27]=sarray[i]->GetMean();
    

    
    Double_t espt5[3];
    Double_t espt10[3];
    Double_t espt15[3];
    Double_t espt20[3];
    Double_t espt25[3];
    Double_t espt30[3];
    Double_t espt35[3];
    Double_t espt40[3];
    Double_t espt45[3];
    Double_t espt50[3];
    for(int i=0;i<3;i++)
        espt5[i]=sarray[i]->GetRMS(1);
    for(int i=3;i<6;i++)
        espt10[i-3]=sarray[i]->GetRMS(1);
    for(int i=6;i<9;i++)
        espt15[i-6]=sarray[i]->GetRMS(1);
    for(int i=9;i<12;i++)
        espt20[i-9]=sarray[i]->GetRMS(1);
    for(int i=12;i<15;i++)
        espt25[i-12]=sarray[i]->GetRMS(1);
    for(int i=15;i<18;i++)
        espt30[i-15]=sarray[i]->GetRMS(1);
    for(int i=18;i<21;i++)
        espt35[i-18]=sarray[i]->GetRMS(1);
    for(int i=21;i<24;i++)
        espt40[i-21]=sarray[i]->GetRMS(1);
    for(int i=24;i<27;i++)
        espt45[i-24]=sarray[i]->GetRMS(1);
    for(int i=27;i<30;i++)
        espt50[i-27]=sarray[i]->GetRMS(1);
   
    Double_t count[3]={0.18,0.28,0.38};
    Double_t count2[3]={0.19,0.29,0.39};
    Double_t count3[3]={.2,.3,.4};
    Double_t count4[3]={.21,.31,.41};
    Double_t count5[3]={.22,.32,.42};
    Double_t range[3]={.15,.3,.45};
    Double_t ex[3]={0,0,0};
    
    TCanvas* c2 = new TCanvas("c2","",1000,1000);
    TGraphErrors *blank=new TGraphErrors(3,range,ex,ex,ex);
    blank->GetYaxis()->SetRangeUser(0,1.5);
    blank->GetYaxis()->SetTitle("mean x_{J#gamma}");
    blank->GetXaxis()->SetTitle("jet radius");
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

void SetLeg(TLegend* l,float txtsize=0.5){
    l->SetBorderSize(0);
    l->SetFillColor(0);
    l->SetTextSize(txtsize);
    gStyle->SetStatStyle(0);
    gStyle->SetTitleStyle(0);
    gROOT->ForceStyle();

}










