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
      
     bool cmsStandardCuts(const edm::Event&, const edm::EventSetup&);
     bool matchingCuts( bool , double , int , int , double, double, double);
     double deltaR(double , double , double, double);
     double conePt(int , int , double , double , int ,const edm::Event& , const edm::EventSetup& );
     double mCos(double , double , double , double  );
     double mTheta(double , double , double , double );
     double invMass(double , double , double , double  , double ,  double );
     double dotProduct(double , double , double , double );
     bool impactParameterCut(reco::TrackCollection::const_iterator, reco::TrackCollection::const_iterator, reco::BeamSpot );
   //   TTree * mtree;
      TFile * mfile;
     // TH1F * h_;
      TH1F * h_invMass;
      TH1F * h_invMassLoose;
      TH1F * h_invMassPt250;
      TH1F * h_invMassPt260;
      TH1F * h_invMassPt270;
      TH1F * h_invMassPt280;
      TH1F * h_invMassPt290;
      TH1F * h_invMassPt300;
      TH1F * h_invMassPt310;
      TH1F * h_invMassPt320;
      TH1F * h_invMassPt330;
      TH1F * h_invMassPt340;
      TH1F * h_invMassPt350;
      TH1F * h_invMassPt250Inv;
      TH1F * h_invMassPt260Inv;
      TH1F * h_invMassPt270Inv;
      TH1F * h_invMassPt280Inv;
      TH1F * h_invMassPt290Inv;
      TH1F * h_invMassPt300Inv;
      TH1F * h_invMassPt310Inv;
      TH1F * h_invMassPt320Inv;
      TH1F * h_invMassPt330Inv;
      TH1F * h_invMassPt340Inv;
      TH1F * h_invMassPt350Inv;
      TH1F * h_invMassDotCuts;
      TH1F * h_invMassDotCutsInv;
      TH1F * h_invMass_lwCut;
      TH1F * h_invMass_lwCut1;
      TH1F * h_invMass_lwCut2;
      TH1F * h_invMass_lwCut3;
      TH1F * h_invMass_lwCut4;
      TH1F * h_invMass_lwCut5;
      TH1F * h_invMass_lwCut6;
      TH1F * h_invMass_lwCut7;
      TH1F * h_invMass_lwCut8;
      TH1F * h_invMass_lwCut9;
      
      TH1F * h_invMass_lwCut_inv;
      TH1F * h_invMass_lwCut_inv1;
      TH1F * h_invMass_lwCut_inv2;
      TH1F * h_invMass_lwCut_inv3;
      TH1F * h_invMass_lwCut_inv4;
      TH1F * h_invMass_lwCut_inv5;
      TH1F * h_invMass_lwCut_inv6;
      TH1F * h_invMass_lwCut_inv7;
      TH1F * h_invMass_lwCut_inv8;
      TH1F * h_invMass_lwCut_inv9;
      TH1F * h_invMass_LC;
      TH1F * h_lxy_err;
      TH1F * h_lxy;
      TH1F * h_dotP;
      TH1F * h_dotP_err;
      TH1F * h_dotPLw;
      TH1F * h_dotPLw_err;
      TH1F * h_theta;
      TH1F * h_thetaLw;
      TH1F * h_thetaLwCut250;
      TH1F * h_thetaLwCut260;
      TH1F * h_thetaLwCut270;
      TH1F * h_thetaLwCut280;
      TH1F * h_thetaLwCut290;
      TH1F * h_thetaLwCut300;
      TH1F * h_thetaLwCut310;
      TH1F * h_thetaLwCut320;
      TH1F * h_thetaLwCut330;
      TH1F * h_thetaLwCut340;
      TH1F * h_thetaLwCut350;
      TH1F * h_thetaCut250;
      TH1F * h_thetaCut260;
      TH1F * h_thetaCut270;
      TH1F * h_thetaCut280;
      TH1F * h_thetaCut290;
      TH1F * h_thetaCut300;
      TH1F * h_thetaCut310;
      TH1F * h_thetaCut320;
      TH1F * h_thetaCut330;
      TH1F * h_thetaCut340;
      TH1F * h_thetaCut350;
      
      
      
       

TH1F * h_invMassDPCut10;
TH1F * h_invMassDPCut20;
TH1F * h_invMassDPCut30;
TH1F * h_invMassDPCut40;
TH1F * h_invMassDPCut50;
TH1F * h_invMassDPCut60;
TH1F * h_invMassDPCut70;
TH1F * h_invMassDPCut80;
TH1F * h_invMassDPCut90;
TH1F * h_invMassDPCut100;
TH1F * h_invMassDPCut110;
TH1F * h_invMassDPCut120;
TH1F * h_invMassDPCut130;
TH1F * h_invMassDPCut140;
TH1F * h_invMassDPCut150;
TH1F * h_invMassDPCut160;
TH1F * h_invMassDPCut170;
TH1F * h_invMassDPCut180;
TH1F * h_invMassDPCut190;
TH1F * h_invMassDPCut200;
TH1F * h_invMassDPCut210;
TH1F * h_invMassDPCut220;
TH1F * h_invMassDPCut230;
TH1F * h_invMassDPCut240;
TH1F * h_invMassDPCut250;
TH1F * h_invMassDPCut260;
TH1F * h_invMassDPCut270;
TH1F * h_invMassDPCut280;
TH1F * h_invMassDPCut290;
TH1F * h_invMassDPCut300;
TH1F * h_invMassDPCut310;
TH1F * h_invMassDPCut320;
TH1F * h_invMassDPCut330;
TH1F * h_invMassDPCut340;
TH1F * h_invMassDPCut350;
TH1F * h_invMassDPCut360;
TH1F * h_invMassDPCut370;
TH1F * h_invMassDPCut380;
TH1F * h_invMassDPCut390;
TH1F * h_invMassDPCut400;
TH1F * h_invMassDPCutLw10;
TH1F * h_invMassDPCutLw20;
TH1F * h_invMassDPCutLw30;
TH1F * h_invMassDPCutLw40;
TH1F * h_invMassDPCutLw50;
TH1F * h_invMassDPCutLw60;
TH1F * h_invMassDPCutLw70;
TH1F * h_invMassDPCutLw80;
TH1F * h_invMassDPCutLw90;
TH1F * h_invMassDPCutLw100;
TH1F * h_invMassDPCutLw110;
TH1F * h_invMassDPCutLw120;
TH1F * h_invMassDPCutLw130;
TH1F * h_invMassDPCutLw140;
TH1F * h_invMassDPCutLw150;
TH1F * h_invMassDPCutLw160;
TH1F * h_invMassDPCutLw170;
TH1F * h_invMassDPCutLw180;
TH1F * h_invMassDPCutLw190;
TH1F * h_invMassDPCutLw200;
TH1F * h_invMassDPCutLw210;
TH1F * h_invMassDPCutLw220;
TH1F * h_invMassDPCutLw230;
TH1F * h_invMassDPCutLw240;
TH1F * h_invMassDPCutLw250;
TH1F * h_invMassDPCutLw260;
TH1F * h_invMassDPCutLw270;
TH1F * h_invMassDPCutLw280;
TH1F * h_invMassDPCutLw290;
TH1F * h_invMassDPCutLw300;
TH1F * h_invMassDPCutLw310;
TH1F * h_invMassDPCutLw320;
TH1F * h_invMassDPCutLw330;
TH1F * h_invMassDPCutLw340;
TH1F * h_invMassDPCutLw350;
TH1F * h_invMassDPCutLw360;
TH1F * h_invMassDPCutLw370;
TH1F * h_invMassDPCutLw380;
TH1F * h_invMassDPCutLw390;
TH1F * h_invMassDPCutLw400;

