class Solution {
public:
    int maxArea(vector<int>& height) {
       int maxar = INT_MIN;
        int left = 0, right = height.size()-1, crar = 0;
        while (left < right){
            crar = abs(left-right) * (min(height[left], height[right]));
            if (maxar < crar) maxar = crar;

            if (height[left] < height[right]) left++;
            else right--;
        }

        return maxar; 
    }
};
