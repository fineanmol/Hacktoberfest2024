#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 
 
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> p(n);

        for(int i=0;i<n;i++)
        {
        	cin>>p[i];
        } 

        int result=0;

        int min=*min_element(p.begin(),p.end());
        
        for(int i=0;i<n;i++)
        {
            if(p[i]!=min) 
            {
            	result++;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}