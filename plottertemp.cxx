{ 

double lumi = .286137;  //   1/pb

THStack *hs_lxy = new THStack("hs_lxy", "");
THStack *hs_lxyLoose = new THStack("hs_lxyLoose", "");
THStack *hs_lxy_err = new THStack("hs_lxy_err", "");
THStack *hs_lxy_errLoose = new THStack("hs_lxy_errLoose", "");
THStack *hs_InvMass = new THStack("hs_InvMass", "");
THStack *hs_InvMassLoose = new THStack("hs_InvMassLoose", "");
THStack *hs_InvMassLW = new THStack("hs_InvMassLW", "");
THStack *hs_d0_err = new THStack("hs_d0_err", "");
THStack *hs_d0_errLoose = new THStack("hs_d0_errLoose", "");
THStack *hs_dxy_err = new THStack("hs_dxy_err", "");
THStack *hs_dxy_errLoose = new THStack("hs_dxy_errLoose", "");
THStack *hs_cos = new THStack("hs_cos", "");
THStack *hs_cosLoose = new THStack("hs_cosLoose", "");
THStack *hs_delPhi = new THStack("hs_delPhi", "");
THStack *hs_delPhiLoose = new THStack("hs_delPhiLoose", "");
THStack *hs_conePt = new THStack("hs_conePt", "");
THStack *hs_chi2_NDF = new THStack("hs_chi2_NDF", "");
THStack *hs_chi2_NDF = new THStack("hs_chi2_NDF", "");
THStack *hs_chi2_NDFLoose = new THStack("hs_chi2_NDFLoose", "");
THStack *hs_numHitsLoose = new THStack("hs_numHitsLoose", "");
THStack *hs_h_dot = new THStack("hs_h_dot", "");
 
 

TFile *fZZ = new TFile("ZZM.root");
TFile *fWZ = new TFile("WZM.root");
TFile *fWW = new TFile("WWM.root");
TFile *fDY = new TFile("DYM.root");
TFile *fll = new TFile("llM.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_lxy= (TH1F*)fZZ->Get("lxy");
TH1F * hWZ_lxy= (TH1F*)fWZ->Get("lxy");
TH1F * hWW_lxy= (TH1F*)fWW->Get("lxy");
TH1F * hDY_lxy= (TH1F*)fDY->Get("lxy");
TH1F * hll_lxy= (TH1F*)fll->Get("lxy");
TH1F * hDat_lxy= (TH1F*)fDat->Get("lxy");


TH1F * hZZ_lxyLoose= (TH1F*)fZZ->Get("lxyLoose");
TH1F * hWZ_lxyLoose= (TH1F*)fWZ->Get("lxyLoose");
TH1F * hWW_lxyLoose= (TH1F*)fWW->Get("lxyLoose");
TH1F * hDY_lxyLoose= (TH1F*)fDY->Get("lxyLoose");
TH1F * hll_lxyLoose= (TH1F*)fll->Get("lxyLoose");
TH1F * hDat_lxyLoose= (TH1F*)fDat->Get("lxyLoose");


TH1F * hZZ_lxy_err= (TH1F*)fZZ->Get("lxy_err");
TH1F * hWZ_lxy_err= (TH1F*)fWZ->Get("lxy_err");
TH1F * hWW_lxy_err= (TH1F*)fWW->Get("lxy_err");
TH1F * hDY_lxy_err= (TH1F*)fDY->Get("lxy_err");
TH1F * hll_lxy_err= (TH1F*)fll->Get("lxy_err");
TH1F * hDat_lxy_err= (TH1F*)fDat->Get("lxy_err");


TH1F * hZZ_lxy_errLoose= (TH1F*)fZZ->Get("lxy_errLoose");
TH1F * hWZ_lxy_errLoose= (TH1F*)fWZ->Get("lxy_errLoose");
TH1F * hWW_lxy_errLoose= (TH1F*)fWW->Get("lxy_errLoose");
TH1F * hDY_lxy_errLoose= (TH1F*)fDY->Get("lxy_errLoose");
TH1F * hll_lxy_errLoose= (TH1F*)fll->Get("lxy_errLoose");
TH1F * hDat_lxy_errLoose= (TH1F*)fDat->Get("lxy_errLoose");


TH1F * hZZ_InvMass= (TH1F*)fZZ->Get("InvMass");
TH1F * hWZ_InvMass= (TH1F*)fWZ->Get("InvMass");
TH1F * hWW_InvMass= (TH1F*)fWW->Get("InvMass");
TH1F * hDY_InvMass= (TH1F*)fDY->Get("InvMass");
TH1F * hll_InvMass= (TH1F*)fll->Get("InvMass");
TH1F * hDat_InvMass= (TH1F*)fDat->Get("InvMass");


TH1F * hZZ_InvMassLoose= (TH1F*)fZZ->Get("InvMassLoose");
TH1F * hWZ_InvMassLoose= (TH1F*)fWZ->Get("InvMassLoose");
TH1F * hWW_InvMassLoose= (TH1F*)fWW->Get("InvMassLoose");
TH1F * hDY_InvMassLoose= (TH1F*)fDY->Get("InvMassLoose");
TH1F * hll_InvMassLoose= (TH1F*)fll->Get("InvMassLoose");
TH1F * hDat_InvMassLoose= (TH1F*)fDat->Get("InvMassLoose");


TH1F * hZZ_InvMassLW= (TH1F*)fZZ->Get("InvMassLW");
TH1F * hWZ_InvMassLW= (TH1F*)fWZ->Get("InvMassLW");
TH1F * hWW_InvMassLW= (TH1F*)fWW->Get("InvMassLW");
TH1F * hDY_InvMassLW= (TH1F*)fDY->Get("InvMassLW");
TH1F * hll_InvMassLW= (TH1F*)fll->Get("InvMassLW");
TH1F * hDat_InvMassLW= (TH1F*)fDat->Get("InvMassLW");


TH1F * hZZ_d0_err= (TH1F*)fZZ->Get("d0_err");
TH1F * hWZ_d0_err= (TH1F*)fWZ->Get("d0_err");
TH1F * hWW_d0_err= (TH1F*)fWW->Get("d0_err");
TH1F * hDY_d0_err= (TH1F*)fDY->Get("d0_err");
TH1F * hll_d0_err= (TH1F*)fll->Get("d0_err");
TH1F * hDat_d0_err= (TH1F*)fDat->Get("d0_err");


TH1F * hZZ_d0_errLoose= (TH1F*)fZZ->Get("d0_errLoose");
TH1F * hWZ_d0_errLoose= (TH1F*)fWZ->Get("d0_errLoose");
TH1F * hWW_d0_errLoose= (TH1F*)fWW->Get("d0_errLoose");
TH1F * hDY_d0_errLoose= (TH1F*)fDY->Get("d0_errLoose");
TH1F * hll_d0_errLoose= (TH1F*)fll->Get("d0_errLoose");
TH1F * hDat_d0_errLoose= (TH1F*)fDat->Get("d0_errLoose");


TH1F * hZZ_dxy_err= (TH1F*)fZZ->Get("dxy_err");
TH1F * hWZ_dxy_err= (TH1F*)fWZ->Get("dxy_err");
TH1F * hWW_dxy_err= (TH1F*)fWW->Get("dxy_err");
TH1F * hDY_dxy_err= (TH1F*)fDY->Get("dxy_err");
TH1F * hll_dxy_err= (TH1F*)fll->Get("dxy_err");
TH1F * hDat_dxy_err= (TH1F*)fDat->Get("dxy_err");


TH1F * hZZ_dxy_errLoose= (TH1F*)fZZ->Get("dxy_errLoose");
TH1F * hWZ_dxy_errLoose= (TH1F*)fWZ->Get("dxy_errLoose");
TH1F * hWW_dxy_errLoose= (TH1F*)fWW->Get("dxy_errLoose");
TH1F * hDY_dxy_errLoose= (TH1F*)fDY->Get("dxy_errLoose");
TH1F * hll_dxy_errLoose= (TH1F*)fll->Get("dxy_errLoose");
TH1F * hDat_dxy_errLoose= (TH1F*)fDat->Get("dxy_errLoose");


TH1F * hZZ_cos= (TH1F*)fZZ->Get("cos");
TH1F * hWZ_cos= (TH1F*)fWZ->Get("cos");
TH1F * hWW_cos= (TH1F*)fWW->Get("cos");
TH1F * hDY_cos= (TH1F*)fDY->Get("cos");
TH1F * hll_cos= (TH1F*)fll->Get("cos");
TH1F * hDat_cos= (TH1F*)fDat->Get("cos");


TH1F * hZZ_cosLoose= (TH1F*)fZZ->Get("cosLoose");
TH1F * hWZ_cosLoose= (TH1F*)fWZ->Get("cosLoose");
TH1F * hWW_cosLoose= (TH1F*)fWW->Get("cosLoose");
TH1F * hDY_cosLoose= (TH1F*)fDY->Get("cosLoose");
TH1F * hll_cosLoose= (TH1F*)fll->Get("cosLoose");
TH1F * hDat_cosLoose= (TH1F*)fDat->Get("cosLoose");


TH1F * hZZ_delPhi= (TH1F*)fZZ->Get("delPhi");
TH1F * hWZ_delPhi= (TH1F*)fWZ->Get("delPhi");
TH1F * hWW_delPhi= (TH1F*)fWW->Get("delPhi");
TH1F * hDY_delPhi= (TH1F*)fDY->Get("delPhi");
TH1F * hll_delPhi= (TH1F*)fll->Get("delPhi");
TH1F * hDat_delPhi= (TH1F*)fDat->Get("delPhi");


TH1F * hZZ_delPhiLoose= (TH1F*)fZZ->Get("delPhiLoose");
TH1F * hWZ_delPhiLoose= (TH1F*)fWZ->Get("delPhiLoose");
TH1F * hWW_delPhiLoose= (TH1F*)fWW->Get("delPhiLoose");
TH1F * hDY_delPhiLoose= (TH1F*)fDY->Get("delPhiLoose");
TH1F * hll_delPhiLoose= (TH1F*)fll->Get("delPhiLoose");
TH1F * hDat_delPhiLoose= (TH1F*)fDat->Get("delPhiLoose");


TH1F * hZZ_conePt= (TH1F*)fZZ->Get("conePt");
TH1F * hWZ_conePt= (TH1F*)fWZ->Get("conePt");
TH1F * hWW_conePt= (TH1F*)fWW->Get("conePt");
TH1F * hDY_conePt= (TH1F*)fDY->Get("conePt");
TH1F * hll_conePt= (TH1F*)fll->Get("conePt");
TH1F * hDat_conePt= (TH1F*)fDat->Get("conePt");


TH1F * hZZ_chi2_NDF= (TH1F*)fZZ->Get("chi2_NDF");
TH1F * hWZ_chi2_NDF= (TH1F*)fWZ->Get("chi2_NDF");
TH1F * hWW_chi2_NDF= (TH1F*)fWW->Get("chi2_NDF");
TH1F * hDY_chi2_NDF= (TH1F*)fDY->Get("chi2_NDF");
TH1F * hll_chi2_NDF= (TH1F*)fll->Get("chi2_NDF");
TH1F * hDat_chi2_NDF= (TH1F*)fDat->Get("chi2_NDF");


TH1F * hZZ_chi2_NDF= (TH1F*)fZZ->Get("chi2_NDF");
TH1F * hWZ_chi2_NDF= (TH1F*)fWZ->Get("chi2_NDF");
TH1F * hWW_chi2_NDF= (TH1F*)fWW->Get("chi2_NDF");
TH1F * hDY_chi2_NDF= (TH1F*)fDY->Get("chi2_NDF");
TH1F * hll_chi2_NDF= (TH1F*)fll->Get("chi2_NDF");
TH1F * hDat_chi2_NDF= (TH1F*)fDat->Get("chi2_NDF");


TH1F * hZZ_chi2_NDFLoose= (TH1F*)fZZ->Get("chi2_NDFLoose");
TH1F * hWZ_chi2_NDFLoose= (TH1F*)fWZ->Get("chi2_NDFLoose");
TH1F * hWW_chi2_NDFLoose= (TH1F*)fWW->Get("chi2_NDFLoose");
TH1F * hDY_chi2_NDFLoose= (TH1F*)fDY->Get("chi2_NDFLoose");
TH1F * hll_chi2_NDFLoose= (TH1F*)fll->Get("chi2_NDFLoose");
TH1F * hDat_chi2_NDFLoose= (TH1F*)fDat->Get("chi2_NDFLoose");


TH1F * hZZ_numHitsLoose= (TH1F*)fZZ->Get("numHitsLoose");
TH1F * hWZ_numHitsLoose= (TH1F*)fWZ->Get("numHitsLoose");
TH1F * hWW_numHitsLoose= (TH1F*)fWW->Get("numHitsLoose");
TH1F * hDY_numHitsLoose= (TH1F*)fDY->Get("numHitsLoose");
TH1F * hll_numHitsLoose= (TH1F*)fll->Get("numHitsLoose");
TH1F * hDat_numHitsLoose= (TH1F*)fDat->Get("numHitsLoose");


TH1F * hZZ_h_dot= (TH1F*)fZZ->Get("h_dot");
TH1F * hWZ_h_dot= (TH1F*)fWZ->Get("h_dot");
TH1F * hWW_h_dot= (TH1F*)fWW->Get("h_dot");
TH1F * hDY_h_dot= (TH1F*)fDY->Get("h_dot");
TH1F * hll_h_dot= (TH1F*)fll->Get("h_dot");
TH1F * hDat_h_dot= (TH1F*)fDat->Get("h_dot");


hZZ_lxy->Sumw2();
hWZ_lxy->Sumw2();
hWW_lxy->Sumw2();
hDY_lxy->Sumw2();
hll_lxy->Sumw2();
hDat_lxy->Sumw2();


hZZ_lxyLoose->Sumw2();
hWZ_lxyLoose->Sumw2();
hWW_lxyLoose->Sumw2();
hDY_lxyLoose->Sumw2();
hll_lxyLoose->Sumw2();
hDat_lxyLoose->Sumw2();


hZZ_lxy_err->Sumw2();
hWZ_lxy_err->Sumw2();
hWW_lxy_err->Sumw2();
hDY_lxy_err->Sumw2();
hll_lxy_err->Sumw2();
hDat_lxy_err->Sumw2();


hZZ_lxy_errLoose->Sumw2();
hWZ_lxy_errLoose->Sumw2();
hWW_lxy_errLoose->Sumw2();
hDY_lxy_errLoose->Sumw2();
hll_lxy_errLoose->Sumw2();
hDat_lxy_errLoose->Sumw2();


hZZ_InvMass->Sumw2();
hWZ_InvMass->Sumw2();
hWW_InvMass->Sumw2();
hDY_InvMass->Sumw2();
hll_InvMass->Sumw2();
hDat_InvMass->Sumw2();


hZZ_InvMassLoose->Sumw2();
hWZ_InvMassLoose->Sumw2();
hWW_InvMassLoose->Sumw2();
hDY_InvMassLoose->Sumw2();
hll_InvMassLoose->Sumw2();
hDat_InvMassLoose->Sumw2();


hZZ_InvMassLW->Sumw2();
hWZ_InvMassLW->Sumw2();
hWW_InvMassLW->Sumw2();
hDY_InvMassLW->Sumw2();
hll_InvMassLW->Sumw2();
hDat_InvMassLW->Sumw2();


hZZ_d0_err->Sumw2();
hWZ_d0_err->Sumw2();
hWW_d0_err->Sumw2();
hDY_d0_err->Sumw2();
hll_d0_err->Sumw2();
hDat_d0_err->Sumw2();


hZZ_d0_errLoose->Sumw2();
hWZ_d0_errLoose->Sumw2();
hWW_d0_errLoose->Sumw2();
hDY_d0_errLoose->Sumw2();
hll_d0_errLoose->Sumw2();
hDat_d0_errLoose->Sumw2();


hZZ_dxy_err->Sumw2();
hWZ_dxy_err->Sumw2();
hWW_dxy_err->Sumw2();
hDY_dxy_err->Sumw2();
hll_dxy_err->Sumw2();
hDat_dxy_err->Sumw2();


hZZ_dxy_errLoose->Sumw2();
hWZ_dxy_errLoose->Sumw2();
hWW_dxy_errLoose->Sumw2();
hDY_dxy_errLoose->Sumw2();
hll_dxy_errLoose->Sumw2();
hDat_dxy_errLoose->Sumw2();


hZZ_cos->Sumw2();
hWZ_cos->Sumw2();
hWW_cos->Sumw2();
hDY_cos->Sumw2();
hll_cos->Sumw2();
hDat_cos->Sumw2();


hZZ_cosLoose->Sumw2();
hWZ_cosLoose->Sumw2();
hWW_cosLoose->Sumw2();
hDY_cosLoose->Sumw2();
hll_cosLoose->Sumw2();
hDat_cosLoose->Sumw2();


hZZ_delPhi->Sumw2();
hWZ_delPhi->Sumw2();
hWW_delPhi->Sumw2();
hDY_delPhi->Sumw2();
hll_delPhi->Sumw2();
hDat_delPhi->Sumw2();


hZZ_delPhiLoose->Sumw2();
hWZ_delPhiLoose->Sumw2();
hWW_delPhiLoose->Sumw2();
hDY_delPhiLoose->Sumw2();
hll_delPhiLoose->Sumw2();
hDat_delPhiLoose->Sumw2();


hZZ_conePt->Sumw2();
hWZ_conePt->Sumw2();
hWW_conePt->Sumw2();
hDY_conePt->Sumw2();
hll_conePt->Sumw2();
hDat_conePt->Sumw2();


hZZ_chi2_NDF->Sumw2();
hWZ_chi2_NDF->Sumw2();
hWW_chi2_NDF->Sumw2();
hDY_chi2_NDF->Sumw2();
hll_chi2_NDF->Sumw2();
hDat_chi2_NDF->Sumw2();


hZZ_chi2_NDF->Sumw2();
hWZ_chi2_NDF->Sumw2();
hWW_chi2_NDF->Sumw2();
hDY_chi2_NDF->Sumw2();
hll_chi2_NDF->Sumw2();
hDat_chi2_NDF->Sumw2();


hZZ_chi2_NDFLoose->Sumw2();
hWZ_chi2_NDFLoose->Sumw2();
hWW_chi2_NDFLoose->Sumw2();
hDY_chi2_NDFLoose->Sumw2();
hll_chi2_NDFLoose->Sumw2();
hDat_chi2_NDFLoose->Sumw2();


hZZ_numHitsLoose->Sumw2();
hWZ_numHitsLoose->Sumw2();
hWW_numHitsLoose->Sumw2();
hDY_numHitsLoose->Sumw2();
hll_numHitsLoose->Sumw2();
hDat_numHitsLoose->Sumw2();


hZZ_h_dot->Sumw2();
hWZ_h_dot->Sumw2();
hWW_h_dot->Sumw2();
hDY_h_dot->Sumw2();
hll_h_dot->Sumw2();
hDat_h_dot->Sumw2();


hZZ_lxy->SetLineColor(1);
hWZ_lxy->SetLineColor(1);
hWW_lxy->SetLineColor(1);
hDY_lxy->SetLineColor(1);


hZZ_lxyLoose->SetLineColor(1);
hWZ_lxyLoose->SetLineColor(1);
hWW_lxyLoose->SetLineColor(1);
hDY_lxyLoose->SetLineColor(1);


hZZ_lxy_err->SetLineColor(1);
hWZ_lxy_err->SetLineColor(1);
hWW_lxy_err->SetLineColor(1);
hDY_lxy_err->SetLineColor(1);


hZZ_lxy_errLoose->SetLineColor(1);
hWZ_lxy_errLoose->SetLineColor(1);
hWW_lxy_errLoose->SetLineColor(1);
hDY_lxy_errLoose->SetLineColor(1);


hZZ_InvMass->SetLineColor(1);
hWZ_InvMass->SetLineColor(1);
hWW_InvMass->SetLineColor(1);
hDY_InvMass->SetLineColor(1);


hZZ_InvMassLoose->SetLineColor(1);
hWZ_InvMassLoose->SetLineColor(1);
hWW_InvMassLoose->SetLineColor(1);
hDY_InvMassLoose->SetLineColor(1);


hZZ_InvMassLW->SetLineColor(1);
hWZ_InvMassLW->SetLineColor(1);
hWW_InvMassLW->SetLineColor(1);
hDY_InvMassLW->SetLineColor(1);


hZZ_d0_err->SetLineColor(1);
hWZ_d0_err->SetLineColor(1);
hWW_d0_err->SetLineColor(1);
hDY_d0_err->SetLineColor(1);


hZZ_d0_errLoose->SetLineColor(1);
hWZ_d0_errLoose->SetLineColor(1);
hWW_d0_errLoose->SetLineColor(1);
hDY_d0_errLoose->SetLineColor(1);


hZZ_dxy_err->SetLineColor(1);
hWZ_dxy_err->SetLineColor(1);
hWW_dxy_err->SetLineColor(1);
hDY_dxy_err->SetLineColor(1);


hZZ_dxy_errLoose->SetLineColor(1);
hWZ_dxy_errLoose->SetLineColor(1);
hWW_dxy_errLoose->SetLineColor(1);
hDY_dxy_errLoose->SetLineColor(1);


hZZ_cos->SetLineColor(1);
hWZ_cos->SetLineColor(1);
hWW_cos->SetLineColor(1);
hDY_cos->SetLineColor(1);


hZZ_cosLoose->SetLineColor(1);
hWZ_cosLoose->SetLineColor(1);
hWW_cosLoose->SetLineColor(1);
hDY_cosLoose->SetLineColor(1);


hZZ_delPhi->SetLineColor(1);
hWZ_delPhi->SetLineColor(1);
hWW_delPhi->SetLineColor(1);
hDY_delPhi->SetLineColor(1);


hZZ_delPhiLoose->SetLineColor(1);
hWZ_delPhiLoose->SetLineColor(1);
hWW_delPhiLoose->SetLineColor(1);
hDY_delPhiLoose->SetLineColor(1);


hZZ_conePt->SetLineColor(1);
hWZ_conePt->SetLineColor(1);
hWW_conePt->SetLineColor(1);
hDY_conePt->SetLineColor(1);


hZZ_chi2_NDF->SetLineColor(1);
hWZ_chi2_NDF->SetLineColor(1);
hWW_chi2_NDF->SetLineColor(1);
hDY_chi2_NDF->SetLineColor(1);


hZZ_chi2_NDF->SetLineColor(1);
hWZ_chi2_NDF->SetLineColor(1);
hWW_chi2_NDF->SetLineColor(1);
hDY_chi2_NDF->SetLineColor(1);


hZZ_chi2_NDFLoose->SetLineColor(1);
hWZ_chi2_NDFLoose->SetLineColor(1);
hWW_chi2_NDFLoose->SetLineColor(1);
hDY_chi2_NDFLoose->SetLineColor(1);


hZZ_numHitsLoose->SetLineColor(1);
hWZ_numHitsLoose->SetLineColor(1);
hWW_numHitsLoose->SetLineColor(1);
hDY_numHitsLoose->SetLineColor(1);


hZZ_h_dot->SetLineColor(1);
hWZ_h_dot->SetLineColor(1);
hWW_h_dot->SetLineColor(1);
hDY_h_dot->SetLineColor(1);


hZZ_lxy->SetFillColor(kGreen +3);
hWZ_lxy->SetFillColor(kCyan -9);
hWW_lxy->SetFillColor(kMagenta -3);
hDY_lxy->SetFillColor(2);


hZZ_lxyLoose->SetFillColor(kGreen +3);
hWZ_lxyLoose->SetFillColor(kCyan -9);
hWW_lxyLoose->SetFillColor(kMagenta -3);
hDY_lxyLoose->SetFillColor(2);


hZZ_lxy_err->SetFillColor(kGreen +3);
hWZ_lxy_err->SetFillColor(kCyan -9);
hWW_lxy_err->SetFillColor(kMagenta -3);
hDY_lxy_err->SetFillColor(2);


hZZ_lxy_errLoose->SetFillColor(kGreen +3);
hWZ_lxy_errLoose->SetFillColor(kCyan -9);
hWW_lxy_errLoose->SetFillColor(kMagenta -3);
hDY_lxy_errLoose->SetFillColor(2);


hZZ_InvMass->SetFillColor(kGreen +3);
hWZ_InvMass->SetFillColor(kCyan -9);
hWW_InvMass->SetFillColor(kMagenta -3);
hDY_InvMass->SetFillColor(2);


hZZ_InvMassLoose->SetFillColor(kGreen +3);
hWZ_InvMassLoose->SetFillColor(kCyan -9);
hWW_InvMassLoose->SetFillColor(kMagenta -3);
hDY_InvMassLoose->SetFillColor(2);


hZZ_InvMassLW->SetFillColor(kGreen +3);
hWZ_InvMassLW->SetFillColor(kCyan -9);
hWW_InvMassLW->SetFillColor(kMagenta -3);
hDY_InvMassLW->SetFillColor(2);


hZZ_d0_err->SetFillColor(kGreen +3);
hWZ_d0_err->SetFillColor(kCyan -9);
hWW_d0_err->SetFillColor(kMagenta -3);
hDY_d0_err->SetFillColor(2);


hZZ_d0_errLoose->SetFillColor(kGreen +3);
hWZ_d0_errLoose->SetFillColor(kCyan -9);
hWW_d0_errLoose->SetFillColor(kMagenta -3);
hDY_d0_errLoose->SetFillColor(2);


hZZ_dxy_err->SetFillColor(kGreen +3);
hWZ_dxy_err->SetFillColor(kCyan -9);
hWW_dxy_err->SetFillColor(kMagenta -3);
hDY_dxy_err->SetFillColor(2);


hZZ_dxy_errLoose->SetFillColor(kGreen +3);
hWZ_dxy_errLoose->SetFillColor(kCyan -9);
hWW_dxy_errLoose->SetFillColor(kMagenta -3);
hDY_dxy_errLoose->SetFillColor(2);


hZZ_cos->SetFillColor(kGreen +3);
hWZ_cos->SetFillColor(kCyan -9);
hWW_cos->SetFillColor(kMagenta -3);
hDY_cos->SetFillColor(2);


hZZ_cosLoose->SetFillColor(kGreen +3);
hWZ_cosLoose->SetFillColor(kCyan -9);
hWW_cosLoose->SetFillColor(kMagenta -3);
hDY_cosLoose->SetFillColor(2);


hZZ_delPhi->SetFillColor(kGreen +3);
hWZ_delPhi->SetFillColor(kCyan -9);
hWW_delPhi->SetFillColor(kMagenta -3);
hDY_delPhi->SetFillColor(2);


hZZ_delPhiLoose->SetFillColor(kGreen +3);
hWZ_delPhiLoose->SetFillColor(kCyan -9);
hWW_delPhiLoose->SetFillColor(kMagenta -3);
hDY_delPhiLoose->SetFillColor(2);


hZZ_conePt->SetFillColor(kGreen +3);
hWZ_conePt->SetFillColor(kCyan -9);
hWW_conePt->SetFillColor(kMagenta -3);
hDY_conePt->SetFillColor(2);


hZZ_chi2_NDF->SetFillColor(kGreen +3);
hWZ_chi2_NDF->SetFillColor(kCyan -9);
hWW_chi2_NDF->SetFillColor(kMagenta -3);
hDY_chi2_NDF->SetFillColor(2);


hZZ_chi2_NDF->SetFillColor(kGreen +3);
hWZ_chi2_NDF->SetFillColor(kCyan -9);
hWW_chi2_NDF->SetFillColor(kMagenta -3);
hDY_chi2_NDF->SetFillColor(2);


hZZ_chi2_NDFLoose->SetFillColor(kGreen +3);
hWZ_chi2_NDFLoose->SetFillColor(kCyan -9);
hWW_chi2_NDFLoose->SetFillColor(kMagenta -3);
hDY_chi2_NDFLoose->SetFillColor(2);


hZZ_numHitsLoose->SetFillColor(kGreen +3);
hWZ_numHitsLoose->SetFillColor(kCyan -9);
hWW_numHitsLoose->SetFillColor(kMagenta -3);
hDY_numHitsLoose->SetFillColor(2);


hZZ_h_dot->SetFillColor(kGreen +3);
hWZ_h_dot->SetFillColor(kCyan -9);
hWW_h_dot->SetFillColor(kMagenta -3);
hDY_h_dot->SetFillColor(2);


hDat_lxy->SetMarkerStyle(21);
hDat_lxy->SetMarkerSize(1);
hDat_lxy->SetLineColor(1);
hll_lxy->SetLineColor(2);
hDat_lxyLoose->SetMarkerStyle(21);
hDat_lxyLoose->SetMarkerSize(1);
hDat_lxyLoose->SetLineColor(1);
hll_lxyLoose->SetLineColor(2);
hDat_lxy_err->SetMarkerStyle(21);
hDat_lxy_err->SetMarkerSize(1);
hDat_lxy_err->SetLineColor(1);
hll_lxy_err->SetLineColor(2);
hDat_lxy_errLoose->SetMarkerStyle(21);
hDat_lxy_errLoose->SetMarkerSize(1);
hDat_lxy_errLoose->SetLineColor(1);
hll_lxy_errLoose->SetLineColor(2);
hDat_InvMass->SetMarkerStyle(21);
hDat_InvMass->SetMarkerSize(1);
hDat_InvMass->SetLineColor(1);
hll_InvMass->SetLineColor(2);
hDat_InvMassLoose->SetMarkerStyle(21);
hDat_InvMassLoose->SetMarkerSize(1);
hDat_InvMassLoose->SetLineColor(1);
hll_InvMassLoose->SetLineColor(2);
hDat_InvMassLW->SetMarkerStyle(21);
hDat_InvMassLW->SetMarkerSize(1);
hDat_InvMassLW->SetLineColor(1);
hll_InvMassLW->SetLineColor(2);
hDat_d0_err->SetMarkerStyle(21);
hDat_d0_err->SetMarkerSize(1);
hDat_d0_err->SetLineColor(1);
hll_d0_err->SetLineColor(2);
hDat_d0_errLoose->SetMarkerStyle(21);
hDat_d0_errLoose->SetMarkerSize(1);
hDat_d0_errLoose->SetLineColor(1);
hll_d0_errLoose->SetLineColor(2);
hDat_dxy_err->SetMarkerStyle(21);
hDat_dxy_err->SetMarkerSize(1);
hDat_dxy_err->SetLineColor(1);
hll_dxy_err->SetLineColor(2);
hDat_dxy_errLoose->SetMarkerStyle(21);
hDat_dxy_errLoose->SetMarkerSize(1);
hDat_dxy_errLoose->SetLineColor(1);
hll_dxy_errLoose->SetLineColor(2);
hDat_cos->SetMarkerStyle(21);
hDat_cos->SetMarkerSize(1);
hDat_cos->SetLineColor(1);
hll_cos->SetLineColor(2);
hDat_cosLoose->SetMarkerStyle(21);
hDat_cosLoose->SetMarkerSize(1);
hDat_cosLoose->SetLineColor(1);
hll_cosLoose->SetLineColor(2);
hDat_delPhi->SetMarkerStyle(21);
hDat_delPhi->SetMarkerSize(1);
hDat_delPhi->SetLineColor(1);
hll_delPhi->SetLineColor(2);
hDat_delPhiLoose->SetMarkerStyle(21);
hDat_delPhiLoose->SetMarkerSize(1);
hDat_delPhiLoose->SetLineColor(1);
hll_delPhiLoose->SetLineColor(2);
hDat_conePt->SetMarkerStyle(21);
hDat_conePt->SetMarkerSize(1);
hDat_conePt->SetLineColor(1);
hll_conePt->SetLineColor(2);
hDat_chi2_NDF->SetMarkerStyle(21);
hDat_chi2_NDF->SetMarkerSize(1);
hDat_chi2_NDF->SetLineColor(1);
hll_chi2_NDF->SetLineColor(2);
hDat_chi2_NDF->SetMarkerStyle(21);
hDat_chi2_NDF->SetMarkerSize(1);
hDat_chi2_NDF->SetLineColor(1);
hll_chi2_NDF->SetLineColor(2);
hDat_chi2_NDFLoose->SetMarkerStyle(21);
hDat_chi2_NDFLoose->SetMarkerSize(1);
hDat_chi2_NDFLoose->SetLineColor(1);
hll_chi2_NDFLoose->SetLineColor(2);
hDat_numHitsLoose->SetMarkerStyle(21);
hDat_numHitsLoose->SetMarkerSize(1);
hDat_numHitsLoose->SetLineColor(1);
hll_numHitsLoose->SetLineColor(2);
hDat_h_dot->SetMarkerStyle(21);
hDat_h_dot->SetMarkerSize(1);
hDat_h_dot->SetLineColor(1);
hll_h_dot->SetLineColor(2);
double DY_scale = lumi*3048.0/(hDY_lxy->Integral());
double ZZ_scale = lumi*5.9/(hZZ_lxy->Integral());
double WZ_scale = lumi*18.2/(hWZ_lxy->Integral());
double WW_scale = lumi*42.0/(hWW_lxy->Integral());


hZZ_lxy->Scale(ZZ_scale);
hWZ_lxy->Scale(WZ_scale);
hWW_lxy->Scale(WW_scale);
hDY_lxy->Scale(DY_scale);


hZZ_lxyLoose->Scale(ZZ_scale);
hWZ_lxyLoose->Scale(WZ_scale);
hWW_lxyLoose->Scale(WW_scale);
hDY_lxyLoose->Scale(DY_scale);


hZZ_lxy_err->Scale(ZZ_scale);
hWZ_lxy_err->Scale(WZ_scale);
hWW_lxy_err->Scale(WW_scale);
hDY_lxy_err->Scale(DY_scale);


hZZ_lxy_errLoose->Scale(ZZ_scale);
hWZ_lxy_errLoose->Scale(WZ_scale);
hWW_lxy_errLoose->Scale(WW_scale);
hDY_lxy_errLoose->Scale(DY_scale);


hZZ_InvMass->Scale(ZZ_scale);
hWZ_InvMass->Scale(WZ_scale);
hWW_InvMass->Scale(WW_scale);
hDY_InvMass->Scale(DY_scale);


hZZ_InvMassLoose->Scale(ZZ_scale);
hWZ_InvMassLoose->Scale(WZ_scale);
hWW_InvMassLoose->Scale(WW_scale);
hDY_InvMassLoose->Scale(DY_scale);


hZZ_InvMassLW->Scale(ZZ_scale);
hWZ_InvMassLW->Scale(WZ_scale);
hWW_InvMassLW->Scale(WW_scale);
hDY_InvMassLW->Scale(DY_scale);


hZZ_d0_err->Scale(ZZ_scale);
hWZ_d0_err->Scale(WZ_scale);
hWW_d0_err->Scale(WW_scale);
hDY_d0_err->Scale(DY_scale);


hZZ_d0_errLoose->Scale(ZZ_scale);
hWZ_d0_errLoose->Scale(WZ_scale);
hWW_d0_errLoose->Scale(WW_scale);
hDY_d0_errLoose->Scale(DY_scale);


hZZ_dxy_err->Scale(ZZ_scale);
hWZ_dxy_err->Scale(WZ_scale);
hWW_dxy_err->Scale(WW_scale);
hDY_dxy_err->Scale(DY_scale);


hZZ_dxy_errLoose->Scale(ZZ_scale);
hWZ_dxy_errLoose->Scale(WZ_scale);
hWW_dxy_errLoose->Scale(WW_scale);
hDY_dxy_errLoose->Scale(DY_scale);


hZZ_cos->Scale(ZZ_scale);
hWZ_cos->Scale(WZ_scale);
hWW_cos->Scale(WW_scale);
hDY_cos->Scale(DY_scale);


hZZ_cosLoose->Scale(ZZ_scale);
hWZ_cosLoose->Scale(WZ_scale);
hWW_cosLoose->Scale(WW_scale);
hDY_cosLoose->Scale(DY_scale);


hZZ_delPhi->Scale(ZZ_scale);
hWZ_delPhi->Scale(WZ_scale);
hWW_delPhi->Scale(WW_scale);
hDY_delPhi->Scale(DY_scale);


hZZ_delPhiLoose->Scale(ZZ_scale);
hWZ_delPhiLoose->Scale(WZ_scale);
hWW_delPhiLoose->Scale(WW_scale);
hDY_delPhiLoose->Scale(DY_scale);


hZZ_conePt->Scale(ZZ_scale);
hWZ_conePt->Scale(WZ_scale);
hWW_conePt->Scale(WW_scale);
hDY_conePt->Scale(DY_scale);


hZZ_chi2_NDF->Scale(ZZ_scale);
hWZ_chi2_NDF->Scale(WZ_scale);
hWW_chi2_NDF->Scale(WW_scale);
hDY_chi2_NDF->Scale(DY_scale);


hZZ_chi2_NDF->Scale(ZZ_scale);
hWZ_chi2_NDF->Scale(WZ_scale);
hWW_chi2_NDF->Scale(WW_scale);
hDY_chi2_NDF->Scale(DY_scale);


hZZ_chi2_NDFLoose->Scale(ZZ_scale);
hWZ_chi2_NDFLoose->Scale(WZ_scale);
hWW_chi2_NDFLoose->Scale(WW_scale);
hDY_chi2_NDFLoose->Scale(DY_scale);


hZZ_numHitsLoose->Scale(ZZ_scale);
hWZ_numHitsLoose->Scale(WZ_scale);
hWW_numHitsLoose->Scale(WW_scale);
hDY_numHitsLoose->Scale(DY_scale);


hZZ_h_dot->Scale(ZZ_scale);
hWZ_h_dot->Scale(WZ_scale);
hWW_h_dot->Scale(WW_scale);
hDY_h_dot->Scale(DY_scale);


hZZ_lxy->SetStats(0);
hWZ_lxy->SetStats(0);
hWW_lxy->SetStats(0);
hDY_lxy->SetStats(0);
hll_lxy->SetStats(0);
hDat_lxy->SetStats(0);


hZZ_lxyLoose->SetStats(0);
hWZ_lxyLoose->SetStats(0);
hWW_lxyLoose->SetStats(0);
hDY_lxyLoose->SetStats(0);
hll_lxyLoose->SetStats(0);
hDat_lxyLoose->SetStats(0);


hZZ_lxy_err->SetStats(0);
hWZ_lxy_err->SetStats(0);
hWW_lxy_err->SetStats(0);
hDY_lxy_err->SetStats(0);
hll_lxy_err->SetStats(0);
hDat_lxy_err->SetStats(0);


hZZ_lxy_errLoose->SetStats(0);
hWZ_lxy_errLoose->SetStats(0);
hWW_lxy_errLoose->SetStats(0);
hDY_lxy_errLoose->SetStats(0);
hll_lxy_errLoose->SetStats(0);
hDat_lxy_errLoose->SetStats(0);


hZZ_InvMass->SetStats(0);
hWZ_InvMass->SetStats(0);
hWW_InvMass->SetStats(0);
hDY_InvMass->SetStats(0);
hll_InvMass->SetStats(0);
hDat_InvMass->SetStats(0);


hZZ_InvMassLoose->SetStats(0);
hWZ_InvMassLoose->SetStats(0);
hWW_InvMassLoose->SetStats(0);
hDY_InvMassLoose->SetStats(0);
hll_InvMassLoose->SetStats(0);
hDat_InvMassLoose->SetStats(0);


hZZ_InvMassLW->SetStats(0);
hWZ_InvMassLW->SetStats(0);
hWW_InvMassLW->SetStats(0);
hDY_InvMassLW->SetStats(0);
hll_InvMassLW->SetStats(0);
hDat_InvMassLW->SetStats(0);


hZZ_d0_err->SetStats(0);
hWZ_d0_err->SetStats(0);
hWW_d0_err->SetStats(0);
hDY_d0_err->SetStats(0);
hll_d0_err->SetStats(0);
hDat_d0_err->SetStats(0);


hZZ_d0_errLoose->SetStats(0);
hWZ_d0_errLoose->SetStats(0);
hWW_d0_errLoose->SetStats(0);
hDY_d0_errLoose->SetStats(0);
hll_d0_errLoose->SetStats(0);
hDat_d0_errLoose->SetStats(0);


hZZ_dxy_err->SetStats(0);
hWZ_dxy_err->SetStats(0);
hWW_dxy_err->SetStats(0);
hDY_dxy_err->SetStats(0);
hll_dxy_err->SetStats(0);
hDat_dxy_err->SetStats(0);


hZZ_dxy_errLoose->SetStats(0);
hWZ_dxy_errLoose->SetStats(0);
hWW_dxy_errLoose->SetStats(0);
hDY_dxy_errLoose->SetStats(0);
hll_dxy_errLoose->SetStats(0);
hDat_dxy_errLoose->SetStats(0);


hZZ_cos->SetStats(0);
hWZ_cos->SetStats(0);
hWW_cos->SetStats(0);
hDY_cos->SetStats(0);
hll_cos->SetStats(0);
hDat_cos->SetStats(0);


hZZ_cosLoose->SetStats(0);
hWZ_cosLoose->SetStats(0);
hWW_cosLoose->SetStats(0);
hDY_cosLoose->SetStats(0);
hll_cosLoose->SetStats(0);
hDat_cosLoose->SetStats(0);


hZZ_delPhi->SetStats(0);
hWZ_delPhi->SetStats(0);
hWW_delPhi->SetStats(0);
hDY_delPhi->SetStats(0);
hll_delPhi->SetStats(0);
hDat_delPhi->SetStats(0);


hZZ_delPhiLoose->SetStats(0);
hWZ_delPhiLoose->SetStats(0);
hWW_delPhiLoose->SetStats(0);
hDY_delPhiLoose->SetStats(0);
hll_delPhiLoose->SetStats(0);
hDat_delPhiLoose->SetStats(0);


hZZ_conePt->SetStats(0);
hWZ_conePt->SetStats(0);
hWW_conePt->SetStats(0);
hDY_conePt->SetStats(0);
hll_conePt->SetStats(0);
hDat_conePt->SetStats(0);


hZZ_chi2_NDF->SetStats(0);
hWZ_chi2_NDF->SetStats(0);
hWW_chi2_NDF->SetStats(0);
hDY_chi2_NDF->SetStats(0);
hll_chi2_NDF->SetStats(0);
hDat_chi2_NDF->SetStats(0);


hZZ_chi2_NDF->SetStats(0);
hWZ_chi2_NDF->SetStats(0);
hWW_chi2_NDF->SetStats(0);
hDY_chi2_NDF->SetStats(0);
hll_chi2_NDF->SetStats(0);
hDat_chi2_NDF->SetStats(0);


hZZ_chi2_NDFLoose->SetStats(0);
hWZ_chi2_NDFLoose->SetStats(0);
hWW_chi2_NDFLoose->SetStats(0);
hDY_chi2_NDFLoose->SetStats(0);
hll_chi2_NDFLoose->SetStats(0);
hDat_chi2_NDFLoose->SetStats(0);


hZZ_numHitsLoose->SetStats(0);
hWZ_numHitsLoose->SetStats(0);
hWW_numHitsLoose->SetStats(0);
hDY_numHitsLoose->SetStats(0);
hll_numHitsLoose->SetStats(0);
hDat_numHitsLoose->SetStats(0);


hZZ_h_dot->SetStats(0);
hWZ_h_dot->SetStats(0);
hWW_h_dot->SetStats(0);
hDY_h_dot->SetStats(0);
hll_h_dot->SetStats(0);
hDat_h_dot->SetStats(0);


hs_lxy->Add(hZZ_lxy);
hs_lxy->Add(hWZ_lxy);
hs_lxy->Add(hWW_lxy);
hs_lxy->Add(hDY_lxy);


hs_lxyLoose->Add(hZZ_lxyLoose);
hs_lxyLoose->Add(hWZ_lxyLoose);
hs_lxyLoose->Add(hWW_lxyLoose);
hs_lxyLoose->Add(hDY_lxyLoose);


hs_lxy_err->Add(hZZ_lxy_err);
hs_lxy_err->Add(hWZ_lxy_err);
hs_lxy_err->Add(hWW_lxy_err);
hs_lxy_err->Add(hDY_lxy_err);


hs_lxy_errLoose->Add(hZZ_lxy_errLoose);
hs_lxy_errLoose->Add(hWZ_lxy_errLoose);
hs_lxy_errLoose->Add(hWW_lxy_errLoose);
hs_lxy_errLoose->Add(hDY_lxy_errLoose);


hs_InvMass->Add(hZZ_InvMass);
hs_InvMass->Add(hWZ_InvMass);
hs_InvMass->Add(hWW_InvMass);
hs_InvMass->Add(hDY_InvMass);


hs_InvMassLoose->Add(hZZ_InvMassLoose);
hs_InvMassLoose->Add(hWZ_InvMassLoose);
hs_InvMassLoose->Add(hWW_InvMassLoose);
hs_InvMassLoose->Add(hDY_InvMassLoose);


hs_InvMassLW->Add(hZZ_InvMassLW);
hs_InvMassLW->Add(hWZ_InvMassLW);
hs_InvMassLW->Add(hWW_InvMassLW);
hs_InvMassLW->Add(hDY_InvMassLW);


hs_d0_err->Add(hZZ_d0_err);
hs_d0_err->Add(hWZ_d0_err);
hs_d0_err->Add(hWW_d0_err);
hs_d0_err->Add(hDY_d0_err);


hs_d0_errLoose->Add(hZZ_d0_errLoose);
hs_d0_errLoose->Add(hWZ_d0_errLoose);
hs_d0_errLoose->Add(hWW_d0_errLoose);
hs_d0_errLoose->Add(hDY_d0_errLoose);


hs_dxy_err->Add(hZZ_dxy_err);
hs_dxy_err->Add(hWZ_dxy_err);
hs_dxy_err->Add(hWW_dxy_err);
hs_dxy_err->Add(hDY_dxy_err);


hs_dxy_errLoose->Add(hZZ_dxy_errLoose);
hs_dxy_errLoose->Add(hWZ_dxy_errLoose);
hs_dxy_errLoose->Add(hWW_dxy_errLoose);
hs_dxy_errLoose->Add(hDY_dxy_errLoose);


hs_cos->Add(hZZ_cos);
hs_cos->Add(hWZ_cos);
hs_cos->Add(hWW_cos);
hs_cos->Add(hDY_cos);


hs_cosLoose->Add(hZZ_cosLoose);
hs_cosLoose->Add(hWZ_cosLoose);
hs_cosLoose->Add(hWW_cosLoose);
hs_cosLoose->Add(hDY_cosLoose);


hs_delPhi->Add(hZZ_delPhi);
hs_delPhi->Add(hWZ_delPhi);
hs_delPhi->Add(hWW_delPhi);
hs_delPhi->Add(hDY_delPhi);


hs_delPhiLoose->Add(hZZ_delPhiLoose);
hs_delPhiLoose->Add(hWZ_delPhiLoose);
hs_delPhiLoose->Add(hWW_delPhiLoose);
hs_delPhiLoose->Add(hDY_delPhiLoose);


hs_conePt->Add(hZZ_conePt);
hs_conePt->Add(hWZ_conePt);
hs_conePt->Add(hWW_conePt);
hs_conePt->Add(hDY_conePt);


hs_chi2_NDF->Add(hZZ_chi2_NDF);
hs_chi2_NDF->Add(hWZ_chi2_NDF);
hs_chi2_NDF->Add(hWW_chi2_NDF);
hs_chi2_NDF->Add(hDY_chi2_NDF);


hs_chi2_NDF->Add(hZZ_chi2_NDF);
hs_chi2_NDF->Add(hWZ_chi2_NDF);
hs_chi2_NDF->Add(hWW_chi2_NDF);
hs_chi2_NDF->Add(hDY_chi2_NDF);


hs_chi2_NDFLoose->Add(hZZ_chi2_NDFLoose);
hs_chi2_NDFLoose->Add(hWZ_chi2_NDFLoose);
hs_chi2_NDFLoose->Add(hWW_chi2_NDFLoose);
hs_chi2_NDFLoose->Add(hDY_chi2_NDFLoose);


hs_numHitsLoose->Add(hZZ_numHitsLoose);
hs_numHitsLoose->Add(hWZ_numHitsLoose);
hs_numHitsLoose->Add(hWW_numHitsLoose);
hs_numHitsLoose->Add(hDY_numHitsLoose);


hs_h_dot->Add(hZZ_h_dot);
hs_h_dot->Add(hWZ_h_dot);
hs_h_dot->Add(hWW_h_dot);
hs_h_dot->Add(hDY_h_dot);


double m1, m2, m3, mMax;
m1 = hDat_lxy->GetMaximum();
m2 = hll_lxy->GetMaximum();
m3 = hs_lxy->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_lxy->SetMaximum(2*mMax);
TCanvas *cs_lxy = new TCanvas("cs_lxy","cs_lxy",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_lxy->SetTitle("lxy");
auto legend_lxy = new TLegend(0.5,0.7,0.9,0.9);
legend_lxy->AddEntry(hDY_lxy,"Z/#gamma*#rightarrow #mu#mu","f");
legend_lxy->AddEntry(hWW_lxy,"WW","f");
legend_lxy->AddEntry(hWZ_lxy,"WZ","f");
legend_lxy->AddEntry(hZZ_lxy,"ZZ","f");
legend_lxy->AddEntry(hDat_lxy,"Data","p");
legend_lxy->SetFillColor(0);
hDat_lxy->SetXTitle("mass [GeV/c^{2}]");
hDat_lxy->SetYTitle("Entries");
cs_lxy->cd(1); hll_lxy->Draw("hist eX0"); cs_lxy->Update(); hs_lxy->Draw("same hist eX0"); cs_lxy->Update(); hDat_lxy->Draw("same  eX0");
// cs->cd(1);  hs_lxy->Draw(" hist"); cs->Update(); hDat_lxy->Draw("hist same");
legend_lxy->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_lxyLoose->GetMaximum();
m2 = hll_lxyLoose->GetMaximum();
m3 = hs_lxyLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_lxyLoose->SetMaximum(2*mMax);
TCanvas *cs_lxyLoose = new TCanvas("cs_lxyLoose","cs_lxyLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_lxyLoose->SetTitle("lxyLoose");
auto legend_lxyLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_lxyLoose->AddEntry(hDY_lxyLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_lxyLoose->AddEntry(hWW_lxyLoose,"WW","f");
legend_lxyLoose->AddEntry(hWZ_lxyLoose,"WZ","f");
legend_lxyLoose->AddEntry(hZZ_lxyLoose,"ZZ","f");
legend_lxyLoose->AddEntry(hDat_lxyLoose,"Data","p");
legend_lxyLoose->SetFillColor(0);
hDat_lxyLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_lxyLoose->SetYTitle("Entries");
cs_lxyLoose->cd(1); hll_lxyLoose->Draw("hist eX0"); cs_lxyLoose->Update(); hs_lxyLoose->Draw("same hist eX0"); cs_lxyLoose->Update(); hDat_lxyLoose->Draw("same  eX0");
// cs->cd(1);  hs_lxyLoose->Draw(" hist"); cs->Update(); hDat_lxyLoose->Draw("hist same");
legend_lxyLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_lxy_err->GetMaximum();
m2 = hll_lxy_err->GetMaximum();
m3 = hs_lxy_err->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_lxy_err->SetMaximum(2*mMax);
TCanvas *cs_lxy_err = new TCanvas("cs_lxy_err","cs_lxy_err",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_lxy_err->SetTitle("lxy_err");
auto legend_lxy_err = new TLegend(0.5,0.7,0.9,0.9);
legend_lxy_err->AddEntry(hDY_lxy_err,"Z/#gamma*#rightarrow #mu#mu","f");
legend_lxy_err->AddEntry(hWW_lxy_err,"WW","f");
legend_lxy_err->AddEntry(hWZ_lxy_err,"WZ","f");
legend_lxy_err->AddEntry(hZZ_lxy_err,"ZZ","f");
legend_lxy_err->AddEntry(hDat_lxy_err,"Data","p");
legend_lxy_err->SetFillColor(0);
hDat_lxy_err->SetXTitle("mass [GeV/c^{2}]");
hDat_lxy_err->SetYTitle("Entries");
cs_lxy_err->cd(1); hll_lxy_err->Draw("hist eX0"); cs_lxy_err->Update(); hs_lxy_err->Draw("same hist eX0"); cs_lxy_err->Update(); hDat_lxy_err->Draw("same  eX0");
// cs->cd(1);  hs_lxy_err->Draw(" hist"); cs->Update(); hDat_lxy_err->Draw("hist same");
legend_lxy_err->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_lxy_errLoose->GetMaximum();
m2 = hll_lxy_errLoose->GetMaximum();
m3 = hs_lxy_errLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_lxy_errLoose->SetMaximum(2*mMax);
TCanvas *cs_lxy_errLoose = new TCanvas("cs_lxy_errLoose","cs_lxy_errLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_lxy_errLoose->SetTitle("lxy_errLoose");
auto legend_lxy_errLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_lxy_errLoose->AddEntry(hDY_lxy_errLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_lxy_errLoose->AddEntry(hWW_lxy_errLoose,"WW","f");
legend_lxy_errLoose->AddEntry(hWZ_lxy_errLoose,"WZ","f");
legend_lxy_errLoose->AddEntry(hZZ_lxy_errLoose,"ZZ","f");
legend_lxy_errLoose->AddEntry(hDat_lxy_errLoose,"Data","p");
legend_lxy_errLoose->SetFillColor(0);
hDat_lxy_errLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_lxy_errLoose->SetYTitle("Entries");
cs_lxy_errLoose->cd(1); hll_lxy_errLoose->Draw("hist eX0"); cs_lxy_errLoose->Update(); hs_lxy_errLoose->Draw("same hist eX0"); cs_lxy_errLoose->Update(); hDat_lxy_errLoose->Draw("same  eX0");
// cs->cd(1);  hs_lxy_errLoose->Draw(" hist"); cs->Update(); hDat_lxy_errLoose->Draw("hist same");
legend_lxy_errLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_InvMass->GetMaximum();
m2 = hll_InvMass->GetMaximum();
m3 = hs_InvMass->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_InvMass->SetMaximum(2*mMax);
TCanvas *cs_InvMass = new TCanvas("cs_InvMass","cs_InvMass",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_InvMass->SetTitle("InvMass");
auto legend_InvMass = new TLegend(0.5,0.7,0.9,0.9);
legend_InvMass->AddEntry(hDY_InvMass,"Z/#gamma*#rightarrow #mu#mu","f");
legend_InvMass->AddEntry(hWW_InvMass,"WW","f");
legend_InvMass->AddEntry(hWZ_InvMass,"WZ","f");
legend_InvMass->AddEntry(hZZ_InvMass,"ZZ","f");
legend_InvMass->AddEntry(hDat_InvMass,"Data","p");
legend_InvMass->SetFillColor(0);
hDat_InvMass->SetXTitle("mass [GeV/c^{2}]");
hDat_InvMass->SetYTitle("Entries");
cs_InvMass->cd(1); hll_InvMass->Draw("hist eX0"); cs_InvMass->Update(); hs_InvMass->Draw("same hist eX0"); cs_InvMass->Update(); hDat_InvMass->Draw("same  eX0");
// cs->cd(1);  hs_InvMass->Draw(" hist"); cs->Update(); hDat_InvMass->Draw("hist same");
legend_InvMass->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_InvMassLoose->GetMaximum();
m2 = hll_InvMassLoose->GetMaximum();
m3 = hs_InvMassLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_InvMassLoose->SetMaximum(2*mMax);
TCanvas *cs_InvMassLoose = new TCanvas("cs_InvMassLoose","cs_InvMassLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_InvMassLoose->SetTitle("InvMassLoose");
auto legend_InvMassLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_InvMassLoose->AddEntry(hDY_InvMassLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_InvMassLoose->AddEntry(hWW_InvMassLoose,"WW","f");
legend_InvMassLoose->AddEntry(hWZ_InvMassLoose,"WZ","f");
legend_InvMassLoose->AddEntry(hZZ_InvMassLoose,"ZZ","f");
legend_InvMassLoose->AddEntry(hDat_InvMassLoose,"Data","p");
legend_InvMassLoose->SetFillColor(0);
hDat_InvMassLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_InvMassLoose->SetYTitle("Entries");
cs_InvMassLoose->cd(1); hll_InvMassLoose->Draw("hist eX0"); cs_InvMassLoose->Update(); hs_InvMassLoose->Draw("same hist eX0"); cs_InvMassLoose->Update(); hDat_InvMassLoose->Draw("same  eX0");
// cs->cd(1);  hs_InvMassLoose->Draw(" hist"); cs->Update(); hDat_InvMassLoose->Draw("hist same");
legend_InvMassLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_InvMassLW->GetMaximum();
m2 = hll_InvMassLW->GetMaximum();
m3 = hs_InvMassLW->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_InvMassLW->SetMaximum(2*mMax);
TCanvas *cs_InvMassLW = new TCanvas("cs_InvMassLW","cs_InvMassLW",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_InvMassLW->SetTitle("InvMassLW");
auto legend_InvMassLW = new TLegend(0.5,0.7,0.9,0.9);
legend_InvMassLW->AddEntry(hDY_InvMassLW,"Z/#gamma*#rightarrow #mu#mu","f");
legend_InvMassLW->AddEntry(hWW_InvMassLW,"WW","f");
legend_InvMassLW->AddEntry(hWZ_InvMassLW,"WZ","f");
legend_InvMassLW->AddEntry(hZZ_InvMassLW,"ZZ","f");
legend_InvMassLW->AddEntry(hDat_InvMassLW,"Data","p");
legend_InvMassLW->SetFillColor(0);
hDat_InvMassLW->SetXTitle("mass [GeV/c^{2}]");
hDat_InvMassLW->SetYTitle("Entries");
cs_InvMassLW->cd(1); hll_InvMassLW->Draw("hist eX0"); cs_InvMassLW->Update(); hs_InvMassLW->Draw("same hist eX0"); cs_InvMassLW->Update(); hDat_InvMassLW->Draw("same  eX0");
// cs->cd(1);  hs_InvMassLW->Draw(" hist"); cs->Update(); hDat_InvMassLW->Draw("hist same");
legend_InvMassLW->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_d0_err->GetMaximum();
m2 = hll_d0_err->GetMaximum();
m3 = hs_d0_err->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_d0_err->SetMaximum(2*mMax);
TCanvas *cs_d0_err = new TCanvas("cs_d0_err","cs_d0_err",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_d0_err->SetTitle("d0_err");
auto legend_d0_err = new TLegend(0.5,0.7,0.9,0.9);
legend_d0_err->AddEntry(hDY_d0_err,"Z/#gamma*#rightarrow #mu#mu","f");
legend_d0_err->AddEntry(hWW_d0_err,"WW","f");
legend_d0_err->AddEntry(hWZ_d0_err,"WZ","f");
legend_d0_err->AddEntry(hZZ_d0_err,"ZZ","f");
legend_d0_err->AddEntry(hDat_d0_err,"Data","p");
legend_d0_err->SetFillColor(0);
hDat_d0_err->SetXTitle("mass [GeV/c^{2}]");
hDat_d0_err->SetYTitle("Entries");
cs_d0_err->cd(1); hll_d0_err->Draw("hist eX0"); cs_d0_err->Update(); hs_d0_err->Draw("same hist eX0"); cs_d0_err->Update(); hDat_d0_err->Draw("same  eX0");
// cs->cd(1);  hs_d0_err->Draw(" hist"); cs->Update(); hDat_d0_err->Draw("hist same");
legend_d0_err->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_d0_errLoose->GetMaximum();
m2 = hll_d0_errLoose->GetMaximum();
m3 = hs_d0_errLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_d0_errLoose->SetMaximum(2*mMax);
TCanvas *cs_d0_errLoose = new TCanvas("cs_d0_errLoose","cs_d0_errLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_d0_errLoose->SetTitle("d0_errLoose");
auto legend_d0_errLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_d0_errLoose->AddEntry(hDY_d0_errLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_d0_errLoose->AddEntry(hWW_d0_errLoose,"WW","f");
legend_d0_errLoose->AddEntry(hWZ_d0_errLoose,"WZ","f");
legend_d0_errLoose->AddEntry(hZZ_d0_errLoose,"ZZ","f");
legend_d0_errLoose->AddEntry(hDat_d0_errLoose,"Data","p");
legend_d0_errLoose->SetFillColor(0);
hDat_d0_errLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_d0_errLoose->SetYTitle("Entries");
cs_d0_errLoose->cd(1); hll_d0_errLoose->Draw("hist eX0"); cs_d0_errLoose->Update(); hs_d0_errLoose->Draw("same hist eX0"); cs_d0_errLoose->Update(); hDat_d0_errLoose->Draw("same  eX0");
// cs->cd(1);  hs_d0_errLoose->Draw(" hist"); cs->Update(); hDat_d0_errLoose->Draw("hist same");
legend_d0_errLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_dxy_err->GetMaximum();
m2 = hll_dxy_err->GetMaximum();
m3 = hs_dxy_err->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_dxy_err->SetMaximum(2*mMax);
TCanvas *cs_dxy_err = new TCanvas("cs_dxy_err","cs_dxy_err",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_dxy_err->SetTitle("dxy_err");
auto legend_dxy_err = new TLegend(0.5,0.7,0.9,0.9);
legend_dxy_err->AddEntry(hDY_dxy_err,"Z/#gamma*#rightarrow #mu#mu","f");
legend_dxy_err->AddEntry(hWW_dxy_err,"WW","f");
legend_dxy_err->AddEntry(hWZ_dxy_err,"WZ","f");
legend_dxy_err->AddEntry(hZZ_dxy_err,"ZZ","f");
legend_dxy_err->AddEntry(hDat_dxy_err,"Data","p");
legend_dxy_err->SetFillColor(0);
hDat_dxy_err->SetXTitle("mass [GeV/c^{2}]");
hDat_dxy_err->SetYTitle("Entries");
cs_dxy_err->cd(1); hll_dxy_err->Draw("hist eX0"); cs_dxy_err->Update(); hs_dxy_err->Draw("same hist eX0"); cs_dxy_err->Update(); hDat_dxy_err->Draw("same  eX0");
// cs->cd(1);  hs_dxy_err->Draw(" hist"); cs->Update(); hDat_dxy_err->Draw("hist same");
legend_dxy_err->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_dxy_errLoose->GetMaximum();
m2 = hll_dxy_errLoose->GetMaximum();
m3 = hs_dxy_errLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_dxy_errLoose->SetMaximum(2*mMax);
TCanvas *cs_dxy_errLoose = new TCanvas("cs_dxy_errLoose","cs_dxy_errLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_dxy_errLoose->SetTitle("dxy_errLoose");
auto legend_dxy_errLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_dxy_errLoose->AddEntry(hDY_dxy_errLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_dxy_errLoose->AddEntry(hWW_dxy_errLoose,"WW","f");
legend_dxy_errLoose->AddEntry(hWZ_dxy_errLoose,"WZ","f");
legend_dxy_errLoose->AddEntry(hZZ_dxy_errLoose,"ZZ","f");
legend_dxy_errLoose->AddEntry(hDat_dxy_errLoose,"Data","p");
legend_dxy_errLoose->SetFillColor(0);
hDat_dxy_errLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_dxy_errLoose->SetYTitle("Entries");
cs_dxy_errLoose->cd(1); hll_dxy_errLoose->Draw("hist eX0"); cs_dxy_errLoose->Update(); hs_dxy_errLoose->Draw("same hist eX0"); cs_dxy_errLoose->Update(); hDat_dxy_errLoose->Draw("same  eX0");
// cs->cd(1);  hs_dxy_errLoose->Draw(" hist"); cs->Update(); hDat_dxy_errLoose->Draw("hist same");
legend_dxy_errLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_cos->GetMaximum();
m2 = hll_cos->GetMaximum();
m3 = hs_cos->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_cos->SetMaximum(2*mMax);
TCanvas *cs_cos = new TCanvas("cs_cos","cs_cos",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_cos->SetTitle("cos");
auto legend_cos = new TLegend(0.5,0.7,0.9,0.9);
legend_cos->AddEntry(hDY_cos,"Z/#gamma*#rightarrow #mu#mu","f");
legend_cos->AddEntry(hWW_cos,"WW","f");
legend_cos->AddEntry(hWZ_cos,"WZ","f");
legend_cos->AddEntry(hZZ_cos,"ZZ","f");
legend_cos->AddEntry(hDat_cos,"Data","p");
legend_cos->SetFillColor(0);
hDat_cos->SetXTitle("mass [GeV/c^{2}]");
hDat_cos->SetYTitle("Entries");
cs_cos->cd(1); hll_cos->Draw("hist eX0"); cs_cos->Update(); hs_cos->Draw("same hist eX0"); cs_cos->Update(); hDat_cos->Draw("same  eX0");
// cs->cd(1);  hs_cos->Draw(" hist"); cs->Update(); hDat_cos->Draw("hist same");
legend_cos->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_cosLoose->GetMaximum();
m2 = hll_cosLoose->GetMaximum();
m3 = hs_cosLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_cosLoose->SetMaximum(2*mMax);
TCanvas *cs_cosLoose = new TCanvas("cs_cosLoose","cs_cosLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_cosLoose->SetTitle("cosLoose");
auto legend_cosLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_cosLoose->AddEntry(hDY_cosLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_cosLoose->AddEntry(hWW_cosLoose,"WW","f");
legend_cosLoose->AddEntry(hWZ_cosLoose,"WZ","f");
legend_cosLoose->AddEntry(hZZ_cosLoose,"ZZ","f");
legend_cosLoose->AddEntry(hDat_cosLoose,"Data","p");
legend_cosLoose->SetFillColor(0);
hDat_cosLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_cosLoose->SetYTitle("Entries");
cs_cosLoose->cd(1); hll_cosLoose->Draw("hist eX0"); cs_cosLoose->Update(); hs_cosLoose->Draw("same hist eX0"); cs_cosLoose->Update(); hDat_cosLoose->Draw("same  eX0");
// cs->cd(1);  hs_cosLoose->Draw(" hist"); cs->Update(); hDat_cosLoose->Draw("hist same");
legend_cosLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_delPhi->GetMaximum();
m2 = hll_delPhi->GetMaximum();
m3 = hs_delPhi->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_delPhi->SetMaximum(2*mMax);
TCanvas *cs_delPhi = new TCanvas("cs_delPhi","cs_delPhi",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_delPhi->SetTitle("delPhi");
auto legend_delPhi = new TLegend(0.5,0.7,0.9,0.9);
legend_delPhi->AddEntry(hDY_delPhi,"Z/#gamma*#rightarrow #mu#mu","f");
legend_delPhi->AddEntry(hWW_delPhi,"WW","f");
legend_delPhi->AddEntry(hWZ_delPhi,"WZ","f");
legend_delPhi->AddEntry(hZZ_delPhi,"ZZ","f");
legend_delPhi->AddEntry(hDat_delPhi,"Data","p");
legend_delPhi->SetFillColor(0);
hDat_delPhi->SetXTitle("mass [GeV/c^{2}]");
hDat_delPhi->SetYTitle("Entries");
cs_delPhi->cd(1); hll_delPhi->Draw("hist eX0"); cs_delPhi->Update(); hs_delPhi->Draw("same hist eX0"); cs_delPhi->Update(); hDat_delPhi->Draw("same  eX0");
// cs->cd(1);  hs_delPhi->Draw(" hist"); cs->Update(); hDat_delPhi->Draw("hist same");
legend_delPhi->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_delPhiLoose->GetMaximum();
m2 = hll_delPhiLoose->GetMaximum();
m3 = hs_delPhiLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_delPhiLoose->SetMaximum(2*mMax);
TCanvas *cs_delPhiLoose = new TCanvas("cs_delPhiLoose","cs_delPhiLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_delPhiLoose->SetTitle("delPhiLoose");
auto legend_delPhiLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_delPhiLoose->AddEntry(hDY_delPhiLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_delPhiLoose->AddEntry(hWW_delPhiLoose,"WW","f");
legend_delPhiLoose->AddEntry(hWZ_delPhiLoose,"WZ","f");
legend_delPhiLoose->AddEntry(hZZ_delPhiLoose,"ZZ","f");
legend_delPhiLoose->AddEntry(hDat_delPhiLoose,"Data","p");
legend_delPhiLoose->SetFillColor(0);
hDat_delPhiLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_delPhiLoose->SetYTitle("Entries");
cs_delPhiLoose->cd(1); hll_delPhiLoose->Draw("hist eX0"); cs_delPhiLoose->Update(); hs_delPhiLoose->Draw("same hist eX0"); cs_delPhiLoose->Update(); hDat_delPhiLoose->Draw("same  eX0");
// cs->cd(1);  hs_delPhiLoose->Draw(" hist"); cs->Update(); hDat_delPhiLoose->Draw("hist same");
legend_delPhiLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_conePt->GetMaximum();
m2 = hll_conePt->GetMaximum();
m3 = hs_conePt->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_conePt->SetMaximum(2*mMax);
TCanvas *cs_conePt = new TCanvas("cs_conePt","cs_conePt",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_conePt->SetTitle("conePt");
auto legend_conePt = new TLegend(0.5,0.7,0.9,0.9);
legend_conePt->AddEntry(hDY_conePt,"Z/#gamma*#rightarrow #mu#mu","f");
legend_conePt->AddEntry(hWW_conePt,"WW","f");
legend_conePt->AddEntry(hWZ_conePt,"WZ","f");
legend_conePt->AddEntry(hZZ_conePt,"ZZ","f");
legend_conePt->AddEntry(hDat_conePt,"Data","p");
legend_conePt->SetFillColor(0);
hDat_conePt->SetXTitle("mass [GeV/c^{2}]");
hDat_conePt->SetYTitle("Entries");
cs_conePt->cd(1); hll_conePt->Draw("hist eX0"); cs_conePt->Update(); hs_conePt->Draw("same hist eX0"); cs_conePt->Update(); hDat_conePt->Draw("same  eX0");
// cs->cd(1);  hs_conePt->Draw(" hist"); cs->Update(); hDat_conePt->Draw("hist same");
legend_conePt->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_chi2_NDF->GetMaximum();
m2 = hll_chi2_NDF->GetMaximum();
m3 = hs_chi2_NDF->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_chi2_NDF->SetMaximum(2*mMax);
TCanvas *cs_chi2_NDF = new TCanvas("cs_chi2_NDF","cs_chi2_NDF",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_chi2_NDF->SetTitle("chi2_NDF");
auto legend_chi2_NDF = new TLegend(0.5,0.7,0.9,0.9);
legend_chi2_NDF->AddEntry(hDY_chi2_NDF,"Z/#gamma*#rightarrow #mu#mu","f");
legend_chi2_NDF->AddEntry(hWW_chi2_NDF,"WW","f");
legend_chi2_NDF->AddEntry(hWZ_chi2_NDF,"WZ","f");
legend_chi2_NDF->AddEntry(hZZ_chi2_NDF,"ZZ","f");
legend_chi2_NDF->AddEntry(hDat_chi2_NDF,"Data","p");
legend_chi2_NDF->SetFillColor(0);
hDat_chi2_NDF->SetXTitle("mass [GeV/c^{2}]");
hDat_chi2_NDF->SetYTitle("Entries");
cs_chi2_NDF->cd(1); hll_chi2_NDF->Draw("hist eX0"); cs_chi2_NDF->Update(); hs_chi2_NDF->Draw("same hist eX0"); cs_chi2_NDF->Update(); hDat_chi2_NDF->Draw("same  eX0");
// cs->cd(1);  hs_chi2_NDF->Draw(" hist"); cs->Update(); hDat_chi2_NDF->Draw("hist same");
legend_chi2_NDF->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_chi2_NDF->GetMaximum();
m2 = hll_chi2_NDF->GetMaximum();
m3 = hs_chi2_NDF->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_chi2_NDF->SetMaximum(2*mMax);
TCanvas *cs_chi2_NDF = new TCanvas("cs_chi2_NDF","cs_chi2_NDF",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_chi2_NDF->SetTitle("chi2_NDF");
auto legend_chi2_NDF = new TLegend(0.5,0.7,0.9,0.9);
legend_chi2_NDF->AddEntry(hDY_chi2_NDF,"Z/#gamma*#rightarrow #mu#mu","f");
legend_chi2_NDF->AddEntry(hWW_chi2_NDF,"WW","f");
legend_chi2_NDF->AddEntry(hWZ_chi2_NDF,"WZ","f");
legend_chi2_NDF->AddEntry(hZZ_chi2_NDF,"ZZ","f");
legend_chi2_NDF->AddEntry(hDat_chi2_NDF,"Data","p");
legend_chi2_NDF->SetFillColor(0);
hDat_chi2_NDF->SetXTitle("mass [GeV/c^{2}]");
hDat_chi2_NDF->SetYTitle("Entries");
cs_chi2_NDF->cd(1); hll_chi2_NDF->Draw("hist eX0"); cs_chi2_NDF->Update(); hs_chi2_NDF->Draw("same hist eX0"); cs_chi2_NDF->Update(); hDat_chi2_NDF->Draw("same  eX0");
// cs->cd(1);  hs_chi2_NDF->Draw(" hist"); cs->Update(); hDat_chi2_NDF->Draw("hist same");
legend_chi2_NDF->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_chi2_NDFLoose->GetMaximum();
m2 = hll_chi2_NDFLoose->GetMaximum();
m3 = hs_chi2_NDFLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_chi2_NDFLoose->SetMaximum(2*mMax);
TCanvas *cs_chi2_NDFLoose = new TCanvas("cs_chi2_NDFLoose","cs_chi2_NDFLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_chi2_NDFLoose->SetTitle("chi2_NDFLoose");
auto legend_chi2_NDFLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_chi2_NDFLoose->AddEntry(hDY_chi2_NDFLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_chi2_NDFLoose->AddEntry(hWW_chi2_NDFLoose,"WW","f");
legend_chi2_NDFLoose->AddEntry(hWZ_chi2_NDFLoose,"WZ","f");
legend_chi2_NDFLoose->AddEntry(hZZ_chi2_NDFLoose,"ZZ","f");
legend_chi2_NDFLoose->AddEntry(hDat_chi2_NDFLoose,"Data","p");
legend_chi2_NDFLoose->SetFillColor(0);
hDat_chi2_NDFLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_chi2_NDFLoose->SetYTitle("Entries");
cs_chi2_NDFLoose->cd(1); hll_chi2_NDFLoose->Draw("hist eX0"); cs_chi2_NDFLoose->Update(); hs_chi2_NDFLoose->Draw("same hist eX0"); cs_chi2_NDFLoose->Update(); hDat_chi2_NDFLoose->Draw("same  eX0");
// cs->cd(1);  hs_chi2_NDFLoose->Draw(" hist"); cs->Update(); hDat_chi2_NDFLoose->Draw("hist same");
legend_chi2_NDFLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_numHitsLoose->GetMaximum();
m2 = hll_numHitsLoose->GetMaximum();
m3 = hs_numHitsLoose->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_numHitsLoose->SetMaximum(2*mMax);
TCanvas *cs_numHitsLoose = new TCanvas("cs_numHitsLoose","cs_numHitsLoose",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_numHitsLoose->SetTitle("numHitsLoose");
auto legend_numHitsLoose = new TLegend(0.5,0.7,0.9,0.9);
legend_numHitsLoose->AddEntry(hDY_numHitsLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_numHitsLoose->AddEntry(hWW_numHitsLoose,"WW","f");
legend_numHitsLoose->AddEntry(hWZ_numHitsLoose,"WZ","f");
legend_numHitsLoose->AddEntry(hZZ_numHitsLoose,"ZZ","f");
legend_numHitsLoose->AddEntry(hDat_numHitsLoose,"Data","p");
legend_numHitsLoose->SetFillColor(0);
hDat_numHitsLoose->SetXTitle("mass [GeV/c^{2}]");
hDat_numHitsLoose->SetYTitle("Entries");
cs_numHitsLoose->cd(1); hll_numHitsLoose->Draw("hist eX0"); cs_numHitsLoose->Update(); hs_numHitsLoose->Draw("same hist eX0"); cs_numHitsLoose->Update(); hDat_numHitsLoose->Draw("same  eX0");
// cs->cd(1);  hs_numHitsLoose->Draw(" hist"); cs->Update(); hDat_numHitsLoose->Draw("hist same");
legend_numHitsLoose->Draw();
gPad->Update();
gPad->SetLogy(1);


m1 = hDat_h_dot->GetMaximum();
m2 = hll_h_dot->GetMaximum();
m3 = hs_h_dot->GetMaximum();
mMax = m1;
if (mMax<m2)
{
mMax = m2;
}
if(mMax < m3)
{
mMax = m3;
}
hll_h_dot->SetMaximum(2*mMax);
TCanvas *cs_h_dot = new TCanvas("cs_h_dot","cs_h_dot",10,10,700,900);
TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_h_dot->SetTitle("h_dot");
auto legend_h_dot = new TLegend(0.5,0.7,0.9,0.9);
legend_h_dot->AddEntry(hDY_h_dot,"Z/#gamma*#rightarrow #mu#mu","f");
legend_h_dot->AddEntry(hWW_h_dot,"WW","f");
legend_h_dot->AddEntry(hWZ_h_dot,"WZ","f");
legend_h_dot->AddEntry(hZZ_h_dot,"ZZ","f");
legend_h_dot->AddEntry(hDat_h_dot,"Data","p");
legend_h_dot->SetFillColor(0);
hDat_h_dot->SetXTitle("mass [GeV/c^{2}]");
hDat_h_dot->SetYTitle("Entries");
cs_h_dot->cd(1); hll_h_dot->Draw("hist eX0"); cs_h_dot->Update(); hs_h_dot->Draw("same hist eX0"); cs_h_dot->Update(); hDat_h_dot->Draw("same  eX0");
// cs->cd(1);  hs_h_dot->Draw(" hist"); cs->Update(); hDat_h_dot->Draw("hist same");
legend_h_dot->Draw();
gPad->Update();
gPad->SetLogy(1);


 
 }
