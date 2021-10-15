#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UPPER_LIMIT pow(2,limite)-1
#define LOWER_LIMIT -pow(2,limite)
#define MAX(x,y) (x > y ? x : y)
#define MAX2(x,y) ((x) > (y) ? (x) : (y)) //no difference when doing MAX2(a++,b++)
#define FINDMAX(m, x, n)\
{\
  typeof(n) _n = n;           /* _n is local copy of the number of elements*/\
  if (_n > 0) {               /* in case the array is empty */\
    int _i;\
    typeof((x)[0]) * _x = x;  /* _x is local copy of pointer to the elements */\
    typeof(m) _m = _x[0];     /* _m is maximum value found */\
    for (_i=1; _i<_n; _i++)   /* Iterate through all elements */\
      if (_x[_i] > _m)\
        _m = _x[_i];\
    (m) = _m;                 /* returns the result */\
  }\
}
#define SWAP(a, b)\
{\
	typeof(a) _a = a;		 /* _a is a local copy of the number a*/\
	(a) = b;\
	(b) = _a;\
}

void ordenaVetor(char* C, int tam, char prioridade);

int main() {
	double limite, V[3];
	char C[2];

	scanf("%lf", &limite); //5
	scanf("%lf %c %lf %c %lf", &V[0], &C[0], &V[1], &C[1], &V[2]);

	double result = 0;
	if (C[1] == '*'){
		result += C[0] == '+' ? V[0]+V[1]*V[2] : V[0]*V[1]*V[2] ;
	}else{
		result += C[0] == '+' ? V[0]+V[1]+V[2] : V[0]*V[1]+V[2] ;
	}

	if (result>UPPER_LIMIT || result<LOWER_LIMIT)
		printf("%.0lf OVERFLOW\n", result);
	else
		printf("%.0lf OK\n", result);

	return 0;
}

void ordenaVetor(char* C, int tam, char prioridade){
	int i, j;
	for (i=0; i<tam-1; i++){
		for (j=i+1; j<tam; j++){
			if(C[j] == prioridade) SWAP(C[i], C[j]);
		}
	}
}


