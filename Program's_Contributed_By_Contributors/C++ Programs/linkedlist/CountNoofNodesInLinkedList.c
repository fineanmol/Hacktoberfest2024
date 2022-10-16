#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node{
    int data;
    struct Node *next;
}*first = NULL;

// Creating a Linked List 
void create(int a[],int n){
    struct Node *p,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = 0;
    last = first;
    for(int i=1;i<n;i++){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = a[i];
        p->next = 0;
        last->next = p;
        last = p;
    }
}

void count_node(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    printf("No of Nodes in Linked List: %d\n",count);
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    count_node(first);
    return 0;
}
