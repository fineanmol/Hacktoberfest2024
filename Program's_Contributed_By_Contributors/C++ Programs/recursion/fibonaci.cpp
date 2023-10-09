// Fibonacci series using tail recursion
#include<iostream>

int fibonacci(int n)
{
    if(n== 0 || n==1)
    {
        return n;
    }
   else{
        return fibonacci(n-1)+ fibonacci(n-2);}

    }
int tail(int n,int a=0,int b=1){
    
	if (n == 0 || n == 1) {
		return b;
	}
	return tail(n - 1, b, a + b);
}
int main()
{
   
    std::cout<<" tail: recursion:"<<tail(6);;
  
    std::cout<<"\n normal: recursion:"<<fibonacci(6);;
   
  
}


