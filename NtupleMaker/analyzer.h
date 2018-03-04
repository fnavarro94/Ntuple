//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Mar  4 05:44:10 2018 by ROOT version 5.32/00
// from TTree mtree/Ntuple
// found on file: tuple.root
//////////////////////////////////////////////////////////

#ifndef analyzer_h
#define analyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class analyzer : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           Ev_Branch_numTrack;
   Int_t           Ev_Branch_numTrigObj;
   Int_t           Ev_Branch_numVertTrack;
   Int_t           Ev_Branch_numVert;
   Double_t        track_pt[659];   //[numTrack]
   Double_t        track_px[659];   //[numTrack]
   Double_t        track_py[659];   //[numTrack]
   Double_t        track_pz[659];   //[numTrack]
   Double_t        track_vx[659];   //[numTrack]
   Double_t        track_vy[659];   //[numTrack]
   Double_t        track_vz[659];   //[numTrack]
   Double_t        track_chi2[659];   //[numTrack]
   Int_t           track_ndof[659];   //[numTrack]
   Double_t        track_eta[659];   //[numTrack]
   Double_t        track_phi[659];   //[numTrack]
   Int_t           track_nHits[659];   //[numTrack]
   Int_t           track_found[659];   //[numTrack]
   Double_t        track_dxy[659];   //[numTrack]
   Double_t        track_dxyError[659];   //[numTrack]
   Double_t        track_dz[659];   //[numTrack]
   Int_t           track_charge[659];   //[numTrack]
   Bool_t          track_highPurity[659];   //[numTrack]
   Bool_t          track_tight[659];   //[numTrack]
   Bool_t          track_loose[659];   //[numTrack]
   Double_t        trigObj_pt[3];   //[numTrigObj]
   Double_t        trigObj_px[3];   //[numTrigObj]
   Double_t        trigObj_py[3];   //[numTrigObj]
   Double_t        trigObj_pz[3];   //[numTrigObj]
   Double_t        trigObj_eta[3];   //[numTrigObj]
   Double_t        trigObj_phi[3];   //[numTrigObj]
   Bool_t          triggerActivated;
   Bool_t          trigObj_energy[3];   //[numTrigObj]
   Double_t        vertexTrack_vx[127];   //[numVertTrack]
   Double_t        vertexTrack_vy[127];   //[numVertTrack]
   Double_t        vertexTrack_vz[127];   //[numVertTrack]
   Int_t           vertexTrack_nHits[127];   //[numVertTrack]
   Double_t        vertexTrack_chi2[127];   //[numVertTrack]
   Double_t        vertex[16][6];   //[numVert]


 
  // Additional variables
  Int_t 		   matchedTrack[660];
  int vuelta;
  // root file
  
  TFile * file;
  
  // Histograms
  
  TH1F * h_invMass;


   // List of branches
   TBranch        *b_Ev_Branch;   //!
   TBranch        *b_track_pt;   //!
   TBranch        *b_track_px;   //!
   TBranch        *b_track_py;   //!
   TBranch        *b_track_pz;   //!
   TBranch        *b_track_vx;   //!
   TBranch        *b_track_vy;   //!
   TBranch        *b_track_vz;   //!
   TBranch        *b_track_chi2;   //!
   TBranch        *b_track_ndof;   //!
   TBranch        *b_track_eta;   //!
   TBranch        *b_track_phi;   //!
   TBranch        *b_track_nHits;   //!
   TBranch        *b_track_found;   //!
   TBranch        *b_track_dxy;   //!
   TBranch        *b_track_dxyError;   //!
   TBranch        *b_track_dz;   //!
   TBranch        *b_track_charge;   //!
   TBranch        *b_track_highPurity;   //!
   TBranch        *b_track_tight;   //!
   TBranch        *b_track_loose;   //!
   TBranch        *b_trigObj_pt;   //!
   TBranch        *b_trigObj_px;   //!
   TBranch        *b_trigObj_py;   //!
   TBranch        *b_trigObj_pz;   //!
   TBranch        *b_trigObj_eta;   //!
   TBranch        *b_trigObj_phi;   //!
   TBranch        *b_triggerActivated;   //!
   TBranch        *b_trigObj_energy;   //!
   TBranch        *b_vertexTrack_vx;   //!
   TBranch        *b_vertexTrack_vy;   //!
   TBranch        *b_vertexTrack_vz;   //!
   TBranch        *b_vertexTrack_nHits;   //!
   TBranch        *b_vertexTrack_chi2;   //!
   TBranch        *b_vertex;   //!

   analyzer(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~analyzer() { }
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

   ClassDef(analyzer,0);
};

