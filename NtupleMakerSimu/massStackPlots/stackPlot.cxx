{

  
  
   TFile *fll = new TFile("ll.root");
   TFile *flw = new TFile("lw.root");
   TFile *fZZ = new TFile("ZZ.root");
   TFile *fWW = new TFile("WW.root");
   TFile *fDY = new TFile("DY.root");
   TFile *fWZ = new TFile("WZ.root");
   
   THStack *hsFull = new THStack("hsFull","");
   THStack *hs = new THStack("hs","");
   THStack *hs1 = new THStack("hs1","");
   THStack *hs2 = new THStack("hs2","");
   THStack *hs3 = new THStack("hs3","");
   THStack *hs4 = new THStack("hs4","");
   THStack *hs5 = new THStack("hs5","");
   THStack *hs6 = new THStack("hs6","");
   THStack *hs7 = new THStack("hs7","");
   THStack *hs8 = new THStack("hs8","");
   THStack *hs9 = new THStack("hs9","");
   THStack *hs10 = new THStack("hs10","");
   
   
   TH1F * hllFull = (TH1F*)fll->Get("t_invMassFull");
   TH1F * hll = (TH1F*)fll->Get("t_invMass");
   TH1F * hll1 = (TH1F*)fll->Get("t_invMass1");
   TH1F * hll2 = (TH1F*)fll->Get("t_invMass2");
   TH1F * hll3 = (TH1F*)fll->Get("t_invMass3");
   TH1F * hll4 = (TH1F*)fll->Get("t_invMass4");
   TH1F * hll5 = (TH1F*)fll->Get("t_invMass5");
   TH1F * hll6 = (TH1F*)fll->Get("t_invMass6");
   TH1F * hll7 = (TH1F*)fll->Get("t_invMass7");
   TH1F * hll8 = (TH1F*)fll->Get("t_invMass8");
   TH1F * hll9 = (TH1F*)fll->Get("t_invMass9");
   TH1F * hll10 = (TH1F*)fll->Get("t_invMass10");
   
   TH1F * hlwFull = (TH1F*)flw->Get("t_invMassFull");
   TH1F * hlw = (TH1F*)flw->Get("t_invMass");
   TH1F * hlw1 = (TH1F*)flw->Get("t_invMass1");
   TH1F * hlw2 = (TH1F*)flw->Get("t_invMass2");
   TH1F * hlw3 = (TH1F*)flw->Get("t_invMass3");
   TH1F * hlw4 = (TH1F*)flw->Get("t_invMass4");
   TH1F * hlw5 = (TH1F*)flw->Get("t_invMass5");
   TH1F * hlw6 = (TH1F*)flw->Get("t_invMass6");
   TH1F * hlw7 = (TH1F*)flw->Get("t_invMass7");
   TH1F * hlw8 = (TH1F*)flw->Get("t_invMass8");
   TH1F * hlw9 = (TH1F*)flw->Get("t_invMass9");
   TH1F * hlw10 = (TH1F*)flw->Get("t_invMass10");
   
  
   TH1F * hZZFull = (TH1F*)fZZ->Get("t_invMassFull");
   TH1F * hZZ = (TH1F*)fZZ->Get("t_invMass");
   TH1F * hZZ1 = (TH1F*)fZZ->Get("t_invMass1");
   TH1F * hZZ2 = (TH1F*)fZZ->Get("t_invMass2");
   TH1F * hZZ3 = (TH1F*)fZZ->Get("t_invMass3");
   TH1F * hZZ4 = (TH1F*)fZZ->Get("t_invMass4");
   TH1F * hZZ5 = (TH1F*)fZZ->Get("t_invMass5");
   TH1F * hZZ6 = (TH1F*)fZZ->Get("t_invMass6");
   TH1F * hZZ7 = (TH1F*)fZZ->Get("t_invMass7");
   TH1F * hZZ8 = (TH1F*)fZZ->Get("t_invMass8");
   TH1F * hZZ9 = (TH1F*)fZZ->Get("t_invMass9");
   TH1F * hZZ10 = (TH1F*)fZZ->Get("t_invMass10");
   
   TH1F * hWWFull = (TH1F*)fWW->Get("t_invMassFull");
   TH1F * hWW = (TH1F*)fWW->Get("t_invMass");
   TH1F * hWW1 = (TH1F*)fWW->Get("t_invMass1");
   TH1F * hWW2 = (TH1F*)fWW->Get("t_invMass2");
   TH1F * hWW3 = (TH1F*)fWW->Get("t_invMass3");
   TH1F * hWW4 = (TH1F*)fWW->Get("t_invMass4");
   TH1F * hWW5 = (TH1F*)fWW->Get("t_invMass5");
   TH1F * hWW6 = (TH1F*)fWW->Get("t_invMass6");
   TH1F * hWW7 = (TH1F*)fWW->Get("t_invMass7");
   TH1F * hWW8 = (TH1F*)fWW->Get("t_invMass8");
   TH1F * hWW9 = (TH1F*)fWW->Get("t_invMass9");
   TH1F * hWW10 = (TH1F*)fWW->Get("t_invMass10");
   
   TH1F * hDYFull = (TH1F*)fDY->Get("t_invMassFull");
   TH1F * hDY = (TH1F*)fDY->Get("t_invMass");
   TH1F * hDY1 = (TH1F*)fDY->Get("t_invMass1");
   TH1F * hDY2 = (TH1F*)fDY->Get("t_invMass2");
   TH1F * hDY3 = (TH1F*)fDY->Get("t_invMass3");
   TH1F * hDY4 = (TH1F*)fDY->Get("t_invMass4");
   TH1F * hDY5 = (TH1F*)fDY->Get("t_invMass5");
   TH1F * hDY6 = (TH1F*)fDY->Get("t_invMass6");
   TH1F * hDY7 = (TH1F*)fDY->Get("t_invMass7");
   TH1F * hDY8 = (TH1F*)fDY->Get("t_invMass8");
   TH1F * hDY9 = (TH1F*)fDY->Get("t_invMass9");
   TH1F * hDY10 = (TH1F*)fDY->Get("t_invMass10");
   
   TH1F * hWZFull = (TH1F*)fWZ->Get("t_invMassFull");
   TH1F * hWZ = (TH1F*)fWZ->Get("t_invMass");
   TH1F * hWZ1 = (TH1F*)fWZ->Get("t_invMass1");
   TH1F * hWZ2 = (TH1F*)fWZ->Get("t_invMass2");
   TH1F * hWZ3 = (TH1F*)fWZ->Get("t_invMass3");
   TH1F * hWZ4 = (TH1F*)fWZ->Get("t_invMass4");
   TH1F * hWZ5 = (TH1F*)fWZ->Get("t_invMass5");
   TH1F * hWZ6 = (TH1F*)fWZ->Get("t_invMass6");
   TH1F * hWZ7 = (TH1F*)fWZ->Get("t_invMass7");
   TH1F * hWZ8 = (TH1F*)fWZ->Get("t_invMass8");
   TH1F * hWZ9 = (TH1F*)fWZ->Get("t_invMass9");
   TH1F * hWZ10 = (TH1F*)fWZ->Get("t_invMass10");
   
  
  
   
  
   
   
   
   hllFull->SetFillColor(2);
   hll->SetFillColor(2);
   hll1->SetFillColor(2);
   hll2->SetFillColor(2);
   hll3->SetFillColor(2);
   hll4->SetFillColor(2);
   hll5->SetFillColor(2);
   hll6->SetFillColor(2);
   hll7->SetFillColor(2);
   hll8->SetFillColor(2);
   hll9->SetFillColor(2);
   hll10->SetFillColor(2);
   
   hlwFull->SetFillColor(3);
   hlw->SetFillColor(3);
   hlw1->SetFillColor(3);
   hlw2->SetFillColor(3);
   hlw3->SetFillColor(3);
   hlw4->SetFillColor(3);
   hlw5->SetFillColor(3);
   hlw6->SetFillColor(3);
   hlw7->SetFillColor(3);
   hlw8->SetFillColor(3);
   hlw9->SetFillColor(3);
   hlw10->SetFillColor(3);
   
   hZZFull->SetFillColor(4);
   hZZ->SetFillColor(4);
   hZZ1->SetFillColor(4);
   hZZ2->SetFillColor(4);
   hZZ3->SetFillColor(4);
   hZZ4->SetFillColor(4);
   hZZ5->SetFillColor(4);
   hZZ6->SetFillColor(4);
   hZZ7->SetFillColor(4);
   hZZ8->SetFillColor(4);
   hZZ9->SetFillColor(4);
   hZZ10->SetFillColor(4);
   
   hWWFull->SetFillColor(5);
   hWW->SetFillColor(5);
   hWW1->SetFillColor(5);
   hWW2->SetFillColor(5);
   hWW3->SetFillColor(5);
   hWW4->SetFillColor(5);
   hWW5->SetFillColor(5);
   hWW6->SetFillColor(5);
   hWW7->SetFillColor(5);
   hWW8->SetFillColor(5);
   hWW9->SetFillColor(5);
   hWW10->SetFillColor(5);
   
   hDYFull->SetFillColor(6);
   hDY->SetFillColor(6);
   hDY1->SetFillColor(6);
   hDY2->SetFillColor(6);
   hDY3->SetFillColor(6);
   hDY4->SetFillColor(6);
   hDY5->SetFillColor(6);
   hDY6->SetFillColor(6);
   hDY7->SetFillColor(6);
   hDY8->SetFillColor(6);
   hDY9->SetFillColor(6);
   hDY10->SetFillColor(6);
   
   hWZFull->SetFillColor(7);
   hWZ->SetFillColor(7);
   hWZ1->SetFillColor(7);
   hWZ2->SetFillColor(7);
   hWZ3->SetFillColor(7);
   hWZ4->SetFillColor(7);
   hWZ5->SetFillColor(7);
   hWZ6->SetFillColor(7);
   hWZ7->SetFillColor(7);
   hWZ8->SetFillColor(7);
   hWZ9->SetFillColor(7);
   hWZ10->SetFillColor(7);
   
   
  double ll_scale = 1;
  double ZZ_scale = 1;
  double lw_scale = 1;
  
   
   hll->Scale(ll_scale);
   hZZ->Scale(ZZ_scale); 
   hlw->Scale(lw_scale);
   
   
     hsFull->Add(hllFull);
     hsFull->Add(hlwFull);
     hsFull->Add(hZZFull);
     hsFull->Add(hWWFull);
     hsFull->Add(hDYFull);
     hsFull->Add(hWZFull);
     
     hs->Add(hll);
     hs->Add(hlw);
     hs->Add(hZZ);
     hs->Add(hWW);
     hs->Add(hDY);
     hs->Add(hWZ);
     
     hs1->Add(hll1);
     hs1->Add(hlw1);
     hs1->Add(hZZ1);
     hs1->Add(hWW1);
     hs1->Add(hDY1);
     hs1->Add(hWZ1);
     
     hs2->Add(hll2);
     hs2->Add(hlw2);
     hs2->Add(hZZ2);
     hs2->Add(hWW2);
     hs2->Add(hDY2);
     hs2->Add(hWZ2);
     
     hs3->Add(hll3);
     hs3->Add(hlw3);
     hs3->Add(hZZ3);
     hs3->Add(hWW3);
     hs3->Add(hDY3);
     hs3->Add(hWZ3);
     
     hs4->Add(hll4);
     hs4->Add(hlw4);
     hs4->Add(hZZ4);
     hs4->Add(hWW4);
     hs4->Add(hDY4);
     hs4->Add(hWZ4);
     
     hs5->Add(hll5);
     hs5->Add(hlw5);
     hs5->Add(hZZ5);
     hs5->Add(hWW5);
     hs5->Add(hDY5);
     hs5->Add(hWZ5);
     
     hs6->Add(hll6);
     hs6->Add(hlw6);
     hs6->Add(hZZ6);
     hs6->Add(hWW6);
     hs6->Add(hDY6);
     hs6->Add(hWZ6);
     
     hs7->Add(hll7);
     hs7->Add(hlw7);
     hs7->Add(hZZ7);
     hs7->Add(hWW7);
     hs7->Add(hDY7);
     hs7->Add(hWZ7);
     
     hs8->Add(hll8);
     hs8->Add(hlw8);
     hs8->Add(hZZ8);
     hs8->Add(hWW8);
     hs8->Add(hDY8);
     hs8->Add(hWZ8);
     
     hs9->Add(hll9);
     hs9->Add(hlw9);
     hs9->Add(hZZ9);
     hs9->Add(hWW9);
     hs9->Add(hDY9);
     hs9->Add(hWZ9);
     
     hs10->Add(hll10);
     hs10->Add(hlw10);
     hs10->Add(hZZ10);
     hs10->Add(hWW10);
     hs10->Add(hDY10);
     hs10->Add(hWZ10);
     
       
   
  
   
  
   TCanvas *csFull = new TCanvas("csFull","csFull",10,10,700,900);
    csFull->cd(1); hsFull->Draw("hist"); csFull->Update();
   TCanvas *cs = new TCanvas("cs","cs",10,10,700,900);
   
  
  
   cs->Divide(2,5);
   cs->cd(1); hs->Draw("hist"); cs->Update(); 
   cs->cd(2); hs1->Draw("hist"); cs->Update(); 
   cs->cd(3); hs2->Draw("hist"); cs->Update(); 
   cs->cd(4); hs3->Draw("hist"); cs->Update(); 
   cs->cd(5); hs4->Draw("hist"); cs->Update(); 
   cs->cd(6); hs5->Draw("hist"); cs->Update(); 
   cs->cd(7); hs6->Draw("hist"); cs->Update(); 
   cs->cd(8); hs7->Draw("hist"); cs->Update(); 
   cs->cd(9); hs8->Draw("hist"); cs->Update(); 
   cs->cd(10); hs9->Draw("hist"); cs->Update(); 
   cs->cd(11); hs10->Draw("hist"); cs->Update(); 
   
   
   //cs->cd(2); hDat_mass->Draw("e"); cs->Update(); hs_mass->Draw("same hist"); T.DrawTextNDC(.5,.95,"Default drawing option"); 
  
   gPad->Update();
   //gPad->SetLogy(1);
   return cs;
   return cFull;
}
