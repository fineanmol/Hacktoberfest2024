
#include <stdio.h>
#include <math.h>

void circleArea(int r){
    printf("The area of the circle is: %f\n", M_PI*(r*r));
}


void circlePerimeter(int r){
    printf("The perimeter of the circle is: %f\n", 2*M_PI*r);
}

int main(){

    int radius = 6; //change me
    int *pr = &radius;
    circleArea(*pr);
    circlePerimeter(*pr);

    return 0;
}