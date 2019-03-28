/*==========================================================================
// //  Author: Carlos Segura, Joel Chacón 
//     Description: 
//
// ===========================================================================*/


#ifndef _PROBLEM_H
#define _PROBLEM_H

#include "cec09.h"
#include "RealLife-MOPs.h"


//// Toolkit includes. //////////////////////////////////////////////////////

#include "Toolkit/ExampleProblems.h"
#include "Toolkit/TransFunctions.h"
using namespace WFG::Toolkit;
using namespace WFG::Toolkit::Examples;


///////////////////////

#include "OPTBAR/Optimizador.h"



void Bar_Opt(std::vector< double >& F, std::vector< int >& X)
{
 // cout<<"in Bar_Opt"<<endl;

  for(unsigned int i=1; i<X.size(); i++) 
    mata[i]=X[i-1];


  std::vector<double> v;


  v=Funcion_fitness(isho, npno,nele, npre,  ncar, ntipo, ngd, nmat,
                 ndim, iwri, isal, nres, ninc, nfam, ncas,
                  nnod, mnod, nprp, ngau, nten, neva, inds, ntot,
                 lnod, inpr, narea, naref, narec, narcon,
                 lres, linc, ntip, nodp, matn, mata, matm,
                 iffi, indf, node, maxa,mhig, leq,
                 coor, cargaa,carp, pres, prop,
                 fuem, fuep, rig, xmas, vmat,
                 gir, girt, tem, fuef, fueb,
                 srm, smm, cArma, cAceRF,
                 cAceRC,cCon, res, xinc,
                 fuec, aslo, desp, fix, reac,
                 veca, vec1, des, xlon, valr,
                 valm, angl, anglg, wcar, vecr,
                 asti, vecp, vecu, listaCata, ubiC,
                 vectores_f, npes, efi_mx, stif, neq,
                 nwkt);//@mg'

  F[0]=v[0]*2000000.0;//to_normal[0];//with normalization
  F[1]=v[1];//to_normal[1];
  
//  F[2]=v[0];//without normalization
//  F[3]=v[1];

  //printf("%lf %lf %lf %lf %lf %lf \n", F[0],F[1],F[2],F[3],to_normal[0],to_normal[1]);

 /* cout<<"Valores correspondientes al individuo";
  for (int i = 0; i < v.size(); ++i)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;*/
 /* LiberaMemoria( npno, nele, ncar, ngd, nmat, ndim, neva, inds, lnod,
                   inpr, narea, naref, narec, narcon, lres, linc, ntip,
                   nodp, matn, mata, matm, iffi, indf, node, maxa, mhig,
                   leq, coor, cargaa, carp, pres, prop, fuem, fuep, rig,
                   xmas, vmat, gir, girt, tem, fuef, fueb, srm, smm,
                   res, xinc, fuec, aslo, desp, fix, reac, veca, vec1,
                   des, xlon, valr, valm, angl, anglg, wcar, vecr, asti,
                   vecp, vecu, listaCata, ubiC, vectores_f, cArma.nombre,
                   cArma.tamCat, cArma.arear, cAceRF.nombre, cAceRF.tamCat,
                   cAceRF.arerf, cAceRC.nombre, cAceRC.tamCat, cAceRC.arerc,
                   cCon.nombre, cCon.tamCat, cCon.arecr, cCon.dtcon,
                   cArma.nCat, cAceRF.nCat, cAceRC.nCat, cCon.nCat,
                   stif, npes, efi_mx );
  cout<<"deaspues LiberaMemoria"<<endl;*/

}
// *********************** CEC 2009 ************************************
void CEC09_F1(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(2); 
	std::vector<double> XX(X);
	for(unsigned int i=1; i<X.size(); i++) XX[i] = -1.0 + 2.0*X[i];
	CEC09::UF1(&(*(XX.begin())), &(*(F.begin())), X.size());
}
void CEC09_F2(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(2); 
	std::vector<double> XX(X);
	for(unsigned int i=1; i<X.size(); i++) XX[i] = -1.0 + 2.0*X[i];
	CEC09::UF2(&(*(XX.begin())), &(*(F.begin())), X.size());
}
void CEC09_F3(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(2); 
	CEC09::UF3(&(*(X.begin())), &(*(F.begin())), X.size());
}
void CEC09_F4(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(2); 
	std::vector<double> XX(X);
	for(unsigned int i=1; i<X.size(); i++) XX[i] = -2.0 + 4.0*X[i];
	CEC09::UF4(&(*(XX.begin())), &(*(F.begin())), X.size());
}
void CEC09_F5(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(2); 
	std::vector<double> XX(X);
	for(unsigned int i=1; i<X.size(); i++) XX[i] = -1.0 + 2.0*X[i];
	CEC09::UF5(&(*(XX.begin())), &(*(F.begin())), X.size());
}
void CEC09_F6(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(2); 
	std::vector<double> XX(X);
	for(unsigned int i=1; i<X.size(); i++) XX[i] = -1.0 + 2.0*X[i];
	CEC09::UF6(&(*(XX.begin())), &(*(F.begin())), X.size());
}
void CEC09_F7(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(2); 
	std::vector<double> XX(X);
	for(unsigned int i=1; i<X.size(); i++) XX[i] = -1.0 + 2.0*X[i];
	CEC09::UF7(&(*(XX.begin())), &(*(F.begin())), X.size());
}
void CEC09_F8(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(3); 
	std::vector<double> XX(X);
	for(unsigned int i=2; i<X.size(); i++) XX[i] = -2.0 + 4.0*X[i];
	CEC09::UF8(&(*(XX.begin())), &(*(F.begin())), X.size());
}
void CEC09_F9(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(3); 
	std::vector<double> XX(X);
	for(unsigned int i=2; i<X.size(); i++) XX[i] = -2.0 + 4.0*X[i];
	CEC09::UF9(&(*(XX.begin())), &(*(F.begin())), X.size());
}
void CEC09_F10(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(3); 
	std::vector<double> XX(X);
	for(unsigned int i=2; i<X.size(); i++) XX[i] = -2.0 + 4.0*X[i];
	CEC09::UF10(&(*(XX.begin())), &(*(F.begin())), X.size());
}

