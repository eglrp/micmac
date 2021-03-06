// File Automatically generated by eLiSe
#include "StdAfx.h"
#include "cREgDistVal_DRad_PPaEqPPs.h"


cREgDistVal_DRad_PPaEqPPs::cREgDistVal_DRad_PPaEqPPs():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("Intr",0,8));
   Close(false);
}



void cREgDistVal_DRad_PPaEqPPs::ComputeVal()
{
   double tmp0_ = mCompCoord[1];
   double tmp1_ = mLocRegDistValP1_x - tmp0_;
   double tmp2_ = mCompCoord[2];
   double tmp3_ = mLocRegDistValP1_y - tmp2_;
   double tmp4_ = (tmp1_) * (tmp1_);
   double tmp5_ = (tmp3_) * (tmp3_);
   double tmp6_ = tmp4_ + tmp5_;
   double tmp7_ = (tmp6_) * (tmp6_);
   double tmp8_ = tmp7_ * (tmp6_);
   double tmp9_ = tmp8_ * (tmp6_);
   double tmp10_ = mCompCoord[3];
   double tmp11_ = tmp10_ * (tmp6_);
   double tmp12_ = mCompCoord[4];
   double tmp13_ = tmp12_ * tmp7_;
   double tmp14_ = tmp11_ + tmp13_;
   double tmp15_ = mCompCoord[5];
   double tmp16_ = tmp15_ * tmp8_;
   double tmp17_ = tmp14_ + tmp16_;
   double tmp18_ = mCompCoord[6];
   double tmp19_ = tmp18_ * tmp9_;
   double tmp20_ = tmp17_ + tmp19_;
   double tmp21_ = mCompCoord[7];
   double tmp22_ = tmp9_ * (tmp6_);
   double tmp23_ = tmp21_ * tmp22_;
   double tmp24_ = tmp20_ + tmp23_;

  mVal[0] = (mLocRegDistValP1_x + (tmp1_) * (tmp24_)) - mLocRegDistKnownVal_x;

  mVal[1] = (mLocRegDistValP1_y + (tmp3_) * (tmp24_)) - mLocRegDistKnownVal_y;

}


