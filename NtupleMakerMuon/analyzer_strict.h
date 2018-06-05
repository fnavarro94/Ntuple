//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 28 22:24:21 2018 by ROOT version 5.32/00
// from TTree mtree/Ntuple
// found on file: muonsSimu.root
//////////////////////////////////////////////////////////

#ifndef analyzer_strict_h
#define analyzer_strict_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class analyzer_strict : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           Ev_Branch_eventNumber;
   Int_t           Ev_Branch_runNumber;
   Int_t           Ev_Branch_lumiBlock;
   Int_t           Ev_Branch_numTrack;
   
   Int_t           Ev_Branch_numTrigObj;
   Int_t           Ev_Branch_numJets;
   Int_t           Ev_Branch_numVert;
   Bool_t          Ev_Branch_wasTriggerFound;
   Int_t           Ev_Branch_triggerFound;
   Int_t           vert_numTrack[6];   //[numVert]
   Double_t        track_pt[20000];   //[numTrack]
   Double_t        track_ptError[20000];   //[numTrack]
   Double_t        track_px[20000];   //[numTrack]
   Double_t        track_py[20000];   //[numTrack]
   Double_t        track_pz[20000];   //[numTrack]
   Double_t        track_vx[20000];   //[numTrack]
   Double_t        track_vy[20000];   //[numTrack]
   Double_t        track_vz[20000];   //[numTrack]
   Double_t        track_chi2[20000];   //[numTrack]
   Int_t           track_ndof[20000];   //[numTrack]
   Double_t        track_eta[20000];   //[numTrack]
   Double_t        track_etaError[20000];   //[numTrack]
   Double_t        track_phi[20000];   //[numTrack]
   Double_t        track_phiError[20000];   //[numTrack]
   Int_t           track_nHits[20000];   //[numTrack]
   Int_t           track_found[20000];   //[numTrack]
   Int_t           track_n3DHits[20000];   //[numTrack]
   Double_t        track_dxy[20000];   //[numTrack]
   Double_t        track_dxyError[20000];   //[numTrack]
   Double_t        track_d0[20000];   //[numTrack]
   Double_t        track_d0Error[20000];   //[numTrack]
   Double_t        track_lxy1[20000];   //[numTrack]
   Double_t        track_lxy1Error[20000];   //[numTrack]
   Double_t        track_lxy2[20000];   //[numTrack]
   Double_t        track_lxy2Error[20000];   //[numTrack]
   Double_t        track_lxy3[20000];   //[numTrack]
   Double_t        track_lxyError[20000];   //[numTrack]
   Double_t        track_dz[20000];   //[numTrack]
   Double_t        track_dzError[20000];   //[numTrack]
   Int_t           track_charge[20000];   //[numTrack]
   Bool_t          track_highPurity[20000];   //[numTrack]
   Bool_t          track_tight[20000];   //[numTrack]
   Bool_t          track_loose[20000];   //[numTrack]
   Int_t           track_matchedVertIndex[20000];   //[numTrack]
  
   Double_t        trigObj_pt[100];   //[numTrigObjM]
   Double_t        trigObj_px[100];   //[numTrigObjM]
   Double_t        trigObj_py[100];   //[numTrigObjM]
   Double_t        trigObj_pz[100];   //[numTrigObjM]
   Double_t        trigObj_eta[100];   //[numTrigObjM]
   Double_t        trigObj_phi[100];   //[numTrigObjM]
   Bool_t          triggerActivated;
   Bool_t          trigObj_energy[100];   //[numTrigObjM]
   Bool_t          trigObj_energy[100];   //[numTrigObjM]
   Double_t        vertex1Track_vx[6];   //[numVertTrack]
   Double_t        vertex1Track_vy[6];   //[numVertTrack]
   Double_t        vertex1Track_vz[6];   //[numVertTrack]
   Double_t        vertex2Track_vx[6];   //[numVertTrack]
   Double_t        vertex2Track_vy[6];   //[numVertTrack]
   Double_t        vertex2Track_vz[6];   //[numVertTrack]
   Double_t        vertex3Track_vx[6];   //[numVertTrack]
   Double_t        vertex3Track_vy[6];   //[numVertTrack]
   Double_t        vertex3Track_vz[6];   //[numVertTrack]
   Double_t        vertex4Track_vx[6];   //[numVertTrack]
   Double_t        vertex4Track_vy[6];   //[numVertTrack]
   Double_t        vertex4Track_vz[6];   //[numVertTrack]
   Double_t        vertex5Track_vx[6];   //[numVertTrack]
   Double_t        vertex5Track_vy[6];   //[numVertTrack]
   Double_t        vertex5Track_vz[6];   //[numVertTrack]
   Double_t        vertex6Track_vx[6];   //[numVertTrack]
   Double_t        vertex6Track_vy[6];   //[numVertTrack]
   Double_t        vertex6Track_vz[6];   //[numVertTrack]
   Double_t        matchedVertex_x[6];   //[numVertTrack]
   Double_t        matchedVertex_xError[6];   //[numVertTrack]
   Double_t        matchedVertex_y[6];   //[numVertTrack]
   Double_t        matchedVertex_yError[6];   //[numVertTrack]
   Double_t        matchedVertex_z[6];   //[numVertTrack]
   Double_t        matchedVertex_zError[6];   //[numVertTrack]
   Double_t        matchedVertex_chi2[6];   //[numVertTrack]
   Double_t        matchedVertex_ndof[6];   //[numVertTrack]
   Double_t        vertex_chi2[6];   //[numVert]
   Double_t        vertex_ndof[6];   //[numVert]
   Double_t        vertex_x[6];   //[numVert]
   Double_t        vertex_y[6];   //[numVert]
   Double_t        vertex_z[6];   //[numVert]
   Double_t        vertex_xError[6];   //[numVert]
   Double_t        vertex_yError[6];   //[numVert]
   Double_t        vertex_zError[6];   //[numVert]
   Double_t        vertex_nTracks[6];   //[numVert]
   Double_t        ak5jet_x[78];   //[numJets]
   Double_t        ak5jet_y[78];   //[numJets]
   Double_t        ak5jet_z[78];   //[numJets]
   Double_t        ak5jet_pt[78];   //[numJets]
   Double_t        ak5jet_px[78];   //[numJets]
   Double_t        ak5jet_py[78];   //[numJets]
   Double_t        ak5jet_pz[78];   //[numJets]
   Double_t        ak5jet_phi[78];   //[numJets]
   Double_t        ak5jet_eta[78];   //[numJets]
   Double_t        ak5jet_mass[78];   //[numJets]
   Char_t          triggerPath[100];

  // Additional variables
  Int_t 		   matchedTrack[20000];
  Int_t 		   matchedTrackLoose[20000];
  Int_t 		   matchedTrigObj[20000];
  Int_t 		   trackTrigObjIndex[20000];
  int vuelta;
  // root file
  int matchCount;
  int triggerTurnOns;
  int effCount;
  int triggerObjects;
  TFile * file;
  
  // Histograms
  TH1F * nEvents;  
  TH1F * h_invMassLoose;
  TH1F * h_invMass;
  TH1F * h_invMassLW;
  TH1F * h_lxy_errLoose;
  TH1F * h_lxy_err;
  TH1F * h_lxy2_err;
  TH1F * h_lxy;
  TH1F * h_lxyLoose;
  TH1F * h_d0_err;
  TH1F * h_d0_errLoose;
  TH1F * h_dxy_err;
  TH1F * h_dxy_errLoose;
  TH1F * h_conePt;
  TH1F * h_dot;
  TH1F * h_chi2_NDF;
  TH1F * h_chi2_NDFLoose;
  TH1F * h_delPhi;
  TH1F * h_delPhiLoose;
  TH1F * h_numHitsLoose;
  TH1F * h_cos;
  TH1F * h_cosLoose;
   // List of branches
   TBranch        *b_Ev_Branch;   //!
   TBranch        *b_vert_numTrack;   //!
   TBranch        *b_track_pt;   //!
   TBranch        *b_track_ptError;   //!
   TBranch        *b_track_px;   //!
   TBranch        *b_track_py;   //!
   TBranch        *b_track_pz;   //!
   TBranch        *b_track_vx;   //!
   TBranch        *b_track_vy;   //!
   TBranch        *b_track_vz;   //!
   TBranch        *b_track_chi2;   //!
   TBranch        *b_track_ndof;   //!
   TBranch        *b_track_eta;   //!
   TBranch        *b_track_etaError;   //!
   TBranch        *b_track_phi;   //!
   TBranch        *b_track_phiError;   //!
   TBranch        *b_track_nHits;   //!
   TBranch        *b_track_found;   //!
   TBranch        *b_track_n3DHits;   //!
   TBranch        *b_track_dxy;   //!
   TBranch        *b_track_dxyError;   //!
   TBranch        *b_track_d0;   //!
   TBranch        *b_track_d0Error;   //!
   TBranch        *b_track_lxy1;   //!
   TBranch        *b_track_lxy1Error;   //!
   TBranch        *b_track_lxy2;   //!
   TBranch        *b_track_lxy2Error;   //!
   TBranch        *b_track_lxy3;   //!
   TBranch        *b_track_lxyError;   //!
   TBranch        *b_track_dz;   //!
   TBranch        *b_track_dzError;   //!
   TBranch        *b_track_charge;   //!
   TBranch        *b_track_highPurity;   //!
   TBranch        *b_track_tight;   //!
   TBranch        *b_track_loose;   //!
   TBranch        *b_track_matchedVertIndex;   //!
   
   TBranch        *b_trigObj_pt;   //!
   TBranch        *b_trigObj_px;   //!
   TBranch        *b_trigObj_py;   //!
   TBranch        *b_trigObj_pz;   //!
   TBranch        *b_trigObj_eta;   //!
   TBranch        *b_trigObj_phi;   //!
   TBranch        *b_triggerActivated;   //!
   TBranch        *b_trigObj_energy;   //!
   TBranch        *b_vertex1Track_vx;   //!
   TBranch        *b_vertex1Track_vy;   //!
   TBranch        *b_vertex1Track_vz;   //!
   TBranch        *b_vertex2Track_vx;   //!
   TBranch        *b_vertex2Track_vy;   //!
   TBranch        *b_vertex2Track_vz;   //!
   TBranch        *b_vertex3Track_vx;   //!
   TBranch        *b_vertex3Track_vy;   //!
   TBranch        *b_vertex3Track_vz;   //!
   TBranch        *b_vertex4Track_vx;   //!
   TBranch        *b_vertex4Track_vy;   //!
   TBranch        *b_vertex4Track_vz;   //!
   TBranch        *b_vertex5Track_vx;   //!
   TBranch        *b_vertex5Track_vy;   //!
   TBranch        *b_vertex5Track_vz;   //!
   TBranch        *b_vertex6Track_vx;   //!
   TBranch        *b_vertex6Track_vy;   //!
   TBranch        *b_vertex6Track_vz;   //!
   TBranch        *b_matchedVertex_x;   //!
   TBranch        *b_matchedVertex_xError;   //!
   TBranch        *b_matchedVertex_y;   //!
   TBranch        *b_matchedVertex_yError;   //!
   TBranch        *b_matchedVertex_z;   //!
   TBranch        *b_matchedVertex_zError;   //!
   TBranch        *b_matchedVertex_chi2;   //!
   TBranch        *b_matchedVertex_ndof;   //!
   TBranch        *b_vertex_chi2;   //!
   TBranch        *b_vertex_ndof;   //!
   TBranch        *b_vertex_x;   //!
   TBranch        *b_vertex_y;   //!
   TBranch        *b_vertex_z;   //!
   TBranch        *b_vertex_xError;   //!
   TBranch        *b_vertex_yError;   //!
   TBranch        *b_vertex_zError;   //!
   TBranch        *b_vertex_nTracks;   //!
   TBranch        *b_ak5jet_x;   //!
   TBranch        *b_ak5jet_y;   //!
   TBranch        *b_ak5jet_z;   //!
   TBranch        *b_ak5jet_pt;   //!
   TBranch        *b_ak5jet_px;   //!
   TBranch        *b_ak5jet_py;   //!
   TBranch        *b_ak5jet_pz;   //!
   TBranch        *b_ak5jet_phi;   //!
   TBranch        *b_ak5jet_eta;   //!
   TBranch        *b_triggerPath;   //!

   analyzer_strict(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~analyzer_strict() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(analyzer_strict,0);
};

