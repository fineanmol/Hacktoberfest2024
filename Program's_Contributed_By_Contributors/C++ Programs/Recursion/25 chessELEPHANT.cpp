#include<iostream>
using namespace std;
int countWays(int i, int j){
	if(i==0 && j==0){
		return 1;
	}

	int count =0;
	for(int k=1;k<=i;k++){
		count+= countWays(i-k,j);
	}

	for(int k=1;k<=j;k++){
		count+= countWays(i,j-k);
	}
	return count;
}


int main(){
	

	int  n=4;
	cout<< countWays(n-1,n-1);

	return 0;
}


// #include<iostream>

// using namespace std;

// int countWays(int i, int j) {

// 	// base case
// 	if(i == 0 and j == 0) {
// 		return 1;
// 	}

// 	// recursive case

// 	int c1 = 0;
// 	for(int k=1; k<=i; k++) {
// 		c1 += countWays(i-k, j);
// 	}

// 	int c2 = 0;
// 	for(int k=1; k<=j; k++) {
// 		c2 += countWays(i, j-k);
// 	}

// 	return c1+c2;



// }

// int main() {

// 	int n = 2;

// 	cout << countWays(n-1, n-1) << endl;

// 	return 0;
// }