void cREgDistVal_DRad_PPaEqPPs::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[1];
   double tmp1_ = mLocRegDistValP1_x - tmp0_;
   double tmp2_ = mCompCoord[2];
   double tmp3_ = mLocRegDistValP1_y - tmp2_;
   double tmp4_ = (tmp1_) * (tmp1_);
   double tmp5_ = (tmp3_) * (tmp3_);
   double tmp6_ = tmp4_ + tmp5_;
   double tmp7_ = (tmp6_) * (tmp6_);
   double tmp8_ = tmp7_ * (tmp6_);
   double tmp9_ = tmp8_ * (tmp6_);
   double tmp10_ = mCompCoord[3];
   double tmp11_ = tmp10_ * (tmp6_);
   double tmp12_ = mCompCoord[4];
   double tmp13_ = tmp12_ * tmp7_;
   double tmp14_ = tmp11_ + tmp13_;
   double tmp15_ = mCompCoord[5];
   double tmp16_ = tmp15_ * tmp8_;
   double tmp17_ = tmp14_ + tmp16_;
   double tmp18_ = mCompCoord[6];
   double tmp19_ = tmp18_ * tmp9_;
   double tmp20_ = tmp17_ + tmp19_;
   double tmp21_ = mCompCoord[7];
   double tmp22_ = tmp9_ * (tmp6_);
   double tmp23_ = tmp21_ * tmp22_;
   double tmp24_ = tmp20_ + tmp23_;
   double tmp25_ = -(1);
   double tmp26_ = tmp25_ * (tmp1_);
   double tmp27_ = tmp26_ + tmp26_;
   double tmp28_ = (tmp27_) * (tmp6_);
   double tmp29_ = tmp28_ + tmp28_;
   double tmp30_ = (tmp29_) * (tmp6_);
   double tmp31_ = (tmp27_) * tmp7_;
   double tmp32_ = tmp30_ + tmp31_;
   double tmp33_ = (tmp32_) * (tmp6_);
   double tmp34_ = (tmp27_) * tmp8_;
   double tmp35_ = tmp33_ + tmp34_;
   double tmp36_ = tmp25_ * (tmp3_);
   double tmp37_ = tmp36_ + tmp36_;
   double tmp38_ = (tmp37_) * (tmp6_);
   double tmp39_ = tmp38_ + tmp38_;
   double tmp40_ = (tmp39_) * (tmp6_);
   double tmp41_ = (tmp37_) * tmp7_;
   double tmp42_ = tmp40_ + tmp41_;
   double tmp43_ = (tmp42_) * (tmp6_);
   double tmp44_ = (tmp37_) * tmp8_;
   double tmp45_ = tmp43_ + tmp44_;
   double tmp46_ = (tmp27_) * tmp10_;
   double tmp47_ = (tmp29_) * tmp12_;
   double tmp48_ = tmp46_ + tmp47_;
   double tmp49_ = (tmp32_) * tmp15_;
   double tmp50_ = tmp48_ + tmp49_;
   double tmp51_ = (tmp35_) * tmp18_;
   double tmp52_ = tmp50_ + tmp51_;
   double tmp53_ = (tmp35_) * (tmp6_);
   double tmp54_ = (tmp27_) * tmp9_;
   double tmp55_ = tmp53_ + tmp54_;
   double tmp56_ = (tmp55_) * tmp21_;
   double tmp57_ = tmp52_ + tmp56_;
   double tmp58_ = tmp25_ * (tmp24_);
   double tmp59_ = (tmp37_) * tmp10_;
   double tmp60_ = (tmp39_) * tmp12_;
   double tmp61_ = tmp59_ + tmp60_;
   double tmp62_ = (tmp42_) * tmp15_;
   double tmp63_ = tmp61_ + tmp62_;
   double tmp64_ = (tmp45_) * tmp18_;
   double tmp65_ = tmp63_ + tmp64_;
   double tmp66_ = (tmp45_) * (tmp6_);
   double tmp67_ = (tmp37_) * tmp9_;
   double tmp68_ = tmp66_ + tmp67_;
   double tmp69_ = (tmp68_) * tmp21_;
   double tmp70_ = tmp65_ + tmp69_;

  mVal[0] = (mLocRegDistValP1_x + (tmp1_) * (tmp24_)) - mLocRegDistKnownVal_x;

  mCompDer[0][0] = 0;
  mCompDer[0][1] = tmp58_ + (tmp57_) * (tmp1_);
  mCompDer[0][2] = (tmp70_) * (tmp1_);
  mCompDer[0][3] = (tmp6_) * (tmp1_);
  mCompDer[0][4] = tmp7_ * (tmp1_);
  mCompDer[0][5] = tmp8_ * (tmp1_);
  mCompDer[0][6] = tmp9_ * (tmp1_);
  mCompDer[0][7] = tmp22_ * (tmp1_);
  mVal[1] = (mLocRegDistValP1_y + (tmp3_) * (tmp24_)) - mLocRegDistKnownVal_y;

  mCompDer[1][0] = 0;
  mCompDer[1][1] = (tmp57_) * (tmp3_);
  mCompDer[1][2] = tmp58_ + (tmp70_) * (tmp3_);
  mCompDer[1][3] = (tmp6_) * (tmp3_);
  mCompDer[1][4] = tmp7_ * (tmp3_);
  mCompDer[1][5] = tmp8_ * (tmp3_);
  mCompDer[1][6] = tmp9_ * (tmp3_);
  mCompDer[1][7] = tmp22_ * (tmp3_);
}


void cREgDistVal_DRad_PPaEqPPs::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cREgDistVal_DRad_PPaEqPPs Has no Der Sec");
}

void cREgDistVal_DRad_PPaEqPPs::SetRegDistKnownVal_x(double aVal){ mLocRegDistKnownVal_x = aVal;}
void cREgDistVal_DRad_PPaEqPPs::SetRegDistKnownVal_y(double aVal){ mLocRegDistKnownVal_y = aVal;}
void cREgDistVal_DRad_PPaEqPPs::SetRegDistValP1_x(double aVal){ mLocRegDistValP1_x = aVal;}
void cREgDistVal_DRad_PPaEqPPs::SetRegDistValP1_y(double aVal){ mLocRegDistValP1_y = aVal;}



double * cREgDistVal_DRad_PPaEqPPs::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "RegDistKnownVal_x") return & mLocRegDistKnownVal_x;
   if (aName == "RegDistKnownVal_y") return & mLocRegDistKnownVal_y;
   if (aName == "RegDistValP1_x") return & mLocRegDistValP1_x;
   if (aName == "RegDistValP1_y") return & mLocRegDistValP1_y;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cREgDistVal_DRad_PPaEqPPs::mTheAuto("cREgDistVal_DRad_PPaEqPPs",cREgDistVal_DRad_PPaEqPPs::Alloc);


cElCompiledFonc *  cREgDistVal_DRad_PPaEqPPs::Alloc()
{  return new cREgDistVal_DRad_PPaEqPPs();
}


