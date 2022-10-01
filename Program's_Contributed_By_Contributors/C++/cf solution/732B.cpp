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
    int sum=0; int arr[n];
    memset(arr, 0, sizeof(arr));
   for (int i = 2; i <= n; i++) {
      if (isPrimeNumber(i))
         { sum=+i;
         if(sum==n || sum==n-1)
         {break;}

         arr[i]=i;

      }
   }
   int a[n];
    int size = sizeof arr / sizeof arr[1];
//   for(int i=0;i<size;i++)
//   {if(arr[i]!)

   if(sum=n-1)

   {arr[1]=1;
       for(int i=1;i<size;i++)
       {   if(arr[i]!=0)
           cout<<arr[i]<<" ";}
   }
   else {for(int i=2;i<size;i++)
       {if(arr[i]!=0)
           cout<<arr[i]<<" ";}
}}
int main() {
   int n;
   cin>>n;

   printPrime(n);}
