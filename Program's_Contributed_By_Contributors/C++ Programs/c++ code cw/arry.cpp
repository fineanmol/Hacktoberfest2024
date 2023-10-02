#include <iostream>
using namespace std;

int main(){
    /// array 

    // int mark[] = {4, 43 ,53,63 };
    // cout<<"These are marks "<<endl;
    // cout<<mark[0]<<endl;
    // cout<<mark[3]<<endl;

    // another one method for declair arrays

    // int marks[4] ;
    //  marks[0] = 575;
    //  marks[1] = 65;
    //  marks[2] = 55;
    //  marks[3] = 98;
     
       
    // cout<<"These are tractor model names "<<endl;
    // marks[2]= 455;
    // cout<<marks[0]<<endl;
    //             // print hone se pahle change karna hai .
    // cout<<marks[1]<<endl;
    // cout<<marks[2]<<endl;

   // loops ki madat se bhi hum array me vlue daal sakte hai 

    
    // for (int i = 0; i < 4 ; i++)
    // {
    //     cout<<marks[i]<<endl;
    // }

    // pointer and arrays 

    // int *p = marks;
    // cout<<marks[0]<<endl;
    // cout<<*p<<endl;
    // cout<<*(p+1)<<endl;
    // cout<<*(p+2)<<endl;
    // cout<<*(p+3)<<endl;
    


    int marks[]={45,55,77,88,90};
    // cout<<"these are marks "<<endl;
    // cout<<marks[0]<<endl;
    // cout<<marks[1]<<endl;
    // cout<<marks[2]<<endl;
    // cout<<marks[3]<<endl;
    // cout<<marks[4]<<endl;

// int mathmarks[6];
// mathmarks[0]=98;
// mathmarks[1]=97;
// mathmarks[2]=546;
// mathmarks[3]=45;
// mathmarks[4]=56;
// mathmarks[5]=456;
// mathmarks[2]=540;
// cout<<"these are mathmarks "<<endl;
// cout<<mathmarks[0]<<endl;
// cout<<mathmarks[1]<<endl;
// cout<<mathmarks[2]<<endl;
// cout<<mathmarks[3]<<endl;
// cout<<mathmarks[4]<<endl;
// cout<<mathmarks[5]<<endl;

// cout<<"print marks with the help of loop "<<endl;
// for (int  i = 0; i <=6; i++)
// {
//     cout<<"these are mathmatics marks "<<i<<" = "<<mathmarks[i]<<endl;
// }

// int i=0;
// while(i<=6){
//     cout<<"these are mathmatics marks "<<i<<" = "<<mathmarks[i]<<endl;
//     i++;
// }
// int i=0;
// do
// {
//    cout<<"these are mathmatics marks "<<i<<" = "<<mathmarks[i]<<endl;
//    i++;
// } while (i<=6);


// pointer and arrays 
int* p = marks;
cout<<"The value of *p is "<<*p<<endl;
cout<<"The value of *(p+1) is "<<*(p+1)<<endl;
cout<<"The value of *(p+2 is "<<*(p+2)<<endl;
cout<<"The value of *(p+3) is "<<*(p+3)<<endl;
cout<<"The value of *(p+4) is "<<*(p+4)<<endl;
    return 0;
}