#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int number=0;

void bubbleSort (int *v, int n);
void recursiveBubble (int *v, int n, int aux);
void swap (int *a, int *b);

int main(){
	int i, v[5];
	
	for (i=0; i<5; i++)
		scanf("%d", &v[i]);
	
	//bubbleSort (v, 4);
	recursiveBubble (v, 4, 0);
	for (i=0; i<5; i++)
		printf("%d ", v[i]);
	printf("\nnumber = %d\n", number);
	
	return 0;
}

void bubbleSort (int *v, int n)
{
	int i, j, aux=0;
	int flag;
	for (i=0; i<n; i++){
		flag = 1;
		for (j=0; j<n-aux; j++){
			if (v[j]>v[j+1]){
				swap (&v[j], &v[j+1]);
				flag = 0;
			}
		}
		if (flag)
			break;
		aux++;
	}
}

void swap (int *a, int *b)
{
	*a+=*b;
	*b=*a-*b;
	*a-=*b;
}

void recursiveBubble (int *v, int n, int aux) // 4, 0
{
	number = number + 1;
	
	if (v[aux] > v[aux+1])
		swap (&v[aux], &v[aux+1]);
	if (aux < n-1){
		recursiveBubble(v, n, aux+1);
		return;
	}
	if (n>1)
		recursiveBubble(v,n-1, 0);
	return;
}
