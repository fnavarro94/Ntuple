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
      TH1F * h_invMassPt50;
      TH1F * h_invMassPt60;
      TH1F * h_invMassPt70;
      TH1F * h_invMassPt80;
      TH1F * h_invMassPt90;
      TH1F * h_invMassPt250;
      TH1F * h_invMassPt50Inv;
      TH1F * h_invMassPt60Inv;
      TH1F * h_invMassPt70Inv;
      TH1F * h_invMassPt80Inv;
      TH1F * h_invMassPt90Inv;
      TH1F * h_invMassPt250Inv;
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
      TH1F * h_theta;
      TH1F * h_thetaLw;
      TH1F * h_thetaLwCut;
      TH1F * h_thetaCut;
      
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
			  if (pt > 50){h_invMassPt50Inv->Fill(invariantMass);}
			  if (pt > 60){h_invMassPt60Inv->Fill(invariantMass);}
			  if (pt > 70){h_invMassPt70Inv->Fill(invariantMass);}
			  if (pt > 80){h_invMassPt80Inv->Fill(invariantMass);}
			  if (pt > 90){h_invMassPt90Inv->Fill(invariantMass);}
			  if (pt > 250){h_invMassPt250Inv->Fill(invariantMass); h_thetaCut->Fill(theta); h_thetaLwCut->Fill(3.1514-theta);}
			  h_dotP->Fill(dot/tdl_err);
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
					   if (pt > 50){h_invMassPt50->Fill(invariantMass);}
			           if (pt > 60){h_invMassPt60->Fill(invariantMass);}
					   if (pt > 70){h_invMassPt70->Fill(invariantMass);}
					   if (pt > 80){h_invMassPt80->Fill(invariantMass);}
				       if (pt > 90){h_invMassPt90->Fill(invariantMass);}
					   if (pt > 100){h_invMassPt250->Fill(invariantMass);}
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
SimuMuonAnalyzer::beginJob()
{TH1::AddDirectory(true);
 vuelta = 0;
 const char* of = outFile_.c_str();
 mfile = new TFile(of, "recreate");
 
 h_invMass = new TH1F ("InvMass", "Lepton Pair Invariant Mass", 100, 0 , 600);
 h_invMassLoose = new TH1F ("InvMassLoose", "Lepton Pair Invariant Mass with no theta cut", 100, 0 , 600);
 h_invMassPt50 = new TH1F ("InvMassPt50", "Lepton Pair Invariant Mass (Pt >50, lw cut)", 100, 0 , 600);
 h_invMassPt60 = new TH1F ("InvMassPt60", "Lepton Pair Invariant Mass (Pt >60, lw cut)", 100, 0 , 600);
 h_invMassPt70 = new TH1F ("InvMassPt70", "Lepton Pair Invariant Mass (Pt >70, lw cut)", 100, 0 , 600);
 h_invMassPt80 = new TH1F ("InvMassPt80", "Lepton Pair Invariant Mass (Pt >80, lw cut)", 100, 0 , 600);
 h_invMassPt90 = new TH1F ("InvMassPt90", "Lepton Pair Invariant Mass (Pt >90, lw cut)", 100, 0 , 600);
 h_invMassPt250 = new TH1F ("InvMassPt250", "Lepton Pair Invariant Mass (Pt >100 lw cut)", 100, 0 , 600);
 h_invMassPt50Inv = new TH1F ("InvMassPt50Inv", "Lepton Pair Invariant Mass (Pt >50)", 100, 0 , 600);
 h_invMassPt60Inv = new TH1F ("InvMassPt60Inv", "Lepton Pair Invariant Mass (Pt >60)", 100, 0 , 600);
 h_invMassPt70Inv = new TH1F ("InvMassPt70Inv", "Lepton Pair Invariant Mass (Pt >70)", 100, 0 , 600);
 h_invMassPt80Inv = new TH1F ("InvMassPt80Inv", "Lepton Pair Invariant Mass (Pt >80)", 100, 0 , 600);
 h_invMassPt90Inv = new TH1F ("InvMassPt90Inv", "Lepton Pair Invariant Mass (Pt >90)", 100, 0 , 600);
 h_invMassPt250Inv = new TH1F ("InvMassPt250Inv", "Lepton Pair Invariant Mass (Pt >100)", 100, 0 , 600);
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
 h_dotP = new TH1F ("dotP", "vertex-momentum dot product",50,-300,300); 	  
 h_theta = new TH1F ("theta", "primary-secondary vertex displacement and lepton total momentum angle",200,0,4); 	  
 h_thetaCut = new TH1F ("thetaCut", "primary-secondary vertex displacement and lepton total momentum angle with pt > 250",200,0,4); 	  
 h_thetaLw = new TH1F ("thetaLw", "primary-secondary vertex displacement and lepton total momentum angle for lw particles",200,0,4); 	  
 h_thetaLwCut = new TH1F ("thetaLwCut", "primary-secondary vertex displacement and lepton total momentum angle for lw particles with pt > 250",200,0,4); 	  
 nEvents = new TH1F ("nEvents", "Number of Events", 5, -5,5);
		
		
}




           


          


// ------------ method called once each job just after ending the event loop  ------------
void 
SimuMuonAnalyzer::endJob() {
using namespace std;
//mtree->Write();
//std::cout<<"num traks "<<Ntracks<<" num vertTraks "<<NvertTracks<<std::endl;
mfile->Write();
mfile->Close();

cout<<"dot max "<<dotMax<<endl;
cout<<"dot min "<<dotMin<<endl;
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
SimuMuonAnalyzer::matchingCuts( bool purity, double pt, int hits, int hits3D, double eta, double dxy, double dxyError)
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
double
SimuMuonAnalyzer::dotProduct(double x1, double y1 , double x2, double y2)
{
	double ret;
	ret = x1*x2+y1*y2;
	return ret;
}
bool
SimuMuonAnalyzer::impactParameterCut(reco::TrackCollection::const_iterator it1, reco::TrackCollection::const_iterator it2, reco::BeamSpot beamSpot)
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
