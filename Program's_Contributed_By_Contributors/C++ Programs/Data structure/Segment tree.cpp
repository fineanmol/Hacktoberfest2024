#include<iostream>
using namespace std;
#define N 1005
int n,T[N<<2],arr[N];
/*
    
    "Fake" segment tree (with single element update)
    use array instead of pointer
    (Botton-up with bitwise operation )
*/
void Build(){
    for(int i=n-1;i ;i--){
        T[i]=T[i<<1] + T[i<<1|1];
    }
}

int Query(int l,int r){ // [l,r )
    int ret=0;
    for(l+=n,r+=n ;l<r ;l>>=1 ,r>>=1 ){
        if(l&1) ret+= T[l++];
        if(r&1) ret+= T[--r];
    }
    return ret;
}
void Modify(int i,int val){
    for( T[i+=n]=val ;i ;i>>=1){
        T[i>>1] = T[i]+T[i^1];
    }
}
void Demo(){
    n=10;
    for(int i=0;i<n;i++){
        arr[i]=rand()%10+1;
        cout<<arr[i]<<' ';
        T[i+n]= arr[i];
    }
    cout<<'\n';
    Build();
    cout<<Query(0,6)<<'\n'; //[0,5]
    cout<<Query(1,6)<<'\n'; //[1,5]
    cout<<Query(0,3)<<'\n'; //[0,2]
    Modify(1,3);
    cout<<Query(1,2)<<'\n'; //[1,1]
}
int main(){
    srand(time(NULL));

    Demo();
    return 0;
}
