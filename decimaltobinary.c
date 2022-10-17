#include <stdio.h>
#include <math.h>
#include <conio.h>

int convertToBinary(int);

int main(void)
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);    

    printf("Binary :%d\nPress any key", convertToBinary(number));
    
    getch(); 

    return 0;
}

int convertToBinary(int dec)
{
    int bin = 0;

    for (int i = 0; dec != 0; i++)
    {
        bin += (dec % 2) * pow(10, i);
        dec /= 2;
    }

    return bin;
}