#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;



struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}


class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
       if(!head)return;
       Node  *it = head;
       for(int i=0;i<M-1;++i){
           if(!it)return;
           it = it->next;
       }
       //it would be at empty node
       if(!it)return;
       
       Node* MthNode = it;
       it = MthNode->next;
       
       for(int i=0;i<N; ++i){
           if(!it)break;
           
           Node* temp = it->next;
           delete it;
           it = temp;
       }
       
       MthNode->next = it;
       linkdelete(it, M,N);
    }
};




int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}
