{

THStack *hs_InvMassDPCut60 = new THStack("hs_InvMassDPCut60", "");


double lumi = 2*2333;  //   1/pb


TFile *fZZ = new TFile("ZZM.root");
TFile *fWZ = new TFile("WWM.root");
TFile *fWW = new TFile("WZM.root");
TFile *fDY = new TFile("DYM.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lw5.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_InvMassDPCut60= (TH1F*)fZZ->Get("InvMassDPCut190");
TH1F * hWZ_InvMassDPCut60= (TH1F*)fWZ->Get("InvMassDPCut190");
TH1F * hWW_InvMassDPCut60= (TH1F*)fWW->Get("InvMassDPCut190");
TH1F * hDY_InvMassDPCut60= (TH1F*)fDY->Get("InvMassDPCut190");
TH1F * hll_InvMassDPCut60= (TH1F*)fll->Get("InvMassDPCut190");
TH1F * hlw_InvMassDPCut60= (TH1F*)flw->Get("InvMassDPCutLw190");
TH1F * hDat_InvMassDPCut60= (TH1F*)fDat->Get("InvMassDPCut190"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_InvMassDPCut60->SetLineColor(2);
hll_InvMassDPCut60->SetLineColor(1);
hZZ_InvMassDPCut60->SetLineColor(1);
hWW_InvMassDPCut60->SetLineColor(1);
hWZ_InvMassDPCut60->SetLineColor(1);
hDY_InvMassDPCut60->SetLineColor(1);

hlw_InvMassDPCut60->SetFillColor(2);
hll_InvMassDPCut60->SetFillColor(2);
hZZ_InvMassDPCut60->SetFillColor(46);
hWW_InvMassDPCut60->SetFillColor(8);
hWZ_InvMassDPCut60->SetFillColor(41);
hDY_InvMassDPCut60->SetFillColor(9);



double ZZ_InvMassDPCut60_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_InvMassDPCut60->Scale(ZZ_InvMassDPCut60_scale);
double WZ_InvMassDPCut60_scale = lumi*0.868/(hWZ_nEvents->Integral());
hWZ_InvMassDPCut60->Scale(WZ_InvMassDPCut60_scale);
double WW_InvMassDPCut60_scale = lumi*42/(hWW_nEvents->Integral());
hWW_InvMassDPCut60->Scale(WW_InvMassDPCut60_scale);
double DY_InvMassDPCut60_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_InvMassDPCut60->Scale(DY_InvMassDPCut60_scale);
double ll_InvMassDPCut60_scale = lumi*1/(4000);
hll_InvMassDPCut60->Scale(ll_InvMassDPCut60_scale);
hlw_InvMassDPCut60->Scale(0.066*ll_InvMassDPCut60_scale);

//hs_InvMassDPCut60->Add(hlw_InvMassDPCut60);
//hs_InvMassDPCut60->Add(hll_InvMassDPCut60);
hs_InvMassDPCut60->Add(hZZ_InvMassDPCut60);
hs_InvMassDPCut60->Add(hWZ_InvMassDPCut60);
hs_InvMassDPCut60->Add(hWW_InvMassDPCut60);
hs_InvMassDPCut60->Add(hDY_InvMassDPCut60);



hZZ_InvMassDPCut60->Sumw2();
hWZ_InvMassDPCut60->Sumw2();
hWW_InvMassDPCut60->Sumw2();
hDY_InvMassDPCut60->Sumw2();
hll_InvMassDPCut60->Sumw2();
hlw_InvMassDPCut60->Sumw2();


TCanvas *cs_InvMassDPCut60 = new TCanvas("cs_InvMassDPCut60","cs_InvMassDPCut60",10,10,700,700);
cs_InvMassDPCut60->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_InvMassDPCut60->SetTitle("");
auto legend_InvMassDPCut60 = new TLegend(0.5,0.7,0.9,0.9);


hDat_InvMassDPCut60->SetMarkerStyle(21);
hDat_InvMassDPCut60->SetMarkerSize(1);
hDat_InvMassDPCut60->SetLineColor(1);
// legend stuff
legend_InvMassDPCut60->AddEntry(hlw_InvMassDPCut60," Lee-Wick H(1000)#rightarrow XX(350), 66 fb","f");
//legend_InvMassDPCut60->AddEntry(hll_InvMassDPCut60,"H(1000)#rightarrow XX(350), 1 pb","f");
//legend_InvMassDPCut60->AddEntry(hDY_InvMassDPCut60,"Z/#gamma*#rightarrow #mu#mu","f");
legend_InvMassDPCut60->AddEntry(hDY_InvMassDPCut60,"Z/#gamma*#rightarrow #mu#mu","f");
legend_InvMassDPCut60->AddEntry(hWW_InvMassDPCut60,"WW","f");
legend_InvMassDPCut60->AddEntry(hWZ_InvMassDPCut60,"WZ","f");
legend_InvMassDPCut60->AddEntry(hZZ_InvMassDPCut60,"ZZ","f");
legend_InvMassDPCut60->AddEntry(hDat_InvMassDPCut60,"Datos","p");
legend_InvMassDPCut60->SetFillColor(0);
legend_InvMassDPCut60->SetFillStyle(0);
legend_InvMassDPCut60->SetBorderSize(0);

hs_InvMassDPCut60->SetMaximum(40);
hs_InvMassDPCut60->SetTitle("");

hlw_InvMassDPCut60->SetStats(0);
hs_InvMassDPCut60->Draw("hist eX0");
hlw_InvMassDPCut60->Draw("same hist");
cs_InvMassDPCut60->Update(); 
hDat_InvMassDPCut60->Draw("same hist eX0");

hs_InvMassDPCut60->GetXaxis()->SetTitle("M_{#mu#mu} [GeV/c]");
hs_InvMassDPCut60->GetYaxis()->SetTitleOffset(1.5);
hs_InvMassDPCut60->GetYaxis()->SetTitle("Eventos");
cs_InvMassDPCut60->Update(); 

legend_InvMassDPCut60->Draw();
gPad->Update();
gPad->SetLogy(1);
 

}
