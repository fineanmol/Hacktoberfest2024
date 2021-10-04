#include <stdio.h>

#define SIZE 10

int S[SIZE+1];
int top = 0;

int is_empty() 
{
  if(top == 0)
    return 1;
  return 0;
}

void push(int x) {
  top = top+1;
  if(top > SIZE) {
    printf("Stack Overflow\n");
  }
  else {
    S[top] = x;
  }
}

int pop() {
  if(is_empty()) {
    printf("Stack Underflow\n");
    return -1000;
  }
  else {
    top = top-1;
    return S[top+1];
  }
}

int main() 
{
  pop();
  push(11);
  push(22);
  push(33);
  push(44);
  push(55);
  push(66);
  push(77);
  push(88);
  push(99);
  push(7863);
  push(110);

  int i;
  for(i=1; i<=SIZE; i++) {
    printf("%d\n",S[i]);
  }
  return 0;
}