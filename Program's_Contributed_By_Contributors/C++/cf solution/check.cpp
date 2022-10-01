#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
 string s1="best";
 string s2="cost";
 int sum1=0;
 int sum2=0;
 for (int i = 0; i < s1.size(); i++)
 {
    sum1+= s1[i];
 }
 for (int i = 0; i < s2.size(); i++)
 {
    sum2+= s2[i];
 }
 
 cout<<sum1-sum2<<endl;
return 0;
}