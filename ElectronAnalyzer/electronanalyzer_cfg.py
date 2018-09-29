import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )



process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')



#from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag,'FT_53_LV5_AN1::All', '')



process.GlobalTag.connect = cms.string('sqlite_file:/cvmfs/cms-opendata-conddb.cern.ch/FT_53_LV5_AN1_RUNA.db')
#process.GlobalTag.connect = cms.string('sqlite_file:/cvmfs/cms-opendata-conddb.cern.ch/START53_LV6A1.db')
process.GlobalTag.globaltag = 'FT_53_LV5_AN1::All'
#process.GlobalTag.globaltag = 'START53_LV6A1::All'

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/02B69E3F-8239-E311-8297-003048F0E39E.root'
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0020AF81-A835-E311-97DC-00261894398C.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0062BD79-9235-E311-9320-003048FFCC2C.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/008B0182-5E35-E311-B039-003048FFD71E.root',3'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/009A5FA1-0D36-E311-B603-00261894388A.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/009A5FA1-0D36-E311-B603-00261894388A.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/00ADCF5D-7435-E311-9347-00261894397A.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/00C4AE70-4335-E311-9743-0026189438D9.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/00EF5A25-6235-E311-8D64-002618B27F8A.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0200DC35-9535-E311-8AE6-003048678B34.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02495C0E-3A35-E311-A75D-003048678BE6.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02A4FDA7-7135-E311-AEAB-003048FFCBFC.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02A5EA3E-6F35-E311-9232-003048678F8A.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02CC8DC7-9435-E311-8DDD-0026189438F3.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02DC4EAD-9235-E311-B0C3-002618943985.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/02F46E80-7335-E311-B046-003048FFD732.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/041E647E-5435-E311-8A79-002618943856.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/04302453-1136-E311-95F0-00261894393E.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0467D790-6C35-E311-B1DA-003048678FEA.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/04695FC2-5B35-E311-AADF-003048FF9AA6.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/046B867E-A835-E311-B2E8-003048FFD728.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/0490CFDC-4A35-E311-85B6-002618943920.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/049A90E4-6835-E311-A384-003048678BEA.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/04F1C9E5-A935-E311-9F92-002618943945.root',

#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/061185A7-6A35-E311-A8D1-003048678FEA.root',
#'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/DoubleMu/AOD/12Oct2013-v1/10000/062E45B5-1036-E311-9CA0-0025905964BA.root'  
    )
)

process.demo = cms.EDAnalyzer('ElectronAnalyzer'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("electron.root"),
      processName = cms.string("HLT"),
                              triggerName = cms.string("@"),         
                              datasetName = cms.string("SingleMu"),           
                              triggerResults = cms.InputTag("TriggerResults","","HLT"),
                              triggerEvent   = cms.InputTag("hltTriggerSummaryAOD","","HLT")        
)

#process.gettriggerinfo = cms.EDAnalyzer('TriggerInfoAnalyzer',
#                              processName = cms.string("HLT"),
#                              triggerName = cms.string("@"),         
#                              datasetName = cms.string("SingleMu"),           
#                              triggerResults = cms.InputTag("TriggerResults","","HLT"),
#                              triggerEvent   = cms.InputTag("hltTriggerSummaryAOD","","HLT")                             
#                              )


#process.triggerinfo = cms.Path(process.gettriggerinfo)
process.p = cms.Path(process.demo)
