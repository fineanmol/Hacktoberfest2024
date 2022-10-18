#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    char input[10];
    long v1[10];
    long v2[10];

    printf("Enter a number 10 times.\n");

    for(int i = 0; i < 10; i++ ) {
        fgets(input, 10, stdin);
        v1[i] = strtol(input, NULL, 10);
    }

    for(int i = 0; i < 10; i++) {
        long sum = 0;
        for(int j = i; j < 10; j++){
            sum += v1[j];
        }
        v2[i] = sum;
        printf("v2[%d] = %ld\n", i, v2[i]);
    }

    return 0;
}