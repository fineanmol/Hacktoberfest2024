#include <iostream>
using namespace std;
int findMin(int arr[], int i, int j){
   int minpos;
   if (i == j){
      return i;
   }
   minpos = findMin(arr, i + 1, j);
   if(arr[i]<arr[minpos]){
      minpos=i;
   }
   return (minpos);
}
void recurselectSort(int arr1[], int len1, int pos1){
   int temp;
   int minpos1;
   if (pos1 == len1){
      return;
   }
   minpos1 = findMin(arr1, pos1, len1-1);
   if (minpos1 != pos1){
      temp=arr1[pos1];
      arr1[pos1]=arr1[minpos1];
      arr1[minpos1]=temp;
   }
   recurselectSort(arr1, len1, pos1 + 1);
}
int main(){
   int Arr[] = {1,5,3,0,9,3,5};
   int length = sizeof(Arr)/sizeof(Arr[0]);
   recurselectSort(Arr,length,0);
   cout<<"Sorted Array using recursive Selection sort: "<<endl;
   for (int i = 0; i<length ; i++){
      cout << Arr[i] << " ";
   }
   return 0;
}