//*****************************
// Rutina Para Optimizar
//*****************************
#pragma hdrstop
#include "Optimizador.h"





std::vector<Individuo> poblacion;
std::vector<Individuo> selec;
std::vector<Individuo> hijos;
std::vector<Individuo> newpob;
std::vector<Individuo> R_pob;

int dimension;
int tam_pob=100;
std::vector<int> max_secciones;
int evaluaciones;

int secciones_max;
std::vector<std::vector<int> > Grafo;
std::vector<std::vector<int> > Grafobarras;
std::vector<std::vector<int> > MatrixAdy;
std::vector<bool> visitados;
std::vector<int> rama;
std::vector<int> bars;
std::vector<int> barras_tent;
Individuo vecino;
int cont_bfs=0;
int num1;
int objtosort;

std::vector<int> bars_cross(){
      int n,num1;
                   
      n=rand()%(Grafo.size());//en que nodo empieza
      num1=rand()%(Grafo.size());//maximo numero de nodos  a recorrer
      bars.clear();//barras conexas
      cont_bfs=0;//cuenta los nodos que se van abriendo
      visitados.clear();//reinicia a los visitados.
      barras_tent.clear();
      BC_barras(n);

    return bars;

}



int Optimizador(int prueba )
{

/**********************
Optimizador
**********************/

srand(time(NULL)); //semilla 

Grafo.resize(npno);
Grafobarras.resize(nele);


MatrixAdy.assign(npno,std::vector<int> (npno,-1));

for(int ielem=1; ielem<=nele; ielem++) {
    
    MatrixAdy[lnod[ielem][1]-1][lnod[ielem][2]-1]=ielem-1;//Llena matriz de adyacencias
    MatrixAdy[lnod[ielem][2]-1][lnod[ielem][1]-1]=ielem-1;
    Grafo[lnod[ielem][1]-1].push_back(lnod[ielem][2]-1);
    Grafo[lnod[ielem][2]-1].push_back(lnod[ielem][1]-1);

}

for(int ielem=1; ielem<=nele; ielem++) {//elementos=cantidad de barras
	
	//printf("%d\n", (int) MatrixAdy[lnod[ielem][1]-1].size());

	for (int i = 0; i < MatrixAdy[lnod[ielem][1]-1].size(); ++i)
	{
		//printf(" m %d\n", MatrixAdy[lnod[ielem][1]-1][i]);
		if (MatrixAdy[lnod[ielem][1]-1][i]!=-1 && MatrixAdy[lnod[ielem][1]-1][i]!=ielem-1)
		{
			Grafobarras[ielem-1].push_back( MatrixAdy[lnod[ielem][1]-1][i]);
			//Grafobarras[MatrixAdy[lnod[ielem][1]-1][i]].push_back(ielem-1);
		}
	}

	for (int i = 0; i < MatrixAdy[lnod[ielem][2]-1].size(); ++i)
	{
		
		if (MatrixAdy[lnod[ielem][2]-1][i]!=-1 && MatrixAdy[lnod[ielem][2]-1][i]!=ielem-1)
		{
			Grafobarras[ielem-1].push_back( MatrixAdy[lnod[ielem][2]-1][i]);
			//Grafobarras[MatrixAdy[lnod[ielem][2]-1][i]].push_back(ielem-1);
		}

	}

 }
    

return 1;

}



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
                 double* fuerc, double* aslod, double* despl, double* fixd, double* react,
                 double* vecta, double* vect1, double* deslo, double* xlong, double* valor,
                 double* valom, double* angulo, double** angulg, double* wcarg, double** vectr,
                 double** astif, double* vectp, double* vectu, char **listaCatalogos, int* ubiCat,
                 double ***vectores_fuerzas, int *npesp, double *efi_max, double *stiff, int neqns,
                  int nwktl){

    double num,n,secc;
    std::vector<double> v;

    for (int i = 0; i < tam_pob; ++i)//recorre  
    {   
        
        
        for (int j = 0; j < dimension; ++j)//recorre secciones segun sea viga o columna
        {
             num=rand()/(double)RAND_MAX;
            //cout<<num<<endl;
            if (num<0.055)//antes en 0.055-(1/(double)nelem)
            {
                secc=1+rand()%(max_secciones[j]+1-1);//necesito saber  cual es el numero maximo de secciones en el catalogo 1-59
                hijos[i].secciones[j]=(int)secc;
                    
            }


            matva[j+1]=hijos[i].secciones[j];
                
        }
    //printf("secciones %d  %d \n",hijos[i].secciones[0],hijos[i].secciones[1]);


//////////////////////////////////////////////////////////////////////////////////////
        v=Funcion_fitness(ishot, npnod,nelem,npres,ncarg,ntipo,ngdln,nmats,ndime,iwrit,isale,nreso,nincl,//QUEDE AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
                                                  nfami,ncaso, nnode,mnode,nprop,ngaus,ntens,nevab,indso,ntotv,lnods,inpre,
                                                  nareas,narerf,narerc,narecon,lreso,lincl,ntips,nodpr,matnu,matva,matvm,
                                                  iffix,indfu,nodea,maxad,mhigh,leqns,coord,carga,carpp,presc,props,fuemp,
                                                  fuepp,rigid,xmasa,vmatr, girom,girtm,tempr,fuefl,fuerb,srmat,smmat,
                                                  cArmaduras,cAceroRF,cAceroRC,cConcr,resor,xincl,fuerc,aslod,despl,fixd,
                                                  react,vecta,vect1,deslo,xlong,valor,valom,angulo,angulg,wcarg,vectr,astif,
                                                  vectp,vectu,listaCatalogos,ubiCat,vectores_fuerzas,npesp,efi_max,stiff,
                                                  neqns, nwktl);//@mg'

                     hijos[i].objs.push_back(v[0]);
               hijos[i].objs.push_back(v[1]);
               hijos[i].pena.push_back(v[2]);
               hijos[i].pena.push_back(v[3]);
               hijos[i].sum_pen=v[2]+v[3];

       /* for (int j = 0; j < nmats; ++j)
        {
             hijos[i].secciones[j]=matva[j+1];//haciendo individuo

            //poblacion[i].secciones.push_back(valor[j+3]);
        }*/
       // printf("pob secciones %d  %d\n", poblacion[i].secciones[0],poblacion[i].secciones[1]);
        for (int j = 1; j < 5; ++j)//4 porque son 4 valores, peso propio,desplazamiento maximo,eficiencia maxima
        {
             hijos[i].valores.push_back(valor[j]);//
            //poblacion[i].secciones.push_back(valor[j+3]);
        }
        hijos[i].desplazamiento=valor[2];
        hijos[i].peso=valor[4];
         hijos[i].efi=valor[3];

        
        v.clear();
    }




}

