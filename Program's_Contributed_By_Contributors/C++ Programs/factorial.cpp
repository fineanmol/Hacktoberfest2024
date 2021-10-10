#include <stdio.h>

// my factorial -> nx(n-1)x(n-2)x(n-3)x...
int factorial(int number) {
  if (number==0) return 1;
  else return (number * factorial(number-1));
}

int main() {

  int number;
  scanf("%d", &number);
  printf("The factorial of %d : %d\n", number, factorial(number));
  return 0;
}
