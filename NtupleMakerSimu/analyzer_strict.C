#define analyzer_strict_cxx
// The class definition in analyzer_strict.h has been generated automatically
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
// Root > T->Process("analyzer_strict.C")
// Root > T->Process("analyzer_strict.C","some options")
// Root > T->Process("analyzer_strict.C+")
//

#include "analyzer_strict.h"
#include <TH2.h>
#include <TStyle.h>


void analyzer_strict::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void analyzer_strict::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   
 file = new TFile("DY.root", "recreate");
   file = new TFile("jueves.root", "recreate");
   
   h_invMassLoose = new TH1F ("InvMassLoose", "Lepton Pair Invariant Mass (loose)", 100, 0 , 600);
   h_invMass = new TH1F ("InvMass", "Lepton Pair Invariant Mass", 100, 0 , 600);
   h_invMass2 = new TH1F ("InvMass2", "Lepton Pair Invariant Mass (d0)", 100, 0 , 600);
   h_invMassLW = new TH1F ("InvMassLW", "Lepton Pair Invariant Mass (L-W cuts)", 100, 0 , 600);
   h_invMassLW2 = new TH1F ("InvMassLW2", "Lepton Pair Invariant Mass (L-W cuts, d0)", 100, 0 , 600);
   h_lxy = new TH1F ("lxy", "Transverse decay length", 20, 0 , 20);
   h_lxy2 = new TH1F ("lxy2", "Transverse decay length (d0)", 20, 0 , 20);
   h_lxyLoose = new TH1F ("lxyLoose", "Transverse decay length (loose)", 20, 0 , 20);
   h_lxy_err = new TH1F ("lxy_err", "Transverse decay length significance", 20, 0 , 20);
   h_lxy_err2 = new TH1F ("lxy_err2", "Transverse decay length significance (d0)", 20, 0 , 20);
   h_lxy_errLoose = new TH1F ("lxy_errLoose", "Transverse decay length significance (loose)", 20, 0 , 20);
   h_lxy2_err = new TH1F ("lxy2_err", "Transverse decay length significance", 20, 0 , 20);
   h_lxy2_err2 = new TH1F ("lxy2_err2", "Transverse decay length significance (d0)", 20, 0 , 20);
   h_dxy_errLoose = new TH1F ("dxy_errLoose", "Impact parameter / Standar Deviation (loose)", 100, 0 , 20);
   h_dxy_err = new TH1F ("dxy_err", "Impact parameter / Standar Deviation", 100, 0 , 20);
   h_dxy_err2 = new TH1F ("dxy_err2", "Impact parameter / Standar Deviation (d0)", 100, 0 , 20);
   h_d0_errLoose = new TH1F ("d0_errLoose", "Impact parameter / Standar Deviation (loose)", 100, 0 , 20);
   h_d0_err = new TH1F ("d0_err", "Impact parameter / Standar Deviation", 100, 0 , 20);
   h_d0_err2 = new TH1F ("d0_err2", "Impact parameter / Standar Deviation (d0)", 100, 0 , 20);
   h_conePt = new TH1F ("conePt", "Transverse momentum sum arround isolation cone", 100, 0 , 20);
   h_cos = new TH1F ("cos", "Cos(#alpha) lepton pairs", 100, -1.1 , 1.1);
   h_cos2 = new TH1F ("cos2", "Cos(#alpha) lepton pairs (d0)", 100, -1.1 , 1.1);
   h_cosLoose = new TH1F ("cosLoose", "Cos(#alpha) lepton pairs (loose)", 100, -1.1 , 1.1);
   h_delPhi = new TH1F ("delPhi", "lep Pt and vertex distance vector angle", 100, 0 , 1);
   h_delPhi2 = new TH1F ("delPhi2", "lep Pt and vertex distance vector angle (d0)", 100, 0 , 1);
   h_delPhiLoose = new TH1F ("delPhiLoose", "lep Pt and vertex distance vector angle (loose)", 100, 0 , 1);
   h_chi2_NDF = new TH1F ("chi2_NDF", "#chi^{2}/NDF", 100, 0 , 20);
   h_chi2_NDF2 = new TH1F ("chi2_NDF2", "#chi^{2}/NDF (d0)", 100, 0 , 20);
   h_chi2_NDFLoose = new TH1F ("chi2_NDFLoose", "#chi^{2}/NDF (loose)", 100, 0 , 20);
   h_numHitsLoose = new TH1F ("numHitsLoose", "Number of tracker hits between lepton pairs", 100, 0 , 20);
   h_dot = new TH1F ("h_dot","Dot product between lepton pair momentum and secVert-primVert distance",100,-10000,10000);
   h_dot2 = new TH1F ("h_dot2","Dot product between lepton pair momentum and secVert-primVert distance (d0)",100,-10000,10000);
   nEvents = new TH1F ("nEvents", "Number of Events", 5, -5,5);
  
   matchCount = 0;
   triggerTurnOns = 0;
   triggerObjects = 0;
   effCount = 0;
   TH1::AddDirectory(true);
   vuelta = 0;
}

