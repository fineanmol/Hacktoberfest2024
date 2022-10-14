#include "singly-linked.h"

#include <stdio.h>
#include <stdlib.h>

// creates an empty node with data set to 0 and next set to NULL
node *
createEmptyNode(){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = 0;
    newNode->next = NULL;

    return newNode;
}

// creates a new node and initializes it's data with the passed param. next is still NULL
node *
createNewNode(int data){
    node *newNode = createEmptyNode();
    newNode->data = data;

    return newNode;
}

// creates a new node interactively
node *
createNodeInteractive(){
    int data;
    printf("Enter the value to be stored in the node: ");
    scanf("%d", &data);
    node *newNode = createNewNode(data);

    return newNode;
}


// creates a new empty list with no elements- head and tail set to NULL and length 0
list *
createEmptyList(){
    list *newList = (list *)malloc(sizeof(list));
    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;

    return newList;
}


// returns the present length of the list
int 
getLength(list *l){
    return l->length;
}

// returns the first (head) element of the list
node *
getHead(list *l){
    return l->head;
}


// returns the address of the node at a specific index
node *
getNodeAt(list *l, int index){
    // responding to invalid conditions
    if(!l){
        fprintf(stderr, "the passed list is NULL!\n");
        return NULL;
    } else if(index >= l->length || index < 0){
        fprintf(stderr, "the demanded index is out of bounds [0-%d]\n", l->length - 1);
        return NULL;
    }

    node *current = l->head;

    // loops until the demanded index is reached
    for(int i = 0; i < index; i++, current = current->next);

    return current;
}

// returns the pointer to the pointer that's recording the passed node element
node **
getIndirect(list *l, node *element){
    node **nodeptr = &l->head;
    while(*nodeptr && *nodeptr != element)
        nodeptr = &(*nodeptr)->next;

    return nodeptr;
}

// returns the pointer to the pointer that's recording the node at index idx
node **
getIndirectAt(list *l, int idx){
    if(!l){
        fprintf(stderr, "the passed list is NULL!\n");
        return NULL;
    } else if(idx < 0 || idx >= getLength(l)) {
        fprintf(stderr, "the passed index is out of bounds [0-%d]\n", l->length - 1);
        return NULL;
    }
    
    node **nodeptr = &l->head;
    while(*nodeptr && idx--)
        nodeptr = &(*nodeptr)->next;

    return nodeptr;
}


// appends the passed item at the end of the list
int 
append(list *l, node *element){
    if(!l){
        fprintf(stderr, "the passed list is NULL!\n");
        return 1;
    }

    node **nodeptr = &l->head;
    while(*nodeptr)
        nodeptr = &(*nodeptr)->next;

    *nodeptr = element;
    l->length++;
    
    return 0;
}

// inserts an element before a given node
int 
insertBefore(list *l, node *before, node *element){
    if(!l){
        fprintf(stderr, "the passed list is NULL!\n");
        return 1;
    }

    node **beforeptr = getIndirect(l, before);
    *beforeptr = element;
    element->next = before;
    l->length++;

    return 0;
}

// inserts a node after a given node
int 
insertAfter(list *l, node *after, node *element){
    if(!l){
        fprintf(stderr, "the passed list is NULL!\n");
        return 1;
    }

    node *tmp = after->next;
    after->next = element;
    element->next = tmp;
    l->length++;

    return 0;
}

// inserts an element at a specified index
int 
insertAt(list *l, node *element, int idx){
    if(!l){
        fprintf(stderr, "the passed list is NULL!\n");
        return 1;
    }
    node **beforeptr = getIndirectAt(l, idx);
    node *tmp = *beforeptr;
    *beforeptr = element;
    element->next = tmp;
    
    l->length++;
    
    return 0;
}


// de-links the last element from the list and returns it.
node *
pop(list *l){
    node **tailptr = getIndirectAt(l, getLength(l) - 1);
    node *popped = *tailptr;
    *tailptr = NULL;
    l->length--;

    return popped;
}

// de-links the passed node
int 
deleteNode(list *l, node *element){
    if(!l){
        fprintf(stderr, "the passed list is NULL!\n");
        return 1;
    } else if(!element) {
        fprintf(stderr, "the passed node is NULL!\n");
        return 1;
    }

    node **nodeptr = getIndirect(l, element);
    *nodeptr = element->next;
    
    l->length--;
    free(element);
    return 0;
}


// prints the list
void
printList(list *l){
    if(!l){
        fprintf(stderr, "the passed list is NULL!\n");
        return;
    } 
    printf("list length: %d\n", getLength(l));

    node *current = l->head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}