typedef struct cnode {
    int data;

    struct cnode *next;
} cnode;

typedef struct clist {
    int length;

    struct cnode *head;
} clist;

// === checker functions ===

int     checkBounds(clist *l, int idx);
int     checkNNull(cnode *node);
int     checkLNull(clist *l);


// === father functions ===

cnode * createEmptyNode();
cnode * createNewNode(int data);
cnode * createNodeInteractive();
clist * createEmptyList();

// === adder functions

int     append(clist *l, cnode *item);
int     newHead(clist *l, cnode *item);

// === remover functions

cnode * pop(clist *l);
cnode * behead(clist *l);

// === display ===

void    printList(clist *l);