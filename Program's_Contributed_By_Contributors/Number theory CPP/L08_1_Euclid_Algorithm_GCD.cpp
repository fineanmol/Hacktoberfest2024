#include<bits/stdc++.h>
using namespace std;
//recursive approach
// int gcd(int a, int b)
// {
//     if (b==0)
//         return a;
//     else
//         return gcd(b, a%b);
// }
//Iteratibe approach
int gcd(int a, int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b; 
        a=temp;
    }
    return a;
}



int main()
{
    int a, b;
    cin>>a>>b;
    cout<<gcd(a, b)<<endl;
    return 0;
}
