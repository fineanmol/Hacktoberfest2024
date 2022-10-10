#include<bits/stdc++.h>
using namespace std ;

#define  ff      first 
#define  ss      second
#define  ull     unsigned long long 
#define  mod     1000000007
#define  inf     1e18
#define  w(x)    int x;cin>>x;while(x--)
#define  f(x,y)  for( x=0;x<y;x++) 

int main(){
    w(t){
        int a,b,c;
        cin>>a>>b;
        c=a+b;
        if(c<3){
            cout<<1<<endl;
        }
        else if(3<=c && c<=10){
            cout<<2<<endl;
        }
        else if(11<=c && c<=60){
            cout<<3<<endl;
        }
        else if(60<c){
            cout<<4<<endl;
        }
    }


 	return 0;
}