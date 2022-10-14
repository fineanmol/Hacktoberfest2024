typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct list {
    struct node *head;
    struct node *tail;

    int length;
} list;

// creator functions
node *  createEmptyNode();
node *  createNewNode(int data);
list *  createEmptyList();
node *  createNodeInteractive();

// prop. getter functions
int     getLength(list *l);
node *  getHead(list *l);
node *  getTail(list *l);

// finder functions
node *  getNodeAt(list *l, int index);
node ** getIndirect(list *l, node *element);

// adder functions
int     append(list *l, node *element);
int     insertBefore(list *l, node *before, node *element);
int     insertAfter(list *l, node *after, node *element);
int     insertAt(list *l, node *element, int idx);

// remover functions
node *  pop(list *l);
int     deleteNode(list *l, node *element);

// display
void    printList(list *l);
