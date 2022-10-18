#include <stdio.h>
#include <stdlib.h>


int * fibo(int n); // fibonacci sequence returns an array
int main(void) {
    int n;
    printf("Enter a number for your fib sequence: ");
    scanf("%d", &n);

    if((n <= 0)) { 
        printf("Malloc a mammt, inserisci un numero maggiore di 0.\n...e possibilmente che non vada in overflow"); 
        exit(1);
        }

    int * fib = fibo(n);

    // print the sequence
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    return 0;

}


int * fibo(int n) {
    // Dynamically allocate memory based on the input size
    // for the returned int array
    int * fibo = malloc(n * sizeof(int));
    // Allocate n * intBytes for the sequence

    // Fixate the first two entries of the sequence
    // as they are constant and start the loop at 2.
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo;
}