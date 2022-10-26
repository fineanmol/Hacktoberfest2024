//basic bank deposit withdraw logic


#include<iostream>
#include<cmath>
#include<string>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

class bank
{
public:
string customer_name;
int accno;
string account_type;
float balance;

void initialize()
{
cout<<"Enter customer name : "<<endl;
cin>>customer_name;
cout<<"Enter account type: "<<endl;
cin>>account_type;
cout<<"Enter account number:"<<endl;
cin>>accno;
cout<<"Enter balance amount in account: "<<endl;
cin>>balance;

}

void deposit()
{
int amt;
cout<<"Enter amount to deposit in account:"<<endl;
cin>>amt;
balance +=amt;
cout<<" the final amount in the account is : "<<balance<<endl;
}

void withdraw()
{
int amt;
cout<<"Enter amout to be withdrawed from the account"<<endl;
cin>>amt;
if(amt<=balance)
{
balance-=amt;
cout<<"Remaining balance in the account is :"<<balance<<endl;
}
else
{
cout<<"Insuffienct balance"<<endl;
exit(0);
}
}
void display()
{
cout<<"Name of the customer:"<<customer_name<<endl;

cout<<"balance in your account: "<<balance<<endl;
}
void choice(){
    cout<<" \nEnter '1' to display information\n Enter '2' to deposit amount in your account\n Enter '3' to withdraw amount from your account\n  Enter '4' to exit\n" ;


}
};

int main()
{
int i;

bank b;
b.initialize();

while(i!=4){
    b.choice();


cin>>i;
if(i==1){b.display();}
else if (i==2){b.deposit();}
else if(i==3){b.withdraw();}
else if(i==4){break;}

}

return 0;

}
