#include "doubly-linked.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef 	__linux__
    #define clear()  system("clear")
#elif _WIN32
    #define clear()  system("cls")
#else
    #define clear()  system("clear")
#endif

// === checker functions ===

// checks if the given index is within the bounds of the list.
int
checkBounds(dlist *l, int idx){
    if(idx < 0 || idx >= l->length){
        fprintf(stderr, "index out of bounds [0 - %d]\n", l->length);
        return 1;
    }
    return 0;
}

// checks if the given node is null and prints an error message if it is.
int
checkNNull(dnode *node){
    if(!node){
        fprintf(stderr, "the passed node is null!\n");
        return 1;
    }
    return 0;
}

// checks if the given list is null and prints an error message if it is.
int
checkLNull(dlist *l) {
    if (!l) {
        fprintf(stderr, "the passed list is null!\n");
        return 1;
    }
    return 0;
}

// checks if deletion is possible
int
checkCapacity(dlist *l){
    if(!l)
        return 1;

    if(l->length == 0){
        fprintf(stderr, "deletion is not possible as the list is empty!\n");
        return 1;
    }
    return 0;
}


// === father functions ===

// creates an empty node. initializes the pointers to null and sets data to 0.
dnode *
createEmptyNode(){
    dnode *newNode = (dnode *) malloc(sizeof(dnode));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = 0;

    return newNode;
}

// creates a new node. initializes the pointer to null and sets data as passed in the arg.
dnode *
createNewNode(int data){
    dnode *newNode = createEmptyNode();
    newNode->data = data;

    return newNode;
}

// creates a new node. initializes the pointer to null and sets data interactively.
dnode *
createNodeInteractive(){
    int data;
    printf("enter the data to be stored in the node: ");
    scanf("%d", &data);
    dnode *newNode = createNewNode(data);

    return newNode;
}

// creates a new list. initializes the head as null and sets length = 0.
dlist *
createEmptyList(){
    dlist *newList = (dlist *)malloc(sizeof(dlist));
    newList->length = 0;
    newList->head = NULL;

    return newList;
}


// === adder functions ===

// adds an element to the end of the list
int
append(dlist *l, dnode *element){
    if(checkLNull(l) || checkNNull(element))
        return -1;

    dnode **dnodeptr = &l->head;
    dnode *tail = *dnodeptr;
    while(*dnodeptr) {
        tail = *dnodeptr;
        dnodeptr = &(*dnodeptr)->next;
    }
    *dnodeptr = element;
    element->prev = tail;
    element->next = NULL;

    l->length++;

    return 0;
}

// adds an element to the beginning of the list
int
newHead(dlist *l, dnode *element){
    if(checkLNull(l) || checkNNull(element))
        return -1;

    element->prev = NULL;
    element->next = l->head;
    if(l->head)
        l->head->prev = element;

    l->head = element;

    l->length++;

    return 0;
}


// === remover functions ===

// removes the last element from the list
dnode *
pop(dlist *l){
    if(checkLNull(l) || checkCapacity(l))
        return NULL;

    dnode **dnodeptr = &l->head;
    while(*dnodeptr && (*dnodeptr)->next)
        dnodeptr = &(*dnodeptr)->next;

    dnode *popped = *dnodeptr;
    *dnodeptr = NULL;

    l->length--;

    return popped;
}

// removes the first element in the list
dnode *
behead(dlist *l){
    if(checkLNull(l) || checkCapacity(l))
        return NULL;

    dnode *popped = l->head;
    l->head = popped->next;
    l->head->prev = NULL;
    popped->next = NULL;

    l->length--;

    return popped;
}


// === info functions ===

// prints the list
void
printList(dlist *l){
    if(checkLNull(l))
        return;

    printf("length of the list is: %d\n", l->length);

    dnode *current = l->head;

    // prints in format  <prev node data> <- <data> -> <next node data>
    while(current){
        if(current->prev)
            printf("%6d <- ", current->prev->data);
        else
            printf("  NULL <- ");

        printf("%6d", current->data);

        if(current->next)
            printf(" -> %6d\n", current->next->data);
        else
            printf(" ->   NULL\n");

        current = current->next;
    }
}