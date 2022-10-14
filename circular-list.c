#include "circular-list.h"

#include <stdio.h>
#include <stdlib.h>

// === checker functions ===

// checks if the given index is within the bounds of the list.
int
checkBounds(clist *l, int idx){
    if(idx < 0 || idx >= l->length){
        fprintf(stderr, "index out of bounds [0 - %d]\n", l->length);
        return 1;
    }
    return 0;
}

// checks if the given node is null and prints an error message if it is.
int
checkNNull(cnode *node){
    if(!node){
        fprintf(stderr, "the passed node is null!\n");
        return 1;
    }
    return 0;
}

// checks if the given list is null and prints an error message if it is.
int
checkLNull(clist *l){
    if(!l){
        fprintf(stderr, "the passed list is null!\n");
        return 1;
    }
    return 0;
}


// === father functions ===

// creates an empty node. initialises the pointer to null and data to 0.
cnode *
createEmptyNode(){
    cnode *newNode = (cnode *)malloc(sizeof(cnode));
    newNode->data = 0;
    newNode->next = NULL;

    return newNode;
}

// creates a new node. initialises the pointer to null and sets data as the passed arg.
cnode *
createNewNode(int data){
    cnode *newNode = createEmptyNode();
    newNode->data = data;

    return newNode;
}

// creates a new node. initialises the pointer to null and sets data interactively.
cnode *
createNodeInteractive(){
    int data;
    printf("enter the value to store in the node: ");
    scanf("%d", &data);

    cnode *newNode = createNewNode(data);
    return newNode;
}

// creates an empty list. initialises the head pointer to null and sets the length to 0.
clist *
createEmptyList(){
    clist *newList = (clist *)malloc(sizeof(clist));
    newList->length = 0;
    newList->head = NULL;

    return newList;
}


// === adder functions

// adds a new node at the end of the list
int
append(clist *l, cnode *item){
    if(checkNNull(item) || checkLNull(l))
        return -1;

    cnode **cnodeptr = &l->head;
    while(*cnodeptr) {
        cnodeptr = &(*cnodeptr)->next;
        if(*cnodeptr == l->head) break;
    }

    *cnodeptr = item;
    item->next = l->head;
    l->length++;
    return 0;
}

// add a new noe at the beginning of the list
int
newHead(clist *l, cnode *item){
    if(append(l, item))
        return -1;
    l->head = item;

    return 0;
}

// === remover functions ===

// removes the last element in the list
cnode *
pop(clist *l){
    if(checkLNull(l))
        return NULL;

    cnode **cnodeptr = &l->head;
    while(*cnodeptr && (*cnodeptr)->next != l->head)
        cnodeptr = &(*cnodeptr)->next;

    cnode *popped = *cnodeptr;
    *cnodeptr = l->head;

    l->length--;
    return popped;
}

// removes the first element in the list
cnode *
behead(clist *l){
    if(checkLNull(l))
        return NULL;

    // finding indirect pointer to the head from tail end.
    cnode **cnodeptr = &l->head;
    cnode *tail = *cnodeptr;
    while(*cnodeptr) {
        cnodeptr = &(*cnodeptr)->next;
        if(*cnodeptr == l->head) break;
    }

    cnode *popped = *cnodeptr;*cnodeptr = (*cnodeptr)->next;
    l->head = *cnodeptr;

    l->length--;
    return NULL;
}


// === display ===
void
printList(clist *l){
    if(checkLNull(l))
        return;
    printf("length of the list is: %d\n", l->length);
    cnode *current = l->head;
    while(current){
        printf("%d [%p] -> ", current->data, current);
        if(current->next)
            printf("%d [%p]", current->next->data, current->next);
        else
            printf("NULL");
        printf("\n");
        if(current->next == l->head) break;
        current = current->next;
    }
}