#include<iostream>
using namespace std;

int main()
{
    string str,st="",sa="";
    cout<<"Enter Line of String ";
    getline(cin,str);
    int i,largest=0;
    int l=str.length();
    for(i=0;i<l;i++){
        if(str[i]==' '){
            if(largest<sa.length()){
                largest=sa.length();
                st=sa;
            }
            sa="";
        }
        else{
            sa+=str[i];
        }
    }
    if(largest<sa.length()){
        largest=sa.length();
        st=sa;
    }
    cout<<"Largest Word Length = "<<largest<<endl;
    cout<<"Word = "<<st;
}
