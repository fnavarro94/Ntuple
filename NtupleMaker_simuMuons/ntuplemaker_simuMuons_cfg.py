import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
       'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0013A453-7ABD-E311-AAC9-0025905A60F8.root'
   
    )
)

process.demo = cms.EDAnalyzer('NtupleMaker_simuMuons'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("muonsSimu.root")
)


process.p = cms.Path(process.demo)
