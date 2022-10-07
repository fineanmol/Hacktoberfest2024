#include <stdio.h>
int main(){
   char Operator;
   float number1, number2, result = 0;
   printf("\n Enter any one operator like +, -, *, / : ");
   scanf("%c", &Operator);
   printf("Enter the values of Operands number1 and number2 \n : ");
   scanf("%f%f", &number1, &number2);
   switch(Operator){
      case '+': result = number1 + number2;
         break;
      case '-': result = number1 - number2;
         break;
      case '*': result = number1 * number2;
         break;
      case '/': result = number1 / number2;
         break;
      default: printf("\n Invalid Operator ");
   }
   printf("The value = %f", result);
   return 0;
}