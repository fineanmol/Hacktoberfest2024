#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<vector<int>> intervals = {{1,2},{2,6},{4,8},{9,11},{11,15},{18,20}};
	sort(intervals.begin(),intervals.end());    
    int curr_start = intervals[0][0];
    int curr_end = intervals[0][1];
    for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>curr_end)
            {
                cout<<curr_start<<", "<<curr_end<<endl;
                curr_start = intervals[i][0];
                curr_end = intervals[i][1];
            }
            else
            {
                curr_end = max(curr_end, intervals[i][1]);
            }
        }
        cout<<curr_start<<", "<<curr_end<<endl;
        return 0;
        
}