#endif

#ifdef analyzer_cxx
void analyzer::Init(TTree *tree)
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

   fChain->SetBranchAddress("Ev_Branch", &Ev_Branch_numTrack, &b_Ev_Branch);
   fChain->SetBranchAddress("track_pt", track_pt, &b_track_pt);
   fChain->SetBranchAddress("track_px", track_px, &b_track_px);
   fChain->SetBranchAddress("track_py", track_py, &b_track_py);
   fChain->SetBranchAddress("track_pz", track_pz, &b_track_pz);
   fChain->SetBranchAddress("track_vx", track_vx, &b_track_vx);
   fChain->SetBranchAddress("track_vy", track_vy, &b_track_vy);
   fChain->SetBranchAddress("track_vz", track_vz, &b_track_vz);
   fChain->SetBranchAddress("track_chi2", track_chi2, &b_track_chi2);
   fChain->SetBranchAddress("track_ndof", track_ndof, &b_track_ndof);
   fChain->SetBranchAddress("track_eta", track_eta, &b_track_eta);
   fChain->SetBranchAddress("track_phi", track_phi, &b_track_phi);
   fChain->SetBranchAddress("track_nHits", track_nHits, &b_track_nHits);
   fChain->SetBranchAddress("track_found", track_found, &b_track_found);
   fChain->SetBranchAddress("track_dxy", track_dxy, &b_track_dxy);
   fChain->SetBranchAddress("track_dxyError", track_dxyError, &b_track_dxyError);
   fChain->SetBranchAddress("track_dz", track_dz, &b_track_dz);
   fChain->SetBranchAddress("track_charge", track_charge, &b_track_charge);
   fChain->SetBranchAddress("track_highPurity", track_highPurity, &b_track_highPurity);
   fChain->SetBranchAddress("track_tight", track_tight, &b_track_tight);
   fChain->SetBranchAddress("track_loose", track_loose, &b_track_loose);
   fChain->SetBranchAddress("trigObj_pt", trigObj_pt, &b_trigObj_pt);
   fChain->SetBranchAddress("trigObj_px", trigObj_px, &b_trigObj_px);
   fChain->SetBranchAddress("trigObj_py", trigObj_py, &b_trigObj_py);
   fChain->SetBranchAddress("trigObj_pz", trigObj_pz, &b_trigObj_pz);
   fChain->SetBranchAddress("trigObj_eta", trigObj_eta, &b_trigObj_eta);
   fChain->SetBranchAddress("trigObj_phi", trigObj_phi, &b_trigObj_phi);
   fChain->SetBranchAddress("triggerActivated", &triggerActivated, &b_triggerActivated);
   fChain->SetBranchAddress("trigObj_energy", trigObj_energy, &b_trigObj_energy);
   fChain->SetBranchAddress("vertexTrack_vx", vertexTrack_vx, &b_vertexTrack_vx);
   fChain->SetBranchAddress("vertexTrack_vy", vertexTrack_vy, &b_vertexTrack_vy);
   fChain->SetBranchAddress("vertexTrack_vz", vertexTrack_vz, &b_vertexTrack_vz);
   fChain->SetBranchAddress("vertexTrack_nHits", vertexTrack_nHits, &b_vertexTrack_nHits);
   fChain->SetBranchAddress("vertexTrack_chi2", vertexTrack_chi2, &b_vertexTrack_chi2);
   fChain->SetBranchAddress("vertex", vertex, &b_vertex);
}

Bool_t analyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef analyzer_cxx
