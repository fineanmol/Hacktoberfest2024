#include <bits/stdc++.h>
using namespace std;

 // given 2 array , for each element of array2 find no. of elements smaller than or equal to it in array1.
 // Ex - arr1[] = {1,2,3};
 //      arr2[] = {2,4};
 //      result[] = {2,3}; //1,2 ->equal to or smaller than 2 & 1,2,3 equal/smaller than 4

vector<int> calculateSmaller(vector<int> &a, vector<int> &b) {
    // int max1 = *max_element(a.begin(), a.end());
    // int max2 = *max_element(b.begin(), b.end());
    // // int maxElement = max(, *max_element(b.begin(), b.end()));
    // int maxElement = max(max1, max2);
    vector<int> count(1000);
    vector<int> result;
    
    //counting each element of arr1
    for(int i = 0; i < a.size(); i++) {
        count[a[i]]++;
    }
    // adding previous element value to get all the smaller element for that value
    for(int i = 1; i <= count.size(); i++) {
        count[i] += count[i-1];
    }
    

    for(int i = 0; i < b.size(); i++) {
        if(b[i] <= count.size()) {
            result.push_back(count[b[i]]);
        }
        else {
            result.push_back(count[count.size()-1]);
        }
    }

    return result;
}

int main() {
    vector<int> a = {1,2,3};
    vector<int> b = {2,4};

    vector<int> result = calculateSmaller(a,b);

    for(auto i : result) {
        cout<<i<<" ";
    }
}
