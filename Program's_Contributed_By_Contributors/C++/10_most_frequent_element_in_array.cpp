// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

void frequent_element(int arr[], int n)
{

    int i, j, max_count = 0;
    cout << "\nMost occurred number: ";

    for (i = 0; i < n; i++)
    {
        int count = 1;
        for (j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j]) 
            {
                count++;
            }
            if(count > max_count)
            {
                max_count = count;
            }
        }
        
    }

    // this loop checks if there are more than one elements that are repeated

    for (i = 0; i < n; i++)
    {
        int count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count == max_count)
        {
            cout << arr[i] << endl;
        }
    }
}

int main()
{
    int arr[100], n, i;
    cout << "Please enter size of the array: ";
    cin >> n;
    cout << "Please enter elements in the array: \n";
    for (i = 0; i < n; i++)
    {
        cout << i + 1 << ":";
        cin >> arr[i];
    }

    cout << "Original array: ";

    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    frequent_element(arr, n);
    return 0;
}