// -*- C++ -*-
//
// Package:    SimuMuonAnalyzer
// Class:      SimuMuonAnalyzer
// 
/**\class SimuMuonAnalyzer SimuMuonAnalyzer.cc Ntuple/SimuMuonAnalyzer/src/SimuMuonAnalyzer.cc

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

class SimuMuonAnalyzer : public edm::EDAnalyzer {
   public:
      explicit SimuMuonAnalyzer(const edm::ParameterSet&);
      ~SimuMuonAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endRun(edm::Run const&, edm::EventSetup const&);
      virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      
     bool cmsStandardCuts(const edm::Event&, const edm::EventSetup&);
     bool matchingCuts( bool , double , int , int , double);
     double deltaR(double , double , double, double);
     double conePt(int , int , double , double , int ,const edm::Event& , const edm::EventSetup& );
     double mCos(double , double , double , double  );
     double mTheta(double , double , double , double );
     double invMass(double , double , double , double  , double ,  double );
   //   TTree * mtree;
      TFile * mfile;
     // TH1F * h_;
      TH1F * h_invMass;
      int vuelta;
      int NvertTracks = 0, Ntracks = 0;
      int numJets2 = 0;
      
    
		 

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
SimuMuonAnalyzer::SimuMuonAnalyzer(const edm::ParameterSet& iConfig)
:
 trackTags_(iConfig.getUntrackedParameter<edm::InputTag>("tracks")),
 outFile_(iConfig.getParameter<std::string>("outFile"))

{
   //now do what ever initialization is needed

}


SimuMuonAnalyzer::~SimuMuonAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
SimuMuonAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace reco;
   using namespace std;
  
Handle<TrackCollection> tracks;
iEvent.getByLabel(trackTags_,tracks);
   
edm::Handle<edm::TriggerResults> trigResults; 
edm::InputTag trigResultsTag("TriggerResults","","HLT");
edm::InputTag trigEventTag("hltTriggerSummaryAOD","","HLT");
iEvent.getByLabel(trigResultsTag,trigResults);
const edm::TriggerNames& trigNames = iEvent.triggerNames(*trigResults);


//data process=HLT, MC depends, Spring11 is REDIGI311X
edm::Handle<trigger::TriggerEvent> trigEvent; 
iEvent.getByLabel(trigEventTag,trigEvent);

// get primary vertex coordinates
Handle<reco::VertexCollection> vertHand;
   iEvent.getByLabel( "offlinePrimaryVertices",vertHand);
double vertex_x=0, vertex_y=0;
 for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->begin()+1&& itVert != vertHand->end();
       ++itVert)
       {
		   vertex_x=itVert->x();
		   vertex_y = itVert->y();
		   
		   if (vertex_x && vertex_y){}
	   }
 reco::BeamSpot beamSpot;
edm::Handle<reco::BeamSpot> beamSpotHandle;
iEvent.getByLabel("offlineBeamSpot", beamSpotHandle);


double beamX = 0;
double beamY = 0;
if ( beamSpotHandle.isValid() )
{
    beamSpot = *beamSpotHandle; 
    beamX = beamSpot.x0();
    beamY = beamSpot.y0();
}
 
 
std::string pathName = "none";
std::string toFind[2] = {"HLT_L2DoubleMu23_NoVertex_v9", "HLT_L2DoubleMu30_NoVertex"};

   
int trigPathSize = trigNames.size();
int triggerFound=9;
for(int j = 0; j < 2; j++){
for (unsigned int i = 0; i< trigNames.size(); i++)
{
	
	
	std::string trig = trigNames.triggerName(i);
	if ( trig.find(toFind[j]) !=std::string::npos ){
		
		
		triggerFound=j;
		pathName = trig;
		i = trigNames.size();
		j = 3;
		
		}
		
	}
}

std::string filterName = "none";

if (triggerFound == 0)
{
	filterName = "hltL2DoubleMu23NoVertexL2PreFiltered";
}
else if (triggerFound == 1)
{
	filterName = "hltL2DoubleMu30NoVertexL2PreFiltered";
}
else
{
	cout<<"trigger Not found"<<endl;
}

//cout<<filterName<<endl;


bool passTrig;
int trigIndex = trigNames.triggerIndex(pathName);
if (trigIndex != trigPathSize)
{
    passTrig=trigResults->accept(trigNames.triggerIndex(pathName));   // may cause vector::_M_range_check exeption
    
    //event.triggerActivated = passTrig;
    //cout<<"was trigger activated: "<<(int)passTrig<<endl;
}
else
{
	passTrig=false;
}
   
bool standardCuts = cmsStandardCuts(iEvent, iSetup);


int matchedTrack[tracks->size()];
for (int i = 0; i<(int)tracks->size(); i++)
{
	matchedTrack[i] = 0;
}
//cout<<matchedTrack[0]<<endl;
std::string e_filterName(filterName); // dataset photones (para filtrar electrones)
   

trigger::size_type e_filterIndex = trigEvent->filterIndex(edm::InputTag(e_filterName,"",trigEventTag.process())); 
  
 if(e_filterIndex<trigEvent->sizeFilters())
 { 
	  
	 
      const trigger::Keys& trigKeys = trigEvent->filterKeys(e_filterIndex); 
      
      const trigger::TriggerObjectCollection & e_trigObjColl(trigEvent->getObjects());
     
     
  
if ((standardCuts && passTrig) )
{
 int i = 0;
 for(TrackCollection::const_iterator itTrack = tracks->begin();
       itTrack != tracks->end();                      
       ++itTrack) 
       {
		  for(trigger::Keys::const_iterator keyIt=trigKeys.begin();keyIt!=trigKeys.end();++keyIt)
		  {
			   const trigger::TriggerObject& obj = e_trigObjColl[*keyIt];
			  // cout<<obj.pt()<<endl;
			   bool lepMatchCut =matchingCuts( itTrack->quality(reco::Track::highPurity)  , itTrack->pt() , itTrack->hitPattern().numberOfValidTrackerHits(),itTrack->hitPattern().numberOfValidPixelHits(), itTrack->eta());
		
		  
		   if (lepMatchCut)
		   { 
			    if(deltaR(itTrack->phi(), itTrack->eta(), obj.phi(), obj.eta())< 0.1 )
			   {  
				   matchedTrack[i] = 1;
				   
			      
			   }
			   
		   } 
			  
		  }
		  i++;
	   }
	
	

}
}



int  i =0;
for(TrackCollection::const_iterator itTrack1 = tracks->begin();
       itTrack1 != tracks->end();                      
       ++itTrack1) 
{
	if (itTrack1->charge()==1 && matchedTrack[i] == 1 ){
	int	j=0;
	for(TrackCollection::const_iterator itTrack2 = tracks->begin();
       itTrack2 != tracks->end();                      
       ++itTrack2) 
       {
		   if(itTrack2->charge() ==-1 && matchedTrack[j] ==1   && deltaR(itTrack1->phi(), itTrack1->eta(), itTrack2->phi(), itTrack2->eta())> 0.2 )
		   {  
			   
 // Secondary vertex is reconstructed
			   // get RECO tracks from the event
					edm::Handle<reco::TrackCollection> tks;
					iEvent.getByLabel(trackTags_, tks);
                    KalmanVertexFitter fitter;
					//get the builder:
					edm::ESHandle<TransientTrackBuilder> theB;
					iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder",theB);
					//do the conversion:
					std::vector<reco::TransientTrack> t_tks = (*theB).build(tks);
					
				   
				   std::vector<reco::TransientTrack> trackVec;
                    
				   if ( (int)t_tks.size()>2){

				   trackVec.push_back(t_tks[i]);
					

				   trackVec.push_back(t_tks[j]); 
				   TransientVertex myVertex = fitter.vertex(trackVec);
				  
		 
				  
              if (myVertex.isValid() && myVertex.normalisedChiSquared() < 5)
					 {
			   double secVert_x =(double)myVertex.position().x();
			   double secVert_y =(double)myVertex.position().y();
			   //cout<<secVert_x<<secVert_y<<endl;
			   double conePt_var=conePt(i , j, itTrack1->eta(), itTrack1->phi(),  tracks->size(), iEvent,iSetup);
			   
			   double cosAlpha = mCos(itTrack1->phi(), itTrack1->eta(), itTrack2->phi(), itTrack2->eta());
			   double theta = mTheta(itTrack1->px()+itTrack2->px(), itTrack1->py()+itTrack2->py(),secVert_x -beamX,  secVert_y-beamY);
			  // cout<<conePt_var<<cosAlpha<<vertex_x<<vertex_y<<theta<<endl;
			  cout<<"theta: "<<theta*180/3.1415<<endl;
			  cout<<"disp "<<secVert_x -beamX<<endl;
			  cout<<"beam "<<beamX<<endl;
			  cout<<"secVert "<<secVert_x<<endl;
			   if ((conePt_var < 4 && cosAlpha > -0.95 && (theta < 0.2 )))
					
					{
						double invariantMass;
					 invariantMass = invMass(itTrack1->px(), itTrack1->py(), itTrack1->pz(),itTrack2->px(), itTrack2->py(), itTrack2->pz());
				         h_invMass->Fill(invariantMass);
				 
				 
				 }
			   
		   }
		   }
		   }
		
		j ++;   
	   }
   }
i++;
}



//   Compare mathced tracks to see if they originated from the same vertex




#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
//mtree->Fill();

}

// ------------ method called once each job just before starting event loop  ------------
void 
SimuMuonAnalyzer::beginJob()
{TH1::AddDirectory(true);
 vuelta = 0;
 const char* of = outFile_.c_str();
 mfile = new TFile(of, "recreate");
 
 h_invMass = new TH1F ("InvMass", "Lepton Pair Invariant Mass", 100, 0 , 600);
	  
	
		
		
}




           


          


// ------------ method called once each job just after ending the event loop  ------------
void 
SimuMuonAnalyzer::endJob() {

//mtree->Write();
//std::cout<<"num traks "<<Ntracks<<" num vertTraks "<<NvertTracks<<std::endl;
mfile->Write();
mfile->Close();
}




bool
SimuMuonAnalyzer::cmsStandardCuts(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
 bool ret = false;
 int disp = 0;
 int numHighPurity = 0;
 int numTracks = 0;

 double purityFrac = 0.0;
 using namespace edm;
 using namespace reco;
   Handle<reco::VertexCollection> vertHand;
   iEvent.getByLabel( "offlinePrimaryVertices",vertHand);
   
   Handle<TrackCollection> tracks;
   iEvent.getByLabel(trackTags_,tracks);
   
   for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->begin()+1 && itVert != vertHand->end();
       ++itVert)
       {
		  
		    for(reco::Vertex::trackRef_iterator itTrack = itVert->tracks_begin();
       itTrack != itVert->tracks_end();
       ++itTrack)
           {
		        
		 double tx = (**itTrack).vx();
	     double ty = (**itTrack).vy();
		 double tz = (**itTrack).vz();
		 double tr = sqrt(tx*tx +ty*ty);
		 if ( (tr < 2 )&&(tz < 24) )
		 {
			 disp ++;
		 }
 
    	   }
		    
	   }
	 
	   
	   for(TrackCollection::const_iterator itTrack = tracks->begin();
       itTrack != tracks->end();                      
       ++itTrack) 
       {   
		  
		   numTracks ++;
		   
		   if (itTrack->quality(reco::Track::highPurity))
		   {
			   numHighPurity++;
		   }
		   
	   }
	   
	   purityFrac = (double)numHighPurity/numTracks;
	   if (numTracks<10)
	   {
		   purityFrac = 1;
	   }
	   
	   if(disp >=4 && purityFrac >= 0.25)
	   {
		   ret = true;
	   }
	   
	
	
	return ret;
	

}




bool 
SimuMuonAnalyzer::matchingCuts( bool purity, double pt, int hits, int hits3D, double eta)
{
	bool ret = false;
	
	
		
	  if(purity && pt > 33 && hits >= 6   && eta < 2  )
	  if(true)
	  
	  {
		  ret = true;

	  }	
	 
	  

	
	return ret;
}
double 
SimuMuonAnalyzer::deltaR(double obj1Phi, double obj1Eta, double obj2Phi, double obj2Eta)
{
	double dPhi = obj1Phi - obj2Phi;
	if (abs(dPhi)>3.1415/2)
	{
		dPhi =  3.1415 -dPhi;
	}
	double dEta = obj1Eta - obj2Eta;
	double dR = sqrt(dPhi*dPhi + dEta*dEta);
	return dR;
}
double 
SimuMuonAnalyzer::conePt(int forbiddenIndex1, int forbiddenIndex2, double eta, double phi, int numTracks,const edm::Event& iEvent, const edm::EventSetup& iSetup )
{  
	using namespace edm;
	using namespace reco;
    Handle<TrackCollection> tracks;
   iEvent.getByLabel(trackTags_,tracks);
    int i =0;
	double sumPt = 0.0;
	for(TrackCollection::const_iterator itTrack = tracks->begin();
       itTrack != tracks->end();                      
       ++itTrack) 
	{
		if(deltaR(phi, eta, itTrack->phi(), itTrack->eta()) < 0.3 && deltaR(phi, eta, itTrack->phi(), itTrack->eta()) > 0.03 && i != forbiddenIndex1 && i != forbiddenIndex2)
		{
			sumPt = itTrack->pt() +sumPt;
			i++;
		}
	}
	
	return sumPt;
}
double 
SimuMuonAnalyzer::mCos(double phi1, double eta1, double phi2, double eta2 )
{double cosAlpha = cos(eta1)*cos(phi1)*cos(eta2)*cos(phi2) + cos(eta1)*sin(phi1)*cos(eta2)*sin(phi2) + sin(eta1)*cos(eta2);
	
	return cosAlpha;
}
double 
SimuMuonAnalyzer::mTheta(double ax, double ay, double bx, double by)
{
	double cosAlpha = ax*bx + ay*by;
	double theta;
	cosAlpha = cosAlpha/sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by);
	//std::cout<<"cosAlpha: "<<cosAlpha<<std::endl;
	theta  = acos(cosAlpha);
	return theta;
}
double 
SimuMuonAnalyzer::invMass(double px1, double py1, double pz1, double px2 , double py2,  double pz2)
{
  double E1 =  sqrt(px1*px1 + py1*py1 + pz1*pz1);  // asummes rest mass energy to be negligible
  double E2 =  sqrt(px2*px2 + py2*py2 + pz2*pz2);
  
  double E = E1+E2;
  double px = px1 + px2;
  double py = py1 + py2;
  double pz = pz1 + pz2;
  double mass = sqrt(E*E - px*px - py*py - pz*pz);
  
  return mass;
  
  

	
}
// ------------ method called when starting to processes a run  ------------
void 
SimuMuonAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
SimuMuonAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
SimuMuonAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
SimuMuonAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
SimuMuonAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
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
DEFINE_FWK_MODULE(SimuMuonAnalyzer);
