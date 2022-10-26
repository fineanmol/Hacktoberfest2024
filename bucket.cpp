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
    vector<int> B[n];
    for(int i=0;i<n;i++){
        B[n*A[i]]=
    }
}

int main()
{
    vector<int> V;
    int ch, n;
    cout << "size: ";
    cin >> n;
    cout << "ENTER ARRY: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        V.push_back(ch);
    }

    B_S(V, n);
    display(V, n);
}