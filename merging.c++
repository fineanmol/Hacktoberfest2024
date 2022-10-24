#include <iostream>
#include <new>
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;
struct node {
   int data;
   struct node *next;
};
node *createList(int *arr, int n){
   node *head, *p;
   p = head = new node;
   head->data = arr[0];
   head->next = NULL;
   for (int i = 1; i < n; ++i) {
      p->next = new node;
      p = p->next;
      p->data = arr[i];
      p->next = NULL;
   }
return head;
}
void displayList(node *head){
   while (head != NULL) {
      cout << head->data << " ";
      head = head->next;
   }
   cout << endl;
}
node *mergeSortedLists(node *head1, node *head2){
   node *result = NULL;
   if (head1 == NULL) {
      return head2;
   }
   if (head2 == NULL) {
      return head1;
   }
   if (head1->data < head2->data) {
      result = head1;
      result->next = mergeSortedLists(head1->next, head2);
   } else {
      result = head2;
      result->next = mergeSortedLists(head1, head2->next);
   }
   return result;
}
int main(){
   int arr1[] = {10, 15, 17, 20};
   int arr2[] = {5, 9, 13, 19};
   node *head1, *head2, *result = NULL;
   head1 = createList(arr1, SIZE(arr1));
   head2 = createList(arr2, SIZE(arr1));
   cout << "First sorted list: " << endl;
   displayList(head1);
   cout << "Second sorted list: " << endl;
   displayList(head2);
   result = mergeSortedLists(head1, head2);
   cout << "Final sorted list: " << endl;
   displayList(result);
   return 0;
}
