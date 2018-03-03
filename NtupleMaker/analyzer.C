#define analyzer_cxx
// The class definition in analyzer.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("analyzer.C")
// Root > T->Process("analyzer.C","some options")
// Root > T->Process("analyzer.C+")
//

#include "analyzer.h"
#include <TH2.h>
#include <TStyle.h>


void analyzer::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void analyzer::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t analyzer::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either analyzer::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
 fChain->GetTree()->GetEntry(entry);
std::cout<<" "<<endl;   
bool standardCuts = cmsStandardCuts(Ev_Branch_numTrack, Ev_Branch_vertexTrack_vx, Ev_Branch_vertexTrack_vy, Ev_Branch_vertexTrack_vz);


int matchedTrack[numTrack] = {0};

if (standardCuts || true)   // quitar true
{
	for (int i = 0 ; i< numTrack; i ++)
	{
		for (int j = 0; j< numTrigObj; j++)
		{
		   if (deltaR(track_phi[i], track_eta[i], trigObj_phi[j], trigObj_eta[j])< 0.1 && abs(track_pt[i] -trigObj_pt[j]) < 3)
		   {
			   matchedTrack[i] = 1;
		   }
		}
	}
	
	// the following section compares origin of opositly chareged trigger matched leptons to find lepton pairs product of the same decay.
	
	for ( int i = 0; int i < numTrack; i++)
	{
		if ( matchedTrack[i] ==1 && track_charge[i] == 1)
		{
			for (int j =0; j< numTrack; j++)
			if ( matchedTrack[j] == 1 && track_charge[j] == -1)
			{
				if ( deltaR(track_phi[i], track_eta[i], track_phi[j], track_eta[j]) < 0.1)
				{
					double invariantMass;
					 invariantMass = invMass(track_px[i], track_py[i], track_pz[i], track_px[j], track_py[j], track_pz[j]);
				}
			}
		}
	}
	
	
}


   return kTRUE;
}

// calculates rest mass of a pair of  leptons
double analyzer::invMass(double px1, double py1, double pz1, double px2 , double py2,  double pz2)
{
  double E1 =  sqrt(px1*px1 + py1*py1 + pz1*pz1);  // asummes rest mass energy to be negligible
  double E2 =  sqrt(px2*px2 + py2*py2 + pz2*pz2);
  
  double E = E1+E2;
  double px = px1 + px2;
  double py = py1 + py2;
  double py = pz1 + pz2;
  double mass = sqrt(E*E - px*px - py*py - pz*pz);
  
  return mass;
  
  

	
}

double analyzer::deltaR(double obj1Phi, double obj1Eta, double obj2Phi, double obj2Eta)
{
	double dPhi = obj1Phi - obj2Phi;
	double dEta = obj1Eta - obj2Eta;
	double dR = sqrt(dPhi*dPhi + dEta*dEta);
	return dR;
}


bool analyzer::cmsStandardCuts(Int_t numTracks, Double_t vx[], Double_t vy[], Double_t vz[] )
{
	bool ret =  false;
	int distCount = 0;
	 
		for (int i =0; i< numTracks; i ++) 
		{
			
			double vxy = sqrt(vx[i]*vx[i] + vy[i]*vy[i]);
			if (vxy< 24 && vz[i] < 2)
			{
				distCount ++;
			}
		}
	if (numTracks > 4 && distCount > 4)
	{
		ret  = true;
	}
	return ret;

}

void analyzer::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void analyzer::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
