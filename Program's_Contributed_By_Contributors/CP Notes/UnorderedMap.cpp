#include<bits/stdc++.h>
using namespace std; 

int main(){
/*
The only difference between ordered and unordered map is that unordered maps are really fast having coz they use the 
concept of hashing, but this comes at the cost of limited use with complex ds

⚠️Always use unordered maps when order isnt important

Eg: Given N strings and Q queries, print the frequency of strings present in the query
*/

//See that the answer is printed based on the query asked hence, order isnt necessary

//declarartion of unordered map
unordered_map<string,int> m;
int n,q;
cin>>n;
for (int i = 0; i < n; i++)
{
    string temp;
    cin>>temp;
    m[temp]++;
}
cin>>q;
while(q--)
{
    string str;
    cin>>str;
    auto freq = m.find(str);
    cout<<freq->second<<endl;
}

}