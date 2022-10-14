#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int realloc_step = 5;

char** reallocate(long* size, int diff, char** orig){
    *size += diff;
    return (char**)realloc(orig, *size * sizeof(char*));
}

char** loadfile(char* file, long* length){
    FILE *f = fopen(file, "r");
    if(!f){
        fprintf(stderr, "I/O Err. Failed to open the file.\n");
        exit(2);
    }

    printf("Loading file into the structure...\n");

    long size = 0;
    char** lines = NULL;

    char buffer[1000];
    while(fgets(buffer, 1000, f)){
        if(*length == size){
            size += realloc_step;
            char** temp = reallocate(&size, realloc_step, lines);
            if(!temp){
                fprintf(stderr, "FATAL. Failed to reallocate memory!\n");
                exit(3);
            }
            lines = temp;
        }
        buffer[strlen(buffer) - 1] = '\0';

        // allocate space for the string and null character
        char* str = (char*) malloc((strlen(buffer)+1) * sizeof(char));
        if(!str){
            fprintf(stderr, "FATAL. Failed to allocate memory!\n");
        }
        strcpy(str, buffer);

        lines[*length] = str;
        *length = *length + 1;
    }
    return lines;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "USAGE: ./load <filename>\n");
        exit(1);
    }

    // Load file into a structure
    long length = 0;
    char **text = loadfile(argv[1], &length);
    printf("Finished loading!\n");
    printf("Last line is: %s\n", text[length - 1]);
}
