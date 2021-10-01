#include <iostream>
#include <numeric>
using namespace std;
 
// Optimized method to find the equilibrium index of an array
void findEquilibriumIndex(int A[], int n)
{
    // `total` stores the sum of all the array elements
    int total = accumulate(A, A + n, 0);
 
    // `right` stores the sum of elements of subarray `A[i+1…n)`
    int right = 0;
 
    // traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        /* `i` is an equilibrium index if the sum of elements of subarray `A[0…i-1]`
           is equal to the sum of elements of the subarray `A[i+1…n)` i.e.
           `(A[0] + A[1] + … + A[i-1])` = `(A[i+1] + A[i+2] + … + A[n-1])` */
 
        // sum of elements of the left subarray `A[0…i-1]` is `total - (A[i] + right)`
        if (right == total - (A[i] + right)) {
            cout << "Equilibrium Index found " << i << endl;
        }
 
        // new right is `A[i] + (A[i+1] + A[i+2] + … + A[n-1])`
        right += A[i];
    }
}
 
int main()
{
    int A[] = { 0, -3, 5, -4, -2, 3, 1, 0 };
    int n = sizeof(A) / sizeof(A[0]);
 
    findEquilibriumIndex(A, n);
 
    return 0;
}
