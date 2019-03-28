#include "util.h"



//·············································································
void Comult(int l, int m, int n, double** a, double** b, double** c)
{
	register int i, j, k;

	for(i=1; i<=l; i++) {
		for(j=1; j<=n; j++) {
			a[i][j] = 0.0;

			for(k=1; k<=m; k++) a[i][j] = a[i][j]+b[i][k]*c[k][j];
        }
	}
}

//·············································································
void CierraLimpia(void)
{
	fclose(fp5);
	fclose(fp16);
    //fclose(fp79);

    //	remove(nom[0]);
    //	remove(nom[1]);
    //	remove(nom[2]);
    //	remove(nom[3]);
}
//·············································································
void ConvSegHrs(long int segs, char* hora)
{
	int hrs, mins;

	// Obtiene las horas:
	//hrs = int(segs/3600);
	hrs = (int) segs/3600;

	// Obtiene lo minutos:
	segs-= hrs*3600;
	//mins = int(segs/60);
	mins = (int)segs/60;

	// Obtiene los segundos restantes:
	segs-= mins*60;

	// Completa la cadena de tiempo:
	sprintf(hora, " Tiempo total de ejecucion :   %d:%d:%ld", hrs, mins, segs);
	//W1.printf(10,300,"Termino programa exitosamente en :   %d:%d:%d", hrs, mins, segs);
}
//·············································································
