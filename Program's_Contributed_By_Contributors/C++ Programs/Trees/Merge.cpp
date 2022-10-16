#include <stdio.h>
#include <stdlib.h>
#include<iostream>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int *merge(int arr1[], int arr2[], int m, int n);
void storeInorder(struct node* node, int inorder[], int *index_ptr);
struct node* sortedArrayToBST(int arr[], int start, int end);

struct node* mergeTrees(struct node *root1, struct node *root2, int m, int n)
{

    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);


    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);

    int *mergedArr = merge(arr1, arr2, m, n);


    return sortedArrayToBST (mergedArr, 0, m+n-1);
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);

    printf("%d ", node->data);
    printInorder(node->right);
}
int *merge(int arr1[], int arr2[], int m, int n)
{
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++; k++;
    }
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++; k++;
    }

    return mergedArr;
}
void storeInorder(struct node* node, int inorder[], int *index_ptr)
{
    if (node == NULL)
        return;

    storeInorder(node->left, inorder, index_ptr);

    inorder[*index_ptr] = node->data;
    (*index_ptr)++;

    storeInorder(node->right, inorder, index_ptr);
}
struct node* sortedArrayToBST(int arr[], int start, int end)
{

    if (start > end)
      return NULL;

    int mid = (start + end)/2;
    struct node *root = newNode(arr[mid]);
    root->left =  sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

int main()
{
    struct node *root1  = newNode(10);
    root1->left         = newNode(8);
    root1->right        = newNode(15);
    root1->left->left   = newNode(6);
    root1->left->right  = newNode(9);

    struct node *root2  = newNode(15);
    root2->left         = newNode(14);
    root2->right        = newNode(20);

    struct node *mergedTree = mergeTrees(root1, root2, 5, 3);

    printf ("Following is Inorder traversal of the merged tree \n");
    printInorder(mergedTree);

    getchar();
    return 0;
}