TH1F * h_invMassDPCut_noErr5;
TH1F * h_invMassDPCut_noErr10;
TH1F * h_invMassDPCut_noErr15;
TH1F * h_invMassDPCut_noErr20;
TH1F * h_invMassDPCut_noErr25;
TH1F * h_invMassDPCut_noErr30;
TH1F * h_invMassDPCut_noErr35;
TH1F * h_invMassDPCut_noErr40;
TH1F * h_invMassDPCut_noErr45;
TH1F * h_invMassDPCut_noErr50;
TH1F * h_invMassDPCut_noErr55;
TH1F * h_invMassDPCut_noErr60;
TH1F * h_invMassDPCut_noErr65;
TH1F * h_invMassDPCut_noErr70;
TH1F * h_invMassDPCut_noErr75;
TH1F * h_invMassDPCut_noErr80;
TH1F * h_invMassDPCut_noErr85;
TH1F * h_invMassDPCut_noErr90;
TH1F * h_invMassDPCut_noErr95;
TH1F * h_invMassDPCut_noErr100;
TH1F * h_invMassDPCut_noErr105;
TH1F * h_invMassDPCut_noErr110;
TH1F * h_invMassDPCut_noErr115;
TH1F * h_invMassDPCut_noErr120;
TH1F * h_invMassDPCut_noErr125;
TH1F * h_invMassDPCut_noErr130;
TH1F * h_invMassDPCut_noErr135;
TH1F * h_invMassDPCut_noErr140;
TH1F * h_invMassDPCut_noErr145;
TH1F * h_invMassDPCut_noErr150;
TH1F * h_invMassDPCut_noErr155;
TH1F * h_invMassDPCut_noErr160;
TH1F * h_invMassDPCut_noErr165;
TH1F * h_invMassDPCut_noErr170;
TH1F * h_invMassDPCut_noErr175;
TH1F * h_invMassDPCut_noErr180;
TH1F * h_invMassDPCut_noErr185;
TH1F * h_invMassDPCut_noErr190;
TH1F * h_invMassDPCut_noErr195;
TH1F * h_invMassDPCut_noErr200;
TH1F * h_invMassDPCutLw_noErr5;
TH1F * h_invMassDPCutLw_noErr10;
TH1F * h_invMassDPCutLw_noErr15;
TH1F * h_invMassDPCutLw_noErr20;
TH1F * h_invMassDPCutLw_noErr25;
TH1F * h_invMassDPCutLw_noErr30;
TH1F * h_invMassDPCutLw_noErr35;
TH1F * h_invMassDPCutLw_noErr40;
TH1F * h_invMassDPCutLw_noErr45;
TH1F * h_invMassDPCutLw_noErr50;
TH1F * h_invMassDPCutLw_noErr55;
TH1F * h_invMassDPCutLw_noErr60;
TH1F * h_invMassDPCutLw_noErr65;
TH1F * h_invMassDPCutLw_noErr70;
TH1F * h_invMassDPCutLw_noErr75;
TH1F * h_invMassDPCutLw_noErr80;
TH1F * h_invMassDPCutLw_noErr85;
TH1F * h_invMassDPCutLw_noErr90;
TH1F * h_invMassDPCutLw_noErr95;
TH1F * h_invMassDPCutLw_noErr100;
TH1F * h_invMassDPCutLw_noErr105;
TH1F * h_invMassDPCutLw_noErr110;
TH1F * h_invMassDPCutLw_noErr115;
TH1F * h_invMassDPCutLw_noErr120;
TH1F * h_invMassDPCutLw_noErr125;
TH1F * h_invMassDPCutLw_noErr130;
TH1F * h_invMassDPCutLw_noErr135;
TH1F * h_invMassDPCutLw_noErr140;
TH1F * h_invMassDPCutLw_noErr145;
TH1F * h_invMassDPCutLw_noErr150;
TH1F * h_invMassDPCutLw_noErr155;
TH1F * h_invMassDPCutLw_noErr160;
TH1F * h_invMassDPCutLw_noErr165;
TH1F * h_invMassDPCutLw_noErr170;
TH1F * h_invMassDPCutLw_noErr175;
TH1F * h_invMassDPCutLw_noErr180;
TH1F * h_invMassDPCutLw_noErr185;
TH1F * h_invMassDPCutLw_noErr190;
TH1F * h_invMassDPCutLw_noErr195;
TH1F * h_invMassDPCutLw_noErr200;
      
      TH1F * h_pt;
      TH1F * h_ptP;
      TH1F * h_ptM;
      TH1F * nEvents;
      
      
      int vuelta;
      int NvertTracks = 0, Ntracks = 0;
      int numJets2 = 0;
      double dotMax = 0;
      double dotMin = 0;
    
		 

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
   using namespace reco;
   using namespace std;
nEvents->Fill(1); 
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
double vertex_x=0, vertex_y=0, vertex_xError=0, vertex_yError=0;
 for(reco::VertexCollection::const_iterator itVert = vertHand->begin();
       itVert != vertHand->begin()+1&& itVert != vertHand->end();
       ++itVert)
       {
		   vertex_x=itVert->x();
		   vertex_y = itVert->y();
		   vertex_xError=itVert->xError();
		   vertex_yError=itVert->yError();
		   
		   if (vertex_x && vertex_y){}
	   }
 reco::BeamSpot beamSpot;
edm::Handle<reco::BeamSpot> beamSpotHandle;
iEvent.getByLabel("offlineBeamSpot", beamSpotHandle);


double beamX = 0;
double beamY = 0;
double beamXErr = 0;
double beamYErr = 0;
if ( beamSpotHandle.isValid() )
{
    beamSpot = *beamSpotHandle; 
    beamX = beamSpot.x0();
    beamY = beamSpot.y0();
    beamXErr = beamSpot.x0Error();
    beamYErr = beamSpot.y0Error();
    if(beamX && beamY && beamXErr && beamYErr){}
}
 
 
std::string pathName = "none";
std::string toFind[2] = {"HLT_L2DoubleMu23_NoVertex", "HLT_L2DoubleMu30_NoVertex"};

   
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
     
     
  
