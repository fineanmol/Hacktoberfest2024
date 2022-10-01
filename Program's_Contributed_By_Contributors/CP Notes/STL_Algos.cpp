#include<bits/stdc++.h>
using namespace std; 

int main(){
/*
These are some popular algorithms that can make your life easy all have the same pattern of usage ie name of the func.
(lower lim, upper lim+1)
*/

vector<int> v= {1,4,2,5,6,3,9,0,10,3,15,17,3};
//To find the minimum element in the array, it returns the pointer/iterator
auto min = min_element(v.begin(),v.end());
cout<<"Min element: "<<*min<<endl;

//Max element
auto max = max_element(v.begin(),v.end());
cout<<"Max Element: "<<*max<<endl;

//Sum of all elements, the third parameter tells us initial sum ki value kya hai.
auto sum = accumulate(v.begin(),v.end(),0);
cout<<"The sum of all elements: "<<sum<<endl;

//Count the frequency of an element in the array/vector
auto cnt = count(v.begin(),v.end(),3);
cout<<"Frequency Of 3 is: "<<cnt<<endl;

//Finds an element and returns its pointer
auto elem = find(v.begin(),v.end(),3);
if(elem!=v.end())
    cout<<"the element is at posn: "<< *elem <<endl;
else
cout<<"Element not found"<<endl;

//🔥Reverse a string or array/vector
reverse(v.begin(),v.end());
cout<<"Reversed Vector: ";
for(auto val:v)
{
    cout<<val<<" ";
}

}