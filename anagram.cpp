#include<iostream>
using namespace std;
void sort(char s1[]){
    int i,j,n,temp;
    n=strlen(s1);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s1[i]>s1[j]){
                temp=s1[i];
                s1[i]=s1[j];
                s1[j]=temp;
            }
        }
    }
}
int main(){
    char s1[100],s2[100];
    cin>>s1;
    cin>>s2;
    sort(s1);
    sort(s2);
    if(strcmp(s1,s2)==0){
        cout<<"Anagram";
    }
    else{
        cout<<"Not Anagram";
    }
}