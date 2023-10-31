#include<iostream>
using namespace std;

int Nstair(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return Nstair(n-1)+Nstair(n-2)+Nstair(n-3);
}
int Nstair1(int n, int k){
     if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
int sum=0;
    for(int j=1;j<=k;j++){
        sum+=Nstair1(n-j,k);
    }
    return sum;

}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    cout<<Nstair1(n,k)<<endl;
    return 0;
}