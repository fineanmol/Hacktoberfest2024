#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long pisano(long long m) {
    long long i,x=0,y=1,z=x+y;
    for(i=0;i<m*m;i++){
        z=(x+y)%m;
        x=y;
        y=z;
        if(x==0 && y==1){
        	return (i+1);
		}
	}
}
long long fibonacci_sum_fast(long long n, long long m){
	long long i,F[n];
	long long sum=0;
    F[0]=0;
    F[1]=1;
    if (n <= 1)
        return n;
	for(i=2;i<=n;i++){
		F[i]=(F[i-1]+F[i-2])%10;
		sum=(sum+F[i])%10;
	}
    return (sum+1)%10;
}

int main() {
    long long n = 0;
    int m=10;
    std::cin >> n;
    int c=pisano(m);
    std::cout << fibonacci_sum_fast(n%c,10);
}
