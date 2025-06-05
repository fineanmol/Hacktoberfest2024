/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> hts;
        int maxarea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!hts.empty() && heights[i] < heights[hts.top()]) {
                int ht1 = heights[hts.top()];
                hts.pop();
                int width = (hts.empty() ? i : i - hts.top() - 1);
                int area = ht1 * width;
                maxarea = max(maxarea, area);
            }
            hts.push(i);
        }

        while (!hts.empty()) {
            int ht1 = heights[hts.top()];
            hts.pop();
            int width = (hts.empty() ? n : n - hts.top() - 1);
            int area = ht1 * width;
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};