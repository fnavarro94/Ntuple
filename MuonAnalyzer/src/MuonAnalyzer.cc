// -*- C++ -*-
//
// Package:    MuonAnalyzer
// Class:      MuonAnalyzer
// 
/**\class MuonAnalyzer MuonAnalyzer.cc Ntuple/MuonAnalyzer/src/MuonAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  
//         Created:  Thu Feb 22 02:00:06 CLST 2018
// $Id$
//
//

// system include files
#include<vector>
#include<TLorentzVector.h>
#include<cmath>
#include <memory>
#include <Math/GenVector/PxPyPzE4D.h>                                                                                                   
#include <Math/GenVector/PxPyPzM4D.h>
#include "vector"
#include "algorithm"
#include <TH1.h>
#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include "DataFormats/TrackReco/interface/TrackFwd.h"
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "HLTrigger/HLTcore/interface/HLTConfigData.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/PFJet.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"

#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"

//
// class declaration
//

class MuonAnalyzer : public edm::EDAnalyzer {
   public:
      explicit MuonAnalyzer(const edm::ParameterSet&);
      ~MuonAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endRun(edm::Run const&, edm::EventSetup const&);
      virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      
     
      
      TTree * mtree;
      TFile * mfile;
     // TH1F * h_;
      int vuelta;
      int NvertTracks = 0, Ntracks = 0;
      int numJets2 = 0;
      
      struct mEvent {

          static const Int_t entryMax = 100000;
		  Int_t eventNumer = 0;
		  Int_t runNumber = 0;
		  Int_t lumiBlock = 0;
		  Int_t numTrack =0;
		  Int_t numTrigObj=0;
		  Int_t numJets = 0;
		  Int_t numVert=0;
		  Bool_t wasTriggerFound = false;
		  Bool_t wasBeamSpotFound = false;
		  Int_t triggerFound = 0;
		  Int_t numVertTrack[entryMax]={0};
		  
		  
		// track data 
		  Double_t track_pt[entryMax] = {0};
		  Double_t track_ptError[entryMax] = {0};
		  Double_t track_px[entryMax]= {0};
		  Double_t track_pz[entryMax]= {0};
		  Double_t track_py[entryMax]= {0};
		  Double_t track_vx[entryMax]= {0};
		  Double_t track_vy[entryMax]= {0};
		  Double_t track_vz[entryMax]= {0};
		  Double_t track_chi2[entryMax] = {0};
		  Double_t track_ndof[entryMax] = {0};
		  Double_t track_eta[entryMax]= {0};
		  Double_t track_etaError[entryMax]= {0};
		  Double_t track_phi[entryMax]= {0};
		  Double_t track_phiError[entryMax]= {0};
		  Double_t track_nHits[entryMax] = {0};
		  Int_t track_n3DHits[entryMax] = {0};
		  Int_t track_nTrackerHits[entryMax] = {0};
		  Double_t track_found[entryMax] = {0};
		  Double_t track_dxy[entryMax] = {0};
		  Double_t track_dxyError[entryMax] = {0};
		  Double_t track_d0[entryMax] = {0};
		  Double_t track_d0Error[entryMax] = {0};
		  Double_t track_lxy1[entryMax] = {0};
		  Double_t track_lxy1Error[entryMax] = {0};
		  Double_t track_lxy2[entryMax] = {0};
		  Double_t track_lxy2Error[entryMax] = {0};
		  Double_t track_lxy3[entryMax] = {0};
		  Double_t track_lxy3Error[entryMax] = {0};
		  Double_t track_dz[entryMax] = {0};
		  Double_t track_dzError[entryMax] = {0};
		  Int_t track_matchedVertIndex[entryMax] = {0};    
		  Int_t track_charge[entryMax] = {0};
		  Bool_t track_highPurity[entryMax] = {0};
		  Bool_t track_tight[entryMax] = {0};   // quality lower than highPurity
		  Bool_t track_loose[entryMax] = {0};   // lowest quality
		// trigger object data (for objects passing filter)
		  Double_t trigObj_pt[entryMax] = {0};
		  Double_t trigObj_px[entryMax] = {0};
		  Double_t trigObj_pz[entryMax] = {0};
		  Double_t trigObj_py[entryMax] = {0};
		  Double_t trigObj_eta[entryMax] = {0};
		  Double_t trigObj_phi[entryMax] = {0};
		  Double_t trigObj_energy[entryMax] = {0};
		  
	    // Event data
		  Bool_t triggerActivated = false;
		  
		  Double_t vertex1Track_vx[entryMax];   //primer indice es del vertice, el segundo es el track;
		  Double_t vertex1Track_vy[entryMax];
		  Double_t vertex1Track_vz[entryMax];
		 // Double_t vertex1Track_nHits[entryMax];
		  //Double_t vertex1Track_chi2[entryMax];
		  
		  Double_t vertex2Track_vx[entryMax];   //primer indice es del vertice, el segundo es el track;
		  Double_t vertex2Track_vy[entryMax];
		  Double_t vertex2Track_vz[entryMax];
		  //Double_t vertex2Track_nHits[entryMax];
		  //Double_t vertex2Track_chi2[entryMax];
		  
		  Double_t vertex3Track_vx[entryMax];   //primer indice es del vertice, el segundo es el track;
		  Double_t vertex3Track_vy[entryMax];
		  Double_t vertex3Track_vz[entryMax];
		  //Double_t vertex3Track_nHits[entryMax];
		  //Double_t vertex3Track_chi2[entryMax];
		  
		  Double_t vertex4Track_vx[entryMax];   //primer indice es del vertice, el segundo es el track;
		  Double_t vertex4Track_vy[entryMax];
		  Double_t vertex4Track_vz[entryMax];
		  //Double_t vertex4Track_nHits[entryMax];
		  //Double_t vertex4Track_chi2[entryMax];
		  
		  Double_t vertex5Track_vx[entryMax];   //primer indice es del vertice, el segundo es el track;
		  Double_t vertex5Track_vy[entryMax];
		  Double_t vertex5Track_vz[entryMax];
		  //Double_t vertex5Track_nHits[entryMax];
		  //Double_t vertex5Track_chi2[entryMax];
		  
		  Double_t vertex6Track_vx[entryMax];   //primer indice es del vertice, el segundo es el track;
		  Double_t vertex6Track_vy[entryMax];
		  Double_t vertex6Track_vz[entryMax];
		  //Double_t vertex6Track_nHits[entryMax];
		  //Double_t vertex6Track_chi2[entryMax];
		  
		  //vertex data
		  
		  Double_t matchedVertex_x[entryMax] = {0};
		  Double_t matchedVertex_y[entryMax] = {0};
		  Double_t matchedVertex_z[entryMax] = {0};
		  Double_t matchedVertex_chi2[entryMax] = {0};
		  Double_t matchedVertex_ndof[entryMax] = {0};
		  Double_t matchedVertex_xError[entryMax] = {0};
		  Double_t matchedVertex_yError[entryMax] = {0};
		  Double_t matchedVertex_zError[entryMax] = {0};
		  
		  
		  Double_t vertex_chi2[entryMax] = {0}; 
		  Double_t vertex_ndof[entryMax] = {0}; 
		  
		  Double_t vertex_x[entryMax] = {0};             
		  Double_t vertex_y[entryMax] = {0};               
 		  Double_t vertex_z[entryMax] = {0};               
		              
		  Double_t vertex_xError[entryMax] = {0};          
		  Double_t vertex_yError[entryMax] = {0};          
		  Double_t vertex_zError[entryMax] = {0};    
		  Int_t vertex_nTracks[entryMax] = {0};      
		       
		  
		  // test
		  
		  Double_t test_leaf[entryMax] = {0};
		  
		  // Jet Data
		   
		  Double_t ak5jet_x[entryMax] = {0};
		  Double_t ak5jet_y[entryMax] = {0};
		  Double_t ak5jet_z[entryMax] = {0};
		  Double_t ak5jet_pt[entryMax] = {0};
		  Double_t ak5jet_px[entryMax] = {0};
		  Double_t ak5jet_py[entryMax] = {0};
		  Double_t ak5jet_pz[entryMax] = {0};
		  Double_t ak5jet_phi[entryMax] = {0};
		  Double_t ak5jet_eta[entryMax] = {0};
		  Double_t ak5jet_mass[entryMax] = {0};
		  char triggerPath[100];
		  char filter[100];
		  
		  //Beam spot
		  Double_t beamSpot_x = 0;
		  Double_t beamSpot_y = 0;
		  Double_t beamSpot_z = 0;
		  Double_t beamSpot_xError = 0;
		  Double_t beamSpot_yError = 0;
		  Double_t beamSpot_zError = 0;
		  
		  
		  }event,eventReset;
		  //static const struct  mEvent eventReset ;

      // ----------member data ---------------------------
      edm::InputTag trackTags_; //used to select what tracks to read from configuration file
       std::string  outFile_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor  
//
MuonAnalyzer::MuonAnalyzer(const edm::ParameterSet& iConfig)
:
 trackTags_(iConfig.getUntrackedParameter<edm::InputTag>("tracks")),
 outFile_(iConfig.getParameter<std::string>("outFile"))

{
   //now do what ever initialization is needed

}


MuonAnalyzer::~MuonAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
MuonAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;


#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
mtree->Fill();


}

// ------------ method called once each job just before starting event loop  ------------
void 
MuonAnalyzer::beginJob()
{
 vuelta = 0;
 const char* of = outFile_.c_str();
 mfile = new TFile(of, "recreate");
 mtree = new TTree("mtree","Ntuple");
 
 //mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I:track_pt[numTrack]/D:track_px[numTrack]/D:track_pz[numTrack]/D:track_py[numTrack]/D:track_vx[numTrack]/D:track_vy[numTrack]/D:track_vz[numTrack]/D:track_chi2[numTrack]/D:track_ndof[numTrack]/I:track_eta[numTrack]/D:track_phi[numTrack]/D:track_nHits[numTrack]/D:track_found[numTrack]/I:track_dxy[numTrack]/D:track_dxyError[numTrack]/D:track_dz[numTrack]/D:track_charge[numTrack]/I:track_highPurity[numTrack]/O:track_tight[numTrack]/O:track_loose[numTrack]/O:trigObj_pt[numTrigObj]/D:trigObj_px[numTrigObj]/D:trigObj_pz[numTrigObj]/D:trigObj_py[numTrigObj]/D:trigObj_eta[numTrigObj]/D:trigObj_phi[numTrigObj]/D:trigObj_energy[numTrigObj]/D:triggerActivated/O:vertexTrack_vx[numVertTrack]/D:vertexTrack_vy[numVertTrack]/D:vertexTrack_vz[numVertTrack]/D:vertexTrack_nHits[numVertTrack]/D:vertexTrack_chi2[numVertTrack]/D:vertex[numVert][6]/D");
 //mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I");

 
           mtree->Branch("Ev_Branch",&event ,"eventNumber/I:runNumber/I:lumiBlock/I:numTrack/I:numTrigObj/I:numJets/I:numVert/I:wasTriggerFound/O:wasBeamSpotFound/O:triggerFound/I");
           
		   mtree->Branch("vert_numTrack",event.numVertTrack,"numVertTrack[numVert]/I");
		   mtree->Branch("track_pt",event.track_pt,"track_pt[numTrack]/D");
		   mtree->Branch("track_ptError",event.track_ptError,"track_ptError[numTrack]/D");
		   mtree->Branch("track_px", event.track_px, "track_px[numTrack]/D");
           mtree->Branch("track_py", event.track_py, "track_py[numTrack]/D");
           mtree->Branch("track_pz", event.track_pz, "track_pz[numTrack]/D");
           mtree->Branch("track_vx", event.track_vx, "track_vx[numTrack]/D");
           mtree->Branch("track_vy", event.track_vy, "track_vy[numTrack]/D");
           mtree->Branch("track_vz", event.track_vz, "track_vz[numTrack]/D");
           mtree->Branch("track_chi2", event.track_chi2, "track_chi2[numTrack]/D");
           mtree->Branch("track_ndof", event.track_ndof, "track_ndof[numTrack]/I");
           mtree->Branch("track_eta", event.track_eta, "track_eta[numTrack]/D");
           mtree->Branch("track_etaError", event.track_etaError, "track_etaError[numTrack]/D");
           mtree->Branch("track_phi", event.track_phi, "track_phi[numTrack]/D");
           mtree->Branch("track_phiError", event.track_phiError, "track_phiError[numTrack]/D");
           mtree->Branch("track_nHits", event.track_nHits, "track_nHits[numTrack]/I");
           mtree->Branch("track_found", event.track_found, "track_nfound[numTrack]/I");
           mtree->Branch("track_n3DHits", event.track_n3DHits, "track_n3DHits[numTrack]/I");
           mtree->Branch("track_nTrackerHits", event.track_nTrackerHits, "track_nTrackerHits[numTrack]/I");
           mtree->Branch("track_dxy", event.track_dxy, "track_dxy[numTrack]/D");
           mtree->Branch("track_dxyError", event.track_dxyError, "track_dxyError[numTrack]/D");
           mtree->Branch("track_d0", event.track_d0, "track_d0[numTrack]/D");
           mtree->Branch("track_d0Error", event.track_d0Error, "track_d0Error[numTrack]/D");
           mtree->Branch("track_lxy1", event.track_lxy1, "track_lxy1[numTrack]/D");
           mtree->Branch("track_lxy1Error", event.track_lxy1Error, "track_lxy1Error[numTrack]/D");
           mtree->Branch("track_lxy2", event.track_lxy2, "track_lxy2[numTrack]/D");
           mtree->Branch("track_lxy2Error", event.track_lxy2Error, "track_lxy2Error[numTrack]/D");
           mtree->Branch("track_lxy3", event.track_lxy3, "track_lxy3[numTrack]/D");
           mtree->Branch("track_lxyError", event.track_lxy3Error, "track_lxyError[numTrack]/D");
           mtree->Branch("track_dz", event.track_dz, "track_dz[numTrack]/D");
           mtree->Branch("track_dzError", event.track_dzError, "track_dzError[numTrack]/D");
           mtree->Branch("track_charge", event.track_charge, "track_charge[numTrack]/I");
           mtree->Branch("track_highPurity", event.track_highPurity, "track_highPurity[numTrack]/O");
           mtree->Branch("track_tight", event.track_tight, "track_tight[numTrack]/O");
           mtree->Branch("track_loose", event.track_loose, "track_loose[numTrack]/O");
           mtree->Branch("track_matchedVertIndex", event.track_matchedVertIndex, "track_matchedVertIndex[numTrack]/I");
           
           mtree->Branch("trigObj_pt", event.trigObj_pt, "trigObj_pt[numTrigObj]/D");
           mtree->Branch("trigObj_px", event.trigObj_px, "trigObj_px[numTrigObj]/D");
           mtree->Branch("trigObj_py", event.trigObj_py, "trigObj_py[numTrigObj]/D");
           mtree->Branch("trigObj_pz", event.trigObj_pz, "trigObj_pz[numTrigObj]/D");
           mtree->Branch("trigObj_eta", event.trigObj_eta, "trigObj_eta[numTrigObj]/D");
           mtree->Branch("trigObj_phi", event.trigObj_phi, "trigObj_phi[numTrigObj]/D");
           mtree->Branch("triggerActivated", &event.triggerActivated, "triggerActivated/O");
           mtree->Branch("trigObj_energy", event.trigObj_energy, "trigObj_energy[numTrigObj]/O");
           
           mtree->Branch("vertex1Track_vx", event.vertex1Track_vx, "vertex1Track_vx[numVertTrack]/D");
           mtree->Branch("vertex1Track_vy", event.vertex1Track_vy, "vertex1Track_vy[numVertTrack]/D");
           mtree->Branch("vertex1Track_vz", event.vertex1Track_vz, "vertex1Track_vz[numVertTrack]/D");
            mtree->Branch("vertex2Track_vx", event.vertex2Track_vx, "vertex2Track_vx[numVertTrack]/D");
           mtree->Branch("vertex2Track_vy", event.vertex2Track_vy, "vertex2Track_vy[numVertTrack]/D");
           mtree->Branch("vertex2Track_vz", event.vertex2Track_vz, "vertex2Track_vz[numVertTrack]/D");
            mtree->Branch("vertex3Track_vx", event.vertex3Track_vx, "vertex3Track_vx[numVertTrack]/D");
           mtree->Branch("vertex3Track_vy", event.vertex3Track_vy, "vertex3Track_vy[numVertTrack]/D");
           mtree->Branch("vertex3Track_vz", event.vertex3Track_vz, "vertex3Track_vz[numVertTrack]/D");
            mtree->Branch("vertex4Track_vx", event.vertex4Track_vx, "vertex4Track_vx[numVertTrack]/D");
           mtree->Branch("vertex4Track_vy", event.vertex4Track_vy, "vertex4Track_vy[numVertTrack]/D");
           mtree->Branch("vertex4Track_vz", event.vertex4Track_vz, "vertex4Track_vz[numVertTrack]/D");
            mtree->Branch("vertex5Track_vx", event.vertex5Track_vx, "vertex5Track_vx[numVertTrack]/D");
           mtree->Branch("vertex5Track_vy", event.vertex5Track_vy, "vertex5Track_vy[numVertTrack]/D");
           mtree->Branch("vertex5Track_vz", event.vertex5Track_vz, "vertex5Track_vz[numVertTrack]/D");
            mtree->Branch("vertex6Track_vx", event.vertex6Track_vx, "vertex6Track_vx[numVertTrack]/D");
           mtree->Branch("vertex6Track_vy", event.vertex6Track_vy, "vertex6Track_vy[numVertTrack]/D");
           mtree->Branch("vertex6Track_vz", event.vertex6Track_vz, "vertex6Track_vz[numVertTrack]/D");
           mtree->Branch("matchedVertex_x", event.matchedVertex_x, "matchedVertex_x[numVertTrack]/D");
           mtree->Branch("matchedVertex_xError", event.matchedVertex_xError, "matchedVertex_xError[numVertTrack]/D");
           mtree->Branch("matchedVertex_y", event.matchedVertex_y, "matchedVertex_y[numVertTrack]/D");
           mtree->Branch("matchedVertex_yError", event.matchedVertex_yError, "matchedVertex_yError[numVertTrack]/D");
           mtree->Branch("matchedVertex_z", event.matchedVertex_z, "matchedVertex_z[numVertTrack]/D");
           mtree->Branch("matchedVertex_zError", event.matchedVertex_zError, "matchedVertex_zError[numVertTrack]/D");
           mtree->Branch("matchedVertex_chi2", event.matchedVertex_chi2, "matchedVertex_chi2[numVertTrack]/D");
           mtree->Branch("matchedVertex_ndof", event.matchedVertex_ndof, "matchedVertex_ndof[numVertTrack]/D");


           //mtree->Branch("test_leaf", event.test_leaf, "test_leaf[numVert]/D");
           
         
           mtree->Branch("vertex_chi2", event.vertex_chi2, "vertex_chi2[numVert]/D");
           mtree->Branch("vertex_ndof", event.vertex_ndof, "vertex_nodf[numVert]/D");
           mtree->Branch("vertex_x", event.vertex_x, "vertex_x[numVert]/D");
           mtree->Branch("vertex_y", event.vertex_y, "vertex_y[numVert]/D");
           mtree->Branch("vertex_z", event.vertex_z, "vertex_z[numVert]/D");
           mtree->Branch("vertex_xError", event.vertex_xError, "vertex_xError[numVert]/D");
           mtree->Branch("vertex_yError", event.vertex_yError, "vertex_yError[numVert]/D");
           mtree->Branch("vertex_zError", event.vertex_zError, "vertex_zError[numVert]/D");
           mtree->Branch("vertex_nTracks", event.vertex_nTracks, "vertex_nTracks[numVert]/D");
           
           mtree->Branch("ak5jet_x", event.ak5jet_x, "ak5jet_x[numJets]/D");
           mtree->Branch("ak5jet_y", event.ak5jet_y, "ak5jet_y[numJets]/D");
           mtree->Branch("ak5jet_z", event.ak5jet_z, "ak5jet_z[numJets]/D");
           mtree->Branch("ak5jet_pt", event.ak5jet_pt, "ak5jet_pt[numJets]/D");
           mtree->Branch("ak5jet_px", event.ak5jet_px, "ak5jet_px[numJets]/D");
           mtree->Branch("ak5jet_py", event.ak5jet_py, "ak5jet_py[numJets]/D");
           mtree->Branch("ak5jet_pz", event.ak5jet_pz, "ak5jet_pz[numJets]/D");
           mtree->Branch("ak5jet_phi", event.ak5jet_phi, "ak5jet_phi[numJets]/D");
           mtree->Branch("ak5jet_eta", event.ak5jet_eta, "ak5jet_eta[numJets]/D");
           mtree->Branch("ak5jet_mass", event.ak5jet_mass, "ak5jet_mass[numJets]/D");
           
           mtree->Branch("triggerPath", event.triggerPath, "triggerPath[100]/C");
           mtree->Branch("filter", event.filter, "filter[100]/C");
		  
		  
		  mtree->Branch("beamSpot_x", &event.beamSpot_x, "beamSpot_x/D");
          mtree->Branch("beamSpot_y", &event.beamSpot_y, "beamSpot_y/D");
          mtree->Branch("beamSpot_z", &event.beamSpot_z, "beamSpot_z/D");
           
          mtree->Branch("beamSpot_xError", &event.beamSpot_xError, "beamSpot_xError/D");
          mtree->Branch("beamSpot_yError", &event.beamSpot_yError, "beamSpot_yError/D");
          mtree->Branch("beamSpot_zError", &event.beamSpot_zError, "beamSpot_zError/D");
		  
	
		
		
}




           


          


// ------------ method called once each job just after ending the event loop  ------------
void 
MuonAnalyzer::endJob() {

//mtree->Write();
//std::cout<<"num traks "<<Ntracks<<" num vertTraks "<<NvertTracks<<std::endl;
mfile->Write();
mfile->Close();
}

// ------------ method called when starting to processes a run  ------------
void 
MuonAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
MuonAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
MuonAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
MuonAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MuonAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

 //Specify that only 'tracks' is allowed
 //To use, remove the default given above and uncomment below
 //ParameterSetDescription desc;
 //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
 //descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MuonAnalyzer);
