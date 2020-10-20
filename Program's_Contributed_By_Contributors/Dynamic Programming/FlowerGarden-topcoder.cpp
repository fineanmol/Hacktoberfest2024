#include<bits/stdc++.h>
using namespace std;

//INCOMPLETE

int main(){

int height[1000];
int bloom[1000];
int wilt[1000];


int n;
cin>>n;

for(int i=0;i<n;i++)
{
    cin>>height[i];
}

for(int i=0;i<n;i++)
{
    cin>>bloom[i];
}

for(int i=0;i<n;i++)
{
    cin>>wilt[i];
}


vector<int> v;
bool placed[1000]=false;

int next_flower = 0;



for(int flowers = 0;i<n;i++){

int next_flower = some_unplaced_flower;

for(int i=0;i<n;i++){
    if(placed[i]==false&&height[i]>=height[next_flower] && ((bloom[i]<bloom[next_flower] && wilt[i]<bloom[next_flower])){
        next_flower = i;
        }
    }

}


return 0;
}


