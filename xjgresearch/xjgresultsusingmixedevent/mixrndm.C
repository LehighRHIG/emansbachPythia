void mixrndm(TString infile = "histos.root"){
    set_plot_style();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    TH1* array[30];
    TFile *_file0 = TFile::Open("plotsrndm.root");
    TH1* xjgjetone = (TH1*)gROOT->FindObject("m5p2");
    array[0]= xjgjetone;
    
    TFile *_file1 = TFile::Open("plotsrndm.root");
    TH1* xjgjettwo = (TH1*)gROOT->FindObject("m5p3");
    array[1]= xjgjettwo;

    TFile *_file2 = TFile::Open("plotsrndm.root");
    TH1* xjgjetthree = (TH1*)gROOT->FindObject("m5p4");
    array[2]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("plotsrndm.root");
    TH1* xjgjetfour = (TH1*)gROOT->FindObject("m10p2");
    array[3]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("plotsrndm.root");
    TH1* xjgjetfive = (TH1*)gROOT->FindObject("m10p3");
    array[4]= xjgjetfive;

    TFile *_file5 = TFile::Open("plotsrndm.root");
    TH1* xjgjetsix = (TH1*)gROOT->FindObject("m10p4");
    array[5]= xjgjetsix;
    
    TFile *_file6 = TFile::Open("plotsrndm.root");
    TH1* xjgjetseven = (TH1*)gROOT->FindObject("m15p2");
    array[6]= xjgjetseven;
    
    TFile *_file7 = TFile::Open("plotsrndm.root");
    TH1* xjgjeteight = (TH1*)gROOT->FindObject("m15p3");
    array[7]= xjgjeteight;
    
    TFile *_file8 = TFile::Open("plotsrndm.root");
    TH1* xjgjetnine = (TH1*)gROOT->FindObject("m15p4");
    array[8]= xjgjetnine;
    
    TFile *_file0 = TFile::Open("plotsrndm.root");
    TH1* xjgjetonea = (TH1*)gROOT->FindObject("m20p2");
    array[9]= xjgjetonea;
    
    TFile *_file1 = TFile::Open("plotsrndm.root");
    TH1* xjgjettwoa = (TH1*)gROOT->FindObject("m20p3");
    array[10]= xjgjettwoa;
    
    TFile *_file2 = TFile::Open("plotsrndm.root");
    TH1* xjgjetthreea = (TH1*)gROOT->FindObject("m20p4");
    array[11]= xjgjetthreea;
    
    TFile *_file3 = TFile::Open("plotsrndm.root");
    TH1* xjgjetfoura = (TH1*)gROOT->FindObject("m25p2");
    array[12]= xjgjetfoura;
    
    TFile *_file4 = TFile::Open("plotsrndm.root");
    TH1* xjgjetfivea = (TH1*)gROOT->FindObject("m25p3");
    array[13]= xjgjetfivea;
    
    TFile *_file5 = TFile::Open("plotsrndm.root");
    TH1* xjgjetsixa = (TH1*)gROOT->FindObject("m25p4");
    array[14]= xjgjetsixa;
    
    TFile *_file0 = TFile::Open("plotsrndm.root");
    TH1* xjgjetone = (TH1*)gROOT->FindObject("m30p2");
    array[15]= xjgjetone;
    
    TFile *_file1 = TFile::Open("plotsrndm.root");
    TH1* xjgjettwo = (TH1*)gROOT->FindObject("m30p3");
    array[16]= xjgjettwo;
    
    TFile *_file2 = TFile::Open("plotsrndm.root");
    TH1* xjgjetthree = (TH1*)gROOT->FindObject("m30p4");
    array[17]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("plotsrndm.root");
    TH1* xjgjetfour = (TH1*)gROOT->FindObject("m35p2");
    array[18]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("plotsrndm.root");
    TH1* xjgjetfive = (TH1*)gROOT->FindObject("m35p3");
    array[19]= xjgjetfive;
    
    TFile *_file5 = TFile::Open("plotsrndm.root");
    TH1* xjgjetsix = (TH1*)gROOT->FindObject("m35p4");
    array[20]= xjgjetsix;
    
    TFile *_file6 = TFile::Open("plotsrndm.root");
    TH1* xjgjetseven = (TH1*)gROOT->FindObject("m40p2");
    array[21]= xjgjetseven;
    
    TFile *_file7 = TFile::Open("plotsrndm.root");
    TH1* xjgjeteight = (TH1*)gROOT->FindObject("m40p3");
    array[22]= xjgjeteight;
    
    TFile *_file8 = TFile::Open("plotsrndm.root");
    TH1* xjgjetnine = (TH1*)gROOT->FindObject("m40p4");
    array[23]= xjgjetnine;
    TFile *_file0 = TFile::Open("plotsrndm.root");
    TH1* xjgjetone = (TH1*)gROOT->FindObject("m45p2");
    array[24]= xjgjetone;
    
    TFile *_file1 = TFile::Open("plotsrndm.root");
    TH1* xjgjettwo = (TH1*)gROOT->FindObject("m45p3");
    array[25]= xjgjettwo;
    
    TFile *_file2 = TFile::Open("plotsrndm.root");
    TH1* xjgjetthree = (TH1*)gROOT->FindObject("m45p4");
    array[26]= xjgjetthree;
    
    TFile *_file3 = TFile::Open("plotsrndm.root");
    TH1* xjgjetfour = (TH1*)gROOT->FindObject("m50p2");
    array[27]= xjgjetfour;
    
    TFile *_file4 = TFile::Open("plotsrndm.root");
    TH1* xjgjetfive = (TH1*)gROOT->FindObject("m50p3");
    array[28]= xjgjetfive;
    
    TFile *_file5 = TFile::Open("plotsrndm.root");
    TH1* xjgjetsix = (TH1*)gROOT->FindObject("m50p4");
    array[29]= xjgjetsix;
    
    TH1* carray[30];
    TFile *_file0 = TFile::Open("plotsrndm.root");
    TH1* cone = (TH1*)gROOT->FindObject("c5p2");
    carray[0]= cone;
    
    TFile *_file1 = TFile::Open("plotsrndm.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("c5p3");
    carray[1]= ctwo;
    
    TFile *_file2 = TFile::Open("plotsrndm.root");
    TH1* cthree = (TH1*)gROOT->FindObject("c5p4");
    carray[2]= cthree;
    
    TFile *_file3 = TFile::Open("plotsrndm.root");
    TH1* cfour = (TH1*)gROOT->FindObject("c10p2");
    carray[3]= cfour;
    
    TFile *_file4 = TFile::Open("plotsrndm.root");
    TH1* cfive = (TH1*)gROOT->FindObject("c10p3");
    carray[4]= cfive;
    
    TFile *_file5 = TFile::Open("plotsrndm.root");
    TH1* csix = (TH1*)gROOT->FindObject("c10p4");
    carray[5]= csix;
    
    TFile *_file6 = TFile::Open("plotsrndm.root");
    TH1* cseven = (TH1*)gROOT->FindObject("c15p2");
    carray[6]= cseven;
    
    TFile *_file7 = TFile::Open("plotsrndm.root");
    TH1* ceight = (TH1*)gROOT->FindObject("c15p3");
    carray[7]= ceight;
    
    TFile *_file8 = TFile::Open("plotsrndm.root");
    TH1* cnine = (TH1*)gROOT->FindObject("c15p4");
    carray[8]= cnine;
    
    TFile *_file0 = TFile::Open("plotsrndm.root");
    TH1* conea = (TH1*)gROOT->FindObject("c20p2");
    carray[9]= conea;
    
    TFile *_file1 = TFile::Open("plotsrndm.root");
    TH1* ctwoa = (TH1*)gROOT->FindObject("c20p3");
    carray[10]= ctwoa;
    
    TFile *_file2 = TFile::Open("plotsrndm.root");
    TH1* cthreea = (TH1*)gROOT->FindObject("c20p4");
    carray[11]= cthreea;
    
    TFile *_file3 = TFile::Open("plotsrndm.root");
    TH1* cfoura = (TH1*)gROOT->FindObject("c25p2");
    carray[12]= cfoura;
    
    TFile *_file4 = TFile::Open("plotsrndm.root");
    TH1* cfivea = (TH1*)gROOT->FindObject("c25p3");
    carray[13]= cfivea;
    
    TFile *_file5 = TFile::Open("plotsrndm.root");
    TH1* csixa = (TH1*)gROOT->FindObject("c25p4");
    carray[14]= csixa;
    
    TFile *_file0 = TFile::Open("plotsrndm.root");
    TH1* cone = (TH1*)gROOT->FindObject("c30p2");
    carray[15]= cone;
    
    TFile *_file1 = TFile::Open("plotsrndm.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("c30p3");
    carray[16]= ctwo;
    
    TFile *_file2 = TFile::Open("plotsrndm.root");
    TH1* cthree = (TH1*)gROOT->FindObject("c30p4");
    carray[17]= cthree;
    
    TFile *_file3 = TFile::Open("plotsrndm.root");
    TH1* cfour = (TH1*)gROOT->FindObject("c35p2");
    carray[18]= cfour;
    
    TFile *_file4 = TFile::Open("plotsrndm.root");
    TH1* cfive = (TH1*)gROOT->FindObject("c35p3");
    carray[19]= cfive;
    
    TFile *_file5 = TFile::Open("plotsrndm.root");
    TH1* csix = (TH1*)gROOT->FindObject("c35p4");
    carray[20]= csix;
    
    TFile *_file6 = TFile::Open("plotsrndm.root");
    TH1* cseven = (TH1*)gROOT->FindObject("c40p2");
    carray[21]= cseven;
    
    TFile *_file7 = TFile::Open("plotsrndm.root");
    TH1* ceight = (TH1*)gROOT->FindObject("c40p3");
    carray[22]= ceight;
    
    TFile *_file8 = TFile::Open("plotsrndm.root");
    TH1* cnine = (TH1*)gROOT->FindObject("c40p4");
    carray[23]= cnine;
    TFile *_file0 = TFile::Open("plotsrndm.root");
    TH1* cone = (TH1*)gROOT->FindObject("c45p2");
    carray[24]= cone;
    
    TFile *_file1 = TFile::Open("plotsrndm.root");
    TH1* ctwo = (TH1*)gROOT->FindObject("c45p3");
    carray[25]= ctwo;
    
    TFile *_file2 = TFile::Open("plotsrndm.root");
    TH1* cthree = (TH1*)gROOT->FindObject("c45p4");
    carray[26]= cthree;
    
    TFile *_file3 = TFile::Open("plotsrndm.root");
    TH1* cfour = (TH1*)gROOT->FindObject("c50p2");
    carray[27]= cfour;
    
    TFile *_file4 = TFile::Open("plotsrndm.root");
    TH1* cfive = (TH1*)gROOT->FindObject("c50p3");
    carray[28]= cfive;
    
    TFile *_file5 = TFile::Open("plotsrndm.root");
    TH1* csix = (TH1*)gROOT->FindObject("c50p4");
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
            leg->Draw();
        }
        else if(i==1){
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetHeader("R=0.3");
            leg2->AddEntry(array[0],"mixed event","l");
            leg2->AddEntry(carray[0],"combined tracks","l");
            leg2->Draw();
        }
        else if(i==2){
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
            leg3->Draw();
        }
        else if(i==3){
            TLegend* leg4 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg4,.05);
            leg4->SetHeader("Ptmin=10 GeV");
            leg4->Draw();
        }
        else if(i==6){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=15 GeV");
            leg5->Draw();
        }
        else if(i==9){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=20 GeV");
            leg5->Draw();
        }
        else if(i==12){
            TLegend* leg5 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg5,.05);
            leg5->SetHeader("Ptmin=25 GeV");
            leg5->Draw();
        }
        for (int j=1;j<=150;j++){
            if(array[i]->GetBinContent(j)<5)
                array[i]->SetBinContent(j,0);
        }
        scale= ((carray[i]->Integral(0,50))/(array[i]->Integral(0,50)));
        array[i]->Scale(scale);
        array[i]->SetLineColor(kRed);
        array[i]->Draw("same");
        cout<<scale<<endl;
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
            leg6->AddEntry("array[15]","combined tracks","");
            leg6->Draw();
        }
        else if(i==16){
            TLegend* leg2 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg2,.05);
            leg2->SetHeader("R=0.3");
            leg2->AddEntry(array[0],"mixed event","l");
            leg2->AddEntry(carray[0],"combined tracks","l");
            leg2->Draw();
        }
        else if(i==17){
            TLegend* leg3 = new TLegend(0.6,0.7,0.85,0.85);
            SetLeg(leg3,.05);
            leg3->SetHeader("R=0.4");
            leg3->Draw();
        }
        else if(i==18){
            TLegend* leg7 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg7,.05);
            leg7->SetHeader("Ptmin=35 GeV");
            leg7->Draw();
        }
        else if(i==21){
            TLegend* leg8 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg8,.05);
            leg8->SetHeader("Ptmin=40 GeV");
            leg8->Draw();
        }
        else if(i==24){
            TLegend* leg9 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg9,.05);
            leg9->SetHeader("Ptmin=45 GeV");
            leg9->Draw();
        }
        else if(i==27){
            TLegend* leg10 = new TLegend(0.7,0.8,0.85,0.85);
            SetLeg(leg10,.05);
            leg10->SetHeader("Ptmin=50 GeV");
            leg10->Draw();
        }
        for (int j=1;j<=150;j++){
            if(array[i]->GetBinContent(j)<5)
                array[i]->SetBinContent(j,0);
        }
        scale= ((carray[i]->Integral(0,50))/(array[i]->Integral(0,50)));
        array[i]->Scale(scale);
        array[i]->SetLineColor(kRed);
        array[i]->Draw("same");
        cout<<scale<<endl;
    }
    
    
    
    
    /*TCanvas* c2 = new TCanvas("c2","",1000,1000);
    gPad->SetLeftMargin(0.15);
    gPad->SetRightMargin(0.0);
    gPad->SetTopMargin(0.0);
    gPad->SetBottomMargin(0.0);
    c2->Divide(3,5);
    for(int i=15;i<30;i++){
        c2->cd(i-14);
        carray[i]->Draw("colz");
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
    Double_t count[3]={0.21,0.31,0.41};
    Double_t count2[3]={0.19,0.29,0.39};
    Double_t ex[3]={0,0,0};
    TGraphErrors *f = new TGraphErrors(3,count,jpt5,ex,ejpt5);
    f->GetYaxis()->SetRangeUser(0,3);
    f->GetXaxis()->SetRangeUser(.15,.42);
    f->SetMarkerStyle(23);
    f->SetMarkerSize(2);
    f->SetMarkerColor(kAzure);
    f->SetLineColor(kAzure);
    f->GetYaxis()->SetTitle("Mean XJG");
    f->GetXaxis()->SetTitle("Jet Radius");
    f->Draw("APsame");
    TGraphErrors *g = new TGraphErrors(3,count2,jpt15,ex,ejpt15);
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
    TGraphErrors *w = new TGraphErrors(3,count2,jpt35,ex,ejpt35);
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
    TGraphErrors *k = new TGraphErrors(3,count2,spt15,ex,espt15);
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
    TGraphErrors *r = new TGraphErrors(3,count2,spt35,ex,espt35);
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
    leg9->AddEntry(f,"PYTHIA","P");
    leg9->AddEntry(y,"PYTHIA-Rho","P");
    leg9->Draw();

    TCanvas *c4= new TCanvas("c4","",1000,1000);
    
    TGraph*f1 = new TGraph(3,count,ejpt5);
    f1->GetYaxis()->SetRangeUser(0,1);
    f1->GetXaxis()->SetRangeUser(.15,.42);
    f1->SetMarkerStyle(23);
    f1->SetMarkerSize(2);
    f1->SetMarkerColor(kAzure);
    f1->SetLineColor(kAzure);
    f1->GetYaxis()->SetTitle("RMS");
    f1->GetXaxis()->SetTitle("Jet Radius");
    f1->Draw("APsame");
    TGraph *g1 = new TGraph(3,count2,ejpt15);
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
    TGraph *w1 = new TGraph(3,count2,ejpt35);
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
    TGraph *k1 = new TGraph(3,count2,espt15);
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
    TGraph *r1 = new TGraph(3,count2,espt35);
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
    leg9->AddEntry(f,"PYTHIA","P");
    leg9->AddEntry(y,"PYTHIA-Rho","P");
    leg9->Draw();
*/
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

void SetLeg(TLegend* l,float txtsize=0.1){
    l->SetBorderSize(0);
    l->SetFillColor(0);
    l->SetTextSize(txtsize);
}










