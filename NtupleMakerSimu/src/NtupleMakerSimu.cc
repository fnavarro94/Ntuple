// -*- C++ -*-
//
// Package:    NtupleMakerSimu
// Class:      NtupleMakerSimu
// 
/**\class NtupleMakerSimu NtupleMakerSimu.cc Ntuple/NtupleMakerSimu/src/NtupleMakerSimu.cc

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

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
//
// class declaration
//

class NtupleMakerSimu : public edm::EDAnalyzer {
   public:
      explicit NtupleMakerSimu(const edm::ParameterSet&);
      ~NtupleMakerSimu();

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
      int triggerTurnOns = 0;
      
      struct mEvent {

          static const Int_t entryMax = 10000;
		  Int_t eventNumer = 0;
		  Int_t runNumber = 0;
		  Int_t lumiBlock = 0;
		  Int_t numTrack =0;
		  Int_t numTrigObjE=0;
		  Int_t numTrigObjM=0;
		  Int_t numJets = 0;
		  Int_t numVert=0;
		  Bool_t wasTriggerFound = false;
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
		  Double_t track_found[entryMax] = {0};
		  Double_t track_dxy[entryMax] = {0};
		  Double_t track_d0[entryMax] = {0};
		  Double_t track_d0Error[entryMax] = {0};
		  Double_t track_dxyError[entryMax] = {0};
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
		  Double_t trigObjE_pt[entryMax] = {0};
		  Double_t trigObjE_px[entryMax] = {0};
		  Double_t trigObjE_pz[entryMax] = {0};
		  Double_t trigObjE_py[entryMax] = {0};
		  Double_t trigObjE_eta[entryMax] = {0};
		  Double_t trigObjE_phi[entryMax] = {0};
		  Double_t trigObjE_energy[entryMax] = {0};
		  
		   Double_t trigObjM_pt[entryMax] = {0};
		  Double_t trigObjM_px[entryMax] = {0};
		  Double_t trigObjM_pz[entryMax] = {0};
		  Double_t trigObjM_py[entryMax] = {0};
		  Double_t trigObjM_eta[entryMax] = {0};
		  Double_t trigObjM_phi[entryMax] = {0};
		  Double_t trigObjM_energy[entryMax] = {0};
		  
		  
	    // Event data
		  Bool_t triggerEActivated = false;
		  Bool_t triggerMActivated = false;
		  
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
		 // char filter[100];
		  
		  // generated particles data
		  
		  Double_t genMu_phi[2] = {0};
		  Double_t genMu_eta[2] = {0};
		  Double_t genMu_pt[2] = {0};
		  Double_t genMu_px[2] = {0};
		  Double_t genMu_py[2] = {0};
		  Double_t genMu_pz[2] = {0};
		  
		  Double_t genMuBar_phi[2] = {0};
		  Double_t genMuBar_eta[2] = {0};
		  Double_t genMuBar_pt[2] = {0};
		  Double_t genMuBar_px[2] = {0};
		  Double_t genMuBar_py[2] = {0};
		  Double_t genMuBar_pz[2] = {0};
		  
		  Double_t genVert[3] = {0};
		  
		  
		  
		  Double_t ZZgenMu_phi[2] = {0};
		  Double_t ZZgenMu_eta[2] = {0};
		  Double_t ZZgenMu_pt[2] = {0};
		  Double_t ZZgenMu_px[2] = {0};
		  Double_t ZZgenMu_py[2] = {0};
		  Double_t ZZgenMu_pz[2] = {0};
		  
		  Double_t ZZgenMuBar_phi[2] = {0};
		  Double_t ZZgenMuBar_eta[2] = {0};
		  Double_t ZZgenMuBar_pt[2] = {0};
		  Double_t ZZgenMuBar_px[2] = {0};
		  Double_t ZZgenMuBar_py[2] = {0};
		  Double_t ZZgenMuBar_pz[2] = {0};
		  
		  Double_t ZZgenVert[3] = {0};
		  
		  
		  Double_t WWgenMu_phi[2] = {0};
		  Double_t WWgenMu_eta[2] = {0};
		  Double_t WWgenMu_pt[2] = {0};
		  Double_t WWgenMu_px[2] = {0};
		  Double_t WWgenMu_py[2] = {0};
		  Double_t WWgenMu_pz[2] = {0};
		  
		  Double_t WWgenMuBar_phi[2] = {0};
		  Double_t WWgenMuBar_eta[2] = {0};
		  Double_t WWgenMuBar_pt[2] = {0};
		  Double_t WWgenMuBar_px[2] = {0};
		  Double_t WWgenMuBar_py[2] = {0};
		  Double_t WWgenMuBar_pz[2] = {0};
		  
		  Double_t WWgenVert[3] = {0};
		  
		  Bool_t MuWasFound = false;
		  Bool_t MuBarWasFound = false;
		  Bool_t ZZMuWasFound = false;
		  Bool_t ZZMuBarWasFound = false;
		  Bool_t WWMuWasFound = false;
		  Bool_t WWMuBarWasFound = false;
		  
		  
		  
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
NtupleMakerSimu::NtupleMakerSimu(const edm::ParameterSet& iConfig)
:
 trackTags_(iConfig.getUntrackedParameter<edm::InputTag>("tracks")),
 outFile_(iConfig.getParameter<std::string>("outFile"))

{
   //now do what ever initialization is needed

}


NtupleMakerSimu::~NtupleMakerSimu()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
NtupleMakerSimu::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace reco;
   using namespace std;
  vuelta++;
  if (vuelta%1000 ==0){std::cout<<"vuelta: "<<vuelta<<std::endl;}
  event = eventReset;
  using reco::TrackCollection;
  
  
  Handle<GenParticleCollection> genParticles;
  iEvent.getByLabel("genParticles", genParticles);
  
  edm::Handle<edm::TriggerResults> trigResults; //Our trigger result object
edm::InputTag trigResultsTag("TriggerResults","","HLT");
iEvent.getByLabel(trigResultsTag,trigResults);
const edm::TriggerNames& trigNames = iEvent.triggerNames(*trigResults);
 
std::string pathName_e = "HLT_DoubleEle33_CaloIdL_v8";
std::string pathName_m = "HLT_L2DoubleMu23_NoVertex_v9";
//std::string toFind[2] = {"HLT_DoubleEle33_CaloIdL_v8", "HLT_L2DoubleMu23_NoVertex_9"}; 

 event.eventNumer= iEvent.id().event();
 event.runNumber= iEvent.id().run();
 event.lumiBlock = iEvent.id().luminosityBlock();
 int k = 0, ZZk = 0, WWk = 0;
 int kBar = 0, ZZkBar = 0, WWkBar= 0;
for (size_t i =0; i< genParticles->size(); i++)
{
	const GenParticle & p = (*genParticles)[i];
	double  id = p.pdgId();
	
	if(k >2 ||kBar > 2)
	{
		cout<< " WARNING: k couter is greater than 4" << endl;
	}
	
	if(id == 6000111 && p.numberOfDaughters() !=0 && k < 4)
	{
		
		
			event.genVert[0] = p.vx();
			event.genVert[1] = p.vy();
			event.genVert[2] = p.vz();
		
		for (size_t j =0; j< p.numberOfDaughters(); j++)
		{
			const Candidate & dp =  *(p.daughter(j));
			//cout<<dp.pt()<<endl;
			
			if(dp.pdgId()== 13)
			{
				event.genMu_phi[k] = dp.phi();
				event.genMu_eta[k] = dp.eta();
				event.genMu_pt[k] = dp.pt();
				event.genMu_px[k] = dp.px();
				event.genMu_py[k] = dp.py();
				event.genMu_pz[k] = dp.pz();
				
				k++;
				
			}
			if(dp.pdgId()== -13)
			{
				event.genMuBar_phi[kBar] = dp.phi();
				event.genMuBar_eta[kBar] = dp.eta();
				event.genMuBar_pt[kBar] = dp.pt();
				event.genMuBar_px[kBar] = dp.px();
				event.genMuBar_py[kBar] = dp.py();
				event.genMuBar_pz[kBar] = dp.pz();
				
				
				kBar++;
			}
		}
	}
	if(id == 23 && p.numberOfDaughters() !=0 && k < 4)
	{  // cout<<"Z found"<<endl;
		
		
			event.ZZgenVert[0] = p.vx();
			event.ZZgenVert[1] = p.vy();
			event.ZZgenVert[2] = p.vz();
		
		for (size_t j =0; j< p.numberOfDaughters(); j++)
		{
			const Candidate & dp =  *(p.daughter(j));
			
			if(dp.pdgId()== 13)
			{ cout<<"corresponding muon found"<<endl;
				event.ZZgenMu_phi[k] = dp.phi();
				event.ZZgenMu_eta[k] = dp.eta();
				event.ZZgenMu_pt[k] = dp.pt();
				event.ZZgenMu_px[k] = dp.px();
				event.ZZgenMu_py[k] = dp.py();
				event.ZZgenMu_pz[k] = dp.pz();
				event.ZZMuWasFound  = true;
				ZZk++;
				
			}
			if(dp.pdgId()== -13)
			{     cout<<"corresponding mubar found"<<endl;
				event.ZZgenMuBar_phi[kBar] = dp.phi();
				event.ZZgenMuBar_eta[kBar] = dp.eta();
				event.ZZgenMuBar_pt[kBar] = dp.pt();
				event.ZZgenMuBar_px[kBar] = dp.px();
				event.ZZgenMuBar_py[kBar] = dp.py();
				event.ZZgenMuBar_pz[kBar] = dp.pz();
				event.ZZMuBarWasFound = true;
				
				ZZkBar++;
			}
		}
	}
	if(id == 24 && p.numberOfDaughters() !=0 && k < 4)
	{
		
		
			event.WWgenVert[0] = p.vx();
			event.WWgenVert[1] = p.vy();
			event.WWgenVert[2] = p.vz();
		
		for (size_t j =0; j< p.numberOfDaughters(); j++)
		{
			const Candidate & dp =  *(p.daughter(j));
			
			if(dp.pdgId()== 13)
			{
				event.WWgenMu_phi[k] = dp.phi();
				event.WWgenMu_eta[k] = dp.eta();
				event.WWgenMu_pt[k] = dp.pt();
				event.WWgenMu_px[k] = dp.px();
				event.WWgenMu_py[k] = dp.py();
				event.WWgenMu_pz[k] = dp.pz();
				event.WWMuWasFound = true;
				
				WWk++;
				
			}
			if(dp.pdgId()== -13)
			{
				event.WWgenMuBar_phi[kBar] = dp.phi();
				event.WWgenMuBar_eta[kBar] = dp.eta();
				event.WWgenMuBar_pt[kBar] = dp.pt();
				event.WWgenMuBar_px[kBar] = dp.px();
				event.WWgenMuBar_py[kBar] = dp.py();
				event.WWgenMuBar_pz[kBar] = dp.pz();
				event.WWMuBarWasFound = true;
				
				WWkBar++;
			}
		}
	}
}






int trigPathSize = trigNames.size();
/*
for(int j = 0; j < 3; j++){
for (unsigned int i = 0; i< trigNames.size(); i++)
{
	
	
	std::string trig = trigNames.triggerName(i);
	if ( trig.find(toFind[j]) !=std::string::npos ){
		
		pathName = trig;
		
		int l = 0;
        for(std::string::iterator it = pathName.begin(); it != pathName.end(); ++it) 
        {
			event.triggerPath[l++] = *it;
		}
    

		event.wasTriggerFound = true;
		event.triggerFound = j;
		i = trigNames.size();
		j = 3;
		
		}
		
	}
}*/

