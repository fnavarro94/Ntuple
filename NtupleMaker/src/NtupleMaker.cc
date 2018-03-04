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

          static const Int_t entryMax = 1000;
		  Int_t numTrack =0;
		  Int_t numTrigObj=0;
		  Int_t numVertTrack=0;
		  Int_t numVert=0;
		  
		  
		// track data 
		  Double_t track_pt[entryMax] = {0};
		  Double_t track_px[entryMax]= {0};
		  Double_t track_pz[entryMax]= {0};
		  Double_t track_py[entryMax]= {0};
		  Double_t track_vx[entryMax]= {0};
		  Double_t track_vy[entryMax]= {0};
		  Double_t track_vz[entryMax]= {0};
		  Double_t track_chi2[entryMax] = {0};
		  Double_t track_ndof[entryMax] = {0};
		  Double_t track_eta[entryMax]= {0};
		  Double_t track_phi[entryMax]= {0};
		  Double_t track_nHits[entryMax] = {0};
		  Double_t track_found[entryMax] = {0};
		  Double_t track_dxy[entryMax] = {0};
		  Double_t track_dxyError[entryMax] = {0};
		  Double_t track_dz[entryMax] = {0};
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
		  Bool_t triggerActivated;
		  
		  Double_t vertexTrack_vx[entryMax] = {0};
		  Double_t vertexTrack_vy[entryMax] = {0};
		  Double_t vertexTrack_vz[entryMax] = {0};
		  Double_t vertexTrack_nHits[entryMax] = {0};
		  Double_t vertexTrack_chi2[entryMax] = {0};
		  
		  //vertex data
		  
		  Double_t vertex[entryMax][6];
		  
		/*  Double_t vertex_x[entryMax] = {0};             1
		  Double_t vertex_y[entryMax] = {0};               2
 		  Double_t vertex_z[entryMax] = {0};               3
		  Double_t vertex_t[entryMax] = {0};               4
		  Double_t vertex_xError[entryMax] = {0};          5
		  Double_t vertex_yError[entryMax] = {0};          6
		  Double_t vertex_zError[entryMax] = {0};          7
		  Double_t vertex_tError[entryMax] = {0};          8
		  
		  */
		  
		  
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
   int i, j;
   event.numVert=0;
   j =0;
    for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->end();
       ++itVert){
		  
         event.numVert++;
	     
	     event.vertex[j][0] = itVert->x();
	     event.vertex[j][1] = itVert->y();
	     event.vertex[j][2] = itVert->z();
	     //event.vertex[j][3] = itVert->t();
	     event.vertex[j][3] = itVert->xError();
	     event.vertex[j][4] = itVert->yError();
	     event.vertex[j][5] = itVert->xError();
	     //event.vertex[j][7] = itVert->tError();
		 j++;
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
		   event.track_phi[i] = itTrack->phi();
		   event.track_nHits[i] = itTrack->numberOfValidHits();
		   event.track_found[i] = itTrack->found();
		   event.track_dxy[i] = itTrack->dxy();
		   event.track_dxyError[i] = itTrack->dxyError();
		   event.track_dz[i] = itTrack->dz();
		   event.track_charge[i] = itTrack->charge();
		   //std::cout<<event.track_charge[i]<<std::endl;
		   event.track_highPurity[i] = itTrack->quality(reco::Track::highPurity);
		   event.track_tight[i] = itTrack->quality(reco::Track::tight);
		   event.track_loose[i] = itTrack->quality(reco::Track::loose);
         
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
 
 //mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I:track_pt[numTrack]/D:track_px[numTrack]/D:track_pz[numTrack]/D:track_py[numTrack]/D:track_vx[numTrack]/D:track_vy[numTrack]/D:track_vz[numTrack]/D:track_chi2[numTrack]/D:track_ndof[numTrack]/I:track_eta[numTrack]/D:track_phi[numTrack]/D:track_nHits[numTrack]/D:track_found[numTrack]/I:track_dxy[numTrack]/D:track_dxyError[numTrack]/D:track_dz[numTrack]/D:track_charge[numTrack]/I:track_highPurity[numTrack]/O:track_tight[numTrack]/O:track_loose[numTrack]/O:trigObj_pt[numTrigObj]/D:trigObj_px[numTrigObj]/D:trigObj_pz[numTrigObj]/D:trigObj_py[numTrigObj]/D:trigObj_eta[numTrigObj]/D:trigObj_phi[numTrigObj]/D:trigObj_energy[numTrigObj]/D:triggerActivated/O:vertexTrack_vx[numVertTrack]/D:vertexTrack_vy[numVertTrack]/D:vertexTrack_vz[numVertTrack]/D:vertexTrack_nHits[numVertTrack]/D:vertexTrack_chi2[numVertTrack]/D:vertex[numVert][6]/D");
 //mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I");

 
        mtree->Branch("Ev_Branch",&event ,"numTrack/I:numTrigObj/I:numVertTrack/I:numVert/I");
		   mtree->Branch("track_pt",event.track_pt,"track_pt[numTrack]/D");
		   mtree->Branch("track_px", event.track_px, "track_px[numTrack]/D");
           mtree->Branch("track_py", event.track_py, "track_py[numTrack]/D");
           mtree->Branch("track_pz", event.track_pz, "track_pz[numTrack]/D");
           mtree->Branch("track_vx", event.track_vx, "track_vx[numTrack]/D");
           mtree->Branch("track_vy", event.track_vy, "track_vy[numTrack]/D");
           mtree->Branch("track_vz", event.track_vz, "track_vz[numTrack]/D");
           mtree->Branch("track_chi2", event.track_chi2, "track_chi2[numTrack]/D");
           mtree->Branch("track_ndof", event.track_ndof, "track_ndof[numTrack]/I");
           mtree->Branch("track_eta", event.track_eta, "track_eta[numTrack]/D");
           mtree->Branch("track_phi", event.track_phi, "track_phi[numTrack]/D");
           mtree->Branch("track_nHits", event.track_nHits, "track_nHits[numTrack]/I");
           mtree->Branch("track_found", event.track_found, "track_nfound[numTrack]/I");
           mtree->Branch("track_dxy", event.track_dxy, "track_dxy[numTrack]/D");
           mtree->Branch("track_dxyError", event.track_dxyError, "track_dxyError[numTrack]/D");
           mtree->Branch("track_dz", event.track_dz, "track_dz[numTrack]/D");
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
           mtree->Branch("vertexTrack_vx", event.vertexTrack_vx, "vertexTrack_vx[numVertTrack]/D");
           mtree->Branch("vertexTrack_vy", event.vertexTrack_vy, "vertexTrack_vy[numVertTrack]/D");
           mtree->Branch("vertexTrack_vz", event.vertexTrack_vz, "vertexTrack_vz[numVertTrack]/D");
           mtree->Branch("vertexTrack_nHits", event.vertexTrack_nHits, "vertexTrack_nHits[numVertTrack]/I");
           mtree->Branch("vertexTrack_chi2", event.vertexTrack_chi2, "vertexTrack_chi2[numVertTrack]/D");
           mtree->Branch("vertex", event.vertex, "vertex[numVert][6]/D");
		  
		  
		  
	
		
		
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
