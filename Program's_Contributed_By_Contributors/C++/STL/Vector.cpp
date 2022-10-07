#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    cout<<"capacity "<<v.capacity()<<endl;

    // adding eleemnt 
    v.push_back(10);
    v.push_back(20);
    
    // printing vetor
    for(int i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"capacity "<<v.capacity()<<endl;
    cout<<"Size "<<v.size()<<endl;
    cout<<"element at index "<<v.at(1)<<endl;

    //clear size will zero only
     v.clear();
        



}