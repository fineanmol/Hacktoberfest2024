//This algorithm is used to print all the subsequences of a string

#include<bits/stdc++.h>
using namespace std;

void printSubsequence(string str){

	int n = str.size();

	string sub = " ";

	for(int i=0;i<(1<<n);i++){

		sub = " ";

		for(int j=0;j<n;j++){

			if(i & (1 << j))
				sub += str[j];
		}

		cout<<i+1<<". "<<sub<<endl;
	}
}



int main(){

	//Additional code for input-output
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif


	string str;
	cin>>str;

	printSubsequence(str);

	return 0;
}