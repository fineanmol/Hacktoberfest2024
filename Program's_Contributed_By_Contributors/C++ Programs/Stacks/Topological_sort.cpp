#include <iostream>
using namespace std;
int indegree[10];
void find_indegree(int a[10][10],int n)
{
for (int j=0;j<n;j++)
{
int sum=0;
for ( int i=0;i<n;i++)
sum=sum+a[i][j];
indegree[j]=sum;
}
}
void topological_sort(int a[10][10],int n)
{
int u,v,t[10];
int s[10],top=-1;// Stack
find_indegree(a,n);// find indegree of each node
int k=0;
for ( int i=0; i<n;i++)
{
if (indegree[i]==0)
s[++top]=i;
}
while (top!=-1)
{
u=s[top--];//Remove the node having zero indegree
t[k++]=u;//store the popped( deleted ) node in solution vector array t
for (v=0;v<n;v++)
{
if (a[u][v]==1)
{
indegree[v]--;// remove the edge originating from u to v
if (indegree[v]==0)
s[++top]=v;
}
}
}
cout<<"The topological sequence is :\n";
for (int i=0;i<n;i++)
cout<<t[i]<<" ";
}
int main()
{
int n;
int a[10][10];
cout<<"Enter the number of nodes\n";
cin>>n;
cout<<"Enter the adjacency matrix row wise\n ";

for (int i=0; i<n; i++)
for ( int j=0; j<n; j++)
cin>>a[i][j];
topological_sort(a,n);
return 0;
}
