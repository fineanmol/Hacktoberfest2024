/* C++ code for Book Allocation problem to find the minimum value of the maximum
number of pages*/
#include <bits/stdc++.h>

using namespace std;
/*function to check if it is possible to allocate the books such that the
maximum number of pages assigned to any student is numPages*/
bool isPossible(int pages[], int n, int m, int numPages) {
    int cntStudents = 1;
    int curSum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > numPages) {
            return false;
        }
        if (curSum + pages[i] > numPages) {
            /* Increment student count by '1'*/
            cntStudents += 1;
            /* assign current book to next student and update curSum */
            curSum = pages[i];
            /* If count of students becomes greater than given no. of students, return False*/
            if (cntStudents > m) {
                return false;
            }
        } else {
            /* Else assign this book to current student and update curSum */
            curSum += pages[i];
        }
    }
    return true;
}
int allocateBooks(int pages[], int n, int m) {
    /* If number student is more than number of books */
    if (n < m) {
        return -1;
    }
    /* Count total number of pages */
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pages[i];
    }
    /* Check for every possible value */
    for (int numPages = 1; numPages <= sum; numPages++) {
        if (isPossible(pages, n, m, numPages)) {
            return numPages;
        }
    }
    return -1;
}
int main() {
    int n = 4;
    int m = 2;
    int pages[] = {10, 20, 30, 40};
    cout << "The minimum value of the maximum number of pages in book allocation is: " << allocateBooks(pages, n, m) << endl;
}