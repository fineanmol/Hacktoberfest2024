#include <iostream>

using namespace std;


void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
}



void intersection1(int a[],int b[],int m,int n)
{
    int i,j,k=0,flag;
    int c[30];
    
    for(i=0;i<n;i++)
    {
       for(j=0;j<m;j++)
       {
           
           if(b[i]==a[j])
            {
                c[k++]=b[i];
                break;
            }
       
       }
       
    }
    if(k==0)
        cout<<"No common element";
    
    display(c,k);
}


int main()
{
	int a[20],b[20],n,i,m;
	cout<<"enter size of 1st and 2nd array\t";
	cin>>m>>n;
	cout<<"enter element in 1st array\t";
	for(i=0;i<m;i++)
	{
		cin>>a[i];
	}
	cout<<"enter element in 2nd array\t";
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	
	intersection1(a,b,m,n);

	return 0;
}
