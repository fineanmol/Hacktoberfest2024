
#include <bits/stdc++.h>
using namespace std;
#define N 101

int ar[N][N], I[N][N];

void mul(int A[][N], int B[][N], int dim)
{
    int res[dim][dim];
    for(int i=0; i<dim; i++)
    {
        for(int j=0; j<dim; j++)
        {
            res[i][j]=0;
            for(int k=0; k<dim; k++)
            {
                res[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    for(int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            A[i][j]=res[i][j];
        }
    }
}

void power(int a[][N], int dim, int n)//a[][N] is important  
{
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            if (i==j) I[i][j]=1;
            else      I[i][j]=0;
        }
    }
    while(n)
    {
        if (n%2)
        {
            mul(I,a, dim), n--;
        }
        else
        {
            mul(a,a, dim);
            n/=2;
        }
    }
    for (int i=0; i<dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            a[i][j]=I[i][j];
        }
    }
}

void printmat(int a[][N],int dim)
{
    for (int i=0; i<dim; i++)
    {
        for(int j=0; j<dim; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    } 
}
int main()
{
    int t, dim, n;
    cin>>t;
    while(t--)
    {
        cin>>dim>>n;
        for (int i=0; i<dim; i++)
        {
            for (int j=0; j<dim; j++)
            {
                cin>>ar[i][j];
            }
        }
        power(ar, dim, n);
        printmat(ar, dim);
    }   
    return 0;
}