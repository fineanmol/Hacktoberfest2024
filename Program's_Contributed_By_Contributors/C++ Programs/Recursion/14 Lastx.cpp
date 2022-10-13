#include<iostream>
using namespace std;
string move(string s){
	if(s == ""){
		return s; // empty string not have any character so we return empty string
	}
	
	//1. extract the substring starts from 1st indx
	string substring=s.substr(1);

	//2. ask your friend to move all 'x' char in substring to the end 
	string ans=move(substring);

	//3. extract char at 0th index 

	if(s[0]=='x'){ // s.substr(0,1)=="x"
		return ans+s[0]; 
	}
	else{
		return s[0]+ans;
	}
}

int main(){
	string str="axbxcxxd";
	cout<<move(str);	
	return 0;
}