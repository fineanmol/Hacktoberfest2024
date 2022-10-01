#include<bits/stdc++.h>
using namespace std; 

int main(){

/*
Maps are data types to store key value pairs, more like python dictionaries, normal maps store these as an order of keys
for eg:
lets store
1 --- abc
5 --- cde
3 --- acd

now if we store them in normal map theyll be stored like
1 -- ...
3 -- ...
5 -- ...

They work on the concept of Red Black Tree

Yaha iterator me ++i karte hai


//Declaring a map
map<int,string> m;
m[1]="abc";
m[5]="csc";
m[3]="acd";

//or another way is 
m.insert({4,"afg"});
//or 
m.insert(make_pair(5,"abc"));


//Iterator of Map

//Traditional Way
map<int,string> :: iterator it;
cout<<"printing with traditional way"<<endl;
for(it=m.begin();it!=m.end();++it) //++i hota hai not i++
{
    //cout<<(*it).first<<" "<<(*it).second<<endl;
    //Or in a more modern way is *it.first ==> it->first
    cout<<it->first<<" "<<it->second<<endl;
    //⚠️Observe all the keys are printed in sorted order
}

cout<<"printing with Swag way"<<endl;
for(auto &i : m) //& lagate hai taki copies na create ho
{
    cout<<i.first<<" "<<i.second<<endl;
}


cout<<"Finding in maps"<<endl;
//Finding in maps
auto iterator = m.find(4);
//m.find returns the iterator , of the key or else returns m.end()
if(iterator==m.end())
cout<<"Value Not Found"<<endl;
else
cout<<iterator->first<<" "<<iterator->second<<endl;

m.erase(5); //it erases the key or the key value pair the iterator points to in the parameter


A question on maps
Print the strings in lexographical order and also print the frequency of each string
*/
map<string,int> str;
int n;
cin>>n;
for (int i = 0; i < n; ++i)
{
    string temp;
    cin>>temp;
    str[temp]++;
}
cout<<"The strings and their frequency are"<<endl;
for(auto &itr : str)
{
    cout<<itr.first<<" "<<itr.second<<endl;
}

}