// ---------------- 5 objective test instances ------------------

void CEC09_R2_DTLZ2_M5(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(5); 
	std::vector<double> XX(X);
	
	double low30[] = {-1.773,	-1.846,	-1.053,	-2.370,	-1.603,	-1.878,	-1.677,	-0.935,	-1.891,	-0.964,	-0.885,	-1.690,	-2.235,	-1.541,	-0.720,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000};
	double upp30[] = {1.403,	1.562,	2.009,	0.976,	1.490,	1.334,	1.074,	2.354,	1.462,	2.372,	2.267,	1.309,	0.842,	1.665,	2.476,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000};

	for(unsigned int i=0; i<X.size(); i++) XX[i] = low30[i] + X[i]*(upp30[i] - low30[i]);
	CEC09::R2_DTLZ2_M5(&(*(XX.begin())), &(*(F.begin())), X.size(), nobj);
}

void CEC09_R2_DTLZ3_M5(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(5); 
	std::vector<double> XX(X);
	
	double low30[] = {-1.773,	-1.846,	-1.053,	-2.370,	-1.603,	-1.878,	-1.677,	-0.935,	-1.891,	-0.964,	-0.885,	-1.690,	-2.235,	-1.541,	-0.720,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000,	0.000};
	double upp30[] = {1.403,	1.562,	2.009,	0.976,	1.490,	1.334,	1.074,	2.354,	1.462,	2.372,	2.267,	1.309,	0.842,	1.665,	2.476,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000,	1.000};

	for(unsigned int i=0; i<X.size(); i++) XX[i] = low30[i] + X[i]*(upp30[i] - low30[i]);
	CEC09::R2_DTLZ3_M5(&(*(XX.begin())), &(*(F.begin())), X.size(), nobj);
}

void CEC09_WFG1_M5(std::vector< double >& F, std::vector< double >& X)
{
	F.resize(5); 
	std::vector<double> XX(X);
	CEC09::WFG1_M5(&(*(XX.begin())), &(*(F.begin())), X.size(), nobj);
}

