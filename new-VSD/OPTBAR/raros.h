#ifndef _raros_h_
#define _raros_h_

#include <stdio.h>
#include "datos.h"

extern char nomFlaviaMesh[256];
extern char nomFlaviaRes[256];
extern char nomPos[256];
extern char nomGir[256];
extern char nomOpt[256];  // reportar los materiales de los elementos              MAX
extern char nomLog[256];  //reportar en log la corrida usualmente print a pantalla MAX
extern FILE *fpOpt;
extern FILE *fpLog;


extern char nom[5][250];
extern FILE *fp;
extern FILE *fp5;
extern FILE *fp16;
extern FILE *fp1;
extern FILE *fp3;
extern FILE *fp10;
extern FILE *fp9;
extern FILE *fp79;
extern FILE *fpresults;
extern time_t a;
extern time_t b;


extern int inds,isho;
extern	int *narea, *narec, *naref, *narcon, *mata, *matm, *ubiC, casoCarg, *npes;
extern	cat_armadura cArma;
extern	cat_acero_RF cAceRF;
extern	cat_acero_RC cAceRC;
extern	cat_concreto cCon;
extern	double ***dtco, *efi_mx;
extern	double *angl, **anglg;
extern	bool iwritModif;
	//jacob.modif aumento de nom[4][256] a nom[5][256]
extern	char title[1000], uLongi[1000], uFuer[1000], ve[1000], **listaCata;
extern	int ipro, ncar, ndim, nele, neva, ngau, ngd, nmat, nfam, ncas, nvp, thread;
extern	int nnod, npno, npre, npro, nprp, nten, ntipo, isal,ntot, neq, mkou;
extern	int iwri, nwkt, nres,ninc, mnod, i, iva, iv, paso, *ntip, **inpr,  *nodp;

    
extern	int **lnod,  *matn,  *iffi, *maxa, *mhig, **leq,  *node,  *lres,  *linc, **indf;
extern	double* fix;
extern	double 	 *xlon, *wcar, **coor, **cargaa,  **carp, *desp, **prop, **pres, **fuem, **fuep, **asti,
	*aslo,  *reac,  *fuec,  *stif,  *vecp,  *vecu, *valr, *valm,
	*veca, *vec1,  *des, **res,  *xinc, **rig, **gir, **fueb,
	**girt, **tem, **vmat, **fuef, **xmas, **vecr, ***srm, ***smm;
extern    double *ten, *mval, *auxx, *aux11, ** mvecto, ** vecto11, ** desl, ** tenl, ** vech; // Se agrego para valores propios
extern    double ***vectores_f;           // Se agrego para almacenar los vectores de fuerza para cada caso de carga
extern	double beta,alfa;                     // Se agrego para optimizador
extern	double deltaf,dd,de,fact,penaliza;    // Se agrego para optimizador
extern	int jj,imats,Num_iter;                // Se agrego para optimizador

extern    char letrero[100]; //Contenido no importante, solo para lectura de letreros en archivos de datos.

extern   bool generaMatRig;
extern	int auxa;

#endif
