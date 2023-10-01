#include <iostream>
#include <cstdlib>
using namespace std;

int quick_sort(int a[],int LB,int UB){
    if (LB<UB){
        int pivot,t,i,j,key,flag;
        pivot = rand()%(UB-LB+1);
        t = a[LB];
        a[LB] = a[pivot];
        a[pivot] = t;
        i = LB;
        j = UB+1;
        key = a[i];
        flag = 0;
        while (flag==0){
            i = i+1;
            while (a[i]<key){
                i=i+1;
            }
            j = j-1;
            while (a[j]>key){
                j=j-1;
            }
            if (i<j){
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            else{
                flag = 1;
            }
        }
        t = a[LB];
        a[LB] = a[j];
        a[j] = t;
        quick_sort(a,LB,j-1);
        quick_sort(a,j+1,UB);
    }
    return 0;
}
int main(){
    int n,i;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements : "<<endl;
    for (i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for (i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}