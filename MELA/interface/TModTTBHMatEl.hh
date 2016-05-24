#ifndef _TMODTTBHMATEL_HH_
#define _TMODTTBHMATEL_HH_

extern "C" {
  void __modttbh_MOD_initprocess_ttbh();
//  void __modttbh_MOD_exitprocess_ttbh();
  void __modttbh_MOD_evalamp_gg_ttbh(double Ptth[13][4], double *MatElSq);
  void __modttbh_MOD_evalamp_qqb_ttbh(double Ptth[13][4], double *MatElSq);
  void __modttbh_MOD_evalxsec_pp_ttbh(double Ptth[13][4], int* SelectProcess, double MatElSq[11][11]);
  void __modttbh_MOD_evalxsec_pp_bbbh(double Ptth[13][4], int* SelectProcess, double MatElSq[11][11]);
}

#endif
