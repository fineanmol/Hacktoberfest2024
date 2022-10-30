#include<bits/stdc++.h>

using namespace std;
int main(){
set<int>s;
int arr[] = {10, 10, 20, 30, 30, 30, 40};
int n = sizeof(arr)/sizeof(arr[0]);
for(int i=0; i<n; i++)
s.insert(arr[i]);
for(auto it = s.begin(); it != s.end(); it++)
cout<<*it<<" ";
}
