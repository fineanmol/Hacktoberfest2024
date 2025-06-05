#include<iostream>
#include<vector>
using namespace std;

void input(vector<int>&arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        int element;
        cin>>element;
        arr[i] = element;
    }
}

void output(vector<int>arr)
{
    for(int i = 0; i < arr.size(); ++i)
        cout<<arr[i]<<" ";
}

void bubble_sort(vector<int>&arr)
{
    for(int i = 0; i < arr.size() - 1; ++i)
        for(int j = 0; j < arr.size() - 1 - i; ++j)
            if(arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int main()
{
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter "<<n<<" elements into array : ";
    input(arr);
    bubble_sort(arr);
    cout<<"Sorted array : ";
    output(arr);
    return 0;
}
