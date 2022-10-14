#include "circular-list.h"

#include <stdio.h>
#include <stdlib.h>


#ifdef 	__linux__
#define clear()  system("clear")
#elif _WIN32
#define clear()  system("cls")
#else
#define clear()  system("clear")
#endif

// === driver functions ===

// handles the choices made by the user
void
handle(int choice, clist **lptr){
    clist *l = *lptr;
    cnode *node, *popped;
    switch(choice) {
        case 1:
            if(*lptr)
                free(*lptr);
            *lptr = createEmptyList();
            break;
        case 2:
            printList(l);
            break;
        case 3:
            node = createNodeInteractive();
            newHead(l, node);
            break;
        case 4:
            node = createNodeInteractive();
            append(l, node);
            break;
        case 5:
            popped = behead(l);
            if(popped) {
                printf("%d popped.\n", popped->data);
                free(popped);
            }
            break;
        case 6:
            popped = pop(l);
            if(popped) {
                printf("%d popped.\n", popped->data);
                free(popped);
            }
            break;
        case 7:
            printf("thanks for using the program. exiting now...\n");
            break;
        default:
            printf("invalid choice!\n");
            break;
    }
    fflush(stdin);
    printf("press any key to continue...");
    char ch;
    scanf("%c", &ch);
}

// prints the menu of the application
void
printMenu(){
    clear();

    printf( "menu.\n"
            "1. create a new list.\n"
            "2. display the list.\n"
            "3. add a node at the beginning of the list.\n"
            "4. add a node at the end of the list.\n"
            "5. delete a node from the beginning of the list.\n"
            "6. delete a node from the end of the list.\n"
            "7. exit the program.\n");
}

int
main(){
    int choice = 0;
    clist *l = NULL;
    do{
        printMenu();
        printf("enter your choice: ");
        scanf("%d", &choice);

        handle(choice, &l);
    } while(choice != 7);
}