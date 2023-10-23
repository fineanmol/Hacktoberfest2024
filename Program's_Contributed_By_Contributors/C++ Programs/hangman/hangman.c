#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 30
#define MAX_GUESSES 10

void clearScreen() {
    printf("\033[2J\033[1;1H");
}

void drawHangman(int incorrect) {
    switch (incorrect) {
        case 0:
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            break;
        case 1:
            printf(" _________\n");
            printf("|         |\n");
            printf("|         O\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 2:
            printf(" _________\n");
            printf("|         |\n");
            printf("|         O\n");
            printf("|         |\n");
            printf("|\n");
            printf("|\n");
            break;
        case 3:
            printf(" _________\n");
            printf("|         |\n");
            printf("|         O\n");
            printf("|        /|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 4:
            printf(" _________\n");
            printf("|         |\n");
            printf("|         O\n");
            printf("|        /|\\\n");
            printf("|\n");
            printf("|\n");
            break;
        case 5:
            printf(" _________\n");
            printf("|         |\n");
            printf("|         O\n");
            printf("|        /|\\\n");
            printf("|        /\n");
            printf("|\n");
            break;
        case 6:
            printf(" _________\n");
            printf("|         |\n");
            printf("|         O\n");
            printf("|        /|\\\n");
            printf("|        / \\\n");
            printf("|\n");
            break;
    }
}

int main(int argc, char** argv) {
    char word[MAX_LEN];
    char wordCopy[MAX_LEN];
    char guess[MAX_LEN];
    int incorrect = 0;
    int len;
    int i, j;
    int alreadyGuessed = 0;

    srand(time(NULL));
    int wordNum = rand() % 5;

    switch (wordNum) {
        case 0:
            strcpy(word, "hello");
            break;
        case 1:
            strcpy(word, "world");
            break;
        case 2:
            strcpy(word, "apple");
            break;
        case 3:
            strcpy(word, "pear");
            break;
        case 4:
            strcpy(word, "banana");
            break;
    }

    len = strlen(word);

    for (i = 0; i < len; i++) {
        wordCopy[i] = '_';
    }
    wordCopy[i] = '\0';

    while (incorrect < MAX_GUESSES && strcmp(word, wordCopy) != 0) {
        clearScreen();
        printf("Guess the word: %s\n", wordCopy);
        printf("You have %d incorrect guesses left.\n", MAX_GUESSES - incorrect);
        drawHangman(incorrect);
        printf("Enter your guess: ");
        scanf("%s", guess);

        alreadyGuessed = 0;
        for (i = 0; i < len; i++) {
            if (guess[0] == word[i]) {
                wordCopy[i] = guess[0];
                alreadyGuessed = 1;
            }
        }
        if (!alreadyGuessed) {
            incorrect++;
        }
    }

    clearScreen();
    if (incorrect == MAX_GUESSES) {
        printf("You lost! The word was: %s\n", word);
    } else {
        printf("You won! The word was: %s\n", word);
    }

    return 0;
}
