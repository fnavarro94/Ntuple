import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/10000/AC980FCC-943D-E311-A1D6-003048F11824.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/10000/B4770060-823E-E311-BA5E-02163E007964.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/10000/BA973944-5D3E-E311-AE63-02163E0079A0.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/110000/744EEF92-843D-E311-8B2C-02163E008CDB.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/009BB2E2-F738-E311-A58F-002481E0E184.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/00FAFD3C-F338-E311-839A-00215AEDFF9A.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/00FE3991-E138-E311-AB14-02163E008CCC.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/024DEE9D-F738-E311-92E5-02163E008D95.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/025CBF72-7E39-E311-9257-003048CF96DA.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/0279A787-EC38-E311-817B-5404A63886AC.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/027C492F-0439-E311-B4F0-C860001BD85E.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/029C6224-8A39-E311-BC15-5404A63886C6.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/02A4238E-B238-E311-81C5-02163E00BB69.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/02B69E3F-8239-E311-8297-003048F0E39E.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/02C22832-7239-E311-9A58-003048F17282.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/02C81C85-2539-E311-85F6-003048CF8CDC.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/02DEE65D-8B38-E311-BD46-02163E008D9D.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/0418B4AC-7D39-E311-9195-003048F1BF76.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/04251EF7-7539-E311-AFCA-003048F0258E.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/0430400B-B838-E311-802D-003048F0116C.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/04341542-0239-E311-BBF0-002590496FE6.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/0435F7CD-3839-E311-BB3F-BCAEC5364C42.root',
'root://eospublic.cern.ch//eos/opendata/cms/Run2011A/Photon/AOD/12Oct2013-v1/20000/043C49BF-B738-E311-A1E6-002481E0E9D4.root'
   
    )
)

process.demo = cms.EDAnalyzer('NtupleMaker'
    , tracks = cms.untracked.InputTag('generalTracks'),
      outFile = cms.string("electron.root")
)


process.p = cms.Path(process.demo)
