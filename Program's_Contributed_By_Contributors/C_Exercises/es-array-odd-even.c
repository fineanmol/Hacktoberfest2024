#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char input[10];
    long numbers[7];

    printf("Enter a number 7 times.\n");

    for(int i = 0; i < 7; i++ ) {
        fgets(input, 10, stdin);
        numbers[i] = strtol(input, NULL, 10);
    }

    // Print odd indexes
    for(int i = 0; i < 7; i+=2) {
        printf("%ld", numbers[i]);
    }
    // Print even indexes
    for(int i = 1; i < 7; i+=2) {
        printf("%ld", numbers[i]);
    }

    return 0;
}