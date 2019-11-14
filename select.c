#include <stdio.h>
#include <stdlib.h>
#define sf(x) scanf("%f", &x)

void selectionSort (float* v, float n);
void swap (float* a, float* b, float*v);
void printVector (float* v, float n);

int main(){
	int i;
	float rep, input;
	float *v;
	
	printf("Quantos números?\n");
	sf(rep);
	v = (float*)malloc(rep*sizeof(float));
	printf("Insira %.f números:\n", rep);
	for (i=0; i<rep; i++) sf(v[i]);
	printf("\n");
	
	//printVector (v, rep);
	//printf("\n");
	
	selectionSort (v, rep);
	
	printVector(v, rep);
	printf("----END----\n");
	
	free (v);
	return 0;
}

void selectionSort (float* v, float n)
{
	int pos=0, i, flag=1, maior;
	

	while (pos < n-1 && flag){
		maior = pos;
		flag = 0;
		for (i=pos; i<n; i++){
			if (v[i] > v[maior]){ 
				maior = i;
			}	
			if (v[i] > v[i+1] && i<n	) flag = 1;
		}
		if (!flag) break;
		//printf("maior = v[%d] = %.f\npos = %d -> %.f\n", maior, v[maior], pos, v[pos]);
		if (maior != pos) swap(&v[maior], &v[pos], v);	
		pos++;
	}
}

void swap (float* a, float* b, float* v)
{
	printf("%.2f <---> %.2f\n", *a, *b);
	*a+= *b;
	*b = *a - *b;
	*a-=*b;
	//printf("%.2f <---> %.2f\n", *a, *b);
	
	//printVector(v, 5);
	//printf("\n\n");
}

void printVector (float* v, float n)
{
	int i;	
	for (i=0; i<n; i++) printf("%.2f ", v[i]);
	printf("\n");
}
