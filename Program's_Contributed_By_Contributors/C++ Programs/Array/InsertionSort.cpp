#include <iostream>
using namespace std;

void printing(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   
}

int main()
{
    int n;
    cout<<"Enter the number of elements in array-";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"\n\nUnsorted array is"<<endl;
    printing(arr,n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int j = i-1;
        while(arr[j] > curr && j!=-1){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
    cout<<"\n\nSorted array is"<<endl;
    printing(arr,n);
    return 0;
}