void BC_barras(int v){//para recorrer grafo GRAFO
  visitados.assign(Grafobarras.size(),false);
  //printf("%d\n",v);
   
  bars.push_back(v);
  cont_bfs++;
  for (int i = 0; i < Grafobarras[v].size(); ++i)
  {
    //printf("tentativos\n");
    barras_tent.push_back(Grafobarras[v][i]);
  }
  
  visitados[v]=true;
  double numrand;

  while(cont_bfs<num1){

    numrand=rand()%(barras_tent.size());
    if (!visitados[barras_tent[numrand]]){

      bars.push_back(barras_tent[numrand]);
      visitados[barras_tent[numrand]]=true;
      //printf("%d\n",barras_tent[numrand]);

      for (int i = 0; i < Grafobarras[barras_tent[numrand]].size(); ++i)
      {
        barras_tent.push_back(Grafobarras[barras_tent[numrand]][i]);
      }
      cont_bfs++;

    }




  }

}





std::vector<double> Funcion_fitness( int ishot, int npnod, int nelem, int npres, int ncarg, int ntipo, int ngdln, int nmats,
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
                 double* fuerc, double* aslod, double* despl, double* fixd, double* react,
                 double* vecta, double* vect1, double* deslo, double* xlong, double* valor,
                 double* valom, double* angulo, double** angulg, double* wcarg, double** vectr,
                 double** astif, double* vectp, double* vectu, char **listaCatalogos, int* ubiCat,
                 double ***vectores_fuerzas, int *npesp, double *efi_max, double *stiff, int neqns,
                  int nwktl){//@mg 



    double dd,de,penalizacion1=0.0,penalizacion2=0.0;
    std::vector<double> fitness;
    double penaliza = 1.e12;
   // bool Optimiza = true;
    bool generaMatRigidez,Optimiza=true;
    int ival, casoCarga;

    
   
    CargaPropCatOpt(matva,ndime,nmats,props,cArmaduras.arear,cAceroRF.arerf,cAceroRC.arerc,cConcr.arecr,ubiCat);
        valor[2] = 0.0; // Para guardar el desplazamiento maximo
        valor[3] = 0.0; // Para guardar la eficiencia maxima
        generaMatRigidez = true;


        for( casoCarga = 1; casoCarga <= ncarg; casoCarga++ ){
            // Escoge el vector de fuerzas del caso de carga
          escoge_vector_fuerza(casoCarga,nelem,nevab,carga,vectores_fuerzas);
            // Incluye las fuerzas de peso propio al vector de fuerzas

          incluye_peso_propio(npesp[casoCarga],nelem,ndime,ntipo,lnods,matnu,ntips,coord,
                             xlong,props,vectr,carga);

            // Determina el vector de fueras de empotramiento perfecto
            //      vector_fuer_emp_perf(nelem,nevab,fuemp,carga);
          ival = Estatico( nelem,npnod,nevab,ndime,ntipo,ncaso,npres,false,indso,isale,ngdln,nnode,
                     ntotv,nincl,nreso,neqns,nwktl,ishot,lnods,matnu,inpre,iffix,ntips,maxad,
                     nodea,nodpr,leqns,lincl,lreso,react,coord,presc,fixd,despl,aslod,stiff,
                     srmat,props,xlong,vectr,rigid,carpp,fuepp,carga,fuemp,girom,girtm,tempr,
                     fuerc,valor,cArmaduras.arear,cAceroRF.arerf,cAceroRC.arerc,cConcr.arecr,
                     cConcr.dtcon,indfu,fuerb,fuefl,wcarg,xincl,resor,astif,vectp,vectu,vect1,
                     deslo,ubiCat,efi_max,generaMatRigidez,Optimiza);
            // Ya se genero una vez la matriz de rigidez
          generaMatRigidez = false;
        }

    dd = valor[2]-10.0;  // Castiga desplazamientos mayores a 10cm. Aparentemente aqui podemos poner claro/norma.
    de = valor[3]-1.0;   // Castiga eficiencia maxima. Ahorita la trata de llevar al 100%.
    valor[4]=valor[1];   // Peso de la estructura total.
            
            if (de >0) penalizacion1=de*penaliza;
            if (dd >0) penalizacion2=dd*penaliza;
   // fitness= valor[4];
    fitness.push_back(valor[4]+penalizacion1+penalizacion2);// mg se agrega al valor de la funcion //PESO 
    fitness.push_back(valor[2]+penalizacion1+penalizacion2);// mg se agrega al valor de la funcion  //DESPLAZAMIENTO
    fitness.push_back(penalizacion1);
    fitness.push_back(penalizacion2);
    fitness.push_back(valor[2]);
    fitness.push_back(valor[3]);
    fitness.push_back(valor[4]);
    evaluaciones++;
    
   /* printf(" En Funcion_fitness \n ",fitness);

    for(int i=1;i<=nelem;i++){
        printf(" %d ",matva[i]);
    }

     printf(" %lf \n ",fitness);*/
  

    return fitness;//DEVUELVE: obj1 obj2 penalizacion1 penalizacion 2


}


