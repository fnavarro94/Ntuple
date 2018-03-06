// -*- C++ -*-
//
// Package:    NtupleMaker
// Class:      NtupleMaker
// 
/**\class NtupleMaker NtupleMaker.cc Ntuple/NtupleMaker/src/NtupleMaker.cc

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

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
//
// class declaration
//

class NtupleMaker : public edm::EDAnalyzer {
   public:
      explicit NtupleMaker(const edm::ParameterSet&);
      ~NtupleMaker();

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
      struct mEvent {

          static const Int_t entryMax = 10000;
		  Int_t numTrack =0;
		  Int_t numTrigObj=0;
		
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
		  Double_t track_found[entryMax] = {0};
		  Double_t track_dxy[entryMax] = {0};
		  Double_t track_dxyError[entryMax] = {0};
		  Double_t track_dz[entryMax] = {0};
		  Double_t track_dzError[entryMax] = {0};
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
		  
		  
		  Double_t vertex_chi2[entryMax] = {0}; 
		  Double_t vertex_ndof[entryMax] = {0}; 
		  
		  Double_t vertex_x[entryMax] = {0};             
		  Double_t vertex_y[entryMax] = {0};               
 		  Double_t vertex_z[entryMax] = {0};               
		              
		  Double_t vertex_xError[entryMax] = {0};          
		  Double_t vertex_yError[entryMax] = {0};          
		  Double_t vertex_zError[entryMax] = {0};    
		  Int_t vertex_nTracks[entryMax] = {0};      
		       
		  
		  
		  
		  
		  }event,eventReset;
		  //static const struct  mEvent eventReset ;

      // ----------member data ---------------------------
      edm::InputTag trackTags_; //used to select what tracks to read from configuration file
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
NtupleMaker::NtupleMaker(const edm::ParameterSet& iConfig)
:
 trackTags_(iConfig.getUntrackedParameter<edm::InputTag>("tracks"))

{
   //now do what ever initialization is needed

}


NtupleMaker::~NtupleMaker()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
NtupleMaker::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
  vuelta++;
  if (vuelta%1000 ==0){std::cout<<"vuelta: "<<vuelta<<std::endl;}
  event = eventReset;
  using reco::TrackCollection;
  
  
  
  
  edm::Handle<edm::TriggerResults> trigResults; //Our trigger result object
edm::InputTag trigResultsTag("TriggerResults","","HLT");
iEvent.getByLabel(trigResultsTag,trigResults);
const edm::TriggerNames& trigNames = iEvent.triggerNames(*trigResults);
 
std::string pathName = "none";
std::string toFind[2] = {"HLT_DoublePhoton33", "HLT_DoublePhoton38"};
 

int trigPathSize = trigNames.size();

for(int j = 0; j < 2; j++){
for (unsigned int i = 0; i< trigNames.size(); i++)
{
	
	
	std::string trig = trigNames.triggerName(i);
	if ( trig.find(toFind[j]) !=std::string::npos ){
		
		pathName = trig;
		event.wasTriggerFound = true;
		event.triggerFound = j;
		i = trigNames.size();
		j = 2;
		
		}
		
	}
}
int trigIndex = trigNames.triggerIndex(pathName);
if (trigIndex != trigPathSize)
{
bool passTrig=trigResults->accept(trigNames.triggerIndex(pathName));   // may cause vector::_M_range_check exeption
    
    event.triggerActivated = passTrig;
}
else
{
	event.triggerActivated=false;
}
 
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
   
	     
    for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->begin()+6 && itVert != vertHand->end();
       ++itVert){
		  
         event.numVert++;
         
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
   
	     
   for(TrackCollection::const_iterator itTrack = tracks->begin();
       itTrack != tracks->end();                      
       ++itTrack) {
        
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
		   event.track_found[i] = itTrack->found();
		   event.track_dxy[i] = itTrack->dxy();
		   event.track_dxyError[i] = itTrack->dxyError();
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
   
    
  std::string e_filterName("hltDoublePhoton33EgammaLHEDoubleFilter"); // dataset photones (para filtrar electrones)
   
  //std::string e_filterName("hltDoubleEG43HEVTDoubleFilter"); // simulacion
  trigger::size_type e_filterIndex = trigEvent->filterIndex(edm::InputTag(e_filterName,"",trigEventTag.process())); 
  
  if(e_filterIndex<trigEvent->sizeFilters()){ 
	  
	 
      const trigger::Keys& trigKeys = trigEvent->filterKeys(e_filterIndex); 
      
      const trigger::TriggerObjectCollection & e_trigObjColl(trigEvent->getObjects());
     
   i = 0;
   event.numTrigObj=0;
   
	     
  for(trigger::Keys::const_iterator keyIt=trigKeys.begin();keyIt!=trigKeys.end();++keyIt){ 
	     const trigger::TriggerObject& obj = e_trigObjColl[*keyIt];
	      event.trigObj_pt[i] = obj.pt();
		  event.trigObj_px[i] = obj.px();
		  event.trigObj_pz[i] = obj.pz();
		  event.trigObj_py[i] = obj.py();
		  event.trigObj_eta[i] = obj.eta();
		  event.trigObj_phi[i] = obj.phi();
	      event.trigObj_energy[i] = obj.energy();
	  
	  i++;
	  event.numTrigObj++;
     }
     
     
	     
 
}

 
 

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
NtupleMaker::beginJob()
{
 vuelta = 0;
 mfile = new TFile("tuple.root", "recreate");
 mtree = new TTree("mtree","Ntuple");
 
 //mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I:track_pt[numTrack]/D:track_px[numTrack]/D:track_pz[numTrack]/D:track_py[numTrack]/D:track_vx[numTrack]/D:track_vy[numTrack]/D:track_vz[numTrack]/D:track_chi2[numTrack]/D:track_ndof[numTrack]/I:track_eta[numTrack]/D:track_phi[numTrack]/D:track_nHits[numTrack]/D:track_found[numTrack]/I:track_dxy[numTrack]/D:track_dxyError[numTrack]/D:track_dz[numTrack]/D:track_charge[numTrack]/I:track_highPurity[numTrack]/O:track_tight[numTrack]/O:track_loose[numTrack]/O:trigObj_pt[numTrigObj]/D:trigObj_px[numTrigObj]/D:trigObj_pz[numTrigObj]/D:trigObj_py[numTrigObj]/D:trigObj_eta[numTrigObj]/D:trigObj_phi[numTrigObj]/D:trigObj_energy[numTrigObj]/D:triggerActivated/O:vertexTrack_vx[numVertTrack]/D:vertexTrack_vy[numVertTrack]/D:vertexTrack_vz[numVertTrack]/D:vertexTrack_nHits[numVertTrack]/D:vertexTrack_chi2[numVertTrack]/D:vertex[numVert][6]/D");
 //mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I");

 
           mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVert/I:wasTriggerFound/O:triggerFound/I");
           
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
           mtree->Branch("track_dxy", event.track_dxy, "track_dxy[numTrack]/D");
           mtree->Branch("track_dxyError", event.track_dxyError, "track_dxyError[numTrack]/D");
           mtree->Branch("track_dz", event.track_dz, "track_dz[numTrack]/D");
           mtree->Branch("track_dzError", event.track_dzError, "track_dzError[numTrack]/D");
           mtree->Branch("track_charge", event.track_charge, "track_charge[numTrack]/I");
           mtree->Branch("track_highPurity", event.track_highPurity, "track_highPurity[numTrack]/O");
           mtree->Branch("track_tight", event.track_tight, "track_tight[numTrack]/O");
           mtree->Branch("track_loose", event.track_loose, "track_loose[numTrack]/O");
           
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
          
           
         
           mtree->Branch("vertex_chi2", event.vertex_chi2, "vertex_chi2[numVert]/D");
           mtree->Branch("vertex_ndof", event.vertex_ndof, "vertex_nodf[numVert]/D");
           mtree->Branch("vertex_x", event.vertex_x, "vertex_x[numVert]/D");
           mtree->Branch("vertex_y", event.vertex_y, "vertex_y[numVert]/D");
           mtree->Branch("vertex_z", event.vertex_z, "vertex_z[numVert]/D");
           mtree->Branch("vertex_xError", event.vertex_xError, "vertex_xError[numVert]/D");
           mtree->Branch("vertex_yError", event.vertex_yError, "vertex_yError[numVert]/D");
           mtree->Branch("vertex_zError", event.vertex_zError, "vertex_zError[numVert]/D");
           mtree->Branch("vertex_nTracks", event.vertex_nTracks, "vertex_nTracks[numVert]/D");
		  
		  
		  
	
		
		
}




           


          


// ------------ method called once each job just after ending the event loop  ------------
void 
NtupleMaker::endJob() {

//mtree->Write();

mfile->Write();
mfile->Close();
}

// ------------ method called when starting to processes a run  ------------
void 
NtupleMaker::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
NtupleMaker::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
NtupleMaker::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
NtupleMaker::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
NtupleMaker::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
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
DEFINE_FWK_MODULE(NtupleMaker);
