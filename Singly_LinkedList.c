#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  

void beginsert ();   
void lastinsert ();  
void insertAfter();
void insertBefore();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
int main (){  
    int choice1 =0, data, choice2, value, location;  
    while(choice1 != 4){
      printf("\n*********** SLL MENU *************\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
      scanf("%d",&choice1);
      switch(choice1){
         case 1:
            while(1){
               printf("\nSelect from the following Inserting options\n");
               printf("1. At Beginning\n2. At End\n3. After a Node\n4. Before a Node\n5. Cancel\nEnter your choice: ");
               scanf("%d",&choice2);
               switch(choice2){
                  case 1:
                    beginsert();
                    display();
                    break;
                  case 2: 
                    lastinsert();
                    display();
                    break;
                  case 3:
                    insertAfter();
                    display();
                    break;
                  case 4:
                    insertBefore();
                    display();
                    break;
                  case 5: 
                    goto EndSwitch;
                  default:
                    printf("\nPlease select correct Inserting option!!\n");
               }
            }
         case 2:
            while(1){
               printf("\nSelect from the following Deleting options\n");
               printf("1. At Beginning\n2. At End\n3. Specific Node\n4. Cancel\nEnter your choice: ");
               scanf("%d", &choice2);
               switch(choice2){
                  case 1:
                     begin_delete();
                     display();
                     break;
                  case 2:
                     last_delete();
                     display();
                     break;
                  case 3:
                     random_delete();
                     display();
                     break;
                  case 4:
                     goto EndSwitch;
                  default:
                     printf("\nPlease select correct Deleting option!!!\n");
               }
            }
            EndSwitch: break;
         case 3: 
            display();
            break;
         case 4: 
            exit(0);
         default:
            printf("\nPlease select correct option!!!");
      }
   }
   return 0;
}

void beginsert(){  
    struct node *ptr;  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL){  
        printf("\nOVERFLOW");  
    } else{  
        printf("\nEnter value: ");    
        scanf("%d",&item);    
        ptr->data = item;  
        ptr->next = head;  
        head = ptr;  
        printf("\nNode inserted");  
    }  
      
}  
void lastinsert(){  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL){  
        printf("\nOVERFLOW");     
    } else{  
        printf("\nEnter value: ");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL) {  
            ptr -> next = NULL;  
            head = ptr;  
            printf("\nNode inserted");  
        } else {
            temp = head;
            while (temp -> next != NULL) {  
                temp = temp -> next;  
            }
            temp->next = ptr;  
            ptr->next = NULL;
            printf("\nNode Inserted\n");
        }  
    }  
}  
void insertAfter(){  
    int i, loc, item;   
    struct node *ptr, *temp;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL){  
        printf("\nOVERFLOW");  
    } else{  
        printf("\nEnter element value: ");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location after which you want to insert: ");  
        scanf("%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++){  
            temp = temp->next;  
            if(temp == NULL){  
                printf("\ncan't insert\n");  
                return;  
            }  
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        printf("\nNode Inserted\n");  
    }  
}

void insertBefore(){
    int val;
    struct node *newNode, *ptr, *preptr;
    newNode=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the data for new node to be added before a node : ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }else{
        printf("\nEnter the value from list before which new node to insert : ");
        scanf("%d",&val);
        ptr=head;
        while(ptr->data!=val){
            preptr=ptr;
            ptr=ptr->next;
        }
        newNode->next=ptr;
        preptr->next=newNode;
        printf("\nNode Inserted\n"); 
    }
}

void begin_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining\n");  
    }  
}  
void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted\n");  
    }  
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last\n");  
    }     
}  
void random_delete()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion: ");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  

void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nPrinting the list: \n");   
        while (ptr!=NULL) {  
            printf("%d ",ptr->data);  
            ptr = ptr -> next;  
        }
        printf("\n");
    }  
}     
 