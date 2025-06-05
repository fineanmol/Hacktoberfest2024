 #include<stdio.h>
 #include<stdlib.h>
 struct node{
     int data;
     struct node *next;
 };
 void list_traversal(struct node *ptr){
    while(ptr!=NULL){
         printf("element :%d\n",ptr->data);
         ptr=ptr->next;
     }
 }
 struct node *deletion_atfirst(struct node *head){
     struct node *p=head;
     head=head->next;
     free(p);
     return head;
 }
 struct node *deletion_atend(struct node *head){
     struct node *p=head;
     struct node *q=(struct node *)malloc(sizeof(struct node));
     q=p->next;
     while(q->next!=NULL){
         p=p->next;
         q=q->next;
     }
     p->next=NULL;
     free(q);
     return head;
 }
 //deletion of an element at a given index of linked list
 struct node *deletion_atindex(struct node *head,int index){
     struct node *p=head;
     struct node *q=p->next;
     for(int i=0;i<index-1;i++){
         p=p->next;
         q=q->next;
     }
     p->next=q->next;
     free(q);
     return head;
 }
 //deletion of a given element from linked list
 struct node *deletion_ofelement(struct node *head,int value){
     struct node *p=head;
     struct node *q=p->next;
     while(q->data!=value&&q->next!=NULL){
         p=p->next;
         q=q->next;
     }
     if(q->data==value){
         p->next=q->next;
     }
     free(q);
     return head;
 }
 int main(){
     struct node *head;
     struct node *second;
     struct node *third;
     struct node *fourth;
     head=(struct node *)malloc(sizeof(struct node));
     second=(struct node *)malloc(sizeof(struct node));
     third=(struct node *)malloc(sizeof(struct node));
     fourth=(struct node *)malloc(sizeof(struct node));
     head->data=15;
     head->next=second;
     second->data=171;
     second->next=third;
     third->data=50;
     third->next=fourth;
     fourth->data=78;
     fourth->next=NULL;
     //list_traversal(head);
     //head=deletion_atfirst(head);
     //head=deletion_atend(head);
     //head=deletion_atindex(head,1);
     head=deletion_ofelement(head,171);
     list_traversal(head);
 }
