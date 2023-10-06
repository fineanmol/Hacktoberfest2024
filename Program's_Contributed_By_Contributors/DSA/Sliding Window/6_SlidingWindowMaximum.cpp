/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

https://leetcode.com/problems/sliding-window-maximum/description/
*/

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> result;
      deque<int> window;

      for (int i = 0; i < nums.size(); i++) {
          // Remove elements that are out of the current window
          while (!window.empty() && window.front() < i - k + 1) {
              window.pop_front();
          }

          // Remove elements that are less than the current element
          while (!window.empty() && nums[i] >= nums[window.back()]) {
              window.pop_back();
          }

          // Add the current element to the window
          window.push_back(i);

          // Add the maximum element of the current window to the result
          if (i >= k - 1) {
              result.push_back(nums[window.front()]);
          }
      }

      return result;
  }
};