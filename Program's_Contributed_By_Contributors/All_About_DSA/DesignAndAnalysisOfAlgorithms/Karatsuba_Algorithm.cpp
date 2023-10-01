#include <iostream>
using namespace std;

int power(int a,int b){
    int i,mult=1;
    for (i=0;i<b;i++){
        mult = mult*a;
    }
    return mult;
}
int length(long int n,int b){
    int l=0;
    while (n>0){
        n=n/b;
        l++;
    }
    return l;
}
int max(int a,int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int b;
    long int x,y;
    long int result;
    cout<<"Enter the base : ";
    cin>>b;
    cout<<"Enter the first number : ";
    cin>>x;
    cout<<"Enter the second number : ";
    cin>>y;
    int m,n,max_mn,i;
    m = length(x,b);
    n = length(y,b);
    max_mn = max(m,n);
    if (max_mn%2!=0){
        max_mn = max_mn+1;
    }
    int xh=0,xl=0,yh=0,yl=0;
    int mult=1;
    for (i=0;i<max_mn/2;i++){
        xl = xl+mult*(x%b);
        x = x/b;
        mult = mult*b;
    }
    xh = x;
    mult=1;
    for (i=0;i<max_mn/2;i++){
        yl = yl+mult*(y%b);
        y = y/b;
        mult = mult*b;
    }
    yh = y;
    long int s1,s2,s3,s4;
    s1 = xh*yh;
    s2 = xl*yl;
    s3 = (xh+xl)*(yh+yl);
    s4 = s3-s2-s1;
    result = s1*power(b,max_mn)+s4*power(b,max_mn/2);
    cout<<x<<"*"<<y<<"="<<result<<endl;
    return 0;
}