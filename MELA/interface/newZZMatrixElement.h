#ifndef newZZMatrixElement_newZZMatrixElement_h
#define newZZMatrixElement_newZZMatrixElement_h

#include <vector>
#include <TLorentzVector.h>
#include "ZZMatrixElement/MELA/interface/TVar.hh"
#include "ZZMatrixElement/MELA/interface/TEvtProb.hh"


class  newZZMatrixElement{
public:
  //pathtoHiggsCSandWidth: path to the textfiles of the HiggsCSandWidth package
  newZZMatrixElement(
    const char* pathtoPDFSet,
    int PDFMember,
    const char* pathtoHiggsCSandWidth,
    double ebeam,
    TVar::VerbosityLevel verbosity
    );

  ~newZZMatrixElement(){ /*std::cout << "End of newZZME" << std::endl;*/ };
  /// Compute KD from masses and angles.
  /// The user must ensure that the order of m1/m2 matches the order of theta1/theta2.
  // flavor 1 for 4e, 2 for 4m, 3 for 2e2mu
  void computeXS(float mZZ, float mZ1, float mZ2,
    float costhetastar,
    float costheta1,
    float costheta2,
    float phistar1,
    float phi,
    int flavor,
    TVar::Process process_,
    TVar::MatrixElement me_,
    TVar::Production production_,
    float &mevalue
    );

  void computeProdXS_VVHVV(
    TLorentzVector jet[2],
    TLorentzVector Higgs_daughter[4],
    int jet_pdgid[2],
    int Higgs_daughter_pdgid[4],
    TVar::Process process_,
    TVar::MatrixElement me_,
    TVar::Production production_,
    float& mevalue
    );

  void computeProdXS_JJH(TLorentzVector jet1,
    TLorentzVector jet2,
    TLorentzVector higgs,
    TVar::Process process_,
    TVar::MatrixElement me_,
    TVar::Production production_,
    float &mevalue
    );

  void computeProdXS_JH(TLorentzVector singleJet,
    TLorentzVector higgs,
    TVar::Process process_,
    TVar::MatrixElement me_,
    TVar::Production production_,
    float &mevalue
    );

  void computeProdXS_VH(
    TLorentzVector V_daughter[2],
    TLorentzVector Higgs_daughter[4],
    int V_daughter_pdgid[2],
    int Higgs_daughter_pdgid[4],
    bool includeHiggsDecay,
    TVar::Process process_,
    TVar::MatrixElement me_,
    TVar::Production production_,
    float &mevalue
    );

  void computeProdXS_ttH(
    TLorentzVector vTTH[6],
    TLorentzVector Higgs,
    int ttbar_daughters_pdgid[6],
    int topDecay,
    int topProcess,
    TVar::Process process_,
    TVar::MatrixElement me_,
    TVar::Production production_,
    float &mevalue);

  void set_Process(TVar::Process process_, TVar::MatrixElement me_, TVar::Production production_);
  void set_mHiggs(float myPoleMass);
  void set_wHiggs(float myPoleWidth);
  void set_LeptonInterference(TVar::LeptonInterference myLepInterf);
  void set_LHAgrid(const char* path, int pdfmember=0);
  void set_RenFacScaleMode(TVar::EventScaleScheme renormalizationSch, TVar::EventScaleScheme factorizationSch, double ren_sf, double fac_sf);
  void reset_MCFM_EWKParameters(double ext_Gf, double ext_aemmz, double ext_mW, double ext_mZ, double ext_xW, int ext_ewscheme=3);
  void resetPerEvent();

  void set_SpinZeroCouplings(
    double selfDHvvcoupl_freenorm[SIZE_HVV_FREENORM],
    double selfDHqqcoupl[SIZE_HQQ][2],
    double selfDHggcoupl[SIZE_HGG][2],
    double selfDHzzcoupl[SIZE_HVV][2],
    double selfDHwwcoupl[SIZE_HVV][2],
    double selfDHzzLambda_qsq[4][3],
    double selfDHwwLambda_qsq[4][3],
    int selfDHzzCLambda_qsq[3],
    int selfDHwwCLambda_qsq[3],
    bool diffHWW = false
    );
  void set_SpinZeroCouplings_NoGamma(
    double selfDHvvcoupl_freenorm[SIZE_HVV_FREENORM],
    double selfDHqqcoupl[SIZE_HQQ][2],
    double selfDHggcoupl[SIZE_HGG][2],
    double selfDHzzcoupl[SIZE_HVV_VBF][2],
    double selfDHwwcoupl[SIZE_HVV_VBF][2],
    double selfDHzzLambda_qsq[4][3],
    double selfDHwwLambda_qsq[4][3],
    int selfDHzzCLambda_qsq[3],
    int selfDHwwCLambda_qsq[3],
    bool diffHWW = false
    );
  void set_SpinOneCouplings(
    double selfDZqqcoupl[SIZE_ZQQ][2],
    double selfDZvvcoupl[SIZE_ZVV][2]
    );
  void set_SpinTwoCouplings(
    double selfDGqqcoupl[SIZE_GQQ][2],
    double selfDGggcoupl[SIZE_GGG][2],
    double selfDGvvcoupl[SIZE_GVV][2]
    );

  // Compute four-momenta from angles - not cos(theta) - only 
  std::vector<TLorentzVector> Calculate4Momentum(double Mx, double M1, double M2, double theta, double theta1, double theta2, double Phi1, double Phi);

  // Get-functions
  MelaIO* get_IORecord();

private:
  
  TVar::VerbosityLevel verb;
  TEvtProb Xcal2;
  hzz4l_event_type hzz4l_event;
  vh_event_type vh_event;
  tth_event_type tth_event;
  float mHiggs;
  float wHiggs;
  double EBEAM;
  TVar::Process myModel;
  TVar::MatrixElement myME;
  TVar::Production myProduction;
  TVar::LeptonInterference myLeptonInterference;

  SpinZeroCouplings* selfD_SpinZeroCouplings;
  SpinOneCouplings* selfD_SpinOneCouplings;
  SpinTwoCouplings* selfD_SpinTwoCouplings;

};
#endif
