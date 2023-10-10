//Leetcode 42

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0; int right = n-1;
        int res = 0;
        int maxleft = 0; int maxright = 0;
        while(left<=right){
            if (height[left] <= height[right]){
                if (height[left]>=maxleft) maxleft = height[left];
                else res+= maxleft-height[left];

                left++;
            }
            else {
                if(height[right]>= maxright) maxright = height[right];
                else res+=maxright - height[right];

                right--;
            }
        }
        return res;
        
    }
};
