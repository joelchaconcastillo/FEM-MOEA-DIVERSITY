#ifndef _RECOMBINATION_H_
#define _RECOMBINATION_H_

#include "global.h"
#include "individual.h"
#include "OPTBAR/Optimizador.h"



// crossover to OPT_BAR
void Crossover_bybars(CIndividual &parent1, CIndividual &parent2, CIndividual &child1, CIndividual &child2){
    
        std::vector<int> bars;
        int aux,unif,n;

            //num=rand()/(double)RAND_MAX;

            if(rnd_uni(&rnd_uni_init) < 0.8){//PROBABILIDAD DE CROSSOVER

                bars=bars_cross();

               
                

                for (int i = 0; i < bars.size(); ++i)
                {
                    child1.x_var[bars[i]]=parent2.x_var[bars[i]];
                    child2.x_var[bars[i]]=parent1.x_var[bars[i]];
                }



            }else{

                for (int l = 0; l < parent1.x_var.size(); ++l)
                {
                    child1.x_var[l] = parent1.x_var[l];
                    child2.x_var[l] = parent2.x_var[l];
                }

            }

            bars.clear();

}

//Mutation by var
void mutation_var(CIndividual &ind){

    double num;
    int    secc;


    for (int j = 0; j < ind.x_var.size(); ++j)//recorre secciones segun sea viga o columna
    {
        //cout<<num<<endl;
            if (rnd_uni(&rnd_uni_init)<= 0.055)//antes en 0.055-(1/(double)nelem)
            {
                secc = int(rnd_uni(&rnd_uni_init)*(max_seccion-1))+1;
                ind.x_var[j]=secc;
                    
            }


    }
}

/* Routine for real polynomial mutation of an T */
void realmutation(CIndividual &ind)
{
    double rnd, delta1, delta2, mut_pow, deltaq;
    double y, yl, yu, val, xy;
	double eta_m = etam;

	int    id_rnd = int(rnd_uni(&rnd_uni_init)*nvar);

    for (int j=0; j<nvar; j++)
    {
        if (rnd_uni(&rnd_uni_init)<= realm)
        {
            y  = ind.x_var[j];
            yl = vlowBound[j];
            yu = vuppBound[j];
            delta1 = (y-yl)/(yu-yl);
            delta2 = (yu-y)/(yu-yl);
            rnd = rnd_uni(&rnd_uni_init);
            mut_pow = 1.0/(eta_m+1.0);
            if (rnd <= 0.5)
            {
                xy = 1.0-delta1;
                val = 2.0*rnd+(1.0-2.0*rnd)*(pow(xy,(eta_m+1.0)));
                deltaq =  pow(val,mut_pow) - 1.0;
            }
            else
            {
                xy = 1.0-delta2;
                val = 2.0*(1.0-rnd)+2.0*(rnd-0.5)*(pow(xy,(eta_m+1.0)));
                deltaq = 1.0 - (pow(val,mut_pow));
            }
            y = y + deltaq*(yu-yl);
            if (y<yl)
                y = yl;
            if (y>yu)
                y = yu;
            ind.x_var[j] = y;
        }
    }
    return;
}


