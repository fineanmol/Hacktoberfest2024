#include<iostream>
using namespace std;
int countpath(char maze[][10],int i,int j){
	
	if(i==0 && j==0){
		return 1; // return 1 mean its a path
	}
	if(i<0 || j<0){
		return 0;
	}
	if(maze[i][j]=='x'){
		return 0;
	}
	 return countpath(maze,i-1,j)+countpath(maze,i,j-1);

}
int main(){
	char maze[][10]={"0000",
					 "00x0",
					 "000x",
					 "0x00"};
	int m=4;
	int n=4;
	cout<<countpath(maze,m-1,n-1);
	return 0;
}