{
	
	double lumi = 5100.227976804;  //   1/pb
	 
	
   THStack *hs = new THStack("hs","");
   THStack *hs_mass = new THStack("hs_mass","");
   THStack *hs_massLC = new THStack("hs_massLC","");
   THStack *hs_massLW = new THStack("hs_massLW","");
   THStack *hs_d0_err = new THStack("hs_d0_err","");
   THStack *hs_d0_errLC = new THStack("hs_d0_errLC","");
  
   TFile *fDY = new TFile("DYbg.root");
   TFile *fZZT = new TFile("ZZbg.root");
   TFile *fWZ = new TFile("WZbg.root");
   TFile *fWW = new TFile("WWbg.root");
   TFile *fDat = new TFile("lw.root");
   
   TH1F * hDY = (TH1F*)fDY->Get("lxy_err"); 
   TH1F * hZZT = (TH1F*)fZZT->Get("lxy_err");
   TH1F * hWZ = (TH1F*)fWZ->Get("lxy_err");
   TH1F * hWW = (TH1F*)fWW->Get("lxy_err");
   TH1F * hDat = (TH1F*)fDat->Get("lxy_err");
   
   
   TH1F * hDY_mass = (TH1F*)fDY->Get("InvMass");
   TH1F * hZZT_mass = (TH1F*)fZZT->Get("InvMass");
   TH1F * hWZ_mass = (TH1F*)fWZ->Get("InvMass");
   TH1F * hWW_mass = (TH1F*)fWW->Get("InvMass");
   TH1F * hDat_mass = (TH1F*)fDat->Get("InvMass");
   
   TH1F * hDY_massLC = (TH1F*)fDY->Get("InvMassLC");
   TH1F * hZZT_massLC = (TH1F*)fZZT->Get("InvMassLC");
   TH1F * hWZ_massLC = (TH1F*)fWZ->Get("InvMassLC");
   TH1F * hWW_massLC = (TH1F*)fWW->Get("InvMassLC");
   TH1F * hDat_massLC = (TH1F*)fDat->Get("InvMassLC");
   
    
   TH1F * hDY_massLW = (TH1F*)fDY->Get("InvMassLW");
   TH1F * hZZT_massLW = (TH1F*)fZZT->Get("InvMassLW");
   TH1F * hWZ_massLW = (TH1F*)fWZ->Get("InvMassLW");
   TH1F * hWW_massLW = (TH1F*)fWW->Get("InvMassLW");
   TH1F * hDat_massLW = (TH1F*)fDat->Get("InvMassLW");
   
   
   TH1F * hDY_d0_err = (TH1F*)fDY->Get("d0_err");
   TH1F * hZZT_d0_err = (TH1F*)fZZT->Get("d0_err");
   TH1F * hWZ_d0_err = (TH1F*)fWZ->Get("d0_err");
   TH1F * hWW_d0_err = (TH1F*)fWW->Get("d0_err");
   TH1F * hDat_d0_err = (TH1F*)fDat->Get("d0_err");
   
   TH1F * hDY_d0_errLC = (TH1F*)fDY->Get("d0_errLC");
   TH1F * hZZT_d0_errLC = (TH1F*)fZZT->Get("d0_errLC");
   TH1F * hWZ_d0_errLC = (TH1F*)fWZ->Get("d0_errLC");
   TH1F * hWW_d0_errLC = (TH1F*)fWW->Get("d0_errLC");
   TH1F * hDat_d0_errLC = (TH1F*)fDat->Get("d0_errLC");
   
   
   
   hDY->Sumw2();  
   hZZT->Sumw2(); 
   hWZ->Sumw2();  
   hWW->Sumw2();
   hDat->Sumw2();
  
   
   hDY_mass->Sumw2();
   hZZT_mass->Sumw2();
   hWZ_mass->Sumw2();
   hWW_mass->Sumw2();
   hDat_mass->Sumw2();
   
   hDY_massLC->Sumw2();
   hZZT_massLC->Sumw2();
   hWZ_massLC->Sumw2();
   hWW_massLC->Sumw2();
   hDat_massLC->Sumw2();
   
   hDY_massLW->Sumw2();
   hZZT_massLW->Sumw2();
   hWZ_massLW->Sumw2();
   hWW_massLW->Sumw2();
   hDat_massLW->Sumw2();
   
   
   hDY_d0_err->Sumw2();
   hZZT_d0_err->Sumw2();
   hWZ_d0_err->Sumw2();
   hWW_d0_err->Sumw2();
   hDat_d0_err->Sumw2();
     
   hDY_d0_errLC->Sumw2();
   hZZT_d0_errLC->Sumw2();
   hWZ_d0_errLC->Sumw2();
   hWW_d0_errLC->Sumw2();
   hDat_d0_errLC->Sumw2();
   
   hDY->SetLineColor(1);
   hZZT->SetLineColor(1);
   hWZ->SetLineColor(1);
   hWW->SetLineColor(1); 
   
    hDY_mass->SetLineColor(1);
   hZZT_mass->SetLineColor(1);
   hWZ_mass->SetLineColor(1);
   hWW_mass->SetLineColor(1); 
   
   hDY_massLC->SetLineColor(1);
   hZZT_massLC->SetLineColor(1);
   hWZ_massLC->SetLineColor(1);
   hWW_massLC->SetLineColor(1); 
   
   hDY_massLW->SetLineColor(1);
   hZZT_massLW->SetLineColor(1);
   hWZ_massLW->SetLineColor(1);
   hWW_massLW->SetLineColor(1); 
   
   hDY_d0_err->SetLineColor(1);
   hZZT_d0_err->SetLineColor(1);
   hWZ_d0_err->SetLineColor(1);
   hWW_d0_err->SetLineColor(1); 
   
   hDY_d0_errLC->SetLineColor(1);
   hZZT_d0_errLC->SetLineColor(1);
   hWZ_d0_errLC->SetLineColor(1);
   hWW_d0_errLC->SetLineColor(1); 
  
   
   hDY->SetFillColor(2);
   hZZT->SetFillColor(kGreen +3); 
   hWZ->SetFillColor(kCyan -9); 
   hWW->SetFillColor(kMagenta -3);   
   hDat->SetFillColor(0);
   hDat->SetLineColor(2);
   
   hDY_mass->SetFillColor(2);
   hZZT_mass->SetFillColor(kGreen +3);
   hWZ_mass->SetFillColor(kCyan -9);
   hWW_mass->SetFillColor(kMagenta -3);
   hDat_mass->SetFillColor(0);
   hDat_mass->SetLineColor(2);
   
   hDY_massLC->SetFillColor(2);
   hZZT_massLC->SetFillColor(kGreen +3);
   hWZ_massLC->SetFillColor(kCyan -9);
   hWW_massLC->SetFillColor(kMagenta -3);
   hDat_massLC->SetFillColor(0);
   hDat_massLC->SetLineColor(2);
   
   hDY_massLW->SetFillColor(2);
   hZZT_massLW->SetFillColor(kGreen +3);
   hWZ_massLW->SetFillColor(kCyan -9);
   hWW_massLW->SetFillColor(kMagenta -3);
   hDat_massLW->SetFillColor(0);
   hDat_massLW->SetLineColor(2);
   
   hDY_d0_err->SetFillColor(2);
   hZZT_d0_err->SetFillColor(kGreen +3);
   hWZ_d0_err->SetFillColor(kCyan -9);
   hWW_d0_err->SetFillColor(kMagenta -3);
   hDat_d0_err->SetFillColor(0);
   hDat_d0_err->SetLineColor(2);
   
   hDY_d0_errLC->SetFillColor(2);
   hZZT_d0_errLC->SetFillColor(kGreen +3);
   hWZ_d0_errLC->SetFillColor(kCyan -9);
   hWW_d0_errLC->SetFillColor(kMagenta -3);
   hDat_d0_errLC->SetFillColor(0);
   hDat_d0_errLC->SetLineColor(2);
   
   
  double DY_scale = lumi*3048.0/(hDY->Integral());
  double ZZ_scale = lumi*5.9/(hZZT->Integral());
  double WZ_scale = lumi*18.2/(hWZ->Integral());
  double WW_scale = lumi*42.0/(hWW->Integral());
  double Dat_scale = lumi*1/(hDat->Integral());
   
   cout<<hDY_d0_err->Integral(-99999999,99999999)<<endl;
   
   hDY->Scale(DY_scale);
   hZZT->Scale(ZZ_scale); 
   hWZ->Scale(WZ_scale);
   hWW->Scale(WW_scale);
   hDat->Scale(Dat_scale);
   
   hDY_mass->Scale(DY_scale);
   hZZT_mass->Scale(ZZ_scale); 
   hWZ_mass->Scale(WZ_scale);
   hWW_mass->Scale(WW_scale);
   hDat_mass->Scale(Dat_scale);
   
   hDY_massLC->Scale(DY_scale);
   hZZT_massLC->Scale(ZZ_scale); 
   hWZ_massLC->Scale(WZ_scale);
   hWW_massLC->Scale(WW_scale);
   hDat_massLC->Scale(Dat_scale);
   
   hDY_massLW->Scale(DY_scale);
   hZZT_massLW->Scale(ZZ_scale); 
   hWZ_massLW->Scale(WZ_scale);
   hWW_massLW->Scale(WW_scale);
   hDat_massLW->Scale(Dat_scale);
   
   hDY_d0_err->Scale(DY_scale);
   hZZT_d0_err->Scale(ZZ_scale); 
   hWZ_d0_err->Scale(WZ_scale);
   hWW_d0_err->Scale(WW_scale);
   hDat_d0_err->Scale(Dat_scale);
   
   hDY_d0_errLC->Scale(DY_scale);
   hZZT_d0_errLC->Scale(ZZ_scale); 
   hWZ_d0_errLC->Scale(WZ_scale);
   hWW_d0_errLC->Scale(WW_scale);
   hDat_d0_errLC->Scale(Dat_scale);
   
    
    
   hDY->SetStats(0);
   hZZT->SetStats(0);
   hWZ->SetStats(0);
   hWW->SetStats(0);
   hDat->SetStats(0);
    
   hDY_mass->SetStats(0);
   hZZT_mass->SetStats(0);
   hWZ_mass->SetStats(0);
   hWW_mass->SetStats(0);
   hDat_mass->SetStats(0);
   
   hDY_massLC->SetStats(0);
   hZZT_massLC->SetStats(0);
   hWZ_massLC->SetStats(0);
   hWW_massLC->SetStats(0);
   hDat_massLC->SetStats(0);
   
   hDY_massLW->SetStats(0);
   hZZT_massLW->SetStats(0);
   hWZ_massLW->SetStats(0);
   hWW_massLW->SetStats(0);
   hDat_massLW->SetStats(0);
   
   hDY_d0_err->SetStats(0);
   hZZT_d0_err->SetStats(0);
   hWZ_d0_err->SetStats(0);
   hWW_d0_err->SetStats(0);
   hDat_d0_err->SetStats(0);
   
   
   
   
  
  
     hs->Add(hZZT);
     hs->Add(hWZ);
     hs->Add(hWW);
     hs->Add(hDY);
    
     hs_mass->Add(hZZT_mass);
     hs_mass->Add(hWZ_mass);
     hs_mass->Add(hWW_mass);
     hs_mass->Add(hDY_mass);
     
     hs_massLC->Add(hZZT_massLC);
     hs_massLC->Add(hWZ_massLC);
     hs_massLC->Add(hWW_massLC);
     hs_massLC->Add(hDY_massLC);
     
     hs_massLW->Add(hZZT_massLW);
     hs_massLW->Add(hWZ_massLW);
     hs_massLW->Add(hWW_massLW);
     hs_massLW->Add(hDY_massLW);

     hs_d0_err->Add(hZZT_d0_err);
     hs_d0_err->Add(hWZ_d0_err);
     hs_d0_err->Add(hWW_d0_err);
     hs_d0_err->Add(hDY_d0_err);
     
     hs_d0_errLC->Add(hZZT_d0_errLC);
     hs_d0_errLC->Add(hWZ_d0_errLC);
     hs_d0_errLC->Add(hWW_d0_errLC);
     hs_d0_errLC->Add(hDY_d0_errLC);
    
    
   

   
 
   
   hDat->SetMarkerStyle(21);
   hDat_mass->SetMarkerStyle(21);
   hDat_massLC->SetMarkerStyle(21);
   hDat_massLW->SetMarkerStyle(21);
   hDat_d0_err->SetMarkerStyle(21);
   hDat_d0_errLC->SetMarkerStyle(21);
   
  
   // lxy
  
   TCanvas *cs = new TCanvas("cs","cs",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
    
   auto legend = new TLegend(0.5,0.7,0.9,0.9);
  
   legend->AddEntry(hDY_mass,"Z/#gamma*#rightarrow #mu#mu","f");
   legend->AddEntry(hWW_mass,"WW","f");
   legend->AddEntry(hWZ_mass,"WZ","f");
   legend->AddEntry(hZZT_mass,"ZZ","f");
   legend->AddEntry(hDat_mass,"Data","p");
  
   legend->SetFillColor(0);
 
   hDat->SetMaximum(2*hs->GetMaximum());
   hs->SetTitle("Transverse decay length significance");
   hDat->SetXTitle("L_{xy}/#sigma_{xy}");
   hDat->SetYTitle("Entries");
   cs->cd(1); hDat->Draw("hist "); cs->Update(); hs->Draw("same e hist");
   //cs->cd(1);  hs->Draw(" hist"); cs->Update(); hDat->Draw("hist same");
 
   legend->Draw(); 
   gPad->Update();
   gPad->SetLogy(1);
  
   
    // inv mass loose cuts
    
   TCanvas *cs_mass = new TCanvas("cs_mass","cs_mass",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
    hs_mass->SetTitle("Muon Pair Invariant Mass (loose cuts)");
   auto legend_mass = new TLegend(0.5,0.7,0.9,0.9);
  
   legend_mass->AddEntry(hDY_mass,"Z/#gamma*#rightarrow #mu#mu","f");
   legend_mass->AddEntry(hWW_mass,"WW","f");
   legend_mass->AddEntry(hWZ_mass,"WZ","f");
   legend_mass->AddEntry(hZZT_mass,"ZZ","f");
   legend_mass->AddEntry(hDat_mass,"Data","p");
  
   legend_mass->SetFillColor(0);
   hDat_mass->SetMaximum(2*hs_mass->GetMaximum());
   hDat_mass->SetXTitle("mass [GeV/c^{2}]");
   hDat_mass->SetYTitle("Entries");
   cs_mass->cd(1); hDat_mass->Draw("hist"); cs_mass->Update(); hs_mass->Draw("same hist");
   // cs->cd(1);  hs_mass->Draw(" hist"); cs->Update(); hDat_mass->Draw("hist same");
 
   legend_mass->Draw(); 
   
   gPad->Update();
   gPad->SetLogy(1);
   
    // inv mass all cuts
    hs_massLC->SetTitle("Muon Pair Invariant Mass");
   TCanvas *cs_massLC = new TCanvas("cs_massLC","cs_massLC",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
    
   auto legend_massLC = new TLegend(0.5,0.7,0.9,0.9);
  
   legend_massLC->AddEntry(hDY_mass,"Z/#gamma*#rightarrow #mu#mu","f");
   legend_massLC->AddEntry(hWW_mass,"WW","f");
   legend_massLC->AddEntry(hWZ_mass,"WZ","f");
   legend_massLC->AddEntry(hZZT_mass,"ZZ","f");
   legend_massLC->AddEntry(hDat_mass,"Data","p");
  
   legend_massLC->SetFillColor(0);
  hDat_massLC->SetMaximum(2*hs_massLC->GetMaximum());
   hDat_massLC->SetXTitle("mass [GeV/c^{2}]");
   hDat_massLC->SetYTitle("Entries");
   //cs_massLC->cd(1); hDat_massLC->Draw("hist"); cs_massLC->Update(); hs_massLC->Draw("same hist");
    cs->cd(1);  hs_massLC->Draw(" hist"); cs->Update(); hDat_massLC->Draw("hist same");
 
   legend_massLC->Draw(); 
   
   
   gPad->Update();
   gPad->SetLogy(1);
   
       // inv mass lw
    
   hs_massLW->SetTitle("Muon Pair Invariant Mass (Lee-Wick Cuts)"); 
   TCanvas *cs_massLW = new TCanvas("cs_massLW","cs_massLW",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
    
   auto legend_massLW = new TLegend(0.5,0.7,0.9,0.9);
  
   legend_massLW->AddEntry(hDY_mass,"Z/#gamma*#rightarrow #mu#mu","f");
   legend_massLW->AddEntry(hWW_mass,"WW","f");
   legend_massLW->AddEntry(hWZ_mass,"WZ","f");
   legend_massLW->AddEntry(hZZT_mass,"ZZ","f");
   legend_massLW->AddEntry(hDat_mass,"Data","p");
  
   legend_massLW->SetFillColor(0);
   hDat_massLW->SetMaximum(2*hs_massLW->GetMaximum());
   hDat_massLW->SetXTitle("mass [GeV/c^{2}]");
   hDat_massLW->SetYTitle("Entries");
   cs_massLW->cd(1); hDat_massLW->Draw("hist"); cs_massLW->Update(); hs_massLW->Draw("same hist");
   //cs->cd(1);  hs_massLW->Draw(" hist"); cs->Update(); hDat_massLW->Draw("hist same");
 
   legend_massLW->Draw(); 
   
   
   gPad->Update();
   gPad->SetLogy(1);
   
    // d0_err
   hs_d0_err->SetTitle("Transverse Impact Parameter Significance (loose cuts)");
   TCanvas *cs_d0_err = new TCanvas("cs_d0_err","cs_d0_err",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
    
   auto legend_d0_err = new TLegend(0.5,0.7,0.9,0.9);
  
   legend_d0_err->AddEntry(hDY_mass,"Z/#gamma*#rightarrow #mu#mu","f");
   legend_d0_err->AddEntry(hWW_mass,"WW","f");
   legend_d0_err->AddEntry(hWZ_mass,"WZ","f");
   legend_d0_err->AddEntry(hZZT_mass,"ZZ","f");
   legend_d0_err->AddEntry(hDat_mass,"Data","p");
  
   legend_d0_err->SetFillColor(0);
   hDat_d0_err->SetMaximum(2*hs_d0_err->GetMaximum());
   hDat_d0_err->SetXTitle("|d_{0}/#sigma_{0}|");
   hDat_d0_err->SetYTitle("Entries");
   cs_d0_err->cd(1); hDat_d0_err->Draw("hist"); cs_d0_err->Update(); hs_d0_err->Draw("same hist");
  // cs->cd(1);  hs_d0_err->Draw(" hist"); cs->Update(); hDat_d0_err->Draw("hist same");
 
   legend_d0_err->Draw(); 
   
   
   gPad->Update();
   gPad->SetLogy(1);
   
    // d0_errLC
    hs_d0_errLC->SetTitle("Transverse Impact Parameter Significance");
   TCanvas *cs_d0_errLC = new TCanvas("cs_d0_errLC","cs_d0_errLC_",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
    
   auto legend_d0_errLC = new TLegend(0.5,0.7,0.9,0.9);
  
   legend_d0_errLC->AddEntry(hDY_mass,"Z/#gamma*#rightarrow #mu#mu","f");
   legend_d0_errLC->AddEntry(hWW_mass,"WW","f");
   legend_d0_errLC->AddEntry(hWZ_mass,"WZ","f");
   legend_d0_errLC->AddEntry(hZZT_mass,"ZZ","f");
   legend_d0_errLC->AddEntry(hDat_mass,"Data","p");
  
   legend_d0_errLC->SetFillColor(0);
   hDat_d0_errLC->SetMaximum(2*hs_d0_errLC->GetMaximum());
   hDat_d0_errLC->SetXTitle("|d_{0}/#sigma_{0}|");
   hDat_d0_errLC->SetYTitle("Entries");
     cs_d0_errLC->cd(1); hDat_d0_errLC->Draw("hist"); cs_d0_errLC->Update(); hs_d0_errLC->Draw("same hist");
    //cs->cd(1);  hs_d0_errLC->Draw(" hist"); cs->Update(); hDat_d0_errLC->Draw("hist same");
 
   legend_d0_errLC->Draw(); 
   
   
   gPad->Update();
   gPad->SetLogy(1);
   return cs;
}
