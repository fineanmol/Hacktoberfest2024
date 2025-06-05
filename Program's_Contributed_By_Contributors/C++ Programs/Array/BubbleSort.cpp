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
    cout<<"Enter number of elements in array- ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i]; 
    }
    cout<<"\n\nUnsorted array is"<<endl;
    printing(arr,n);
    for(int i = 1; i < n; i++){
        for (int j = 0; j < n-i; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }    
    }
    cout<<"\n\nSorted array is"<<endl;
    printing(arr,n);
    return 0;
}