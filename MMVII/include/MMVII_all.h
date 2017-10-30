#ifndef _MMVII_ALL_H_
#define _MMVII_ALL_H_

// Header standar c++
#include "memory.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <vector>
#include <list>
// #include <algorithm> => put it in file requiring it as it seem to slow down compilation
#include<boost/optional.hpp>


namespace MMVII
{
//========== LIB EXTEN==============


//===========================================
#include "MMVII_AllClassDeclare.h"
// Header MMVII
// #include "TypeNum.h"
#include "MMVII_Sys.h"
#include "MMVII_Error.h"
#include "MMVII_memory.h"
#include "MMVII_util.h"



// Les class cPtxd, cPt1d, cPt2d
#include "MMVII_Ptxd.h"
#include "MMVII_Bench.h"
// 
#include "cMMVII_Appli.h"

// Les classe lies aux conversion vers des chaines, fichier ...
#include "MMVII_Stringifier.h"
template <class Type> class  cStrIO;

};

using namespace MMVII;


#endif //  _MMVII_ALL_H_
