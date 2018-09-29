{

THStack *hs_pt = new THStack("hs_pt", "");


double lumi = 2333;  //   1/pb


TFile *fZZ = new TFile("ZZM.root");
TFile *fWZ = new TFile("WZM.root");
TFile *fWW = new TFile("WWM.root");
TFile *fDY = new TFile("DYM.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lw5.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_pt= (TH1F*)fZZ->Get("pt");
TH1F * hWZ_pt= (TH1F*)fWZ->Get("pt");
TH1F * hWW_pt= (TH1F*)fWW->Get("pt");
TH1F * hDY_pt= (TH1F*)fDY->Get("pt");
TH1F * hll_pt= (TH1F*)fll->Get("pt");
TH1F * hlw_pt= (TH1F*)flw->Get("pt");
TH1F * hDat_pt= (TH1F*)fDat->Get("pt"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_pt->SetLineColor(1);
hll_pt->SetLineColor(1);
hZZ_pt->SetLineColor(1);
hWW_pt->SetLineColor(1);
hWZ_pt->SetLineColor(1);
hDY_pt->SetLineColor(1);

hlw_pt->SetFillColor(7);
hll_pt->SetFillColor(2);
hZZ_pt->SetFillColor(3);
hWW_pt->SetFillColor(4);
hWZ_pt->SetFillColor(5);
hDY_pt->SetFillColor(6);


double ZZ_pt_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_pt->Scale(ZZ_pt_scale);
double WZ_pt_scale = lumi*0.868/(hWZ_nEvents->Integral());
hWZ_pt->Scale(WZ_pt_scale);
double WW_pt_scale = lumi*42/(hWW_nEvents->Integral());
hWW_pt->Scale(WW_pt_scale);
double DY_pt_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_pt->Scale(DY_pt_scale);
double ll_pt_scale = lumi*1/(4000);
hll_pt->Scale(ll_pt_scale);
hlw_pt->Scale(ll_pt_scale);

hs_pt->Add(hlw_pt);
hs_pt->Add(hll_pt);
hs_pt->Add(hZZ_pt);
hs_pt->Add(hWZ_pt);
hs_pt->Add(hWW_pt);
hs_pt->Add(hDY_pt);



hZZ_pt->Sumw2();
hWZ_pt->Sumw2();
hWW_pt->Sumw2();
hDY_pt->Sumw2();
hll_pt->Sumw2();
hlw_pt->Sumw2();


TCanvas *cs_pt = new TCanvas("cs_pt","cs_pt",10,10,700,700);
cs_pt->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_pt->SetTitle("");
auto legend_pt = new TLegend(0.5,0.7,0.9,0.9);


// legend stuff
legend_pt->AddEntry(hlw_pt," Lee-Wick H(1000)#rightarrow XX(350), 1 pb","f");
legend_pt->AddEntry(hll_pt,"H(1000)#rightarrow XX(350), 1 pb","f");
legend_pt->AddEntry(hDY_pt,"Z/#gamma*#rightarrow #mu#mu","f");
legend_pt->AddEntry(hWW_pt,"WW","f");
legend_pt->AddEntry(hWZ_pt,"WZ","f");
legend_pt->AddEntry(hZZ_pt,"ZZ","f");
legend_pt->SetFillColor(0);
legend_pt->SetFillStyle(0);
legend_pt->SetBorderSize(0);



hs_pt->Draw(" hist eX0"); 
hs_pt->GetXaxis()->SetTitle("PT [GeV/c]");
hs_pt->GetYaxis()->SetTitle("Eventos");
hs_pt->GetYaxis()->SetTitleOffset(1.4);
cs_pt->Update(); 

legend_pt->Draw();
gPad->Update();
gPad->SetLogy(1);
 

}
