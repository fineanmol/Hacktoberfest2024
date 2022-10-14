#include <bits/stdc++.h>
using namespace std;

void display(vector<int> A, int n)
{
    cout << endl;
    for (auto i : A)
        cout << i << " ";
}

void Q_S(vector<int> &A, int n,int f,int l)
{
    if(f>=l)
    return;
    if(l-f==1)
    {
        if(A[l]<A[f])
        swap(A[l],A[f]);
        return;
    }
    int pivot=A[l];
    int i=l-1,j=f;
    while (i>=j)
    {
        if(A[j]>pivot && A[i]<pivot)
        swap(A[j],A[i]);
        if(A[i]>pivot)
        i--;
        if(A[j]<pivot)
        j++;
        
    }
    swap(A[j],A[l]);
    int mid=j;
    Q_S(A,n,f,mid-1);
    Q_S(A,n,mid+1,l);
    display(A,n);
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

    Q_S(V, n, 0, n-1);
    display(V, n);
}