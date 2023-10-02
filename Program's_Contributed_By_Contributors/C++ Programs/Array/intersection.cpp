/* Code to find intersection of 2 array*/
#include<bits/stdc++.h>
void intersection(int *input1, int *input2, int m, int n)
{
    //Write your code here
    vector<int>res;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(input1[i]==input2[j])
            {
                res.push_back(input1[i]);
                input2[j]=INT_MIN;
                break;
            }
        }
    }
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;

}
