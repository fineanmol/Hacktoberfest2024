#include <stdio.h>
#include <math.h>
#include <conio.h>

int main(void) {
    int N;

    printf("Size of the population: ");
    scanf("%d", &N);

    float x[N], mean, sum = 0, SD;

    printf("Enter each value from the population\n");

    for (int i = 0; i < N; i++)
    {
        printf(": ");
        scanf("%f", &x[i]);
    }

    for (int i = 0; i < N; i++)
    {
        sum += x[i];
    }

    mean = sum / N;
    sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += (x[i] - mean) * (x[i] - mean);
    }

    SD =  sqrt(sum / N);

    printf("Standard Deviation = %0.03f", SD);

    getch();
}