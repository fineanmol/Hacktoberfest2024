//to run gcc Binary.c -o test; ./test; rm test;

#include <stdio.h>
#include <stdlib.h>

void binaryConvertion(int pdecimal)
{
    int *binary = (int *)calloc(8, sizeof(int));

    for (int i = 8; i != 0; i--)
    {
        int result = pdecimal % 2;
        pdecimal = pdecimal / 2;
        binary[i] = result;
    }

    for (int i = 1; i != sizeof(binary) + 1; i++)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main()
{
    int *pdecimal = (int *)malloc(sizeof(int));
    int binary = 254;//change me
    if (binary < 255)
    {
        pdecimal = &binary;
        binaryConvertion(*pdecimal);
    }
    else
    {
        printf("Please nenter a number between 1 - 255. So we don't jump the 8 bit limit.");
    }
    return 0;
}