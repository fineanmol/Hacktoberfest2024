#include<stdio.h>
int main()
{
    char ch;
    printf("Enter any character:");

    scanf("%c", &ch);

    printf("ASCII value of character %c is: %d", ch, ch);
    return 0;
}
