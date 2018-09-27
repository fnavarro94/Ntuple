from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'WWJ2L_analisis'
config.General.workArea = 'crabWWJ2L'
config.General.transferOutputs = True
config.General.transferLogs = False
#config.JobType.scriptExe = 'myscript.sh'
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'simumuonanalyzer_cfg.py'
config.JobType.maxJobRuntimeMin = 1000
#config.JobType.inputFiles = ['list.txt','pyScript.py']
config.JobType.outputFiles = ['simu.root']
#config.Data.inputDataset = '/SingleElectron/Run2011A-12Oct2013-v1/AOD'
#config.Data.inputDataset = '/EG/Run2010A-Apr21ReReco-v1/AOD'
config.Data.userInputFiles = ['root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/00530C57-ACB7-E311-BA79-0025905964C4.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/02AEDE1A-AFB7-E311-A90F-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/04369C42-B3B7-E311-A204-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/0844E46F-B8B7-E311-99DA-003048FFCC18.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/0AE79929-AEB7-E311-9B3F-003048FF9AC6.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/0CC39189-9BB7-E311-AAC2-0025905A605E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/10ED9148-A4B7-E311-96C0-0025905964B2.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/12B1A91D-B5B7-E311-87E6-003048FFCC0A.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/18AEAE34-AAB7-E311-B458-003048FFD752.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/1AAC4A1A-92B7-E311-92A0-0025905AA9F0.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/1CBA85C8-B6B7-E311-AB46-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/1E0695AB-ADB7-E311-A95A-003048FFCC1E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/2645A973-85B7-E311-8E38-0025905A608C.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/26C8DB89-AFB7-E311-827D-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/26CD3BCD-B6B7-E311-A790-0025905A609A.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/2827033A-B8B7-E311-95EB-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/2C300C31-B5B7-E311-98B2-003048FFD770.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/3036FF2B-B8B7-E311-B04C-003048FFCC0A.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/3A4F2B46-C2B7-E311-B816-003048FFD79C.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/3E0B98A7-98B7-E311-87A0-0025905A60B4.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/4085B028-B5B7-E311-B8CE-003048FFCC1E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/46A96521-B5B7-E311-B0CB-0025905A6094.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/50E45CB6-B6B7-E311-A5FF-003048FFD770.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/54CDF438-B9B7-E311-B810-003048FFD770.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/5653C5BD-9FB7-E311-9ACB-0025905964BA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/5A17DEE0-A5B7-E311-A8FC-0025905964CC.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/605147AE-A7B7-E311-95AD-0025905964CC.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/6088D0A9-7DB7-E311-BD6C-0025905A6082.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/648A8F2F-B5B7-E311-9C09-0025905A609A.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/688E19EB-B7B7-E311-AEFD-0025905A6094.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/689BD4BA-B6B7-E311-994B-003048FFCC0A.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/70D895F0-ACB7-E311-A5F2-0025905964CC.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/76B8C072-ABB7-E311-84C9-003048FFCC1E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/780BC03E-AEB7-E311-9054-002590596468.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/8207851E-AEB7-E311-89C1-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/8486ECC9-A6B7-E311-A40D-0025905964CC.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/86939620-B5B7-E311-9ABE-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/88326085-8BB7-E311-A7D0-0025905A6118.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/8A132A2D-BEB7-E311-A193-003048FF9AC6.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/8AD9C6DC-A1B7-E311-9865-002590593878.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/94A6C22A-B8B7-E311-BA05-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/9A243C69-B3B7-E311-8DDB-003048FFD770.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/9E96412A-B8B7-E311-9A3C-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/A0D39C27-CBB7-E311-BD14-003048FFD79C.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/A2795476-B8B7-E311-9C13-003048FFCC1E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/A8F56E30-B7B7-E311-BA24-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/AA12EDF6-B7B7-E311-BBD9-0025905A609A.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/AE3F8103-AAB7-E311-BA11-003048FFCC1E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/B2EEAF30-B9B7-E311-983C-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/B65E13A7-B6B7-E311-AB25-003048FFD770.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/B89439B7-9DB7-E311-8A02-003048FFD79C.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/BC47B431-B5B7-E311-A1DA-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/C2099AE6-ACB7-E311-829F-002590596468.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/C63A9742-BFB7-E311-9818-0025905A6080.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/CC40B2BF-B6B7-E311-9BEB-003048FFCC1E.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/D6799ABC-B6B7-E311-8B4D-0025905A6094.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/D89B3430-B7B7-E311-B57B-003048FFCC18.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/DE19EE9A-AFB7-E311-A11A-0025905A610C.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/E25399EF-B7B7-E311-A1E7-003048FFD770.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/E2907918-AEB7-E311-B113-0025905A610C.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/E42D8118-BCB7-E311-872E-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/EE031242-B8B7-E311-ADED-003048FFD770.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/F08C19ED-B6B7-E311-8CEC-003048FF86CA.root',
'root://eospublic.cern.ch//eos/opendata/cms/MonteCarlo2011/Summer11LegDR/WWJetsTo2L2Nu_TuneZ2_7TeV-madgraph-tauola/AODSIM/PU_S13_START53_LV6-v2/00000/F4246840-BAB7-E311-B4CB-003048FFCC0A.root',

]
config.Data.publication = False
#config.Data.userInputFiles = ['dummy.root']
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 150


config.Site.storageSite = 'T2_US_Nebraska'
config.section_("Debug")
#config.Debug.extraJDL = [ '+DESIRED_Sites="T3_CH_Opportunistic_opendata"','+JOB_CMSSite="T3_CH_Opportunistic_opendata"']