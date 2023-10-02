#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> A = {1,2,3,4,4,5,7,8};
	int s1=0,s2=0;
	for(int i=0;i<A.size();i++)
	{
		s1+=A[i]-(i+1);
		s2+=(A[i]*A[i])-(i+1)*(i+1);
	}
	s2 = s2/s1;
	int x = (s1+s2)/2;
	int y = (s2-s1)/2;
	cout<<x<<" "<<y<<endl;
	return 0;
}