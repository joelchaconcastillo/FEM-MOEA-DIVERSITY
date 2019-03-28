#ifndef __COMMON_H_
#define __COMMON_H_

#include "global.h"

void fast_sort_non_dominated()
{

}
void minfastsort(std::vector<double> &x, std::vector<int> &idx, int n, int m)
{
    for(int i=0; i<m; i++)
	{
	    for(int j=i+1; j<n; j++)
			if(x[i]>x[j])
			{
			    double temp = x[i];
				x[i]        = x[j];
				x[j]        = temp;
				int id      = idx[i];
				idx[i]      = idx[j];
				idx[j]      = id;
			}
	}
}


double dist_vector(std::vector <double> &vec1, std::vector <double> &vec2)
{
	int dim = vec1.size();
    double sum = 0;
	for(int n=0; n<dim; n++)
	    sum+=(vec1[n] - vec2[n])*(vec1[n] - vec2[n]);
	return sqrt(sum);
}

bool   dominate(std::vector<double> &u, std::vector<double> &v, double epsilon)
{
    int dim = u.size();
	for(int i=0; i<dim; i++)
	{
	    if(u[i]<v[i]-epsilon)
		{
		    return false;
		}
	}
	return true;
}
void load_data(char filename[1024], std::vector< std::vector<double> > &data, int dim)
{
	std::ifstream readf(filename);
	std::vector<double> vect = std::vector<double>(dim, 0);
	while(!readf.eof())
	{
        for(int i=0; i<dim; i++)
		{
			readf>>vect[i];
			//printf(" %f ", vect[i]);
		}
		data.push_back(vect);
		//vect.clear();    // bug here. 
	}

	readf.close();    
}
#endif
