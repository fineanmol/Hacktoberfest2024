#include<stdio.h>
struct Node 
{ 
    int data; 
    struct Node *next; 
}*last; 
int addBegin(int data) 
{ 
    if (last == NULL) 
        return addToEmpty(last, data); 
  
    struct Node *temp =  
            (struct Node *)malloc(sizeof(struct Node)); 
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
  
    return 0; 
} 
  
int addEnd(int data) 
{ 
    if (last == NULL) 
        return addToEmpty(last, data); 
      
    struct Node *temp =  
        (struct Node *)malloc(sizeof(struct Node)); 
  
    temp -> data = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    last = temp; 
  
    return 0; 
} 
  
int addAfter(int data, int item) 
{ 
    if (last == NULL) 
        return NULL; 
    struct Node *temp, *p; 
    p = last -> next; 
    do
    { 
        if (p ->data == item) 
        { 
            temp = (struct Node *)malloc(sizeof(struct Node)); 
            temp -> data = data; 
            temp -> next = p -> next; 
            p -> next = temp; 
  
            if (p == last) 
                last = temp; 
            return last; 
        } 
        p = p -> next; 
    }  while(p != last -> next); 
  
    printf(“%d, not present in the list.”,item); 
    return  0; 
  
} 
  
void traverse() 
{ 
    struct Node *p; 
    if (last == NULL) 
    { 
        printf("List is empty."); 
        return; 
    } 
    p = last -> next; 
    do
    { 
      printf(“%d”,p -> data); 
      p = p -> next; 
    } 
    while(p != last->next); 
} 
void main()
{
	char y='y';
	int data,ch;
	printf(“Insert info\n”);
	scanf(“%d”,&data);
	while(y=='y')
	{
		printf(“Menu\n 1. Insert at begining 2. Insert at last 3. At a 	location 4.Display”);
		scanf(“%d”,&ch);
		if(ch==1) addBegin(data); 
		else if(ch==2) addEnd(data)
		else if(ch==3)
		{
			printf(“Enter Position”);
			scanf(”%d”,&pos);
			addAfter(pos,data);
		}
		else if(ch==4) display(); 
		else Printf(“Invalid Choice\n”)
		printf(“Do you want to continue?\n y/n”);
		scanf(“%c”,&y); 
	}
}
  
