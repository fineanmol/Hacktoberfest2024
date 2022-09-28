#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *rear;
    int data;
    struct node *front;

};
struct head{
    unsigned int count;
    struct node *front;
};
void create();
void display();
void insertBegin();

int main()
{
    int choice;
    struct head *head;
    head=(struct head *)malloc(sizeof(struct head));
    head->count=0;
    head->front=NULL;
    while(1){
        printf("----------------------------------\n");
        printf("1: Create\n2: Insert\n3: Delete\n4: Noel\n5: isEmpty\n6: Display\n");
        scanf("%d", &choice);
        switch(choice){
            case 1/*create*/:{
                int data;
                printf("Enter data you want to give to the beginning node: ");
                scanf("%d", &data);
                create(head, data);
                break;
            }
            case 2/*insert*/:{
                int choiceI;
                printf("1: Insert At Beginning\n2: Insert At Pos\n3: Insert At End\n");
                scanf("%d", &choiceI);
                switch(choiceI){
                    case 1:{
                        int data;
                        printf("Enter data you want to enter at beginning: ");
                        scanf("%d", &data);
                        insertBegin(head, data);
                        printf("Element is added\n");
                        break;
                    }
                    case 2:{
                        break;
                    }
                    case 3:{
                        break;
                    }

                }
                break;
            }
            case 3/*delete*/:{
                break;
            }
            case 4/*noel*/:{
                break;
            }
            case 5/*isempty*/:{
                break;
            }
            case 6/*display*/:{
                display(head);
                break;
            }
            default :{
                //exit(0);
            }

        }
    }
    return 0;
}

void create (struct head *head,int data){
    if(head->count!=0){
        head->count=0;
        struct node *ptr;
        ptr=head->front;
        do{
            ptr=ptr->front;
            free(ptr->rear);
        }while(head->front!=ptr);
        head->front=NULL;
    }
    struct node * node;
    node=(struct node *)malloc(sizeof(struct node));
    head->front=node;
    head->count++;
    node->data=data;
    node->front=node;
    node->rear=node;
}

void display(struct head *head){
    struct node * ptr;
    ptr=head->front;
    do{
        printf("%x\t%d  %x\n",ptr->rear, ptr->data, ptr->front);
    }while(head->front!=ptr);
}

void insertBegin(struct head *head,int data){
    struct node *ptr;
    ptr=(struct ptr *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->front=head->front;
    ptr->rear=head->front->rear;
    head->front=ptr;
}
