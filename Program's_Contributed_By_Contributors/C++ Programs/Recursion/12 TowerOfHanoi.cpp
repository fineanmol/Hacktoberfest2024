#include<iostream>
using namespace std;
void toh(int n, char src, char hlp, char dest){
	//base case
	if(n==0)
		return;
	int count=1;

	//ask your friend move (n-1) disk from src to help using destn
	toh(n-1,src,dest,hlp);

	// move largest disk from src to destn
	cout<<count<<"Move from "<< src<<" to "<<dest<<endl;
	count++;
	//ask your friend to move (n-1) disk from help to destn
	toh(n-1,hlp,src,dest);
}
int main(){
	int n=3;
	toh(n, 'A' ,'B' , 'C');
	return 0;
}