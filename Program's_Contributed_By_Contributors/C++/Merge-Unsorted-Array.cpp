#include <bits/stdc++.h>  
using namespace std;  
  
void sortedMerge(int a[], int b[], int res[],  
    int n, int m) // Merge two arrays in unsorted manner  
{  
    // Concatenate two arrays  
    int i = 0, j = 0, k = 0;  
    while (i < n) { // iterate in first array  
        res[k] = a[i]; // put each element in res array  
        i += 1;  
        k += 1;  
    }  
    while (j < m) { // iterate in the second array  
        res[k] = b[j]; // put each element in res array  
        j += 1;  
        k += 1;  
    }  
  
    sort(res, res + n + m); // sort the res array to get the sorted Concatenate  
}  
  
int main()  
{  
    int a[] = { 10, 5, 15, 22, 100 };  
    int b[] = { 20, 3, 2, 12, 1, 7 };  
    int n = sizeof(a) / sizeof(a[0]); // find the size of array a  
    int m = sizeof(b) / sizeof(b[0]); // find the size of array b  
  
    int res[n + m]; // create res array to Concatenate both the array  
    sortedMerge(a, b, res, n, m); // call function to append and sort  
  
    cout << "The sorted array is: ";  
    for (int i = 0; i < n + m; i++)  
        cout << " " << res[i];  
    cout << "\n";  
  
    return 0;  
} 
