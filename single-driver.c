#include "singly-linked.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef 	__linux__
#define clear()  system("clear")
#elif _WIN32
#define clear()  system("cls")
#else
#define clear()  system("clear")
#endif


// === driver functions

void
printMenu(){
    printf( "\nmenu.\n"
            "1.  create a list.\n"
            "2.  display the list.\n"
            "3.  add a node at the beginning.\n"
            "4.  add a node at the end.\n"
            "5.  add a node before another node.\n"
            "6.  add a node after a given node.\n"
            "7.  delete a node from the beginning.\n"
            "8.  delete a node from the end.\n"
            "10. exit.\n");
}

void
handler(list **lp, int choice){
    list *l = *lp;
    int idx;
    node *element;
    node *popped;
    switch(choice){
        case 1:
            *lp = createEmptyList();
            break;
        case 2:
            printList(l);
            break;
        case 3:
            element = createNodeInteractive();
            insertBefore(l, getHead(l), element);
            break;
        case 4:
            element = createNodeInteractive();
            append(l, element);
            break;
        case 5:
            element = createNodeInteractive();
            printf("enter the node index before which you want to insert: ");
            scanf("%d", &idx);
            insertBefore(l, getNodeAt(l, idx), element);
            break;
        case 6:
            element = createNodeInteractive();
            printf("enter the node index after which you want to insert: ");
            scanf("%d", &idx);
            insertAfter(l, getNodeAt(l, idx), element);
            break;
        case 7:
            if(getLength(l) == 0){
                fprintf(stderr, "list is empty. cannot delete.\n");
                break;
            }
            deleteNode(l, getHead(l));
            break;
        case 8:
            popped = pop(l);
            if(popped)
                free(popped);
            break;
        case 10:
            printf("thanks for using the program. exiting now...\n");
            break;
    }
}

int
main(){
    list *l = NULL;
    int choice = 0;
    while(choice != 10){
        printMenu();
        printf("-> ");
        scanf("%d", &choice);

        handler(&l, choice);
    }
}