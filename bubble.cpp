#include <bits/stdc++.h>
using namespace std;

void display(vector<int> A, int n)
{
    cout << endl;
    for (auto i : A)
        cout << i << " ";
}

void B_S(vector<int> &A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
}

int main()
{
    vector<int> V;
    int ch, n;
    cout << "size: ";     
    cin >> n;		//taking size from user
    cout << "ENTER ARRY: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ch;		//taking array values
        V.push_back(ch);
    }

    B_S(V, n);			//user defined fxn to sort the array
    display(V, n);		//to display the array
}