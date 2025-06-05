#include<iostream>
using namespace std;
// typedef struct employee{
//     //data 
//     int eid;
//     char favchar;
//     float salary;
// }ep;
// type def ka use karke struct employee ko short me likh sakte hai . ep for example .

/********  union ******/
// union money{
//     int rice ;
//     char car;
//     float pounds;
// };

int main(){
    // struct employee pankaj;
    // ep shubham;
    
   
    //     pankaj.eid = 28;
    //     pankaj.favchar ='p';
    //     pankaj.salary = 120000000;
  
    // cout<<"pankaj salary "<<pankaj.salary<<endl;
    // cout<<"this is shubham details "<<endl;
    // shubham.eid=45;
    // shubham.favchar='s';
    // shubham.salary=5000000000;
    // cout<<"shubham salary "<<shubham.salary;

// union 
//  union money m1;
//  m1.rice = 34;
//  m1.car = 'a';
//  m1.pounds = 3.4;
 
//  cout<<m1.pounds;


/*************************** ENUM ***********************************/
enum meal {breakfast, lunch , dinnner};
meal m1 = dinnner;
cout<<m1;
}

// ok i understand  all three things .