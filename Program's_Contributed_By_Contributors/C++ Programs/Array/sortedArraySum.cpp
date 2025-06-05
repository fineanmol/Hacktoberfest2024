// Square of sorted Array
/*
Given an array of N integers sorted in non-decreasing order. 
You square each of these integers and re-arrange them in non-decreasing order. 
Print newly obtained array.

INPUT
The first line contains a single integer N
 - number of integers in the given array.

The next line contains N
 space-separated integers representing the array.

OUTPUT
Output a single line containing N integers consisting of new array obtained by squaring each integer in original array arranged in non decreasing order.
*/
#include <bits/stdc++.h>
using namespace std;

void squareSort(vector<int> &arr, vector<int> &ans){
  int n = arr.size();
  int left = 0, right = n-1;
  for(int i = n-1; i >= 0; i--){
    if(abs(arr[left]) >= abs(arr[right]))
    {
      ans[i] = arr[left] * arr[left];
      left++;
    }
    else{
      ans[i] = arr[right] * arr[right];
      right--;
    }
  }
}
int main() {
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++)
  cin>>arr[i];
  vector<int> ans(n);
  squareSort(arr, ans);
  for(auto x: ans) cout<<x<<" ";
  return 0;
}