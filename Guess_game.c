/*This is going to be fun!!  We will write a program that generates a random number and asks the player to guess it. If the player’s guess is higher than the actual number, the program displays “Lower number please.” Similarly, if the user’s guess is too low, the program prints “Higher number please.”

When the user guesses the correct number, the program displays the number of guesses the player used to arrive at the number.

Hints:

Use loops
Use a random number generator.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number,guess,nguess=1;
    srand(time(0));
    number=rand()%100 + 1;// Generates a random number between 1 and 100
    // printf("The number is %d\n", number);
    // Keep running the loop until the number is guessed
    do
    {
        printf("Guess the number between 1 to 100\n");
        scanf("%d",&guess);
        if (guess>number)
        {
            printf("Lower number please!");
        }
        else if (guess<number)
        {
            printf("Higher number please!");
        }
        else{
            printf("You guessed it in %d attempts!",nguess);
            
        }
        nguess++;
        
    } while (guess!=number);
       
    return 0;
}
