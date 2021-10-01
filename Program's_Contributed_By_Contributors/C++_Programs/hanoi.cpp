//This program is to implement tower of hanoi using recursion
#include<iostream>
using namespace std;
void TOH(int n,char sour,char des,char aux)
{   if(n==1)
    {   cout<<"Move Disk "<<n<<" from "<<sour<<" to "<<des<<endl;
        return;
    }
    
    TOH(n-1,sour,aux,des);
    cout<<"Move disk "<<n<<" from "<<sour<<" to "<<des<<endl;
    TOH(n-1,aux,des,sour);
}
int main()
{   
    int n;
    cout<<"Enter number of disks ";
    cin>>n;
    TOH(n,'A','B','C');
    system("pause");
    return 0;
}