std::string filterName_e = "none";
std::string filterName_m = "none";


	filterName_e = "hltDiEle33CaloIdLPixelMatchDoubleFilter";
	filterName_m = "hltL2DoubleMu23NoVertexL2PreFiltered";






int trigIndex = trigNames.triggerIndex(pathName_e);
if (trigIndex != trigPathSize)
{
bool passTrig_e=trigResults->accept(trigNames.triggerIndex(pathName_e));   // may cause vector::_M_range_check exeption
    
    event.triggerEActivated = passTrig_e;
}
else
{
	event.triggerEActivated=false;
}

int trigIndexM = trigNames.triggerIndex(pathName_m);


if (trigIndexM != trigPathSize)
{
bool passTrig_m=trigResults->accept(trigNames.triggerIndex(pathName_m));   // may cause vector::_M_range_check exeption
    
    event.triggerMActivated = passTrig_m;
    triggerTurnOns++;
}
else
{
	event.triggerMActivated=false;
}
   
   Handle<reco::PFJetCollection> ak5Jets;
   iEvent.getByLabel("ak5PFJets", ak5Jets);
   
   Handle<TrackCollection> tracks;
   iEvent.getByLabel(trackTags_,tracks);
  
   Handle<reco::VertexCollection> vertHand;
   iEvent.getByLabel( "offlinePrimaryVertices",vertHand);
   
   edm::InputTag trigEventTag("hltTriggerSummaryAOD","","HLT"); //make sure have correct process on MC
   //data process=HLT, MC depends, Spring11 is REDIGI311X
   edm::Handle<trigger::TriggerEvent> trigEvent; 
   iEvent.getByLabel(trigEventTag,trigEvent);
  
  
   //const edm::TriggerNames& trigNames = iEvent.triggerNames(*trigResults);
   int i, j;
   event.numVert=0;
   j =0;
  math::XYZPoint  vertex1;
  math::XYZPoint  vertex2; 
  math::XYZPoint  vertex3; 
	     NvertTracks = 0;
    for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->begin()+6 && itVert != vertHand->end();
       ++itVert){
		  
         event.numVert++;
       
       if(j ==0)
       {
		   vertex1 = itVert->position();
	   }
	  if (j == 1)
	  {
	      vertex2 = itVert->position();
	  }
	  if (j ==2)
	  {
		  vertex3 = itVert->position();
	  }
         
         //std::cout<<"Tracks de vertices "<<itVert->tracksSize()<<std::endl;
	      
	       event.vertex_chi2[j] = itVert->chi2();
		   event.vertex_ndof[j] = itVert->ndof();
		  
		  event.vertex_x[j] = itVert->x();          
		  event.vertex_y[j] = itVert->y();        
 		  event.vertex_z[j] = itVert->z();     
		              
		   event.vertex_xError[j] = itVert->xError();        
		   event.vertex_yError[j] = itVert->yError();        
		   event.vertex_zError[j] = itVert->zError();
		   event.vertex_nTracks[j] =  itVert->tracksSize();
	    
		 
         i = 0;
          
		 
        for(reco::Vertex::trackRef_iterator itTrack = itVert->tracks_begin();
       itTrack != itVert->tracks_begin() +6 && itTrack != itVert->tracks_end();
       ++itTrack){ 
		NvertTracks++;
		   // matching vertex track to track
		  // int k = 0;
		   //int vertexIndex = 0;
		   /* for(TrackCollection::const_iterator itTrack2 = tracks->begin();
				itTrack2 != tracks->end();                      
				++itTrack) 
				{
					std::cout<<(&(*itTrack2))<<"  "<<(&(**itTrack))<<std::endl;
					//reco::TrackRef trkRef(itTrack->castTo<reco::TrackRef>());
					//reco::TrackRef trkRef2(itTrack2->castTo<reco::TrackRef>());
					if(true)//(**itTrack) == (*itTrack))
					{
						event.matchedVertex_x[vertexIndex] = itVert->x();
						event.matchedVertex_xError[vertexIndex] = itVert->xError();
						event.matchedVertex_y[vertexIndex] = itVert->y();
						event.matchedVertex_yError[vertexIndex] = itVert->yError();
						event.matchedVertex_z[vertexIndex] = itVert->z();
						event.matchedVertex_zError[vertexIndex] = itVert->zError();
						event.matchedVertex_chi2[vertexIndex] = itVert->chi2();
						event.matchedVertex_ndof[vertexIndex] = itVert->ndof();
						event.track_matchedVertIndex[k] = vertexIndex;
						vertexIndex++;
						
					}
					else
					{
						event.track_matchedVertIndex[k] = 999999;
					}
					k++;
				}*/
		   
		   
		   // Top 6 vertex with most tracks
		   if(itTrack == itVert->tracks_begin()){
		   event.vertex1Track_vx[i] = (**itTrack).vx();
	       event.vertex1Track_vy[i] = (**itTrack).vy();
		   event.vertex1Track_vz[i] = (**itTrack).vz();}
		   
		   if(itTrack == itVert->tracks_begin()+1){
		    event.vertex2Track_vx[i] = (**itTrack).vx();
	       event.vertex2Track_vy[i] = (**itTrack).vy();
		   event.vertex2Track_vz[i] = (**itTrack).vz();}
		  
		   if(itTrack == itVert->tracks_begin()+2){
		    event.vertex3Track_vx[i] = (**itTrack).vx();
	       event.vertex3Track_vy[i] = (**itTrack).vy();
		   event.vertex3Track_vz[i] = (**itTrack).vz();}
		   
		   if(itTrack == itVert->tracks_begin()+3){
		    event.vertex4Track_vx[i] = (**itTrack).vx();
	       event.vertex4Track_vy[i] = (**itTrack).vy();
		   event.vertex4Track_vz[i] = (**itTrack).vz();}
		   
		   if(itTrack == itVert->tracks_begin()+4){
		    event.vertex5Track_vx[i] = (**itTrack).vx();
	       event.vertex5Track_vy[i] = (**itTrack).vy();
		   event.vertex5Track_vz[i] = (**itTrack).vz();}
		   
		    if(itTrack == itVert->tracks_begin()+5){
		    event.vertex6Track_vx[i] = (**itTrack).vx();
	       event.vertex6Track_vy[i] = (**itTrack).vy();
		   event.vertex6Track_vz[i] = (**itTrack).vz();}
		 //  event.vertexTrack_nHits[i] = (**itTrack).numberOfValidHits();
		  // event.vertexTrack_chi2[i] =  (**itTrack).chi2();

          event.numVertTrack[j]++;
           i++;
		   } 
		   j++;
   
}
   
	      
   i=0;
   event.numTrack=0;
   Ntracks = 0;
	     
   for(TrackCollection::const_iterator itTrack = tracks->begin();
       itTrack != tracks->end();                      
       ++itTrack) {
        Ntracks++;
           //double vx = itTrack->vx();
           //double vy = itTrack->vy();
           //double vz = itTrack->vz();
           
           event.track_pt[i] = itTrack->pt();
           event.track_ptError[i] = itTrack->ptError();
           //std::cout<<event.track_pt[i]<<std::endl;
		   event.track_px[i] = itTrack->px();
		   event.track_py[i] = itTrack->py();
		   event.track_pz[i] = itTrack->pz();
		   //std::cout<<event.track_px[i]<<" "<<event.track_py[i]<<" "<<event.track_pz[i]<<std::endl;
		   event.track_vx[i] = itTrack->vx();
		   event.track_vy[i] = itTrack->vy();
		   event.track_vz[i] = itTrack->vz();
		   event.track_chi2[i] = itTrack->chi2(); 
		   event.track_ndof[i] = itTrack->ndof(); 
		   event.track_eta[i] = itTrack->eta();
		   event.track_etaError[i] = itTrack->etaError();
		   event.track_phi[i] = itTrack->phi();
		   event.track_phiError[i] = itTrack->phiError();
		   event.track_nHits[i] = itTrack->numberOfValidHits();
		   event.track_n3DHits[i] = itTrack->hitPattern().numberOfValidPixelHits();
		   event.track_found[i] = itTrack->found();
		   event.track_dxy[i] = itTrack->dxy();
		   event.track_d0[i] = itTrack->d0();
		   event.track_d0Error[i] = itTrack->d0Error();
		   event.track_dxyError[i] = itTrack->dxyError();
		   event.track_lxy1[i] = itTrack->dxy(vertex1);
		   event.track_lxy1Error[i] = itTrack->dxyError();
		   event.track_lxy2[i] = itTrack->dxy(vertex2);
		   event.track_lxy2Error[i] = itTrack->dxyError();
		   event.track_lxy3[i] = itTrack->dxy(vertex3);
		   event.track_lxy3Error[i] = itTrack->dxyError();
		   event.track_dz[i] = itTrack->dz();
		   event.track_dzError[i] = itTrack->dzError();
		   event.track_charge[i] = itTrack->charge();
		   //std::cout<<event.track_charge[i]<<std::endl;
		   event.track_highPurity[i] = itTrack->quality(reco::Track::highPurity);
		   event.track_tight[i] = itTrack->quality(reco::Track::tight);
		   event.track_loose[i] = itTrack->quality(reco::Track::loose);
           //std::cout<<"track vx "<<event.track_vx[i]<<std::endl;
        i ++;
        event.numTrack++;
  }
  
	     
  //std::cout<<event.numVert<<std::endl;
   
    
  std::string e_filterName(filterName_e); // dataset photones (para filtrar electrones)
   
  //std::string e_filterName("hltDoubleEG43HEVTDoubleFilter"); // simulacion
  trigger::size_type e_filterIndex = trigEvent->filterIndex(edm::InputTag(e_filterName,"",trigEventTag.process())); 
  //std::cout<<e_filterIndex<<" "<<trigEvent->sizeFilters()<<std::endl;
  if(e_filterIndex<trigEvent->sizeFilters()){ 
	  
	 
      const trigger::Keys& trigKeys = trigEvent->filterKeys(e_filterIndex); 
      
      const trigger::TriggerObjectCollection & e_trigObjColl(trigEvent->getObjects());
     
   i = 0;
   event.numTrigObjE=0;
   
	     
  for(trigger::Keys::const_iterator keyIt=trigKeys.begin();keyIt!=trigKeys.end();++keyIt){ 
	     const trigger::TriggerObject& obj = e_trigObjColl[*keyIt];
	      event.trigObjE_pt[i] = obj.pt();
		  event.trigObjE_px[i] = obj.px();
		  event.trigObjE_pz[i] = obj.pz();
		  event.trigObjE_py[i] = obj.py();
		  event.trigObjE_eta[i] = obj.eta();
		  event.trigObjE_phi[i] = obj.phi();
	      event.trigObjE_energy[i] = obj.energy();
	  
	  i++;
	  event.numTrigObjE++;
     }
     
     
	     
 
}


 std::string m_filterName(filterName_m); // dataset photones (para filtrar electrones)
   
  //std::string e_filterName("hltDoubleEG43HEVTDoubleFilter"); // simulacion
  trigger::size_type m_filterIndex = trigEvent->filterIndex(edm::InputTag(m_filterName,"",trigEventTag.process())); 
  
  if(m_filterIndex<trigEvent->sizeFilters()){ 
	  
	 // std::cout<<"paso"<<std::endl;
	 
      const trigger::Keys& trigKeys = trigEvent->filterKeys(m_filterIndex); 
      
      const trigger::TriggerObjectCollection & m_trigObjColl(trigEvent->getObjects());
     
   i = 0;
   event.numTrigObjM=0;
   
	     
  for(trigger::Keys::const_iterator keyIt=trigKeys.begin();keyIt!=trigKeys.end();++keyIt){ 
	     const trigger::TriggerObject& obj = m_trigObjColl[*keyIt];
	      event.trigObjM_pt[i] = obj.pt();
		  event.trigObjM_px[i] = obj.px();
		  event.trigObjM_pz[i] = obj.pz();
		  event.trigObjM_py[i] = obj.py();
		  event.trigObjM_eta[i] = obj.eta();
		  event.trigObjM_phi[i] = obj.phi();
	      event.trigObjM_energy[i] = obj.energy();
	  
	  i++;
	  event.numTrigObjM++;
     }
     
     
	     
 
}