#endif

#ifdef analyzer_strict_cxx
void analyzer_strict::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Ev_Branch", &Ev_Branch_eventNumber, &b_Ev_Branch);
   fChain->SetBranchAddress("vert_numTrack", vert_numTrack, &b_vert_numTrack);
   fChain->SetBranchAddress("track_pt", track_pt, &b_track_pt);
   fChain->SetBranchAddress("track_ptError", track_ptError, &b_track_ptError);
   fChain->SetBranchAddress("track_px", track_px, &b_track_px);
   fChain->SetBranchAddress("track_py", track_py, &b_track_py);
   fChain->SetBranchAddress("track_pz", track_pz, &b_track_pz);
   fChain->SetBranchAddress("track_vx", track_vx, &b_track_vx);
   fChain->SetBranchAddress("track_vy", track_vy, &b_track_vy);
   fChain->SetBranchAddress("track_vz", track_vz, &b_track_vz);
   fChain->SetBranchAddress("track_chi2", track_chi2, &b_track_chi2);
   fChain->SetBranchAddress("track_ndof", track_ndof, &b_track_ndof);
   fChain->SetBranchAddress("track_eta", track_eta, &b_track_eta);
   fChain->SetBranchAddress("track_etaError", track_etaError, &b_track_etaError);
   fChain->SetBranchAddress("track_phi", track_phi, &b_track_phi);
   fChain->SetBranchAddress("track_phiError", track_phiError, &b_track_phiError);
   fChain->SetBranchAddress("track_nHits", track_nHits, &b_track_nHits);
   fChain->SetBranchAddress("track_found", track_found, &b_track_found);
   fChain->SetBranchAddress("track_n3DHits", track_n3DHits, &b_track_n3DHits);
   fChain->SetBranchAddress("track_dxy", track_dxy, &b_track_dxy);
   fChain->SetBranchAddress("track_dxyError", track_dxy, &b_track_dxy);
   fChain->SetBranchAddress("track_d0", track_d0, &b_track_d0);
   fChain->SetBranchAddress("track_d0Error", track_d0Error, &b_track_d0Error);
   fChain->SetBranchAddress("track_lxy1", track_lxy1, &b_track_lxy1);
   fChain->SetBranchAddress("track_lxy1Error", track_lxy1Error, &b_track_lxy1Error);
   fChain->SetBranchAddress("track_lxy2", track_lxy2, &b_track_lxy2);
   fChain->SetBranchAddress("track_lxy2Error", track_lxy2Error, &b_track_lxy2Error);
   fChain->SetBranchAddress("track_lxy3", track_lxy3, &b_track_lxy3);
   fChain->SetBranchAddress("track_lxyError", track_lxyError, &b_track_lxyError);
   fChain->SetBranchAddress("track_dz", track_dz, &b_track_dz);
   fChain->SetBranchAddress("track_dzError", track_dzError, &b_track_dzError);
   fChain->SetBranchAddress("track_charge", track_charge, &b_track_charge);
   fChain->SetBranchAddress("track_highPurity", track_highPurity, &b_track_highPurity);
   fChain->SetBranchAddress("track_tight", track_tight, &b_track_tight);
   fChain->SetBranchAddress("track_loose", track_loose, &b_track_loose);
   fChain->SetBranchAddress("track_matchedVertIndex", track_matchedVertIndex, &b_track_matchedVertIndex);
   
   
   fChain->SetBranchAddress("trigObj_pt", trigObj_pt, &b_trigObj_pt);
   fChain->SetBranchAddress("trigObj_px", trigObj_px, &b_trigObj_px);
   fChain->SetBranchAddress("trigObj_py", trigObj_py, &b_trigObj_py);
   fChain->SetBranchAddress("trigObj_pz", trigObj_pz, &b_trigObj_pz);
   fChain->SetBranchAddress("trigObj_eta", trigObj_eta, &b_trigObj_eta);
   fChain->SetBranchAddress("trigObj_phi", trigObj_phi, &b_trigObj_phi);
   fChain->SetBranchAddress("triggerActivated", &triggerActivated, &b_triggerActivated);
   fChain->SetBranchAddress("trigObj_energy", trigObj_energy, &b_trigObj_energy);
   fChain->SetBranchAddress("vertex1Track_vx", vertex1Track_vx, &b_vertex1Track_vx);
   fChain->SetBranchAddress("vertex1Track_vy", vertex1Track_vy, &b_vertex1Track_vy);
   fChain->SetBranchAddress("vertex1Track_vz", vertex1Track_vz, &b_vertex1Track_vz);
   fChain->SetBranchAddress("vertex2Track_vx", vertex2Track_vx, &b_vertex2Track_vx);
   fChain->SetBranchAddress("vertex2Track_vy", vertex2Track_vy, &b_vertex2Track_vy);
   fChain->SetBranchAddress("vertex2Track_vz", vertex2Track_vz, &b_vertex2Track_vz);
   fChain->SetBranchAddress("vertex3Track_vx", vertex3Track_vx, &b_vertex3Track_vx);
   fChain->SetBranchAddress("vertex3Track_vy", vertex3Track_vy, &b_vertex3Track_vy);
   fChain->SetBranchAddress("vertex3Track_vz", vertex3Track_vz, &b_vertex3Track_vz);
   fChain->SetBranchAddress("vertex4Track_vx", vertex4Track_vx, &b_vertex4Track_vx);
   fChain->SetBranchAddress("vertex4Track_vy", vertex4Track_vy, &b_vertex4Track_vy);
   fChain->SetBranchAddress("vertex4Track_vz", vertex4Track_vz, &b_vertex4Track_vz);
   fChain->SetBranchAddress("vertex5Track_vx", vertex5Track_vx, &b_vertex5Track_vx);
   fChain->SetBranchAddress("vertex5Track_vy", vertex5Track_vy, &b_vertex5Track_vy);
   fChain->SetBranchAddress("vertex5Track_vz", vertex5Track_vz, &b_vertex5Track_vz);
   fChain->SetBranchAddress("vertex6Track_vx", vertex6Track_vx, &b_vertex6Track_vx);
   fChain->SetBranchAddress("vertex6Track_vy", vertex6Track_vy, &b_vertex6Track_vy);
   fChain->SetBranchAddress("vertex6Track_vz", vertex6Track_vz, &b_vertex6Track_vz);
   fChain->SetBranchAddress("matchedVertex_x", matchedVertex_x, &b_matchedVertex_x);
   fChain->SetBranchAddress("matchedVertex_xError", matchedVertex_xError, &b_matchedVertex_xError);
   fChain->SetBranchAddress("matchedVertex_y", matchedVertex_y, &b_matchedVertex_y);
   fChain->SetBranchAddress("matchedVertex_yError", matchedVertex_yError, &b_matchedVertex_yError);
   fChain->SetBranchAddress("matchedVertex_z", matchedVertex_z, &b_matchedVertex_z);
   fChain->SetBranchAddress("matchedVertex_zError", matchedVertex_zError, &b_matchedVertex_zError);
   fChain->SetBranchAddress("matchedVertex_chi2", matchedVertex_chi2, &b_matchedVertex_chi2);
   fChain->SetBranchAddress("matchedVertex_ndof", matchedVertex_ndof, &b_matchedVertex_ndof);
   fChain->SetBranchAddress("vertex_chi2", vertex_chi2, &b_vertex_chi2);
   fChain->SetBranchAddress("vertex_ndof", vertex_ndof, &b_vertex_ndof);
   fChain->SetBranchAddress("vertex_x", vertex_x, &b_vertex_x);
   fChain->SetBranchAddress("vertex_y", vertex_y, &b_vertex_y);
   fChain->SetBranchAddress("vertex_z", vertex_z, &b_vertex_z);
   fChain->SetBranchAddress("vertex_xError", vertex_xError, &b_vertex_xError);
   fChain->SetBranchAddress("vertex_yError", vertex_yError, &b_vertex_yError);
   fChain->SetBranchAddress("vertex_zError", vertex_zError, &b_vertex_zError);
   fChain->SetBranchAddress("vertex_nTracks", vertex_nTracks, &b_vertex_nTracks);
   fChain->SetBranchAddress("ak5jet_x", ak5jet_x, &b_ak5jet_x);
   fChain->SetBranchAddress("ak5jet_y", ak5jet_y, &b_ak5jet_y);
   fChain->SetBranchAddress("ak5jet_z", ak5jet_z, &b_ak5jet_z);
   fChain->SetBranchAddress("ak5jet_pt", ak5jet_pt, &b_ak5jet_pt);
   fChain->SetBranchAddress("ak5jet_px", ak5jet_px, &b_ak5jet_px);
   fChain->SetBranchAddress("ak5jet_py", ak5jet_py, &b_ak5jet_py);
   fChain->SetBranchAddress("ak5jet_pz", ak5jet_pz, &b_ak5jet_pz);
   fChain->SetBranchAddress("ak5jet_phi", ak5jet_phi, &b_ak5jet_phi);
   fChain->SetBranchAddress("ak5jet_eta", ak5jet_eta, &b_ak5jet_eta);
   fChain->SetBranchAddress("triggerPath", triggerPath, &b_triggerPath);
}

Bool_t analyzer_strict::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef analyzer_strict_cxx
