#include <bits/stdc++.h>
//#include <stdio.h>

using namespace std;

//find number of greater element from current no.
//number of greater elements would be total length - current index of number - (for non repetative)

int main(){
	int t = 0;
	cin >> t;
	while(t--){
		int size = 0;
		cin >> size ;
		int arr[size];
		for(int i=0;i<size;i++){
			cin >> arr[i];
		}
		for(int i = 0;i<size;i++){
			int count = 0;
			for(int j = i+1;j<size;j++){
				if(arr[i]<arr[j]){
					count++;
				}
			}
			arr[i] = count;
		}
		for(int k=0;k<size;k++){
			if(k == size - 1){
				cout << arr[k] << endl;
			}else{
				cout << arr[k] << " ";
			}
			
		}
	}
	return 0;
}

