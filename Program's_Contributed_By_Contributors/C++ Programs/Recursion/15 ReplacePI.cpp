#include<iostream>

using namespace std;

void replacePi(char* inp, int i){

	if(inp[i]=='\0')
		return;

	// recursive
	if(inp[i]=='p' && inp[i+1]=='i'){
		// 1. shift all char from (i+2)th idx to two steps right

		int j=i+2; //i+2 idx -> j
		
		while(inp[j] != '\0') // -> int j= strlen(inp); => also point to null 
			j++;
		

		while(j>=i+2){
			inp[j+2]=inp[j];
			j--;
		}

		// 2. Replace pi at (i,i+1) idx with 3.14
		inp[i]='3';
		inp[i+1]='.';
		inp[i+2]='1';
		inp[i+3]='4';

		// 3. ask your friend to replace all "pi" in substr
		//    that starts from (i+4)th idx

		replacePi(inp,i+4);
	}
	else{
		// 1. ask your friend to replace all "pi" in substr
		//    that starts from (i+1)th idx

		replacePi(inp,i+1);
	}
}

int main() {

	char inp[21]="ipip";

	replacePi(inp,0);

	cout<<inp;

	return 0;
}