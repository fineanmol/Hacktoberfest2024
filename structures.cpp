#include<iostream>
using namespace std;

union employee{
    int id;
    char fav_char;
    float salary;
}Rohan,Sohan,Ram,Shyam;

int main(){

    
    
    Rohan.salary=2000000;
    Rohan.id=1;
Rohan.fav_char='A';
        
    Sohan.salary=3000000;
Sohan.id=2;
Sohan.fav_char='B';
    
    Ram.salary=4000000;
  Ram.id=3;
  Ram.fav_char='C';
        
    Shyam.salary=5000000;
    Shyam.id=4;
Shyam.fav_char='D';

    cout<<"Printing Details of Rohan"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Rohan's Id: "<<Rohan.id<<endl;
    cout<<"Rohan's Favourite Character: "<<Rohan.fav_char<<endl;
    // // cout<<"Rohan's Salary: "<<Rohan.salary<<endl<<endl;

     cout<<"Printing Details of Sohan"<<endl;
     cout<<"-------------------------------------------------------------------------"<<endl;
     cout<<"Sohan's Id: "<<Sohan.id<<endl;
     cout<<"Sohan's Favourite Character: "<<Sohan.fav_char<<endl;
    // // cout<<"Sohan's Salary: "<<Sohan.salary<<endl<<endl;

     cout<<"Printing Details of Ram"<<endl;
     cout<<"-------------------------------------------------------------------------"<<endl;
     cout<<"Ram's Id: "<<Ram.id<<endl;
    cout<<"Ram's Favourite Character: "<<Ram.fav_char<<endl;
    // // cout<<"Ram's Salary: "<<Ram.salary<<endl<<endl;

    cout<<"Printing Details of Shyam"<<endl;
     cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Shyam's Id: "<<Shyam.id<<endl;
     cout<<"Shyam's Favourite Character: "<<Shyam.fav_char<<endl;
    // // cout<<"Shyam's Salary: "<<Shyam.salary<<endl<<endl;


    
    return 0; 
}
