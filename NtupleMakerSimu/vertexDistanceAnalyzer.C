#define vertexDistanceAnalyzer_cxx
// The class definition in vertexDistanceAnalyzer.h has been generated automatically
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
// Root > T->Process("vertexDistanceAnalyzer.C")
// Root > T->Process("vertexDistanceAnalyzer.C","some options")
// Root > T->Process("vertexDistanceAnalyzer.C+")
//

#include "vertexDistanceAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>


void vertexDistanceAnalyzer::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void vertexDistanceAnalyzer::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   
   file = new TFile("exotic.root", "recreate");
   h_invMass = new TH1F ("InvMass", "Lepton Pair Invariant Mass", 100, 0 , 600);
   h_lxy = new TH1F ("lxy", "Transverse decay length", 20, 0 , 20);
   h_lxy_err = new TH1F ("lxy_err", "Transverse decay length significance", 20, 0 , 20);
   h_lxy2_err = new TH1F ("lxy2_err", "Transverse decay length significance", 20, 0 , 20);
   h_d0_err = new TH1F ("d0_err", "Impact parameter / Standar Deviation", 100, 0 , 20);
   h_conePt = new TH1F ("conePt", "Transverse momentum sum arround isolation cone", 100, 0 , 20);
   h_dv = new TH1F ("h_dv", "Vertex distane between lepton candidates", 100, 0,10);
   h_dx = new TH1F ("h_dx", "Vertex distane between lepton candidates", 100, -10,10);
   h_dy = new TH1F ("h_dy", "Vertex distane between lepton candidates", 100, -10,10);
   h_dz = new TH1F ("h_dz", "Vertex distane between lepton candidates", 100, -10,10);
   h_mpt = new TH1F ("h_mpt", "Vertex distane between lepton candidates", 100, -100,100);
   h_dm = new TH1F ("h_dm", "Vertex distane between lepton candidates", 100, 0,600);
   nEvents = new TH1F ("nEvents", "Number of Events", 5, -5,5);
   
   //Histograms for track pairs
   t_invMass = new TH1F ("t_invMass", "track pair Invariant Mass (with some cut)", 100, 0 , 600);
   t_dv = new TH1F ("t_dv","Distance between track vertices ", 100, -20,20);
   
   // Histograms with cuts
   
   c_invMass = new TH1F ("c_invMass", "Lepton Pair Invariant Mass (with some cut)", 100, 0 , 600);
   c_pt = new TH1F ("c_mpt", "Vertex distane between lepton candidates (with some cut) ", 100, -100,100);
   c_phi = new TH1F ("c_phi","#phi (whith some cut)", 100, -4, 4);
   c_eta = new TH1F ("c_eta","#eta (whith some cut)", 100, -4, 4);
   c_dv = new TH1F ("c_dv","Distance between track vertices (whith some cut)", 100, -4, 4);
   
   cc_invMass = new TH1F ("cc_invMass", "Lepton Pair Invariant Mass (complementary cut)", 100, 0 , 600);
   cc_pt = new TH1F ("cc_mpt", "Vertex distane between lepton candidates (complementary cut) ", 100, -100,100);
   cc_phi = new TH1F ("cc_phi","#phi (complementary cut)", 100, -4, 4);
   cc_eta = new TH1F ("cc_eta","#eta (complementery cut)", 100, -4, 4);
   cc_dv = new TH1F ("cc_dv","Distance between track vertices (complementary cut)", 100, -4, 4);
   
   
   
  //matchedTrack[ = {0};
   TH1::AddDirectory(true);
   vuelta = 0;
}

Bool_t vertexDistanceAnalyzer::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either vertexDistanceAnalyzer::GetEntry() or TBranch::GetEntry()
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
   double dv1= 100;
	double dv2 = 100;
bool standardCuts = cmsStandardCuts(vert_numTrack[0], Ev_Branch_numTrack, vertex1Track_vx, vertex1Track_vy, vertex1Track_vz, track_highPurity);
reset();




// find index of tracks with highest pt
int nTGPt = 2;  // number of tracks with greatest pt to use afterwards
int gPtIndexPos[2];
int gPtIndexNeg[2];
int gPtIndex[4];

for (int i = 0; i < nTGPt; i++)
{
	gPtIndexPos[i] = -1;
}


for (int i = 0; i < nTGPt; i++)
{
	gPtIndexNeg[i] = -1;
}


for (int i = 0; i < 4; i++)
{
	gPtIndex[i] = -1;
}


