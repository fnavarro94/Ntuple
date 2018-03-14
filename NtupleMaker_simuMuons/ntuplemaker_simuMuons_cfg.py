import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
       
   
    )
)

process.demo = cms.EDAnalyzer('NtupleMaker_simuMuons'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("muonsSimu.root")
)


process.p = cms.Path(process.demo)
