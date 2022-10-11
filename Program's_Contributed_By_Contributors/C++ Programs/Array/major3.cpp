#include<bits/stdc++.h>
using namespace std;

int main()
{

	vector<int> nums = {1,1,1,2,3,2,3,2};
	int num1 = INT_MIN;
        int num2 = INT_MIN;
        int count1=0,count2=0;
        for(auto x: nums)
        {
            if(x==num1)
                count1++;
            else if(x==num2)
                count2++;
            else if(count1==0)
            {
                num1=x;
                count1=1;
            }
            else if(count2==0)
            {
                num2=x;
                count2=1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(auto x:nums)
        {
            if(x==num1)
                count1++;
            if(x==num2)
                count2++;
            
        }
        vector<int> ans;
        if(count1>nums.size()/3)
            cout<<num1<<" ";
        if(count2>nums.size()/3)
            cout<<num2<<" ";
        cout<<endl;

        return 0;
}