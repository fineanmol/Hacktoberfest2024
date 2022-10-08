#include<iostream>
using namespace std;

int sum (int a , int b);
{
    int s1= a+b;
    return s1;

}
    

void print (int s2)
{
    cout<<"the sum is"<<s2;
    return ;

}
int main()
{
int num1=5;
int num2=6;
int sum_of= sum(num1 ,num2);
print(sum_of);
return 0;
}
