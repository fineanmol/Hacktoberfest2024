//Josephus problem

#include <bits/stdc++.h>
using namespace std;

void solve(int k, vector<int> v, int start){
	if(v.size()==1){
		cout<<v[0]<<"\n";
	}
	else{
		start += k;
		int s = v.size();
		start = start%s;
		v.erase(v.begin()+start);
		solve(k, v, start);
		return;
	}
}

int main(){
	int n = 5;
	int k = 2;
	k--;
	vector<int> v;
	for(int i=0; i<n; i++){
		v.push_back(i+1);
	}
	solve(k, v, 0);
	return 0;
}