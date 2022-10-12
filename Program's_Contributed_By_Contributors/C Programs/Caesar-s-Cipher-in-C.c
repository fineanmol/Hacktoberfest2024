#include <stdio.h>
#include <string.h>

    
void cryptographyAndDecryption(char * phrase, int key){ //function to do encryption and decryption
    key = key % 26;
    int i = 0;
    while (phrase[i] != '\0') {
        if (phrase[i] >= 'a' && phrase[i] <= 'z') {
            unsigned sum = phrase[i] + key;
            if (sum > 'z') {
                sum -= 26;
            }
            if (sum < 'a') {
                sum += 26;
            }
            phrase[i] = sum;
        }
        if (phrase[i] >= 'A' && phrase[i] <= 'Z') {
            unsigned sum = phrase[i] + key;
            if (sum > 'Z') {
                sum -= 26;
            }
            if (sum < 'A') {
                sum += 26;
            }
            phrase[i] = sum;
        }
        i++;
    }
}

int main(void)
{
    char phrase[100];
    char C_or_D;
    int key = 0;

    printf("Type the word/phrase to Encrypt or Decrypt\n");
    fgets(phrase,100,stdin);
    
    
    printf("Enter the desired Key size\n");
    scanf(" %i",&key);
    printf("Type C to Encrypt, or D to Decrypt the entered word/phrase\n");
    scanf(" %c", &C_or_D);


    if (C_or_D == 'C' || C_or_D == 'c') {


       cryptographyAndDecryption(phrase, key);

        printf("Ecrypted: %s\n", phrase);


    }
    else if (C_or_D == 'D' || C_or_D == 'd') {

    
      cryptographyAndDecryption(phrase,-key); // minus symbol in the "key" to decrypt the sentenc

        printf("Deciphered: %s\n", phrase);
    }
    else {
        printf("The character entered is invalid");
    }

   
    return 0;
}