#include <stdio.h>
#include <math.h> /* It is ecessary for using sqrt function  */

void main()
{
    /*Variable Declaration*/
    float a, b, c, s, area;

    /*Taking user input*/
    printf("Enter the three sides, a, b, and c, of the triangle:");
    scanf("%f%f%f", &a, &b, &c);

    /*Calculate the area of the triangle*/
    s = (a + b + c) / 2;
    area = sqrt((s *(s - a) *(s - b) *(s - c)));
    printf("\n The area of the triangle is %f.", area);
}
