#include<bits/stdc++.h>
using namespace std;
int count1=0;
class edge
{
	public:	int src,dest,cost;
	edge(){}
	edge(int s,int d,int c):src(s),dest(d),cost(c){}
};
bool operator < (const edge e1 , const edge e2)
	{
		return ((-1)*e1.cost)<((-1)*e2.cost);
	}
	
int findset(int a[],int e)
{
	while(a[e]!=-1)
	{
		e=a[e];
	}
	return e;
}
void set_union(int a[],int p,int q)
{
	a[p]=q;
}
int main()
{
	priority_queue<edge>q;
	int v,e;
	e=28; 
	v=9;
	int s[v];
		cout<<"ENTER SRC,DEST,COST\n";
	for(int i=0;i<v;i++)s[i]=-1;
/*	for(int i=0;i<e;i++)
	{
	
		int s,d,c;
		cin>>s>>d>>c;
		edge e(s,d,c);
		q.push(e);		
	}*/
		int src[] = {0, 1, 0, 7, 1, 2, 1, 7, 2, 3, 2, 5, 2, 8, 3, 4, 3, 5, 4, 5, 5, 6, 6, 7, 6, 8, 7, 8};
	int d[] = {1, 0, 7, 0, 2, 1, 7, 1, 3, 2, 5, 2, 8, 2, 4, 3, 5, 3, 5, 4, 6, 5, 7, 6, 8, 6, 8, 7};
	int c[] = {4, 4, 8, 8, 8, 8, 11, 11, 7, 7, 4, 4, 2, 2, 9, 9, 14, 14, 10, 10, 2, 2, 1, 1, 6, 6, 7, 7};
	
	//Edge *input = new Edge[E];
	for(int i = 0;i<e;i++){
       edge e(src[i],d[i],c[i]);
       q.push(e);
	}
	vector<edge>res;
	int mincost=0;
	int cur=0;
	edge *output = new edge[e];
	while(!q.empty() && cur<v-1)
	{	
		edge e=q.top();
		q.pop();
		int sr=findset(s,e.src);
		int d=findset(s,e.dest);
		if(sr!=d)
		{   output[cur] = e;
		    count1++;
			cur++;
			mincost+=e.cost;
			set_union(s,sr,d);
			res.push_back(e);
		}
		
	}
	
		cout << "Input to be used : " << endl;
    cout << "Number of vertices: "<<v<<endl<<"Edges: ";
    

		for(int i=0; i < v-1; i++){
		if(output[i].src < output[i].dest)
		  
			cout<<output[i].src<<"-"<<output[i].dest<<", ";
		else
		
			cout<<output[i].dest<<"-"<<output[i].src<<", ";
	
	}

	cout<<endl<<"No. of steps = "<<count1;

}
