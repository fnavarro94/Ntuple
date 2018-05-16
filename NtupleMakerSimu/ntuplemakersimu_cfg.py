import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10000) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
       duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),
       fileNames = cms.untracked.vstring(
#       'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0013A453-7ABD-E311-AAC9-0025905A60F8.root'
   
#'file:reco.root' 




#'file:TT_320.root'

'file:simu/recosimu1.root',
'file:simu/recosimu2.root',
'file:simu/recosimu3.root',
'file:simu/recosimu4.root',
'file:simu/recosimu5.root',
'file:simu/recosimu6.root',
'file:simu/recosimu7.root',
'file:simu/recosimu8.root',
'file:simu/recosimu9.root',
'file:simu/recosimu10.root',
'file:simu/recosimu11.root',
'file:simu/recosimu12.root',
'file:simu/recosimu13.root',
'file:simu/recosimu14.root',
'file:simu/recosimu15.root',
'file:simu/recosimu16.root'
#'file:simu/DY_2032.root'

  )
)

process.demo = cms.EDAnalyzer('NtupleMakerSimu'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("exoticNtuple.root")
)


process.p = cms.Path(process.demo)
