#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

// Merge Sort Algorithm

// Time complexity
// Best: O(n log n)
// Average: O(n log n)
// Worst: O(n log n)

// Space complexity: O(n)
template <class T>
void merge(vector<T>& list, int start, int mid, int end, int &nComparisons) { // merge two sorted sublists
    vector<T> left; // left sublist
    vector<T> right; // right sublist
    int leftSize = mid - start + 1; // size of left sublist
    int rightSize = end - mid; // size of right sublist

    for (int i = 0; i < leftSize; i++) { // copy left sublist to left vector
        left.push_back(list[start+i]); // copy element
    }

    for (int i = 0; i < rightSize; i++) { // copy right sublist to right vector
        right.push_back(list[i+mid+1]); // copy element
    }

    int pos = start; // position in list
    int leftPos = 0; // position in left sublist
    int rightPos = 0; // position in right sublist

    while (leftPos < leftSize && rightPos < rightSize) {    // while both sublists are not empty
        nComparisons++;    // increment comparisons
        if (left[leftPos] < right[rightPos]) { // if left element is smaller than right element
            list[pos] = left[leftPos]; // copy left element to list
            leftPos++; // increment left sublist position
        } else { // if right element is smaller than left element
            list[pos] = right[rightPos]; // copy right element to list
            rightPos++; // increment right sublist position
        }
        pos++; // increment position in list
    }

    while (leftPos < leftSize) { // while left sublist is not empty
        list[pos] = left[leftPos]; // copy left element to list
        leftPos++; // increment left sublist position
        pos++; // increment position in list
    }

    while (rightPos < rightSize) { // while right sublist is not empty
        list[pos] = right[rightPos]; // copy right element to list
        rightPos++; // increment right sublist position
        pos++; // increment position in list
    }
}

template <class T> // merge sort algorithm
void mergeSort(vector<T>& list, int start, int end, int &nComparisons) { // sort sublist

    if(end > start) { // if sublist is not empty
        int mid = (start + end) / 2;  // find midpoint of sublist
        mergeSort(list, start, mid, nComparisons); // sort left sublist
        mergeSort(list, mid+1, end, nComparisons); // sort right sublist
        merge(list, start, mid, end, nComparisons); // merge two sorted sublists
    }
}


int main()
{
    int nComparisons = 0;
    vector<int> list;
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter element " << i+1 << ": ";
        cin >> x;
        list.push_back(x);
    }
    cout << "The list is: ";
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << "\n";
    mergeSort(list, 0, n-1, nComparisons);
    cout << "The sorted list is: ";
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << "\n";
    cout << "The number of comparisons is: " << nComparisons << "\n";
    return 0;
}
