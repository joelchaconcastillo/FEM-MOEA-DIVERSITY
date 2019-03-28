#ifndef _util_h_
#define _util_h_

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "raros.h"


void Comult(int l, int m, int n, double** a, double** b, double** c);

void CierraLimpia(void);

void ConvSegHrs(long int segs, char* hora);

#endif
