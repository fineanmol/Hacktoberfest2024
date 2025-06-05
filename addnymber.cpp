#include<iostream>
using namespace std;
int main()
{
    int i, n, num, sum=0;
    cout<<"How many numbers you want to enter ? ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers: ";
    for(i=0; i<n; i++)
    {
        cin>>num;
        sum = sum+num;
    }
    cout<<"\nSum of all "<<n<<" numbers is "<<sum;
    cout<<endl;
    return 0;
}
