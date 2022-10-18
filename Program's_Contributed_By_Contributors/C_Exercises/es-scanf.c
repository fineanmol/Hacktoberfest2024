#include <stdio.h>

// No error handling & no media
/* int main(void) {
    int input = 0;
    int somma = 0;

    do {
        scanf("%ud", &input);
        somma+= input;
    }
    while(input != 0);
    printf("La somma totale è %d", somma);
    
} */


// Error handling + media
int main(void) {
    int input = 0;
    int somma = 0;
    int result = scanf("%ud", &input);
    int nums = 0;

    while(result != EOF) {
        if(result) {
            if(input) {
                somma+= input;
                nums++;
                result = scanf("%ud", &input);
            } else {
                result = EOF;
            }
        } else {
            printf("Error\n");
            result = EOF;
        }
    }
    printf("Media: %1f Somma: %d\n", (float)somma/nums, somma);
}