//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr 27 07:54:21 2018 by ROOT version 5.32/00
// from TTree mtree/Ntuple
// found on file: exoticNtuple.root
//////////////////////////////////////////////////////////

#ifndef vertexDistanceAnalyzer_h
#define vertexDistanceAnalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class vertexDistanceAnalyzer : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
          
   Int_t           Ev_Branch_eventNumber;
   Int_t           Ev_Branch_runNumber;
   Int_t           Ev_Branch_lumiBlock;
   Int_t           Ev_Branch_numTrack;
   Int_t           Ev_Branch_numTrigObjE;
   Int_t           Ev_Branch_numTrigObjM;
   Int_t           Ev_Branch_numJets;
   Int_t           Ev_Branch_numVert;
   Bool_t          Ev_Branch_wasTriggerFound;
   Int_t           Ev_Branch_triggerFound;
   Int_t           vert_numTrack[3];   //[numVert]
   Double_t        track_pt[2000];   //[numTrack]
   Double_t        track_ptError[2000];   //[numTrack]
   Double_t        track_px[2000];   //[numTrack]
   Double_t        track_py[2000];   //[numTrack]
   Double_t        track_pz[2000];   //[numTrack]
   Double_t        track_vx[2000];   //[numTrack]
   Double_t        track_vy[2000];   //[numTrack]
   Double_t        track_vz[2000];   //[numTrack]
   Double_t        track_chi2[2000];   //[numTrack]
   Int_t           track_ndof[2000];   //[numTrack]
   Double_t        track_eta[2000];   //[numTrack]
   Double_t        track_etaError[2000];   //[numTrack]
   Double_t        track_phi[2000];   //[numTrack]
   Double_t        track_phiError[2000];   //[numTrack]
   Int_t           track_nHits[2000];   //[numTrack]
   Int_t           track_found[2000];   //[numTrack]
   Int_t           track_n3DHits[2000];   //[numTrack]
   Double_t        track_dxy[2000];   //[numTrack]
   Double_t        track_dxyError[2000];   //[numTrack]
   Double_t        track_lxy1[2000];   //[numTrack]
   Double_t        track_lxy1Error[2000];   //[numTrack]
   Double_t        track_lxy2[2000];   //[numTrack]
   Double_t        track_lxy2Error[2000];   //[numTrack]
   Double_t        track_lxy3[2000];   //[numTrack]
   Double_t        track_lxyError[2000];   //[numTrack]
   Double_t        track_dz[2000];   //[numTrack]
   Double_t        track_dzError[2000];   //[numTrack]
   Int_t           track_charge[2000];   //[numTrack]
   Bool_t          track_highPurity[2000];   //[numTrack]
   Bool_t          track_tight[2000];   //[numTrack]
   Bool_t          track_loose[2000];   //[numTrack]
   Int_t           track_matchedVertIndex[2000];   //[numTrack]
   Double_t        trigObjE_pt[2];   //[numTrigObjE]
   Double_t        trigObjE_px[2];   //[numTrigObjE]
   Double_t        trigObjE_py[2];   //[numTrigObjE]
   Double_t        trigObjE_pz[2];   //[numTrigObjE]
   Double_t        trigObjE_eta[2];   //[numTrigObjE]
   Double_t        trigObjE_phi[2];   //[numTrigObjE]
   Bool_t          triggerEActivated;
   Bool_t          trigObjE_energy[2];   //[numTrigObjE]
   Double_t        trigObjM_pt[4];   //[numTrigObjM]
   Double_t        trigObjM_px[4];   //[numTrigObjM]
   Double_t        trigObjM_py[4];   //[numTrigObjM]
   Double_t        trigObjM_pz[4];   //[numTrigObjM]
   Double_t        trigObjM_eta[4];   //[numTrigObjM]
   Double_t        trigObjM_phi[4];   //[numTrigObjM]
   Bool_t          triggerMActivated;
   Bool_t          trigObjM_energy[4];   //[numTrigObjM]
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
   Double_t        vertex_chi2[3];   //[numVert]
   Double_t        vertex_ndof[3];   //[numVert]
   Double_t        vertex_x[3];   //[numVert]
   Double_t        vertex_y[3];   //[numVert]
   Double_t        vertex_z[3];   //[numVert]
   Double_t        vertex_xError[3];   //[numVert]
   Double_t        vertex_yError[3];   //[numVert]
   Double_t        vertex_zError[3];   //[numVert]
   Double_t        vertex_nTracks[3];   //[numVert]
   Double_t        ak5jet_x[31];   //[numJets]
   Double_t        ak5jet_y[31];   //[numJets]
   Double_t        ak5jet_z[31];   //[numJets]
   Double_t        ak5jet_pt[31];   //[numJets]
   Double_t        ak5jet_px[31];   //[numJets]
   Double_t        ak5jet_py[31];   //[numJets]
   Double_t        ak5jet_pz[31];   //[numJets]
   Double_t        ak5jet_phi[31];   //[numJets]
   Double_t        ak5jet_eta[31];   //[numJets]
   Double_t        ak5jet_mass[31];   //[numJets]
   Double_t        genMu_phi[2];
   Double_t        genMu_eta[2];
   Double_t        genMu_pt[2];
   Double_t        genMu_px[2];
   Double_t        genMu_py[2];
   Double_t        genMu_pz[2];
   Double_t        genMuBar_phi[2];
   Double_t        genMuBar_eta[2];
   Double_t        genMuBar_pt[2];
   Double_t        genMuBar_px[2];
   Double_t        genMuBar_py[2];
   Double_t        genMuBar_pz[2];
   Char_t          triggerPath[100];


  // Additional variables
  Int_t 		   matchedTrack[2000];
  Int_t 		   matchedTrigObj[2000];
  Int_t 		   trackTrigObjIndex[2000];
  int vuelta;
  // root file
  TH1F * h_dv;
  TH1F * h_dx;
  TH1F * h_dy;
  TH1F * h_dz;
  TH1F * h_mpt;
  TH1F * h_dm;
  TFile * file;
  
  // Histograms
  TH1F * nEvents;  
  TH1F * h_invMass;
  TH1F * h_lxy_err;
  TH1F * h_lxy2_err;
  TH1F * h_lxy;
  TH1F * h_d0_err;
  TH1F * h_conePt;
  
  // histograms with cuts
  
  TH1F * c_invMass;
  TH1F * c_pt;
  TH1F * c_phi;
  TH1F * c_eta;
  TH1F * c_dv;
  
  TH1F * cc_invMass;
  TH1F * cc_pt;
  TH1F * cc_phi;
  TH1F * cc_eta;
  TH1F * cc_dv;


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
   TBranch        *b_trigObjE_pt;   //!
   TBranch        *b_trigObjE_px;   //!
   TBranch        *b_trigObjE_py;   //!
   TBranch        *b_trigObjE_pz;   //!
   TBranch        *b_trigObjE_eta;   //!
   TBranch        *b_trigObjE_phi;   //!
   TBranch        *b_triggerEActivated;   //!
   TBranch        *b_trigObjE_energy;   //!
   TBranch        *b_trigObjM_pt;   //!
   TBranch        *b_trigObjM_px;   //!
   TBranch        *b_trigObjM_py;   //!
   TBranch        *b_trigObjM_pz;   //!
   TBranch        *b_trigObjM_eta;   //!
   TBranch        *b_trigObjM_phi;   //!
   TBranch        *b_triggerMActivated;   //!
   TBranch        *b_trigObjM_energy;   //!
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
   TBranch        *b_ak5jet_mass;   //!
   TBranch        *b_genMu_phi;   //!
   TBranch        *b_genMu_eta;   //!
   TBranch        *b_genMu_pt;   //!
   TBranch        *b_genMu_px;   //!
   TBranch        *b_genMu_py;   //!
   TBranch        *b_genMu_pz;   //!
   TBranch        *b_genMuBar_phi;   //!
   TBranch        *b_genMuBar_eta;   //!
   TBranch        *b_genMuBar_pt;   //!
   TBranch        *b_genMuBar_px;   //!
   TBranch        *b_genMuBar_py;   //!
   TBranch        *b_genMuBar_pz;   //!
   TBranch        *b_triggerPath;   //!

   vertexDistanceAnalyzer(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~vertexDistanceAnalyzer() { }
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

   ClassDef(vertexDistanceAnalyzer,0);
};

