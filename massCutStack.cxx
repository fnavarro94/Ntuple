{

THStack *hs_InvMassPt250 = new THStack("hs_InvMassPt250", "");


double lumi = 2333;  //   1/pb


TFile *fZZ = new TFile("ZZM.root");
TFile *fWZ = new TFile("WZM.root");
TFile *fWW = new TFile("WWM.root");
TFile *fDY = new TFile("DYM.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lw5.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_InvMassPt250= (TH1F*)fZZ->Get("InvMassPt250");
TH1F * hWZ_InvMassPt250= (TH1F*)fWZ->Get("InvMassPt250");
TH1F * hWW_InvMassPt250= (TH1F*)fWW->Get("InvMassPt250");
TH1F * hDY_InvMassPt250= (TH1F*)fDY->Get("InvMassPt250");
TH1F * hll_InvMassPt250= (TH1F*)fll->Get("InvMassPt250");
TH1F * hlw_InvMassPt250= (TH1F*)flw->Get("InvMassPt250Inv");
TH1F * hDat_InvMassPt250= (TH1F*)fDat->Get("InvMassPt250"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_InvMassPt250->SetLineColor(1);
hll_InvMassPt250->SetLineColor(1);
hZZ_InvMassPt250->SetLineColor(1);
hWW_InvMassPt250->SetLineColor(1);
hWZ_InvMassPt250->SetLineColor(1);
hDY_InvMassPt250->SetLineColor(1);

hlw_InvMassPt250->SetFillColor(7);
hll_InvMassPt250->SetFillColor(2);
hZZ_InvMassPt250->SetFillColor(3);
hWW_InvMassPt250->SetFillColor(4);
hWZ_InvMassPt250->SetFillColor(5);
hDY_InvMassPt250->SetFillColor(6);


double ZZ_InvMassPt250_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_InvMassPt250->Scale(ZZ_InvMassPt250_scale);
double WZ_InvMassPt250_scale = lumi*0.868/(hWZ_nEvents->Integral());
hWZ_InvMassPt250->Scale(WZ_InvMassPt250_scale);
double WW_InvMassPt250_scale = lumi*42/(hWW_nEvents->Integral());
hWW_InvMassPt250->Scale(WW_InvMassPt250_scale);
double DY_InvMassPt250_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_InvMassPt250->Scale(DY_InvMassPt250_scale);
double ll_InvMassPt250_scale = lumi*1/(4000);
hll_InvMassPt250->Scale(ll_InvMassPt250_scale);
hlw_InvMassPt250->Scale(ll_InvMassPt250_scale);

hs_InvMassPt250->Add(hlw_InvMassPt250);
hs_InvMassPt250->Add(hll_InvMassPt250);
hs_InvMassPt250->Add(hZZ_InvMassPt250);
hs_InvMassPt250->Add(hWZ_InvMassPt250);
hs_InvMassPt250->Add(hWW_InvMassPt250);
hs_InvMassPt250->Add(hDY_InvMassPt250);



hZZ_InvMassPt250->Sumw2();
hWZ_InvMassPt250->Sumw2();
hWW_InvMassPt250->Sumw2();
hDY_InvMassPt250->Sumw2();
hll_InvMassPt250->Sumw2();
hlw_InvMassPt250->Sumw2();


TCanvas *cs_InvMassPt250 = new TCanvas("cs_InvMassPt250","cs_InvMassPt250",10,10,700,700);
cs_InvMassPt250->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_InvMassPt250->SetTitle("");
auto legend_InvMassPt250 = new TLegend(0.5,0.7,0.9,0.9);


// legend stuff
legend_InvMassPt250->AddEntry(hlw_InvMassPt250," Lee-Wick H(1000)#rightarrow XX(350), 1 pb","f");
legend_InvMassPt250->AddEntry(hll_InvMassPt250,"H(1000)#rightarrow XX(350), 1 pb","f");
legend_InvMassPt250->AddEntry(hDY_InvMassPt250,"Z/#gamma*#rightarrow #mu#mu","f");
legend_InvMassPt250->AddEntry(hWW_InvMassPt250,"WW","f");
legend_InvMassPt250->AddEntry(hWZ_InvMassPt250,"WZ","f");
legend_InvMassPt250->AddEntry(hZZ_InvMassPt250,"ZZ","f");
legend_InvMassPt250->SetFillColor(0);
legend_InvMassPt250->SetFillStyle(0);
legend_InvMassPt250->SetBorderSize(0);



hs_InvMassPt250->Draw(" hist eX0"); 
hs_InvMassPt250->GetXaxis()->SetTitle("M_{#mu#mu} [GeV/c^{2}]");
hs_InvMassPt250->GetYaxis()->SetTitleOffset(1.5);
hs_InvMassPt250->GetYaxis()->SetTitle("Eventos");
cs_InvMassPt250->Update(); 

legend_InvMassPt250->Draw();
gPad->Update();
gPad->SetLogy(1);
 

}
