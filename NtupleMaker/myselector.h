//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar  2 06:36:23 2018 by ROOT version 5.32/00
// from TTree mtree/Ntuple
// found on file: tuple.root
//////////////////////////////////////////////////////////

#ifndef myselector_h
#define myselector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class myselector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           Ev_Branch_entryMax;
   Int_t           Ev_Branch_numTrack;
   Int_t           Ev_Branch_numTrigObj;
   Int_t           Ev_Branch_numVertTrack;
   Int_t           Ev_Branch_numVert;
   Double_t        Ev_Branch_track_pt[343];   //[entryMax]
   Double_t        Ev_Branch_track_px[343];   //[entryMax]
   Double_t        Ev_Branch_track_pz[343];   //[entryMax]
   Double_t        Ev_Branch_track_py[343];   //[entryMax]
   Double_t        Ev_Branch_track_vx[343];   //[entryMax]
   Double_t        Ev_Branch_track_vy[343];   //[entryMax]
   Double_t        Ev_Branch_track_vz[343];   //[entryMax]
   Double_t        Ev_Branch_track_chi2[343];   //[entryMax]
   Double_t        Ev_Branch_track_eta[343];   //[entryMax]
   Double_t        Ev_Branch_track_phi[343];   //[entryMax]
   Double_t        Ev_Branch_track_nHits[343];   //[entryMax]
   Double_t        Ev_Branch_track_dxy[343];   //[entryMax]
   Double_t        Ev_Branch_track_dz[343];   //[entryMax]
   Double_t        Ev_Branch_track_charge[343];   //[entryMax]
   Double_t        Ev_Branch_trigObj_pt[343];   //[entryMax]
   Double_t        Ev_Branch_trigObj_px[343];   //[entryMax]
   Double_t        Ev_Branch_trigObj_pz[343];   //[entryMax]
   Double_t        Ev_Branch_trigObj_py[343];   //[entryMax]
   Double_t        Ev_Branch_trigObj_eta[343];   //[entryMax]
   Double_t        Ev_Branch_trigObj_phi[343];   //[entryMax]
   Double_t        Ev_Branch_trigObj_energy[343];   //[entryMax]
   Bool_t          Ev_Branch_triggerActivated;
   Double_t        Ev_Branch_vertexTrack_vx[343];   //[entryMax]
   Double_t        Ev_Branch_vertexTrack_vy[343];   //[entryMax]
   Double_t        Ev_Branch_vertexTrack_vz[343];   //[entryMax]
   Double_t        Ev_Branch_vertexTrack_nHits[343];   //[entryMax]
   Double_t        Ev_Branch_vertexTrack_chi2[343];   //[entryMax]

   // List of branches
   TBranch        *b_Ev_Branch;   //!

   myselector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~myselector() { }
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

   ClassDef(myselector,0);
};

#endif

#ifdef myselector_cxx
void myselector::Init(TTree *tree)
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

   fChain->SetBranchAddress("Ev_Branch", &Ev_Branch_entryMax, &b_Ev_Branch);
}

Bool_t myselector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef myselector_cxx
