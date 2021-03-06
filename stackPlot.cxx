{
   THStack *hs = new THStack("hs","");
   THStack *hs_mass = new THStack("hs_mass","");
  
   TFile *fDY = new TFile("notStrictDYMuon.root");
   // TFile *fZZ2 = new TFile("histsZZ2.root");
   TFile *fZZT = new TFile("notStrictZZMuon.root");
   // TFile *fZZ4 = new TFile("histsZZ4.root");
   TFile *fWZ = new TFile("notStrictWZMuon.root");
   TFile *fWW = new TFile("notStrictWWMuon.root");
   TFile *fDat = new TFile("hists.root");
   
   TH1F * hDY = (TH1F*)fDY->Get("lxy_err");
   //TH1F * hZZ2 = (TH1F*)fZZ2->Get("lxy_err");
   TH1F * hZZT = (TH1F*)fZZT->Get("lxy_err");
   //  TH1F * hZZ4 = (TH1F*)fZZ4->Get("lxy_err");
   TH1F * hWZ = (TH1F*)fWZ->Get("lxy_err");
   TH1F * hWW = (TH1F*)fWW->Get("lxy_err");
   TH1F * hDat = (TH1F*)fDat->Get("lxy_err");
   
   
   TH1F * hDY_mass = (TH1F*)fDY->Get("InvMass");
   //TH1F * hZZ2 = (TH1F*)fZZ2->Get("lxy_err");
   TH1F * hZZT_mass = (TH1F*)fZZT->Get("InvMass");
   // TH1F * hZZ4 = (TH1F*)fZZ4->Get("lxy_err");
   TH1F * hWZ_mass = (TH1F*)fWZ->Get("InvMass");
   TH1F * hWW_mass = (TH1F*)fWW->Get("InvMass");
   TH1F * hDat_mass = (TH1F*)fDat->Get("InvMass");
   
   hDY->Sumw2();
   hDY_mass->Sumw2();
   //hZZ2->Sumw2();
   hZZT->Sumw2();
   hZZT_mass->Sumw2();
   //  hZZ4->Sumw2();
   hWZ->Sumw2();
   hWZ_mass->Sumw2();
   hWW->Sumw2();
   hWW_mass->Sumw2();
   hDat->Sumw2();
   hDat_mass->Sumw2();
   
   
   hDY->SetFillColor(2);
   hDY_mass->SetFillColor(2);
   //hZZ2->SetFillColor(8);
   hZZT->SetFillColor(8);
   hZZT_mass->SetFillColor(8);
 //  hZZ4->SetFillColor(2);
   hWZ->SetFillColor(7);
   hWZ_mass->SetFillColor(7);
   hWW->SetFillColor(6);
   hWW_mass->SetFillColor(6);
   hDat->SetFillColor(1);
   hDat_mass->SetFillColor(1);
   
  double DY_scale = 3048.0/3987986;
  double ZZ_scale = 5.9/3899263;
  double WZ_scale = 18.2/1284698;
  double WW_scale = 42.0/193524;
  double Dat_scale = 1.0/10000;
   
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
   
   //hs->Add(hZZ2);
     hs->Add(hZZT);
     hs->Add(hWZ);
     hs->Add(hWW);
     hs->Add(hDY);
    
     hs_mass->Add(hZZT_mass);
     hs_mass->Add(hWZ_mass);
     hs_mass->Add(hWW_mass);
     hs_mass->Add(hDY_mass);
    
    
   
  // hs->Add(hZZ4);
   
 
   
   hDat->SetMarkerStyle(21);
  
   
  
   TCanvas *cs = new TCanvas("cs","cs",10,10,700,900);
   TText T; T.SetTextFont(42); T.SetTextAlign(21);
  
   cs->Divide(1,2);
   cs->cd(1); hDat->Draw("e"); cs->Update(); hs->Draw("same hist");T.DrawTextNDC(.5,.95,"Default drawing option"); 
   //cs->cd(2); hDat_mass->Draw("e"); cs->Update(); hs_mass->Draw("same hist"); T.DrawTextNDC(.5,.95,"Default drawing option"); 
  
   gPad->Update();
   gPad->SetLogy(1);
   return cs;
}