/* Routine for real variable SBX crossover */
void real_sbx_xoverA(CIndividual &parent1, CIndividual &parent2, CIndividual &child1, CIndividual &child2)
{
    double rand;
    double y1, y2, yl, yu;
    double c1, c2;
    double alpha, beta, betaq;
	double eta_c = etax;
    if (rnd_uni(&rnd_uni_init) <= realx) 
    {
        for (int i=0; i<nvar; i++)
        {
            if (rnd_uni(&rnd_uni_init)<=0.5 )
            {
                if (fabs(parent1.x_var[i]-parent2.x_var[i]) > EPS)
                {
                    if (parent1.x_var[i] < parent2.x_var[i])
                    {
                        y1 = parent1.x_var[i];
                        
                        y2 = parent2.x_var[i];
                    }
                    else
                    {
                        y1 = parent2.x_var[i];
                        y2 = parent1.x_var[i];
                    }
                    yl = vlowBound[i];
                    yu = vuppBound[i];
                    rand = rnd_uni(&rnd_uni_init);
                    beta = 1.0 + (2.0*(y1-yl)/(y2-y1));
                    alpha = 2.0 - pow(beta,-(eta_c+1.0));
                    if (rand <= (1.0/alpha))
                    {
                        betaq = pow ((rand*alpha),(1.0/(eta_c+1.0)));
                    }
                    else
                    {
                        betaq = pow ((1.0/(2.0 - rand*alpha)),(1.0/(eta_c+1.0)));
                    }
                    c1 = 0.5*((y1+y2)-betaq*(y2-y1));
                    beta = 1.0 + (2.0*(yu-y2)/(y2-y1));
                    alpha = 2.0 - pow(beta,-(eta_c+1.0));
                    if (rand <= (1.0/alpha))
                    {
                        betaq = pow ((rand*alpha),(1.0/(eta_c+1.0)));
                    }
                    else
                    {
                        betaq = pow ((1.0/(2.0 - rand*alpha)),(1.0/(eta_c+1.0)));
                    }
                    c2 = 0.5*((y1+y2)+betaq*(y2-y1));
                    if (c1<yl)
                        c1=yl;
                    if (c2<yl)
                        c2=yl;
                    if (c1>yu)
                        c1=yu;
                    if (c2>yu)
                        c2=yu;
                    if (rnd_uni(&rnd_uni_init)<=0.5)
                    {
                        child1.x_var[i] = c2;
                        child2.x_var[i] = c1;
                    }
                    else
                    {
                        child1.x_var[i] = c1;
                        child2.x_var[i] = c2;
                    }
                }
                else
                {
                    child1.x_var[i] = parent1.x_var[i];
                    child2.x_var[i] = parent2.x_var[i];
                }
            }
            else
            {
                child1.x_var[i] = parent1.x_var[i];
                child2.x_var[i] = parent2.x_var[i];
            }
        }
    }
    else
    {
        for (int i=0; i<nvar; i++)
        {
            child1.x_var[i] = parent1.x_var[i];
            child2.x_var[i] = parent2.x_var[i];
        }
    }
    return;
}