if ((standardCuts && passTrig && beamSpotHandle.isValid()) )
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
			   bool lepMatchCut =matchingCuts( itTrack->quality(reco::Track::highPurity)  , itTrack->pt() , itTrack->hitPattern().numberOfValidTrackerHits(),itTrack->hitPattern().numberOfValidPixelHits(), itTrack->eta(), itTrack->dxy(beamSpot), itTrack->dxyError());
		
		  
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
			   double theta = mTheta(itTrack1->px()+itTrack2->px(), itTrack1->py()+itTrack2->py(),secVert_x -vertex_x,  secVert_y-vertex_y);
			   double px = itTrack1->px() + itTrack2->px();
			   double py = itTrack1->py() + itTrack2->py();
			   double pt = sqrt(px*px + py*py);
			   
			    bool IPC = impactParameterCut(itTrack1, itTrack2, beamSpot);
					    //double IPC = impactParameterCut(itTrack1, itTrack2, beamSpot);
			    double secVertErrx = myVertex.positionError().cxx();
			    double secVertErry = myVertex.positionError().cyy();
				double tdl_x = secVert_x - vertex_x;
				double tdl_y = secVert_y - vertex_y;
				double tdl = sqrt(tdl_x*tdl_x + tdl_y*tdl_y);
				double tdl_errx = secVertErrx + vertex_xError;
				double tdl_erry = secVertErry + vertex_yError;
						//double tdl_err = sqrt(tdl_errx*tdl_errx + tdl_erry*tdl_erry);
				double difx = (secVert_x)/(sqrt((secVert_x*secVert_x)+(secVert_y*secVert_y)));
				double dify = (secVert_y)/(sqrt((secVert_x*secVert_x)+(secVert_y*secVert_y)));
				double tot_variance = difx*difx*tdl_errx +dify*dify*tdl_erry; 
				double tdl_err = sqrt(tot_variance);
				double invariantMass;
			  // cout<<conePt_var<<cosAlpha<<vertex_x<<vertex_y<<theta<<endl;
			 /* cout<<"theta: "<<theta*180/3.1415<<endl;
			  cout<<"disp "<<secVert_x -beamX<<endl;
			  cout<<"beam "<<beamX<<endl;
			  cout<<"secVert "<<secVert_x<<endl;*/
			  double dot;
			  dot = dotProduct(secVert_x-vertex_x, secVert_y-vertex_y, itTrack1->px()+itTrack2->px(),itTrack1->py()+itTrack2->py());
			  invariantMass = invMass(itTrack1->px(), itTrack1->py(), itTrack1->pz(),itTrack2->px(), itTrack2->py(), itTrack2->pz());
			  //cout<<theta<<endl;
			  h_theta->Fill(theta);
			  h_thetaLw->Fill(3.1514-theta);
			  h_pt->Fill(pt);
			  if ((dot/tdl_err) <-3){h_ptM->Fill(pt);}
			  if ((dot/tdl_err) > 3){h_ptP->Fill(pt);}
			   if (pt > 250){h_invMassPt250Inv->Fill(invariantMass);h_thetaCut250->Fill(theta); h_thetaLwCut250->Fill(3.1514-theta);}
			  if (pt > 260){h_invMassPt260Inv->Fill(invariantMass);h_thetaCut260->Fill(theta); h_thetaLwCut260->Fill(3.1514-theta);}
			  if (pt > 270){h_invMassPt270Inv->Fill(invariantMass);h_thetaCut270->Fill(theta); h_thetaLwCut270->Fill(3.1514-theta);}
			  if (pt > 280){h_invMassPt280Inv->Fill(invariantMass);h_thetaCut280->Fill(theta); h_thetaLwCut280->Fill(3.1514-theta);}
			  if (pt > 290){h_invMassPt290Inv->Fill(invariantMass);h_thetaCut290->Fill(theta); h_thetaLwCut290->Fill(3.1514-theta);}
			  if (pt > 300){h_invMassPt300Inv->Fill(invariantMass); h_thetaCut300->Fill(theta); h_thetaLwCut300->Fill(3.1514-theta);}
			  if (pt > 310){h_invMassPt310Inv->Fill(invariantMass); h_thetaCut310->Fill(theta); h_thetaLwCut310->Fill(3.1514-theta);}
			  if (pt > 320){h_invMassPt320Inv->Fill(invariantMass); h_thetaCut320->Fill(theta); h_thetaLwCut320->Fill(3.1514-theta);}
			  if (pt > 330){h_invMassPt330Inv->Fill(invariantMass); h_thetaCut330->Fill(theta); h_thetaLwCut330->Fill(3.1514-theta);}
			  if (pt > 340){h_invMassPt340Inv->Fill(invariantMass); h_thetaCut340->Fill(theta); h_thetaLwCut340->Fill(3.1514-theta);}
			  if (pt > 350){h_invMassPt350Inv->Fill(invariantMass); h_thetaCut350->Fill(theta); h_thetaLwCut350->Fill(3.1514-theta);}
			  
			  
			  
			  					  
				if ((dot/tdl_err) <-10){h_invMassDPCut10->Fill(invariantMass);} 
				if ((dot/tdl_err) <-20){h_invMassDPCut20->Fill(invariantMass);} 
				if ((dot/tdl_err) <-30){h_invMassDPCut30->Fill(invariantMass);} 
				if ((dot/tdl_err) <-40){h_invMassDPCut40->Fill(invariantMass);} 
				if ((dot/tdl_err) <-50){h_invMassDPCut50->Fill(invariantMass);} 
				if ((dot/tdl_err) <-60){h_invMassDPCut60->Fill(invariantMass);} 
				if ((dot/tdl_err) <-70){h_invMassDPCut70->Fill(invariantMass);} 
				if ((dot/tdl_err) <-80){h_invMassDPCut80->Fill(invariantMass);} 
				if ((dot/tdl_err) <-90){h_invMassDPCut90->Fill(invariantMass);} 
				if ((dot/tdl_err) <-100){h_invMassDPCut100->Fill(invariantMass);} 
				if ((dot/tdl_err) <-110){h_invMassDPCut110->Fill(invariantMass);} 
				if ((dot/tdl_err) <-120){h_invMassDPCut120->Fill(invariantMass);} 
				if ((dot/tdl_err) <-130){h_invMassDPCut130->Fill(invariantMass);} 
				if ((dot/tdl_err) <-140){h_invMassDPCut140->Fill(invariantMass);} 
				if ((dot/tdl_err) <-150){h_invMassDPCut150->Fill(invariantMass);} 
				if ((dot/tdl_err) <-160){h_invMassDPCut160->Fill(invariantMass);} 
				if ((dot/tdl_err) <-170){h_invMassDPCut170->Fill(invariantMass);} 
				if ((dot/tdl_err) <-180){h_invMassDPCut180->Fill(invariantMass);} 
				if ((dot/tdl_err) <-190){h_invMassDPCut190->Fill(invariantMass);} 
				if ((dot/tdl_err) <-200){h_invMassDPCut200->Fill(invariantMass);} 
				if ((dot/tdl_err) <-210){h_invMassDPCut210->Fill(invariantMass);} 
				if ((dot/tdl_err) <-220){h_invMassDPCut220->Fill(invariantMass);} 
				if ((dot/tdl_err) <-230){h_invMassDPCut230->Fill(invariantMass);} 
				if ((dot/tdl_err) <-240){h_invMassDPCut240->Fill(invariantMass);} 
				if ((dot/tdl_err) <-250){h_invMassDPCut250->Fill(invariantMass);} 
				if ((dot/tdl_err) <-260){h_invMassDPCut260->Fill(invariantMass);} 
				if ((dot/tdl_err) <-270){h_invMassDPCut270->Fill(invariantMass);} 
				if ((dot/tdl_err) <-280){h_invMassDPCut280->Fill(invariantMass);} 
				if ((dot/tdl_err) <-290){h_invMassDPCut290->Fill(invariantMass);} 
				if ((dot/tdl_err) <-300){h_invMassDPCut300->Fill(invariantMass);} 
				if ((dot/tdl_err) <-310){h_invMassDPCut310->Fill(invariantMass);} 
				if ((dot/tdl_err) <-320){h_invMassDPCut320->Fill(invariantMass);} 
				if ((dot/tdl_err) <-330){h_invMassDPCut330->Fill(invariantMass);} 
				if ((dot/tdl_err) <-340){h_invMassDPCut340->Fill(invariantMass);} 
				if ((dot/tdl_err) <-350){h_invMassDPCut350->Fill(invariantMass);} 
				if ((dot/tdl_err) <-360){h_invMassDPCut360->Fill(invariantMass);} 
				if ((dot/tdl_err) <-370){h_invMassDPCut370->Fill(invariantMass);} 
				if ((dot/tdl_err) <-380){h_invMassDPCut380->Fill(invariantMass);} 
				if ((dot/tdl_err) <-390){h_invMassDPCut390->Fill(invariantMass);} 
				if ((dot/tdl_err) <-400){h_invMassDPCut400->Fill(invariantMass);} 
				if ((-dot/tdl_err) <-10){h_invMassDPCutLw10->Fill(invariantMass);}
				if ((-dot/tdl_err) <-20){h_invMassDPCutLw20->Fill(invariantMass);}
				if ((-dot/tdl_err) <-30){h_invMassDPCutLw30->Fill(invariantMass);}
				if ((-dot/tdl_err) <-40){h_invMassDPCutLw40->Fill(invariantMass);}
				if ((-dot/tdl_err) <-50){h_invMassDPCutLw50->Fill(invariantMass);}
				if ((-dot/tdl_err) <-60){h_invMassDPCutLw60->Fill(invariantMass);}
				if ((-dot/tdl_err) <-70){h_invMassDPCutLw70->Fill(invariantMass);}
				if ((-dot/tdl_err) <-80){h_invMassDPCutLw80->Fill(invariantMass);}
				if ((-dot/tdl_err) <-90){h_invMassDPCutLw90->Fill(invariantMass);}
				if ((-dot/tdl_err) <-100){h_invMassDPCutLw100->Fill(invariantMass);}
				if ((-dot/tdl_err) <-110){h_invMassDPCutLw110->Fill(invariantMass);}
				if ((-dot/tdl_err) <-120){h_invMassDPCutLw120->Fill(invariantMass);}
				if ((-dot/tdl_err) <-130){h_invMassDPCutLw130->Fill(invariantMass);}
				if ((-dot/tdl_err) <-140){h_invMassDPCutLw140->Fill(invariantMass);}
				if ((-dot/tdl_err) <-150){h_invMassDPCutLw150->Fill(invariantMass);}
				if ((-dot/tdl_err) <-160){h_invMassDPCutLw160->Fill(invariantMass);}
				if ((-dot/tdl_err) <-170){h_invMassDPCutLw170->Fill(invariantMass);}
				if ((-dot/tdl_err) <-180){h_invMassDPCutLw180->Fill(invariantMass);}
				if ((-dot/tdl_err) <-190){h_invMassDPCutLw190->Fill(invariantMass);}
				if ((-dot/tdl_err) <-200){h_invMassDPCutLw200->Fill(invariantMass);}
				if ((-dot/tdl_err) <-210){h_invMassDPCutLw210->Fill(invariantMass);}
				if ((-dot/tdl_err) <-220){h_invMassDPCutLw220->Fill(invariantMass);}
				if ((-dot/tdl_err) <-230){h_invMassDPCutLw230->Fill(invariantMass);}
				if ((-dot/tdl_err) <-240){h_invMassDPCutLw240->Fill(invariantMass);}
				if ((-dot/tdl_err) <-250){h_invMassDPCutLw250->Fill(invariantMass);}
				if ((-dot/tdl_err) <-260){h_invMassDPCutLw260->Fill(invariantMass);}
				if ((-dot/tdl_err) <-270){h_invMassDPCutLw270->Fill(invariantMass);}
				if ((-dot/tdl_err) <-280){h_invMassDPCutLw280->Fill(invariantMass);}
				if ((-dot/tdl_err) <-290){h_invMassDPCutLw290->Fill(invariantMass);}
				if ((-dot/tdl_err) <-300){h_invMassDPCutLw300->Fill(invariantMass);}
				if ((-dot/tdl_err) <-310){h_invMassDPCutLw310->Fill(invariantMass);}
				if ((-dot/tdl_err) <-320){h_invMassDPCutLw320->Fill(invariantMass);}
				if ((-dot/tdl_err) <-330){h_invMassDPCutLw330->Fill(invariantMass);}
				if ((-dot/tdl_err) <-340){h_invMassDPCutLw340->Fill(invariantMass);}
				if ((-dot/tdl_err) <-350){h_invMassDPCutLw350->Fill(invariantMass);}
				if ((-dot/tdl_err) <-360){h_invMassDPCutLw360->Fill(invariantMass);}
				if ((-dot/tdl_err) <-370){h_invMassDPCutLw370->Fill(invariantMass);}
				if ((-dot/tdl_err) <-380){h_invMassDPCutLw380->Fill(invariantMass);}
				if ((-dot/tdl_err) <-390){h_invMassDPCutLw390->Fill(invariantMass);}
				if ((-dot/tdl_err) <-400){h_invMassDPCutLw400->Fill(invariantMass);}
				
				if ((dot) <-0.5){h_invMassDPCut_noErr5->Fill(invariantMass);} 
				if ((dot) <-1.0){h_invMassDPCut_noErr10->Fill(invariantMass);} 
				if ((dot) <-1.5){h_invMassDPCut_noErr15->Fill(invariantMass);} 
				if ((dot) <-2.0){h_invMassDPCut_noErr20->Fill(invariantMass);} 
				if ((dot) <-2.5){h_invMassDPCut_noErr25->Fill(invariantMass);} 
				if ((dot) <-3.0){h_invMassDPCut_noErr30->Fill(invariantMass);} 
				if ((dot) <-3.5){h_invMassDPCut_noErr35->Fill(invariantMass);} 
				if ((dot) <-4.0){h_invMassDPCut_noErr40->Fill(invariantMass);} 
				if ((dot) <-4.5){h_invMassDPCut_noErr45->Fill(invariantMass);} 
				if ((dot) <-5.0){h_invMassDPCut_noErr50->Fill(invariantMass);} 
				if ((dot) <-5.5){h_invMassDPCut_noErr55->Fill(invariantMass);} 
				if ((dot) <-6.0){h_invMassDPCut_noErr60->Fill(invariantMass);} 
				if ((dot) <-6.5){h_invMassDPCut_noErr65->Fill(invariantMass);} 
				if ((dot) <-7.0){h_invMassDPCut_noErr70->Fill(invariantMass);} 
				if ((dot) <-7.5){h_invMassDPCut_noErr75->Fill(invariantMass);} 
				if ((dot) <-8.0){h_invMassDPCut_noErr80->Fill(invariantMass);} 
				if ((dot) <-8.5){h_invMassDPCut_noErr85->Fill(invariantMass);} 
				if ((dot) <-9.0){h_invMassDPCut_noErr90->Fill(invariantMass);} 
				if ((dot) <-9.5){h_invMassDPCut_noErr95->Fill(invariantMass);} 
				if ((dot) <-10.0){h_invMassDPCut_noErr100->Fill(invariantMass);} 
				if ((dot) <-10.5){h_invMassDPCut_noErr105->Fill(invariantMass);} 
				if ((dot) <-11.0){h_invMassDPCut_noErr110->Fill(invariantMass);} 
				if ((dot) <-11.5){h_invMassDPCut_noErr115->Fill(invariantMass);} 
				if ((dot) <-12.0){h_invMassDPCut_noErr120->Fill(invariantMass);} 
				if ((dot) <-12.5){h_invMassDPCut_noErr125->Fill(invariantMass);} 
				if ((dot) <-13.0){h_invMassDPCut_noErr130->Fill(invariantMass);} 
				if ((dot) <-13.5){h_invMassDPCut_noErr135->Fill(invariantMass);} 
				if ((dot) <-14.0){h_invMassDPCut_noErr140->Fill(invariantMass);} 
				if ((dot) <-14.5){h_invMassDPCut_noErr145->Fill(invariantMass);} 
				if ((dot) <-15.0){h_invMassDPCut_noErr150->Fill(invariantMass);} 
				if ((dot) <-15.5){h_invMassDPCut_noErr155->Fill(invariantMass);} 
				if ((dot) <-16.0){h_invMassDPCut_noErr160->Fill(invariantMass);} 
				if ((dot) <-16.5){h_invMassDPCut_noErr165->Fill(invariantMass);} 
				if ((dot) <-17.0){h_invMassDPCut_noErr170->Fill(invariantMass);} 
				if ((dot) <-17.5){h_invMassDPCut_noErr175->Fill(invariantMass);} 
				if ((dot) <-18.0){h_invMassDPCut_noErr180->Fill(invariantMass);} 
				if ((dot) <-18.5){h_invMassDPCut_noErr185->Fill(invariantMass);} 
				if ((dot) <-19.0){h_invMassDPCut_noErr190->Fill(invariantMass);} 
				if ((dot) <-19.5){h_invMassDPCut_noErr195->Fill(invariantMass);} 
				if ((dot) <-20.0){h_invMassDPCut_noErr200->Fill(invariantMass);} 
				if ((-dot) <-0.5){h_invMassDPCutLw_noErr5->Fill(invariantMass);}
				if ((-dot) <-1.0){h_invMassDPCutLw_noErr10->Fill(invariantMass);}
				if ((-dot) <-1.5){h_invMassDPCutLw_noErr15->Fill(invariantMass);}
				if ((-dot) <-2.0){h_invMassDPCutLw_noErr20->Fill(invariantMass);}
				if ((-dot) <-2.5){h_invMassDPCutLw_noErr25->Fill(invariantMass);}
				if ((-dot) <-3.0){h_invMassDPCutLw_noErr30->Fill(invariantMass);}
				if ((-dot) <-3.5){h_invMassDPCutLw_noErr35->Fill(invariantMass);}
				if ((-dot) <-4.0){h_invMassDPCutLw_noErr40->Fill(invariantMass);}
				if ((-dot) <-4.5){h_invMassDPCutLw_noErr45->Fill(invariantMass);}
				if ((-dot) <-5.0){h_invMassDPCutLw_noErr50->Fill(invariantMass);}
				if ((-dot) <-5.5){h_invMassDPCutLw_noErr55->Fill(invariantMass);}
				if ((-dot) <-6.0){h_invMassDPCutLw_noErr60->Fill(invariantMass);}
				if ((-dot) <-6.5){h_invMassDPCutLw_noErr65->Fill(invariantMass);}
				if ((-dot) <-7.0){h_invMassDPCutLw_noErr70->Fill(invariantMass);}
				if ((-dot) <-7.5){h_invMassDPCutLw_noErr75->Fill(invariantMass);}
				if ((-dot) <-8.0){h_invMassDPCutLw_noErr80->Fill(invariantMass);}
				if ((-dot) <-8.5){h_invMassDPCutLw_noErr85->Fill(invariantMass);}
				if ((-dot) <-9.0){h_invMassDPCutLw_noErr90->Fill(invariantMass);}
				if ((-dot) <-9.5){h_invMassDPCutLw_noErr95->Fill(invariantMass);}
				if ((-dot) <-10.0){h_invMassDPCutLw_noErr100->Fill(invariantMass);}
				if ((-dot) <-10.5){h_invMassDPCutLw_noErr105->Fill(invariantMass);}
				if ((-dot) <-11.0){h_invMassDPCutLw_noErr110->Fill(invariantMass);}
				if ((-dot) <-11.5){h_invMassDPCutLw_noErr115->Fill(invariantMass);}
				if ((-dot) <-12.0){h_invMassDPCutLw_noErr120->Fill(invariantMass);}
				if ((-dot) <-12.5){h_invMassDPCutLw_noErr125->Fill(invariantMass);}
				if ((-dot) <-13.0){h_invMassDPCutLw_noErr130->Fill(invariantMass);}
				if ((-dot) <-13.5){h_invMassDPCutLw_noErr135->Fill(invariantMass);}
				if ((-dot) <-14.0){h_invMassDPCutLw_noErr140->Fill(invariantMass);}
				if ((-dot) <-14.5){h_invMassDPCutLw_noErr145->Fill(invariantMass);}
				if ((-dot) <-15.0){h_invMassDPCutLw_noErr150->Fill(invariantMass);}
				if ((-dot) <-15.5){h_invMassDPCutLw_noErr155->Fill(invariantMass);}
				if ((-dot) <-16.0){h_invMassDPCutLw_noErr160->Fill(invariantMass);}
				if ((-dot) <-16.5){h_invMassDPCutLw_noErr165->Fill(invariantMass);}
				if ((-dot) <-17.0){h_invMassDPCutLw_noErr170->Fill(invariantMass);}
				if ((-dot) <-17.5){h_invMassDPCutLw_noErr175->Fill(invariantMass);}
				if ((-dot) <-18.0){h_invMassDPCutLw_noErr180->Fill(invariantMass);}
				if ((-dot) <-18.5){h_invMassDPCutLw_noErr185->Fill(invariantMass);}
				if ((-dot) <-19.0){h_invMassDPCutLw_noErr190->Fill(invariantMass);}
				if ((-dot) <-19.5){h_invMassDPCutLw_noErr195->Fill(invariantMass);}
				if ((-dot) <-20.0){h_invMassDPCutLw_noErr200->Fill(invariantMass);}
			  
			  h_dotP->Fill(dot);
			  h_dotPLw->Fill(dot);
			  h_dotP_err->Fill(dot/tdl_err);
			  h_dotPLw_err->Fill(-dot/tdl_err);
			  h_invMassLoose->Fill(invariantMass);
			   if ((conePt_var < 4 && cosAlpha > -0.95 && (theta < 0.2 )))
					
					{
					   
						cout<< tdl_err<<endl;
				     //without lifetime related cuts
						
						
						if(dot> dotMax){dotMax=dot;}
						if (dot< dotMin){dotMin=dot;}
						
					    
					     
				         h_invMass->Fill(invariantMass);
				         if ((dot/tdl_err) >3){h_invMassDotCutsInv->Fill(invariantMass);}
						 
						 h_invMass_lwCut_inv->Fill(invariantMass);
						 if (theta < 0.18){h_invMass_lwCut_inv1->Fill(invariantMass);}
						 if (theta < 0.16){h_invMass_lwCut_inv2->Fill(invariantMass);}
						 if (theta < 0.14){h_invMass_lwCut_inv3->Fill(invariantMass);}
						 if (theta < 0.12){h_invMass_lwCut_inv4->Fill(invariantMass);}
						 if (theta < 0.10){h_invMass_lwCut_inv5->Fill(invariantMass);}
						 if (theta < 0.08){h_invMass_lwCut_inv6->Fill(invariantMass);}
						 if (theta < 0.06){h_invMass_lwCut_inv7->Fill(invariantMass);}
						 if (theta < 0.04){h_invMass_lwCut_inv8->Fill(invariantMass);}
						 if (theta < 0.02){h_invMass_lwCut_inv9->Fill(invariantMass);}
						 
				         double lxy_err = tdl/(tdl_err);
				         if (lxy_err > 20)
				         {lxy_err = 19;}
				         h_lxy_err->Fill(lxy_err);
				         
				    //with lifetime related cuts
				         if (IPC && tdl/tdl_err > 5)
				         {
							 h_invMass_LC->Fill(invariantMass);
						 }
						 
				    
				 }
				 if ((conePt_var < 4 && cosAlpha > -0.95 && (theta >3.1514- 0.2 )))
					
					{
				
					   double invariantMass;
					   invariantMass = invMass(itTrack1->px(), itTrack1->py(), itTrack1->pz(),itTrack2->px(), itTrack2->py(), itTrack2->pz());
					   h_invMass_lwCut->Fill(invariantMass);
					    if (pt > 250){h_invMassPt250->Fill(invariantMass);}
			           if (pt > 260){h_invMassPt260->Fill(invariantMass);}
					   if (pt > 270){h_invMassPt270->Fill(invariantMass);}
					   if (pt > 280){h_invMassPt280->Fill(invariantMass);}
				       if (pt > 290){h_invMassPt290->Fill(invariantMass);}
					   if (pt > 300){h_invMassPt300->Fill(invariantMass);}
					   if (pt > 310){h_invMassPt310->Fill(invariantMass);}
					   if (pt > 320){h_invMassPt320->Fill(invariantMass);}
					   if (pt > 330){h_invMassPt330->Fill(invariantMass);}
					   if (pt > 340){h_invMassPt340->Fill(invariantMass);}
					   if (pt > 350){h_invMassPt350->Fill(invariantMass);}
					   if ((dot/tdl_err) <-3){h_invMassDotCuts->Fill(invariantMass);}
					   if (theta > 3.1514 -0.18){h_invMass_lwCut1->Fill(invariantMass);}
					   if (theta > 3.1514 -0.16){h_invMass_lwCut2->Fill(invariantMass);}
					   if (theta > 3.1514 -0.14){h_invMass_lwCut3->Fill(invariantMass);}
					   if (theta > 3.1514 -0.12){h_invMass_lwCut4->Fill(invariantMass);}
					   if (theta > 3.1514 -0.10){h_invMass_lwCut5->Fill(invariantMass);}
					   if (theta > 3.1514 -0.08){h_invMass_lwCut6->Fill(invariantMass);}
					   if (theta > 3.1514 -0.06){h_invMass_lwCut7->Fill(invariantMass);}
					   if (theta > 3.1514 -0.04){h_invMass_lwCut8->Fill(invariantMass);}
					   if (theta > 3.1514 -0.02){h_invMass_lwCut9->Fill(invariantMass);}
					  
		    
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
MuonAnalyzer::beginJob()
{TH1::AddDirectory(true);
 vuelta = 0;
 const char* of = outFile_.c_str();
 mfile = new TFile(of, "recreate");
 

 h_invMassLoose = new TH1F ("InvMassLoose", "Lepton Pair Invariant Mass with no theta cut", 100, 0 , 600);
 
 h_invMass = new TH1F ("InvMass", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMassLoose = new TH1F ("InvMassLoose", "Lepton Pair Invariant Mass with no theta cut", 100, 0 , 600);
 h_invMassPt250 = new TH1F ("InvMassPt250", "Lepton Pair Invariant Mass (Pt >250, lw cut)", 100, 0 , 600);
 h_invMassPt260 = new TH1F ("InvMassPt260", "Lepton Pair Invariant Mass (Pt >260, lw cut)", 100, 0 , 600);
 h_invMassPt270 = new TH1F ("InvMassPt270", "Lepton Pair Invariant Mass (Pt >270, lw cut)", 100, 0 , 600);
 h_invMassPt280 = new TH1F ("InvMassPt280", "Lepton Pair Invariant Mass (Pt >280, lw cut)", 100, 0 , 600);
 h_invMassPt290 = new TH1F ("InvMassPt290", "Lepton Pair Invariant Mass (Pt >290, lw cut)", 100, 0 , 600);
 h_invMassPt300 = new TH1F ("InvMassPt300", "Lepton Pair Invariant Mass (Pt >300 lw cut)", 100, 0 , 600);
 h_invMassPt310 = new TH1F ("InvMassPt310", "Lepton Pair Invariant Mass (Pt >310 lw cut)", 100, 0 , 600);
 h_invMassPt320 = new TH1F ("InvMassPt320", "Lepton Pair Invariant Mass (Pt >320 lw cut)", 100, 0 , 600);
 h_invMassPt330 = new TH1F ("InvMassPt330", "Lepton Pair Invariant Mass (Pt >330 lw cut)", 100, 0 , 600);
 h_invMassPt340 = new TH1F ("InvMassPt340", "Lepton Pair Invariant Mass (Pt >340 lw cut)", 100, 0 , 600);
 h_invMassPt350 = new TH1F ("InvMassPt350", "Lepton Pair Invariant Mass (Pt >350 lw cut)", 100, 0 , 600);
 
 h_invMassPt250Inv = new TH1F ("InvMassPt250Inv", "Lepton Pair Invariant Mass (Pt >250)", 100, 0 , 600);
 h_invMassPt260Inv = new TH1F ("InvMassPt260Inv", "Lepton Pair Invariant Mass (Pt >260)", 100, 0 , 600);
 h_invMassPt270Inv = new TH1F ("InvMassPt270Inv", "Lepton Pair Invariant Mass (Pt >270)", 100, 0 , 600);
 h_invMassPt280Inv = new TH1F ("InvMassPt280Inv", "Lepton Pair Invariant Mass (Pt >280)", 100, 0 , 600);
 h_invMassPt290Inv = new TH1F ("InvMassPt290Inv", "Lepton Pair Invariant Mass (Pt >290)", 100, 0 , 600);
 h_invMassPt300Inv = new TH1F ("InvMassPt300Inv", "Lepton Pair Invariant Mass (Pt >300)", 100, 0 , 600);
 h_invMassPt310Inv = new TH1F ("InvMassPt310Inv", "Lepton Pair Invariant Mass (Pt >310)", 100, 0 , 600);
 h_invMassPt320Inv = new TH1F ("InvMassPt320Inv", "Lepton Pair Invariant Mass (Pt >320)", 100, 0 , 600);
 h_invMassPt330Inv = new TH1F ("InvMassPt330Inv", "Lepton Pair Invariant Mass (Pt >330)", 100, 0 , 600);
 h_invMassPt340Inv = new TH1F ("InvMassPt340Inv", "Lepton Pair Invariant Mass (Pt >340)", 100, 0 , 600);
 h_invMassPt350Inv = new TH1F ("InvMassPt350Inv", "Lepton Pair Invariant Mass (Pt >350)", 100, 0 , 600);
 h_invMassDotCuts = new TH1F ("InvMassDotCuts", "Lepton Pair Invariant Mass (dot product cut)", 100, 0 , 600);
 h_invMassDotCutsInv = new TH1F ("InvMassDotCutsInv", "Lepton Pair Invariant Mass  (inverted dot product cut)", 100, 0 , 600);
 h_pt = new TH1F ("pt", "Lepton Pair Transverse momentum", 100, 0 , 450);
 h_ptP = new TH1F ("ptP", "Lepton Pair Transverse momentum dot > 1.5", 100, 0 , 450);
 h_ptM = new TH1F ("ptM", "Lepton Pair Transverse momentum dot < -1.5", 100, 0 , 450);
 h_invMass_lwCut = new TH1F ("InvMass_lwCut", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut1 = new TH1F ("InvMass_lwCut1", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut2 = new TH1F ("InvMass_lwCut2", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut3 = new TH1F ("InvMass_lwCut3", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut4 = new TH1F ("InvMass_lwCut4", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut5 = new TH1F ("InvMass_lwCut5", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut6 = new TH1F ("InvMass_lwCut6", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut7 = new TH1F ("InvMass_lwCut7", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut8 = new TH1F ("InvMass_lwCut8", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut9 = new TH1F ("InvMass_lwCut9", "Lepton Pair Invariant Mass", 100, 0 , 600);


 h_invMass_lwCut_inv = new TH1F ("InvMass_lwCut_inv", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv1 = new TH1F ("InvMass_lwCut_inv1", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv2 = new TH1F ("InvMass_lwCut_inv2", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv3 = new TH1F ("InvMass_lwCut_inv3", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv4 = new TH1F ("InvMass_lwCut_inv4", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv5 = new TH1F ("InvMass_lwCut_inv5", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv6 = new TH1F ("InvMass_lwCut_inv6", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv7 = new TH1F ("InvMass_lwCut_inv7", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv8 = new TH1F ("InvMass_lwCut_inv8", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_lwCut_inv9 = new TH1F ("InvMass_lwCut_inv9", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMass_LC = new TH1F ("InvMass_LC", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_lxy_err = new TH1F ("Lxy_err", "Transeverse decay length",20,0,20); 	  
 h_dotP = new TH1F ("dotP", "vertex-momentum dot product",50,-30,30); 	  
 h_dotP_err = new TH1F ("dotP_err", "vertex-momentum dot product/error",50,-600,600); 	  
 h_dotPLw = new TH1F ("dotPLw", "vertex-momentum dot product (lw)",50,-30,30); 	  
 h_dotPLw_err = new TH1F ("dotPLw_err", "vertex-momentum dot product /error (lw)",50,-600,600); 	  
 h_theta = new TH1F ("theta", "primary-secondary vertex displacement and lepton total momentum angle",200,0,4); 	  
  
 h_thetaCut250 = new TH1F ("thetaCut250", "primary-secondary vertex displacement and lepton total momentum angle with pt > 250",200,0,4); 	  
 h_thetaCut260 = new TH1F ("thetaCut260", "primary-secondary vertex displacement and lepton total momentum angle with pt > 260",200,0,4); 	  
 h_thetaCut270 = new TH1F ("thetaCut270", "primary-secondary vertex displacement and lepton total momentum angle with pt > 270",200,0,4); 	  
 h_thetaCut280 = new TH1F ("thetaCut280", "primary-secondary vertex displacement and lepton total momentum angle with pt > 280",200,0,4); 	  
 h_thetaCut290 = new TH1F ("thetaCut290", "primary-secondary vertex displacement and lepton total momentum angle with pt > 290",200,0,4); 	  
 h_thetaCut300 = new TH1F ("thetaCut300", "primary-secondary vertex displacement and lepton total momentum angle with pt > 300",200,0,4); 	  
 h_thetaCut310 = new TH1F ("thetaCut310", "primary-secondary vertex displacement and lepton total momentum angle with pt > 310",200,0,4); 	  
 h_thetaCut320 = new TH1F ("thetaCut320", "primary-secondary vertex displacement and lepton total momentum angle with pt > 320",200,0,4); 	  
 h_thetaCut330 = new TH1F ("thetaCut330", "primary-secondary vertex displacement and lepton total momentum angle with pt > 330",200,0,4); 	  
 h_thetaCut340 = new TH1F ("thetaCut340", "primary-secondary vertex displacement and lepton total momentum angle with pt > 340",200,0,4); 	  
 h_thetaCut350 = new TH1F ("thetaCut350", "primary-secondary vertex displacement and lepton total momentum angle with pt > 350",200,0,4); 	  
 h_thetaLw = new TH1F ("thetaLw", "primary-secondary vertex displacement and lepton total momentum angle for lw particles",200,0,4); 
 	  
 h_thetaLwCut250 = new TH1F ("thetaLwCut250", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 250",200,0,4); 	  
 h_thetaLwCut260 = new TH1F ("thetaLwCut260", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 260",200,0,4); 	  
 h_thetaLwCut270 = new TH1F ("thetaLwCut270", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 270",200,0,4); 	  
 h_thetaLwCut280 = new TH1F ("thetaLwCut280", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 280",200,0,4); 	  
 h_thetaLwCut290 = new TH1F ("thetaLwCut290", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 290",200,0,4); 	  
 h_thetaLwCut300 = new TH1F ("thetaLwCut300", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 300",200,0,4); 	  
 h_thetaLwCut310 = new TH1F ("thetaLwCut310", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 310",200,0,4); 	  
 h_thetaLwCut320 = new TH1F ("thetaLwCut320", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 320",200,0,4); 	  
 h_thetaLwCut330 = new TH1F ("thetaLwCut330", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 330",200,0,4); 	  
 h_thetaLwCut340 = new TH1F ("thetaLwCut340", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 340",200,0,4); 	  
 h_thetaLwCut350 = new TH1F ("thetaLwCut350", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 350",200,0,4); 	    
 
 
 
 
 h_invMassDPCut10 = new TH1F ("InvMassDPCut10", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut20 = new TH1F ("InvMassDPCut20", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut30 = new TH1F ("InvMassDPCut30", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut40 = new TH1F ("InvMassDPCut40", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut50 = new TH1F ("InvMassDPCut50", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut60 = new TH1F ("InvMassDPCut60", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut70 = new TH1F ("InvMassDPCut70", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut80 = new TH1F ("InvMassDPCut80", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut90 = new TH1F ("InvMassDPCut90", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut100 = new TH1F ("InvMassDPCut100", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut110 = new TH1F ("InvMassDPCut110", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut120 = new TH1F ("InvMassDPCut120", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut130 = new TH1F ("InvMassDPCut130", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut140 = new TH1F ("InvMassDPCut140", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut150 = new TH1F ("InvMassDPCut150", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut160 = new TH1F ("InvMassDPCut160", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut170 = new TH1F ("InvMassDPCut170", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut180 = new TH1F ("InvMassDPCut180", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut190 = new TH1F ("InvMassDPCut190", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut200 = new TH1F ("InvMassDPCut200", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut210 = new TH1F ("InvMassDPCut210", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut220 = new TH1F ("InvMassDPCut220", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut230 = new TH1F ("InvMassDPCut230", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut240 = new TH1F ("InvMassDPCut240", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut250 = new TH1F ("InvMassDPCut250", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut260 = new TH1F ("InvMassDPCut260", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut270 = new TH1F ("InvMassDPCut270", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut280 = new TH1F ("InvMassDPCut280", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut290 = new TH1F ("InvMassDPCut290", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut300 = new TH1F ("InvMassDPCut300", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut310 = new TH1F ("InvMassDPCut310", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut320 = new TH1F ("InvMassDPCut320", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut330 = new TH1F ("InvMassDPCut330", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut340 = new TH1F ("InvMassDPCut340", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut350 = new TH1F ("InvMassDPCut350", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut360 = new TH1F ("InvMassDPCut360", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut370 = new TH1F ("InvMassDPCut370", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut380 = new TH1F ("InvMassDPCut380", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut390 = new TH1F ("InvMassDPCut390", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut400 = new TH1F ("InvMassDPCut400", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw10 = new TH1F ("InvMassDPCutLw10", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw20 = new TH1F ("InvMassDPCutLw20", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw30 = new TH1F ("InvMassDPCutLw30", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw40 = new TH1F ("InvMassDPCutLw40", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw50 = new TH1F ("InvMassDPCutLw50", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw60 = new TH1F ("InvMassDPCutLw60", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw70 = new TH1F ("InvMassDPCutLw70", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw80 = new TH1F ("InvMassDPCutLw80", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw90 = new TH1F ("InvMassDPCutLw90", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw100 = new TH1F ("InvMassDPCutLw100", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw110 = new TH1F ("InvMassDPCutLw110", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw120 = new TH1F ("InvMassDPCutLw120", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw130 = new TH1F ("InvMassDPCutLw130", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw140 = new TH1F ("InvMassDPCutLw140", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw150 = new TH1F ("InvMassDPCutLw150", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw160 = new TH1F ("InvMassDPCutLw160", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw170 = new TH1F ("InvMassDPCutLw170", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw180 = new TH1F ("InvMassDPCutLw180", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw190 = new TH1F ("InvMassDPCutLw190", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw200 = new TH1F ("InvMassDPCutLw200", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw210 = new TH1F ("InvMassDPCutLw210", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw220 = new TH1F ("InvMassDPCutLw220", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw230 = new TH1F ("InvMassDPCutLw230", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw240 = new TH1F ("InvMassDPCutLw240", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw250 = new TH1F ("InvMassDPCutLw250", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw260 = new TH1F ("InvMassDPCutLw260", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw270 = new TH1F ("InvMassDPCutLw270", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw280 = new TH1F ("InvMassDPCutLw280", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw290 = new TH1F ("InvMassDPCutLw290", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw300 = new TH1F ("InvMassDPCutLw300", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw310 = new TH1F ("InvMassDPCutLw310", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw320 = new TH1F ("InvMassDPCutLw320", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw330 = new TH1F ("InvMassDPCutLw330", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw340 = new TH1F ("InvMassDPCutLw340", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw350 = new TH1F ("InvMassDPCutLw350", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw360 = new TH1F ("InvMassDPCutLw360", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw370 = new TH1F ("InvMassDPCutLw370", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw380 = new TH1F ("InvMassDPCutLw380", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw390 = new TH1F ("InvMassDPCutLw390", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw400 = new TH1F ("InvMassDPCutLw400", "Lepton Pair Invariant Mass", 100, 0 , 600);


h_invMassDPCut_noErr5 = new TH1F ("InvMassDPCut_noErr5", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr10 = new TH1F ("InvMassDPCut_noErr10", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr15 = new TH1F ("InvMassDPCut_noErr15", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr20 = new TH1F ("InvMassDPCut_noErr20", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr25 = new TH1F ("InvMassDPCut_noErr25", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr30 = new TH1F ("InvMassDPCut_noErr30", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr35 = new TH1F ("InvMassDPCut_noErr35", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr40 = new TH1F ("InvMassDPCut_noErr40", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr45 = new TH1F ("InvMassDPCut_noErr45", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr50 = new TH1F ("InvMassDPCut_noErr50", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr55 = new TH1F ("InvMassDPCut_noErr55", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr60 = new TH1F ("InvMassDPCut_noErr60", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr65 = new TH1F ("InvMassDPCut_noErr65", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr70 = new TH1F ("InvMassDPCut_noErr70", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr75 = new TH1F ("InvMassDPCut_noErr75", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr80 = new TH1F ("InvMassDPCut_noErr80", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr85 = new TH1F ("InvMassDPCut_noErr85", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr90 = new TH1F ("InvMassDPCut_noErr90", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr95 = new TH1F ("InvMassDPCut_noErr95", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr100 = new TH1F ("InvMassDPCut_noErr100", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr105 = new TH1F ("InvMassDPCut_noErr105", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr110 = new TH1F ("InvMassDPCut_noErr110", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr115 = new TH1F ("InvMassDPCut_noErr115", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr120 = new TH1F ("InvMassDPCut_noErr120", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr125 = new TH1F ("InvMassDPCut_noErr125", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr130 = new TH1F ("InvMassDPCut_noErr130", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr135 = new TH1F ("InvMassDPCut_noErr135", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr140 = new TH1F ("InvMassDPCut_noErr140", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr145 = new TH1F ("InvMassDPCut_noErr145", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr150 = new TH1F ("InvMassDPCut_noErr150", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr155 = new TH1F ("InvMassDPCut_noErr155", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr160 = new TH1F ("InvMassDPCut_noErr160", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr165 = new TH1F ("InvMassDPCut_noErr165", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr170 = new TH1F ("InvMassDPCut_noErr170", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr175 = new TH1F ("InvMassDPCut_noErr175", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr180 = new TH1F ("InvMassDPCut_noErr180", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr185 = new TH1F ("InvMassDPCut_noErr185", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr190 = new TH1F ("InvMassDPCut_noErr190", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr195 = new TH1F ("InvMassDPCut_noErr195", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCut_noErr200 = new TH1F ("InvMassDPCut_noErr200", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr5 = new TH1F ("InvMassDPCutLw_noErr5", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr10 = new TH1F ("InvMassDPCutLw_noErr10", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr15 = new TH1F ("InvMassDPCutLw_noErr15", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr20 = new TH1F ("InvMassDPCutLw_noErr20", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr25 = new TH1F ("InvMassDPCutLw_noErr25", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr30 = new TH1F ("InvMassDPCutLw_noErr30", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr35 = new TH1F ("InvMassDPCutLw_noErr35", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr40 = new TH1F ("InvMassDPCutLw_noErr40", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr45 = new TH1F ("InvMassDPCutLw_noErr45", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr50 = new TH1F ("InvMassDPCutLw_noErr50", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr55 = new TH1F ("InvMassDPCutLw_noErr55", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr60 = new TH1F ("InvMassDPCutLw_noErr60", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr65 = new TH1F ("InvMassDPCutLw_noErr65", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr70 = new TH1F ("InvMassDPCutLw_noErr70", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr75 = new TH1F ("InvMassDPCutLw_noErr75", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr80 = new TH1F ("InvMassDPCutLw_noErr80", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr85 = new TH1F ("InvMassDPCutLw_noErr85", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr90 = new TH1F ("InvMassDPCutLw_noErr90", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr95 = new TH1F ("InvMassDPCutLw_noErr95", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr100 = new TH1F ("InvMassDPCutLw_noErr100", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr105 = new TH1F ("InvMassDPCutLw_noErr105", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr110 = new TH1F ("InvMassDPCutLw_noErr110", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr115 = new TH1F ("InvMassDPCutLw_noErr115", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr120 = new TH1F ("InvMassDPCutLw_noErr120", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr125 = new TH1F ("InvMassDPCutLw_noErr125", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr130 = new TH1F ("InvMassDPCutLw_noErr130", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr135 = new TH1F ("InvMassDPCutLw_noErr135", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr140 = new TH1F ("InvMassDPCutLw_noErr140", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr145 = new TH1F ("InvMassDPCutLw_noErr145", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr150 = new TH1F ("InvMassDPCutLw_noErr150", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr155 = new TH1F ("InvMassDPCutLw_noErr155", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr160 = new TH1F ("InvMassDPCutLw_noErr160", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr165 = new TH1F ("InvMassDPCutLw_noErr165", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr170 = new TH1F ("InvMassDPCutLw_noErr170", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr175 = new TH1F ("InvMassDPCutLw_noErr175", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr180 = new TH1F ("InvMassDPCutLw_noErr180", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr185 = new TH1F ("InvMassDPCutLw_noErr185", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr190 = new TH1F ("InvMassDPCutLw_noErr190", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr195 = new TH1F ("InvMassDPCutLw_noErr195", "Lepton Pair Invariant Mass", 100, 0 , 600);
h_invMassDPCutLw_noErr200 = new TH1F ("InvMassDPCutLw_noErr200", "Lepton Pair Invariant Mass", 100, 0 , 600);
 
 nEvents = new TH1F ("nEvents", "Number of Events", 5, -5,5);
		
		
}




           


          


// ------------ method called once each job just after ending the event loop  ------------
void 
MuonAnalyzer::endJob() {
using namespace std;
//mtree->Write();
//std::cout<<"num traks "<<Ntracks<<" num vertTraks "<<NvertTracks<<std::endl;
mfile->Write();
mfile->Close();

cout<<"dot max "<<dotMax<<endl;
cout<<"dot min "<<dotMin<<endl;
}




bool
MuonAnalyzer::cmsStandardCuts(const edm::Event& iEvent, const edm::EventSetup& iSetup)
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
MuonAnalyzer::matchingCuts( bool purity, double pt, int hits, int hits3D, double eta, double dxy, double dxyError)
{
	bool ret = false;
	
	
		
	  if(purity && pt > 33 && hits >= 6   && eta < 2  && hits3D >1)
	  if(true)
	  
	  {
		  ret = true;

	  }	
	 
	  

	
	return ret;
}
double 
MuonAnalyzer::deltaR(double obj1Phi, double obj1Eta, double obj2Phi, double obj2Eta)
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
MuonAnalyzer::conePt(int forbiddenIndex1, int forbiddenIndex2, double eta, double phi, int numTracks,const edm::Event& iEvent, const edm::EventSetup& iSetup )
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
MuonAnalyzer::mCos(double phi1, double eta1, double phi2, double eta2 )
{double cosAlpha = cos(eta1)*cos(phi1)*cos(eta2)*cos(phi2) + cos(eta1)*sin(phi1)*cos(eta2)*sin(phi2) + sin(eta1)*cos(eta2);
	
	return cosAlpha;
}
double 
MuonAnalyzer::mTheta(double ax, double ay, double bx, double by)
{
	double cosAlpha = ax*bx + ay*by;
	double theta;
	cosAlpha = cosAlpha/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by));
	//std::cout<<"cosAlpha: "<<cosAlpha<<std::endl;
	theta  = acos(cosAlpha);
	if (theta > 3.1514)
	{
		theta =  2*3.1514-theta;
	}
	return theta;
}
double 
MuonAnalyzer::invMass(double px1, double py1, double pz1, double px2 , double py2,  double pz2)
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
double
MuonAnalyzer::dotProduct(double x1, double y1 , double x2, double y2)
{
	double ret;
	ret = x1*x2+y1*y2;
	return ret;
}
bool
MuonAnalyzer::impactParameterCut(reco::TrackCollection::const_iterator it1, reco::TrackCollection::const_iterator it2, reco::BeamSpot beamSpot)
{    
	double dxy1, dxy1Err, dxy2, dxy2Err, sig1, sig2;
	bool ret = false;
	dxy1 = it1->dxy(beamSpot);
	dxy2 = it2->dxy(beamSpot);
	dxy1Err = it1->dxyError();
	dxy2Err = it2->dxyError();
	
	sig1 = dxy1/dxy1Err;
	sig2 = dxy2/dxy2Err;
	
	if (sig1 > 2 && sig2 > 2)
	{
		ret = true;
	}
	
	
	return ret;
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
