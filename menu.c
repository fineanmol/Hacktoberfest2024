#include<stdio.h>

int main()
{
    int choice,a,b,s;
    while(1)
    {printf("\n 1.Addition");
    printf("\n 2.Odd-Even");
    printf("\n 3.Printing N numbers");
    printf("\n 4.Exit");
    printf("\n\nEnter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                  printf("Enter two numbers");
                  scanf("%d%d",&a,&b);
                  s=a+b;
                  printf("\n sum is %d",a);
                  break;
        case 2 :
                  printf("Enter any number");
                  scanf("%d",a);
                  if(a/2==0)
                  {printf("Even");}
                  else
                  {printf("Odd");}
                  break;
        case 3 :
                  printf("Enter any number");
                  scanf("%d",&a);
                  for(b=1;b<=a;b++)
                  {printf("%d\n",b);}
        case 4 :
                  exit(0);
        default :
                printf("Invalid choice");



    }}
    return 0;
}
