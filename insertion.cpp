#include <bits/stdc++.h>
using namespace std;

void display(vector<int> A, int n)
{
    cout << endl;
    for (auto i : A)
        cout << i << " ";
}

void I_S(vector<int> &A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, key = A[i];
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    vector<int> V;
    int ch, n;
    cout << "size: ";
    cin >> n;                //taking size from user
    cout << "ENTER ARRY: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        V.push_back(ch);	//taking and storing array values form user

    }

    I_S(V, n);			//user defined sort fun
    display(V, n);		// to display array
}