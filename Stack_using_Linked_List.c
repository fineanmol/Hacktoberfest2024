//head is now top of the stack as it is easier to insert and delete
//Stack Empty condition -> Top == Null
//Stack is full when heap memory is exhausted (ptr points to null),unless a custom size has been set
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct Node *ptr){
    if(ptr == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct Node *ptr){
    struct Node * p =(struct Node *)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Node * push(struct Node * top,int data){
    if(isFull(top)){
        printf("Stack Overflow!\n");
    }
    else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}
struct Node * pop(struct Node * top){
    if(isEmpty(top)){
        printf("Stack Underflow!\n");
    }
    else{
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        printf("The Popped Element is : %d\n",x);
        return top;
    }
}
int Peek(struct Node * top, int pos){
    struct Node * ptr = top;
    for(int i=0;(i<pos-1 && ptr!= NULL);i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int StackTop(struct Node * top){
    return top->data;
}
int StackBottom(struct Node * top){
    struct Node * p = top;
    while(p->next!=NULL){
        p = p->next;
    }
    return p->data;
}
int main(){
    struct Node * top = NULL;
    top = push(top,2);
    top = push(top,4);
    top = push(top,6);
    top = push(top,8);
    top = push(top,10);
    linkedListTraversal(top);
    printf("Value at position 3 is : %d\n",Peek(top,3));
    printf("Stack Top : %d\n",StackTop(top));
    printf("Stack Bottom : %d\n",StackBottom(top));
    return 0;

}
