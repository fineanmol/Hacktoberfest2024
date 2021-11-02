#include<bits/stdc++.h>
using namespace std;



void rotate(int a[][100] , int  n){
	//to reverse an array
	for(int row = 0 ; row< n ; row++){
		int start_col = 0;
		int end_col = n-1;
		while(start_col<end_col){
			swap(a[row][start_col],a[row][end_col]);
			start_col++;
			end_col--;
		}
		cout<<"\n";
	}
	
	//transpose
		for( int i = 0 ; i< n; i++){
		for( int j = 0 ; j< n ; j++){
		if(i<j){
			swap(a[i][j],a[j][i]);
	}
		}
		cout<<"\n";
	}
}

void display(int a[][100], int n){

	
	for( int i = 0 ; i< n; i++){
		for( int j = 0 ; j< n ; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}



int main(){
	int  n;
	cin>>n;
	int a[100][100]={0};

	
	for( int i = 0 ; i< n; i++){
		for( int j = 0 ; j< n ; j++){
			cin>>a[i][j];
		}
	}
	rotate(a,n);
	display(a,n);
	return 0 ;
}