for (int i = 0; i <nTGPt ; i++)
{
	int candidate = 0;
	int dumCanPt = 0;
	for (int j =0; j < Ev_Branch_numTrack; j ++ )
	{
		if ( j != gPtIndexPos[0] &&  j != gPtIndexPos[1] && (int)track_charge[j] ==1 )
		{
			if (track_pt[j] > dumCanPt)
			{
				dumCanPt = track_pt[j];
				candidate = j;
			}
		}		
	}
	gPtIndexPos[i] = candidate;
}


for (int i = 0; i <nTGPt ; i++)
{
	int candidate = 0;
	int dumCanPt = 0;
	for (int j =0; j < Ev_Branch_numTrack; j ++ )
	{
		if ( j != gPtIndexNeg[0] &&  j != gPtIndexNeg[1] && (int)track_charge[j] == -1 )
		{
			if (track_pt[j] > dumCanPt)
			{
				dumCanPt = track_pt[j];
				candidate = j;
			}
		}		
	}
	gPtIndexNeg[i] = candidate;
}

for (int i = 0; i <4 ; i++)
{
	int candidate = 0;
	int dumCanPt = 0;
	for (int j =0; j < Ev_Branch_numTrack; j ++ )
	{
		if ( j != gPtIndex[0] &&  j != gPtIndex[1]&&  j != gPtIndex[2]&&  j != gPtIndex[3] )
		{
			if (track_pt[j] > dumCanPt)
			{
				dumCanPt = track_pt[j];
				candidate = j;
			}
		}		
	}
	gPtIndex[i] = candidate;
}



// Ordeno a los muones generados de acuerdo a Pt (de mayor pt a menor pt)
double dumGenMuPt;
if (genMu_pt[0] < genMu_pt[1])
{
	dumGenMuPt =  genMu_pt[0];
	genMu_pt[0] = genMu_pt[1];
	genMu_pt[1] = dumGenMuPt;
	
	dumGenMuPt =  genMuBar_pt[0];
	genMuBar_pt[0] = genMuBar_pt[1];
	genMuBar_pt[1] = dumGenMuPt;
	
}
cout<<"***********************************************************"<<endl;
for (int i =0; i < 2; i++)
{
	cout<<"pos track "<< track_pt[gPtIndexPos[i]]<<endl;
}
for (int i =0; i < 2; i++)
{
	cout<<"neg track "<<  track_pt[gPtIndexNeg[i]]<<endl;
}
for (int i =0; i < 4; i++)
{
	cout<<"sorted track "<<track_pt[gPtIndex[i]]<<" charge "<<(int)track_charge[gPtIndex[i]]<<endl;
}
for (int i =0; i < 2; i++)
{
	cout<<"gen mu " <<genMu_pt[i]<<endl;
}
for (int i =0; i < 2; i++)
{
	cout<<"gen muBar "<<genMuBar_pt[i]<<endl;
}



bool altCompare = false;

if (genMuBar_pt[0] < genMuBar_pt[1])
{
	altCompare = true;
}
double iM, dV;
if (! altCompare)
{   
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass->Fill(iM);
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass->Fill(iM);
	
    dV = deltaV(track_vx[gPtIndexPos[0]], track_vy[gPtIndexPos[0]], track_vz[gPtIndexPos[0]],track_vx[gPtIndexNeg[0]], track_vy[gPtIndexNeg[0]], track_vz[gPtIndexNeg[0]]);
    t_dv->Fill(dV);
	dV = deltaV(track_vx[gPtIndexPos[1]], track_vy[gPtIndexPos[1]], track_vz[gPtIndexPos[0]],track_vx[gPtIndexNeg[1]], track_vy[gPtIndexNeg[1]], track_vz[gPtIndexNeg[1]]); 
	  t_dv->Fill(dV);
	
	
}
/* if (altCompare)
{  
	
    iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass->Fill(iM);
    iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass->Fill(iM);
		
	dV = deltaV(track_vx[gPtIndexPos[0]], track_vy[gPtIndexPos[0]], track_vz[gPtIndexPos[0]],track_vx[gPtIndexNeg[1]], track_vy[gPtIndexNeg[1]], track_vz[gPtIndexNeg[1]]);
	dV = deltaV(track_vx[gPtIndexPos[0]], track_vy[gPtIndexPos[0]], track_vz[gPtIndexPos[0]],track_vx[gPtIndexNeg[0]], track_vy[gPtIndexNeg[0]], track_vz[gPtIndexNeg[0]]); 
	
}
*/
//cout<<"number of trigger objects "<<Ev_Branch_numTrigObjM<<endl;

nEvents->Fill(1); 

for(int  i = 0 ; i< 2; i++)
{
	double px1,py1, pz1, px2, py2, pz2, m;
	
	px1 = genMu_px[i];
	py1 = genMu_py[i];
	pz1 = genMu_pz[i];
	px2 = genMuBar_px[i];
	py2 = genMuBar_py[i];
	pz2 = genMuBar_pz[i];
	
    m = invMass(px1,py1,pz1,px2,py2,pz2);
    h_dm->Fill(m);
	
}


