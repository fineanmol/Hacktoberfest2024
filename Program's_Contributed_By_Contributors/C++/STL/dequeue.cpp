#include<iostream>
#include<deque>
using  namespace std;
int main()
{
    deque<int> d;
    d.push_back(12);
    d.push_front(21);
    for(int i:d){
        cout<<i<<" ";    
    }

    cout<<endl;
    cout<<"print firste index element "<<d.at(1)<<endl;

    // simmilary it have pop_front and pop_back()
    cout<<"empty or not "<<d.empty()<<endl;

    //dection  0 index element 
    d.erase(d.begin(),d.begin()+1);


}