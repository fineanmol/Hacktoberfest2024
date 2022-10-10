class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

const node = new Node(100);
class LinkedList {
  constructor() {
    this.head = null;
    this.size = 0;
  }

  // Insert first node
  insertFirst(data) {
    this.head = new Node(data, this.head);
    this.size++;
  }

  // Insert last node
  insertLast(data) {
    let node = new Node(data);
    let current;

    // If empty, make head
    if (!this.head) {
      this.head = node;
    } else {
      current = this.head;

      // Iterating until next field of node is null
      while (current.next) {
        // traverse through the list
        current = current.next;
      }

      // Add new node to next field of last node of linked list
      current.next = node;
    }
    this.size++;
  }

  // Insert at index
  insertAt(data, index) {
    // If index is out of range
    if (index > 0 && index > this.size) {
      return;
    }
    // If first index
    if (index === 0) {
      this.head = new Node(data, this.head);
      return;
    }
    const node = new Node(data);
    let current, previous;

    // Set current to first
    current = this.head;

    let count = 0;
    while (count < index) {
      previous = current; // Node before the index to insert
      count++;
      current = current.next; // Node after the index
    }
    node.next = current;
    previous.next = node;

    this.size++;
  }
  // Get at index
  retrieveAt(index) {
    let count = 0;
    let current = this.head;
    while (current) {
      if (count === index) {
        console.log(current.data);
      }
      current = current.next;
      count++;
    }
    return null;
  }

  // Get first data
  getFirst() {
    let current = this.head;
    if (!current) return;
    console.log(current.data);
    return current.data;
  }

  // Get last data
  getLast() {
    let current = this.head;
    if (!current) return;
    while (current.next) {
      current = current.next;
    }
    console.log(current.data);
    return current.data;
  }
  // Delete first node
  removeFirst() {
    let current = this.head;
    if (!current) return;
    this.head = current.next;
  }

  // Delete last node
  removeLast() {
    let current = this.head;
    let previous;
    if (!current) return;
    while (current.next) {
      previous = current;
      current = current.next;
    }
    previous.next = null;
  }

  // Remove at index
  removeAt(index) {
    if (index > 0 && index > this.size) return;
    let current = this.head;
    let previous;
    let count = 0;
    // Remove first
    if (index === 0) {
      this.head = current.next;
    } else {
      while (count < index) {
        count++;
        previous = current;
        current = current.next;
      }
      previous.next = current.next;
    }
    this.size--;
  }

  // Clear list
  clearList() {
    this.head = null;
    this.size = 0;
  }

  // Pring list data
  printListData() {
    let current = this.head;
    while (current) {
      console.log(current.data);
      current = current.next;
    }
  }
}

const linkedList = new LinkedList();

linkedList.insertFirst(100);
linkedList.insertFirst(200);
linkedList.insertLast(300);
linkedList.insertAt(500, 2);

linkedList.printListData();
// 200
// 100
// 500
// 300
console.log("---------");
linkedList.retrieveAt(1);
//100
console.log("---------");
linkedList.removeAt(1);

linkedList.printListData();
// 200
// 500
// 300
console.log("---------");
linkedList.clearList(); // Delete all the nodes

linkedList.printListData();
// nothing
linkedList.insertFirst(200);
linkedList.insertFirst(300);

linkedList.getFirst();
// 300
console.log("---------");

linkedList.getLast();
// 200
console.log("---------");

linkedList.printListData();
// 300
// 200

console.log("---------");
linkedList.removeFirst();

linkedList.printListData();

console.log("---------");

linkedList.insertFirst(500);
linkedList.printListData();
// 500
// 200
console.log("---------");

linkedList.removeLast();
linkedList.printListData();
// 500