Bool_t analyzer_strict::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either analyzer_strict::GetEntry() or TBranch::GetEntry()
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


//  



//


//cout<<"number of trigger objects "<<Ev_Branch_numTrigObjM<<endl;

nEvents->Fill(1); 
if (triggerMActivated)
{
	triggerTurnOns++;
}


//****** LeeWick mod

     /*                  
int ctemp = 0;
int check = 0;
for (int i = 0; i< Ev_Branch_numTrack; i++)
{
	

	track_px[i] = -track_px[i];
	track_py[i] = -track_py[i];
	track_pz[i] = -track_pz[i];
	
	//if (track_nHits[i] > 5 && track_n3DHits[i]>1)
	if(track_pt[i]>33)
	{  
		  // cout<<track_nHits[i]<<endl;
	
			ctemp++;
		
	}
	
	
	
}

if (ctemp >  1)
{
	effCount++;
}

*/
triggerObjects = triggerObjects + Ev_Branch_numTrigObjM;
if (standardCuts && triggerMActivated)   // quitar true
{   
    
     
	for (int i = 0 ; i< Ev_Branch_numTrack; i++)
	{

		for (int j = 0; j< Ev_Branch_numTrigObjM; j++)
		{
			bool lepMatch =matchingCuts( track_highPurity[i]  , track_pt[i] , track_nHits[i],track_n3DHits[i], fabs(track_eta[i]));
		
		  
		   if (lepMatch)
		   {  
			   if(deltaR(track_phi[i], track_eta[i], trigObjM_phi[j], trigObjM_eta[j])< 0.1 )
			   {   matchCount++;
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
				if ( deltaV(track_vx[i], track_vy[i], track_vz[i],track_vx[j], track_vy[j], track_vz[j]) <5 )
				{       
					double conePt_var = conePt(i, j, track_eta[i], track_phi[i], Ev_Branch_numTrack, track_eta, track_phi, track_pt);
					double alpha = mCos(track_phi[i], track_eta[i], track_phi[j], track_eta[j]);
					double theta = mTheta(track_px[i]+track_px[j], track_py[i]+track_py[j],vertex_x[0]-track_vx[i],  vertex_y[0]-track_vy[i]); 
					double theta2 = mTheta(-track_px[i]-track_px[j], -track_py[i]-track_py[j],vertex_x[0]-track_vx[i],  vertex_y[0]-track_vy[i]);
					double cosAlpha = mCos(track_phi[i], track_eta[i], track_phi[j], track_eta[j]);
					
					double dot, iM;
					
					double p1[3], p2[3], sv1[3], sv2[3], pV[3];
					
					
                         	   	
					//cout<<conePt_var<<endl;
					//cout<<alpha<<endl;
					//cout<<theta*180/(3.1415)<<endl;
					
					//if (conePt_var < 4 && alpha > -0.95 && (theta < 0.2 )/*0.8 ipara electron*/)
					if (conePt_var < 4 && alpha > -0.95/*0.8 ipara electron*/)
					
					{
						double invariantMass, sumPt;
					 invariantMass = invMass(track_px[i], track_py[i], track_pz[i], track_px[j], track_py[j], track_pz[j]);
					 
					 
					 
					p1[0] = track_px[i];
					p1[1] = track_py[i];
					p1[2] = track_pz[i];
					
					p2[0] = track_px[i];
					p2[1] = track_py[i];
					p2[2] = track_pz[i];
					
					sv1[0] = track_vx[i];
					sv1[1] = track_vy[i];
					sv1[2] = track_vz[i];
					
					sv2[0] = track_vx[i];
					sv2[1] = track_vy[i];
					sv2[2] = track_vz[i];
					
					pV[0] = vertex_x[0];
					pV[1] = vertex_y[0];
					pV[2] = vertex_z[0];
					dot = dotPL(pV,sv1,sv2,p1,p2);
					
					
					
					h_dot->Fill(dot);
					 

					//***************** Histograms with loose cuts
					h_dot->Fill(dot); 
					h_invMassLoose->Fill(invariantMass);
					h_lxyLoose->Fill(track_lxy1[i]);
					h_lxy_errLoose->Fill(fabs(track_lxy1[i]/track_dxyError[i]));
					h_chi2_NDFLoose->Fill(track_chi2[i]/track_ndof[i]);
					h_d0_errLoose->Fill(fabs(track_d0[i]/track_d0Error[i]));
					h_dxy_errLoose->Fill(fabs(track_dxy[i]/track_dxyError[i]));
					h_lxy2_err->Fill(fabs(track_lxy2[i]/track_dxyError[i]));
					h_delPhiLoose->Fill(theta);
					h_cosLoose->Fill(cosAlpha);
					h_numHitsLoose->Fill(track_nHits[i]+track_nHits[j]);

					 
					 // ***************** Histograms with life time related cuts
					 
					 if (fabs(track_lxy1[i]/track_dxyError[i])>5 && fabs(track_dxy[i]/track_dxyError[i]) > 2)
					 {
							h_invMass->Fill(invariantMass);
							h_lxy->Fill(track_lxy1[i]);
							h_lxy_err->Fill(fabs(track_lxy1[i]/track_dxyError[i]));
							h_chi2_NDF->Fill(track_chi2[i]/track_ndof[i]);
							h_delPhi->Fill(theta);
							h_cos->Fill(cosAlpha);
							h_d0_err->Fill(fabs(track_d0[i]/track_d0Error[i]));
							h_dxy_err->Fill(fabs(track_dxy[i]/track_dxyError[i]));
							
							if (dot<-400)
							{
								h_invMassLW->Fill(invariantMass);
							}
							
							
					 }
					  
					 if (fabs(track_lxy1[i]/track_dxyError[i])>5 && fabs(track_d0[i]/track_d0Error[i]) > 2)
					 {
							h_invMass2->Fill(invariantMass);
							h_lxy2->Fill(track_lxy1[i]);
							h_lxy_err2->Fill(fabs(track_lxy1[i]/track_dxyError[i]));
							h_chi2_NDF2->Fill(track_chi2[i]/track_ndof[i]);
							h_delPhi2->Fill(theta);
							h_cos2->Fill(cosAlpha);
							h_d0_err2->Fill(fabs(track_d0[i]/track_d0Error[i]));
							h_dxy_err2->Fill(fabs(track_dxy[i]/track_dxyError[i]));
							
							if (dot<-400)
							{
								h_invMassLW2->Fill(invariantMass);
							}
							
							
					 }
					 
					 //****************** End Histograms with....
					 
					 
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
   if(vuelta%10000 == 0)
   {
  cout<<"Vuelta "<<vuelta<<endl;
   }

   return kTRUE;
}

// calculates cosine of the angle between objects
double analyzer_strict::mTheta(double ax, double ay, double bx, double by)
{
	double cosAlpha = ax*bx + ay*by;
	double theta;
	cosAlpha = cosAlpha/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by));
	theta  = acos(cosAlpha);
	return theta;
}

double analyzer_strict::mCos(double phi1, double eta1, double phi2, double eta2 )
{double cosAlpha = sin(eta1)*cos(phi1)*sin(eta2)*cos(phi2) + sin(eta1)*sin(phi1)*sin(eta2)*sin(phi2) + cos(eta1)*cos(eta2);
	
	return cosAlpha;
}
// calculates sum of pt arround an isolation cone

double analyzer_strict::conePt(int forbiddenIndex, double eta, double phi, int numTracks, double tracks_eta[], double tracks_phi[], double tracks_pt[])
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
double analyzer_strict::conePt(int forbiddenIndex1, int forbiddenIndex2, double eta, double phi, int numTracks, double tracks_eta[], double tracks_phi[], double tracks_pt[])
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

bool analyzer_strict::matchingCuts( bool purity, double pt, int hits, int hits3D, double eta)
{
	bool ret = false;
	
	
		
	  if(purity && pt > 33 && hits >= 6   && eta < 2  )
	  if(true)
	  
	  {
		  ret = true;

	  }	
	 
	  

	
	return ret;
}

void analyzer_strict::reset()
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
double analyzer_strict::invMass(double px1, double py1, double pz1, double px2 , double py2,  double pz2)
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
double analyzer_strict::deltaP(double px1, double py1, double pz1, double px2, double py2, double pz2)
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

double analyzer_strict::deltaV(double vx1, double vy1, double vz1, double vx2, double vy2, double vz2)
{
   double dx = vx1-vx2;
   double dy = vy1-vy2;
   double dz = vz1 - vz2;
   
   double dv = sqrt(dx*dx +dy*dy +dz*dz);
   return dv;	
}

double analyzer_strict::deltaR(double obj1Phi, double obj1Eta, double obj2Phi, double obj2Eta)
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


bool analyzer_strict::cmsStandardCuts(Int_t numVertTracks, Int_t numTracks, Double_t vx[], Double_t vy[], Double_t vz[], bool purity[] )
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
	
	
	if (numTracks > 3 && distCount >3 &&  moreThan25percent)
	{
		ret  = true;
	}
	
	return ret;
	

}
double analyzer_strict::dotPL(double pV[3], double sv1[3], double sv2[3], double p1[3], double p2[3])
{
	double VAv[3], vertV[3], pTot[3], dot;
	
	for (int i = 0; i< 3; i++)
	{  
		pTot[i] = (p1[i] + p2[i]);
		
		VAv[i] = 0.5*(sv1[i] + sv2[i]);
		
		vertV[i] = VAv[i] - pV[i];
	}
	// normalize pAv
	
	for (int i = 0; i<3; i++)
	{
		/*pTot[i] = pTot[i]/norm(pTot[0],pTot[1], pTot[2]);
		vertV[i] = vertV[i]/norm(vertV[0], vertV[1], vertV[2]);*/
		
		/*pTot[i] = pTot[i]/norm(pTot[0],pTot[1]);
		vertV[i] = vertV[i]/norm(vertV[0], vertV[1]);*/
	}
	
	
	dot = pTot[0]*vertV[0] +pTot[1]*vertV[1] + pTot[2]*vertV[2];
	//dot = pTot[0]*vertV[0] +pTot[1]*vertV[1];
	//cout<<"normal "<<dot<<endl;
	return dot;
	
}

void analyzer_strict::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void analyzer_strict::Terminate()
{
	//cout<<vuelta<<endl;
	cout<<"Number of matches: "<<matchCount<<" efficiency  "<<matchCount/(4000.0*4)<<endl;
	cout<<"Trigger turnons: "<<triggerTurnOns<<" efficiency:   "<<triggerTurnOns/4000.0<<endl;
	cout<<"NUmber of trigger objects "<<triggerObjects<<"     "<<triggerObjects/(4000.0*4)<<endl;
	cout<<"eff Count: "<<effCount<<endl;
	file->Write();
	file->Close();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
