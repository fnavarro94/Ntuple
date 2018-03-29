import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('NtupleMaker'
    ,tracks = cms.untracked.InputTag('ctfWithMaterialTracks')
)
