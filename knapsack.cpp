#include <stdio.h>
#include <stdlib.h>
#define UNVISITED 0
#define VISITED 1
#define debug printf("passei aqui hihi\n");

typedef struct {
    bool** matrix;
    int numEdge;
    bool* Mark;
    int numV;
} Graph;

typedef struct Link {
    int element;  // value stored in this link/node
    struct Link* next;  // reference to the next link/node
} Link;

typedef struct {
    Link* top;
    int size;
} Stack;

typedef struct {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;    // list size
} List;

Link* create_link(int it, Link* nextval) {
    Link* n = (Link *) calloc(1, sizeof(Link));
    n->element = it;
    n->next = nextval;

    return n;
}

Stack* create_stack() {
    Stack* s = (Stack *) malloc(sizeof(Stack));
    s->top = create_link(0, s->top);
    s->size = 0;
    return s;
}

List* create_list() {
    List* l = (List *) malloc(sizeof(List));
    l->curr = l->tail = l->head = create_link(4, NULL); // all pointing to header (doesn't matter what's in header)
    l->cnt = 0;

    return l;
}

void push(Stack* s, int it) {
    s->top = create_link(it, s->top);
    s->size++;
}

long long int pop(Stack* s) {
    if(s->top == NULL) exit(1);
    long long int it = s->top->element;
    Link* temp = s->top;
    s->top = s->top->next;
    s->size--;
    free(temp);
    return it;
}

int lengthS(Stack* s) { return s->size; }

int topValue(Stack* s) { return s->top->element; }

void insert(List* l, int it) {
    l->curr->next = create_link(it, l->curr->next);
    if (l->tail == l->curr) l->tail = l->curr->next;
    l->cnt++;
}

void next(List* l) {
    if (l->curr != l->tail) l->curr = l->curr->next; // if it's not the last of the list
}

void prev(List* l) {
    if (l->curr == l->head) return; // first
    Link* temp = l->head;
    while (temp->next != l->curr) {
        temp = temp->next;
    }
    l->curr = temp;
}

void moveToStart(List* l) { l->curr = l->head; }
void moveToEnd(List* l) { l->curr = l->tail; }

int removeElement(List* l) {
    if (l->curr->next == NULL) return 0;
    int it = l->curr->next->element;
    if (l->tail == l->curr->next) {
        l->tail = l->curr;  
    }
    Link* temp = l->curr->next;
    l->curr->next = l->curr->next->next;
    free(temp); 
    l->cnt--;

    return it;
}

void printT(List *l){
    Link* temp = l->curr;
    moveToEnd(l);
    for (int i = 0; i < l->cnt; i++) {
        printf("%d" , l->curr->element);
        prev(l);
    }
    l->curr = temp;
}

int verify(int arr[], int size) {
    for(int j=1; j<size; j++) {
        if(arr[j] > arr[j-1]) return 0;
    }
    return 1;
}

Graph* create_graph (int n) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->Mark = (bool*) malloc(n*sizeof(bool));
    g->matrix = (bool**) calloc(n, sizeof(bool*));
    for (int i = 0; i < n; i++) {
        g->matrix[i] = (bool*) calloc(n, sizeof(bool));
    }
    g->numEdge = 0;
    g->numV = n;
    return g;
}

int n (Graph* g) {
    return g->numV;
}

int e (Graph* g) {
    return g->numEdge;
}

int first(Graph* g, int v) {
    for (int i = 0; i < n(g); i++) {
        if (g->matrix[v][i] != 0) return i;
    }
    return n(g); // vertice não se conecta a ninguém
}

int nextV(Graph* g, int v, int w){
    for (int i = w+1; i < n(g); i++) {
        if (g->matrix[v][i] != 0) return i;
    }
    return n(g); // vertice não se conecta a ninguém
}

void setEdge(Graph* g, int i, int j, int wt) {
    if (wt == 0) exit(1); // peso igual a 0 indica ausencia de aresta
    if (g->matrix[i][j] == 0) g->numEdge++;
    g->matrix[i][j] = wt; // existe aresta entre os dois 
}

void delEdge(Graph* g, int i, int j) {
    if (g->matrix[i][j] != 0) g->numEdge--;
    g->matrix[i][j] = 0;
}

//int isEdge(G g, int i, int j);
//int weight(G g, int i, int j);

void setMark(Graph* g, int v, bool val) {
    g->Mark[v] = val;
}

bool getMark(Graph* g, int v) {
    return g->Mark[v];
}

void toposort (Graph* g, int v, Stack* s) {
    setMark(g, v, 1);
    int w = first(g, v); //2
    while (w < n(g)) {
        if (getMark(g, w) == 0) {
            toposort (g, w, s);
        }
        w = nextV (g, v, w);
    }
    push (s, v);
}

void graphTraverse(Graph* g, Stack* s) {
    for (int v = 0; v < n(g); v++) setMark(g, v, 0);
    for (int v = 0; v < n(g); v++) {
        if (getMark(g, v) == 0) {
            toposort(g, v, s);
        }
    }
} 

void printMatrix (Graph* g) {
    for (int i=0; i<n(g); i++) {
        for (int j=0; j<n(g); j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    long long int V, E, s, t;
    scanf("%lld %lld", &V, &E);
    Graph* graph = create_graph(V);
    Stack* stack = create_stack();

    for (int j = 0; j < E; j++) {
        scanf("%lld %lld", &s, &t);
        setEdge(graph, s, t, 1);
    }
    //toposort(graph, 0, stack);
    graphTraverse(graph, stack);
    
    for (int i = 0; i < V; i++) {
        printf("%lld\n", pop(stack));
    }
}