#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& a, int k) {
    k=k%a.size();
    reverse(a.begin(),a.end());
    reverse(a.begin(),a.begin()+k);
    reverse(a.begin()+k,a.end());

}

int main()
{
    cout<<"Enter size of array ::"<<endl;
    int n;
    cin>>n;

    vector<int> a(n);
    cout<<"Enter the "<<n<<" element of the array ::"<<endl;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int k;
    cout<<"Enter right rotation steps::"<<endl;
    cin>>k;
    rotate(a,k);

    cout<<"After "<<k<<" right rotation::"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
