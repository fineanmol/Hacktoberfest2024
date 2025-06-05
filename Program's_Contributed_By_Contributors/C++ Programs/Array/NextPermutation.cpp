#include <bits/stdc++.h> 
using namespace std;

vector<int> nextPermutation(vector<int> &A, int n) {
    int ind = -1;
    
    // Find the first index (ind) from the right where A[ind] < A[ind + 1]
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }
    
    if (ind == -1) {
        // If no such index is found, reverse the entire vector and return
        reverse(A.begin(), A.end());
    } else {
        // Find the rightmost element greater than A[ind]
        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                swap(A[i], A[ind]);
                break;
            }
        }
        
        // Reverse the elements from ind + 1 to the end to get the next permutation
        reverse(A.begin() + ind + 1, A.end());
    }
    
    return A;
}

int main() {
    vector<int> A = {1, 2, 3};
    int n = A.size();
    
    A = nextPermutation(A, n);
    
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}
