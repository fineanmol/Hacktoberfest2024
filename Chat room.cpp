#include<iostream>
using namespace std;
 
int main(){
	string s, str="hello";
	cin>>s;
	int j=0;
	for(int i=0; i<s.length(); i++){
		if(s[i]==str[j]){
			j++;
			if(j==5){
				cout<<"YES";	
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}
