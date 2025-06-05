// Q70 https://leetcode.com/problems/kth-largest-element-in-an-array/



//BETTER
// https://classroom.codingninjas.com/app/classroom/me/6855/content/92022/offering/1027938/problem/1641
#include<queue>
int kthLargest(int* arr, int n, int k) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> p;
    int i;
    for(i=0;i<k;i++){
        p.push(arr[i]);
    }
    for(i; i<n;i++){
        if(arr[i]>p.top()){
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}








// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0)
            return -1;
        priority_queue<int> pq;
        // priority_queue<int,vector<int>,greater<int>> pq; MIN HEAP
        for(auto i: nums)
            pq.push(i);
        int res=INT_MIN;
        while(k--){
            res=pq.top();
            pq.pop();
        }
        return res;
    }
};
