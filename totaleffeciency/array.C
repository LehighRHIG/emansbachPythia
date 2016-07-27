void array(){
    set_plot_style();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    int fillcol = TColor::kCyan-6;
    int fillstyle = 1001;
    int linecolor = TColor::kCyan+3;
    int markerstyle = 1;
    float legfontsize = 0.04;
    
    TH2* gamma[60];
    TFile *_file0 = TFile::Open("5_10.root");
    TH2* gammaone = (TH2*)gROOT->FindObject("gammatot");
    gamma[0]= gammaone;
    
    TFile *_file1 = TFile::Open("10_15.root");
    TH2* gammatwo = (TH2*)gROOT->FindObject("gammatot");
    gamma[1]= gammatwo;
    
    TFile *_file2 = TFile::Open("15_20.root");
    TH2* gammathree = (TH2*)gROOT->FindObject("gammatot");
    gamma[2]= gammathree;
    
    TFile *_file3 = TFile::Open("20_25.root");
    TH2* gammafour = (TH2*)gROOT->FindObject("gammatot");
    gamma[3]= gammafour;
    
    TFile *_file4 = TFile::Open("25_30.root");
    TH2* gammafive = (TH2*)gROOT->FindObject("gammatot");
    gamma[4]= gammafive;
    
    TFile *_file5 = TFile::Open("30_35.root");
    TH2* gammasix = (TH2*)gROOT->FindObject("gammatot");
    gamma[5]= gammasix;
    
    TFile *_file6 = TFile::Open("35_40.root");
    TH2* gammaseven = (TH2*)gROOT->FindObject("gammatot");
    gamma[6]= gammaseven;
    
    TFile *_file7 = TFile::Open("40_45.root");
    TH2* gammaeight = (TH2*)gROOT->FindObject("gammatot");
    gamma[7]= gammaeight;
    
    TFile *_file8 = TFile::Open("45_50.root");
    TH2* gammanine = (TH2*)gROOT->FindObject("gammatot");
    gamma[8]= gammanine;
    
    TFile *_file9 = TFile::Open("50_55.root");
    TH2* gammaten = (TH2*)gROOT->FindObject("gammatot");
    gamma[9]= gammaten;
   
    for(int i=0;i<10;i++)
        gamma[i+10]=gamma[i];
    for(int i=0;i<10;i++)
        gamma[i+20]=gamma[i];
    for(int i=0;i<10;i++)
        gamma[i+30]=gamma[i];
    for(int i=0;i<10;i++)
        gamma[i+40]=gamma[i];
    for(int i=0;i<10;i++)
        gamma[i+50]=gamma[i];
   
    
    TH2* parton[60];
    TFile *_file0 = TFile::Open("5_10p1.root");
    TH2* partonone = (TH2*)gROOT->FindObject("partontot");
    parton[0]= partonone;
    
    TFile *_file1 = TFile::Open("10_15p1.root");
    TH2* partontwo = (TH2*)gROOT->FindObject("partontot");
    parton[1]= partontwo;
    
    TFile *_file2 = TFile::Open("15_20p1.root");
    TH2* partonthree = (TH2*)gROOT->FindObject("partontot");
    parton[2]= partonthree;
    
    TFile *_file3 = TFile::Open("20_25p1.root");
    TH2* partonfour = (TH2*)gROOT->FindObject("partontot");
    parton[3]= partonfour;
    
    TFile *_file4 = TFile::Open("25_30p1.root");
    TH2* partonfive = (TH2*)gROOT->FindObject("partontot");
    parton[4]= partonfive;
    
    TFile *_file5 = TFile::Open("30_35p1.root");
    TH2* partonsix = (TH2*)gROOT->FindObject("partontot");
    parton[5]= partonsix;
    
    TFile *_file6 = TFile::Open("35_40p1.root");
    TH2* partonseven = (TH2*)gROOT->FindObject("partontot");
    parton[6]= partonseven;
    
    TFile *_file7 = TFile::Open("40_45p1.root");
    TH2* partoneight = (TH2*)gROOT->FindObject("partontot");
    parton[7]= partoneight;
    
    TFile *_file8 = TFile::Open("45_50p1.root");
    TH2* partonnine = (TH2*)gROOT->FindObject("partontot");
    parton[8]= partonnine;
    
    TFile *_file9 = TFile::Open("50_55p1.root");
    TH2* partonten = (TH2*)gROOT->FindObject("partontot");
    parton[9]= partonten;
    
    TFile *_file10 = TFile::Open("5_10p2.root");
    TH2* partonone1 = (TH2*)gROOT->FindObject("partontot");
    parton[10]= partonone1;
    
    TFile *_file11 = TFile::Open("10_15p2.root");
    TH2* partontwo1 = (TH2*)gROOT->FindObject("partontot");
    parton[11]= partontwo1;
    
    TFile *_file12 = TFile::Open("15_20p2.root");
    TH2* partonthree1 = (TH2*)gROOT->FindObject("partontot");
    parton[12]= partonthree1;
    
    TFile *_file13 = TFile::Open("20_25p2.root");
    TH2* partonfour1 = (TH2*)gROOT->FindObject("partontot");
    parton[13]= partonfour1;
    
    TFile *_file14 = TFile::Open("25_30p2.root");
    TH2* partonfive1 = (TH2*)gROOT->FindObject("partontot");
    parton[14]= partonfive1;
    
    TFile *_file15 = TFile::Open("30_35p2.root");
    TH2* partonsix1 = (TH2*)gROOT->FindObject("partontot");
    parton[15]= partonsix1;
    
    TFile *_file16 = TFile::Open("35_40p2.root");
    TH2* partonseven1 = (TH2*)gROOT->FindObject("partontot");
    parton[16]= partonseven1;
    
    TFile *_file17 = TFile::Open("40_45p2.root");
    TH2* partoneight1 = (TH2*)gROOT->FindObject("partontot");
    parton[17]= partoneight1;
    
    TFile *_file18 = TFile::Open("45_50p2.root");
    TH2* partonnine1 = (TH2*)gROOT->FindObject("partontot");
    parton[18]= partonnine1;
    
    TFile *_file19 = TFile::Open("50_55p2.root");
    TH2* partonten1 = (TH2*)gROOT->FindObject("partontot");
    parton[19]= partonten1;
    
    TFile *_file20 = TFile::Open("5_10p3.root");
    TH2* partonone2 = (TH2*)gROOT->FindObject("partontot");
    parton[20]= partonone2;
    
    TFile *_file21 = TFile::Open("10_15p3.root");
    TH2* partontwo2 = (TH2*)gROOT->FindObject("partontot");
    parton[21]= partontwo2;
    
    TFile *_file22 = TFile::Open("15_20p3.root");
    TH2* partonthree2 = (TH2*)gROOT->FindObject("partontot");
    parton[22]= partonthree2;
    
    TFile *_file23 = TFile::Open("20_25p3.root");
    TH2* partonfour2 = (TH2*)gROOT->FindObject("partontot");
    parton[23]= partonfour2;
    
    TFile *_file24 = TFile::Open("25_30p3.root");
    TH2* partonfive2 = (TH2*)gROOT->FindObject("partontot");
    parton[24]= partonfive2;
    
    TFile *_file25 = TFile::Open("30_35p3.root");
    TH2* partonsix2 = (TH2*)gROOT->FindObject("partontot");
    parton[25]= partonsix2;
    
    TFile *_file26 = TFile::Open("35_40p3.root");
    TH2* partonseven2 = (TH2*)gROOT->FindObject("partontot");
    parton[26]= partonseven2;
    
    TFile *_file27 = TFile::Open("40_45p3.root");
    TH2* partoneight2 = (TH2*)gROOT->FindObject("partontot");
    parton[27]= partoneight2;
    
    TFile *_file28 = TFile::Open("45_50p3.root");
    TH2* partonnine2 = (TH2*)gROOT->FindObject("partontot");
    parton[28]= partonnine2;
    
    TFile *_file29 = TFile::Open("50_55p3.root");
    TH2* partonten2 = (TH2*)gROOT->FindObject("partontot");
    parton[29]= partonten2;
    
    TFile *_file30 = TFile::Open("5_10p4.root");
    TH2* partonone3 = (TH2*)gROOT->FindObject("partontot");
    parton[30]= partonone3;
    
    TFile *_file31 = TFile::Open("10_15p4.root");
    TH2* partontwo3 = (TH2*)gROOT->FindObject("partontot");
    parton[31]= partontwo3;
    
    TFile *_file32 = TFile::Open("15_20p4.root");
    TH2* partonthree3 = (TH2*)gROOT->FindObject("partontot");
    parton[32]= partonthree3;
    
    TFile *_file33 = TFile::Open("20_25p4.root");
    TH2* partonfour3 = (TH2*)gROOT->FindObject("partontot");
    parton[33]= partonfour3;
    
    TFile *_file34 = TFile::Open("25_30p4.root");
    TH2* partonfive3 = (TH2*)gROOT->FindObject("partontot");
    parton[34]= partonfive3;
    
    TFile *_file35 = TFile::Open("30_35p4.root");
    TH2* partonsix3 = (TH2*)gROOT->FindObject("partontot");
    parton[35]= partonsix3;
    
    TFile *_file36 = TFile::Open("35_40p4.root");
    TH2* partonseven3 = (TH2*)gROOT->FindObject("partontot");
    parton[36]= partonseven3;
    
    TFile *_file37 = TFile::Open("40_45p4.root");
    TH2* partoneight3 = (TH2*)gROOT->FindObject("partontot");
    parton[37]= partoneight3;
    
    TFile *_file38 = TFile::Open("45_50p4.root");
    TH2* partonnine3 = (TH2*)gROOT->FindObject("partontot");
    parton[38]= partonnine3;
    
    TFile *_file39 = TFile::Open("50_55p4.root");
    TH2* partonten3 = (TH2*)gROOT->FindObject("partontot");
    parton[39]= partonten3;
    
    TFile *_file40 = TFile::Open("5_10p5.root");
    TH2* partonone4 = (TH2*)gROOT->FindObject("partontot");
    parton[40]= partonone4;
    
    TFile *_file41 = TFile::Open("10_15p5.root");
    TH2* partontwo4 = (TH2*)gROOT->FindObject("partontot");
    parton[41]= partontwo4;
    
    TFile *_file42 = TFile::Open("15_20p5.root");
    TH2* partonthree4 = (TH2*)gROOT->FindObject("partontot");
    parton[42]= partonthree4;
    
    TFile *_file43 = TFile::Open("20_25p5.root");
    TH2* partonfour4 = (TH2*)gROOT->FindObject("partontot");
    parton[43]= partonfour4;
    
    TFile *_file44 = TFile::Open("25_30p5.root");
    TH2* partonfive4 = (TH2*)gROOT->FindObject("partontot");
    parton[44]= partonfive4;
    
    TFile *_file45 = TFile::Open("30_35p5.root");
    TH2* partonsix4 = (TH2*)gROOT->FindObject("partontot");
    parton[45]= partonsix4;
    
    TFile *_file46 = TFile::Open("35_40p5.root");
    TH2* partonseven4 = (TH2*)gROOT->FindObject("partontot");
    parton[46]= partonseven4;
    
    TFile *_file47 = TFile::Open("40_45p5.root");
    TH2* partoneight4 = (TH2*)gROOT->FindObject("partontot");
    parton[47]= partoneight4;
    
    TFile *_file48 = TFile::Open("45_50p5.root");
    TH2* partonnine4 = (TH2*)gROOT->FindObject("partontot");
    parton[48]= partonnine4;
    
    TFile *_file49 = TFile::Open("50_55p5.root");
    TH2* partonten4 = (TH2*)gROOT->FindObject("partontot");
    parton[49]= partonten4;
    
    TFile *_file50 = TFile::Open("5_10p7.root");
    TH2* partonone5 = (TH2*)gROOT->FindObject("partontot");
    parton[50]= partonone5;
    
    TFile *_file51 = TFile::Open("10_15p7.root");
    TH2* partontwo5 = (TH2*)gROOT->FindObject("partontot");
    parton[51]= partontwo5;
    
    TFile *_file52 = TFile::Open("15_20p7.root");
    TH2* partonthree5 = (TH2*)gROOT->FindObject("partontot");
    parton[52]= partonthree5;
    
    TFile *_file53 = TFile::Open("20_25p7.root");
    TH2* partonfour5 = (TH2*)gROOT->FindObject("partontot");
    parton[53]= partonfour5;
    
    TFile *_file54 = TFile::Open("25_30p7.root");
    TH2* partonfive5 = (TH2*)gROOT->FindObject("partontot");
    parton[54]= partonfive5;
    
    TFile *_file55 = TFile::Open("30_35p7.root");
    TH2* partonsix5 = (TH2*)gROOT->FindObject("partontot");
    parton[55]= partonsix5;
    
    TFile *_file56 = TFile::Open("35_40p7.root");
    TH2* partonseven5 = (TH2*)gROOT->FindObject("partontot");
    parton[56]= partonseven5;
    
    TFile *_file57 = TFile::Open("40_45p7.root");
    TH2* partoneight5 = (TH2*)gROOT->FindObject("partontot");
    parton[57]= partoneight5;
    
    TFile *_file58 = TFile::Open("45_50p7.root");
    TH2* partonnine5 = (TH2*)gROOT->FindObject("partontot");
    parton[58]= partonnine5;
    
    TFile *_file59 = TFile::Open("50_55p7.root");
    TH2* partonten5 = (TH2*)gROOT->FindObject("partontot");
    parton[59]= partonten5;
    
    
    
    TH2* jet[60];
    TFile *_file0 = TFile::Open("5_10p1.root");
    TH2* jetone = (TH2*)gROOT->FindObject("jettot");
    jet[0]= jetone;
    
    TFile *_file1 = TFile::Open("10_15p1.root");
    TH2* jettwo = (TH2*)gROOT->FindObject("jettot");
    jet[1]= jettwo;
    
    TFile *_file2 = TFile::Open("15_20p1.root");
    TH2* jetthree = (TH2*)gROOT->FindObject("jettot");
    jet[2]= jetthree;
    
    TFile *_file3 = TFile::Open("20_25p1.root");
    TH2* jetfour = (TH2*)gROOT->FindObject("jettot");
    jet[3]= jetfour;
    
    TFile *_file4 = TFile::Open("25_30p1.root");
    TH2* jetfive = (TH2*)gROOT->FindObject("jettot");
    jet[4]= jetfive;
    
    TFile *_file5 = TFile::Open("30_35p1.root");
    TH2* jetsix = (TH2*)gROOT->FindObject("jettot");
    jet[5]= jetsix;
    
    TFile *_file6 = TFile::Open("35_40p1.root");
    TH2* jetseven = (TH2*)gROOT->FindObject("jettot");
    jet[6]= jetseven;
    
    TFile *_file7 = TFile::Open("40_45p1.root");
    TH2* jeteight = (TH2*)gROOT->FindObject("jettot");
    jet[7]= jeteight;
    
    TFile *_file8 = TFile::Open("45_50p1.root");
    TH2* jetnine = (TH2*)gROOT->FindObject("jettot");
    jet[8]= jetnine;
    
    TFile *_file9 = TFile::Open("50_55p1.root");
    TH2* jetten = (TH2*)gROOT->FindObject("jettot");
    jet[9]= jetten;
    
    TFile *_file10 = TFile::Open("5_10p2.root");
    TH2* jetone1 = (TH2*)gROOT->FindObject("jettot");
    jet[10]= jetone1;
    
    TFile *_file11 = TFile::Open("10_15p2.root");
    TH2* jettwo1 = (TH2*)gROOT->FindObject("jettot");
    jet[11]= jettwo1;
    
    TFile *_file12 = TFile::Open("15_20p2.root");
    TH2* jetthree1 = (TH2*)gROOT->FindObject("jettot");
    jet[12]= jetthree1;
    
    TFile *_file13 = TFile::Open("20_25p2.root");
    TH2* jetfour1 = (TH2*)gROOT->FindObject("jettot");
    jet[13]= jetfour1;
    
    TFile *_file14 = TFile::Open("25_30p2.root");
    TH2* jetfive1 = (TH2*)gROOT->FindObject("jettot");
    jet[14]= jetfive1;
    
    TFile *_file15 = TFile::Open("30_35p2.root");
    TH2* jetsix1 = (TH2*)gROOT->FindObject("jettot");
    jet[15]= jetsix1;
    
    TFile *_file16 = TFile::Open("35_40p2.root");
    TH2* jetseven1 = (TH2*)gROOT->FindObject("jettot");
    jet[16]= jetseven1;
    
    TFile *_file17 = TFile::Open("40_45p2.root");
    TH2* jeteight1 = (TH2*)gROOT->FindObject("jettot");
    jet[17]= jeteight1;
    
    TFile *_file18 = TFile::Open("45_50p2.root");
    TH2* jetnine1 = (TH2*)gROOT->FindObject("jettot");
    jet[18]= jetnine1;
    
    TFile *_file19 = TFile::Open("50_55p2.root");
    TH2* jetten1 = (TH2*)gROOT->FindObject("jettot");
    jet[19]= jetten1;
    
    TFile *_file20 = TFile::Open("5_10p3.root");
    TH2* jetone2 = (TH2*)gROOT->FindObject("jettot");
    jet[20]= jetone2;
    
    TFile *_file21 = TFile::Open("10_15p3.root");
    TH2* jettwo2 = (TH2*)gROOT->FindObject("jettot");
    jet[21]= jettwo2;
    
    TFile *_file22 = TFile::Open("15_20p3.root");
    TH2* jetthree2 = (TH2*)gROOT->FindObject("jettot");
    jet[22]= jetthree2;
    
    TFile *_file23 = TFile::Open("20_25p3.root");
    TH2* jetfour2 = (TH2*)gROOT->FindObject("jettot");
    jet[23]= jetfour2;
    
    TFile *_file24 = TFile::Open("25_30p3.root");
    TH2* jetfive2 = (TH2*)gROOT->FindObject("jettot");
    jet[24]= jetfive2;
    
    TFile *_file25 = TFile::Open("30_35p3.root");
    TH2* jetsix2 = (TH2*)gROOT->FindObject("jettot");
    jet[25]= jetsix2;
    
    TFile *_file26 = TFile::Open("35_40p3.root");
    TH2* jetseven2 = (TH2*)gROOT->FindObject("jettot");
    jet[26]= jetseven2;
    
    TFile *_file27 = TFile::Open("40_45p3.root");
    TH2* jeteight2 = (TH2*)gROOT->FindObject("jettot");
    jet[27]= jeteight2;
    
    TFile *_file28 = TFile::Open("45_50p3.root");
    TH2* jetnine2 = (TH2*)gROOT->FindObject("jettot");
    jet[28]= jetnine2;
    
    TFile *_file29 = TFile::Open("50_55p3.root");
    TH2* jetten2 = (TH2*)gROOT->FindObject("jettot");
    jet[29]= jetten2;
    
    TFile *_file30 = TFile::Open("5_10p4.root");
    TH2* jetone3 = (TH2*)gROOT->FindObject("jettot");
    jet[30]= jetone3;
    
    TFile *_file31 = TFile::Open("10_15p4.root");
    TH2* jettwo3 = (TH2*)gROOT->FindObject("jettot");
    jet[31]= jettwo3;
    
    TFile *_file32 = TFile::Open("15_20p4.root");
    TH2* jetthree3 = (TH2*)gROOT->FindObject("jettot");
    jet[32]= jetthree3;
    
    TFile *_file33 = TFile::Open("20_25p4.root");
    TH2* jetfour3 = (TH2*)gROOT->FindObject("jettot");
    jet[33]= jetfour3;
    
    TFile *_file34 = TFile::Open("25_30p4.root");
    TH2* jetfive3 = (TH2*)gROOT->FindObject("jettot");
    jet[34]= jetfive3;
    
    TFile *_file35 = TFile::Open("30_35p4.root");
    TH2* jetsix3 = (TH2*)gROOT->FindObject("jettot");
    jet[35]= jetsix3;
    
    TFile *_file36 = TFile::Open("35_40p4.root");
    TH2* jetseven3 = (TH2*)gROOT->FindObject("jettot");
    jet[36]= jetseven3;
    
    TFile *_file37 = TFile::Open("40_45p4.root");
    TH2* jeteight3 = (TH2*)gROOT->FindObject("jettot");
    jet[37]= jeteight3;
    
    TFile *_file38 = TFile::Open("45_50p4.root");
    TH2* jetnine3 = (TH2*)gROOT->FindObject("jettot");
    jet[38]= jetnine3;
    
    TFile *_file39 = TFile::Open("50_55p4.root");
    TH2* jetten3 = (TH2*)gROOT->FindObject("jettot");
    jet[39]= jetten3;
    
    TFile *_file40 = TFile::Open("5_10p5.root");
    TH2* jetone4 = (TH2*)gROOT->FindObject("jettot");
    jet[40]= jetone4;
    
    TFile *_file41 = TFile::Open("10_15p5.root");
    TH2* jettwo4 = (TH2*)gROOT->FindObject("jettot");
    jet[41]= jettwo4;
    
    TFile *_file42 = TFile::Open("15_20p5.root");
    TH2* jetthree4 = (TH2*)gROOT->FindObject("jettot");
    jet[42]= jetthree4;
    
    TFile *_file43 = TFile::Open("20_25p5.root");
    TH2* jetfour4 = (TH2*)gROOT->FindObject("jettot");
    jet[43]= jetfour4;
    
    TFile *_file44 = TFile::Open("25_30p5.root");
    TH2* jetfive4 = (TH2*)gROOT->FindObject("jettot");
    jet[44]= jetfive4;
    
    TFile *_file45 = TFile::Open("30_35p5.root");
    TH2* jetsix4 = (TH2*)gROOT->FindObject("jettot");
    jet[45]= jetsix4;
    
    TFile *_file46 = TFile::Open("35_40p5.root");
    TH2* jetseven4 = (TH2*)gROOT->FindObject("jettot");
    jet[46]= jetseven4;
    
    TFile *_file47 = TFile::Open("40_45p5.root");
    TH2* jeteight4 = (TH2*)gROOT->FindObject("jettot");
    jet[47]= jeteight4;
    
    TFile *_file48 = TFile::Open("45_50p5.root");
    TH2* jetnine4 = (TH2*)gROOT->FindObject("jettot");
    jet[48]= jetnine4;
    
    TFile *_file49 = TFile::Open("50_55p5.root");
    TH2* jetten4 = (TH2*)gROOT->FindObject("jettot");
    jet[49]= jetten4;
    
    TFile *_file50 = TFile::Open("5_10p7.root");
    TH2* jetone5 = (TH2*)gROOT->FindObject("jettot");
    jet[50]= jetone5;
    
    TFile *_file51 = TFile::Open("10_15p7.root");
    TH2* jettwo5 = (TH2*)gROOT->FindObject("jettot");
    jet[51]= jettwo5;
    
    TFile *_file52 = TFile::Open("15_20p7.root");
    TH2* jetthree5 = (TH2*)gROOT->FindObject("jettot");
    jet[52]= jetthree5;
    
    TFile *_file53 = TFile::Open("20_25p7.root");
    TH2* jetfour5 = (TH2*)gROOT->FindObject("jettot");
    jet[53]= jetfour5;
    
    TFile *_file54 = TFile::Open("25_30p7.root");
    TH2* jetfive5 = (TH2*)gROOT->FindObject("jettot");
    jet[54]= jetfive5;
    
    TFile *_file55 = TFile::Open("30_35p7.root");
    TH2* jetsix5 = (TH2*)gROOT->FindObject("jettot");
    jet[55]= jetsix5;
    
    TFile *_file56 = TFile::Open("35_40p7.root");
    TH2* jetseven5 = (TH2*)gROOT->FindObject("jettot");
    jet[56]= jetseven5;
    
    TFile *_file57 = TFile::Open("40_45p7.root");
    TH2* jeteight5 = (TH2*)gROOT->FindObject("jettot");
    jet[57]= jeteight5;
    
    TFile *_file58 = TFile::Open("45_50p7.root");
    TH2* jetnine5 = (TH2*)gROOT->FindObject("jettot");
    jet[58]= jetnine5;
    
    TFile *_file59 = TFile::Open("50_55p7.root");
    TH2* jetten5 = (TH2*)gROOT->FindObject("jettot");
    jet[59]= jetten5;

    
    TH1* num1 = new TH1F("num1","num1",10,5,55);
    TH1* den1 = new TH1F("den1","den1",10,5,55);
    
    TH1* num2 = new TH1F("num2","num2",10,5,55);
    TH1* den2 = new TH1F("den2","den2",10,5,55);
    
    TH1* num3 = new TH1F("num3","num3",10,5,55);
    TH1* den3 = new TH1F("den3","den3",10,5,55);
    
    TH1* num4 = new TH1F("num4","num4",10,5,55);
    TH1* den4 = new TH1F("den4","den4",10,5,55);
    
    TH1* num5 = new TH1F("num5","num5",10,5,55);
    TH1* den5 = new TH1F("den5","den5",10,5,55);
    
    TH1* num7 = new TH1F("num7","num7",10,5,55);
    TH1* den7 = new TH1F("den7","den7",10,5,55);
    
    for (int i = 0;i<10;i++){
        num1->SetBinContent(i+1,jet[i]->Integral(12,29));
        cout<<jet[i]->Integral(12,29)<<endl;
        den1->SetBinContent(i+1,gamma[i]->Integral(0,40));
    }
    for (int i = 10;i<20;i++){
        num2->SetBinContent(i-9,jet[i]->Integral(13,28));
        den2->SetBinContent(i-9,gamma[i]->Integral(0,40));
    }
    for (int i = 20;i<30;i++){
        num3->SetBinContent(i-19,jet[i]->Integral(14,27));
        den3->SetBinContent(i-19,gamma[i]->Integral(0,40));
    }
    for (int i = 30;i<40;i++){
        num4->SetBinContent(i-29,jet[i]->Integral(15,26));
        den4->SetBinContent(i-29,gamma[i]->Integral(0,40));
    }
    for (int i = 40;i<50;i++){
        num5->SetBinContent(i-39,jet[i]->Integral(16,25));
        den5->SetBinContent(i-39,gamma[i]->Integral(0,40));
    }
    for (int i = 50;i<60;i++){
        num7->SetBinContent(i-49,jet[i]->Integral(18,23));
        cout<<jet[i]->Integral(18,23)<<endl;
        den7->SetBinContent(i-49,gamma[i]->Integral(0,40));
    }
    
    TCanvas* c1 = new TCanvas("c1","",1000,1000);
    c1->Divide(3,2);
    
    c1->cd(1);
    TH1* hDummy = new TH1F("hDummy","",11,0,55);  //dummy histo for axis etc
    hDummy->SetMinimum(0);
    hDummy->SetMaximum(1);
    gPad->SetLeftMargin(0.13);
    gPad->SetTickx();
    gPad->SetTicky();
    TEfficiency* pEff = new TEfficiency(*num1,*den1);
    hDummy->GetYaxis()->SetTitle("Total Efficiency");
    hDummy->GetYaxis()->SetTitleSize(.05);
    hDummy->GetXaxis()->SetTitleSize(.05);
    hDummy->GetXaxis()->SetTitle("Photon Pt (GeV/c)");
    //SetHist(hDummy,"Photon Pt (GeV/c)","Total Efficiency");
    SetHist(pEff,linecolor,markerstyle);
    
    pEff->SetFillColor(fillcol);
    pEff->SetFillStyle(fillstyle);
    
    hDummy->Draw("P");
    //pEff->Draw("E3Same");
    pEff->Draw("L0Same");
    
    TLegend* leg1 = new TLegend(0.2,0.65,0.6,0.85);
    SetLeg(leg1,legfontsize);
    //leg1->AddEntry(hDummy,"Parton Probabilty","");
    leg1->AddEntry(hDummy,"R=0.1","");
    leg1->SetTextSize(.1);
    leg1->Draw();
    
    c1->cd(2);
    TH1* hDummy2 = new TH1F("hDummy2","",11,0,55);  //dummy histo for axis etc
    hDummy2->SetMinimum(0);
    hDummy2->SetMaximum(1);
    gPad->SetLeftMargin(0.13);
    gPad->SetTickx();
    gPad->SetTicky();
    TEfficiency* pEff2 = new TEfficiency(*num2,*den2);
    hDummy2->GetYaxis()->SetTitle("Total Efficiency");
    hDummy2->GetXaxis()->SetTitle("Photon Pt (GeV/c)");
    hDummy2->GetYaxis()->SetTitleSize(.05);
    hDummy2->GetXaxis()->SetTitleSize(.05);
    //SetHist(hDummy2,"Photon Pt (GeV/c)","Total Efficiency");
    SetHist(pEff2,linecolor,markerstyle);
    
    pEff2->SetFillColor(fillcol);
    pEff2->SetFillStyle(fillstyle);
    
    hDummy2->Draw("P");
    //pEff2->Draw("E3Same");
    pEff2->Draw("L0Same");
    
    TLegend* leg2 = new TLegend(0.2,0.65,0.6,0.85);
    SetLeg(leg2,legfontsize);
    //leg2->AddEntry(hDummy,"Parton Probabilty","");
    leg2->AddEntry(hDummy,"R=0.2","");
    leg2->SetTextSize(.1);
    leg2->Draw();
    
    c1->cd(3);
    TH1* hDummy3 = new TH1F("hDummy3","",11,0,55);  //dummy histo for axis etc
    hDummy3->SetMinimum(0);
    hDummy3->SetMaximum(1);
    gPad->SetLeftMargin(0.13);
    gPad->SetTickx();
    gPad->SetTicky();
    TEfficiency* pEff3 = new TEfficiency(*num3,*den3);
    hDummy3->GetYaxis()->SetTitle("Total Efficiency");
    hDummy3->GetXaxis()->SetTitle("Photon Pt (GeV/c)");
    hDummy3->GetYaxis()->SetTitleSize(.05);
    hDummy3->GetXaxis()->SetTitleSize(.05);
    //SetHist(hDummy3,"Photon Pt (GeV/c)","Total Efficiency");
    SetHist(pEff3,linecolor,markerstyle);
    
    pEff3->SetFillColor(fillcol);
    pEff3->SetFillStyle(fillstyle);
    
    hDummy3->Draw("P");
    //pEff3->Draw("E3Same");
    pEff3->Draw("L0Same");
    
    TLegend* leg3 = new TLegend(0.2,0.65,0.6,0.85);
    SetLeg(leg3,legfontsize);
    //leg3->AddEntry(hDummy,"Parton Probabilty","");
    leg3->AddEntry(hDummy,"R=0.3","");
    leg3->SetTextSize(.1);
    leg3->Draw();
    
    c1->cd(4);
    TH1* hDummy4 = new TH1F("hDummy4","",11,0,55);  //dummy histo for axis etc
    hDummy4->SetMinimum(0);
    hDummy4->SetMaximum(1);
    gPad->SetLeftMargin(0.13);
    gPad->SetTickx();
    gPad->SetTicky();
    TEfficiency* pEff4 = new TEfficiency(*num4,*den4);
    hDummy4->GetYaxis()->SetTitle("Total Efficiency");
    hDummy4->GetXaxis()->SetTitle("Photon Pt (GeV/c)");
    hDummy4->GetYaxis()->SetTitleSize(.05);
    hDummy4->GetXaxis()->SetTitleSize(.05);
   // SetHist(hDummy4,"Photon Pt (GeV/c)","Total Efficiency");
    SetHist(pEff4,linecolor,markerstyle);
    
    pEff4->SetFillColor(fillcol);
    pEff4->SetFillStyle(fillstyle);
    
    hDummy4->Draw("P");
    //pEff4->Draw("E3Same");
    pEff4->Draw("L0Same");
    
    TLegend* leg4 = new TLegend(0.2,0.65,0.6,0.85);
    SetLeg(leg4,legfontsize);
    //leg4->AddEntry(hDummy,"Parton Probabilty","");
    leg4->AddEntry(hDummy,"R=0.4","");
    leg4->SetTextSize(.1);
    leg4->Draw();
    
    c1->cd(5);
    TH1* hDummy5 = new TH1F("hDummy5","",11,0,55);  //dummy histo for axis etc
    hDummy5->SetMinimum(0);
    hDummy5->SetMaximum(1);
    gPad->SetLeftMargin(0.13);
    gPad->SetTickx();
    gPad->SetTicky();
    TEfficiency* pEff5 = new TEfficiency(*num5,*den5);
    hDummy5->GetYaxis()->SetTitle("Total Efficiency");
    hDummy5->GetXaxis()->SetTitle("Photon Pt (GeV/c)");
    hDummy5->GetYaxis()->SetTitleSize(.05);
    hDummy5->GetXaxis()->SetTitleSize(.05);
    //SetHist(hDummy5,"Photon Pt (GeV/c)","Total Efficiency");
    SetHist(pEff5,linecolor,markerstyle);
    
    pEff5->SetFillColor(fillcol);
    pEff5->SetFillStyle(fillstyle);
    
    hDummy5->Draw("P");
    //pEff5->Draw("E3Same");
    pEff5->Draw("L0Same");
    
    TLegend* leg5 = new TLegend(0.2,0.65,0.6,0.85);
    SetLeg(leg5,legfontsize);
    //leg5->AddEntry(hDummy,"Parton Probabilty","");
    leg5->AddEntry(hDummy,"R=0.5","");
    leg5->SetTextSize(.1);
    leg5->Draw();
    
    c1->cd(6);
    TH1* hDummy7 = new TH1F("hDummy7","",11,0,55);  //dummy histo for axis etc
    hDummy7->SetMinimum(0);
    hDummy7->SetMaximum(1);
    gPad->SetLeftMargin(0.13);
    gPad->SetTickx();
    gPad->SetTicky();
    TEfficiency* pEff7 = new TEfficiency(*num7,*den7);
    hDummy7->GetYaxis()->SetTitle("Total Efficiency");
    hDummy7->GetXaxis()->SetTitle("Photon Pt (GeV/c)");
    hDummy7->GetYaxis()->SetTitleSize(.05);
    hDummy7->GetXaxis()->SetTitleSize(.05);
    //SetHist(hDummy7,"Photon Pt (GeV/c)","Efficiency");
    SetHist(pEff7,linecolor,markerstyle);
    
    pEff7->SetFillColor(fillcol);
    pEff7->SetFillStyle(fillstyle);
    
    hDummy7->Draw("P");
    //pEff7->Draw("E3Same");
    pEff7->Draw("LOSame");
    
    TLegend* leg7 = new TLegend(0.2,0.65,0.6,0.85);
    SetLeg(leg7,legfontsize);
    //leg7->AddEntry(hDummy,"Parton Probabilty","");
    leg7->AddEntry(hDummy,"R=0.7","");
    leg7->SetTextSize(.1);
    leg7->Draw();
    
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
void SetHist(TEfficiency* h, char* xt ="", char* yt ="",int color = 1, int marker = 20,int width = 3, float size = 1.0)
{
    h->SetLineWidth(width);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(size);
    h->SetMarkerStyle(marker);
    h->GetYaxis()->SetTitle(yt);
    h->GetYaxis()->SetTitleOffset(1.6);
    h->GetXaxis()->SetTitleOffset(1.2);
    h->GetXaxis()->SetTitle(xt);
}

void SetHist(TEfficiency* h, int color = 1, int marker = 20,int width = 3, float size = 1.0)
{
    h->SetLineWidth(width);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(size);
    h->SetMarkerStyle(marker);
}
void SetHist(TEfficiency* h, int color = 1)
{
    h->SetLineWidth(3);
    h->SetLineColor(color);
    h->SetMarkerColor(color);
    h->SetMarkerSize(1);
}

void SetLeg(TLegend* l,float txtsize=0.03){
    l->SetBorderSize(0);
    l->SetFillColor(0);
    l->SetTextSize(txtsize);
}
