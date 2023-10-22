#include<iostream>
using namespace std;
int main(){
    char na[200],n[200];
    int i,j;
    cout<<"Enter Any String";
    cin>>na;
    cout<<"Enter Any String";
    cin>>n;
    for(i=0;na[i]!=NULL;i++);
    na[i]=' ';
    i++;
    for(j=0;n[j]!=NULL;j++,i++){
        na[i]=n[j];
    }
    //cout<<strlen(na)<<endl;
    //cout<<na<<endl;
    na[i]=NULL;
    //cout<<strlen(na)<<endl;
    cout<<na<<endl;
    
}