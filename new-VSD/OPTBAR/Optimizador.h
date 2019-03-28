#ifndef _Optimizador_h_
#define _Optimizador_h_
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <limits>
#include <algorithm> 
#include "estatico.h"
#include "ValoresPropios.h"
#include "fuerzas.h"
#include "posprogid.h"
#include "solver.h"
#include "memoria.h"
#include "raros.h"
#include <vector>

using namespace std; 
typedef struct{
    std::vector<int> secciones;//matva_modif
   // std::vector<int> barras;//matnu_modif

    std::vector<double> valores;
    std::vector<double> objs;//peso y desplazamiento
    std::vector<double> pena;//peso y desplazamiento
    double dist_crow;
    double sum_pen;
    int rank;
    int indice;
    double desplazamiento;
    double peso;
    double efi;

}Individuo;
	
int Optimizador(int prueba);
std::vector<int> bars_cross();

void BC_barras(int v);//para recorrer grafo GRAFO




std::vector<double> Funcion_fitness( int ishot, int npnod, int nelem, int npres, int ncarg, int ntipo, int ngdln, int nmats,//@mg 
                 int ndime, int iwrit, int isale, int nreso, int nincl, int nfami, int ncaso,
                 int nnode, int mnode, int nprop, int ngaus, int ntens, int nevab, int indso, int ntotv,
                 int** lnods, int** inpre, int* nareas, int* narerf, int* narerc, int* narecon,
                 int* lreso, int* lincl,int* ntips, int* nodpr, int* matnu, int* matva, int* matvm,
                 int* iffix, int** indfu, int* nodea, int* maxad, int* mhigh, int** leqns,
                 double** coord, double** carga, double** carpp, double** presc, double** props,
                 double** fuemp, double** fuepp, double** rigid, double** xmasa, double** vmatr,
                 double** girom, double** girtm, double** tempr, double** fuefl,double** fuerb,
                 double*** srmat,double*** smmat, cat_armadura &cArmaduras, cat_acero_RF &cAceroRF,
                 cat_acero_RC &cAceroRC, cat_concreto &cConcr, double** resor, double* xincl,
                 double* fuerc, double* aslod, double* despl, double* fixed, double* react,
                 double* vecta, double* vect1, double* deslo, double* xlong, double* valor,
                 double* valom, double* angulo, double** angulg, double* wcarg, double** vectr,
                 double** astif, double* vectp, double* vectu, char **listaCatalogos, int* ubiCat,
                 double ***vectores_fuerzas, int *npesp, double *efi_max, double *stiff, int neqns,
                  int nwktl);

void parent_selection();//@mg 
void Crossover();
void mutacion(int ishot, int npnod, int nelem, int npres, int ncarg, int ntipo, int ngdln, int nmats,
                 int ndime, int iwrit, int isale, int nreso, int nincl, int nfami, int ncaso,
                 int nnode, int mnode, int nprop, int ngaus, int ntens, int nevab, int indso, int ntotv,
                 int** lnods, int** inpre, int* nareas, int* narerf, int* narerc, int* narecon,
                 int* lreso, int* lincl,int* ntips, int* nodpr, int* matnu, int* matva, int* matvm,
                 int* iffix, int** indfu, int* nodea, int* maxad, int* mhigh, int** leqns,
                 double** coord, double** carga, double** carpp, double** presc, double** props,
                 double** fuemp, double** fuepp, double** rigid, double** xmasa, double** vmatr,
                 double** girom, double** girtm, double** tempr, double** fuefl,double** fuerb,
                 double*** srmat,double*** smmat, cat_armadura &cArmaduras, cat_acero_RF &cAceroRF,
                 cat_acero_RC &cAceroRC, cat_concreto &cConcr, double** resor, double* xincl,
                 double* fuerc, double* aslod, double* despl, double* fixed, double* react,
                 double* vecta, double* vect1, double* deslo, double* xlong, double* valor,
                 double* valom, double* angulo, double** angulg, double* wcarg, double** vectr,
                 double** astif, double* vectp, double* vectu, char **listaCatalogos, int* ubiCat,
                 double ***vectores_fuerzas, int *npesp, double *efi_max, double *stiff, int neqns,
                  int nwktl);//@mg 

void Actualiza(int nmats, int* matva, int* matvm, double* valor, double* valom);
void Inicializa_Materiales( int nmats, int ndime, double** props, int* matva,
                          int *Arm_tamCat, int *RF_tamCat, int *RC_tamCat,
                          int *Con_tamCat, int *ubiCat );











#endif
