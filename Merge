#include<bits/stdc++.h>
using namespace std;

void display(vector<int> A, int n){
    cout<<endl;
    for(auto i:A)
    cout<<i<<" ";
}

void Sh_S(vector<int> &A, int n){
    int interval=1;
    while(interval<n/3)
    {
        interval=(interval*3)+1;
    }
    while(interval>=1)
    {
        for(int i=interval;i<n;i++)
        {
            int key=A[i];
            int j=i-interval;
            while(j>=0 && A[j]>key)
            {
                A[j+interval]=A[j];
                j=j-interval;
            }
            A[j+interval]=key;
            display(A,n);
            cout<<endl<<interval<<endl;///
        }
        interval=(interval-1)/3;
    }
}



int main(){
    vector<int> V;
    int ch,n;
    cout<<"size: ";
    cin>>n;
    cout<<"ENTER ARRY: ";
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        V.push_back(ch);
    }

   Sh_S(V,n);
   display(V,n);
}
