#include<iostream>
using namespace std;
void printnumbers()
{
    int n=1;
    lebel:
     cout<<n<<"";
    n++;
    if(n<=10)
    goto lebel;
    
}
int main()
{
    printnumbers();
    return 0;

}