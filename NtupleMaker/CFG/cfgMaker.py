#!/usr/bin/python

import sys

fileName = sys.argv[1]
mfile = open(fileName,'r')
fileList = mfile.readlines()


numFiles = len(fileList)
	
print numFiles

outputFile = "electron"

for i in range(1,numFiles/100 +1):
	fOutName = outputFile + str(i+1)+ '_cfg'
	fOut = open(fOutName, 'w')
			
	print 'import FWCore.ParameterSet.Config as cms'	
	print 'import FWCore.ParameterSet.Config as cms'
	print 'process = cms.Process("Demo")'
	print 'process.load("FWCore.MessageService.MessageLogger_cfi")'
	print 'process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )'
	print 'process.source = cms.Source("PoolSource",'
	print '  # replace \'myfile.root\' with the source file you want to use'
	print    'fileNames = cms.untracked.vstring('
	lim = 100
	if i == numFiles/100:
		lim = numFiles%100 
	for j in range(1,lim):
		if j < lim-1:
			print '\''+ fileList[(i*100)+j][:-1] +'\','
		else:
			print '\''+ fileList[(i*100)+j][:-1] +'\''
			
	print ' )'
	print ')'
	print 'process.demo = cms.EDAnalyzer(\'NtupleMaker\''
	print   ', tracks = cms.untracked.InputTag(\'generalTracks\'),'
	print   'outFile = cms.string("'+outputFile+str(i+1)+'.root'+'")'
	print  ')'
	print 'process.p = cms.Path(process.demo)'



