#!/usr/bin/python

import sys

outputFile = str(sys.argv[4])
fileName = sys.argv[1]
mfile = open(fileName,'r')
fileList = mfile.readlines()
chainRun = open(outputFile + "_chain.sh",'w')
for y in range(0,50):
	chainRun = open(outputFile + "_chain"+str(y)+".sh",'w')
	print>>chainRun, '#!/bin/bash'
	for j in range(1,21):
		fBash = open(outputFile +str(int(sys.argv[2])+5*(20*y+j-1))+"-"+str(int(sys.argv[3])*(20*y+j))+".sh", 'w')


		print >>chainRun, './'+outputFile +str(int(sys.argv[2])+5*(j+20*y-1))+"-"+str(int(sys.argv[3])*(j+20*y))+".sh" ' &' 
		print>>fBash, '#!/bin/bash'
		numFiles = len(fileList)
		
		print numFiles

		groupSize = 3;


		count = 0

		for i in range(int(sys.argv[2])+5*(j+20*y-1), int(sys.argv[3])*(j+20*y)):
			print i
			fOutName = outputFile + str(i+1)+ '_cfg.py'
			fOut = open(fOutName, 'w')
			print>> fBash, 'echo "run ' +str(i+1)+ ' of ' +str(numFiles/groupSize +1) + '"'
			print>> fBash,  "cmsRun "+ fOutName+ '> '+outputFile + str(i+1) + '.log 2>&1'
			print>> fBash, "sed -i '/Begin processing the/d'  run" + str(i+1) + ".log" 
			print>> fBash, "mv " + outputFile+str(i+1)+'.root'+ " /eos/user/f/fnavarro/ZZ4L/ && echo \"done\""
			#print>> fBash, 'echo tailing file ' +str(i+1)
			#print >> fBash, 'tailf run' + str(i) + '.log '
			#print >> fBash, '^C'
		
			print>> fOut, 'import FWCore.ParameterSet.Config as cms'	
			print>> fOut, 'import FWCore.ParameterSet.Config as cms'
			print>> fOut, 'process = cms.Process("Demo")'
			print>> fOut, 'process.load("FWCore.MessageService.MessageLogger_cfi")'
			print>> fOut, 'process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )'
			print>> fOut, 'process.source = cms.Source("PoolSource",'
			print>> fOut, '  # replace \'myfile.root\' with the source file you want to use'
			print >> fOut,   'fileNames = cms.untracked.vstring('
			lim = groupSize
			if i == numFiles/groupSize:
				lim = numFiles%groupSize
			for j in range(0,lim ):
				#print j
				count = count +1
				if j < lim:
					print>> fOut, '\''+ fileList[(i*groupSize)+j ][:-1] +'\','
				else:
					print j
					print >> fOut, '\''+ fileList[(i*groupSize)+j ][:-1] +'\''
					
			print >> fOut, ' )'
			print >> fOut,')'
			print >> fOut,'process.demo = cms.EDAnalyzer(\'NtupleMakerMuon\''
			print  >> fOut, ', tracks = cms.untracked.InputTag(\'generalTracks\'),'
			print  >> fOut, 'outFile = cms.string("'+outputFile+str(i+1)+'.root'+'")'
			print >> fOut, ')'
			print>> fOut, 'process.p = cms.Path(process.demo)'
		
		
		print count



