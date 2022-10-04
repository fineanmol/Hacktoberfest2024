
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Stack{
    int top;
    unsigned capacity;
    int *a;
};

struct Stack *create(unsigned capacity){
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->a = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack){
    return stack->top == -1;
}

void push(struct Stack *stack, int item){
    if (isFull(stack))
        return;
    stack->a[++stack->top] = item;
}

int pop(struct Stack *stack){
    if (isEmpty(stack))
        return -1;
    return stack->a[stack->top--];
}

typedef struct listNode ListNode;
struct listNode{
    ListNode *next;
    int data;
};

ListNode *createNode(int x){
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

ListNode *insert(ListNode *head, int x){
    if (head == NULL){
        head = createNode(x);
        return head;
    }
    ListNode *temp = head;
    while (temp->next != NULL)temp = temp->next;
    temp->next = createNode(x);
    return head;
}

void print(ListNode *head){
    ListNode *temp = head;
    while (temp != NULL){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void dfs(ListNode **adjList, int visited[],struct Stack *DFS, int v){
    int idx = 0;
    struct Stack *stack = create(100);
    push(stack, v);
    while (!isEmpty(stack)){
        v = pop(stack);
        if (visited[v])continue;
        visited[v] = 1;
        push(DFS,v);
        ListNode *temp = adjList[v];
        while (temp != NULL){
            if (!visited[temp->data])
                push(stack, temp->data);
            temp = temp->next;
        }
    }
}

void TS(ListNode **adjList, int visited[], int v){
    int i;
    struct Stack *DFS = create(v);
    struct Stack *TS = create(v);
    for (i = 0; i < v; i++){
        dfs(adjList, visited, DFS, i);
        while(!isEmpty(DFS)){
            int v = pop(DFS);
            push(TS,v);
        }
    }
    printf("\nTopological sort using DFS : ");
    while(!isEmpty(TS))
        printf("%d ",pop(TS));
    
}

int main(){
    int v, e, i, j;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    ListNode **adjList = malloc(v * sizeof(ListNode *));
    for (i = 0; i < v; i++)adjList[i] = NULL;
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    int start, end, visited[v];
    for (i = 0; i < v; i++)visited[i] = 0;
    for (i = 0; i < e; i++){
        printf("Enter start and end vertex of edge %d : ", i + 1);
        scanf("%d%d", &start, &end);
        adjList[start] = insert(adjList[start], end);
    }
    printf("\nAdjacency List : \n");
    for (i = 0; i < v; i++){
        printf("%d : ", i);
        print(adjList[i]);
    }
    TS(adjList,visited,v);
    printf("\n Gautham Prabhu M \n 200905124");
}

    