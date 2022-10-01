#include<bits/stdc++.h>
using namespace std; 

int main(){
/*
Sets is like array and maps just it store everything automatically in sorted order.
Maps store key and value , remove the value wala part, you'll be having only keys
Three types of sets, Normal or ordered, Unordered And MultiSets
*/

//Declaration, Stores unique elements in sorted order
set<string> s;

//Inserting elements in set
s.insert("abc"); 
s.insert("xyz"); //O(logn)

//Accessing value in sets
auto it = s.find("abc"); //Returns iterator
if(it!=s.end())
{
    //do your calculation, but youve to check it always otherwise if the element is
    //not found it will give segmentatino fault.
}


for(auto value : s)
{
    cout<<value<<endl;
}
//unordered sets, has most of its functions like find and insert in o(1), hence, its
//recommended to use unordered sets in questins where we just need to find if an element
//is present or not

//Multiset are the best coz they not only sort by default but also allows duplicate value
multiset<string> ms;
}