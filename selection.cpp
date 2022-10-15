#include <bits/stdc++.h>
using namespace std;

void display(vector<int> A, int n)
{
    cout << endl;
    for (auto i : A)
        cout << i << " ";
}

void S_S(vector<int> &A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
//         int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
//                 pos = j;
            }
        }
        if(min!=i)
            swap(A[i], A[min]);
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

    S_S(V, n);
    display(V, n);
}
