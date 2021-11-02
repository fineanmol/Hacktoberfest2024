#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;//
}*head;

void insertq(int a[],int m){
    struct node *temp,*newnode;
    head=(struct node*)malloc(sizeof(struct node));//

    head->data=a[0];
    head->next=NULL;

   // temp=(struct node*)malloc(sizeof(struct node));;
    temp=head;
    //head->next=temp;

    for(int i=1;i<m;i++){
       newnode = (struct node*)malloc(sizeof(struct node));//
        newnode->data=a[i];
        newnode->next=NULL;

        temp->next=newnode;
       // newnode=newnode->next;
        temp=newnode;
    }


}
void printq(struct node *head){

    struct node*temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}


int sumOfLastN_Nodes(struct node* head, int n)
{
      // Code here
      if(n<=0)
        return 0;
      struct node*temp = head;
      int m=0,sum=0;
      while(temp!=NULL){
          m++;
          temp=temp->next;
      }
    cout<<"m...."<<m<<endl;
     temp = head;
      for(int pos=1;pos<m-n+1;pos++){
          temp=temp->next;
          cout<<"head\n"<<"....."<<temp->data<<endl;
      }

      while(temp!=NULL){
          sum+=temp->data;
          cout<<"sum  here,,,"<<sum<<endl;
          temp=temp->next;
      }
      cout<<"sum\n"<<"....."<<sum<<endl;
      return sum;
}


int main(){

    int m;
    cout<<"enter size\n";
    cin>>m;
    int a[m];
    cout<<"enter elements\n";
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    cout<<"enter nth\n";
    int n;
    cin>>n;
    cout<<"calling insert....\n";
    insertq(a,m);
    cout<<"calling print....\n";
    printq(head);
    int res=sumOfLastN_Nodes(head,n);
    cout<<"print sum....\n"<<res;
return 0;
}

