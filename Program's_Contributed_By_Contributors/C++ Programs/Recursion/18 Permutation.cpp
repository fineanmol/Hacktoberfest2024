#include<iostream>
#include<cstring>
using namespace std;
void generatePerm(char* inp,int i){

	if(inp[i]=='\0'){
		cout<<inp<<endl;
		return;
	}
	// you have to make decision which char is assigned to the i'th posn

	for(int j=i;j<strlen(inp);j++){
		//let us place char at jth idx to the ith posn
		swap(inp[i],inp[j]);
		//ask your friend to take decision starting from (i+1)idx
		generatePerm(inp,i+1);
		swap(inp[i],inp[j]); //back tracking
	}
}

int main(){
	
	char inp[]="abc";
	generatePerm(inp,0);	
	return 0;
}