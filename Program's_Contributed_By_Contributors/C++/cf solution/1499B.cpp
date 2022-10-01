#include <bits/stdc++.h>
using namespace std;
bool isPrimeNumber(int n){
   if (n <= 1)
      return false;
   if (n <= 3)
      return true;
   if (n % 2 == 0 || n % 3 == 0)
      return false;
   for (int i = 5; i * i <= n; i = i + 6)
      if (n % i == 0 || n % (i + 2) == 0)
         return false;
   return true;
}
void printPrime(int n){
    int sum=0;
   for (int i = 2; i <= n; i++) {
      if (isPrimeNumber(i))
         {
         if(sum!=n)
         {sum=+i;
         cout<<i<<" ";}
         
      }
   }
int main(){
   int n;
   cin>>n;
  
   printPrime(n);
}