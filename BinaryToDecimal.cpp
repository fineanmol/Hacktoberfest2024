#include<bits/stdc++.h>
using namespace std;
// Function to convert in Decimal
int toDecimal(string s)
{
int value = 0;
int indexCounter = 0;
for(int i=s.length()-1;i>=0;i--){

    if(s[i]=='1'){
        value += pow(2, indexCounter);
    }
    indexCounter++;
}
return value;

}
int main()
{
    // Input the binary string you want to convert
    string s="1001011";

    cout<<toDecimal(s)<<endl;

    return 0;
}
