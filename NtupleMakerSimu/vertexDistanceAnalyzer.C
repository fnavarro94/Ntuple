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
   file = new TFile("exotic.root", "recreate");
  
   nEvents = new TH1F ("nEvents", "Number of Events", 5, -5,5);
   
   //Histograms for track pairs
    t_invMassFull = new TH1F ("t_invMassFull", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass = new TH1F ("t_invMass", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass1 = new TH1F ("t_invMass1", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass2 = new TH1F ("t_invMass2", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass3 = new TH1F ("t_invMass3", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass4 = new TH1F ("t_invMass4", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass5 = new TH1F ("t_invMass5", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass6 = new TH1F ("t_invMass6", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass7 = new TH1F ("t_invMass7", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass8 = new TH1F ("t_invMass8", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass9 = new TH1F ("t_invMass9", "track pair Invariant Mass", 100, 0 , 600);
   t_invMass10 = new TH1F ("t_invMass10", "track pair Invariant Mass", 100, 0 , 600);
   
   t_invMassCut = new TH1F ("t_invMassCut", "track pair Invariant Mass (with some cut)", 100, 0 , 600);
   
   t_dv = new TH1F ("t_dv","Distance between track vertices ", 100, -10,10);
   t_dx = new TH1F ("t_dx","Distance between track vertices ", 100, -10,10);
   t_dy = new TH1F ("t_dy","Distance between track vertices ", 100, -10,10);
   t_dz = new TH1F ("t_dz","Distance between track vertices ", 100, -10,10);
   
   t_dvCut = new TH1F ("t_dvCut","Distance between track vertices ", 100, -10,10);
   t_dxCut = new TH1F ("t_dxCut","Distance between track vertices ", 100, -10,10);
   t_dyCut = new TH1F ("t_dyCut","Distance between track vertices ", 100, -10,10);
   t_dzCut = new TH1F ("t_dzCut","Distance between track vertices ", 100, -10,10);
   
   t_dot = new TH1F ("t_dot","Dot product between lepton pair momentum and secVert-primVert distance vector ", 100, -10000,10000);
   t_dotCut = new TH1F ("t_dotCut","Dot product between lepton pair momentum and secVert-primVert distance vector ", 100, -10000,10000);
   t_dotLeeWick = new TH1F ("t_dotLeeWick","Dot product between lepton pair momentum and secVert-primVert distance vector (with lee-wick modification) ", 100, -10000,10000);
   t_dotLeeWickCut = new TH1F ("t_dotLeeWickCut","Dot product between lepton pair momentum and secVert-primVert distance vector (with lee-wick modification) ", 100, -10000,10000);
   
   ZZ_invMass = new TH1F ("ZZ_invMass", "track pair Invariant Mass (with some cut)", 100, 0 , 600);
   ZZ_dv = new TH1F ("ZZ_dv","Distance between track vertices ", 100, -20,20);
   ZZ_dx = new TH1F ("ZZ_dx","Distance between track vertices ", 100, -20,20);
   ZZ_dy = new TH1F ("ZZ_dy","Distance between track vertices ", 100, -20,20);
   ZZ_dz = new TH1F ("ZZ_dz","Distance between track vertices ", 100, -20,20);
   ZZ_dot = new TH1F ("ZZ_dot","Dot product between lepton pair momentum and secVert-primVert distance vector ", 100, -20,20);
   ZZ_dotLeeWick = new TH1F ("ZZ_dotLeeWick","Dot product between lepton pair momentum and secVert-primVert distance vector (with lee-wick modification) ", 100, -20,20);
   
   WW_invMass = new TH1F ("WW_invMass", "track pair Invariant Mass (with some cut)", 100, 0 , 600);
   WW_dv = new TH1F ("WW_dv","Distance between track vertices ", 100, -20,20);
   WW_dx = new TH1F ("WW_dx","Distance between track vertices ", 100, -20,20);
   WW_dy = new TH1F ("WW_dy","Distance between track vertices ", 100, -20,20);
   WW_dz = new TH1F ("WW_dz","Distance between track vertices ", 100, -20,20);
   WW_dot = new TH1F ("WW_dot","Dot product between lepton pair momentum and secVert-primVert distance vector ", 100, -20,20);
   WW_dotLeeWick = new TH1F ("WW_dotLeeWick","Dot product between lepton pair momentum and secVert-primVert distance vector (with lee-wick modification) ", 100, -20,20);
 
  //matchedTrack[ = {0};
   TH1::AddDirectory(true);
   int  vuelta = 0;
}

void vertexDistanceAnalyzer::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

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

// *** Lee wick mod

for (int i = 0; i< Ev_Branch_numTrack; i ++)
{
	track_px[i] = -track_px[i];
	track_py[i] = -track_py[i];
	track_pz[i] = -track_pz[i];
}


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
//repito para ZZ
double ZZdumGenMuPt;
if (ZZgenMu_pt[0] < ZZgenMu_pt[1])
{
	ZZdumGenMuPt =  ZZgenMu_pt[0];
	ZZgenMu_pt[0] = ZZgenMu_pt[1];
	ZZgenMu_pt[1] = ZZdumGenMuPt;
	
	ZZdumGenMuPt =  ZZgenMuBar_pt[0];
	ZZgenMuBar_pt[0] = ZZgenMuBar_pt[1];
	ZZgenMuBar_pt[1] = ZZdumGenMuPt;
	
}
//repito para WW
double WWdumGenMuPt;
if (WWgenMu_pt[0] < WWgenMu_pt[1])
{
	WWdumGenMuPt =  WWgenMu_pt[0];
	WWgenMu_pt[0] = WWgenMu_pt[1];
	WWgenMu_pt[1] = WWdumGenMuPt;
	
	WWdumGenMuPt =  WWgenMuBar_pt[0];
	WWgenMuBar_pt[0] = WWgenMuBar_pt[1];
	WWgenMuBar_pt[1] = WWdumGenMuPt;
	
}




bool altCompare = false;

if (genMuBar_pt[0] < genMuBar_pt[1])
{
	altCompare = true;
}
double iM, iM2, vertDis, dot;


// printing to check errors


/*cout<<"tracks: "<<track_pt[gPtIndexPos[0]]<<" "<<track_pt[gPtIndexPos[1]]<<" "<<track_pt[gPtIndexNeg[0]]<<" "<<track_pt[gPtIndexNeg[1]]<<endl;
cout<<"genZZ:  "<<ZZgenMuBar_pt[0]<<" "<<ZZgenMuBar_pt[1]<<" "<<ZZgenMu_pt[0]<<" "<<ZZgenMu_pt[1]<<endl;
cout<<"genZZ:  "<<genMuBar_pt[0]<<" "<<genMuBar_pt[1]<<" "<<genMu_pt[0]<<" "<<genMu_pt[1]<<endl;*/

// end error check


bool sw = false;



int interval = 400;
int lxyDist = 8;
sw = ZZMuWasFound && ZZMuBarWasFound;
if (ZZMuBarWasFound)
cout<<ZZMuWasFound<<" "<<ZZMuBarWasFound<<" "<<sw<<endl;
double lxyCut = 8.0;
if (! altCompare)
{   
	
	
	double p1[3], p2[3], pV[3], sv1[3], sv2[3], dot, dotL;
	
	p1[0] = track_px[gPtIndexPos[0]];
	p1[1] = track_py[gPtIndexPos[0]];
	p1[2] = track_pz[gPtIndexPos[0]];
    
    p2[0] = track_px[gPtIndexNeg[0]];
	p2[1] = track_py[gPtIndexNeg[0]];
	p2[2] = track_pz[gPtIndexNeg[0]];
	
	sv1[0] = track_vx[gPtIndexPos[0]];
	sv1[1] = track_vy[gPtIndexPos[0]];
	sv1[2] = track_vz[gPtIndexPos[0]];
	
	sv2[0] = track_vx[gPtIndexNeg[0]];
	sv2[1] = track_vy[gPtIndexNeg[0]];
	sv2[2] = track_vz[gPtIndexNeg[0]];
	
	pV[0] = genVert[0];
	pV[1] = genVert[1];
	pV[2] = genVert[2];
if (track_pt[gPtIndexPos[0]]>33 ) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMassFull->Fill(iM);
	
	
   }
	
	// inv mas histograms are filled
	if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < 0 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass1->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*2 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass2->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*3 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass3->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*4 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass4->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*5 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass5->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*6 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass6->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*7 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass7->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*8 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass8->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*9 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass9->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*10 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass10->Fill(iM);
	
	
   }

	
	
   
	 
	 if(iM >  300 && iM <400 ){
		  vertDis = deltaV(track_vx[gPtIndexPos[0]], track_vy[gPtIndexPos[0]], track_vz[gPtIndexPos[0]],track_vx[gPtIndexNeg[0]], track_vy[gPtIndexNeg[0]], track_vz[gPtIndexNeg[0]]);
    t_dv->Fill(vertDis);
	
	 
	t_dx->Fill(track_vx[gPtIndexPos[0]]-track_vx[gPtIndexNeg[0]]);
	t_dy->Fill(track_vy[gPtIndexPos[0]]-track_vy[gPtIndexNeg[0]]);
	t_dz->Fill(track_vz[gPtIndexPos[0]]-track_vz[gPtIndexNeg[0]]);
	
	
	double p1[3], p2[3], pV[3], sv1[3], sv2[3], dot, dotL;
	
	p1[0] = track_px[gPtIndexPos[0]];
	p1[1] = track_py[gPtIndexPos[0]];
	p1[2] = track_pz[gPtIndexPos[0]];
    
    p2[0] = track_px[gPtIndexNeg[0]];
	p2[1] = track_py[gPtIndexNeg[0]];
	p2[2] = track_pz[gPtIndexNeg[0]];
	
	sv1[0] = track_vx[gPtIndexPos[0]];
	sv1[1] = track_vy[gPtIndexPos[0]];
	sv1[2] = track_vz[gPtIndexPos[0]];
	
	sv2[0] = track_vx[gPtIndexNeg[0]];
	sv2[1] = track_vy[gPtIndexNeg[0]];
	sv2[2] = track_vz[gPtIndexNeg[0]];
	
	pV[0] = genVert[0];
	pV[1] = genVert[1];
	pV[2] = genVert[2];
	
    /*pV[0] = vertex_x[0];
	pV[1] = vertex_y[0];
	pV[2] = vertex_z[0];*/
    
    dot = dotP(pV,sv1,sv2,p1,p2);
    
    if (true)
    {
		iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMassCut->Fill(iM);
	}
    
    dotL = dotPLW(pV,sv1,sv2,p1,p2);
    
    t_dot->Fill(dot);
    t_dotLeeWick->Fill(dotL);
    
       if (track_lxy1[gPtIndex[0]]/track_lxy1Error[gPtIndexPos[0]]> lxyCut)
    {
		t_dotCut->Fill(dot);
		t_dotLeeWickCut->Fill(dotL);
	}
	
	
    
   
	
	
			}
			
	
	
double p1[3], p2[3], pV[3], sv1[3], sv2[3], dot, dotL;
	
	p1[0] = track_px[gPtIndexPos[1]];
	p1[1] = track_py[gPtIndexPos[1]];
	p1[2] = track_pz[gPtIndexPos[1]];
    
    p2[0] = track_px[gPtIndexNeg[1]];
	p2[1] = track_py[gPtIndexNeg[1]];
	p2[2] = track_pz[gPtIndexNeg[1]];
	
	sv1[0] = track_vx[gPtIndexPos[1]];
	sv1[1] = track_vy[gPtIndexPos[1]];
	sv1[2] = track_vz[gPtIndexPos[1]];
	
	sv2[0] = track_vx[gPtIndexNeg[1]];
	sv2[1] = track_vy[gPtIndexNeg[1]];
	sv2[2] = track_vz[gPtIndexNeg[1]];
	
	pV[0] = genVert[0];
	pV[1] = genVert[1];
	pV[2] = genVert[2];
	
	
	
	if (track_pt[gPtIndexPos[1]]>33 ) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMassFull->Fill(iM);
	
	
   }
	
	// inv mas histograms are filled
	if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < 0 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass1->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*2 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass2->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*3 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass3->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*4 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass4->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*5 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass5->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*6 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass6->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*7 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass7->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*8 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass8->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*9 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass9->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*10 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass10->Fill(iM);
	
	
   }
   
	 
	 if(iM >  300 && iM <400 ){
		  vertDis = deltaV(track_vx[gPtIndexPos[1]], track_vy[gPtIndexPos[1]], track_vz[gPtIndexPos[1]],track_vx[gPtIndexNeg[1]], track_vy[gPtIndexNeg[1]], track_vz[gPtIndexNeg[1]]);
    t_dv->Fill(vertDis);
	
	 
	t_dx->Fill(track_vx[gPtIndexPos[1]]-track_vx[gPtIndexNeg[1]]);
	t_dy->Fill(track_vy[gPtIndexPos[1]]-track_vy[gPtIndexNeg[1]]);
	t_dz->Fill(track_vz[gPtIndexPos[1]]-track_vz[gPtIndexNeg[1]]);
	
	
	
    /*pV[0] = vertex_x[0];
	pV[1] = vertex_y[0];
	pV[2] = vertex_z[0];*/
    
    dot = dotP(pV,sv1,sv2,p1,p2);
    
    if (true)
    {
		iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMassCut->Fill(iM);
	}
    
    dotL = dotPLW(pV,sv1,sv2,p1,p2);
    
    t_dot->Fill(dot);
    
 
    t_dotLeeWick->Fill(dotL);
       if (track_lxy1[gPtIndex[1]]/track_lxy1Error[gPtIndexPos[1]]> lxyCut)
    {
		t_dotCut->Fill(dot);
		t_dotLeeWickCut->Fill(dotL);
	}
	
	
    
   
	
	
			}
}
  else
{  
	
  
	double p1[3], p2[3], pV[3], sv1[3], sv2[3], dot, dotL;
	
	p1[0] = track_px[gPtIndexPos[0]];
	p1[1] = track_py[gPtIndexPos[0]];
	p1[2] = track_pz[gPtIndexPos[0]];
    
    p2[0] = track_px[gPtIndexNeg[1]];
	p2[1] = track_py[gPtIndexNeg[1]];
	p2[2] = track_pz[gPtIndexNeg[1]];
	
	sv1[0] = track_vx[gPtIndexPos[0]];
	sv1[1] = track_vy[gPtIndexPos[0]];
	sv1[2] = track_vz[gPtIndexPos[0]];
	
	sv2[0] = track_vx[gPtIndexNeg[1]];
	sv2[1] = track_vy[gPtIndexNeg[1]];
	sv2[2] = track_vz[gPtIndexNeg[1]];
	
	pV[0] = genVert[0];
	pV[1] = genVert[1];
	pV[2] = genVert[2];
	
	if (track_pt[gPtIndexPos[0]]>33 ) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMassFull->Fill(iM);
	
	
   }
	
	// inv mas histograms are filled
	if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < 0 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass1->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*2 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass2->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*3 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass3->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*4 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass4->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*5 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass5->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*6 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass6->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*7 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass7->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*8 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass8->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*9 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass9->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[0]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*10 && track_lxy1[gPtIndexPos[0]]/track_lxyError[gPtIndexPos[0]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMass10->Fill(iM);
	
	
   }

	
   
	 
	 if(iM >  300 && iM <400){
		  vertDis = deltaV(track_vx[gPtIndexPos[0]], track_vy[gPtIndexPos[0]], track_vz[gPtIndexPos[0]],track_vx[gPtIndexNeg[1]], track_vy[gPtIndexNeg[1]], track_vz[gPtIndexNeg[1]]);
    t_dv->Fill(vertDis);
	
	 
	t_dx->Fill(track_vx[gPtIndexPos[0]]-track_vx[gPtIndexNeg[1]]);
	t_dy->Fill(track_vy[gPtIndexPos[0]]-track_vy[gPtIndexNeg[1]]);
	t_dz->Fill(track_vz[gPtIndexPos[0]]-track_vz[gPtIndexNeg[1]]);
	
	
	
    /*pV[0] = vertex_x[0];
	pV[1] = vertex_y[0];
	pV[2] = vertex_z[0];*/
    
    dot = dotP(pV,sv1,sv2,p1,p2);
    
    if (true)
    {
		iM = invMass(track_px[gPtIndexPos[0]], track_py[gPtIndexPos[0]], track_pz[gPtIndexPos[0]],track_px[gPtIndexNeg[1]], track_py[gPtIndexNeg[1]], track_pz[gPtIndexNeg[1]]);
	t_invMassCut->Fill(iM);
	}
    
    dotL = dotPLW(pV,sv1,sv2,p1,p2);
    
    t_dot->Fill(dot);
    
 
    t_dotLeeWick->Fill(dotL);
       if (track_lxy1[gPtIndex[0]]/track_lxy1Error[gPtIndexPos[0]]> lxyCut)
    {
		t_dotCut->Fill(dot);
		t_dotLeeWickCut->Fill(dotL);
	}
	
	
    
   
	
	
			}
			
		
		double p1[3], p2[3], pV[3], sv1[3], sv2[3], dot, dotL;
	
	p1[0] = track_px[gPtIndexPos[1]];
	p1[1] = track_py[gPtIndexPos[1]];
	p1[2] = track_pz[gPtIndexPos[1]];
    
    p2[0] = track_px[gPtIndexNeg[0]];
	p2[1] = track_py[gPtIndexNeg[0]];
	p2[2] = track_pz[gPtIndexNeg[0]];
	
	sv1[0] = track_vx[gPtIndexPos[1]];
	sv1[1] = track_vy[gPtIndexPos[1]];
	sv1[2] = track_vz[gPtIndexPos[1]];
	
	sv2[0] = track_vx[gPtIndexNeg[0]];
	sv2[1] = track_vy[gPtIndexNeg[0]];
	sv2[2] = track_vz[gPtIndexNeg[0]];
	
	pV[0] = genVert[0];
	pV[1] = genVert[1];
	pV[2] = genVert[2];
	
	if (track_pt[gPtIndexPos[1]]>33 ) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMassFull->Fill(iM);
	
	
   }
	
	// inv mas histograms are filled
	if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < 0 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass1->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*2 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass2->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*3 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass3->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*4 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass4->Fill(iM);
	
	
   }
   if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*5 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass5->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*6 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass6->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*7 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass7->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*8 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass8->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*9 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass9->Fill(iM);
	
	
   }
    if (track_pt[gPtIndexPos[1]]>33  && dotP(pV,sv1,sv2,p1,p2) < -interval*10 && track_lxy1[gPtIndexPos[1]]/track_lxyError[gPtIndexPos[1]] > lxyDist) {
	
	iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMass10->Fill(iM);
	
	
   }

	
   
	 
	 if(iM >  300 && iM <400){
		  vertDis = deltaV(track_vx[gPtIndexPos[1]], track_vy[gPtIndexPos[1]], track_vz[gPtIndexPos[1]],track_vx[gPtIndexNeg[0]], track_vy[gPtIndexNeg[0]], track_vz[gPtIndexNeg[0]]);
    t_dv->Fill(vertDis);
	
	 
	t_dx->Fill(track_vx[gPtIndexPos[1]]-track_vx[gPtIndexNeg[0]]);
	t_dy->Fill(track_vy[gPtIndexPos[1]]-track_vy[gPtIndexNeg[0]]);
	t_dz->Fill(track_vz[gPtIndexPos[1]]-track_vz[gPtIndexNeg[0]]);
	
	
	
	
    /*pV[0] = vertex_x[0];
	pV[1] = vertex_y[0];
	pV[2] = vertex_z[0];*/
    
    dot = dotP(pV,sv1,sv2,p1,p2);
    
    if (true)
    {
		iM = invMass(track_px[gPtIndexPos[1]], track_py[gPtIndexPos[1]], track_pz[gPtIndexPos[1]],track_px[gPtIndexNeg[0]], track_py[gPtIndexNeg[0]], track_pz[gPtIndexNeg[0]]);
	t_invMassCut->Fill(iM);
	}
    
    dotL = dotPLW(pV,sv1,sv2,p1,p2);
    
    t_dot->Fill(dot);
    
 
    t_dotLeeWick->Fill(dotL);
       if (track_lxy1[gPtIndex[1]]/track_lxy1Error[gPtIndexPos[1]]> lxyCut)
    {
		t_dotCut->Fill(dot);
		t_dotLeeWickCut->Fill(dotL);
	}
	
	
    
   
	
	
			}
}


nEvents->Fill(1); 
   return kTRUE;
}



