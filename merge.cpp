#include <bits/stdc++.h>
using namespace std;

void display(vector<int> A, int n)
{
    cout << endl;
    for (auto i : A)
        cout << i << " ";
}

void merge(int f, int mid, int l, vector<int> &A){
    vector<int> temp;
    int i=f,j=mid+1;
    while(i<=mid && j<=l)
    {
        if(A[i]<A[j])
        {
            temp.push_back(A[i]);
            i++;
        }
        else if(A[i]>A[j])
        {
            temp.push_back(A[j]);
            j++;
        }
        else
        {
            temp.push_back(A[i]);
            temp.push_back(A[j]);
            j++;
            i++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(A[i]);
        i++;
    }
    while(j<=l)
    {
        temp.push_back(A[j]);
        j++;
    }

    for(auto i:temp){
        A[f]=i;
        f++;
    }
}
void M_S(vector<int> &A, int n,int f,int l)
{
    if(f>=l)
    return;
    int mid=(f+l)/2;
    M_S(A,n,f,mid);
    M_S(A,n,mid+1,l);
    merge(f,mid,l,A);  
    display(A, n); 
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

    M_S(V, n, 0, n-1);
    
}