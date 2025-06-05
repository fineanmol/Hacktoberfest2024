#include<iostream>
using namespace std;
int main()
{
    // int t;
    // cin>>t;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    /*
    pd=previous common difference
    ans=final answer
    curr=current arithematic subarray length
    */
    int ans=2;
    int pd=a[1]-a[0];
    int j=2;
    int curr=2;
    while(j<n)
    {
        if(pd==a[j]-a[j-1])
        {
            curr++;
        }
        else
        {
            pd=a[j]-a[j-1];
            curr=2;
            }
            ans=max(ans,curr);
            j++;
        
    }
    cout<<ans<<endl;
    return 0;
}