double vertexDistanceAnalyzer::dotP(double pV[3], double sv1[3], double sv2[3], double p1[3], double p2[3])
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
	
	
	//dot = pTot[0]*vertV[0] +pTot[1]*vertV[1] + pTot[2]*vertV[2];
	dot = pTot[0]*vertV[0] +pTot[1]*vertV[1];
	//cout<<"normal "<<dot<<endl;
	return dot;
	
}

double vertexDistanceAnalyzer::dotPLW(double pV[3], double sv1[3], double sv2[3], double p1[3], double p2[3])
{
	double VAv[3], vertV[3], pTot[3], dot;
	
	for (int i = 0; i< 3; i++)
	{  
		pTot[i] = (p1[i] + p2[i]);
		
		VAv[i] = 0.5*(sv1[i] + sv2[i]);
		
		vertV[i] = -VAv[i] + pV[i];
	}
	// normalize pAv
	
	for (int i = 0; i<3; i++)
	{
		/*pTot[i] = pTot[i]/norm(pTot[0],pTot[1], pTot[2]);
		vertV[i] = vertV[i]/norm(vertV[0], vertV[1], vertV[2]);*/
		
		/*pTot[i] = pTot[i]/norm(pTot[0],pTot[1]);
		vertV[i] = vertV[i]/norm(vertV[0], vertV[1]);*/
	}
	
	
	//dot = pTot[0]*vertV[0] +pTot[1]*vertV[1] +pTot[2]*vertV[2];
	dot = pTot[0]*vertV[0] +pTot[1]*vertV[1];
	//cout<<"lw "<<dot<<endl;
	return dot;
	
}



double vertexDistanceAnalyzer::norm(double x, double y, double  z)
{
	return sqrt(x*x+y*y+z*z);
}

double vertexDistanceAnalyzer::norm(double x, double y)
{
	return sqrt(x*x+y*y);
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
double vertexDistanceAnalyzer::deltaV(double vx1, double vy1, double vz1, double vx2, double vy2, double vz2)
{
   double dx = vx1-vx2;
   double dy = vy1-vy2;
   double dz = vz1 - vz2;
   
   double dv = sqrt(dx*dx +dy*dy +dz*dz);
   return dv;	
}
void vertexDistanceAnalyzer::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void vertexDistanceAnalyzer::Terminate()
{
	
	file->Write();
	file->Close();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
