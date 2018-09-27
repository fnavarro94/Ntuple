{

THStack *hs_InvMass = new THStack("hs_InvMass", "");


double lumi = 2333;  //   1/pb


TFile *fZZ = new TFile("ZZM.root");
TFile *fWZ = new TFile("WZM.root");
TFile *fWW = new TFile("WWM.root");
TFile *fDY = new TFile("DYM.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lw5.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_InvMass= (TH1F*)fZZ->Get("InvMass");
TH1F * hWZ_InvMass= (TH1F*)fWZ->Get("InvMass");
TH1F * hWW_InvMass= (TH1F*)fWW->Get("InvMass");
TH1F * hDY_InvMass= (TH1F*)fDY->Get("InvMass");
TH1F * hll_InvMass= (TH1F*)fll->Get("InvMass");
TH1F * hlw_InvMass= (TH1F*)flw->Get("InvMass");
TH1F * hDat_InvMass= (TH1F*)fDat->Get("InvMass"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_InvMass->SetLineColor(1);
hll_InvMass->SetLineColor(1);
hZZ_InvMass->SetLineColor(1);
hWW_InvMass->SetLineColor(1);
hWZ_InvMass->SetLineColor(1);
hDY_InvMass->SetLineColor(1);

hlw_InvMass->SetFillColor(7);
hll_InvMass->SetFillColor(2);
hZZ_InvMass->SetFillColor(3);
hWW_InvMass->SetFillColor(4);
hWZ_InvMass->SetFillColor(5);
hDY_InvMass->SetFillColor(6);


double ZZ_InvMass_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_InvMass->Scale(ZZ_InvMass_scale);
double WZ_InvMass_scale = lumi*18.2/(hWZ_nEvents->Integral());
hWZ_InvMass->Scale(WZ_InvMass_scale);
double WW_InvMass_scale = lumi*42/(hWW_nEvents->Integral());
hWW_InvMass->Scale(WW_InvMass_scale);
double DY_InvMass_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_InvMass->Scale(DY_InvMass_scale);
double ll_InvMass_scale = lumi*1/(4000);
hll_InvMass->Scale(ll_InvMass_scale);
hlw_InvMass->Scale(ll_InvMass_scale);

hs_InvMass->Add(hlw_InvMass);
hs_InvMass->Add(hll_InvMass);
hs_InvMass->Add(hZZ_InvMass);
hs_InvMass->Add(hWZ_InvMass);
hs_InvMass->Add(hWW_InvMass);
hs_InvMass->Add(hDY_InvMass);



hZZ_InvMass->Sumw2();
hWZ_InvMass->Sumw2();
hWW_InvMass->Sumw2();
hDY_InvMass->Sumw2();
hll_InvMass->Sumw2();
hlw_InvMass->Sumw2();


TCanvas *cs_InvMass = new TCanvas("cs_InvMass","cs_InvMass",10,10,700,700);
cs_InvMass->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_InvMass->SetTitle("");
auto legend_InvMass = new TLegend(0.5,0.7,0.9,0.9);


// legend stuff
legend_InvMass->AddEntry(hlw_InvMass," Lee-Wick H(1000)#rightarrow XX(350), 1 pb","f");
legend_InvMass->AddEntry(hll_InvMass,"H(1000)#rightarrow XX(350), 1 pb","f");
legend_InvMass->AddEntry(hDY_InvMass,"Z/#gamma*#rightarrow #mu#mu","f");
legend_InvMass->AddEntry(hWW_InvMass,"WW","f");
legend_InvMass->AddEntry(hWZ_InvMass,"WZ","f");
legend_InvMass->AddEntry(hZZ_InvMass,"ZZ","f");
legend_InvMass->SetFillColor(0);
legend_InvMass->SetFillStyle(0);
legend_InvMass->SetBorderSize(0);



hs_InvMass->Draw(" hist eX0"); 
hs_InvMass->GetXaxis()->SetTitle("PT [GeV/c]");
cs_InvMass->Update(); 

legend_InvMass->Draw();
gPad->Update();
gPad->SetLogy(1);
 

}
