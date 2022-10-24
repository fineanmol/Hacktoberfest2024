#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
float x, y, result = 1;
int i, a, b;
void mainpage(void);
void info(void);
void ao(void);
void page(void);
void exo(void);
void rt(void);
void trg(void);
void deg(void);
void rad(void);
void lg(void);
int main(void) {
  system("cls");
  page();
  return 0;
}
void page() {
  int chce;
  system("cls");
  do {
    mainpage();
    printf("\n Enter Your choice:\t");
    scanf("%d", &chce);
    switch (chce) {
    case 0: {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
      break;
    }
    case 1: {
      info();
      break;
    }
    case 2: {
      ao();
      break;
    }
    case 3: {
      exo();
      break;
    }
    case 4: {
      rt();
      break;
    }
    case 5: {
      trg();
      break;
    }
    case 6: {
      lg();
      break;
    }
    default:
      printf("\nEnter suitable number!!\n");
      break;
    }
    break;
  } while (1);
}
void mainpage() {
  system("cls");
  printf("\n\t**************** SCIENTIFIC CALCULATOR V.02 ****************\t\n");
  printf("\n SELECT THE TYPE OF OPERATION!\n");
  printf("\nPress < 0 > to exit\n");
  printf("\nPress < 1 > for info\n");
  printf("\nPress < 2 > for arthematic operations\n");
  printf("\nPress < 3 > for exponential operations\n");
  printf("\nPress < 4 > to find root\n");
  printf("\nPress < 5 > for Trignometric operations\n");
  printf("\nPress < 6 > for Logarithm operation\n");
}
void info() {
  int c;
  system("cls");
  printf("\n\t\t\t**** INFO OF SCIENTIFIC CALCULATOR V.02 ****\n");
  printf("\n\n\n\n");
  printf("\n EXIT:\n\tif you enter 0 program will terminate!");
  printf("\n INFO:\n\tif you enter 1 you'll get to about the types and various "
         "operations you can perform here\n");
  printf("\n ARTHEMATIC OPERATIONS:\n\tif u enter 2 youll get to choose your "
         "desired operation like addition,subraction, multiplication, "
         "division, modulus operations, percentage, factorial\n");
  printf("\n EXPONENTIAL OPERATIONS:\n\tif you enter 3 you'll get to choose "
         "your desired operation to perform\n");
  printf("\n ROOT:\n\tif you enter 4 you'll get to chosse your desired "
         "operation to find the roots\n");
  printf("\n TRIGNOMETRIC OPERATIONS:\n\tif you enter 5 you'll get to choose "
         "your desired trignometric operation\n");
  printf("\n LOGARITHM OPERATION:\n\tif you enter 6 you'll get to perform "
         "logarithm operations\n");
  printf("\n\n\n\n\nPress < 0 > to exit\nPress < 1 > to go back to main page ");
  scanf("%d", &c);
  if (c == 1) {
    page();
  }
  else if (c==0)
  {
    printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
    exit(0);
  }
  else
  {
    info();
  }
  
}
void ao() {
  int d;
  system("cls");
  printf("\n\t\t\t**** ARTHEMATIC OPERATIONS ****\n");
  printf("\n\n");
  printf("\nPress < 0 >   to exit\n");
  printf("\nPress < 1 >   for addition\n");
  printf("\nPress < 2 >   for subraction\n");
  printf("\nPress < 3 >   for multiplication\n");
  printf("\nPress < 4 >   for division\n");
  printf("\nPress < 5 >   for modulus operation\n");
  printf("\nPress < 6 >   for finding Factorial\n");
  printf("\nPress < 7 >   to calculate percentage\n");
  printf("\nPress < 8 >   to back to main page\n");
  printf("\n\nEnter your choice:\t");
  scanf("%d", &d);
  switch (d) {
  case 0:{
    printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
    exit(0);
  }  
  case 1: {
    int e;
    system("cls");
    printf("\n\t\t\t**** ADDITION ****\n");
  printf("\n\n");
    printf("\nenter values for X:\t");
    scanf("%f", &x);
    printf("\nenter value for Y:\t");
    scanf("%f", &y);
    printf("\nSum is %f\n", (x + y));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page!\n");
    scanf("%d", &e);
    if (e == 1) {
      ao();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    break;
  }
  case 2: {
    int e;
    system("cls");
    printf("\n\t\t\t**** SUBRACTION ****\n");
    printf("\n\n");
    printf("enter values for X:\t");
    scanf("%f", &x);
    printf("enter value for Y:\t");
    scanf("%f", &y);
    printf("Difference is %f", (x - y));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page!\n");
    scanf("%d", &e);
    if (e == 1) {
      ao();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 3: {
    int e;
    system("cls");
    printf("\n\t\t\t**** MULTIPLICATION ****\n");
    printf("\n\n");
    printf("enter values for X:\t");
    scanf("%f", &x);
    printf("enter value for Y:\t");
    scanf("%f", &y);
    printf("Product is %f", (x * y));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page!\n");
    scanf("%d", &e);
    if (e == 1) {
      ao();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 4: {
    int e;
    system("cls");
    printf("\n\t\t\t**** DIVISION ****\n");
    printf("\n\n");
    printf("enter values for X:\t");
    scanf("%f", &x);
    printf("enter value for Y:\t");
    scanf("%f", &y);
    if (y == 0) {
      printf("\n cannot perform division!!\ndivide by 0 error!\n");
      printf("\n\n\n\n\n\nPress < 0 > to exit\n");
      printf("\nPress < 1 > to go back to previous page!\n");
      scanf("%d", &e);
      if (e == 1){
         ao();
      }
      else if (e==0)
      {
        printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
        exit(0);
      }
      
    }
    printf("Quotient is %f", (x / y));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page!\n");
    scanf("%d", &e);
    if (e == 1) {
      ao();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 5: {
    int e;
    system("cls");
    printf("\n\t\t\t**** MODULUS ****\n");
    printf("\n\n");
    printf("\nValues must be of type integer\n");
    printf("enter values for A:\t");
    scanf("%d", &a);
    printf("enter value for B:\t");
    scanf("%d", &b);
    printf("remainder is %d", (a % b));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page!\n");
    scanf("%d", &e);
    if (e == 1) {
      ao();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 6: {
    int e;
    system("cls");
    printf("\n\t\t\t**** FACTORIAL ****\n");
    printf("\n\n");
    printf("enter values for X:\t");
    scanf("%f", &x);
    if (x<=0)
    {
      printf("\nFactorial of %f is possible as Factorial function is mathematically not defined for 0 and -ve real numberes!!!\n",x);
      printf("\n\n\n\n\nPress < 0 > to exit\n");
      printf("\nPress < 1 > to go back to previous page!\n");
      scanf("%d", &e);
       if (e == 1) {
         ao();
       }
       else if (e==0)
        {
          printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
          exit(0);
        }
    }
    else{
    for (i = 1; i <= x; i++) {
      result *= i;
    }
    printf("Factorial of %f is %f", x, result);
    printf("\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page!\n");
    scanf("%d", &e);
    if (e == 1) {
      ao();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    }
    break;
  }
  case 7: {
    int e;
    system("cls");
    printf("\n\t\t\t**** PERCENTAGE ****\n");
  printf("\n\n");
    printf("\nEnter a value for X:\t");
    scanf("%f", &x);
    printf("\nEnter a value for Y:\t");
    scanf("%f", &y);
    printf("\nPercentage is %f\n", ((x * y / 100)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page!\n");
    scanf("%d", &e);
    if (e == 1) {
      ao();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 8: {
    page();
  }
  default: {
    printf("Enter suitable number!!\n!");
    ao();
  } break;
  }
}
void exo() {
  int d;
  system("cls");
  printf("\n\t\t\t**** EXPONENTIAL OPERATIONS ****\n");
  printf("\n\n");
  printf("\nPress < 0 >   to exit\n");
  printf("\nPress < 1 >   for X ^ Y\n");
  printf("\nPress < 2 >   for X ^ 2\n");
  printf("\nPress < 3 >   for X ^ 3\n");
  printf("\nPress < 4 >   for X ^ (1 / Y)\n");
  printf("\nPress < 5 >   for 1 / X\n");
  printf("\nPress < 6 >   for 10 ^ X\n");
  printf("\nPress < 7 >   to back to main page\n");
  printf("\nEnter your choice:\t");
  scanf("%d", &d);
  switch (d) {
  case 0:{
    printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
    exit(0);
  }
  case 1: {
    int e;
    system("cls");
    printf("\n\t\t\t**** X ^ Y ****\n");
    printf("\n\n");
    printf("\nEnter the value for X:\t");
    scanf("%f", &x);
    printf("\nEnter the value for Y:\t");
    scanf("%f", &y);
    printf("\nResult is %f", (pow(x, y)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      exo();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 2: {
    int e;
    system("cls");
    printf("\n\t\t\t**** X ^ 2 ****\n");
    printf("\n\n");
    printf("\nEnter the value for X:\t");
    scanf("%f", &x);
    printf("\nResult is %f", (pow(x, 2)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      exo();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 3: {
    int e;
    system("cls");
    printf("\n\t\t\t**** X ^ 3 ****\n");
    printf("\n\n");
    printf("\nEnter the value for X:\t");
    scanf("%f", &x);
    printf("\nResult is %f", (pow(x, 3)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      exo();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 4: {
    int e;
    system("cls");
    printf("\n\t\t\t**** X ^ (1/Y) ****\n");
    printf("\n\n");
    printf("\nEnter the value for X:\t");
    scanf("%f", &x);
    printf("\nEnter the value for Y:\t");
    scanf("%f", &y);
    printf("\nResult is %f", (pow(x, (1 / y))));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      exo();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 5: {
    int e;
    system("cls");
    printf("\n\t\t\t**** 1 / X ****\n");
    printf("\n\n");
    printf("\nEnter the value for X:\t");
    scanf("%f", &x);
    printf("\nResult is %f", (1 / x));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      exo();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 6: {
    int e;
    system("cls");
    printf("\n\t\t\t**** 10 ^ X ****\n");
    printf("\n\n");
    printf("\nEnter the value for X:\t");
    scanf("%f", &x);
    printf("\nResult is %f", (pow(10, x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      exo();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 7: {
    page();
  }
  default: {
    printf("Enter suitable number!!\n!");
    exo();
  } break;
  }
}
void rt() {
  int d;
  system("cls");
  printf("\n\t\t\t**** ROOT ****\n");
  printf("\n\n");
  printf("\nPress < 0 >   to exit\n");
  printf("\nPress < 1 >   for Square root\n");
  printf("\nPress < 2 >   for Cube root\n");
  printf("\nPress < 3 >   to back to main page\n");
  printf("\nEnter your choice:\t");
  scanf("%d", &d);
  switch (d) {
  case 0:{
    exit(0);
  }
  case 1: {
    int e;
    system("cls");
    printf("\n\t\t\t**** SQUARE ROOT ****\n");
    printf("\n\n");
    printf("\nEnter value for X:\t");
    scanf("%f", &x);
    printf("\nSquare root is %f\n\n", (sqrt(x)));
    printf("\n\n\n\n\nPress < 0 >   to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      rt();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 2: {
    int e;
    system("cls");
    printf("\n\t\t\t**** CUBE ROOT ****\n");
    printf("\n\n");
    printf("\nEnter value for X:\t");
    scanf("%f", &x);
    printf("\nResult is %f\n\n", (cbrt(x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      rt();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 3: {
    page();
  }
  default: {
    printf("Enter suitable number!!\n!");
    rt();
  } break;
  }
}
void trg() {
  int d;
  system("cls");
  printf("\n\t\t\t**** TRIGNOMETRIC OPERATIONS ****\n");
  printf("\n\n");
  printf("\nPress < 0 >   to exit\n");
  printf("\nPress < 1 >   for Trignometry operation in degree mode\n");
  printf("\nPress < 2 >   for Trignometry operation in radian mode\n");
  printf("\nPress < 3 >   to back to main page\n");
  printf("\nEnter your choice:\t");
  scanf("%d", &d);
  switch (d) {
  case 0:{
    printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
    exit(0);
  }
  case 1: {
    deg();
    break;
  }
  case 2: {
    rad();
    break;
  }
  case 3: {
    page();
  }
  default: {
    printf("Enter suitable number!!\n!");
    trg();
  } break;
  }
}
void deg() {
  int d;
  system("cls");
  printf("\n\t\t\t**** TRIGNOMETRY OPERATIONS IN DEGREE MODE ****\n");
    printf("\n\n");
  printf("\nPress < 0 >   to exit\n");
  printf("\nPress < 1 > for Sine\n");
  printf("\nPress < 2 > for Cosine\n");
  printf("\nPress < 3 > for Tan\n");
  printf("\nPress < 4 > for Cosecant\n");
  printf("\nPress < 5 > for Secant\n");
  printf("\nPress < 6 > for Cot\n");
  printf("\nPress < 7 > to go back to previous page:\n");
  printf("\nEnter your choice:\t");
  scanf("%d", &d);
  switch (d) {
  case 0:{
    printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
    exit(0);
  }
  case 1: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Sine(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    printf("\nSine(%f) is %f", x, (sin(x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      deg();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 2: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Cos(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    printf("\nCos(%f) is %f", x, (cos(x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      deg();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 3: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Tan(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    printf("\nTan(%f) is %f", x, (tan(x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      deg();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 4: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Cosec(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    printf("\nCosec(%f) is %f", x, (1 / (sin(x))));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      deg();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 5: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Sec(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    printf("\nSec(%f) is %f", x, (1 / (cos(x))));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      deg();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 6: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Cot(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    printf("\nCot(%f) is %f", x, (1 / (tan(x))));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      deg();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 7: {
    trg();
  }
  default: {
    printf("Enter suitable number!!\n!");
    deg();
  } break;
  }
}
void rad() {
  int d;
  system("cls");
  printf("\n\t\t\t**** TRIGNOMETRY OPERATIONS IN RADIAN MODE ****\n");
  printf("\n\n");
  printf("\nPress < 0 >   to exit\n");
  printf("\nPress < 1 > for Sine\n");
  printf("\nPress < 2 > for Cosine\n");
  printf("\nPress < 3 > for Tan\n");
  printf("\nPress < 4 > for Cosecant\n");
  printf("\nPress < 5 > for Secant\n");
  printf("\nPress < 6 > for Cot\n");
  printf("\nPress < 7 > to go back to previous page:\n");
  printf("\nEnter your choice:\t");
  scanf("%d", &d);
  switch (d) {
  case 0:{
    printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
    exit(0);
  }
  case 1: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Sine(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    x = ((x * 3.14593) / 180);
    printf("\nSine(%f) is %f", x, (sin(x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      rad();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 2: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Cos(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    x = ((x * 3.14593) / 180);
    printf("\nCos(%f) is %f", x, (cos(x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      deg();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 3: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Tan(x) ****\n");
    printf("\n\n");
    printf("\n Eneter the value for X:\t");
    scanf("%f", &x);
    x = ((x * 3.14593) / 180);
    printf("\nTan(%f) is %f", x, (tan(x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      rad();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 4: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Cosec(x) ****\n");
    printf("\n\n");
    printf("\n Eneter the value for X:\t");
    scanf("%f", &x);
    x = ((x * 3.14593) / 180);
    printf("\nCosec(%f) is %f", x, (1 / (sin(x))));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      rad();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 5: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Sec(x) ****\n");
    printf("\n\n");
    printf("\n Eneter the value for X:\t");
    scanf("%f", &x);
    x = ((x * 3.14593) / 180);
    printf("\nSec(%f) is %f", x, (1 / (cos(x))));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      rad();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 6: {
    int e;
    system("cls");
    printf("\n\t\t\t**** Cot(x) ****\n");
    printf("\n\n");
    printf("\n Eneter the value for X:\t");
    scanf("%f", &x);
    x = ((x * 3.14593) / 180);
    printf("\nCot(%f) is %f", x, (1 / (tan(x))));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      rad();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
    break;
  }
  case 7: {
    trg();
  }
  default: {
    printf("Enter suitable number!!\n!");
    rad();
  } break;
  }
}
void lg() {
  int d;
  system("cls");
  printf("\n\t\t\t**** LOGARITHM OPERATIONS ****\n");
  printf("\n\n");
  printf("\nPress < 0 >   to exit\n");
  printf("\nPress < 1 >   for Logarithmic operation\n");
  printf("\nPress < 2 >   to go to main page\n");
  printf("\nEnter your choice:\t");
  scanf("%d", &d);
  switch (d) {
  case 0:{
    printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
    exit(0);
  }
  case 1: {
    int e;
    system("cls");
    printf("\n\t\t\t**** log10(x) ****\n");
    printf("\n\n");
    printf("\n Enter the value for X:\t");
    scanf("%f", &x);
    printf("\nlog10(%f) is %f", x, (log10(x)));
    printf("\n\n\n\n\nPress < 0 > to exit\n");
    printf("\nPress < 1 > to go back to previous page:\n");
    scanf("%d", &e);
    if (e == 1) {
      lg();
    }
    else if (e==0)
    {
      printf("\n\t\t\t**********THANK YOU**********\t\t\t\n");
      exit(0);
    }
    
  }
  case 2: {
    page();
  }
  default: {
    printf("Enter suitable number!!\n!");
    lg();
  } break;
  }
}