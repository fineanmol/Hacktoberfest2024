
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int count = 0;
        int mxcount = 0;
        int curr_sum = 0;
        
        for(int i=0; i<n; i++){
            if(a[i]==1){
                curr_sum += -1;
                mxcount  = max(mxcount, curr_sum);
                count++;
            }
            else{
                curr_sum += 1;
                mxcount  = max(mxcount, curr_sum);
            }
            if(curr_sum<0){
                curr_sum = 0;
            }
        }
        
        return (count+mxcount);
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;
        int a[n+5];

        for(int i = 0 ; i <n;i++)
               cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a,n)<<endl;
    }
    return 0;
}