if (standardCuts)   // quitar true
{   

	for (int i = 0 ; i< Ev_Branch_numTrack; i++)
	{

		for (int j = 0; j< Ev_Branch_numTrigObjM; j++)
		{
			bool lepMatch =matchingCuts( track_highPurity[i]  , track_pt[i] , track_found[i], fabs(track_eta[i]), fabs(track_dxy[i]/track_dxyError[i]));
		
		  
		   if (lepMatch||true)
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
	
	
	//
	
	//pair gen muons and antimuons with traks
	
	int pairedMuonIndex[2];
	int pairedMuonBarIndex[2];
	pairedMuonIndex[0] = 0;
	pairedMuonIndex[1] = 0;
	pairedMuonBarIndex[0] = 0;
	pairedMuonBarIndex[1] = 0;
	int removedMu = -1;
	
	int removedMuBar = -1;
	
	/*for (int k =0; k <2; k++)
	{double eta1, eta2, phi1, phi2, dum=100, dr=100;
		for ( int i = 0;  i < nTGPt; i++)
		{
		if ( matchedTrack[gPtIndex[i]] ==1 && track_charge[gPtIndex[i]] == 1 )
			{ eta1 = track_eta[i];
			 phi1 = track_phi[i];
			  eta2 = genMu_eta[k];
			  phi2 = genMu_phi[k];
			  
				
				dum = deltaR(phi1, eta1, phi2, eta2);
				if(dum < dr)
				{
					dr = dum;
					pairedMuonIndex[k]= gPtIndex[i];
					
					//cout<<"num tracks1 "<<Ev_Branch_numTrack<<" i "<<i<<endl;
				}
			}
		
		
		}
	}*/
	
	//cout<<"Number of tracks1: "<<Ev_Branch_numTrack<<" Index "<<pairedMuonIndex[0]<<", "<<pairedMuonIndex[1]<<endl; 
		
	/*for (int k =0; k <2; k++)
	{double eta1, eta2, phi1, phi2, dum=100, dr=100;
		for ( int i = 0;  i < nTGPt; i++)
		{
		if ( matchedTrack[gPtIndex[i]] ==1 && track_charge[gPtIndex[i]] == -1  )
			{ 
				eta1 = track_eta[i];
			 phi1 = track_phi[i];
			  eta2 = genMuBar_eta[k];
			  phi2 = genMuBar_phi[k];
				dum = deltaR(phi1, eta1, phi2, eta2);
				if(dum < dr)
				{
					dr = dum;
					
					
					pairedMuonBarIndex[k]= gPtIndex[i];
					
				//cout<<"num tracks2 "<<Ev_Branch_numTrack<<" i "<<i<<endl;
				}
			}
		
		
		}
	}*/
	//cout<<"Number of tracks2: "<<Ev_Branch_numTrack<<" Index "<<pairedMuonBarIndex[0]<<", "<<pairedMuonBarIndex[1]<<endl; 
	
/*for (int i =0; i< 2; i++)
	{
		double dvtemp;
		double  invariantMass = invMass(track_px[i], track_py[i], track_pz[i], track_px[j], track_py[j], track_pz[j]);
       dvtemp = deltaV(track_vx[pairedMuonIndex[i]],track_vy[pairedMuonIndex[i]],track_vz[pairedMuonIndex[i]],track_vx[pairedMuonBarIndex[i]],track_vy[pairedMuonBarIndex[i]],track_vz[pairedMuonBarIndex[i]]);
      invariantMass = abs(invariantMass -350);
      if (invariantMass<50|| true)
      {
		h_dv->Fill(dvtemp);
		h_dx->Fill(track_vx[pairedMuonIndex[i]]-track_vx[pairedMuonBarIndex[i]]);
		h_dy->Fill(track_vy[pairedMuonIndex[i]]-track_vy[pairedMuonBarIndex[i]]);
		h_dz->Fill(track_vz[pairedMuonIndex[i]]-track_vz[pairedMuonBarIndex[i]]);
		
		h_mpt->Fill(track_pt[pairedMuonIndex[i]]-track_pt[pairedMuonBarIndex[i]]);
		
		//Fill histograms with cuts
		
		if (dvtemp < 0.5 ||true)
		{
			c_invMass->Fill(invariantMass);
			c_pt->Fill(track_pt[pairedMuonIndex[i]]-track_pt[pairedMuonBarIndex[i]]);
			c_dv->Fill(dvtemp);
		}
		
		
      } 	
	}*/
	
	double dvDum = 0;
	double massDiff = 100;
	for ( int i = 0;  i < Ev_Branch_numTrack; i++)
	{
		if ( matchedTrack[i] ==1 && track_charge[i] == 1 )
		{ 
			for (int j =i+1; j< Ev_Branch_numTrack; j++)
			if ( matchedTrack[j] == 1 && track_charge[j] == -1 && trackTrigObjIndex[i] != trackTrigObjIndex[j] && deltaR(track_phi[i], track_eta[i], track_phi[j], track_eta[j]) >0.2)
			{  
					 dvDum = deltaV(track_vx[i], track_vy[i], track_vz[i],track_vx[j], track_vy[j], track_vz[j]) ;
				   double  invariantMass = invMass(track_px[i], track_py[i], track_pz[i], track_px[j], track_py[j], track_pz[j]);
				   
				   double conePt_var = conePt(i, j, track_eta[i], track_phi[i], Ev_Branch_numTrack, track_eta, track_phi, track_pt);
					double alpha = mCos(track_phi[i], track_eta[i], track_phi[j], track_eta[j]);
					double theta = mTheta(track_px[i]+track_px[j], track_py[i]+track_py[j],vertex_x[0]-track_vx[i],  vertex_y[0]-track_vy[i]); 
					double theta2 = mTheta(-track_px[i]-track_px[j], -track_py[i]-track_py[j],vertex_x[0]-track_vx[i],  vertex_y[0]-track_vy[i]);
					
					
					
					if (/*conePt_var < 4 && alpha > -0.95 && */(theta <  1.2 )){
				      
				      massDiff= abs(invariantMass - 350);
				      if (massDiff < 10  )
				      { //h_dv-> Fill(dvDum);
					  }
					 
					}
				    
					
					 
				
			}
		}
	}
	
	
}
   h_dv->Fill(dv1);
   vuelta ++;
   if(vuelta%1000 == 0)
   {
//cout<<"Vuelta "<<vuelta<<endl;
   }

   return kTRUE;
}

// calculates cosine of the angle between objects
double vertexDistanceAnalyzer::mTheta(double ax, double ay, double bx, double by)
{
	double cosAlpha = ax*bx + ay*by;
	double theta;
	cosAlpha = cosAlpha/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by));
	theta  = acos(cosAlpha);
	return theta;
}

