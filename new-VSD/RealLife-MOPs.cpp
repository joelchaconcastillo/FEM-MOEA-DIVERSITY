/*==========================================================================
// //  Author: Carlos Segura, Joel Chacón 
//     Description: 
//
// ===========================================================================*/


#include <math.h>
//#include <vector>
//#include <ostream>
#include "RealLife-MOPs.h"
using namespace std;
namespace RealLife_MOPs
{

   //*x (arreglo de variables, en este caso 4, todas en el rango [0,1])
   //*F (arreglo de objetivos, en este caso 4)
   
   
void INJ_4OBJ(double *x, double *F)
//   void INJ_4OBJ(vector<double> &x, vector<double> &F)
   {
   	double a = x[0];
   	double DHA = x[1];
   	double DOA = x[2];
   	double OPTT = x[3];
   
   	// TFmax (minimization)
   	F[0] = 0.692 + 0.477 * a - 0.687 * DHA - 0.080 * DOA - 0.0650 * OPTT
   			- 0.167 * a * a - 0.0129 * DHA * a + 0.0796 * DHA * DHA
   			- 0.0634 * DOA * a - 0.0257 * DOA * DHA + 0.0877 * DOA * DOA
   			- 0.0521 * OPTT * a + 0.00156 * OPTT * DHA + 0.00198 * OPTT * DOA
   			+ 0.0184 * OPTT * OPTT;
   
   	// Xcc (minimization)
   	F[1] = 0.153 - 0.322 * a + 0.396 * DHA + 0.424 * DOA + 0.0226 * OPTT
   			+ 0.175 * a * a + 0.0185 * DHA * a - 0.0701 * DHA * DHA
   			- 0.251 * DOA * a + 0.179 * DOA * DHA + 0.0150 * DOA * DOA
   			+ 0.0134 * OPTT * a + 0.0296 * OPTT * DHA + 0.0752 * OPTT * DOA
   			+ 0.0192 * OPTT * OPTT;
   
   	F[2] = 0.758 + 0.358 * a - 0.807 * DHA + 0.0925 * DOA - 0.0468 * OPTT
   			- 0.172 * a * a + 0.0106 * DHA * a + 0.0697 * DHA * DHA
   			- 0.146 * DOA * a - 0.0416 * DOA * DHA + 0.102 * DOA * DOA
   			- 0.0694 * OPTT * a - 0.00503 * OPTT * DHA + 0.0151 * OPTT * DOA
   			+ 0.0173 * OPTT * OPTT;
   
   	// TTmax (minimization)
   	F[3] = 0.370 - 0.205 * a + 0.0307 * DHA + 0.108 * DOA + 1.019 * OPTT
   			- 0.135 * a * a + 0.0141 * DHA * a + 0.0998 * DHA + 0.208 * DOA * a
   			- 0.0301 * DOA * DHA - 0.226 * DOA * DOA + 0.353 * OPTT * a
   			- 0.0497 * OPTT * DOA - 0.423 * OPTT * OPTT + 0.202 * DHA * a * a
   			- 0.281 * DOA * a * a - 0.342 * DHA * DHA * a
   			- 0.245 * DHA * DHA * DOA + 0.281 * DOA * DOA * DHA
   			- 0.184 * OPTT * OPTT * a + 0.281 * DHA * a * DOA;
   
   	return;
   }
   
   //*t (arreglo de variables, en este caso 5, todas en el rango [1,3])
   //*F (arreglo de objetivos, en este caso 3)
  void CWD(double *t, double *F) 
//   void CWD(vector<double> &t, vector<double> &F)
   {
   	F[0] = 1640.2823 + 2.3573285 * t[0] + 2.3220035 * t[1] + 4.5688768 * t[2]
   			+ 7.7213633 * t[3] + 4.4559504 * t[4];
   
   	F[1] = 6.5856 + 1.15 * t[0] - 1.0427 * t[1] + 0.9738 * t[2] + 0.8364 * t[3]
   			- 0.3695 * t[0] * t[3] + 0.0861 * t[0] * t[4] + 0.3628 * t[1] * t[3]
   			- 0.1106 * t[0] * t[0] - 0.3437 * t[2] * t[2]
   			+ 0.1764 * t[3] * t[3];
   
   	F[2] = -0.0551 + 0.0181 * t[0] + 0.1024 * t[1] + 0.0421 * t[2]
   			- 0.0073 * t[0] * t[1] + 0.024 * t[1] * t[2] - 0.0118 * t[1] * t[3]
   			- 0.0204 * t[2] * t[3] - 0.008 * t[2] * t[4] - 0.0241 * t[1] * t[1]
   			+ 0.0109 * t[3] * t[3];
   	return;
   }

}
