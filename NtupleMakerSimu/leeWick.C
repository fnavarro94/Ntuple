#define leeWick_cxx
// The class definition in leeWick.h has been generated automatically
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
// Root > T->Process("leeWick.C")
// Root > T->Process("leeWick.C","some options")
// Root > T->Process("leeWick.C+")
//

#include "leeWick.h"
#include <TH2.h>
#include <TStyle.h>


void leeWick::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void leeWick::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   
   file = new TFile("notStrictDYMuon.root", "recreate");
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

Bool_t leeWick::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either leeWick::GetEntry() or TBranch::GetEntry()
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
 
 
 //Encontrar los cuatro jets con mayor pt

double sortedPt[20000];
int sortedIndex[20000];
double dumPt = 0;
int dumIndex = 0;
for (int i = 0; i < Ev_Branch_numJets; i++)
{
	sortedPt[i] = ak5jet_pt[i];
	sortedIndex[i] = i;
}

for (int i = 0 ; i <4; i++)
{
	for (int j= Ev_Branch_numJets-1; j >=0; j--)
	if( sortedPt[j] < sortedPt[j+1] )
	{
	   	dumPt = sortedPt[j];
	   	sortedPt[j] = sortedPt[j+1];
	   	sortedPt[j+1] = dumPt;
	   	
	   	dumIndex = sortedIndex[j];
	   	sortedIndex[j] = sortedIndex[j+1];
	   	sortedIndex[j+1] = dumIndex;
	}
}
// index of hardest jets are sortetIndex[i], i = 0, 1, 2, 3.


// calculates the invariant mass for every jet pair

double invMassArr[6];
int  invMassIndexArr[6][2]; 



int k = 0;
for (int i =0; i < 3; i++)
{
	for (int j = i+1; j< 4; j++)
	{
		invMassArr[k] = invMass(ak5jet_px[sortedIndex[i]], ak5jet_px[sortedIndex[i]],ak5jet_px[sortedIndex[i]],0,ak5jet_px[sortedIndex[j]],ak5jet_px[sortedIndex[j]],ak5jet_px[sortedIndex[j]],0);
	   
	    invMassIndexArr[k][0] = i;
	    invMassIndexArr[k][1] = j;
		k++;
	}
}



// Finds out which paris have a mass closest to the Lee-Wick particle mass
double lwMass = 350;
int sortedInvMassIndex[6];
double sortedInvMass[6];
double  dumMass=0;


for(int i = 0; i< 6; i++)
{
	sortedInvMass[i] = abs(invMassArr[i]-lwMass);
	sortedInvMassIndex[i] =i;
}


for(int j =0; j<5; j++)
{
	for (int i = 4; i >=0; i--)
	{
		if(sortedInvMass[i] > sortedInvMass[i+1])
		{
			dumMass = sortedInvMass[i];
			sortedInvMass[i] = sortedInvMass[i+1];
			sortedInvMass[i+1] = dumMass;
			
			dumIndex = sortedInvMassIndex[i];
			sortedInvMassIndex[i] = sortedInvMassIndex[i+1];
			sortedInvMassIndex[i+1] = dumIndex;
		}
		
		
	}
}

//check that the same jet does not appear in both selected pairs

bool check = false;
int count = 1;
while(!check)
{
	if (invMassIndexArr[sortedInvMassIndex[count]][0] == invMassIndexArr[sortedInvMassIndex[0]][0] || invMassIndexArr[sortedInvMassIndex[count]][0] == invMassIndexArr[sortedInvMassIndex[0]][1]
	    || invMassIndexArr[sortedInvMassIndex[count]][1] == invMassIndexArr[sortedInvMassIndex[0]][0]  || invMassIndexArr[sortedInvMassIndex[count]][1] == invMassIndexArr[sortedInvMassIndex[0]][1])
	    {
			count++;
			cout<<"count: "<<count<<endl;
		}
		
	else 
	{
		check = true;
	}
}

// if there was repetition, change the first pair with no repeated jets for the previous candidate

sortedInvMassIndex[1] = sortedInvMassIndex[count];





// Directon of Z bosons
double Z_phi[2], Z_eta[2];
for (int i =0 ; i<2; i++)
{
	double px = ak5jet_px[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][0]]] + ak5jet_px[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][0]]];
	double py = ak5jet_py[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][0]]] + ak5jet_px[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][1]]];
	double pz = ak5jet_pz[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][0]]] + ak5jet_pz[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][1]]];
    double pt = sqrt(px*px +py*py);
	double tanTheta = px/py;
	double th = atan(pt/pz);
	
	Z_phi[i] = atan(tanTheta);
	Z_eta[i] = -log(tan(th/2));
}



// Change the origin of the jets
for(int i=0; i<4; i++){//******
	ak5jet_x[sortedIndex[i]] = gRandom -> Gaus(0,sigma);
	ak5jet_y[sortedIndex[i]] = gRandom -> Gaus(0,sigma);
	ak5jet_z[sortedIndex[i]] = gRandom -> Gaus(0,sigma);
	}//end of jeti


//create z decay position (average of pair of jets)

double Z_X[2], Z_Y[2], Z_Z[2];

for (int i =0; i < 2; i++)
{
	Z_X[i] = (ak5jet_x[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][0]]] + ak5jet_x[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][1]]])/2;
	Z_Y[i] = (ak5jet_y[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][0]]] + ak5jet_y[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][1]]])/2;
	Z_Z[i] = (ak5jet_z[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][0]]] + ak5jet_z[sortedIndex[invMassIndexArr[sortedInvMassIndex[i]][1]]])/2;
	
}