// Jets
event.numJets = 0;
i =0;
for (auto itJet = ak5Jets->begin(); itJet != ak5Jets->end(); ++itJet)
{
	 event.test_leaf[i] = itJet->pt();
	event.ak5jet_x[i] = itJet->pt();
	event.ak5jet_y[i] = itJet->vy();
	event.ak5jet_z[i] = itJet->vz();
	event.ak5jet_pt[i] = itJet->pt();
	event.ak5jet_px[i] = itJet->py();
	event.ak5jet_py[i] = itJet->px();
	event.ak5jet_pz[i] = itJet->pz();
	event.ak5jet_eta[i] = itJet->eta();
	event.ak5jet_phi[i] = itJet->phi();
	event.ak5jet_mass[i] = itJet->mass();
	//event.ak5jet_chi2[i]= itJet->chi2();
	//event.ak5jet_ndof[i] = itJet->ndof();
	
	event.numJets++;
	i++;
}
numJets2=event.numJets;
//std::cout<<"numjets "<<event.numJets<<std::endl;
 

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
NtupleMakerSimu::beginJob()
{
 vuelta = 0;
 const char* of = outFile_.c_str();
 mfile = new TFile(of, "recreate");
 mtree = new TTree("mtree","Ntuple");
 
 //mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I:track_pt[numTrack]/D:track_px[numTrack]/D:track_pz[numTrack]/D:track_py[numTrack]/D:track_vx[numTrack]/D:track_vy[numTrack]/D:track_vz[numTrack]/D:track_chi2[numTrack]/D:track_ndof[numTrack]/I:track_eta[numTrack]/D:track_phi[numTrack]/D:track_nHits[numTrack]/D:track_found[numTrack]/I:track_dxy[numTrack]/D:track_dxyError[numTrack]/D:track_dz[numTrack]/D:track_charge[numTrack]/I:track_highPurity[numTrack]/O:track_tight[numTrack]/O:track_loose[numTrack]/O:trigObj_pt[numTrigObj]/D:trigObj_px[numTrigObj]/D:trigObj_pz[numTrigObj]/D:trigObj_py[numTrigObj]/D:trigObj_eta[numTrigObj]/D:trigObj_phi[numTrigObj]/D:trigObj_energy[numTrigObj]/D:triggerActivated/O:vertexTrack_vx[numVertTrack]/D:vertexTrack_vy[numVertTrack]/D:vertexTrack_vz[numVertTrack]/D:vertexTrack_nHits[numVertTrack]/D:vertexTrack_chi2[numVertTrack]/D:vertex[numVert][6]/D");
 //mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I");

 
           mtree->Branch("Ev_Branch",&event ,"eventNumber/I:runNumber/I:lumiBlock/I:numTrack/I:numTrigObjE/I:numTrigObjM/I:numJets/I:numVert/I:wasTriggerFound/O:triggerFound/I");
           
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
           
           mtree->Branch("trigObjE_pt", event.trigObjE_pt, "trigObjE_pt[numTrigObjE]/D");
           mtree->Branch("trigObjE_px", event.trigObjE_px, "trigObjE_px[numTrigObjE]/D");
           mtree->Branch("trigObjE_py", event.trigObjE_py, "trigObjE_py[numTrigObjE]/D");
           mtree->Branch("trigObjE_pz", event.trigObjE_pz, "trigObjE_pz[numTrigObjE]/D");
           mtree->Branch("trigObjE_eta", event.trigObjE_eta, "trigObjE_eta[numTrigObjE]/D");
           mtree->Branch("trigObjE_phi", event.trigObjE_phi, "trigObjE_phi[numTrigObjE]/D");
           mtree->Branch("triggerEActivated", &event.triggerEActivated, "triggerEActivated/O");
           mtree->Branch("trigObjE_energy", event.trigObjE_energy, "trigObjE_energy[numTrigObjE]/O");
           
           mtree->Branch("trigObjM_pt", event.trigObjM_pt, "trigObjM_pt[numTrigObjM]/D");
           mtree->Branch("trigObjM_px", event.trigObjM_px, "trigObjM_px[numTrigObjM]/D");
           mtree->Branch("trigObjM_py", event.trigObjM_py, "trigObjM_py[numTrigObjM]/D");
           mtree->Branch("trigObjM_pz", event.trigObjM_pz, "trigObjM_pz[numTrigObjM]/D");
           mtree->Branch("trigObjM_eta", event.trigObjM_eta, "trigObjM_eta[numTrigObjM]/D");
           mtree->Branch("trigObjM_phi", event.trigObjM_phi, "trigObjM_phi[numTrigObjM]/D");
           mtree->Branch("triggerMActivated", &event.triggerMActivated, "triggerMActivated/O");
           mtree->Branch("trigObjM_energy", event.trigObjM_energy, "trigObjM_energy[numTrigObjM]/O");
           
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
           mtree->Branch("ak5jet_mass", event.ak5jet_eta, "ak5jet_mass[numJets]/D");
           
           
           
           mtree->Branch("genMu_phi", event.genMu_phi, "genMu_phi[2]/D");
           mtree->Branch("genMu_eta", event.genMu_eta, "genMu_eta[2]/D");
           mtree->Branch("genMu_pt", event.genMu_pt, "genMu_pt[2]/D");
           mtree->Branch("genMu_px", event.genMu_px, "genMu_px[2]/D");
           mtree->Branch("genMu_py", event.genMu_py, "genMu_py[2]/D");
           mtree->Branch("genMu_pz", event.genMu_pz, "genMu_pz[2]/D");
           
           mtree->Branch("genMuBar_phi", event.genMuBar_phi, "genMuBar_phi[2]/D");
           mtree->Branch("genMuBar_eta", event.genMuBar_eta, "genMuBar_eta[2]/D");
           mtree->Branch("genMuBar_pt", event.genMuBar_pt, "genMuBar_pt[2]/D");
           mtree->Branch("genMuBar_px", event.genMuBar_px, "genMuBar_px[2]/D");
           mtree->Branch("genMuBar_py", event.genMuBar_py, "genMuBar_py[2]/D");
           mtree->Branch("genMuBar_pz", event.genMuBar_pz, "genMuBar_pz[2]/D");
           
           mtree->Branch("genVert", event.genVert, "genVert[3]/D");
           
           
            mtree->Branch("ZZgenMu_phi", event.ZZgenMu_phi, "ZZgenMu_phi[2]/D");
           mtree->Branch("ZZgenMu_eta", event.ZZgenMu_eta, "ZZgenMu_eta[2]/D");
           mtree->Branch("ZZgenMu_pt", event.ZZgenMu_pt, "ZZgenMu_pt[2]/D");
           mtree->Branch("ZZgenMu_px", event.ZZgenMu_px, "ZZgenMu_px[2]/D");
           mtree->Branch("ZZgenMu_py", event.ZZgenMu_py, "ZZgenMu_py[2]/D");
           mtree->Branch("ZZgenMu_pz", event.ZZgenMu_pz, "ZZgenMu_pz[2]/D");
           
            mtree->Branch("ZZgenMuBar_phi", event.ZZgenMuBar_phi, "ZZgenMuBar_phi[2]/D");
           mtree->Branch("ZZgenMuBar_eta", event.ZZgenMuBar_eta, "ZZgenMuBar_eta[2]/D");
           mtree->Branch("ZZgenMuBar_pt", event.ZZgenMuBar_pt, "ZZgenMuBar_pt[2]/D");
           mtree->Branch("ZZgenMuBar_px", event.ZZgenMuBar_px, "ZZgenMuBar_px[2]/D");
           mtree->Branch("ZZgenMuBar_py", event.ZZgenMuBar_py, "ZZgenMuBar_py[2]/D");
           mtree->Branch("ZZgenMuBar_pz", event.ZZgenMuBar_pz, "ZZgenMuBar_pz[2]/D");
           
           mtree->Branch("ZZgenVert", event.ZZgenVert, "ZZgenVert[3]/D");
           
             mtree->Branch("WWgenMu_phi", event.WWgenMu_phi, "WWgenMu_phi[2]/D");
           mtree->Branch("WWgenMu_eta", event.WWgenMu_eta, "WWgenMu_eta[2]/D");
           mtree->Branch("WWgenMu_pt", event.WWgenMu_pt, "WWgenMu_pt[2]/D");
           mtree->Branch("WWgenMu_px", event.WWgenMu_px, "WWgenMu_px[2]/D");
           mtree->Branch("WWgenMu_py", event.WWgenMu_py, "WWgenMu_py[2]/D");
           mtree->Branch("WWgenMu_pz", event.WWgenMu_pz, "WWgenMu_pz[2]/D");
           
            mtree->Branch("WWgenMuBar_phi", event.WWgenMuBar_phi, "WWgenMuBar_phi[2]/D");
           mtree->Branch("WWgenMuBar_eta", event.WWgenMuBar_eta, "WWgenMuBar_eta[2]/D");
           mtree->Branch("WWgenMuBar_pt", event.WWgenMuBar_pt, "WWgenMuBar_pt[2]/D");
           mtree->Branch("WWgenMuBar_px", event.WWgenMuBar_px, "WWgenMuBar_px[2]/D");
           mtree->Branch("WWgenMuBar_py", event.WWgenMuBar_py, "WWgenMuBar_py[2]/D");
           mtree->Branch("WWgenMuBar_pz", event.WWgenMuBar_pz, "WWgenMuBar_pz[2]/D");
           
           mtree->Branch("WWgenVert", event.WWgenVert, "WWgenVert[3]/D");
           
           mtree->Branch("triggerPath", event.triggerPath, "triggerPath[100]/C");
           
           
           mtree->Branch("ZZMuWasFound", &event.ZZMuWasFound, "ZZMuWasFound/O");
           mtree->Branch("ZZMuBarWasFound", &event.ZZMuBarWasFound, "ZZMuBarWasFound/O");
           mtree->Branch("WWMuWasFound", &event.WWMuWasFound, "WWMuWasFound/O");
           mtree->Branch("WWMuBarWasFound", &event.ZZMuWasFound, "WWMuBarWasFound/O");
          // mtree->Branch("filter", event.filter, "filter[100]/C");
		  
		  
		 
		  
	
		
		
}




           


          


// ------------ method called once each job just after ending the event loop  ------------
void 
NtupleMakerSimu::endJob() {

//mtree->Write();
std::cout<<"num traks "<<Ntracks<<" num vertTraks "<<NvertTracks<<std::endl;
std::cout<<"Trigger turn ons "<<triggerTurnOns<<std::endl;
mfile->Write();
mfile->Close();
}

// ------------ method called when starting to processes a run  ------------
void 
NtupleMakerSimu::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
NtupleMakerSimu::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
NtupleMakerSimu::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
NtupleMakerSimu::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
NtupleMakerSimu::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
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
DEFINE_FWK_MODULE(NtupleMakerSimu);
