#include<bits/stdc++.h>
using namespace std;
class method{
public:
    double hour;
    double minutes;
    double seconds;

    method(){
    cout<<"Enter the time hour" <<endl;
    cin>> hour ;
    cout<<"Enter the time minutes"<<endl;
    cin>> minutes ;
    cout<<"Enter the time seconds"<<endl;
    cin>>seconds ;
};
int sec(){
double sum = hour*3600+minutes*60+seconds;
cout<< "Given time by you "<<endl;
cout<<hour<<":"<<minutes<<":"<<seconds <<endl;
cout<<"After change into seconds"<<endl;
cout<<sum<<endl;
};
int minu(){
double sum = hour*60+minutes+seconds/60;
cout<< "Given time by you "<<endl;
cout<<hour<<":"<<minutes<<":"<<seconds <<endl;
cout<<"After change into minutes"<<endl;
cout<<sum<<endl;
};
int hou(){
double sum = hour+minutes/60+seconds/3600;
cout<< "Given time by you "<<endl;
cout<<hour<<":"<<minutes<<":"<<seconds <<endl;
cout<<"After change into hours"<<endl;
cout<<sum<<endl;
};
};
int main(){

method mo;
mo.sec();
mo.minu();
mo.hou();
return 0;
}
