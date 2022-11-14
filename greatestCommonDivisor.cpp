#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int euclid_gcd(int a, int b){
  if(b==0){
    return a;
  }
  else{
    return euclid_gcd(b,a%b);
  } 
}

void test_solution() {
    assert(euclid_gcd(30,21) == 3);
    assert(euclid_gcd(1035,759) == 69);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << euclid_gcd(a, b) << std::endl;
  //test_solution();
  return 0;
}
