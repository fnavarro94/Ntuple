{
	
	double lumi = 5100.227976804;  //   1/pb
	 
	
   THStack *hs = new THStack("hs","");
   THStack *hs_mass = new THStack("hs_mass","");
  
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
   
   
   
   hDY->Sumw2();
   hDY_mass->Sumw2();
   hZZT->Sumw2();
   hZZT_mass->Sumw2();
   hWZ->Sumw2();
   hWZ_mass->Sumw2();
   hWW->Sumw2();
   hWW_mass->Sumw2();
   hDat->Sumw2();
   hDat_mass->Sumw2();
   
   hDY->SetFillColor(2);
   hDY_mass->SetFillColor(2);
   hZZT->SetFillColor(kGreen +3);
   hZZT_mass->SetFillColor(kGreen +3);
  
  
   hWZ->SetFillColor(kCyan -9);
   hWZ_mass->SetFillColor(kCyan -9);
   hWW->SetFillColor(kMagenta -3);
   hWW_mass->SetFillColor(kMagenta -3);
   hDat->SetFillColor(1);
   hDat_mass->SetFillColor(1);
   
  double DY_scale = lumi*3048.0/(489661);
  double ZZ_scale = lumi*5.9/(1095073);
  double WZ_scale = lumi*18.2/(1210588);
  double WW_scale = lumi*42.0/(3935865);
  double Dat_scale = lumi*1.0/4000;
   
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
