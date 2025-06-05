#include<stdio.h>
int main()
{
    int r;
    printf("ENTER THE RADIUS = ");
    scanf("%d", &r);
    float area=3.14 * r * r;
    float cir=2 * 3.14 * r;
    printf("THE AREA OF THE CIRCLE IS : %f",area);
    printf("\nTHE CIRCUMFERENCE OF THE CIRCLE IS : %f",cir);
    return 0;
}
