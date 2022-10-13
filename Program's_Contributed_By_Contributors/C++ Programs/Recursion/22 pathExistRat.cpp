#include<iostream>
using namespace std;
bool IspathExist(char maze[][10],int i,int j){
	
	if(i==0 && j==0){
		return true; // return 1 mean its a path
	}
	if(i<0 || j<0){
		return false;
	}
	if(maze[i][j]=='x'){
		return false;
	}
	 return IspathExist(maze,i-1,j) || IspathExist(maze,i,j-1);

}
int main(){
	char maze[][10]={"0000",
					 "00x0",
					 "000x",
					 "0x00"};
	int m=4;
	int n=4;
	IspathExist(maze,m-1,n-1)?cout<<"true":cout<<"false";
	return 0;
}