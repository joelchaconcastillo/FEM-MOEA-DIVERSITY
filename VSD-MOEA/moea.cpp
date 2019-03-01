/*==========================================================================
// //  Author: Carlos Segura, Joel Chacón 
//     Description: 
//
// ===========================================================================*/


#include "algorithm.h"
//#include <omp.h>

void InitializeBounds(int nvar, char * Instance)
{
	if( !strcmp("UF1", Instance) || !strcmp("UF2", Instance) || !strcmp("UF3", Instance) || !strcmp("UF4", Instance) || !strcmp("UF5", Instance) || !strcmp("UF6", Instance) || !strcmp("UF7", Instance) || !strcmp("UF8", Instance) || !strcmp("UF9", Instance) || !strcmp("UF10", Instance))
	{
		for(int i = 0 ;  i < nvar; i++)
		{
		   vlowBound[i]=0.0;
		   vuppBound[i]=1.0;//2.0*(i+1.0);
		}
	}
	
	if( !strcmp("WFG1", Instance) || !strcmp("WFG2", Instance) || !strcmp("WFG3", Instance) || !strcmp("WFG4", Instance) || !strcmp("WFG5", Instance) || !strcmp("WFG6", Instance) || !strcmp("WFG7", Instance) || !strcmp("WFG8", Instance) || !strcmp("WFG9", Instance))
	{
		for(int i = 0 ;  i < nvar; i++)
		{
		   vlowBound[i]=0.0;
		   vuppBound[i]=2.0*(i+1.0);
		}
	}
	if( !strcmp("DTLZ1", Instance) || !strcmp("DTLZ2", Instance) || !strcmp("DTLZ3", Instance) || !strcmp("DTLZ4", Instance) || !strcmp("DTLZ5", Instance) || !strcmp("DTLZ6", Instance) || !strcmp("DTLZ7", Instance) )
	{
		for(int i = 0 ;  i < nvar; i++)
		{
		   vlowBound[i]=0.0;
		   vuppBound[i]=1.0;
		}
	}
	if( !strcmp("RWP1", Instance))
        {
                for(int i = 0 ;  i < nvar; i++)
                {
                   vlowBound[i]=0.0;
                   vuppBound[i]=1.0;
                }
        }
        if( !strcmp("RWP2", Instance))
        {
                for(int i = 0 ;  i < nvar; i++)
                {
                   vlowBound[i]=1.0;
                   vuppBound[i]=3.0;
                }
        }

}
void PrintHelp()
{
	cout << "Instructions:"<<endl;
	cout << "--Instance NAMEINSTANCE (WFG1)"<<endl;
	cout << "--Seed (299)" <<endl;
	cout << "--Px (0.9), is the Crossover probability" <<endl;
	cout << "--Pm (1/n), is the Mutation Probability " << endl;
	cout << "--Path ./RESULT, is the directory where will save results, inside should be POF (fronts) and POS (decision variable fronts) directories"<<endl;
	cout << "--n 100, is the number of individual by generation"<<endl;
	cout << "--nfes, 25000, is the number of function evaluations"<<endl;
	cout << "--Dist_factor 0.75 , initial valor of diversity D"<<endl;
	cout << "--param_l distance parameter (just WFG instances)"<<endl;
	cout << "--param_k distance parameter (just WFG instances)"<<endl;
	cout << "--nvar number of decision variables"<<endl;
	cout << "--nobj number of objectives"<<endl;
	cout << "example: \"./Ejecutable --n 100 --nfes 2500000 --nvar 6 --Instance DTLZ1 --Path . --Dist_factor 0.1 --nobj 2\""<<endl;
}
void SetConfiguration(int argc, char*argv[])
{
	for(int i = 1; i < argc ; i++)
    	{
		string Terminal(argv[i]);
		if( Terminal == "--Instance")
			strcpy(strTestInstance, argv[++i]);
		else if(Terminal == "--Seed")
			run = atoi(argv[++i]);
		else if(Terminal == "--Px")
			realx = atof(argv[++i]);
		else if(Terminal == "--Pm")
			realm= atof(argv[++i]);
		else if(Terminal == "--Path")
			strcpy(currentPATH, argv[++i]);
		else if(Terminal =="--n")
			pops= atoi(argv[++i]);
		else if(Terminal =="--nobj")
			nobj= atoi(argv[++i]);
		else if(Terminal == "--nfes")
			max_nfes = atoi(argv[++i]);
		else if(Terminal == "--nvar")
			nvar = atoi(argv[++i]);
		else if(Terminal == "--param_l")
			param_l = atoi(argv[++i]);
		else if(Terminal == "--param_k")
			param_k = atoi(argv[++i]);
		else if(Terminal == "--Dist_factor")
			Initial_lowest_distance_factor= atof(argv[++i]);
		else if(Terminal == "--help" || Terminal == "--h")
			PrintHelp();
		else
		{
			cout << Terminal<<endl;
			cout << "Unknown Argument...";
			exit(0);
		}
	    }
	if( realm == -1) realm = 1.0/nvar;
	Initial_lowest_distance_factor *=sqrt(nvar);
}
int main(int argc, char *argv[])
{

	if(argc<2)
         {
	    
	    cout << "Unknown Argument.."<<endl;
	    PrintHelp();
	    exit(0);
	 }
	strcpy(currentPATH, ".");
	SetConfiguration(argc, argv);


	InitializeBounds(nvar, strTestInstance);

	clock_t start, temp, finish;
	double  duration, last = 0;
	start = clock();

	std::fstream fout;
	char logFilename[1024];
	sprintf(logFilename, "%s/LOG/LOG_MOEAD_%s.dat", currentPATH, strTestInstance);
	fout.open(logFilename,std::ios::out);
	fout<<"Inst: "<<strTestInstance<<endl;
	fout<<"Time: \n\n";
	MOEA MOEAD;
	MOEAD.exec_emo(run);
	temp = clock();
	duration = (double)(temp - start) / CLOCKS_PER_SEC;
	last = duration;

	fout<<"\n\n";

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	fout.close();
	return 0;

}
