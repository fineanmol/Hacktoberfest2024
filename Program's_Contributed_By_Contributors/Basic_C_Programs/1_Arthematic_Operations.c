#include<stdio.h>

int main()
{
int a,b,add,sub,mult,div;
printf("ENTER THE TWO NUMBERS : \n");
scanf("%d%d",&a,&b);
add=a+b;
sub=a-b;
mult=a*b;
div=a/b;
printf("ADDTION OD TWO NUMBERS ARE : %d\n",add);
printf("SUBTRACTION OF TWO NUMBERS ARE : %d\n",sub);
printf("MULTIPLICATION OF TWO NUMBERS ARE : %d\n",mult);
printf("DIVISION OF TWO NUMBER ARE : %d\n",div);
return 0;
}