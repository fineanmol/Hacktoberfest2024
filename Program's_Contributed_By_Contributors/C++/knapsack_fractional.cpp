#include<bits/stdc++.h>
using namespace std;

class Item
{
public:
    int p,w;
    Item()
    {
        p=0;
        w=0;
    }

    void assign(int a,int b)
    {
        p=a;
        w=b;
    }
};
Item a[100],t[100];

void merge(int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    while(i<=m && j<=r)
    {
        //p1/w1>p2/w2 ie we will choose the one with higher ratio to go first
        int v1=a[i].p*a[j].w,v2=a[i].w*a[j].p;
        if(v1>v2) t[k++].assign(a[i].p,a[i].w), i++;
        else t[k++].assign(a[j].p,a[j].w), j++;
    }

    while(i++<=m) t[k++].assign(a[i-1].p,a[i-1].w);
    while(j++<=r) t[k++].assign(a[j-1].p,a[j-1].w);

    for(i=l,j=0;j<k;i++,j++) a[i].assign(t[j].p,t[j].w);
}

void sort(int l,int r)
{
    if(l>=r) return;
    int m=(l+r)>>1;
    sort(l,m);
    sort(m+1,r);
    merge(l,m,r);
}

int main()
{
    int n,i,w;
    //cout<<"Enter number of elements and weight of knapsack: ";
    cin>>n>>w;
    //cout<<"Enter profit of elements: ";
    for(i=0;i<n;i++) cin>>a[i].p;
    //cout<<"Enter weight of elements: ";
    for(i=0;i<n;i++) cin>>a[i].w;

    sort(0,n-1);
    double val=0; int cur=0;
    /*for(i=0;i<n;i++)
    cout<<a[i].p<<" "<<a[i].w<<"\n";*/

    for(i=0;i<n;i++)
    if(cur+a[i].w<=w) cur+=a[i].w, val+=a[i].p;
    else
    {
        val+=1.0*(w-cur)/a[i].w*a[i].p;
        break;
    }
    //cout<<i<<"\n";
    cout<<"Maximum profit of knapsack is:"<<val<<"\n";
    return 0;
}