{

THStack *hs_dotP_err = new THStack("hs_dotP_err", "");


double lumi = 2333;  //   1/pb


TFile *fZZ = new TFile("ZZE2G.root");
TFile *fWZ = new TFile("WZE2G.root");
TFile *fWW = new TFile("WWE2G.root");
TFile *fDY = new TFile("DYE2G.root");
TFile *fll = new TFile("llM.root");
TFile *flw = new TFile("lwE.root");
TFile *fDat = new TFile("DatE.root");
 
 

TH1F * hZZ_dotP_err= (TH1F*)fZZ->Get("dotP_err");
TH1F * hWZ_dotP_err= (TH1F*)fWZ->Get("dotP_err");
TH1F * hWW_dotP_err= (TH1F*)fWW->Get("dotP_err");
TH1F * hDY_dotP_err= (TH1F*)fDY->Get("dotP_err");
TH1F * hll_dotP_err= (TH1F*)fll->Get("dotP_err");
TH1F * hlw_dotP_err= (TH1F*)flw->Get("dotPLw_err");
TH1F * hDat_dotP_err= (TH1F*)fDat->Get("dotP_err"); 


TH1F * hZZ_nEvents= (TH1F*)fZZ->Get("nEvents");
TH1F * hWZ_nEvents= (TH1F*)fWZ->Get("nEvents");
TH1F * hWW_nEvents= (TH1F*)fWW->Get("nEvents");
TH1F * hDY_nEvents= (TH1F*)fDY->Get("nEvents");
TH1F * hll_nEvents= (TH1F*)fll->Get("nEvents");
TH1F * hlw_nEvents= (TH1F*)flw->Get("nEvents");
TH1F * hDat_nEvents= (TH1F*)fDat->Get("nEvents"); 


hlw_dotP_err->SetLineColor(2);
hll_dotP_err->SetLineColor(1);
hZZ_dotP_err->SetLineColor(1);
hWW_dotP_err->SetLineColor(1);
hWZ_dotP_err->SetLineColor(1);
hDY_dotP_err->SetLineColor(1);

hlw_dotP_err->SetFillColor(2);
hll_dotP_err->SetFillColor(2);
hZZ_dotP_err->SetFillColor(46);
hWW_dotP_err->SetFillColor(8);
hWZ_dotP_err->SetFillColor(41);
hDY_dotP_err->SetFillColor(9);



double ZZ_dotP_err_scale = lumi*5.9/(hZZ_nEvents->Integral());
hZZ_dotP_err->Scale(ZZ_dotP_err_scale);
double WZ_dotP_err_scale = lumi*0.868/(hWZ_nEvents->Integral());
hWZ_dotP_err->Scale(WZ_dotP_err_scale);
double WW_dotP_err_scale = lumi*42/(hWW_nEvents->Integral());
hWW_dotP_err->Scale(WW_dotP_err_scale);
double DY_dotP_err_scale = lumi*3048/(hDY_nEvents->Integral());
hDY_dotP_err->Scale(DY_dotP_err_scale);
double ll_dotP_err_scale = lumi*1/(4000);
hll_dotP_err->Scale(ll_dotP_err_scale);
hlw_dotP_err->Scale(0.066*ll_dotP_err_scale);


hs_dotP_err->Add(hWZ_dotP_err);
hs_dotP_err->Add(hWW_dotP_err);
hs_dotP_err->Add(hDY_dotP_err);

//hs_dotP_err->Add(hlw_dotP_err);
//hs_dotP_err->Add(hll_dotP_err);
hs_dotP_err->Add(hZZ_dotP_err);





hZZ_dotP_err->Sumw2();
hWZ_dotP_err->Sumw2();
hWW_dotP_err->Sumw2();
hDY_dotP_err->Sumw2();
hll_dotP_err->Sumw2();
hlw_dotP_err->Sumw2();


TCanvas *cs_dotP_err = new TCanvas("cs_dotP_err","cs_dotP_err",10,10,700,700);
cs_dotP_err->cd(1); 

TText T; T.SetTextFont(42); T.SetTextAlign(21);
hs_dotP_err->SetTitle("");
auto legend_dotP_err = new TLegend(0.5,0.7,0.9,0.9);

//hll_lxy_err->SetMaximum(400000);
hs_dotP_err->SetMinimum(1);

// legend stuff
legend_dotP_err->AddEntry(hlw_dotP_err," Lee-Wick H(1000)#rightarrow XX(350), 66 fb","f");
//legend_dotP_err->AddEntry(hll_dotP_err,"H(1000)#rightarrow XX(350), 1 pb","f");
legend_dotP_err->AddEntry(hDY_dotP_err,"Z/#gamma*#rightarrow ee","f");
legend_dotP_err->AddEntry(hWW_dotP_err,"WW","f");
legend_dotP_err->AddEntry(hWZ_dotP_err,"WZ","f");
legend_dotP_err->AddEntry(hZZ_dotP_err,"ZZ","f");
legend_dotP_err->SetFillColor(0);
legend_dotP_err->SetFillStyle(0);
legend_dotP_err->SetBorderSize(0);

hs_dotP_err->SetMinimum(0.5);

hs_dotP_err->Draw(" hist eX0"); 
hs_dotP_err->GetXaxis()->SetTitle("Pt_{ee} #bullet L_{xy}/#sigma_{xy}");
hs_dotP_err->GetYaxis()->SetTitleOffset(1.5);
hs_dotP_err->GetYaxis()->SetTitle("Eventos");
cs_dotP_err->Update(); 


gPad->Update();
gPad->SetLogy(1);

hlw_dotP_err->SetMaximum(2*hs_dotP_err->GetMaximum());
hlw_dotP_err->SetTitle("");

hlw_dotP_err->SetStats(0);
hs_dotP_err->Draw(" hist eX0");
hlw_dotP_err->Draw("same hist");
cs_dotP_err->Update(); 
//hDat_dotP_err->Draw("same hist eX0");

hlw_dotP_err->GetXaxis()->SetTitle("Pt #bullet L_{xy}/#sigma_{xy}");
hlw_dotP_err->GetYaxis()->SetTitleOffset(1.5);
hlw_dotP_err->GetYaxis()->SetTitle("Eventos");
legend_dotP_err->Draw();
cs_dotP_err->Update(); 


gPad->Update();
gPad->SetLogy(1); 

}
