#include<iostream>
using namespace std;

class arrayx
{
private:
    char ch1[5];
    char ch2[5];
public:
    void input()
    {
        cout<<"Enter elements of array\n";
        int i;
        for(i=0;i<=4;i++)
        {
            cin>>ch1[i];

        }
    }
    void reversee ()
{
    int i;
    for(i=0;i<=4;i++)
    {
        ch2[4-i]=ch1[i];
    }
}
void output()
{
    int i;
    cout<<"Reversed array is\n";
    for(i=0;i<=4;i++)
    {
        cout<<ch2[i]<<std::endl;

    }
}
};
int main()
{
    arrayx a1;
    a1.input();
    a1.reversee();
    a1.output();
    return(0);
}
