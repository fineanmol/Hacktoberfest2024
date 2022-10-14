typedef struct dnode{
    int data;

    struct dnode *next, *prev;
} dnode;

typedef struct dlist{
    int length;

    dnode *head;
} dlist;

// === checker functions ===

int     checkNNull(dnode *node);
int     checkBounds(dlist *l, int index);
int     checkLNull(dlist *l);
int     checkCapacity(dlist *l);


// === father functions ===

dnode * createEmptyNode();
dnode * createNewNode(int data);
dnode * createNodeInteractive();

dlist * createEmptyList();


// === adder functions ===

int     append(dlist *l, dnode *element);
int     newHead(dlist *l, dnode *element);


// === remover functions ===

dnode * pop(dlist *l);
dnode * behead(dlist *l);


// === info functions ===

void    printList(dlist *l);