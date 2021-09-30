public class BinaryHeapMaxPQ<Key extends Comparable<Key>> {
    
    //Binary tree array representing the heap
    private Key[] heap;
    
    //Number of elements on heap
    private int size;
    
    //Initialize the heap
    public BinaryHeapMaxPQ() {
        heap = (Key[]) new Comparable[2];
        size = 0;
    }

    //Add and sort an element into the correct place in the priority queue
    public void insert(Key key) {
        
        //Valid key?
        if (key == null)
            throw new IllegalArgumentException();
            
        //Double size of array if overflow
        if (size + 1 >= heap.length)
            resize(heap.length * 2);
            
        //Add key to last available child of last level of heap, 
        //swap it up until it fits heap condition
        heap[size + 1] = key;
        swim(size + 1);
        size++;
    }

    //Remove the largest element from the priority queue
    public Key delMax() {
        
        //Does the queue have elements to remove?
        if (isEmpty())
            throw new IllegalStateException();
        
        //Halve size of array if operation shrinks heap to 1/4 of array size
        if (size - 1 < heap.length / 4)
            resize(heap.length / 2);
        
        //Replace the old max element (located at root node) with last child of last level of heap, 
        //then swap it down with largest child until it fits heap condition 
        Key oldMax = heap[1];
        heap[1] = heap[size];
        heap[size] = null;
        sink(1);
        
        size--;
        return oldMax;
    }

    //Get the max element of the priority queue, always located at root node
    public Key max() {
        
        //Are there any elements in the queue?
        if (isEmpty())
            throw new IllegalStateException();
        
        //Return root node of heap
        return heap[1];
    }

    //Is the queue empty?
    public boolean isEmpty() {
        return size == 0;
    }

    //How many elements does the queue have?
    public int size() {
        return size;
    }

    //Change size of the binary tree array that holds heap
    private void resize(int capacity) {
        
        //Create new array with different size
        Key[] newHeap = (Key[]) new Comparable[capacity];
        
        //Copy over elements until either the end of the old array or the capacity is reached
        for (int i = 0; i < capacity && i < heap.length; i++) {
            newHeap[i] = heap[i];
        }
        
        heap = newHeap;
    }

    //Swap an element with its children until it satisfies the heap condition
    private void sink(int k) {
        
        int targetchild;
        int leftchild = 2 * k;
        int rightchild = 2 * k + 1;
        
        //Make sure the element and its children CAN exist
        if (k >= heap.length || leftchild >= heap.length)
            return;
            
        //Make sure the element has existing children to swap itself with
        if (heap[leftchild] == null && heap[rightchild] == null)
            return;
        
        //Decide which child to swap with: if one is null use the other, if both exist compare and pick largest
        if (heap[leftchild] == null) {
            targetchild = rightchild;
        } else if (heap[rightchild] == null) {
            targetchild = leftchild;
        } else {
            targetchild = heap[leftchild].compareTo(heap[rightchild]) > 0 ? leftchild : rightchild; 
        }
        
        //Swap the element with the selected child if it is smaller, continue recursion
        if (heap[k].compareTo(heap[targetchild]) < 0) {
            exch(k, targetchild);
            sink(targetchild);
        }
    }

    //Swap an element with its parent until it satisfies heap condition
    private void swim(int k) {
        int parent = k / 2;
        
        //Make sure the element exists in the heap, if it does so does its parent
        if (k < 0 || k >= heap.length)
            return;
        
        //Swap the element with its parent if the element is greater, continue recursion
        if (parent > 0 && heap[k].compareTo(heap[parent]) > 0) {
            exch(k, parent);
            swim(parent);
        }
    }

    //Exchange two elements in the heap
    private void exch(int i, int j) {
        Key temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
}
