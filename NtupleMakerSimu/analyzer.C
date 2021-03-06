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
   
   file = new TFile("notStrictExoMuon.root", "recreate");
   h_invMass = new TH1F ("InvMass", "Lepton Pair Invariant Mass", 100, 0 , 600);
   h_lxy = new TH1F ("lxy", "Transverse decay length", 20, 0 , 20);
   h_lxy_err = new TH1F ("lxy_err", "Transverse decay length significance", 20, 0 , 20);
   h_lxy2_err = new TH1F ("lxy2_err", "Transverse decay length significance", 20, 0 , 20);
   h_d0_err = new TH1F ("d0_err", "Impact parameter / Standar Deviation", 100, 0 , 20);
   h_conePt = new TH1F ("conePt", "Transverse momentum sum arround isolation cone", 100, 0 , 20);
   nEvents = new TH1F ("nEvents", "Number of Events", 5, -5,5);
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
   
bool standardCuts = cmsStandardCuts(vert_numTrack[0], Ev_Branch_numTrack, vertex1Track_vx, vertex1Track_vy, vertex1Track_vz, track_highPurity);
reset();




nEvents->Fill(1); 

if (standardCuts)   // quitar true
{   

	for (int i = 0 ; i< Ev_Branch_numTrack; i++)
	{

		for (int j = 0; j< Ev_Branch_numTrigObjM; j++)
		{
			bool lepMatch =matchingCuts( track_highPurity[i]  , track_pt[i] , track_found[i], fabs(track_eta[i]), fabs(track_dxy[i]/track_dxyError[i]));
		
		  
		   if (lepMatch)
		   {  
			   if(deltaR(track_phi[i], track_eta[i], trigObjM_phi[j], trigObjM_eta[j])< 0.1 /*&& deltaP(track_px[i], track_py[i],track_pz[i], trigObjM_px[j], trigObjM_py[j], trigObjM_pz[j]) < 3*/)
			   {   
				   matchedTrack[i] = 1;
			       matchedTrigObj[j] = (matchedTrigObj[j] + 1)%2;
			       trackTrigObjIndex[i] = j; 
			   }
			   
		   }
		  
		}
	}
	
	// Eliminate non isolated candidates
	
	
	// the following section compares vertex of opositly chareged trigger-matched leptons in order to find lepton pairs product of the same decay.
	
	for ( int i = 0;  i < Ev_Branch_numTrack; i++)
	{
		if ( matchedTrack[i] ==1 && track_charge[i] == 1 )
		{  
			for (int j =0; j< Ev_Branch_numTrack; j++)
			if ( matchedTrack[j] == 1 && track_charge[j] == -1 && trackTrigObjIndex[i] != trackTrigObjIndex[j] && deltaR(track_phi[i], track_eta[i], track_phi[j], track_eta[j]) >0.2)
			{  
				if ( deltaV(track_vx[i], track_vy[i], track_vz[i],track_vx[j], track_vy[j], track_vz[j]) < 0.1 )
				{
					double conePt_var = conePt(i, j, track_eta[i], track_phi[i], Ev_Branch_numTrack, track_eta, track_phi, track_pt);
					double alpha = mCos(track_phi[i], track_eta[i], track_phi[j], track_eta[j]);
					double theta = mTheta(track_px[i]+track_px[j], track_py[i]+track_py[j],vertex_x[0]-track_vx[i],  vertex_y[0]-track_vy[i]); 
					double theta2 = mTheta(-track_px[i]-track_px[j], -track_py[i]-track_py[j],vertex_x[0]-track_vx[i],  vertex_y[0]-track_vy[i]);
                         	   	
					//cout<<conePt_var<<endl;
					//cout<<alpha<<endl;
					//cout<<theta*180/(3.1415)<<endl;
					
					if (conePt_var < 4 && alpha > -0.95 && (theta < 0.2 || theta2 < 0.2 )/*0.8 ipara electron*/)
					{
						double invariantMass, sumPt;
					 invariantMass = invMass(track_px[i], track_py[i], track_pz[i], track_px[j], track_py[j], track_pz[j]);
					 cout<<invariantMass<<" "<<theta*180/(3.1415)<<endl;
					 //cout<<track_lxy1[i]<<endl;
					 //cout<<sqrt((track_vx[i]-vertex_x[0])*(track_vx[i]-vertex_x[0])+(track_vy[i] -vertex_y[0])*(track_vy[i] -vertex_y[0]))<<"   "<<track_lxy1[i]<<" "<<abs(sqrt((track_vx[i]-vertex_x[0])*(track_vx[i]-vertex_x[0])+(track_vy[i] -vertex_y[0])*(track_vy[i] -vertex_y[0]))-track_lxy1[i])/track_lxy1[i]<<endl;
					 //cout<<sqrt((track_vx[i]-vertex_x[0])*(track_vx[i]-vertex_x[0])+(track_vy[i] -vertex_y[0])*(track_vy[i] -vertex_y[0]))<<"   "<<track_lxy1[i]<<" "<<abs(sqrt((track_vx[i]-vertex_x[0])*(track_vx[i]-vertex_x[0])+(track_vy[i] -vertex_y[0])*(track_vy[i] -vertex_y[0]))-track_lxy1[i])/track_lxy1[i]<<endl;
					 h_invMass->Fill(invariantMass);
					 h_lxy->Fill(track_lxy1[i]);
					 h_lxy_err->Fill(fabs(track_lxy1[i]/track_dxyError[i]));
					 h_d0_err->Fill(fabs(track_dxy[i]/track_dxyError[i]));
					 h_lxy2_err->Fill(fabs(track_lxy2[i]/track_dxyError[i]));
					}
					
	                                //cout<<invariantMass<<endl;				
					 
					sumPt = conePt(i,track_eta[i],track_phi[i], Ev_Branch_numTrack, track_eta, track_phi, track_pt);
					//cout<<sumPt<<endl;
					 h_conePt->Fill(sumPt); 
					 
				}
			}
		}
	}
	
	
}
   vuelta ++;
   if(vuelta%1000 == 0)
   {
//cout<<"Vuelta "<<vuelta<<endl;
   }

   return kTRUE;
}

