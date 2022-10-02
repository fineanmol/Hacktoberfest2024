1) 
// CPP program to print double quotes
#include<iostream>
 
int main()
{
   std::cout << "\"geeksforgeeks\"";
   return 0;
}
Output: "geeksforgeeks"



2) 
// C++ program to check if two numbers are equal
// without using arithmetic operators or
// comparison operators
#include <iostream>
using namespace std;
 
int main()
{
   int x = 10;
   int y = 10;
    
   if (!(x ^ y))
      cout << " x is equal to y ";
   else
      cout << " x is not equal to y ";
       
   return 0;
}
Output: x is equal to y 


3) 
// C++ program to print all natural numbers upto
// N without using semi-colon
#include<iostream>
 
using namespace std;
int N = 10;
 
int main()
{
  static int x = 1;
  if (cout << x << " " && x++ < N && main())
  { }
  return 0;
}
Output: 1 2 3 4 5 6 7 8 9 10 


4)
// C++ program to find maximum and minimum of
// two numbers without using loop and any
// condition.
#include<bits/stdc++.h>
 
int main ()
{
   int a = 15, b = 20;
   printf("max = %d\n", ((a + b) + abs(a - b)) / 2);
   printf("min = %d", ((a + b) - abs(a - b)) / 2);
   return 0;
}
Output: 
max = 20
min = 15



5) 
// CPP program to print sum of two integers
// without +
#include<iostream>
 
using namespace std;
int main()
{
  int a = 5;
  int b = 5;
  int sum = -( -a-b );
  cout << sum;
  return 0;
}
Output: 10