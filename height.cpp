// this is program tell height in different units
#include<iostream>
using namespace std;
int main(){
    double n;
    cout<<"Enter your height in metres: \n";
    cin>>n;
    cout<<endl;
    cout<<"Your height in foots is: \n"<<n*3.28084;
    cout<<"Your height in centimeter is: \n"<<n*100;
    cout<<"Your height in inches is: \n"<<n*39.3701;
}
