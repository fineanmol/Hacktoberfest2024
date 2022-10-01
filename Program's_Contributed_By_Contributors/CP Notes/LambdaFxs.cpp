#include<bits/stdc++.h>
using namespace std; 

int main(){
/*
Lambda functions are temporary functions, their syntax is like this:- [](variables to pass){what to return} => Prototype
eg function is [](int x){return x+2};
*/

auto sum = [](int x,int y){return x+y;};
cout<<"Lambda function to find sum of 10 & 15 => "<<sum(10,15)<<endl;
//Now insted of writing comparative functions upward in the insort(), we'll directly write it inside the ()


vector<int> v ={5,13,11,-3,7,19,13,17};
auto isTrue = all_of(v.begin(),v.end(),[](int x){return x>0;});
if(isTrue==1)
cout<<"All are Positive"<<endl;
else
cout<<"Not all are Positive Numbers"<<endl;
}