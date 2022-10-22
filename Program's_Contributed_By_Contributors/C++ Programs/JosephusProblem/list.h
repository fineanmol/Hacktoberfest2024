typedef struct node Node;
typedef struct list List;

struct node
{
    int num;
    Node *next;
    Node *previous;
};

struct list
{
    int size;
    Node *head;
};
