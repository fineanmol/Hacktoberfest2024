/**
 * QUICK SORT
 * Complexity
 * Best: O(n * log n)
 * Worst: O(n^2)
 * Average: O(n * log n)
 * 
 * @param {Array} items
 * @param {Number} left
 * @param {Number} right
 * @returns {Array} sorted items
 */
 const quickSort = (items, left, right) => {
    let index;

    const swap = (items, leftIndex, rightIndex) => {
        const temp = items[leftIndex];
        items[leftIndex] = items[rightIndex];
        items[rightIndex] = temp;
    }

    const partition = (items, left, right) => {
        let pivot = items[Math.floor((right + left) / 2)],
            i = left,
            j = right;

        while (i <= j) {
            while (items[i] < pivot) {
                i++;
            }
            while (items[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(items, i, j);
                i++;
                j--;
            }
        }
        return i;
    }

    if (items.length > 1) {
        index = partition(items, left, right);
        if (left < index - 1) {
            quickSort(items, left, index - 1);
        }
        if (index < right) {
            quickSort(items, index, right);
        }
    }
    return items;
}

/**
 * BUBBLE SORT
 * Complexity
 * Best: O(n)
 * Worst: O(n^2)
 * Average: O(n^2)
 * 
 * @param {Array} items 
 * @returns {Array} sorted items
 */
const bubbleSort = (items) => {
    for (let i = 0; i <= items.length; i++) {
        for (let j = 0; j <= items.length - i; j++) {
            if (items[j] > items[j + 1]) {
                const temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp
            }
        }
    }

    return items;
}

/**
 * MERGE SORT
 * Complexity
 * Best: O(n * log n)
 * Worst: O(n * log n)
 * Average: O(n * log n)
 * 
 * @param {Array} items 
 * @returns {Array} sorted items
 */
const mergeSort = (items) => {
    if (items.length > 1) {
        const r = Math.floor(items.length / 2);
        let L = [];
        let M = [];
        items.forEach((item, index) => {
            if (index <= r) {
                L.push(item);
            }
            if (index > r) {
                M.push(item);
            }
        })

        let i, j, k = 0;

        while (i < L.length && j < M.length) {
            if (L[i] < M[j]) {
                items[k] = L[i]
                i += 1
            } else {
                items[k] = M[j]
                j += 1
            }
            k += 1
        }

        while (i < L.length) {
            items[k] = L[i]
            i += 1
            k += 1
        }

        while (j < M.length) {
            items[k] = M[j]
            j += 1
            k += 1
        }
    }

    return items;
}

class MaxHeap {
    constructor() {
        this.heap = [];
    }

    parentIndex(index) {
        return Math.floor((index - 1) / 2);
    }

    leftChildIndex(index) {
        return (2 * index + 1);
    }

    rightChildIndex(index) {
        return (2 * index + 2);
    }

    swap(a, b) {
        let temp = this.heap[a];
        this.heap[a] = this.heap[b];
        this.heap[b] = temp;
    }

    insert(item) {
        this.heap.push(item);
        let index = this.heap.length - 1;
        let parent = this.parentIndex(index);
        while (this.heap[parent] && this.heap[parent] < this.heap[index]) {
            this.swap(parent, index);
            index = this.parentIndex(index);
            parent = this.parentIndex(index);
        }
    }

    delete() {
        let item = this.heap.shift();
        this.heap.unshift(this.heap.pop());
        let index = 0;
        let leftChild = this.leftChildIndex(index);
        let rightChild = this.rightChildIndex(index);

        while(this.heap[leftChild] && this.heap[leftChild] > this.heap[index] || this.heap[rightChild] > this.heap[index]){
            let max = leftChild;

            if(this.heap[rightChild] && this.heap[rightChild] > this.heap[max]){
                max = rightChild
            }

            this.swap(max, index);
            index = max;
            leftChild = this.leftChildIndex(max);
            rightChild = this.rightChildIndex(max);
        }
        return item;
    }
}

/**
 * HEAP SORT
 * Complexity
 * Best: O(n * log n)
 * Worst: O(n * log n)
 * Average: O(n * log n)
 * 
 * @param {Array} items 
 * @returns {Array} sorted items
 */
const heapSort = (items) => {
    let sorted = [];
    let heap1 = new MaxHeap();
    
    for(let i = 0; i < items.length; i++){
        heap1.insert(items[i]);
    }
    
    for(let i = 0; i < items.length; i++){
        sorted.push(heap1.delete());
    }
    return sorted.reverse();
}

const itemsToBeSorted = [3, 7, 1, 9, 4, 2];
const size = itemsToBeSorted.length - 1;

console.log(`QuickSort - ${quickSort(itemsToBeSorted, 0, size)}`);
console.log(`BubbleSort - ${bubbleSort(itemsToBeSorted, size)}`);
console.log(`MergeSort - ${mergeSort(itemsToBeSorted)}`);
console.log(`HeapSort - ${heapSort(itemsToBeSorted)}`);
