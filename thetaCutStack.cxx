{

THStack *hs_thetaCut = new THStack("hs_thetaCut", "");


double lumi = 2333;  //   1/pb


TFile *fZZ = new TFile("ZZM.root");
TFile *fWZ = new TFile("WZM.root");
TFile *fWW = new TFile("WWM.root");
TFile *fDY = new TFile("DYM.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lw5.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_thetaCut= (TH1F*)fZZ->Get("thetaCut");
TH1F * hWZ_thetaCut= (TH1F*)fWZ->Get("thetaCut");
TH1F * hWW_thetaCut= (TH1F*)fWW->Get("thetaCut");
TH1F * hDY_thetaCut= (TH1F*)fDY->Get("thetaCut");
TH1F * hll_thetaCut= (TH1F*)fll->Get("thetaCut");
TH1F * hlw_thetaCut= (TH1F*)flw->Get("thetaLwCut");
TH1F * hDat_thetaCut= (TH1F*)fDat->Get("thetaCut"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_thetaCut->SetLineColor(1);
hll_thetaCut->SetLineColor(1);
hZZ_thetaCut->SetLineColor(1);
hWW_thetaCut->SetLineColor(1);
hWZ_thetaCut->SetLineColor(1);
hDY_thetaCut->SetLineColor(1);

hlw_thetaCut->SetFillColor(7);
hll_thetaCut->SetFillColor(2);
hZZ_thetaCut->SetFillColor(3);
hWW_thetaCut->SetFillColor(4);
hWZ_thetaCut->SetFillColor(5);
hDY_thetaCut->SetFillColor(6);


double ZZ_thetaCut_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_thetaCut->Scale(ZZ_thetaCut_scale);
double WZ_thetaCut_scale = lumi*0.868/(hWZ_nEvents->Integral());
hWZ_thetaCut->Scale(WZ_thetaCut_scale);
double WW_thetaCut_scale = lumi*42/(hWW_nEvents->Integral());
hWW_thetaCut->Scale(WW_thetaCut_scale);
double DY_thetaCut_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_thetaCut->Scale(DY_thetaCut_scale);
double ll_thetaCut_scale = lumi*1/(4000);
hll_thetaCut->Scale(ll_thetaCut_scale);
hlw_thetaCut->Scale(ll_thetaCut_scale);

hs_thetaCut->Add(hlw_thetaCut);
hs_thetaCut->Add(hll_thetaCut);
hs_thetaCut->Add(hZZ_thetaCut);
hs_thetaCut->Add(hWZ_thetaCut);
hs_thetaCut->Add(hWW_thetaCut);
hs_thetaCut->Add(hDY_thetaCut);



hZZ_thetaCut->Sumw2();
hWZ_thetaCut->Sumw2();
hWW_thetaCut->Sumw2();
hDY_thetaCut->Sumw2();
hll_thetaCut->Sumw2();
hlw_thetaCut->Sumw2();


TCanvas *cs_thetaCut = new TCanvas("cs_thetaCut","cs_thetaCut",10,10,700,700);
cs_thetaCut->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_thetaCut->SetTitle("");
auto legend_thetaCut = new TLegend(0.5,0.7,0.9,0.9);


// legend stuff
legend_thetaCut->AddEntry(hlw_thetaCut," Lee-Wick H(1000)#rightarrow XX(350), 1 pb","f");
legend_thetaCut->AddEntry(hll_thetaCut,"H(1000)#rightarrow XX(350), 1 pb","f");
legend_thetaCut->AddEntry(hDY_thetaCut,"Z/#gamma*#rightarrow #mu#mu","f");
legend_thetaCut->AddEntry(hWW_thetaCut,"WW","f");
legend_thetaCut->AddEntry(hWZ_thetaCut,"WZ","f");
legend_thetaCut->AddEntry(hZZ_thetaCut,"ZZ","f");
legend_thetaCut->SetFillColor(0);
legend_thetaCut->SetFillStyle(0);
legend_thetaCut->SetBorderSize(0);



hs_thetaCut->Draw(" hist eX0"); 
hs_thetaCut->GetXaxis()->SetTitle(" #theta");
hs_thetaCut->GetYaxis()->SetTitleOffset(1.5);
hs_thetaCut->GetYaxis()->SetTitle("Eventos");
cs_thetaCut->Update(); 

legend_thetaCut->Draw();
gPad->Update();
gPad->SetLogy(1);
 

}
