//*****************************
// Rutina Principal
//*****************************

#include "principal.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "datos.h"
#include "estatico.h"
#include "ValoresPropios.h"
#include "fuerzas.h"
#include "datos.h"
#include "util.h"
#include "principal.h"
#include "raros.h"
#include "posprogid.h"
#include "prelim.h"
#include "solver.h"
#include "memoria.h"
#include "Optimizador.h"
	

	
//******************************************************************************
//							Principal
//******************************************************************************
int principal(int indso, int ishot, char* input1, char* output1, bool Optimiza,int prueba)
{


	// Finaliza 0 si no hubo ningun error.
	// Finaliza -1 si se hubo algun error de calculo.
	// Finaliza -2 si falto algun dato es erroneo.
	// Finaliza -3 si no se cuenta con la version completa (o la copia de evaluacion).
	// Finaliza -4 si el archivo no es de datos.
	// Finaliza -5 si no se pudo crear el archivo de resultados.
	inds=indso;
	isho=ishot;
	auxa=0;
	

    Optimiza = false;
	paso = 1; // este sirve para posrogid

	// Apertura de archivo de datos
	//int nchar = ;
	int i;
	//printf("%s\n", input1);
	fp5  = fopen(input1, "rt");

	 for(i= (int) strlen(input1);i>=0;i--)
	   if(input1[i]=='.') {
			input1[i]='\0';
			break;
        }
	    else {
			input1[i]='\0';
		}
	strcpy(nomFlaviaMesh, input1);
	strcpy(nomFlaviaRes, input1);
//	strcpy(nomPos, input1);
//	strcpy(nomGir, input1);
	strcpy(nomOpt, input1);
	strcpy(nomLog, input1);


	strcat(nomFlaviaMesh, ".flavia.msh");         // para gid
	strcat(nomFlaviaRes, ".flavia.res");          // para gid
	strcat(nomPos, ".pos");
	strcat(nomGir, ".gir");


	// Crea los archivos de resultados
	fp16 = fopen(output1, "wt");
//  fp79 = fopen(nomGir,"wt");
//	fp9  = fopen(nomPos, "wt");
	// Inicia lectura del archivo de datos
	fscanf(fp5, "%s", title);


	fscanf(fp5, "%s", ve);

	
	fprintf(fp16,"%s\n", "ProMECA 1.0");


	iva  = 0;
	npro = 1;
	
	for(ipro=1; ipro<=npro; ipro++){

		// Lee datos del problema
        fscanf(fp5, "%s %s",letrero, title);
		fprintf(fp16, "%s\n", title);
		fscanf(fp5, "%s %s",letrero, uLongi);
		fscanf(fp5, "%s %s", letrero, uFuer);
		fprintf(fp16, "%s\t", uLongi);
		fprintf(fp16, "%s\n", uFuer);

		

		// Lee datos geometricos y del material:
		iv=Datos(npno,nele,npre,ncar,ntipo,ngd,nmat,ndim,iwri,isal,nres,ninc,nfam,ncas,
				 nnod,mnod,nprp,ngau,nten,neva,inds,ntot,thread,nvp,lnod,inpr,narea,naref,narec,
				 narcon,lres,linc,ntip,nodp,matn,mata,matm,iffi,indf,node,maxa,mhig,leq,
				 coor,cargaa,carp,pres,prop,fuem,fuep,rig,xmas,vmat, gir,girt,tem,fuef,
				 fueb,srm,smm,cArma,cAceRF,cAceRC,cCon,res,xinc,fuec,aslo,desp,
				 fix,reac,veca,vec1,des,xlon,valr,valm,angl,anglg,wcar,vecr,asti,vecp,
				 vecu,listaCata,ubiC,vectores_f,npes,efi_mx,ten,mval,
                 auxx,aux11,mvecto,vecto11,desl,tenl,vech);
        
    
		
    
       // printf("termino de leer los datos");
   

		//if( iwri == 1 && Optimiza ) fprintf(fpLog,"Lectura de datos del problema = %d \n\n",Prob());


        // Calculo de cosenos dierectores de las barras //mg vecr es una matriz que contiene los cosenos directores.
		Prelim(nele,ndim,ntipo,lnod,coor,xlon,vmat,vecr,angl);
		//printf("dESpues de prelim \n");

		if(inds == 2) Linkin(nele,nnod,neva,ntot,npre,ngd,neq,nwkt,mkou,
							  lnod,node,nodp,inpr,iffi,leq,maxa,mhig,
							  pres,fix,stif);

        // Lee el letrero de los casos de carg
        for( int i = 1; i <= 10; i++ ) {
            fscanf(fp5, "%s", letrero);
            //printf("%s \n", letrero);

        }
	
		generaMatRig = true;
		/*for( casoCarg = 1; casoCarg <= ncar; casoCarg++ ){


            if(ncas ==1) {
                Fuerzas(nele,npno,ndim,ntipo,neva,nnod,ngd,iwri,casoCarg,lnod,matn,indf,ntip,coor,
                        xlon,prop,fueb,wcar,carp,fuep,vecr,carg,fuem,Optimiza,auxa);

                iva = Estatico( nele,npno,neva,ndim,ntipo,ncas,npre,iwri,inds,isal,ngd,nnod,
				                           ntot,ninc,nres,neq,nwkt,isho,lnod,matn,inpr,iffi,ntip,maxa,
				                           node,nodp,leq,linc,lres,reac,coor,pres,fix,desp,aslo,stif,
				                           srm,prop,xlon,vecr,rig,carp,fuep,carg,fuem,gir,girt,tem,
				                           fuec,valr,cArma.arear,cAceRF.arerf,cAceRC.arerc,cCon.arecr,
				                           cCon.dtcon,indf,fueb,fuef,wcar,xinc,res,asti,vecp,vecu,vec1,
				                           des,ubiC,efi_mx,generaMatRig,Optimiza);
                nvp=paso;
                generaMatRig = false;
            }
            if(ncas ==2){
                     printf("Inicia Calculo de valres y Vectores Propios= %d \n\n",Prob());
                    iva =ValoresPropios( nele,npno,neva,ndim,ntipo,ncas,npre,iwri,inds,isal,ngd,nnod,
                                          ntot,ninc,nres,neq,nwkt,isho,lnod,matn,inpr,iffi,ntip,maxa,
                                          node,nodp,leq,linc,lres,reac,coor,pres,fix,desp,aslo,stif,
                                          srm,prop,xlon,vecr,rig,carp,fuep,carg,fuem,gir,girt,tem,
                                          mkou,mhig,fuec,valr,fueb,fuef,wcar,xinc,res,asti,vecp,vecu,vec1,
                                          des,ten,auxx,aux11,smm,xmas,veca,nvp,mval,mvecto,vecto11,thread,
                                          desl,tenl,vech,generaMatRig);
                generaMatRig = false;
            }
            if(ncas ==3){
                strcat(nomOpt, "Opt.txt");  fpOpt =fopen(nomOpt,"wt");
                strcat(nomLog, "Log.txt");  fpLog =fopen(nomLog,"wt");
                iva = Optimizador(prueba);
              }

		// Post-proceso con GID
		PosproGid(npno,nele,ndim,nnod,ngd,ntot,nmat,ncas,nvp,lnod,matn,mata,coor,
				  prop,desp,fuec,aslo,carg, title,mvecto);
        
        }

		// Libera memoria
		LiberaMemoria( npno, nele, ncar, ngd, nmat, ndim, neva, inds, lnod,
		               inpr, narea, naref, narec, narcon, lres, linc, ntip,
		               nodp, matn, mata, matm, iffi, indf, node, maxa, mhig,
		               leq, coor, carg, carp, pres, prop, fuem, fuep, rig,
		               xmas, vmat, gir, girt, tem, fuef, fueb, srm, smm,
		               res, xinc, fuec, aslo, desp, fix, reac, veca, vec1,
		               des, xlon, valr, valm, angl, anglg, wcar, vecr, asti,
		               vecp, vecu, listaCata, ubiC, vectores_f, cArma.nombre,
		               cArma.tamCat, cArma.arear, cAceRF.nombre, cAceRF.tamCat,
		               cAceRF.arerf, cAceRC.nombre, cAceRC.tamCat, cAceRC.arerc,
		               cCon.nombre, cCon.tamCat, cCon.arecr, cCon.dtcon,
		               cArma.nCat, cAceRF.nCat, cAceRC.nCat, cCon.nCat,
		               stif, npes, efi_mx );*/

     }
//printf("Ejecucion del programa = %d \n\n",Prob());
	return iva;


}


//******************************************************************************

//******************************************************************************

void Recupera(int nmats, int* matva, int* matvm, double* valor, double* valom)
{
	int imats;
	for(imats=1; imats<=nmats; imats++)
 	    matva[imats]=matvm[imats];
	for(imats=1; imats<=10; imats++)
		valor[imats]=valom[imats];
}
//******************************************************************************

//******************************************************************************
void inicializa_array1D( int n, double *v, double cte ){
	for( int i = 1; i <= n; i++ ) v[i] = cte;
}
//******************************************************************************
void escribe_efi_max( int nelem, double *efi_max ){
	for( int ielem = 1; ielem <= nelem; ielem++ )
		fprintf(fp16,"elemento = %d eficiencia_max = %f\n", ielem, efi_max[ielem] );
}


//******************************************************************************
   