void real_sbx_xoverB (CIndividual &parent1, CIndividual &parent2, CIndividual &child)
{
    double rand;
    double y1, y2, yl, yu;
    double c1, c2;
    double alpha, beta, betaq;
	double eta_c = etax;
    if (rnd_uni(&rnd_uni_init) <= realx) 
    {
        for (int i=0; i<nvar; i++)
        {
            if (rnd_uni(&rnd_uni_init) <= 0.5 )
            {
                if (fabs(parent1.x_var[i]-parent2.x_var[i]) > EPS)
                {
                    if (parent1.x_var[i] < parent2.x_var[i])
                    {
                        y1 = parent1.x_var[i];
                        y2 = parent2.x_var[i];
                    }
                    else
                    {
                        y1 = parent2.x_var[i];
                        y2 = parent1.x_var[i];
                    }
                    yl = vlowBound[i];
                    yu = vuppBound[i];
                    rand = rnd_uni(&rnd_uni_init);
                    beta = 1.0 + (2.0*(y1-yl)/(y2-y1));
                    alpha = 2.0 - pow(beta,-(eta_c+1.0));
                    if (rand <= (1.0/alpha))
                    {
                        betaq = pow ((rand*alpha),(1.0/(eta_c+1.0)));
                    }
                    else
                    {
                        betaq = pow ((1.0/(2.0 - rand*alpha)),(1.0/(eta_c+1.0)));
                    }
                    c1 = 0.5*((y1+y2)-betaq*(y2-y1));
                    beta = 1.0 + (2.0*(yu-y2)/(y2-y1));
                    alpha = 2.0 - pow(beta,-(eta_c+1.0));
                    if (rand <= (1.0/alpha))
                    {
                        betaq = pow ((rand*alpha),(1.0/(eta_c+1.0)));
                    }
                    else
                    {
                        betaq = pow ((1.0/(2.0 - rand*alpha)),(1.0/(eta_c+1.0)));
                    }
                    c2 = 0.5*((y1+y2)+betaq*(y2-y1));
                    if (c1<yl)
                        c1=yl;
                    if (c2<yl)
                        c2=yl;
                    if (c1>yu)
                        c1=yu;
                    if (c2>yu)
                        c2=yu;
                    if (rnd_uni(&rnd_uni_init)<=0.5)
                    {
                        child.x_var[i] = c2;
                    }
                    else
                    {
                        child.x_var[i] = c1;
                    }
                }
                else
                {
                    child.x_var[i] = parent1.x_var[i];
                }
            }
            else
            {
                child.x_var[i] = parent1.x_var[i];
            }
        }
    }
    else
    {
        for (int i=0; i<nvar; i++)
        {
            child.x_var[i] = parent1.x_var[i];
        }
    }
    return;
}
void real_sbx_hybrid(CIndividual &parent1, CIndividual &parent2, CIndividual &child1, CIndividual &child2, int max_nfes, int nfes)
{
    double rand;
    double y1, y2, yl, yu;
    double c1, c2;
    double alpha, beta, betaq;
	double eta_c = etax;

    double prob_var = 1.0 - ((double)nfes/max_nfes);
    prob_var = max(0.5, prob_var);



    if (rnd_uni(&rnd_uni_init) <= 0.9) 
    {
        for (int i=0; i<nvar; i++)
        {
            if (rnd_uni(&rnd_uni_init)<= prob_var )
            {
                if (fabs(parent1.x_var[i]-parent2.x_var[i]) > EPS)
                {
                    if (parent1.x_var[i] < parent2.x_var[i])
                    {
                        y1 = parent1.x_var[i];
                        y2 = parent2.x_var[i];
                    }
                    else
                    {
                        y1 = parent2.x_var[i];
                        y2 = parent1.x_var[i];
                    }
                    yl = vlowBound[i];
                    yu = vuppBound[i];
                    rand = rnd_uni(&rnd_uni_init);
                    beta = 1.0 + (2.0*(y1-yl)/(y2-y1));
                    alpha = 2.0 - pow(beta,-(eta_c+1.0));
                    if (rand <= (1.0/alpha))
                    {
                        betaq = pow ((rand*alpha),(1.0/(eta_c+1.0)));
                    }
                    else
                    {
                        betaq = pow ((1.0/(2.0 - rand*alpha)),(1.0/(eta_c+1.0)));
                    }
                    c1 = 0.5*((y1+y2)-betaq*(y2-y1));
                    beta = 1.0 + (2.0*(yu-y2)/(y2-y1));
                    alpha = 2.0 - pow(beta,-(eta_c+1.0));
                    if (rand <= (1.0/alpha))
                    {
                        betaq = pow ((rand*alpha),(1.0/(eta_c+1.0)));
                    }
                    else
                    {
                        betaq = pow ((1.0/(2.0 - rand*alpha)),(1.0/(eta_c+1.0)));
                    }
                    c2 = 0.5*((y1+y2)+betaq*(y2-y1));
                    if (c1<yl)
                        c1=yl;
                    if (c2<yl)
                        c2=yl;
                    if (c1>yu)
                        c1=yu;
                    if (c2>yu)
                        c2=yu;
                    //if (rnd_uni(&rnd_uni_init)<=0.5)
                    //{
                    //    child1.x_var[i] = c2;
                    //    child2.x_var[i] = c1;
                    //}
                    //else
                    //{
                        child1.x_var[i] = c1;
                        child2.x_var[i] = c2;
                    //}
                }
                else
                {
                    child1.x_var[i] = parent1.x_var[i];
                    child2.x_var[i] = parent2.x_var[i];
                }
            }
            else
            {
                child1.x_var[i] = parent1.x_var[i];
                child2.x_var[i] = parent2.x_var[i];
            }
        }
    }
    else
    {
        for (int i=0; i<nvar; i++)
        {
            child1.x_var[i] = parent1.x_var[i];
            child2.x_var[i] = parent2.x_var[i];
        }
    }
    return;
}

