#include <iostream>
using namespace std;
//Taking input
void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> a[i];
    }
}
//swap function
void swap(int& c, int& d) {
    int temp = c;
    c = d;
    d = temp;
}
//bubble sort function
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
//display function
void display(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int numbers[n];
    input(numbers, n);

    cout << "Before sorting: "<<endl;
    display(numbers,n); 
    bubble_sort(numbers, n);
    cout << "\nAfter sorting: "<<endl;
    display(numbers,n);
    
    return 0;
}
