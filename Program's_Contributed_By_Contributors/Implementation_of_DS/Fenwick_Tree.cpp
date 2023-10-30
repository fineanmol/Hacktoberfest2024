#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int n;
int a[N]={0}; 
int BIT[N]={0}; 


// range sum query 

void update(int i,int ic){
    while(i<=n){
        BIT[i]+=ic;
        i+=(i&(-i));
    }
    return;
}


int query(int i){
     int re = 0;
     while(i>0){
         re+=BIT[i];
         i-=(i&(-i));
     }
     return re;
}

int main(){

    cin>>n;
    memset(BIT,0,sizeof BIT); 
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<(query(r)-query(l-1))<<"\n";
    }


    return 0;
}
