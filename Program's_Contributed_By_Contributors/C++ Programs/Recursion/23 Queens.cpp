// place n queensin (n * n) chess board so that no queen attack each other

#include<iostream>
using namespace std;

void nQueen(int n, int r, int* pos){
	// base case
	if(r == n) { // you've placed all the 'n' queens
		// for(int i=0;i<n;i++){
		// 	cout<<pos[i]<<" ";  // columns get print of each row j with jth queen
		// }
		// cout<<endl;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(pos[i]==j){
					cout<<" Q ";
				}
				else{
					cout<< " - ";
				}
			}
			cout<<endl;
		}
		cout<<endl;


		return;
	}
	
	// recursive case

	// you have to make a decision that at which col of row 'r' 
	// we have to place queen 'Qr'

	// in general you can place Qr in the jth column of row 'r'
	// where 0<=j<n if and only if upon  place Qr in jth col of
	// row 'r' it doesn't attack any previously place queen Qi
	// where 0<=i<r ;

	for(int j=0;j<n;j++){
		bool canPlace=true;
		for(int i=0;i<r;i++){
			if(pos[i]==j || pos[i]==j-(r-i) || pos[i]==j+(r-i)){
				canPlace=false;
				break;
			}
		}


		if(canPlace){
			pos[r]=j;
			nQueen(n, r+1, pos);
		}
	}
}

int main(){
	int n=4;// chess board
	int pos[10]; 
	nQueen(n,0,pos);
	return 0;
}