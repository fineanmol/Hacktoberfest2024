#include<iostream>
#include<list>
using namespace std;
int main()
{
    //liSt do not direct access
     list<int> l;
     l.push_back(1);
     l.push_back(12);

     for(int i:l){
       cout <<i<<" ";
     }
      cout<<endl;
      cout<<"Size of list "<<l.size()<<endl;
}