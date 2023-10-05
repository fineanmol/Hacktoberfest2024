// Binary Search
#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int s=0;
    int e=n;

    while(s<=e){
        int mid = (s+e)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        
    }return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int array[n];

    for (int i=0; i<n;i++){
        cin>>array[i];
    }

    int key;
    cin>>key;

    cout<< binarySearch(array, n, key)<<endl;

    return 0;
}