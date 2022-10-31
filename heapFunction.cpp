#include<iostream>
using namespace std;

class heap{
    public:
    int arr[10001];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insertInHeap(int val)
    {
        size += 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else 
                return;
        }

    }

    void deleteInHeap()
    {
        //check if heap is already empty or not
        if(size == 0){
            cout<< "Nothing to delete in heap " << endl;
            return;
        }

        //Step1 Put last element in firstindex
        arr[1] = arr[size];

        //step2 remove last element
        size--;
        
        //step3 take root node to its correct position
        int i = 1;
        while(i <= size){
            int leftchild = 2*i;
            int rightchild = 2*i +1;

            if(leftchild <=size && arr[leftchild] > arr[i]){
                swap(arr[leftchild], arr[i]);
                i = leftchild;
            }
            else if(rightchild <=size && arr[rightchild] > arr[i]){
                swap(arr[rightchild], arr[i]);
                i = rightchild;
            }
            else 
                return;
        }


    }

    void print()
    {
        for(int i = 1; i <= size; i++)
            cout<<arr[i]<<" ";

        cout<<endl;
    }

};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    if(leftChild <= n && arr[leftChild] > arr[largest] ){
        largest = leftChild;
    }
    if(rightChild <= n && arr[rightChild] > arr[largest] ){
        largest = rightChild;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int size){

    while(size > 1){
        //step1 swap
        swap(arr[size], arr[1]);
        size--;
        //step2 implent heapify to create maxheap
        heapify(arr,size,1);
    }

}

int main()
{
    heap h;
    h.insertInHeap(5);
    h.insertInHeap(8);
    h.insertInHeap(7);
    h.insertInHeap(4);
    h.insertInHeap(2);
    h.insertInHeap(9);
    h.insertInHeap(3);

    cout<<"insertion in heap"<<endl;
    h.print();

    h.deleteInHeap();
    cout<<"deletion in heap"<<endl;
    h.print();

    int arr[6] = {-1, 5,4,3,7,9};
    int n = 5;
    for(int i = n/2; i > 0; i--)
        heapify(arr,n,i);

    cout<<"Printing the heapify function "<<endl;
    for(int i = 1; i <= n; i++)
            cout<<arr[i]<<" ";

    cout<<endl;

    heapSort(arr, n);
    cout<<"Printing the heapSort function "<<endl;
    for(int i = 1; i <= n; i++)
            cout<<arr[i]<<" ";

    cout<<endl;
    return 0;

}
