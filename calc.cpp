#include <iostream>
using namespace std;
int main(){
    int a,b;
    char c;
    cout<<"ENTER THE TWO NUMBERS"<<endl;
    cin>>a>>b;
    cout<<"ENTER THE DESIRED OPERATION p-add q- subtract r - multiply s-divide(greatest/smallest - GREATEST INTEGER FUNCTION)"<<endl;
    cin>>c;
    if(c=='p'){
        cout<<(a+b)<<endl;
    } else if(c=='q'){
        if(a>b){
            cout<<(a-b);
        } else{
            cout<<(b-a);
        }
    } else if(c=='r'){
        cout<<a*b<<endl;
    } else if(c=='s'){
        if(a>b){
            cout<<(a/b)<<endl;
        } else {
            cout<<(b/a)<<endl;
        }
    } return 0;
}
