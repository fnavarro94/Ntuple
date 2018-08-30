import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )



process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#process.GlobalTag.connect = cms.string('sqlite_file:/cvmfs/cms-opendata-conddb.cern.ch/FT_53_LV5_AN1_RUNA.db')
process.GlobalTag.connect = cms.string('sqlite_file:/cvmfs/cms-opendata-conddb.cern.ch/START53_LV6A1.db')
#process.GlobalTag.globaltag = 'FT_53_LV5_AN1::All'
process.GlobalTag.globaltag = 'START53_LV6A1::All'

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),
    fileNames = cms.untracked.vstring(
'file:simu/recofile:simu10.root',
'file:simu/recofile:simu11.root',
'file:simu/recofile:simu12.root',
'file:simu/recofile:simu13.root',
'file:simu/recofile:simu14.root',
'file:simu/recofile:simu15.root',
'file:simu/recofile:simu16.root',
'file:simu/recofile:simu1.root',
'file:simu/recofile:simu2.root',
'file:simu/recofile:simu3.root',
'file:simu/recofile:simu4.root',
'file:simu/recofile:simu5.root',
'file:simu/recofile:simu6.root',
'file:simu/recofile:simu7.root',
'file:simu/recofile:simu8.root',
'file:simu/recofile:simu9.root'

   )
)

process.demo = cms.EDAnalyzer('SimuMuonAnalyzer'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("file:simu.root")
)


process.p = cms.Path(process.demo)
