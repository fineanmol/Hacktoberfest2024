#include <iostream>
using namespace std;

int n,set[100];
bool flag=false;

void find_subset(int i,int sum,bool subset[],int expected_sum){
    int j;
    if (sum>expected_sum){
        return;
    }
    if (i==n){
        if (sum==expected_sum){
            for(j=0;j<n;j++){
                cout<<subset[j]<<" ";
            }
            cout<<endl;
            flag = true;
        }
        return ;
    }
    subset[i] = true;
    find_subset(i+1,sum+set[i],subset,expected_sum);
    subset[i] = false;
    find_subset(i+1,sum,subset,expected_sum);
    return;
}

int main(){
    int expected_sum,i;
    cout<<"Enter the number of elements : ";
    cin>>n;
    bool subset[n];
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++){
        cin>>set[i];
        subset[i] = false;
    }
    cout<<"Enter the expected sum : ";
    cin>>expected_sum;
    find_subset(0,0,subset,expected_sum);
    if (!flag){
        cout<<"No subset found"<<endl;
    }
    return 0;
}