#include<iostream>
using namespace std;

int arr[100001];

void CreateFactorial()
{
    arr[0] = 1;
    arr[1] = 1;
    for (int index = 2; index < 100001; index++){
        arr[index] = arr[index-1] * index;
    }
}

int main()
{
    CreateFactorial();
    int x; cin >> x;
    cout << arr[x] << endl;
    return 0;
}