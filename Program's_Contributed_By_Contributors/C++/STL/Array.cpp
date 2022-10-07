#include<iostream>
#include<array>
using namespace std;
int main()
{
 array<int,4> a={1,2,3,4};
 
 int size=a.size();
 for(int i=0;i<size;i++){
    cout<<a[i];
 }

 cout<<"element at index "<<a.at(2)<<endl;
 cout<<"empty itor not "<<a.empty()<<endl;
//  also have fun back() and font()

}