
#include<iostream>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
class Guess{
    int n,i,num;

    public:
        Guess()
        {
            srand(time(0));
            n=1+rand()%100;
            cout<<endl<<"Enter a number between 1 and 100 "<<endl;
            cin>>num;
        }
        void number();
};

void Guess ::number(){
    for (i=4;i>=0;i--)
    {
        if (num==n)
        {
            cout<<endl<<"You guess the right number. ";
            break;
        }
        else if (i==0 &&num!=n)
        {
            cout<<endl<<"You lost the game. ";

        }
        else if (num>n)
        {
            cout<<"The entered number is larger."<<endl;
            cout<<endl<<"You left with "<<i<<" chances. "<<endl;
            cout<<"Enter : ";
            cin>>num;

        }
        else if (num<n)
        {
            cout<<"The entered number is smaller."<<endl;
            cout<<endl<<" You left with "<<i<<" chances. "<<endl;
            cout<<"Enter : ";
            cin>>num;
        }
    }
}

int main(){
    Guess obj;
    obj.number();
    Sleep(3*1000);
    system("pause");
    return 0;
    
}

//instructions not given 
