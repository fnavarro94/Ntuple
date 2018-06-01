


paramList = ["lxy","lxyLoose", "lxy_err","lxy_errLoose", "InvMass", "InvMassLoose", "InvMassLW", "d0_err", "d0_errLoose","dxy_err", "dxy_errLoose", 
               "cos","cosLoose", "delPhi", "delPhiLoose","conePt", "chi2_NDF","chi2_NDF", "chi2_NDFLoose", "numHitsLoose", "h_dot"]

dataSetList = ["ZZ", "WZ", "WW","DY"]
dataSetColor = ["kGreen +3", "kCyan -9","kMagenta -3","2"]
otherSetList = ["ll","Dat"]
mfile = open('plotter.cxx','w')

#THStacks


print >> mfile, "{ \n"

print >>mfile, "double lumi = 5100.227976804;  //   1/pb" + "\n"

for param in paramList:
	print >> mfile, "THStack *hs_" + param + " = new THStack(\"hs_"+  param + "\", \"\");"
	
print>> mfile, " \n \n"

for dset in dataSetList:
	print >> mfile, "TFile *f"+dset+" = new TFile(\""+dset+"bg.root\");"
	
for dset in otherSetList:
	print >> mfile, "TFile *f"+dset+" = new TFile(\""+dset+".root\");"
	
print>> mfile, " \n \n"

for param in paramList:
	for dset in dataSetList:
		
		print >> mfile, "TH1F * h"+dset+"_"+param+ "= (TH1F*)f"+dset+"->Get(\""+param+"\");" 
		#TH1F * hDY_lx_err = (TH1F*)fDY->Get("lxy_err"); 
	print >> mfile , "\n"
for param in paramList:
	for dset in otherSetList:
		
		print >> mfile, "TH1F * h"+dset+"_"+param+ "= (TH1F*)f"+dset+"->Get(\""+param+"\");" 
		#TH1F * hDY_lx_err = (TH1F*)fDY->Get("lxy_err"); 
	print >> mfile , "\n"

for param in paramList:
	for dset in dataSetList:
			print >> mfile , "h"+dset+"_"+param+"->Sumw2();"
		
	print >> mfile, "\n"
	
for param in paramList:
	for dset in otherSetList:
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


print >> mfile, "double DY_scale = lumi*3048.0/(hDY->Integral());"
print >> mfile, "double ZZ_scale = lumi*5.9/(hZZ->Integral());"
print >> mfile, "double WZ_scale = lumi*18.2/(hWZ->Integral());"
print >> mfile, "double WW_scale = lumi*42.0/(hWW->Integral());"
print >> mfile, "\n"


for param in paramList:
	for dset in dataSetList:
			print >> mfile , "h"+dset+"_"+param+"->Scale("+dset+"_scale);"
		
	print >> mfile, "\n"

for param in paramList:
	for dset in dataSetList:
			print >> mfile , "h"+dset+"_"+param+"->SetStats(0);"
		
	print >> mfile, "\n"

for param in paramList:
	for dset in dataSetList:
		print >> mfile , "hs_"+param+"->Add(h"+dset+"_"+param+");"
		
	print >> mfile, "\n"




print >> mfile, " \n }"
