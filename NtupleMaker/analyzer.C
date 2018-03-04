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
   
   file = new TFile("hists.root", "recreate");
   h_invMass = new TH1F ("InvMass", "Lepton Pair Invariant Mass", 100, 0 , 600);
   //matchedTrack[ = {0};
   TH1::AddDirectory(true);
   vuelta = 0;
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
   
bool standardCuts = cmsStandardCuts(Ev_Branch_numTrack, vertexTrack_vx, vertexTrack_vy, vertexTrack_vz);
reset();

//cout<<++vuelta<<endl;


 

if (standardCuts || true)   // quitar true
{
	for (int i = 0 ; i< Ev_Branch_numTrack; i++)
	{
		for (int j = 0; j< Ev_Branch_numTrigObj; j++)
		{
		   if (deltaR(track_phi[i], track_eta[i], trigObj_phi[j], trigObj_eta[j])< 0.1 && deltaP(track_px[i], track_py[i],track_pz[i], trigObj_px[j], trigObj_py[j], trigObj_pz[j]) < 3)
		   {
			   matchedTrack[i] = 1;
			   
			   vuelta ++;
		   }
		  
		}
	}
	
	// the following section compares vertex of opositly chareged trigger-matched leptons in order to find lepton pairs product of the same decay.
	
	for ( int i = 0;  i < Ev_Branch_numTrack; i++)
	{
		if ( matchedTrack[i] ==1 && track_charge[i] == 1)
		{  
			for (int j =0; j< Ev_Branch_numTrack; j++)
			if ( matchedTrack[j] == 1 && track_charge[j] == -1)
			{  
				if ( deltaV(track_vx[i], track_vy[i], track_vz[i],track_vx[j], track_vy[j], track_vz[j]) < 0.1 && track_pt[i] > 41)
				{
					double invariantMass;
					 invariantMass = invMass(track_px[i], track_py[i], track_pz[i], track_px[j], track_py[j], track_pz[j]);
					 cout<<invariantMass<<endl;
					 h_invMass->Fill(invariantMass);
				}
			}
		}
	}
	
	
}


   return kTRUE;
}



// resets arrays and variables to Null/0

void analyzer::reset()
{
	for (int i = 0; i< Ev_Branch_numTrack; i++)
	{
		matchedTrack[i] = 0;
	}
	
}

// calculates rest mass of a pair of  leptons
double analyzer::invMass(double px1, double py1, double pz1, double px2 , double py2,  double pz2)
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
double deltaP(double px1, double py1, double pz1, double px2, double py2, double pz2)
{
	/*double dpx = px1 -px2;
	double dpy = py1 -py2;
	double dpz = pz1 -pz2;*/
	double ptotT = sqrt(px1*px1 + py1*py1 +pz1*pz1);
	double ptotO = sqrt(px2*px2 + py2*py2 +pz2*pz2);
	
    //double dp = sqrt(dpx*dpx + dpy*dpy +dpz*dpz);
    double dp = abs(ptotT - ptotO);
    return dp; 
    
}

double analyzer::deltaV(double vx1, double vy1, double vz1, double vx2, double vy2, double vz2)
{
   double dx = vx1-vx2;
   double dy = vy1-vy2;
   double dz = vz1 - vz2;
   
   double dv = sqrt(dx*dx +dy*dy +dz*dz);
   return dv;	
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
	cout<<vuelta<<endl;
	file->Write();
	file->Close();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
