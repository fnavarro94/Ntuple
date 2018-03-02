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

          static const int entryMax = 1000;
		  int numTrack =0;
		  int numTrigObj=0;
		  int numVertTrack=0;
		  int numVert=0;
		
		// track data 
		  double track_pt[entryMax] = {0};
		  double track_px[entryMax]= {0};
		  double track_pz[entryMax]= {0};
		  double track_py[entryMax]= {0};
		  double track_vx[entryMax]= {0};
		  double track_vy[entryMax]= {0};
		  double track_vz[entryMax]= {0};
		  double track_chi2[entryMax] = {0};
		  double track_eta[entryMax]= {0};
		  double track_phi[entryMax]= {0};
		  double track_nHits[entryMax] = {0};
		  double track_dxy[entryMax] = {0};
		  double track_dz[entryMax] = {0};
		  double track_charge[entryMax] = {0};
		// trigger object data (for objects passing filter)
		  double trigObj_pt[entryMax] = {0};
		  double trigObj_px[entryMax] = {0};
		  double trigObj_pz[entryMax] = {0};
		  double trigObj_py[entryMax] = {0};
		  double trigObj_eta[entryMax] = {0};
		  double trigObj_phi[entryMax] = {0};
		  double trigObj_energy[entryMax] = {0};
	    // Event data
		  bool triggerActivated;
		  
		  double vertexTrack_vx[entryMax] = {0};
		  double vertexTrack_vy[entryMax] = {0};
		  double vertexTrack_vz[entryMax] = {0};
		  double vertexTrack_nHits[entryMax] = {0};
		  double vertexTrack_chi2[entryMax] = {0};
		  
		  
		  
		  
		  
		  
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
  event = eventReset;
  using reco::TrackCollection;
 
   Handle<TrackCollection> tracks;
   iEvent.getByLabel(trackTags_,tracks);
   
   Handle<reco::VertexCollection> vertHand;
   iEvent.getByLabel( "offlinePrimaryVertices",vertHand);
   
   edm::InputTag trigEventTag("hltTriggerSummaryAOD","","HLT"); //make sure have correct process on MC
   //data process=HLT, MC depends, Spring11 is REDIGI311X
   edm::Handle<trigger::TriggerEvent> trigEvent; 
   iEvent.getByLabel(trigEventTag,trigEvent);

   edm::Handle<edm::TriggerResults> trigResults; //our trigger result object
   edm::InputTag trigResultsTag("TriggerResults","","HLT"); //make sure have correct process on MC
   //data process=HLT, MC depends, Spring11 is REDIGI311X
   iEvent.getByLabel(trigResultsTag,trigResults);
   //const edm::TriggerNames& trigNames = iEvent.triggerNames(*trigResults);
   int i;
   
      for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->begin() +1;
       ++itVert){
		   event.numVert++;
		   
	   }
   
    for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->begin() +1;
       ++itVert){
	   
		
         i = 0;
          
		 event.numVertTrack=0;
        for(reco::Vertex::trackRef_iterator itTrack = itVert->tracks_begin();
       itTrack != itVert->tracks_end();
       ++itTrack){ 
		   
		   event.vertexTrack_vx[i] = (**itTrack).vx();
	       event.vertexTrack_vy[i] = (**itTrack).vy();
		   event.vertexTrack_vz[i] = (**itTrack).vz();
		   event.vertexTrack_nHits[i] = (**itTrack).numberOfValidHits();
		   event.vertexTrack_chi2[i] =  (**itTrack).chi2();

           event.numVertTrack++;
           i++;
		   } 
   
   
   
   i=0;
   event.numTrack=0;
   for(TrackCollection::const_iterator itTrack = tracks->begin();
       itTrack != tracks->end();                      
       ++itTrack) {
        
           event.track_pt[i] = itTrack->pt();
		   event.track_px[i] = itTrack->px();
		   event.track_py[i] = itTrack->py();
		   event.track_pz[i] = itTrack->pz();
		   event.track_vx[i] = itTrack->vx();
		   event.track_vy[i] = itTrack->vy();
		   event.track_vz[i] = itTrack->vz();
		   event.track_chi2[i] = itTrack->chi2(); 
		   event.track_eta[i] = itTrack->eta();
		   event.track_phi[i] = itTrack->phi();
		   event.track_nHits[i] = itTrack->numberOfValidHits();
		   event.track_dxy[i] = itTrack->dxy();
		   event.track_dz[i] = itTrack->dz();
		   event.track_charge[i] = itTrack->charge();

        i ++;
        event.numTrack++;
  }
 
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
 
 mtree->Fill();
#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}
}

// ------------ method called once each job just before starting event loop  ------------
void 
NtupleMaker::beginJob()
{
 vuelta = 0;
 mfile = new TFile("tuple.root", "recreate");
 mtree = new TTree("mtree","Ntuple");
 //mtree->Branch("Ev_Branch",&event , "entryMax/I:numTrack/I:numVert/I:vertexTrack_vx[numVertTrack]/D:vertexTrack_vy[numVertTrack]/D:vertexTrack_vz[numVertTrack]/D:vertexTrack_nHits[numVertTrack]/D:vertexTrack_chi2[numVertTrack]/D:numTrigObj/I:track_pt[numTrack]/D:track_px[numTrack]/D:track_pz[numTrack]/D:track_py[numTrack]/D:track_vx[numTrack]/D:track_vy[numTrack]/D:track_vz[numTrack]/D:track_chi2[numTrack]/D:track_eta[numTrack]/D:track_phi[numTrack]/D:track_nHits[numTrack]/D:track_dxy[numTrack]/D:track_dz[numTrack]/D:trigObj_pt[numTrigObj]/D:trigObj_px[numTrigObj]/D:trigObj_pz[numTrigObj]/D:trigObj_py[numTrigObj]/D:trigObj_eta[numTrigObj]/D:trigObj_phi[numTrigObj]/D:trigObj_energy[numTrigObj]/D:triggerActivated/I");
  mtree->Branch("Ev_Branch",&event ,  "entryMax/I:numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I:track_pt[entryMax]/D:track_px[entryMax]/D:track_pz[entryMax]/D:track_py[entryMax]/D:track_vx[entryMax]/D:track_vy[entryMax]/D:track_vz[entryMax]/D:track_chi2[entryMax]/D:track_eta[entryMax]/D:track_phi[entryMax]/D:track_nHits[entryMax]/D:track_dxy[entryMax]/D:track_dz[entryMax]/D:track_charge[entryMax]/D:trigObj_pt[entryMax]/D:trigObj_px[entryMax]/D:trigObj_pz[entryMax]/D:trigObj_py[entryMax]/D:trigObj_eta[entryMax]/D:trigObj_phi[entryMax]/D:trigObj_energy[entryMax]/D:triggerActivated/O:vertexTrack_vx[entryMax]/D:vertexTrack_vy[entryMax]/D:vertexTrack_vz[entryMax]/D:vertexTrack_nHits[entryMax]/D:vertexTrack_chi2[entryMax]/D");	
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
