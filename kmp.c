#include <stdio.h>
#include <string.h>

// Finding the LPS 
void computeLPSArray(char* pattern, int M, int* lps) 
{ 
    int len = 0, i = 1; 

    lps[0] = 0; // 0th index is always 0

    while (i < M) { 
        if (pattern[i] == pattern[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // Condition -> (pat[i] != pat[len]) 
        { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else //Condition if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

// Searcher Utility function
void KMPSearch(char* pattern, char* textString) 
{ 
    int M = strlen(pattern); 
    int N = strlen(textString); 

    // LPS Array for longest prefix suffix
    int lps[M]; 

    computeLPSArray(pattern, M, lps); 

    int i = 0; // index for the textString
    int j = 0; // index for the pattern
    while (i < N) { 
        if (pattern[j] == textString[i]) { 
            j++; 
            i++; 
        } 

        if (j == M) { 
            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        } 
        else if (i < N && pattern[j] != textString[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 


// Driver program to test above function 
int main() 
{ 
    char textString[1000], pattern[1000];
    printf("Enter the text string (1000 characters max) -");
    scanf("%s",&textString);
    printf("Enter the pattern string to be searched (1000 characters max) -");
    scanf("%s",&pattern);
    KMPSearch(pattern, textString); 
    return 0; 
}
