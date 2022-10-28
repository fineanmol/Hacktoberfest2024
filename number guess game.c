// Number Guess Game
// Creater : Manish Kumar       

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int play;
    printf("LOOK HERE SOMEONE WANT TO PLAY GAME :)\n\tYou will have to guess the correct number\n\tLets see how much attempts is required for you\n");

    do
    {
        int number;
        srand(time(0));
        number = rand() % 100 + 1; // Generates a random number between 1 and 100
        // printf("The number is %d\n", number);

        int i, a;
        for (i = 0; a != number; i++) //ERROE UCCURED |:| NOW SOLVED ((;))
        {
            printf("\nEnter your number: ");
            scanf("%d", &a);
            if (a > number)
            {
                printf("You enterd a greater number! Enter a smaller one  :(\n");
            }
            else if (a < number)
            {
                printf("You enterd a smaller number! Enter a bigger one  :(\n");
            }
        }
        // printing Current score
        printf("\nYou have scored %d points\n", i);

        
        // Printing Previous Score
        int high;   FILE * score;
        score = fopen("HighScore.txt", "r");    fscanf(score, "%d", &high);     fclose(score);
        printf("\nYour previous highscore was: %d\n", high);
        

        // Changing Highscore
        if(high >i){
            printf("\n\t\t!CONGRATULATIONS! :) You have creared a new highscore\n\n");
            FILE * score1;
            score1 = fopen("HighScore.txt", "w");    fprintf(score1, "%d", i);     fclose(score1);
        }
        
        // Loop for playing game Again
        do{
        printf("Do you want to play again (0 for NO and 1 for YES): ");
            scanf("%d", &play);
            if (play > 1 || play <0)
            {
            printf("Enter a valid number (i.e. 0 or 1)\n");
            }

            }
            while(play > 1 || play <0);


        } while (play == 1);


        return 0;
}
