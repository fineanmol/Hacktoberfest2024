#include <stdio.h>

main(){

    char morse[26][5]={
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--.."};


    char str[100];
    int n;
    printf("Inserisci la frase: \n");
    scanf("%s",str);
    n=strlen(str);

    for (int i=0;i<n;i++){
        char c=str[i];
        if (c>='a' && c<='z')
            c=toupper(c);
        if (c>='A' && c<='Z')
            printf("%s ", morse[c-'A']);
    }
    printf("\n");
}
