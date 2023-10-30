#include <iostream>

int main() {

  int x = 10;
  int* p1 = &x; // p1 points to x

  int* p2 = p1; // p2 also points to the same x

  std::cout << "x = " << x << std::endl; 
  std::cout << "*p1 = " << *p1 << std::endl;
  std::cout << "*p2 = " << *p2 << std::endl;

  *p1 = 20; // change value of x through p1

  std::cout << "x = " << x << std::endl;
  std::cout << "*p2 = " << *p2 << std::endl;

  return 0;
}
