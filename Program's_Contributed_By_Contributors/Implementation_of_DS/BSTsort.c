//sorting using binary tree
#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

void insert(struct node *, int element);

int * traversal(struct node *node ,int *sort, int *count);

int main()
{
    unsigned int n;
    printf("Enter elements you want to add in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements now: \n");

    for(int i=0;i<n;++i)
        scanf("%d", &arr[i]);

    printf("Element entered in arr: \n");
    for(int i=0;i<n;++i)
            printf("%d\t", arr[i]);
        printf("\n");


    struct node *root;
    root=(struct node *)malloc(sizeof(struct node));
    root->left=NULL;
    root->right=NULL;
    root->data=arr[0];


    for(int i=1;i<n;++i)
        insert(root, arr[i]);






    //Traversal
    int *sort;
    sort=malloc((sizeof(int)*n));
    int count=0;

    sort=traversal(root, sort, &count);

    for(int i=0;i<n;++i){
        printf("%d\t", *(sort+i));
    }

    return 0;
}


void insert(struct node *node, int element){
    if(element<node->data){
        if(node->left==NULL){
            struct node *newNode;
            newNode=(struct node *)malloc(sizeof(struct node));
            newNode->data=element;
            newNode->left=NULL;
            newNode->right=NULL;

            node->left=newNode;
        }
        else{
            insert(node->left, element);
        }
    }
    else if(element>=node->data){
        if(node->right==NULL){
            struct node *newNode;
            newNode=(struct node *)malloc(sizeof(struct node));
            newNode->data=element;
            newNode->left=NULL;
            newNode->right=NULL;

            node->right=newNode;
        }
        else{
            insert(node->right, element);
        }

    }
}


int * traversal(struct node *node, int *sort, int *count){
    if(node!=NULL){
        sort=traversal(node->left, sort, count);
        *(sort+ *count)=node->data;
        (*count)++;
        printf("\n");
        sort=traversal(node->right, sort, count);

    }
    return sort;

}
