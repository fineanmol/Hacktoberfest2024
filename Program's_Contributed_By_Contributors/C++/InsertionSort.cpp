#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    
    vector<int> arr(n);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
