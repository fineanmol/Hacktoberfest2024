#include <stdio.h>
int main() {
    int num, originalNum, remainder, result = 0;
    printf("Enter a three-digit integer: ");
    scanf("%d", &num);
    originalNum = num;

    for (int i=1;i<=3;i++) {
       // remainder contains the last digit
        remainder = originalNum % 10;
        
       result = result + (remainder * remainder * remainder);
        
       // removing last digit from the orignal number
       originalNum =originalNum/10;
    }

    if (result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);

    return 0;
}
