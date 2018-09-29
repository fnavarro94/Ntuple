{

THStack *hs_dotP = new THStack("hs_dotP", "");


double lumi = 2333;  //   1/pb


TFile *fZZ = new TFile("ZZM.root");
TFile *fWZ = new TFile("WZM.root");
TFile *fWW = new TFile("WWM.root");
TFile *fDY = new TFile("DYM.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lw5.root");
TFile *fDat = new TFile("DatM.root");
 
 

TH1F * hZZ_dotP= (TH1F*)fZZ->Get("dotP");
TH1F * hWZ_dotP= (TH1F*)fWZ->Get("dotP");
TH1F * hWW_dotP= (TH1F*)fWW->Get("dotP");
TH1F * hDY_dotP= (TH1F*)fDY->Get("dotP");
TH1F * hll_dotP= (TH1F*)fll->Get("dotP");
TH1F * hlw_dotP= (TH1F*)flw->Get("dotP");
TH1F * hDat_dotP= (TH1F*)fDat->Get("dotP"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_dotP->SetLineColor(1);
hll_dotP->SetLineColor(1);
hZZ_dotP->SetLineColor(1);
hWW_dotP->SetLineColor(1);
hWZ_dotP->SetLineColor(1);
hDY_dotP->SetLineColor(1);

hlw_dotP->SetFillColor(7);
hll_dotP->SetFillColor(2);
hZZ_dotP->SetFillColor(3);
hWW_dotP->SetFillColor(4);
hWZ_dotP->SetFillColor(5);
hDY_dotP->SetFillColor(6);


double ZZ_dotP_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_dotP->Scale(ZZ_dotP_scale);
double WZ_dotP_scale = lumi*0.868/(hWZ_nEvents->Integral());
hWZ_dotP->Scale(WZ_dotP_scale);
double WW_dotP_scale = lumi*42/(hWW_nEvents->Integral());
hWW_dotP->Scale(WW_dotP_scale);
double DY_dotP_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_dotP->Scale(DY_dotP_scale);
double ll_dotP_scale = lumi*1/(4000);
hll_dotP->Scale(ll_dotP_scale);
hlw_dotP->Scale(ll_dotP_scale);

hs_dotP->Add(hlw_dotP);
hs_dotP->Add(hll_dotP);
hs_dotP->Add(hZZ_dotP);
hs_dotP->Add(hWZ_dotP);
hs_dotP->Add(hWW_dotP);
hs_dotP->Add(hDY_dotP);



hZZ_dotP->Sumw2();
hWZ_dotP->Sumw2();
hWW_dotP->Sumw2();
hDY_dotP->Sumw2();
hll_dotP->Sumw2();
hlw_dotP->Sumw2();


TCanvas *cs_dotP = new TCanvas("cs_dotP","cs_dotP",10,10,700,700);
cs_dotP->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_dotP->SetTitle("");
auto legend_dotP = new TLegend(0.5,0.7,0.9,0.9);


// legend stuff
legend_dotP->AddEntry(hlw_dotP," Lee-Wick H(1000)#rightarrow XX(350), 1 pb","f");
legend_dotP->AddEntry(hll_dotP,"H(1000)#rightarrow XX(350), 1 pb","f");
legend_dotP->AddEntry(hDY_dotP,"Z/#gamma*#rightarrow #mu#mu","f");
legend_dotP->AddEntry(hWW_dotP,"WW","f");
legend_dotP->AddEntry(hWZ_dotP,"WZ","f");
legend_dotP->AddEntry(hZZ_dotP,"ZZ","f");
legend_dotP->SetFillColor(0);
legend_dotP->SetFillStyle(0);
legend_dotP->SetBorderSize(0);



hs_dotP->Draw(" hist eX0"); 
hs_dotP->GetXaxis()->SetTitle("Pt #dot L_{xy}");
hs_dotP->GetYaxis()->SetTitle("Entries");
cs_dotP->Update(); 

legend_dotP->Draw();
gPad->Update();
gPad->SetLogy(1);
 

}
