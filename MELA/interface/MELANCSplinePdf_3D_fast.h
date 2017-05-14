#ifndef MELANCSPLINEPDF_3D_FAST
#define MELANCSPLINEPDF_3D_FAST

#include <vector>
#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooRealVar.h"
#include "RooAbsReal.h"
#include "MELANCSplinePdfCore.h"

class MELANCSplinePdf_3D_fast : public MELANCSplinePdfCore{
protected:
  T rangeYmin;
  T rangeYmax;
  T rangeZmin;
  T rangeZmax;

  RooRealProxy theYVar;
  RooRealProxy theZVar;
  std::vector<T> YList;
  std::vector<T> ZList;

  std::vector<std::vector<std::vector<T>>> FcnList;

  std::vector<T> kappaX;
  std::vector<T> kappaY;
  std::vector<T> kappaZ;
  std::vector<std::vector<
    std::vector<std::vector<
    std::vector<std::vector<T>>
    >>
    >> coefficients; // [ix][A_x,B_x,C_x,D_x][iy][A_x_y,B_x_y,C_x_y,D_x_y][iz][A_x_y_z,B_x_y_z,C_x_y_z,D_x_y_z]

public:
  MELANCSplinePdf_3D_fast();
  MELANCSplinePdf_3D_fast(
    const char* name,
    const char* title,
    RooAbsReal& inXVar,
    RooAbsReal& inYVar,
    RooAbsReal& inZVar,
    const std::vector<T>& inXList,
    const std::vector<T>& inYList,
    const std::vector<T>& inZList,
    const std::vector<std::vector<std::vector<T>>>& inFcnList,
    Bool_t inUseFloor=true,
    T inFloorEval=0,
    T inFloorInt=0
    );
  MELANCSplinePdf_3D_fast(const MELANCSplinePdf_3D_fast& other, const char* name=0);
	virtual TObject* clone(const char* newname)const { return new MELANCSplinePdf_3D_fast(*this, newname); }
	inline virtual ~MELANCSplinePdf_3D_fast(){}

  void setRangeValidity(const T valmin, const T valmax, const Int_t whichDirection);

  virtual Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const;
  virtual Double_t analyticalIntegral(Int_t code, const char* rangeName=0)const;

protected:
  virtual void emptyFcnList(){ std::vector<std::vector<std::vector<T>>> tmp; FcnList.swap(tmp); }

  unsigned int npointsY()const{ return YList.size(); }
  unsigned int npointsZ()const{ return ZList.size(); }

  virtual Int_t getWhichBin(const T& val, const Int_t whichDirection)const;
  virtual T getTVar(const std::vector<T>& kappas, const T& val, const Int_t& bin, const Int_t whichDirection)const;
  virtual void getKappas(std::vector<T>& kappas, const Int_t whichDirection);

  Bool_t testRangeValidity(const T& val, const Int_t whichDirection)const;
  void cropValueForRange(T& val, const Int_t whichDirection)const;

  virtual std::vector<std::vector<T>> getCoefficientsPerYPerZ(
    const std::vector<T>& kappaX, const TMatrix_t& xAinv,
    const Int_t& ybin, const Int_t& zbin,
    const Int_t xbin
    )const; // xbin can be -1, which means push all of them

  virtual T interpolateFcn(Int_t code, const char* rangeName=0)const;

  virtual Double_t evaluate()const;

};
 
#endif
