#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30
#define MALLOC(p, s, t)                   \
    p = (t)malloc(s);                     \
    if (p == NULL)                        \
    {                                     \
        printf("insufficient memeory\n"); \
        exit;                             \
    }

struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *NODE;

NODE create(NODE, int);
NODE createtree(NODE, int);
void Preorder(NODE);
void Postorder(NODE);
void Inorder(NODE);
int search(NODE, int);

int n;

int main()
{
    int choice, done, flag, key;
    NODE p;
    p = NULL;
    done = 0;
    while (!done)
    {
        printf("1.create\t2.preorder\t3.inorder\t4.postorder\t5.search\t6.exit\n");
        printf("enter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter no of data elements\n");
            scanf("%d", &n);
            p = create(p, n);
            break;
        case 2:
            Preorder(p);
            printf("\n");
            break;
        case 3:
            Inorder(p);
            printf("\n");
            break;
        case 4:
            Postorder(p);
            printf("\n");
            break;
        case 5:
            printf("enter the key to search\n");
            scanf("%d", &key);
            flag = search(p, key);
            if (flag == 1)
                printf("key found\n");
            else
                printf("key not found\n");
            break;
        case 6:
            done = 1;
            break;
        default:
            printf("invalid choice\n");
        }
    }
    return 0;
}

NODE create(NODE root, int n)
{
    int i, e;
    NODE q;
    if (root == NULL)
    {
        for (i = 1; i <= n; i++)
        {
            printf("enter data element\n");
            scanf("%d", &e);
            root = createtree(root, e);
        }
        return root;
    }
    else
        printf("tree already has some data\n");
    return 0;
}

NODE createtree(NODE p, int e)
{
    if (p == NULL)
    {
        MALLOC(p, sizeof(struct tree), NODE);
        p->info = e;
        p->left = p->right = NULL;
    }
    else if (e == p->info)
        printf("duplicate entry\n");
    else if (e < p->info)
        p->left = createtree(p->left, e);
    else
        p->right = createtree(p->right, e);
    return p;
}

int search(NODE p, int key)
{
    if (p == NULL)
        return 0;
    else if (key == p->info)
        return 1;
    else if (key < p->info)
        return search(p->left, key);
    else
        return search(p->right, key);
}

void Preorder(NODE p)
{
    if (p != NULL)
    {
        printf("%d\t", p->info);
        Preorder(p->left);
        Preorder(p->right);
    }
}

void Inorder(NODE p)
{
    if (p != NULL)
    {
        Inorder(p->left);
        printf("%d\t", p->info);
        Inorder(p->right);
    }
}

void Postorder(NODE p)
{
    if (p != NULL)
    {
        Postorder(p->left);
        Postorder(p->right);
        printf("%d\t", p->info);
    }
}
