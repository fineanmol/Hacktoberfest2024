#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
	
	int t;
	cin>>t;
	while(t--) {
		int flag = 0;
		
		ll d[100] ; ll a[100];
		int n;
		cin>>n;
		for(int i=0 ; i<n ; i++) {
			cin>>d[i];
		}
		
		a[0] = d[0];
		for(int i =1; i<n ; i++){
			if(d[i] == 0) a[i] = a[i-1];
			else if(a[i-1]  - d[i] >= 0 ){
				flag = 1;
				break;
			}
			else{
				a[i] = d[i] + a[i-1];
			}
		}
	
		if(flag == 0) {
			for(int i = 0 ; i< n ; i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		
		else if(flag == 1){
			cout<<-1<<endl;
		}	
	}
	return 0;
}