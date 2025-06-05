#include<stdio.h>
void main()
{
int n,sum=0,temp;
printf("enter the no.");
scanf("%d",&n);
temp=n;
while(temp!=0)
{
sum=sum*10+(temp%10);
temp=temp/10;
}
if(sum==n)
    printf("pallindrome: %d",sum);
else
     printf("not a pallindrome: %d",sum);
}
