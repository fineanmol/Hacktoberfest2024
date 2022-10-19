#include<bits/stdc++.h>
using namespace std;
class  segtree{
    public:
    vector<int> seg;
    segtree(int n){
        seg.resize(4*n+1);
    }
void build(int indx,int low,int high,int arr[]){
    if(low==high) {
        seg[indx]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*indx+1,low,mid,arr);
    build(2*indx+2,mid+1,high,arr);
    seg[indx]=min(seg[2*indx+1],seg[2*indx+2]);
}
int query(int indx,int low,int high,int l,int h){
    if(high<l || low>h) return INT_MAX;
    if(low>=l && high<=h) return seg[indx];
    int mid=(low+high)/2;
    int left=query(2*indx+1,low,mid,l,h);
    int right=query(2*indx+2,mid+1,high,l,h);
    return min(left,right); 
}
void update(int indx,int i,int val,int low,int high){
    if(low==high){
        seg[indx]=val;
        return ;
    }
    int mid=(low+high)/2;
    if(i<=mid) update(2*indx+1,i,val,low,mid);
    else update(2*indx+2,i,val,mid+1,high);
    seg[indx]=min(seg[2*indx+1],seg[2*indx+2]);
}
};
int main(){
return 0;
};
