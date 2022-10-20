#include <stdio.h>
#include <stdlib.h>
typedef struct node{
 int data;
 struct node *link;
} nd;
nd *start;
void insert_front(){
 nd *temp;
 temp=(nd*)malloc(sizeof(nd));
 printf(" Enter the data : ");
 scanf("%d",&temp->data);
 temp->link=start;
 start=temp;
}
int count(){
 nd *ptr;
 ptr=start;
 int c=1;
 while(ptr!=NULL){
 ptr=ptr->link;
 c++;
 }
 return c;
}
void insert_last(){
 nd *temp;
 temp=(nd*)malloc(sizeof(nd));
 printf(" Enter the data : "); 
 scanf("%d",&temp->data);
 if(start==NULL){
 start=temp;
 temp->link=NULL;
 }
 else{
 nd *ptr;
 ptr=start;
 while(ptr->link!=NULL){
 ptr=ptr->link;
 }

 ptr->link=temp;
 temp->link=NULL;
 }
}
void insert_middle(){
 if(start==NULL)
 printf("\n E M P T Y");
 else{
 int f=count(); //3
 int pos;
 printf(" Enter the position : ");
 scanf("%d",&pos);
 if(pos<f){
 nd *ptr;
 ptr=start;
 int c=1;
 while(ptr!=NULL){
 if(c==pos-1) //3
 break;
 ptr=ptr->link;
 c++;
 } 
 nd *temp;
 temp=(nd*)malloc(sizeof(nd));
 printf(" Enter the data : ");
 scanf("%d",&temp->data);
 temp->link=ptr->link;
 ptr->link=temp;
 }
 else
 printf(" Position not available ");
 }

}
void search(){
 if(start==NULL)
 printf("\n E M P T Y");
 else{
 int f=count();
 int search;
 printf(" Enter the search element : ");
 scanf("%d",&search);
 nd *ptr;
 ptr=start;
 int c=1;
 while(ptr!=NULL){
 if(ptr->data==search)
 break;
 ptr=ptr->link;
 c++;
 }
 if(c<(f))
 printf("\n Element Found at : %d",c);
 else
 printf("\n Element not found");
 } 
}
void delete_middle(){
 if(start==NULL)
 printf("\n E M P T Y");
 else{
 int f=count();
 int i;
 printf(" Enter index : ");
 scanf("%d",&i);
 if(i==1){
 printf("\n Delete Element : %d",start->data);
 start=start->link;
 }
 else if(i<f){
 nd *ptr;
 ptr=start;
 int c=1;
 while(ptr!=NULL){
 if(c+1==i)
 break;
 ptr=ptr->link;
 c++;
 }
 printf("\n Delete Element : %d",ptr->link-
>data);
 ptr->link=ptr->link->link;
 }
 else
 printf("\n Index Unavailable ");
 }
} 
void delete_first(){
 if(start==NULL)
 printf("\n U N D E R F L O W");
 else
 {
 printf("\n Delete Element : %d",start->data);
 start=start->link;
 }
}
void display(){
 if(start==NULL)
 printf("\n E M P T Y");
 else{
 nd *ptr;
 ptr=start;
 int c=1;
 while(ptr!=NULL){
 printf("\n Element %d : %d",c++,ptr->data);
 ptr=ptr->link;
 }
 }
}
void delete_end(){
 if(start==NULL)
 printf("\n U N D E R F L O W");
 else{
 nd *ptr;
 ptr=start;
 while(ptr->link->link!=NULL){
 ptr=ptr->link;
 }
 printf("\n Delete Element : %d",ptr->link->data); 
 ptr->link=NULL;
 }
}
int main()
{
 int ch;
 start=NULL;
 while(1)
 {
 printf("\n\n 1 for Insert Front");
 printf("\n 2 for Insert Last");
 printf("\n 3 for Insert Middle");
 printf("\n 4 for Search Element");
 printf("\n 5 for Delete First ");
 printf("\n 6 for Delete at Index ");
 printf("\n 7 for Delete Last ");
 printf("\n 8 for Display ");
 printf("\n 9 for Exit ");
 printf("\n Enter the choice : ");
 scanf("%d",&ch);

 switch(ch)
 {
 case 1:
 insert_front();
 break;

 case 2:
 insert_last();
 break;
 case 3:
 insert_middle();
 break; 
 case 4:
 search();
 break;

 case 5:
 delete_first();
 break;
 case 6:delete_middle();
 break;
 case 7:
 delete_end();
 break;
 case 8:
 display();
 break;
 case 9:
 exit(1);
 }
 }
 return 0;
}
