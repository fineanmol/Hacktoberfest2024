#include<iostream>
using namespace std;
string digit[] = { "zero", "one ", "two ", "three ", "four ",
                 "five ", "six ", "seven ", "eight ",
                 "nine ", "ten "};
void spell(int n ){
	if(n == 0)
		return;

	int num=n%10;

	spell(n/10);
	cout<<digit[num];
}
int main(){
	int n=123;
	
    spell(n);
	
	return 0;
}