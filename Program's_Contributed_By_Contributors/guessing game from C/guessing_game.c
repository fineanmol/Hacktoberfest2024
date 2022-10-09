#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printRandoms()
{

    int num = (rand() % (100));

    return num;
}

int main()
{
    srand(time(0));

    int x = printRandoms();
   
int guess=-1;
int count=0;
    while (guess != x)
    {
         
        scanf("%d", &guess);
        count++;
        if (guess < x)
        {
            printf("higher number please ");
        }
        else if (guess > x)
        {
            printf("lower nummber please  ");
        }
        else{
            printf("Yay!!! you guessed the number in %d attempts",count);

        }
    }
    
    return 0;
}
