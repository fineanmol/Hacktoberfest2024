#include <iostream>
using namespace std;

int main(){
    int n,m,i,j,max,t,flag;
    int profit=0;
    cout<<"Enter the number of items : ";
    cin>>n;
    int p[n],w[n],order[n];
    double v[n];
    for (i=0;i<n;i++){
        cout<<"Enter the profit : ";
        cin>>p[i];
        cout<<"Enter the weight : ";
        cin>>w[i];
        v[i] = double(p[i])/w[i];
        order[i] = i;
    }
    cout<<"Enter the weight of the knapsack : ";
    cin>>m;
    for (i=0;i<n;i++){
        max = i;
        for (j=i+1;j<n;j++){
            if (v[j]>v[max]){
                max = j;
            }
        }
        t = order[i];
        order[i] = max;
        order[max] = i;
    }
    for (i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    flag = 1;
    i = 0;
    while (flag==1){
        if ((m>0)&&(m>=w[order[i]])){
            m = m-w[order[i]];
            profit = profit + p[order[i]];
            i = i+1;
        }
        else{
            profit = profit + v[order[i]]*m;
            flag = 0;
        }
    }
    cout<<"The maximum profit is : "<<profit<<endl;
    return(0);
}