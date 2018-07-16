


paramList = ["lxy","lxyLoose", "lxy_err","lxy_errLoose", "InvMass", "InvMassLoose", "InvMassLW", "d0_err", "d0_errLoose","dxy_err", "dxy_errLoose", 
               "cos","cosLoose", "delPhi", "delPhiLoose","conePt", "chi2_NDF","chi2_NDF", "chi2_NDFLoose", "numHitsLoose", "h_dot"]

dataSetList = ["ZZ", "WZ", "WW","DY"]
dataSimuSetList = ["ZZ", "WZ", "WW","DY","ll"]
dataSetColor = ["kGreen +3", "kCyan -9","kMagenta -3","2"]
otherSetList = ["ll","Dat"]
completeList = ["ZZ", "WZ", "WW","DY","ll","Dat"]
mfile = open('plottertemp.cxx','w')

#THStacks


print >> mfile, "{ \n"

print >>mfile, "double lumi = 2333.286137;  //   1/pb" + "\n"

for param in paramList:
	print >> mfile, "THStack *hs_" + param + " = new THStack(\"hs_"+  param + "\", \"\");"
	
print>> mfile, " \n \n"

for dset in dataSetList:
	print >> mfile, "TFile *f"+dset+" = new TFile(\""+dset+"M.root\");"
	
for dset in otherSetList:
	print >> mfile, "TFile *f"+dset+" = new TFile(\""+dset+"M.root\");"
	
print>> mfile, " \n \n"

for param in paramList:
	for dset in completeList:
		
		print >> mfile, "TH1F * h"+dset+"_"+param+ "= (TH1F*)f"+dset+"->Get(\""+param+"\");" 
		#TH1F * hDY_lx_err = (TH1F*)fDY->Get("lxy_err"); 
	print >> mfile , "\n"


for param in paramList:
	for dset in completeList:
			print >> mfile , "h"+dset+"_"+param+"->Sumw2();"
		
	print >> mfile, "\n"
	

	
for param in paramList:
	for dset in dataSetList:
			print >> mfile , "h"+dset+"_"+param+"->SetLineColor(1);"
		
	print >> mfile, "\n"
	
for param in paramList:
	i = 0
	for dset in dataSetList:
		print >> mfile , "h"+dset+"_"+param+"->SetFillColor("+dataSetColor[i]+");"
		i = i+1
	print >> mfile, "\n"
for param in paramList:
	print >> mfile, "hDat_"+param+"->SetMarkerStyle(21);"
	print >> mfile, "hDat_"+param+"->SetMarkerSize(1);"
	print >> mfile, "hDat_"+param+"->SetLineColor(1);"
	print >> mfile, "hll_"+param+"->SetLineColor(2);"

print >> mfile, "double DY_scale = lumi*3048.0/(hDY_lxy->Integral());"
print >> mfile, "double ZZ_scale = lumi*5.9/(hZZ_lxy->Integral());"
print >> mfile, "double WZ_scale = lumi*18.2/(hWZ_lxy->Integral());"
print >> mfile, "double WW_scale = lumi*42.0/(hWW_lxy->Integral());"
print >> mfile, "\n"


for param in paramList:
	for dset in dataSetList:
			print >> mfile , "h"+dset+"_"+param+"->Scale("+dset+"_scale);"
		
	print >> mfile, "\n"

for param in paramList:
	for dset in completeList:
			print >> mfile , "h"+dset+"_"+param+"->SetStats(0);"
		
	print >> mfile, "\n"

for param in paramList:
	for dset in dataSetList:
		print >> mfile , "hs_"+param+"->Add(h"+dset+"_"+param+");"
		
	print >> mfile, "\n"



print >> mfile, "double m1, m2, m3, mMax;"

for param in paramList:
	
  
  print >>mfile, "m1 = hDat_"+param+"->GetMaximum();"
  print >>mfile, "m2 = hll_"+param+"->GetMaximum();"
  print >>mfile, "m3 = hs_"+param+"->GetMaximum();"

  print >>mfile, "mMax = m1;"

  print >>mfile,"if (mMax<m2)"
  print >>mfile,"{"	
  print >>mfile,	"mMax = m2;"
  print >>mfile,"}"

  print >>mfile,"if(mMax < m3)"
  print >>mfile,"{"
  print >>mfile,	"mMax = m3;"
  print >>mfile,	"}"	
  print >> mfile,    "hll_"+param+"->SetMaximum(2*mMax);"
  print >> mfile, "TCanvas *cs_"+param+" = new TCanvas(\"cs_"+param+"\",\"cs_"+param+"\",10,10,700,900);"
  print >> mfile,  "TText T; T.SetTextFont(42); T.SetTextAlign(21);"
  print >> mfile,  "hs_"+param+"->SetTitle(\"" +param+ "\");"
  print >> mfile,  "auto legend_"+param+" = new TLegend(0.5,0.7,0.9,0.9);"
  
  print >> mfile,   "legend_"+param+"->AddEntry(hDY_"+param+",\"Z/#gamma*#rightarrow #mu#mu\",\"f\");"
  print >> mfile,   "legend_"+param+"->AddEntry(hWW_"+param+",\"WW\",\"f\");"
  print >> mfile,   "legend_"+param+"->AddEntry(hWZ_"+param+",\"WZ\",\"f\");"
  print >> mfile,   "legend_"+param+"->AddEntry(hZZ_"+param+",\"ZZ\",\"f\");"
  print >> mfile,   "legend_"+param+"->AddEntry(hDat_"+param+",\"Data\",\"p\");"
  
  print >> mfile,  "legend_"+param+"->SetFillColor(0);"
 # print >> mfile,  "hDat_"+param+"->SetMaximum(2*hs_"+param+"->GetMaximum());"
  print >> mfile,  "hDat_"+param+"->SetXTitle(\"mass [GeV/c^{2}]\");"
  print >> mfile,  "hDat_"+param+"->SetYTitle(\"Entries\");"
  print >> mfile,  "cs_"+param+"->cd(1); hll_"+param+"->Draw(\"hist eX0\"); cs_"+param+"->Update(); hs_"+param+"->Draw(\"same hist eX0\"); cs_"+param+"->Update(); hDat_"+param+"->Draw(\"same  eX0\");"
  print >> mfile,  "// cs->cd(1);  hs_"+param+"->Draw(\" hist\"); cs->Update(); hDat_"+param+"->Draw(\"hist same\");"
 
  print >> mfile, "legend_"+param+"->Draw();" 
   
  print >> mfile,   "gPad->Update();"
  print >> mfile,  "gPad->SetLogy(1);"
  print >> mfile, "\n"



print >> mfile, " \n }"
