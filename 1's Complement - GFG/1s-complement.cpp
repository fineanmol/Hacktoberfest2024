// { Driver Code Starts
 
#include<bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends
  
class Solution{ 
public:
     string onesComplement(string S,int N){
       //code here
   int i=0;
   string result="";
   while(i<N){
       if(S[i]=='1'){
           result.append("0");
       }
       else{
           result.append("1");
           }
           i++;
       }
       return result;
   
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.onesComplement(s,n)<<"\n";
    }
}  // } Driver Code Ends