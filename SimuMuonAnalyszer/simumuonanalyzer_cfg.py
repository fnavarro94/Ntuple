import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )



process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.GlobalTag.connect = cms.string('sqlite_file:/cvmfs/cms-opendata-conddb.cern.ch/FT_53_LV5_AN1_RUNA.db')
#process.GlobalTag.connect = cms.string('sqlite_file:/cvmfs/cms-opendata-conddb.cern.ch/START53_LV6A1.db')
process.GlobalTag.globaltag = 'FT_53_LV5_AN1::All'
#process.GlobalTag.globaltag = 'START53_LV6A1::All'

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
'simu/recosimu10.root',
'simu/recosimu11.root',
'simu/recosimu12.root',
'simu/recosimu13.root',
'simu/recosimu14.root',
'simu/recosimu15.root',
'simu/recosimu16.root',
'simu/recosimu1.root',
'simu/recosimu2.root',
'simu/recosimu3.root',
'simu/recosimu4.root',
'simu/recosimu5.root',
'simu/recosimu6.root',
'simu/recosimu7.root',
'simu/recosimu8.root',
'simu/recosimu9.root'

   )
)

process.demo = cms.EDAnalyzer('SimuMuonAnalyzer'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("simu.root")
)


process.p = cms.Path(process.demo)
