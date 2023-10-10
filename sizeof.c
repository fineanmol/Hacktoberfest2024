#include<stdio.h>
int main(){
    short int a=5;
    short int b=10;

    printf("\n%d",sizeof(a));
    printf("\n%d",sizeof(a+b));


    int x =5;
    int y=10;
    printf("\n%d",sizeof(x));
    printf("\n%d",sizeof(x+y));


    long int c=5;
    long int d=10;
    printf("\n%d",sizeof(c));
    printf("\n%d",sizeof(c+d));


    short int g=5;
    short int h=10;
    printf("\n%d",sizeof(g));
    printf("\n%d",sizeof(g+h));

     
    long long int e=5;
    long long int f=10;
    printf("\n%d",sizeof(e));
    printf("\n%d",sizeof(e+f));


    signed int i=5;
    unsigned int j=10;
    if(i<j)
        printf("\nx is smaller");
    else
        printf("\ny is smaller");



    signed int i1=-5;
    unsigned int j1=10;
    if(i1<j1)
        printf("\nx is smaller");
    else
        printf("\ny is smaller");
}
