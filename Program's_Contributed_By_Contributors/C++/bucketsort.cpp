#include <bits/stdc++.h>

using namespace std;

struct node
{
    float info;
    struct node *link;
};

void Printarray(float *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

struct node *insort(struct node *Nnode, struct node *sor)
{
    if (sor == NULL || sor->info >= Nnode->info)
    {
        Nnode->link = sor;
        sor = Nnode;
    }
    else
    {
        struct node *curr = sor;
        while (curr->link != NULL && curr->link->info < Nnode->info)
        {
            curr = curr->link;
        }
        Nnode->link = curr->link;
        curr->link = Nnode;
    }
    return sor;
}
struct node *InsertionSort(struct node *head)
{
    struct node *ptr = head, *sor = NULL;
    while (ptr != NULL)
    {
        struct node *next = ptr->link;
        sor = insort(ptr, sor);
        ptr = next;
    }
    return sor;
}

void Bucketsort(float *A, int n)
{
    struct node *B[20];
    int j;

    for (int i = 0; i < n; i++)
    {
        B[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        j = n * A[i];
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = A[i];
        ptr->link = B[j];
        B[j] = ptr;
    }

    for (int i = 0; i < n; i++)
    {
        B[i] = InsertionSort(B[i]);
    }

    int i = 0;
    int t = 0;


    while (i < n)
    {
        for (int j = 0; j < n; j++)
        {
            if (B[j] == NULL)
            {
                continue;
            }
            else
            {
                struct node *ptr = B[j];
                while (ptr != NULL)
                {
                    A[i] = ptr->info;
                    i++;
                    ptr = ptr->link;
                }
            }
        }
    }
}

int main()
{
    int i, n;
    float A[20];

    printf("Enter the value of n :");
    scanf("%d", &n);
    printf("Enter the %d array elements :", n);
    for (i = 0; i < n; i++)
    {
        printf("A[%d]= ", i);
        scanf("%f", A + i);
    }
    Bucketsort(A, n);
    Printarray(A, n);
    return 0;
}
