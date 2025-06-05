#include <iostream>
using namespace std;
//  inline int product (int a, int b){
//     //not recommended use with inline functions
//    // static int c = 0;//this execute only once 
//   //  c=c+1;// next time this function is run, the value of c will be retained
// return a*b;
//}
float moneyReceived(int currentmoney, float factor=1.04){// yaha factor default arguments hai 
    return currentmoney*factor;
}
int main(){
    // int a,b;
    // cout<<"enter a number "<<endl;
    // cin>>a;
    // cout<<"enter a number "<<endl;
    // cin>>b;
    // cout<<"the product is "<<product(a,b)<<endl;
    // cout<<"the product is "<<product(a,b)<<endl;
    // cout<<"the product is "<<product(a,b)<<endl;
    // cout<<"the product is "<<product(a,b)<<endl;9
    int money = 100000;
    cout<<"if you have "<<money<<"Rs in your bank account , you will receive "<<moneyReceived(money)<<"Rs after 1 year"<<endl;
    cout<<"For Vip : if you have "<<money<<"Rs in your bank account , you will recive "<<moneyReceived(money,1.1)<<"Rs after 1 year ";
    return 0;

}  