/*Program to reverse the elements of array*/

#include<iostream>
using namespace std;
int main(){
    int n,temp;
    cout<<"Enter the size of array:";
    cin>>n;
    int array[n];
    cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0,j=n-1;i<n/2;i++,j--){
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
cout<<"Reversed elements of array is:";
    
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}
