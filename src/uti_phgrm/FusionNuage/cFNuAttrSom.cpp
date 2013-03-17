/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in 
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte 
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/

#include "FusionNuage.h"

cFNuAttrSom::cFNuAttrSom
(
       cElNuage3DMaille *aN,
       const cImSecOfMaster&   aSecs,
       const std::string & aNameIm,
       cAppliFusionNuage * anAppli,
       Im2D_U_INT1       aImBsH

) :
   mAppli     (anAppli),
   mSecs      (aSecs),
   mVoisInit  (mSecs.ISOM_AllVois().Val()),
   mStdN      (aN),
   mNameIm    (aNameIm),
   mMasqValid (1,1)
{
   // ELISE_ASSERT(mSecs.ISOM_AllVois

   /******************************************/
   /*                                        */
   /*      Calcul de la liste reduite        */
   /*                                        */
   /******************************************/

   Pt2di aSzN = mStdN->Sz();
   mMasqValid = Im2D_Bits<1>(aSzN.x,aSzN.y,1);
   ELISE_COPY(mMasqValid.all_pts(),mStdN->ImDef().in(),mMasqValid.out());
   if (aImBsH.sz().x > 1)
   {
      ELISE_COPY
      (
         mMasqValid.all_pts(),
         mMasqValid.in() && (aImBsH.in(255) > anAppli->Param().mSeuilBSH),
         mMasqValid.out()
      );
   }


   int aNb1C = anAppli->Param().mNbCellCalcGraph;
   double aSzCel = sqrt(double(aSzN.x*aSzN.y)/ElSquare(aNb1C));
   Pt2di aNb2C = round_up(Pt2dr(aSzN)/aSzCel);
   Pt2di aPK;

   static std::vector<cPtFuNu> aVPTR; aVPTR.clear();
   TIm2DBits<1> aTDef(mMasqValid);
   Im2D_U_INT1 anImDist(aSzN.x,aSzN.y);
   TIm2D<U_INT1,INT> aTDist(anImDist);
   ELISE_COPY(mMasqValid.all_pts(),mMasqValid.in(),anImDist.out());

   Chamfer::d32.im_dist(anImDist);

/*
static Video_Win  aW=Video_Win::WStd(aSzN,3);
ELISE_COPY(anImDist.all_pts(),mStdN->ImDef().in()!=0,aW.odisc());
ELISE_COPY(select(anImDist.all_pts(),anImDist.in()>0),P8COL::blue,aW.odisc());
ELISE_COPY(select(anImDist.all_pts(),anImDist.in()>10),P8COL::yellow,aW.odisc());
getchar();
*/

   mNbSomTest = 0;

   for (aPK.x=0 ; aPK.x<aNb2C.x ; aPK.x++)
   {
       Pt2di aP0,aP1;
       aP0.x = (aPK.x*aSzN.x)     / aNb2C.x;
       aP1.x = ((aPK.x+1)*aSzN.x) / aNb2C.x;
       for (aPK.y=0 ; aPK.y<aNb2C.y ; aPK.y++)
       {
           aP0.y = (aPK.y*aSzN.y)     / aNb2C.y;
           aP1.y = ((aPK.y+1)*aSzN.y) / aNb2C.y;

           Pt2di aP;

           Pt2dr aPMoy(0,0);
           int aNbSom=0;
           // aW.draw_rect(Pt2dr(aP0),Pt2dr(aP1),Line_St(aW.pdisc()(P8COL::green)));
           for (aP.x=aP0.x; aP.x<aP1.x ; aP.x++)
           {
               for (aP.y=aP0.y; aP.y<aP1.y ; aP.y++)
               {
                  if (aTDef.get(aP))
                  {
                     aPMoy = aPMoy + Pt2dr(aP);
                     aNbSom++;
                  }
               }
           }
           if (aNbSom>0)
           {
              aPMoy = aPMoy/double(aNbSom);
              double aDBest = 1e10;
              Pt2di aPBest(0,0);
              for (aP.x=aP0.x; aP.x<aP1.x ; aP.x++)
              {
                  for (aP.y=aP0.y; aP.y<aP1.y ; aP.y++)
                  {
                     if (aTDef.get(aP))
                     {
                        double aDist = euclid(Pt2dr(aP),aPMoy) - ElMin(5.0,aTDist.get(aP)/2.0);
                       
                        if (aDist<aDBest)
                        {
                           aDBest = aDist;
                           aPBest = aP;
                        }
                     }
                  }
              }
              Pt3dr aP3 = mStdN->PtOfIndex(aPBest);
              cPtFuNu aPF;
              aPF.mNb = aNbSom;
              aPF.mPt =  Pt3df(aP3.x,aP3.y,aP3.z);
              aVPTR.push_back(aPF);
              mNbSomTest += aNbSom;
              // aW.draw_circle_abs(Pt2dr(aPBest),3.0,aW.pdisc()(P8COL::red));
           }
       }
   }

   mPtsTestRec = aVPTR;
   mSeuilNbSomTest = round_ni((anAppli->Param().mPercRecMin/100.0) * mNbSomTest);

   std::cout << "aNameIm " << mStdN->Sz()  << " " << aNb2C << " " << mPtsTestRec.size()  << " " << mVoisInit.ISOM_Vois().size()<< "\n";
}


const std::list<cISOM_Vois> & cFNuAttrSom::ListVoisInit()
{
   return mVoisInit.ISOM_Vois();
}

bool cFNuAttrSom::IsArcValide(cFNuAttrSom * aS2)
{
   
   ELISE_ASSERT(false,"cFNuAttrSom::IsArcValide");
   return false;
}

/*
cFNuAttrSom::cFNuAttrSom() :
   mStdN(0)mSecs
{IsArcValide(
}
*/



/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA 
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant 
donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
