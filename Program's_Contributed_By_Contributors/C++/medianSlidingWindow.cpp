#include<bits/stdc++.h>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    // we will use two multiset to get the median such that the right partition multiset will have elements >= left partition
    // left partition gives max element
    multiset<int, greater<int>> left;
    // right partition gives min element
    multiset<int> right;
    int i = 0;
    vector<double> ans;
    for(int j=0; j<nums.size(); j++) {
        left.insert(nums[j]);
        if(!right.empty() && *left.begin() > *right.begin()) { // right partiton will have elements >= left partiton set
            right.insert(*left.begin());
            left.erase(left.begin());
        }
        // balancing left & right partiton such that difference of their size should not exceed 1
        if(left.size() > right.size()+1) {
            right.insert(*left.begin());
            left.erase(left.begin());
        }
        if(right.size() > left.size()+1) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        
        // Reached Window size
        if(j-i+1 == k) {
            double val;
            if(k & 1) { // if window is odd, set won't have equal size then the mid will be always present at the begining of set which have greater size
                val = left.size() > right.size() ? *left.begin() : *right.begin();
            } else { // if window is even, set have equal size then the mid will be the half of top values of both set
                val = ( (double)*left.begin() + (double)*right.begin() ) / (double)2;
            }
            ans.push_back(val);
            // now window is gonna shift by 1, we have to remove the occurence of first value of window
            // the occurence may be present at left partition set or the right partition set
            // we have to check in which partition our ith value is present & then we will delete that occurence from the partition
            bool alreadyRemoved = false;
            auto itr = left.find(nums[i]);
            if(alreadyRemoved == false && itr != left.end()) {
                left.erase(itr);
                alreadyRemoved = true;
            }
            auto jtr = right.find(nums[i]);
            if(alreadyRemoved == false && jtr != right.end()) {
                right.erase(jtr);
                alreadyRemoved = true; 
            }
            // shifting the window
            i++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    vector<double> result = medianSlidingWindow(nums, k);
    for(auto &num : result) {
        cout << num;
    }
    return 0;
}