double vertexDistanceAnalyzer::mCos(double phi1, double eta1, double phi2, double eta2 )
{double cosAlpha = sin(eta1)*cos(phi1)*sin(eta2)*cos(phi2) + sin(eta1)*sin(phi1)*sin(eta2)*sin(phi2) + cos(eta1)*cos(eta2);
	
	return cosAlpha;
}
// calculates sum of pt arround an isolation cone

double vertexDistanceAnalyzer::conePt(int forbiddenIndex, double eta, double phi, int numTracks, double tracks_eta[], double tracks_phi[], double tracks_pt[])
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
double vertexDistanceAnalyzer::conePt(int forbiddenIndex1, int forbiddenIndex2, double eta, double phi, int numTracks, double tracks_eta[], double tracks_phi[], double tracks_pt[])
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

bool vertexDistanceAnalyzer::matchingCuts( bool purity, double pt, int hits, double eta, double impSig)
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

void vertexDistanceAnalyzer::reset()
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
double vertexDistanceAnalyzer::invMass(double px1, double py1, double pz1, double px2 , double py2,  double pz2)
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
double vertexDistanceAnalyzer::deltaP(double px1, double py1, double pz1, double px2, double py2, double pz2)
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

double vertexDistanceAnalyzer::deltaV(double vx1, double vy1, double vz1, double vx2, double vy2, double vz2)
{
   double dx = vx1-vx2;
   double dy = vy1-vy2;
   double dz = vz1 - vz2;
   
   double dv = sqrt(dx*dx +dy*dy +dz*dz);
   return dv;	
}

double vertexDistanceAnalyzer::deltaR(double obj1Phi, double obj1Eta, double obj2Phi, double obj2Eta)
{
	double dPhi = obj1Phi - obj2Phi;
	if(dPhi > (3.1415)/2)
	{
		dPhi =  3.1415 - dPhi;
	}
	double dEta = obj1Eta - obj2Eta;
	double dR = sqrt(dPhi*dPhi + dEta*dEta);
	return dR;
}


bool vertexDistanceAnalyzer::cmsStandardCuts(Int_t numVertTracks, Int_t numTracks, Double_t vx[], Double_t vy[], Double_t vz[], bool purity[] )
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


void vertexDistanceAnalyzer::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void vertexDistanceAnalyzer::Terminate()
{
	//cout<<vuelta<<endl;
	file->Write();
	file->Close();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
