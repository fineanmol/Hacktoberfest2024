#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  int count_set_bits = 0;
  while(n){
    count_set_bits += (n & 1);
    n = n >> 1;
  }
  cout<<"Count of Set Bits in given input is "<<count_set_bits<<"\n";
  return 0;
}
