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
   
   TH1F * hDY_massCutLC = (TH1F*)fDY->Get("InvMassLC");
   TH1F * hZZT_massCutLC = (TH1F*)fZZT->Get("InvMassLC");
   TH1F * hWZ_massCutLC = (TH1F*)fWZ->Get("InvMassLC");
   TH1F * hWW_massCutLC = (TH1F*)fWW->Get("InvMassLC");
   TH1F * hDat_massCutLC = (TH1F*)fDat->Get("InvMassLC");
   
    
   TH1F * hDY_massCutLW = (TH1F*)fDY->Get("InvMassLW");
   TH1F * hZZT_massCutLW = (TH1F*)fZZT->Get("InvMassLW");
   TH1F * hWZ_massCutLW = (TH1F*)fWZ->Get("InvMassLW");
   TH1F * hWW_massCutLW = (TH1F*)fWW->Get("InvMassLW");
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
   
   hDY_massLC->Sumw2();
   hZZT_massLC->Sumw2();
   hWZ_massLC->Sumw2();
   hWW_massLC->Sumw2();
   hDat_massLC->Sumw2();
   
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
   
   hDY->SetFillColor(2);
   hZZT->SetFillColor(kGreen +3); 
   hWZ->SetFillColor(kCyan -9); 
   hWW->SetFillColor(kMagenta -3);   
   hDat->SetFillColor(1);
   
   hDY_mass->SetFillColor(2);
   hZZT_mass->SetFillColor(kGreen +3);
   hWZ_mass->SetFillColor(kCyan -9);
   hWW_mass->SetFillColor(kMagenta -3);
   hDat_mass->SetFillColor(1);
   
   hDY_massLC->SetFillColor(2);
   hZZT_massLC->SetFillColor(kGreen +3);
   hWZ_massLC->SetFillColor(kCyan -9);
   hWW_massLC->SetFillColor(kMagenta -3);
   hDat_massLC->SetFillColor(1);
   
   hDY_massLW->SetFillColor(2);
   hZZT_massLW->SetFillColor(kGreen +3);
   hWZ_massLW->SetFillColor(kCyan -9);
   hWW_massLW->SetFillColor(kMagenta -3);
   hDat_massLW->SetFillColor(1);
   
   hDY_d0_err->SetFillColor(2);
   hZZT_d0_err->SetFillColor(kGreen +3);
   hWZ_d0_err->SetFillColor(kCyan -9);
   hWW_d0_err->SetFillColor(kMagenta -3);
   hDat_d0_err->SetFillColor(1);
   
   hDY_d0_errLC->SetFillColor(2);
   hZZT_d0_errLC->SetFillColor(kGreen +3);
   hWZ_d0_errLC->SetFillColor(kCyan -9);
   hWW_d0_errLC->SetFillColor(kMagenta -3);
   hDat_d0_errLC->SetFillColor(1);
   
   
  double DY_scale = lumi*3048.0/(489661);
  double ZZ_scale = lumi*5.9/(1095073);
  double WZ_scale = lumi*18.2/(1210588);
  double WW_scale = lumi*42.0/(3935865);
  double Dat_scale = lumi*10;
   
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

     hs_mass_d0_err->Add(hZZT_d0_err);
     hs_mass_d0_err->Add(hWZ_d0_err);
     hs_mass_d0_err->Add(hWW_d0_err);
     hs_mass_d0_err->Add(hDY_d0_err);
     
     hs_mass_d0_errLC->Add(hZZT_d0_errLC);
     hs_mass_d0_errLC->Add(hWZ_d0_errLC);
     hs_mass_d0_errLC->Add(hWW_d0_errLC);
     hs_mass_d0_errLC->Add(hDY_d0_errLC);
    
    
   

   
 
   
   hDat->SetMarkerStyle(21);
   hDat_mass->SetMarkerStyle(21);
  
   
  
   TCanvas *cs = new TCanvas("cs","cs",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
    
   auto legend = new TLegend(0.5,0.7,0.9,0.9);
  
   legend->AddEntry(hDY_mass,"Z/#gamma*#rightarrow #mu#mu","f");
   legend->AddEntry(hWW_mass,"WW","f");
   legend->AddEntry(hWZ_mass,"WZ","f");
   legend->AddEntry(hZZT_mass,"ZZ","f");
   legend->AddEntry(hDat_mass,"Data","p");
  
    legend->SetFillColor(0);
    
    hDat_mass->SetXTitle("Mass [GeV/C^2]");
    hDat_mass->SetYTitle("Entries");
    hDat_mass->SetTitle("Muon Pair Invariant Mass");
   cs->cd(1); hDat->Draw("e"); cs->Update(); hs->Draw("same hist");T.DrawTextNDC(.5,.95,"Default drawing option"); 
 //hDat_mass->Draw("e"); cs->Update(); hs_mass->Draw("same hist"); hDat_mass->Draww("e same")
legend->Draw(); 
   gPad->Update();
   gPad->SetLogy(1);
   return cs;
}
