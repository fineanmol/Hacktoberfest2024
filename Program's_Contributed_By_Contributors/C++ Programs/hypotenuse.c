#include<stdio.h>
#include<math.h>

/*
program that calculates the hypotenuse of any triangle

*/

float a,b,h;

main(){
	printf("Enter an adjacent leg: ");
	scanf("%f",&a);
	printf("Enter opposite leg: ");
	scanf("%f", &b);
	h=(a*a)+(b*b);
	printf("Hypotenuse is %.2f", sqrt(h));
	return 0;
}
