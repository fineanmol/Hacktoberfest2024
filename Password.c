 /* C program to accept a password only if the entered password includes:
1 uppercase letter
2 lowercase letters
3 digits
2 symbols
 */

//here, I have written the code and it works fine.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX_LIMIT 20  // defined MAX_LIMIT, you can set this to any value as per the need

bool verify_password(char *p);
int main()
{
char p[MAX_LIMIT];

printf("Enter a password:\n");


fgets(p, MAX_LIMIT, stdin);  
bool result = verify_password(p);

if (result) 
    printf("Verified password!\n");
else 
    printf("Invalid password!\n");
    
return 0;
}

bool verify_password(char *p)
{
int length = strlen(p);

if (length < 8) return false;

int upper_count = 0; // imp lines of code 
int lower_count = 0;
int digit_count = 0;
int symbol_count = 0;

for (int i = 0; i < length; i++)
{
    if (isupper(p[i])) upper_count++;
    if (islower(p[i])) lower_count++;
    if (isdigit(p[i])) digit_count++;
    if (ispunct(p[i])) symbol_count++;
}
if (upper_count > 1) return false;
if (lower_count > 2) return false;
if (digit_count > 3) return false;
if (symbol_count > 2) return false;

return true; 
}
