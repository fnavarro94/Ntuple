{

THStack *hs_theta = new THStack("hs_theta", "");


double lumi = 2333;  //   1/pb


TFile *fZZ = new TFile("ZZM.root");
TFile *fWZ = new TFile("WZM.root");
TFile *fWW = new TFile("WWM.root");
TFile *fDY = new TFile("DYM.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lw5.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_theta= (TH1F*)fZZ->Get("theta");
TH1F * hWZ_theta= (TH1F*)fWZ->Get("theta");
TH1F * hWW_theta= (TH1F*)fWW->Get("theta");
TH1F * hDY_theta= (TH1F*)fDY->Get("theta");
TH1F * hll_theta= (TH1F*)fll->Get("theta");
TH1F * hlw_theta= (TH1F*)flw->Get("thetaLw");
TH1F * hDat_theta= (TH1F*)fDat->Get("theta"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_theta->SetLineColor(1);
hll_theta->SetLineColor(1);
hZZ_theta->SetLineColor(1);
hWW_theta->SetLineColor(1);
hWZ_theta->SetLineColor(1);
hDY_theta->SetLineColor(1);

hlw_theta->SetFillColor(7);
hll_theta->SetFillColor(2);
hZZ_theta->SetFillColor(3);
hWW_theta->SetFillColor(4);
hWZ_theta->SetFillColor(5);
hDY_theta->SetFillColor(6);


double ZZ_theta_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_theta->Scale(ZZ_theta_scale);
double WZ_theta_scale = lumi*0.868/(hWZ_nEvents->Integral());
hWZ_theta->Scale(WZ_theta_scale);
double WW_theta_scale = lumi*42/(hWW_nEvents->Integral());
hWW_theta->Scale(WW_theta_scale);
double DY_theta_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_theta->Scale(DY_theta_scale);
double ll_theta_scale = lumi*1/(4000);
hll_theta->Scale(ll_theta_scale);
hlw_theta->Scale(ll_theta_scale);

hs_theta->Add(hlw_theta);
hs_theta->Add(hll_theta);
hs_theta->Add(hZZ_theta);
hs_theta->Add(hWZ_theta);
hs_theta->Add(hWW_theta);
hs_theta->Add(hDY_theta);



hZZ_theta->Sumw2();
hWZ_theta->Sumw2();
hWW_theta->Sumw2();
hDY_theta->Sumw2();
hll_theta->Sumw2();
hlw_theta->Sumw2();


TCanvas *cs_theta = new TCanvas("cs_theta","cs_theta",10,10,700,700);
cs_theta->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_theta->SetTitle("");
auto legend_theta = new TLegend(0.5,0.7,0.9,0.9);


// legend stuff
legend_theta->AddEntry(hlw_theta," Lee-Wick H(1000)#rightarrow XX(350), 1 pb","f");
legend_theta->AddEntry(hll_theta,"H(1000)#rightarrow XX(350), 1 pb","f");
legend_theta->AddEntry(hDY_theta,"Z/#gamma*#rightarrow #mu#mu","f");
legend_theta->AddEntry(hWW_theta,"WW","f");
legend_theta->AddEntry(hWZ_theta,"WZ","f");
legend_theta->AddEntry(hZZ_theta,"ZZ","f");
legend_theta->SetFillColor(0);
legend_theta->SetFillStyle(0);
legend_theta->SetBorderSize(0);



hs_theta->Draw(" hist eX0"); 
hs_theta->GetXaxis()->SetTitle("#theta");
hs_theta->GetYaxis()->SetTitleOffset(1.5);
hs_theta->GetYaxis()->SetTitle("Eventos");
cs_theta->Update(); 

legend_theta->Draw();
gPad->Update();
gPad->SetLogy(1);
 

}
