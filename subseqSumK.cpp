#include<bits/stdc++.h>

using namespace std;


bool sumSubseq(int i,int arr[],int n,int sum,vector<int>&ds,int s){


    if(i==n)
    {
        //if condition satisfy return true
        if(s==sum){
            for(auto it:ds) cout<<it<<" ";
            
            cout<<endl;
            return true;
          }
    //condition not satisfy continue
    return false;
    }

        ds.push_back(arr[i]);
        s+=arr[i];

        if(sumSubseq(i+1,arr,n,sum,ds,s)==true) return true;

        ds.pop_back();
        s-=arr[i];

        if(sumSubseq(i+1,arr,n,sum,ds,s)==true) return true;

        return false;
    

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum;
    cin>>sum;

    vector<int>ds;
    sumSubseq(0,arr,n,sum,ds,0);
    
    return 0;
}