void diff_evo_xoverA(CIndividual &ind0, CIndividual &ind1, CIndividual &ind2, CIndividual &ind3, CIndividual &child, double rate)
{

	// Check Whether the cross-over to be performed
	/*Loop over no of variables*/
	int idx_rnd = int(rnd_uni(&rnd_uni_init)*nvar);

	for(int n=0;n<nvar;n++)
	{
	  double rnd = rnd_uni(&rnd_uni_init);
	  if(rnd<1||n==idx_rnd)
		  child.x_var[n] = ind1.x_var[n] + rate*(ind2.x_var[n] - ind3.x_var[n]);
	  else
		  child.x_var[n] = ind0.x_var[n];

	  if(child.x_var[n]<vlowBound[n]) child.x_var[n] = vlowBound[n];
	  if(child.x_var[n]>vuppBound[n]) child.x_var[n] = vuppBound[n];
	}
}

//diff_evo_xoverB
void diff_evo_xoverB(CIndividual &ind0, CIndividual &ind1, CIndividual &ind2, CIndividual &child, double rate)
{
	int idx_rnd = int(rnd_uni(&rnd_uni_init)*nvar);


    double CR   = 0.1;//  (rnd_uni(&rnd_uni_init)<0.5)?0.2:1.0;
	for(int n=0;n<nvar;n++)
	{
	  /*Selected Two Parents*/

	  // strategy one 
	  // child.x_var[n] = ind0.x_var[n] + rate*(ind2.x_var[n] - ind1.x_var[n]);
	  
	  //*
	  // strategy two

	  double rnd1 = rnd_uni(&rnd_uni_init);
	  //double CR   = 1.0;
	  if(rnd1<CR||n==idx_rnd)
		  child.x_var[n] = ind0.x_var[n] + (rate)*(ind2.x_var[n] - ind1.x_var[n]);
	  else
		  child.x_var[n] = ind0.x_var[n];
	  //*/

	  // handle the boundary voilation
//	  if(child.x_var[n]<vlowBound[n]){
//	          double rnd = rnd_uni(&rnd_uni_init);
////	          double rnd =-0.1+1.2*rnd_uni(&rnd_uni_init);
// 	       //child.x_var[n] = vlowBound[n] + rnd*(vuppBound[n] - vlowBound[n]);
// 	        child.x_var[n] = vlowBound[n] + rnd*(ind0.x_var[n] - vlowBound[n]);
//	  }
//	  if(child.x_var[n]>vuppBound[n]){ 
//	          double rnd = rnd_uni(&rnd_uni_init);
//	          //double rnd =-0.1+1.2*rnd_uni(&rnd_uni_init);
// 	        //child.x_var[n] = vlowBound[n] + rnd*(vuppBound[n] - vlowBound[n]);
//	        child.x_var[n] = vuppBound[n] - rnd*(vuppBound[n] - ind0.x_var[n]);
//	  }
	  if(child.x_var[n]<vlowBound[n]) child.x_var[n] = vlowBound[n];
	  if(child.x_var[n]>vuppBound[n]) child.x_var[n] = vuppBound[n];
	}
}
void diff_evo_xoverC(CIndividual &ind0, CIndividual &ind1, CIndividual &ind2, std::vector<double> &xdiff,  CIndividual &child,  double rate)
{
      double rnd = rnd_uni(&rnd_uni_init), rnd2 = rnd_uni(&rnd_uni_init);
	  for(int n=0;n<nvar;n++)
	  {
		  /*Selected Two Parents*/
		  
		  if(rnd<1)
		      child.x_var[n] = ind0.x_var[n] + rate*(ind2.x_var[n] - ind1.x_var[n]);
		  else
			  child.x_var[n] = ind0.x_var[n] + rnd2*xdiff[n];
	
		  if(child.x_var[n]<vlowBound[n]) child.x_var[n] = vlowBound[n];
		  if(child.x_var[n]>vuppBound[n]) child.x_var[n] = vuppBound[n];
	  }
}
void diff_evo_xoverD(CIndividual &ind0, CIndividual &ind1, CIndividual &ind2,  CIndividual &ind3, CIndividual &child, double rate)
{
	int idx_rnd = int(rnd_uni(&rnd_uni_init)*nvar);

	for(int n=0;n<nvar;n++)
	{
	  /*Selected Two Parents*/

	  // strategy one 
	  // child.x_var[n] = ind0.x_var[n] + rate*(ind2.x_var[n] - ind1.x_var[n]);
	  
	  //*
	  // strategy two
	  double rnd1 = rnd_uni(&rnd_uni_init);
	  //rate = rnd_uni(&rnd_uni_init);
	  //double CR   = 1.0;
	  double CR   = 0.9;
	  if(rnd1<CR||n==idx_rnd)
	  {
		  child.x_var[n] = ind0.x_var[n] + rate*(ind3.x_var[n] - ind0.x_var[n])+  rate*(ind2.x_var[n] - ind1.x_var[n]);
	  }
	  else
		  child.x_var[n] = ind0.x_var[n];
	  //*/

	  // handle the boundary voilation
	  if(child.x_var[n]<vlowBound[n]){
	          double rnd = rnd_uni(&rnd_uni_init);
 	        //child.x_var[n] = vlowBound[n] + rnd*(vuppBound[n] - vlowBound[n]);
 	        child.x_var[n] = vlowBound[n] + rnd*(ind0.x_var[n] - vlowBound[n]);
	  }
	  if(child.x_var[n]>vuppBound[n]){ 
	          double rnd = rnd_uni(&rnd_uni_init);
 	        //child.x_var[n] = vlowBound[n] + rnd*(vuppBound[n] - vlowBound[n]);
	        child.x_var[n] = vuppBound[n] - rnd*(vuppBound[n] - ind0.x_var[n]);
	  }
	  if(child.x_var[n]<lowBound) child.x_var[n] = lowBound;
	  if(child.x_var[n]>uppBound) child.x_var[n] = uppBound;
	}
}
void HBX(CIndividual &ind0, CIndividual &ind1, CIndividual &ind2, CIndividual &child, double Pc)
{
	int idx_rnd = int(rnd_uni(&rnd_uni_init)*nvar);
	double p1=0.9, p2=0.2;
	double rate = 0.5;
	double rand;
	double y1, y2, yl, yu;
    	double c1, c2;
    	double alpha, beta, betaq;
	double eta_c = etax;
	if(rnd_uni(&rnd_uni_init) < Pc )
	{
		for(int n=0;n<nvar;n++)
		{
			double c_i, v_i;
			if(rnd_uni(&rnd_uni_init) < p1) 
			{
				//Generate u_i
				if (rnd_uni(&rnd_uni_init)<=0.5 )
				    {
					if (fabs(ind0.x_var[n]-ind1.x_var[n]) > EPS)
					{
					    if (ind0.x_var[n] < ind1.x_var[n])
					    {
						y1 = ind0.x_var[n];
						y2 = ind1.x_var[n];
					    }
					    else
					    {
						y1 = ind1.x_var[n];
						y2 = ind0.x_var[n];
					    }
					    yl = vlowBound[n];
					    yu = vuppBound[n];
					    rand = rnd_uni(&rnd_uni_init);
					    beta = 1.0 + (2.0*(y1-yl)/(y2-y1));
					    alpha = 2.0 - pow(beta,-(eta_c+1.0));
					    if (rand <= (1.0/alpha))
					    {
						betaq = pow ((rand*alpha),(1.0/(eta_c+1.0)));
					    }
					    else
					    {
						betaq = pow ((1.0/(2.0 - rand*alpha)),(1.0/(eta_c+1.0)));
					    }
					    c1 = 0.5*((y1+y2)-betaq*(y2-y1));
					    beta = 1.0 + (2.0*(yu-y2)/(y2-y1));
					    alpha = 2.0 - pow(beta,-(eta_c+1.0));
					    if (rand <= (1.0/alpha))
					    {
						betaq = pow ((rand*alpha),(1.0/(eta_c+1.0)));
					    }
					    else
					    {
						betaq = pow ((1.0/(2.0 - rand*alpha)),(1.0/(eta_c+1.0)));
					    }
					    c2 = 0.5*((y1+y2)+betaq*(y2-y1));
					    if (c1<yl)
						c1=yl;
					    if (c2<yl)
						c2=yl;
					    if (c1>yu)
						c1=yu;
					    if (c2>yu)
						c2=yu;
					    if (rnd_uni(&rnd_uni_init)<=0.5)
					    {
						//child.x_var[i] = c2;
						c_i = c2;
					    }
					    else
					    {
						//child.x_var[i] = c1;
						c_i = c1;
					    }
					}
					else
					{
					    //child.x_var[n] = ind0.x_var[n];
					    c_i = ind0.x_var[n];
					}
				    }
				//Generate v_i
				 v_i = ind0.x_var[n] + rate*(ind2.x_var[n] - ind1.x_var[n]);
				
				if(rnd_uni(&rnd_uni_init) < p2 )
					child.x_var[n] = c_i;
				else
				   child.x_var[n] = v_i;
			}
			else 
		 	   child.x_var[n] = ind1.x_var[n];


			if(child.x_var[n]<vlowBound[n]){
				  double rnd = rnd_uni(&rnd_uni_init);
				child.x_var[n] = vlowBound[n] + rnd*(ind0.x_var[n] - vlowBound[n]);
			  }
			  if(child.x_var[n]>vuppBound[n]){ 
				  double rnd = rnd_uni(&rnd_uni_init);
				child.x_var[n] = vuppBound[n] - rnd*(vuppBound[n] - ind0.x_var[n]);
			  }
		}

			  


	}
	else
	{
		for (int i=0; i<nvar; i++)
		{
		    child.x_var[i] = ind0.x_var[i];
		}
	}
   return;
}