// create the acausal vertex

double LW_X[2];
double LW_Y[2];
double LW_Z[2];

double fPx[2], fPy[2], fPz[2];

double d;
float theta;
int aux_mj;
	while (d<20e-3){
	d = gRandom -> Gaus(0,3e-2);
	cout<<d<<endl;
	}
	for(int i=0; i<2; i++){//****
	fPx[i] = d*cos(Z_phi[i])*sin(2*atan(exp(-Z_eta[i])));
	fPy[i] = d*sin(Z_phi[i])*sin(2*atan(exp(-Z_eta[i])));
	fPz[i] = d*cos(2*atan(exp(-Z_eta[i])));
    LW_X[i]=Z_X[i]+fPx[i];
	LW_Y[i]=Z_Y[i]+fPy[i];
	LW_Z[i]=Z_Z[i]+fPz[i];
	}


// calculate pseudo impact parameter

double dx, dy, dz; // 

for (int i =0; i < 4; i++)
{
	double Pjx ak5jet_px[sortedIndex[i]];
	double Pjy ak5jet_py[sortedIndex[i]];
	double Pjz ak5jet_pz[sortedIndex[i]];
	double Pj2 = Pjx*Pjx +Pjy*Pjy + Pjz*Pjz;
	double r0x, r0y, r0z;
	double rjx, rjy, rjz;
	
	rjx = ak5jet_x[sortedIndex[i]];
	rjy = ak5jet_y[sortedIndex[i]];
	rjz = ak5jet_z[sortedIndex[i]];
	
	r0x = LW_X;
	r0y = LW_Y;
	r0z = LW_Z;
     
	double coef = ((Pjx)*(r0x-rjx)+(Pjy)*(r0y-rjy)+(Pjz)*(r0z-rjz))/(pj2);
	
	dx = Pjx*coef + rjx -r0x; 
	dx = Pjy*coef + rjy -r0y; 
	dx = Pjz*coef + rjz -r0z; 
}





cout<<"las parejeas de jets con massa mas parecida a la de leeweick son: "<<endl;
cout<<invMassIndexArr[sortedInvMassIndex[0]][0]<<","<<invMassIndexArr[sortedInvMassIndex[0]][1]<<endl;
cout<<invMassIndexArr[sortedInvMassIndex[1]][0]<<","<<invMassIndexArr[sortedInvMassIndex[1]][1]<<endl;
cout<<invMassIndexArr[sortedInvMassIndex[2]][0]<<","<<invMassIndexArr[sortedInvMassIndex[2]][1]<<endl;
cout<<invMassIndexArr[sortedInvMassIndex[3]][0]<<","<<invMassIndexArr[sortedInvMassIndex[3]][1]<<endl;
cout<<invMassIndexArr[sortedInvMassIndex[4]][0]<<","<<invMassIndexArr[sortedInvMassIndex[4]][1]<<endl;
cout<<invMassIndexArr[sortedInvMassIndex[5]][0]<<","<<invMassIndexArr[sortedInvMassIndex[5]][1]<<endl;





}

// calculates cosine of the angle between objects
double leeWick::mTheta(double ax, double ay, double bx, double by)
{
	double cosAlpha = ax*bx + ay*by;
	double theta;
	cosAlpha = cosAlpha/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by));
	theta  = acos(cosAlpha);
	return theta;
}

double leeWick::mCos(double phi1, double eta1, double phi2, double eta2 )
{double cosAlpha = sin(eta1)*cos(phi1)*sin(eta2)*cos(phi2) + sin(eta1)*sin(phi1)*sin(eta2)*sin(phi2) + cos(eta1)*cos(eta2);
	
	return cosAlpha;
}
// calculates sum of pt arround an isolation cone

double leeWick::conePt(int forbiddenIndex, double eta, double phi, int numTracks, double tracks_eta[], double tracks_phi[], double tracks_pt[])
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
double leeWick::conePt(int forbiddenIndex1, int forbiddenIndex2, double eta, double phi, int numTracks, double tracks_eta[], double tracks_phi[], double tracks_pt[])
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

bool leeWick::matchingCuts( bool purity, double pt, int hits, double eta, double impSig)
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

void leeWick::reset()
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
double leeWick::invMass(double px1, double py1, double pz1,double mass1, double px2 , double py2,  double pz2, double mass2)
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
double leeWick::deltaP(double px1, double py1, double pz1, double px2, double py2, double pz2)
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

double leeWick::deltaV(double vx1, double vy1, double vz1, double vx2, double vy2, double vz2)
{
   double dx = vx1-vx2;
   double dy = vy1-vy2;
   double dz = vz1 - vz2;
   
   double dv = sqrt(dx*dx +dy*dy +dz*dz);
   return dv;	
}

double leeWick::deltaR(double obj1Phi, double obj1Eta, double obj2Phi, double obj2Eta)
{
	double dPhi = obj1Phi - obj2Phi;
	double dEta = obj1Eta - obj2Eta;
	double dR = sqrt(dPhi*dPhi + dEta*dEta);
	return dR;
}


bool leeWick::cmsStandardCuts(Int_t numVertTracks, Int_t numTracks, Double_t vx[], Double_t vy[], Double_t vz[], bool purity[] )
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


void leeWick::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void leeWick::Terminate()
{
	//cout<<vuelta<<endl;
	file->Write();
	file->Close();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
