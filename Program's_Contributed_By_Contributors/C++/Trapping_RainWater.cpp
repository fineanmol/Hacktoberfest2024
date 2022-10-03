// C++ program for LeetCode Famous Trapping Rain Water problem

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    if(!height.size()){
        return 0;
    }
    
    int l = 0;
    int r = height.size()-1;
    int maxLeft = height[l];
    int maxRight = height[r];
    int ans = 0;
    
    while(l < r){
        if (maxLeft < maxRight){
            l += 1;
            maxLeft = max(maxLeft, height[l]);
            ans += maxLeft - height[l];
        }
        else {
            r -= 1;
            maxRight = max(maxRight, height[r]);
            ans += maxRight - height[r];
        }
    }
    
    return ans;
}

// Driver code
int main()
{
	
    vector<int> v { 4, 2, 0, 3, 2, 5 };
    cout << trap(v);

	return 0;
}