///////////////////////////////////////wfg problems...
void wfg1(std::vector<double> &F, std::vector<double> &X)
{
	 //---- Get the function name.

	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG1( X, k, M );
}
void wfg2(std::vector<double> &F, std::vector<double> &X)
{
	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG2( X, k, M );
}
void wfg3(std::vector<double> &F, std::vector<double> &X)
{
	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG3( X, k, M );
}
void wfg4(std::vector<double> &F, std::vector<double> &X)
{
	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG4( X, k, M );
}
void wfg5(std::vector<double> &F, std::vector<double> &X)
{
	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG5( X, k, M );
}
void wfg6(std::vector<double> &F, std::vector<double> &X)
{
	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG6( X, k, M );
}
void wfg7(std::vector<double> &F, std::vector<double> &X)
{
	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG7( X, k, M );
}
void wfg8(std::vector<double> &F, std::vector<double> &X)
{
	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG8( X, k, M );
}
void wfg9(std::vector<double> &F, std::vector<double> &X)
{
	int M = F.size();
	int k=param_k, l=param_l;
        F = Problems::WFG9( X, k, M );
}
void dtlz1(std::vector<double> &F, std::vector<double> &X)
{

  int k = X.size()- F.size() + 1;

  double g = 0.0 ;

  for (int i = X.size() - k; i < X.size(); i++)
    g += (X[i] - 0.5)*(X[i] - 0.5) - cos(20.0 * M_PI * (X[i] - 0.5));

  g = 100 * (k + g);
  for (int i = 0; i < F.size(); i++)
    F[i] = (1.0 + g) * 0.5;

  for (int i = 0; i < F.size(); i++){
    for (int j = 0; j < F.size() - (i + 1); j++)
      F[i] *= X[j];
      if (i != 0){
        int aux = F.size() - (i + 1);
        F[i] *= 1 - X[aux];
      } //if
  }//for

}
void dtlz2(std::vector<double> &F, std::vector<double> &X)
{

  int numberOfVariables_ = X.size();
  int numberOfObjectives_ = F.size();
  int k = numberOfVariables_ - numberOfObjectives_ + 1;
   double g = 0.0;
  for (int i = numberOfVariables_ - k; i < numberOfVariables_; i++)
    g += (X[i] - 0.5)*(X[i] - 0.5);

  for (int i = 0; i < numberOfObjectives_; i++)
    F[i] = 1.0 + g;

  for (int i = 0; i < numberOfObjectives_; i++){
    for (int j = 0; j < numberOfObjectives_ - (i + 1); j++)
      F[i] *= cos(X[j]*0.5*M_PI);
      if (i != 0){
        int aux = numberOfObjectives_ - (i + 1);
        F[i] *= sin(X[aux]*0.5*M_PI);
      } //if
  } // for
}
void dtlz3(std::vector<double> &F, std::vector<double> &X)
{
  int numberOfVariables_ = X.size();
  int numberOfObjectives_ = F.size();

  int k = numberOfVariables_ - numberOfObjectives_ + 1;


  double g = 0.0;
  for (int i = numberOfVariables_ - k; i < numberOfVariables_; i++)
    g += (X[i] - 0.5)*(X[i] - 0.5) - cos(20.0 * M_PI * (X[i] - 0.5));

  g = 100.0 * (k + g);
  for (int i = 0; i < numberOfObjectives_; i++)
    F[i] = 1.0 + g;

  for (int i = 0; i < numberOfObjectives_; i++){
    for (int j = 0; j < numberOfObjectives_ - (i + 1); j++)
      F[i] *= cos(X[j]*0.5*M_PI);
      if (i != 0){
        int aux = numberOfObjectives_ - (i + 1);
        F[i] *= sin(X[aux]*0.5*M_PI);
      } // if
  } //for

}
void dtlz4(std::vector<double> &F, std::vector<double> &X)
{

  int numberOfVariables_ = X.size();
  int numberOfObjectives_ = F.size();
  int k = numberOfVariables_ - numberOfObjectives_ + 1;
  double alpha = 100.0;


  double g = 0.0;
  for (int i = numberOfVariables_ - k; i < numberOfVariables_; i++)
    g += (X[i] - 0.5)*(X[i] - 0.5);

  for (int i = 0; i < numberOfObjectives_; i++)
    F[i] = 1.0 + g;

  for (int i = 0; i < numberOfObjectives_; i++) {
    for (int j = 0; j < numberOfObjectives_ - (i + 1); j++)
      F[i] *= cos(pow(X[j],alpha)*(M_PI/2.0));
      if (i != 0){
        int aux = numberOfObjectives_ - (i + 1);
        F[i] *= sin(pow(X[aux],alpha)*(M_PI/2.0));
      } //if
  } // for

}
void dtlz5(std::vector<double> &F, std::vector<double> &X)
{
  double g = 0.0;
  int numberOfVariables_ = X.size();
  int numberOfObjectives_ = F.size();
  std::vector<double> theta_(numberOfObjectives_-1,0);
  int k = numberOfVariables_ - numberOfObjectives_ + 1;
  double alpha = 100.0;


  for (int i = numberOfVariables_ - k; i < numberOfVariables_; i++)
    g += (X[i] - 0.5)*(X[i] - 0.5);

  double t = M_PI / (4.0 * (1.0 + g));

  theta_[0] = X[0] * M_PI / 2.0;
  for (int i = 1; i < (numberOfObjectives_-1); i++)
    theta_[i] = t * (1.0 + 2.0 * g * X[i]);

  for (int i = 0; i < numberOfObjectives_; i++)
    F[i] = 1.0 + g;

  for (int i = 0; i < numberOfObjectives_; i++){
    for (int j = 0; j < numberOfObjectives_ - (i + 1); j++)
      F[i] *= cos(theta_[j]);
      if (i != 0){
        int aux = numberOfObjectives_ - (i + 1);
        F[i] *= sin(theta_[aux]);
      } // if
  } //for

}
void dtlz6(std::vector<double> &F, std::vector<double> &X)
{
  double g = 0.0;
  int numberOfVariables_ = X.size();
  int numberOfObjectives_ = F.size();

  std::vector<double> theta_(numberOfObjectives_-1,0);
  int k = numberOfVariables_ - numberOfObjectives_ + 1;
  double alpha = 100.0;

  for (int i = numberOfVariables_ - k; i < numberOfVariables_; i++)
    g += pow(X[i],0.1);

  double t = M_PI / (4.0 * (1.0 + g));

  theta_[0] = X[0] * M_PI / 2.0;
  for (int i = 1; i < (numberOfObjectives_-1); i++)
    theta_[i] = t * (1.0 + 2.0 * g * X[i]);

  for (int i = 0; i < numberOfObjectives_; i++)
    F[i] = 1.0 + g;

  for (int i = 0; i < numberOfObjectives_; i++){
    for (int j = 0; j < numberOfObjectives_ - (i + 1); j++)
      F[i] *= cos(theta_[j]);
      if (i != 0){
        int aux = numberOfObjectives_ - (i + 1);
        F[i] *= sin(theta_[aux]);
      } // if
  } //for

}
void dtlz7(std::vector<double> &F, std::vector<double> &X)
{
  double g = 0.0;
  int numberOfVariables_ = X.size();
  int numberOfObjectives_ = F.size();
  int k = numberOfVariables_ - numberOfObjectives_ + 1;
  double alpha = 100.0;

  for (int i = numberOfVariables_ - k; i < numberOfVariables_; i++)
    g += X[i] ;

  g = 1 + (9.0 * g)/k ;


  for (int i = 0; i < numberOfObjectives_ - 1; i++)
    F[i] = X[i] ;

  double h = 0.0 ;
  for (int i = 0; i < numberOfObjectives_ - 1; i++){
    h+=(F[i]/(1.0+g))*(1 + sin(3.0*M_PI*F[i])) ;
  } //for

  h = numberOfObjectives_ - h ;

  F[numberOfObjectives_ - 1] = (1+g)*h ;	
}
void RWP1(std::vector<double> &F, std::vector<double> &X)
{
        RealLife_MOPs::INJ_4OBJ( &(*(X.begin())),  &(*(F.begin())));
}
void RWP2(std::vector<double> &F, std::vector<double> &X)
{
        RealLife_MOPs::CWD( &(*(X.begin())),  &(*(F.begin())));
}

#endif
