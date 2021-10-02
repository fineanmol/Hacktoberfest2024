public class MyMergeSort  
{  
void merge(int arr[], int beg, int mid, int end)  
{  
  
int l = mid - beg + 1;  
int r = end - mid;  
  
intLeftArray[] = new int [l];  
intRightArray[] = new int [r];  
  
for (int i=0; i<l; ++i)  
LeftArray[i] = arr[beg + i];  
  
for (int j=0; j<r; ++j)  
RightArray[j] = arr[mid + 1+ j];  
  
  
int i = 0, j = 0;  
int k = beg;  
while (i<l&&j<r)  
{  
if (LeftArray[i] <= RightArray[j])  
{  
arr[k] = LeftArray[i];  
i++;  
}  
else  
{  
arr[k] = RightArray[j];  
j++;  
}  
k++;  
}  
while (i<l)  
{  
arr[k] = LeftArray[i];  
i++;  
k++;  
}  
  
while (j<r)  
{  
arr[k] = RightArray[j];  
j++;  
k++;  
}  
}  
  
void sort(int arr[], int beg, int end)  
{  
if (beg<end)  
{  
int mid = (beg+end)/2;  
sort(arr, beg, mid);  
sort(arr , mid+1, end);  
merge(arr, beg, mid, end);  
}  
}  
public static void main(String args[])  
{  
intarr[] = {90,23,101,45,65,23,67,89,34,23};  
MyMergeSort ob = new MyMergeSort();  
ob.sort(arr, 0, arr.length-1);  
  
System.out.println("\nSorted array");  
for(int i =0; i<arr.length;i++)  
{  
    System.out.println(arr[i]+"");  
}  
}  
} 
