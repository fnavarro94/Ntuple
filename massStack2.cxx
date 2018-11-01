{

THStack *hs_InvMassLoose = new THStack("hs_InvMassLoose", "");


double lumi = 2*2333;  //   1/pb


TFile *fZZ = new TFile("ZZE2G.root");
TFile *fWZ = new TFile("WWE2G.root");
TFile *fWW = new TFile("WZE2G.root");
TFile *fDY = new TFile("DYE2G.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lwE.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_InvMassLoose= (TH1F*)fZZ->Get("InvMassLoose");
TH1F * hWZ_InvMassLoose= (TH1F*)fWZ->Get("InvMassLoose");
TH1F * hWW_InvMassLoose= (TH1F*)fWW->Get("InvMassLoose");
TH1F * hDY_InvMassLoose= (TH1F*)fDY->Get("InvMassLoose");
TH1F * hll_InvMassLoose= (TH1F*)fll->Get("InvMassLoose");
TH1F * hlw_InvMassLoose= (TH1F*)flw->Get("InvMassLoose");
TH1F * hDat_InvMassLoose= (TH1F*)fDat->Get("InvMassLoose"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_InvMassLoose->SetLineColor(2);
hll_InvMassLoose->SetLineColor(1);
hZZ_InvMassLoose->SetLineColor(1);
hWW_InvMassLoose->SetLineColor(1);
hWZ_InvMassLoose->SetLineColor(1);
hDY_InvMassLoose->SetLineColor(1);

hlw_InvMassLoose->SetFillColor(2);
hll_InvMassLoose->SetFillColor(2);
hZZ_InvMassLoose->SetFillColor(46);
hWW_InvMassLoose->SetFillColor(8);
hWZ_InvMassLoose->SetFillColor(41);
hDY_InvMassLoose->SetFillColor(9);


double ZZ_InvMassLoose_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_InvMassLoose->Scale(ZZ_InvMassLoose_scale);
double WZ_InvMassLoose_scale = lumi*0.868/(hWZ_nEvents->Integral());
hWZ_InvMassLoose->Scale(WZ_InvMassLoose_scale);
double WW_InvMassLoose_scale = lumi*42/(hWW_nEvents->Integral());
hWW_InvMassLoose->Scale(WW_InvMassLoose_scale);
double DY_InvMassLoose_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_InvMassLoose->Scale(DY_InvMassLoose_scale);
double ll_InvMassLoose_scale = lumi*1/(4000);
hll_InvMassLoose->Scale(ll_InvMassLoose_scale);
hlw_InvMassLoose->Scale(0.066*ll_InvMassLoose_scale);

//hs_InvMassLoose->Add(hlw_InvMassLoose);
//hs_InvMassLoose->Add(hll_InvMassLoose);
hs_InvMassLoose->Add(hZZ_InvMassLoose);
hs_InvMassLoose->Add(hWZ_InvMassLoose);
hs_InvMassLoose->Add(hWW_InvMassLoose);
hs_InvMassLoose->Add(hDY_InvMassLoose);



hZZ_InvMassLoose->Sumw2();
hWZ_InvMassLoose->Sumw2();
hWW_InvMassLoose->Sumw2();
hDY_InvMassLoose->Sumw2();
hll_InvMassLoose->Sumw2();
hlw_InvMassLoose->Sumw2();


TCanvas *cs_InvMassLoose = new TCanvas("cs_InvMassLoose","cs_InvMassLoose",10,10,700,700);
cs_InvMassLoose->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_InvMassLoose->SetTitle("");
auto legend_InvMassLoose = new TLegend(0.5,0.7,0.9,0.9);


hDat_InvMassLoose->SetMarkerStyle(21);
hDat_InvMassLoose->SetMarkerSize(1);
hDat_InvMassLoose->SetLineColor(1);
// legend stuff
legend_InvMassLoose->AddEntry(hlw_InvMassLoose," Lee-Wick H(1000)#rightarrow XX(350), 66 fb","l");
//legend_InvMassLoose->AddEntry(hll_InvMassLoose,"H(1000)#rightarrow XX(350), 1 pb","f");
//legend_InvMassLoose->AddEntry(hDY_InvMassLoose,"Z/#gamma*#rightarrow #mu#mu","f");
legend_InvMassLoose->AddEntry(hDY_InvMassLoose,"Z/#gamma*#rightarrow #ee","f");
legend_InvMassLoose->AddEntry(hWW_InvMassLoose,"WW","f");
legend_InvMassLoose->AddEntry(hWZ_InvMassLoose,"WZ","f");
legend_InvMassLoose->AddEntry(hZZ_InvMassLoose,"ZZ","f");
legend_InvMassLoose->AddEntry(hDat_InvMassLoose,"Datos","p");
legend_InvMassLoose->SetFillColor(0);
legend_InvMassLoose->SetFillStyle(0);
legend_InvMassLoose->SetBorderSize(0);

hs_InvMassLoose->SetMaximum(hs_InvMassLoose->GetMaximum()*2);
hs_InvMassLoose->SetMinimum(0.1);
hlw_InvMassLoose->SetTitle("");

hlw_InvMassLoose->SetStats(0);
hs_InvMassLoose->Draw("hist eX0");
hlw_InvMassLoose->Draw("same hist");
cs_InvMassLoose->Update(); 
//hDat_InvMassLoose->Draw("same hist eX0");

hs_InvMassLoose->GetXaxis()->SetTitle("M_{ee} [GeV/c]");
hs_InvMassLoose->GetYaxis()->SetTitleOffset(1.5);
hs_InvMassLoose->GetYaxis()->SetTitle("Eventos");
cs_InvMassLoose->Update(); 

legend_InvMassLoose->Draw();
gPad->Update();
gPad->SetLogy(1);
 

}
