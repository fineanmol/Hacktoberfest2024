#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int sdif(string s1,string s2){
 int sum1=0;
//  int sum2=0;
 int diff;
 for (int i = 0; i < s1.size(); i++)
 {
    sum1+= abs(s1[i]-s2[i]);
 }
//  for (int i = 0; i < s2.size(); i++)
//  {
//     sum2+= s2[i];
//  }

 return sum1;
}

int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){;
 int m,n;
 cin>>n>>m;
 vector <string> arr(n);
 int mini=INT_MAX;
 int d;
 for (int i = 0; i < n; i++)
 {
    cin>>arr[i];
 }
for (int i = 0; i < n; i++)
{
    for (int j = i+1;j < n; j++)
    {
        d=sdif(arr[i],arr[j]);
    mini=min(mini,d);
    }
}


 cout<<mini<<endl;
}
return 0;
}