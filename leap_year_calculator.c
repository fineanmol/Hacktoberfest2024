#include <stdio.h>
int main() {
   int a;
   printf("Enter the year which you want to check for leap year: ");
   scanf("%d", &a);

   if (a%400==0) {
      printf("%d is a leap year.", a);         //if divisible by 400 then leap year
   }
  
   else if (a%100==0) {                          //if not divisible by 400 and divisible by 100 then not leap year
      printf("%d is not a leap year.", a);
   }
   
   else if (a%4==0) {                           //if not divisible by 400 and also not divisibleby 100 but divisibleny 4 then leap year
      printf("%d is a leap year.", a);
   }
   else {                                       //all other years are not leap year
      printf("%d is not a leap year.", a);
   }

   return 0;
}
