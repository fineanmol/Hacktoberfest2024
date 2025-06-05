#include<iostream>
using namespace std;
int swap(int a , int b){
    int temp;
    temp = a;
    a  = b;
    b  = temp;
    
}
// call by pointer by c++ in functons/ call by reference using pointer 
int SwapPointer(int* a , int* b){
    int temp;
    temp = *a;
    *a  = *b;
    *b  = temp;
    
}

// call by reference by c++ in functons
int SwapReference(int &a , int &b){
    int temp;
    temp = a;
    a  = b;
    b  = temp;
    
}
int main(){
    int a=5 ;
    int b=4 ;
    cout<<"with out swap functions "<<" a "<<a<<" and b "<<b<<endl;
    // call by pointer by c++ in functons

    // cout<<"with swap functions "<<SwapPointer(&a,&b)<<endl;
    // cout<<" a = "<<a<<" and b "<<b<<endl;

    // call by reference by c++ in functions

     cout<<"with swap functions "<<SwapReference(a,b)<<endl;
    cout<<" a = "<<a<<" and b "<<b<<endl;


    
}