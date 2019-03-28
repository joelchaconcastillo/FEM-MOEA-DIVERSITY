#include <time.h>
#include "raros.h"

char nomFlaviaMesh[256];
char nomFlaviaRes[256];
char nomPos[256];
char nomGir[256];
char nomOpt[256];  // reportar los materiales de los elementos              MAX
char nomLog[256];  //reportar en log la corrida usualmente print a pantalla MAX
FILE *fpOpt;
FILE *fpLog;

char nom[5][250];
FILE *fp;
FILE *fp5;
FILE *fp16;
FILE *fp1;
FILE *fp3;
FILE *fp10;
FILE *fp9;
FILE *fp79;
FILE *fpresults;
time_t a;
time_t b;


  int inds,isho;
 	int *narea, *narec, *naref, *narcon, *mata, *matm, *ubiC, casoCarg, *npes;
 	cat_armadura cArma;
 	cat_acero_RF cAceRF;
 	cat_acero_RC cAceRC;
 	cat_concreto cCon;
 	double ***dtco, *efi_mx;
 	double *angl, **anglg;
 	bool iwritModif;
	//jacob.modif aumento de nom[4][256] a nom[5][256]
 	char title[1000], uLongi[1000], uFuer[1000], ve[1000], **listaCata;
 	int ipro, ncar, ndim, nele, neva, ngau, ngd, nmat, nfam, ncas, nvp, thread;
 	int nnod, npno, npre, npro, nprp, nten, ntipo, isal,ntot, neq, mkou;
 	int iwri, nwkt, nres,ninc, mnod, i, iva, iv, paso, *ntip, **inpr,  *nodp;

    
 	int **lnod,  *matn,  *iffi, *maxa, *mhig, **leq,  *node,  *lres,  *linc, **indf;
 	double* fix;
 	double 	 *xlon, *wcar, **coor, **cargaa,  **carp, *desp, **prop, **pres, **fuem, **fuep, **asti,
	*aslo,  *reac,  *fuec,  *stif,  *vecp,  *vecu, *valr, *valm,
	*veca, *vec1,  *des, **res,  *xinc, **rig, **gir, **fueb,
	**girt, **tem, **vmat, **fuef, **xmas, **vecr, ***srm, ***smm;
     double *ten, *mval, *auxx, *aux11, ** mvecto, ** vecto11, ** desl, ** tenl, ** vech; // Se agrego para valores propios
     double ***vectores_f;           // Se agrego para almacenar los vectores de fuerza para cada caso de carga
 	double beta,alfa;                     // Se agrego para optimizador
 	double deltaf,dd,de,fact,penaliza;    // Se agrego para optimizador
 	int jj,imats,Num_iter;                // Se agrego para optimizador

     char letrero[100]; //Contenido no importante, solo para lectura de letreros en archivos de datos.

    bool generaMatRig;
 	int auxa;

 	

