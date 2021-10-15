#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define si(x) scanf("%d", &x)
#define sf(x) scanf("%f", &x)
#define sd(x) scanf("%lf", &x)
#define FRASE "The cake is a lie."
#define square(x) (x*x)
#define MAX(a,b) ((a)>(b)? (a) : (b))
#define pI(x) printf("%d\n", x);
#define pS(x) printf("%s\n", x);

int main(){
	int Int;
	float Float;
	double Double;
	
	//int n1 = 10, n2 = 12, n3 = MAX(n1, n2);
	
	/*printf("\nInsert, in that order, an int, a float and a double: \n");
	si(Int);
	sf(Float);
	sd(Double);
	printf("\nThe numbers read were:\nInt: %d\nFloat: %f\nDouble: %lf\n\nFinishing the Program.\n\n", Int, Float, Double);
	*/
	
	//printf("%s\n", FRASE);
	
	//printf("%d\n", square(2+3));
	
	//printf("%d\n", n3);
	
	//char string[15] = "string";	
	//pI(Int);
	//pS(FRASE);
	//pS("com aspas");
	//pS(string);
	//pS(sem aspas);		//don't work
	
	/*inline double max(double a, double b) {return a>b? a : b;}
	double x = 10;
	double y = MAX(sqrt(x), 3); // calls sqrt twice
	double z = max(sqrt(x), 3); // calls sqrt once.*/ // ?? what is inline?
	
	//printf("y = %lf\nz = %lf\n", y, z);
	
	return 0;
}
