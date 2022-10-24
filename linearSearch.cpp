#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int k) {
    for(int i=0; i<n; i++)
        if(arr[i] == k)
            return true;

    return false;
}

int main() {
    int arr[5] = {3,654,236,63,2};
    int target;
    cin >> target;

    cout << (linearSearch(arr, 5, target) ? "Found" : "Not Found") << endl;
}