void Actualiza(int nmats, int* matva, int* matvm, double* valor, double* valom)
{
  int imats;
  //printf("aceptado \n");
  for(imats=1; imats<=nmats; imats++)
      matvm[imats]=matva[imats];
  for(imats=1; imats<=10; imats++)
    valom[imats]=valor[imats];
}
void Inicializa_Materiales( int nmats, int ndime, double** props, int* matva,
              int *Arm_tamCat, int *RF_tamCat, int *RC_tamCat,
              int *Con_tamCat, int *ubiCat ){
  // Inicia los materiales con la seccion ultima, la de mayor area transversal,
  // de cada catalogo. En el catalogo deben estar ordenadas de menor a mayor
  // en cuanto a area.
  int imats, rolado, iCat;
  for( imats = 1; imats <= nmats; imats++ ){
    //if( ndime ==2 ) rolado = (int)props[imats][5] + 0.5;
    //if( ndime ==3 )
        rolado = (int)props[imats][8] + 0.5;
    iCat = ubiCat[imats];
    switch( rolado ){
      case 0:
        matva[imats] = Arm_tamCat[iCat];
        break;
      case 1:
        matva[imats] = RF_tamCat[iCat];
        break;
      case 2:
        matva[imats] = RC_tamCat[iCat];
        break;
      case 3:
        matva[imats] = Con_tamCat[iCat];
        break;
      default:
        break;
    }
  }
}
//***********************************************************************************************************
//***********************************************************************************************************







