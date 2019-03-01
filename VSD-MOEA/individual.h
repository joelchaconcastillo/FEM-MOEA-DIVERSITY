#ifndef __INDIVIDUAL_H_
#define __INDIVIDUAL_H_

#include "global.h"
#include "problem.h"

class CIndividual{
public:
	CIndividual();
	virtual ~CIndividual();

	vector <double> x_var;
	vector <double> y_obj;
	vector <CIndividual *> ptr_dominate;
	int    rank;
	double nearest_variable_distance;
	double neares_objective_distance;
	double times_dominated;
	void   rnd_init();
	void   obj_eval();
	void   show_objective();
	void   show_variable();

    bool   operator<(const CIndividual &ind2);
    bool   operator<<(const CIndividual &ind2);
    bool   operator==(const CIndividual &ind2);
    void   operator=(const CIndividual &ind2);
};

CIndividual::CIndividual()
{
	x_var = vector<double>(nvar, 0);
        y_obj = vector<double>(nobj, 0);
	rank = 0;
}
CIndividual::~CIndividual()
{

}
void CIndividual::rnd_init()
{
    for(int n=0;n<nvar;n++)
        x_var[n] = vlowBound[n] + rnd_uni(&rnd_uni_init)*(vuppBound[n] - vlowBound[n]);    

}

void CIndividual::obj_eval()
{

	if(!strcmp("UF1", strTestInstance))  CEC09_F1(y_obj, x_var);
	if(!strcmp("UF2", strTestInstance))  CEC09_F2(y_obj, x_var);
	if(!strcmp("UF3", strTestInstance))  CEC09_F3(y_obj, x_var);
	if(!strcmp("UF4", strTestInstance))  CEC09_F4(y_obj, x_var);
	if(!strcmp("UF5", strTestInstance))  CEC09_F5(y_obj, x_var);
	if(!strcmp("UF6", strTestInstance))  CEC09_F6(y_obj, x_var);
	if(!strcmp("UF7", strTestInstance))  CEC09_F7(y_obj, x_var);
	if(!strcmp("UF8", strTestInstance))  CEC09_F8(y_obj, x_var);
	if(!strcmp("UF9", strTestInstance))  CEC09_F9(y_obj, x_var);
	if(!strcmp("UF10", strTestInstance)) CEC09_F10(y_obj, x_var);


	if(!strcmp("R2_DTLZ2_M5", strTestInstance))	CEC09_R2_DTLZ2_M5(y_obj, x_var);	
	if(!strcmp("R2_DTLZ3_M5", strTestInstance)) CEC09_R2_DTLZ3_M5(y_obj, x_var);
	if(!strcmp("WFG1_M5", strTestInstance))     CEC09_WFG1_M5(y_obj, x_var);

	//WFG test instances....
	if(!strcmp("WFG1", strTestInstance))  wfg1(y_obj, x_var);
	if(!strcmp("WFG2", strTestInstance))  wfg2(y_obj, x_var);
	if(!strcmp("WFG3", strTestInstance))  wfg3(y_obj, x_var);
	if(!strcmp("WFG4", strTestInstance))  wfg4(y_obj, x_var);
	if(!strcmp("WFG5", strTestInstance))  wfg5(y_obj, x_var);
	if(!strcmp("WFG6", strTestInstance))  wfg6(y_obj, x_var);
	if(!strcmp("WFG7", strTestInstance))  wfg7(y_obj, x_var);
	if(!strcmp("WFG8", strTestInstance))  wfg8(y_obj, x_var);
	if(!strcmp("WFG9", strTestInstance))  wfg9(y_obj, x_var);

	//DTLZ test instances....
	if(!strcmp("DTLZ1", strTestInstance))  dtlz1(y_obj, x_var);
	if(!strcmp("DTLZ2", strTestInstance))  dtlz2(y_obj, x_var);
	if(!strcmp("DTLZ3", strTestInstance))  dtlz3(y_obj, x_var);
	if(!strcmp("DTLZ4", strTestInstance))  dtlz4(y_obj, x_var);
	if(!strcmp("DTLZ5", strTestInstance))  dtlz5(y_obj, x_var);
	if(!strcmp("DTLZ6", strTestInstance))  dtlz6(y_obj, x_var);
	if(!strcmp("DTLZ7", strTestInstance))  dtlz7(y_obj, x_var);

	//world problems...
        if(!strcmp("RWP1", strTestInstance))  RWP1(y_obj, x_var);
        if(!strcmp("RWP2", strTestInstance))  RWP2(y_obj, x_var);
	//Example FEM
        if(!strcmp("FEM", strTestInstance))  FEM(y_obj, x_var);

}
void CIndividual::show_objective()
{
    for(int n=0; n<nobj; n++)
		printf("%f ",y_obj[n]);
	printf("\n");
}

void CIndividual::show_variable()
{
    for(int n=0; n<nvar; n++)
		printf("%f ",x_var[n]);
	printf("\n");
}

void CIndividual::operator=(const CIndividual &ind2)
{
	x_var = ind2.x_var;
	y_obj = ind2.y_obj;
	rank  = ind2.rank;
}

bool CIndividual::operator<(const CIndividual &ind2)
{
	bool dominated = true;
    for(int n=0; n<nobj; n++)
	{
		if(ind2.y_obj[n]<y_obj[n]) return false;
	}
	if(ind2.y_obj==y_obj) return false;
	return dominated;
}


bool CIndividual::operator<<(const CIndividual &ind2)
{
	bool dominated = true;
    for(int n=0; n<nobj; n++)
	{
		if(ind2.y_obj[n]<y_obj[n]  - 0.0001) return false;
	}
	if(ind2.y_obj==y_obj) return false;
	return dominated;
}

bool CIndividual::operator==(const CIndividual &ind2)
{
	if(ind2.y_obj==y_obj) return true;
	else return false;
}
#endif