// calculates cosine of the angle between objects
double analyzer::mTheta(double ax, double ay, double bx, double by)
{
	double cosAlpha = ax*bx + ay*by;
	double theta;
	cosAlpha = cosAlpha/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by));
	theta  = acos(cosAlpha);
	return theta;
}

double analyzer::mCos(double phi1, double eta1, double phi2, double eta2 )
{double cosAlpha = sin(eta1)*cos(phi1)*sin(eta2)*cos(phi2) + sin(eta1)*sin(phi1)*sin(eta2)*sin(phi2) + cos(eta1)*cos(eta2);
	
	return cosAlpha;
}
// calculates sum of pt arround an isolation cone

double analyzer::conePt(int forbiddenIndex, double eta, double phi, int numTracks, double tracks_eta[], double tracks_phi[], double tracks_pt[])
{
	double sumPt = 0.0;
	for (int i = 0; i < numTracks; i++)
	{
		if(deltaR(eta, phi, tracks_eta[i], tracks_phi[i]) < 0.3 && deltaR(eta, phi, tracks_eta[i], tracks_phi[i]) > 0.03 && i != forbiddenIndex)
		{
			sumPt = track_pt[i] +sumPt;
		}
	}
	
	return sumPt;
}
double analyzer::conePt(int forbiddenIndex1, int forbiddenIndex2, double eta, double phi, int numTracks, double tracks_eta[], double tracks_phi[], double tracks_pt[])
{
	double sumPt = 0.0;
	for (int i = 0; i < numTracks; i++)
	{
		if(deltaR(eta, phi, tracks_eta[i], tracks_phi[i]) < 0.3 && deltaR(eta, phi, tracks_eta[i], tracks_phi[i]) > 0.03 && i != forbiddenIndex1 && i != forbiddenIndex2)
		{
			sumPt = track_pt[i] +sumPt;
		}
	}
	
	return sumPt;
}

// resets arrays and variables to Null/0

bool analyzer::matchingCuts( bool purity, double pt, int hits, double eta, double impSig)
{
	bool ret = false;
	
	
		
	  if(purity && pt > 33 && hits >= 6   && eta < 2 && impSig > 2 )
	  {
		  ret = true;

	  }	
	 
	  
	
/*	if(lepton == "electron")
	{
		if(purity && pt > 41 && hits >= 6  && eta < 2 && impSig > 3)
		{
			ret = true;
		}
	}*/
	
	return ret;
}

void analyzer::reset()
{
	for (int i = 0; i< Ev_Branch_numTrack; i++)
	{
		matchedTrack[i] = 0;
	}
	for (int i = 0; i< Ev_Branch_numTrigObjM; i++)
	{
		matchedTrigObj[i] = 0;
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
double analyzer::deltaP(double px1, double py1, double pz1, double px2, double py2, double pz2)
{
	/*double dpx = px1 -px2;
	double dpy = py1 -py2;
	double dpz = pz1 -pz2;*/
	double ptotT = sqrt(px1*px1 + py1*py1 +pz1*pz1);
	double ptotO = sqrt(px2*px2 + py2*py2 +pz2*pz2);
	
    //double dp = sqrt(dpx*dpx + dpy*dpy +dpz*dpz);
    double dp = fabs(ptotT - ptotO);
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


bool analyzer::cmsStandardCuts(Int_t numVertTracks, Int_t numTracks, Double_t vx[], Double_t vy[], Double_t vz[], bool purity[] )
{
	bool ret =  false;
	int distCount = 0;
	int highPurity = 0;
	bool moreThan25percent = false;
	 
		for (int i =0; i< numVertTracks; i ++) 
		{
			
			double vxy = sqrt(vx[i]*vx[i] + vy[i]*vy[i]);
			if (vxy< 2 && vz[i] < 24)
			{
				distCount ++;
			}
		}
	if(numTracks < 9)
	{
		moreThan25percent = true;
	}
	else
	{
		for (int i = 0; i < numTracks; i++)
		{
			if(purity[i])
			{
				highPurity++;
			}
		}
		if ((float)highPurity/numTracks > 0.25)
		{
			moreThan25percent = true;
		}
		
	}
	
	//cout<<numTracks<<" "<< distCount<<" "<<highPurity<<" "<< moreThan25percent<<endl;
	if (numTracks > 4 && distCount >4 && moreThan25percent)
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
	//cout<<vuelta<<endl;
	file->Write();
	file->Close();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
