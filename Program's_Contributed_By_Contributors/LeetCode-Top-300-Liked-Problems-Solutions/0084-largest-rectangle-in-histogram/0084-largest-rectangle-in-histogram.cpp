class Solution {
public:
    // // 3 pases - Optimal => Using the concept of left smallest and right smallest
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     stack<int> st;
    //     int leftSmallest[n], rightSmallest[n];
    //     // finding the left Smallest
    //     for(int i = 0; i < n; i++)
    //     {
    //         while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

    //         if(st.empty()) leftSmallest[i] = 0;
    //         else leftSmallest[i] = st.top() + 1;

    //         st.push(i);
    //     }

    //     while(!st.empty()) st.pop();

    //     // finding the right Smallest
    //     for(int i = n - 1; i >= 0; i--)
    //     {
    //         while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

    //         if(st.empty()) rightSmallest[i] = n - 1;
    //         else rightSmallest[i] = st.top() - 1;

    //         st.push(i);
    //     }

    //     int maxArea = 0;
    //     for(int i = 0; i < n; i++)
    //         maxArea = max(maxArea, (rightSmallest[i] - leftSmallest[i] + 1) * heights[i]);
        
    //     return maxArea;

    // }

    // Single pass - Most optimal
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, n = heights.size();
        for(int i = 0; i <= n; i++){
            // Using the concept of left smallest and right smallest in 1 pass
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i; // There is no leftSmallest
                else width = i - st.top() - 1; // where st.top() is the leftSmallest here and i is the right smallest as  heights[i] is smaller than the top of stack (which is the reason for popping out the top)
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};