class HeapSort  
{  
/* function to heapify a subtree. Here 'i' is the   
index of root node in array a[], and 'n' is the size of heap. */   
static void heapify(int a[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  
/*Function to implement the heap sort*/  
static void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        /* Move current root element to end*/  
        // swap a[0] with a[i]  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}  
/* function to print the array elements */  
static void printArr(int a[], int n)  
{  
    for (int i = 0; i < n; ++i)  
        System.out.print(a[i] + " ");  
}  
public static void main(String args[])   
{  
    int a[] = {45, 7, 20, 40, 25, 23, -2};  
    int n = a.length;  
    System.out.print("Before sorting array elements are - \n");  
    printArr(a, n);  
    heapSort(a, n);  
    System.out.print("\nAfter sorting array elements are - \n");  
    printArr(a, n);  
}  
}  
