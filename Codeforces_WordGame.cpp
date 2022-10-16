// https://codeforces.com/contest/1722/problem/C

#include <bits/stdc++.h>
#include <map>
#include <iterator>
using namespace std;

int main() {
int t;
cin>>t;
while(t--){
        int n;
        cin>>n;
        map<string,int>mp;
        vector<vector<string>>v;
        // vector of vector
        for(int i=0;i<3;i++){
                vector <string> s;
                for(int j=0;j<n;j++){
                        string ss;
                        cin>>ss;
                        mp[ss]++;
                        s.push_back(ss);

                }
                v.push_back(s);

        }
        vector<int>v1(3,0);
        for(int i=0;i<3;i++){
                for(int j=0;j<n;j++){
                        if(mp[v[i][j]]==1) v1[i]=v1[i]+3;
                        else if(mp[v[i][j]]==2) v1[i]=v1[i]+1;
                }
        }
        for(int i=0;i<3;i++){
                cout<<v1[i]<<" ";
        }
        cout<<endl;

}
}