bool diff_evo_xoverB_Bounded(CIndividual &ind0, CIndividual &ind1, CIndividual &ind2, CIndividual &child, double rate)
{
	int idx_rnd = int(rnd_uni(&rnd_uni_init)*nvar);
	double scalebounds = INFINITY, scalebounds_middle = INFINITY;
	bool flag = false;
	for(int n=0;n<nvar;n++)
	{
	  	
	  // strategy two
	  double rnd1 = rnd_uni(&rnd_uni_init);
	  //rate = rnd_uni(&rnd_uni_init);
//	  double CR   = 1.0;
	  double CR   = 0.9;
	  if(rnd1<CR||n==idx_rnd)
		  child.x_var[n] = ind0.x_var[n] + rate*(ind2.x_var[n] - ind1.x_var[n]);
	  else
		  child.x_var[n] = ind0.x_var[n];
//	   if(child.x_var[n] > vuppBound[n])
//	   scalebounds = min(scalebounds,  (vuppBound[n] - ind0.x_var[n])/(child.x_var[n] -ind0.x_var[n]) );
//	   if(child.x_var[n] < vlowBound[n])
//	   scalebounds = min(scalebounds,  ( ind0.x_var[n]-vlowBound[n] )/(ind0.x_var[n] - child.x_var[n]) );

	   //diff[n] = ind0.var[n] - child.x_var[n];
	  //*/
	  // handle the boundary voilation
//	  if(child.x_var[n]<vlowBound[n]){
//		  double rnd = rnd_uni(&rnd_uni_init);
// 		child.x_var[n] = vlowBound[n] + rnd*(ind0.x_var[n] - vlowBound[n]);
//	  }
//	  if(child.x_var[n]>vuppBound[n]){ 
//		  double rnd = rnd_uni(&rnd_uni_init);
//		child.x_var[n] = vuppBound[n] - rnd*(vuppBound[n] - ind0.x_var[n]);
//	  }
	//  if(child.x_var[n]<lowBound) child.x_var[n] = lowBound;
	//  if(child.x_var[n]>uppBound) child.x_var[n] = uppBound;
	if(child.x_var[n]<vlowBound[n] || child.x_var[n]>vuppBound[n]) return true; //flag = true;
	}
return false;
	
//	child = ind0;
//         realmutation(child, nvar); return;
//          if(!flag) return;

	double F1 = scalebounds; 
	double F2 = F1/2.0;
        double rnd, delta1, delta2, mut_pow, deltaq;
        double y, yl, yu, val, xy;
	double eta_m = 2;
	
	//Generate the randum number apply the difference....
	    y  = F2;
            yl = 0.0;
            yu = F1;
            delta1 = (y-yl)/(yu-yl);
            delta2 = (yu-y)/(yu-yl);
            rnd = rnd_uni(&rnd_uni_init);
            mut_pow = 1.0/(eta_m+1.0);
            if (rnd <= 0.5)
            {
                xy = 1.0-delta1;
                val = 2.0*rnd+(1.0-2.0*rnd)*(pow(xy,(eta_m+1.0)));
                deltaq =  pow(val,mut_pow) - 1.0;
            }
            else
            {
                xy = 1.0-delta2;
                val = 2.0*(1.0-rnd)+2.0*(rnd-0.5)*(pow(xy,(eta_m+1.0)));
                deltaq = 1.0 - (pow(val,mut_pow));
            }
            y = y + deltaq*(yu-yl);
            if (y<yl)
                y = yl;
            if (y>yu)
                y = yu;
//		cout << F2 <<endl;;// getchar();
//	cout << F1<< " " << F2<< " "<< y <<endl;
	if(F1 < 0.000001) y = 0.0;
	y = rnd_uni(&rnd_uni_init)*F1;
	for(int n=0;n<nvar;n++)
	{
	//	cout << y << " "<< y*(child.x_var[n]);
	 //  if( child.x_var[n] > vlowBound[n])
	 //   child.x_var[n] =  F1*( child.x_var[n]);
	//   if(child.x_var[n]  < vlowBound[n] )
	//    child.x_var[n] = ind0.x_var[n] + F1*( child.x_var[n] - ind0.x_var[n] );

//		cout << child.x_var[n] << " || "<< vlowBound[n] << " BASE I " << ind0.x_var[n] << " " << vuppBound[n]<<endl;
	    // if(child.x_var[n] > ind0.x_var[n])
	    child.x_var[n] = ind0.x_var[n] + y*( child.x_var[n]-ind0.x_var[n] );
	    //else
	    //child.x_var[n] = ind0.x_var[n] - F1*( ind0.x_var[n] - child.x_var[n]);
//	cout << y << " "<< F1 << " "<<F2<<endl;
		child.x_var[n] = max(child.x_var[n], vlowBound[n] );
		child.x_var[n] = min(child.x_var[n], vuppBound[n] );
//	if(child.x_var[n] < 0  ||child.x_var[n] > 1 )
//		{
//		cout << child.x_var[n] << " || "<< vlowBound[n] << " BASE I " << ind0.x_var[n] << " " << vuppBound[n]<<endl;
//		getchar();
//		}
	}
//	getchar();
}
#endif
