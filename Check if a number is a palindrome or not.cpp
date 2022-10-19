#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
int n,rev = 0,a,b;
printf("Enter the interer: ");
scanf("%d",&n);
b = n;
while(n!=0)
{
    a = n% 10;
    rev = rev* 10+ a;
    n /= 10;
}
if (b == rev)
    printf("%d is a palindrome.", b);
else
    printf("%d is not a palindrome.", b);
return 0;
}
