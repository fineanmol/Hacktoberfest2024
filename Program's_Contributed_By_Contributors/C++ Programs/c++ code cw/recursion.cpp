#include<iostream>
using namespace std;
// int factorial (int n){
//     if(n<=1){
//         return 1;
//     }
//     return n * factorial(n-1);
// }
int fib(int n){
    if(n<=2){
        return 1;
    }
    return fib(n-2) + fib(n-1);
}
int main(){
    // int a ;
    // cin>>a;
    // cout<<"the factorial of a is "<<factorial(a)<<endl;
    // return 0;

    /*
    step by step calculation 
    factorial 4 = 4 * factorial (3)
    factorial  = 4 * 3 * factorial (2)
    factorial  = 4 * 3 * 2 factorial (1)
    factorial  = 4 * 3 * 2 *1
    
    */

    int a ;
    cin>>a;
    cout<<"the fibonacci of a is "<<fib(a)<<endl;
    return 0;

    /*
    fibo = 5 
    fib(2) +  fib(3)
    fib(1) + fib(1)   fib(2) + fib(1)
    
    
    */

}