#endif

#ifdef vertexDistanceAnalyzer_cxx
void vertexDistanceAnalyzer::Init(TTree *tree)
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
   fChain->SetBranchAddress("track_dxyError", track_dxyError, &b_track_dxyError);
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
   fChain->SetBranchAddress("trigObjE_pt", trigObjE_pt, &b_trigObjE_pt);
   fChain->SetBranchAddress("trigObjE_px", trigObjE_px, &b_trigObjE_px);
   fChain->SetBranchAddress("trigObjE_py", trigObjE_py, &b_trigObjE_py);
   fChain->SetBranchAddress("trigObjE_pz", trigObjE_pz, &b_trigObjE_pz);
   fChain->SetBranchAddress("trigObjE_eta", trigObjE_eta, &b_trigObjE_eta);
   fChain->SetBranchAddress("trigObjE_phi", trigObjE_phi, &b_trigObjE_phi);
   fChain->SetBranchAddress("triggerEActivated", &triggerEActivated, &b_triggerEActivated);
   fChain->SetBranchAddress("trigObjE_energy", trigObjE_energy, &b_trigObjE_energy);
   fChain->SetBranchAddress("trigObjM_pt", trigObjM_pt, &b_trigObjM_pt);
   fChain->SetBranchAddress("trigObjM_px", trigObjM_px, &b_trigObjM_px);
   fChain->SetBranchAddress("trigObjM_py", trigObjM_py, &b_trigObjM_py);
   fChain->SetBranchAddress("trigObjM_pz", trigObjM_pz, &b_trigObjM_pz);
   fChain->SetBranchAddress("trigObjM_eta", trigObjM_eta, &b_trigObjM_eta);
   fChain->SetBranchAddress("trigObjM_phi", trigObjM_phi, &b_trigObjM_phi);
   fChain->SetBranchAddress("triggerMActivated", &triggerMActivated, &b_triggerMActivated);
   fChain->SetBranchAddress("trigObjM_energy", trigObjM_energy, &b_trigObjM_energy);
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
   fChain->SetBranchAddress("ak5jet_mass", ak5jet_mass, &b_ak5jet_mass);
   fChain->SetBranchAddress("genMu_phi", genMu_phi, &b_genMu_phi);
   fChain->SetBranchAddress("genMu_eta", genMu_eta, &b_genMu_eta);
   fChain->SetBranchAddress("genMu_pt", genMu_pt, &b_genMu_pt);
   fChain->SetBranchAddress("genMu_px", genMu_px, &b_genMu_px);
   fChain->SetBranchAddress("genMu_py", genMu_py, &b_genMu_py);
   fChain->SetBranchAddress("genMu_pz", genMu_pz, &b_genMu_pz);
   fChain->SetBranchAddress("genMuBar_phi", genMuBar_phi, &b_genMuBar_phi);
   fChain->SetBranchAddress("genMuBar_eta", genMuBar_eta, &b_genMuBar_eta);
   fChain->SetBranchAddress("genMuBar_pt", genMuBar_pt, &b_genMuBar_pt);
   fChain->SetBranchAddress("genMuBar_px", genMuBar_px, &b_genMuBar_px);
   fChain->SetBranchAddress("genMuBar_py", genMuBar_py, &b_genMuBar_py);
   fChain->SetBranchAddress("genMuBar_pz", genMuBar_pz, &b_genMuBar_pz);
   fChain->SetBranchAddress("triggerPath", triggerPath, &b_triggerPath);
}

Bool_t vertexDistanceAnalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef vertexDistanceAnalyzer_cxx
