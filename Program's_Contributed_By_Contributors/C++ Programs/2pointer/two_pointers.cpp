#include <iostream>
#include <vector>
using namespace std;

bool twoSum(vector<int>& nums, int target, int& i, int& j) {
  int left = 0; 
  int right = nums.size() - 1;
  
  while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) {
      i = left;
      j = right;
      return true;
    }
    else if (sum < target) left++; 
    else right--;
  }
  
  return false;
}

int main() {

  vector<int> nums {2, 5, 7, 8, 9}; 
  int target = 11;
  int i, j;
  
  if (twoSum(nums, target, i, j)) {
    cout << "Found: [" << i << ", " << j << "]" << endl; 
  } else {
    cout << "Not found" << endl;
  }

  return 0;
}