#include<iostream>
using namespace std;
string key[]={"","abc","def","ghi"};

void generateWords(char*inp,char*out,int i,int j){
	if(inp[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}

	//decide the char to which we map the digit at ith idx

	int d=(inp[i]-'0');
	string options=key[d];
	for(auto c_k: options){
		out[j]=c_k;
		generateWords(inp,out,i+1,j+1);
	}
}

int main(){
	char inp[]="213";	
	char out[10];
	generateWords(inp,out,0,0);
	return 0;
}