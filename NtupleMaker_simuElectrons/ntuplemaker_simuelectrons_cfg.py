import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
    
    'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0013A453-7ABD-E311-AAC9-0025905A60F8.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/00846A75-09BC-E311-9D9F-002618FDA279.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/046B655D-F5BB-E311-B6A8-003048679214.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/0EEE04BF-FDBB-E311-9E20-0025905A60E4.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/144334CD-00BC-E311-8BF0-0025905A60D0.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/14837FAD-EABB-E311-A422-0025905A6064.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/168D3005-F9BB-E311-9551-002590596490.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/1A1CC59D-EDBB-E311-B9D5-003048678F84.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/1A455B55-F4BB-E311-B68E-002618943908.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/1CA3EAE7-D1BB-E311-8ED1-002618943913.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/1E050ACA-F3BB-E311-9BFA-0025905A60D6.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/2057C4C3-FFBB-E311-96D1-0025905A607E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WZJetsTo3LNu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v1/00000/24E63A07-08BC-E311-87F0-0025905A497A.root'
      
    )
)

process.demo = cms.EDAnalyzer('NtupleMaker_simuElectrons'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("electronSimu.root")
)


process.p = cms.Path(process.demo)
