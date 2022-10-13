#include<iostream>
#include<set>
using namespace std;

void generateSubseq(char* inp, char*out,int i,int j, set<string>&s){
	//base
	if(inp[i]=='\0'){
		out[j]='\0';
		s.insert(string(out));
		//cout<<out<<endl;
		return;
	}

	//recursive 
	// make the decsion for char at the ith idx

	//1. include the char to the out subseq
	out[j]=inp[i];
	generateSubseq(inp,out,i+1,j+1,s);
	//2. exclude the char to the out subseq
	generateSubseq(inp,out,i+1,j,s);

}

int main(){
	
	char inp[]="abc";
	char out[10];
	set<string>s;

	generateSubseq(inp,out,0,0,s);

	for(auto val:s){
		cout<<val<<endl;
	}

	return 0;
}