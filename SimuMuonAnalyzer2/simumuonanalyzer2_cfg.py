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
#'file:simu/recosimu10.root',
#'file:simu/recosimu11.root',
#'file:simu/recosimu12.root',
#'file:simu/recosimu13.root',
#'file:simu/recosimu14.root',
#'file:simu/recosimu15.root',
#'file:simu/recosimu16.root',
#'file:simu/recosimu1.root',
#'file:simu/recosimu2.root',
#'file:simu/recosimu3.root',
#'file:simu/recosimu4.root',
#'file:simu/recosimu5.root',
#'file:simu/recosimu6.root',
#'file:simu/recosimu7.root',
#'file:simu/recosimu8.root',
#'file:simu/recosimu9.root'
'file:lee_wick_5/lw5_1.root',
'file:lee_wick_5/lw5_2.root',
'file:lee_wick_5/lw5_3.root',
'file:lee_wick_5/lw5_4.root',
'file:lee_wick_5/lw5_5.root',
'file:lee_wick_5/lw5_6.root',
'file:lee_wick_5/lw5_7.root',
'file:lee_wick_5/lw5_8.root',
'file:lee_wick_5/lw5_9.root',
'file:lee_wick_5/lw5_10.root',
'file:lee_wick_5/lw5_11.root',
'file:lee_wick_5/lw5_12.root',
'file:lee_wick_5/lw5_13.root',
'file:lee_wick_5/lw5_14.root',
'file:lee_wick_5/lw5_15.root',
'file:lee_wick_5/lw5_16.root'





   )
)

process.demo = cms.EDAnalyzer('SimuMuonAnalyzer2'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("file:simu.root")
)


process.p = cms.Path(process.demo)
