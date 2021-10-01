#include<bits/stdc++.h>
using namespace std;

//Finding Majority element in a given vector in O(1) space using Moore's voting algorithm 
int majorityElement(vector<int>& v) {
        int c1=0;
        int ans1=INT_MIN;
        for(int i=0;i<v.size();i++)
        {
            if(ans1==v[i])
            {
                c1++;
            }
            else if(ans1==INT_MIN)
            {
                c1=1;
                ans1=v[i];
            }
            else
            {
                c1--;
                if(c1==0) ans1=INT_MIN;
            }
        }
        return ans1;
    }

int main()
{
    //input vector
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans=majorityElement(v);
    cout<<ans<<endl;    
}    