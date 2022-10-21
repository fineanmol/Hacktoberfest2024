public class linkedlist {
    Node head;
    private int size;

    linkedlist() {
        this.size = 0;
    }

    class Node {
        String data;
        Node next;
        // Node head;

        Node(String data) {
            this.data = data;
            this.next = null;
            size++;
        }
    }

    public void addFirst(String data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    public void addLast(String data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node lastNode = head;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
        }
        lastNode.next = newNode;
    }

    public void printList() {
        Node currentNode = head;

        while (currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.next;
        }
        System.out.println("null");
    }

    public void removeFirst() {
        if (head == null) {
            System.out.println("list is empty, nothing to delete");
            return;
        }
        size--;

        head = head.next;
    }

    public void removeLast() {
        if (head == null) {
            System.out.println("list is empty, nothing to delete");
            return;
        }
        size--; // doubt

        if (head.next == null) {
            head = null;
            return;
        }

        Node currentNode = head;
        Node lastNode = head.next;

        while (lastNode.next != null) // above condition (head.next == null) has been written because if there is no
                                      // lastNode.next then it will throw error
        {
            currentNode = currentNode.next;
            lastNode = lastNode.next;
        }
        // currentNode.next = null;
        lastNode = null;
    }

    public int getSize() {
        return size;
    }

    public void reverseIterate() {
        if (head == null || head.next == null) {
            return;
        }
        Node prevNode = head;
        Node currNode = head.next;

        while (currNode != null) {
            Node nextNode = currNode.next;
            currNode.next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
        }
        head.next = null;
        head = prevNode;
    }

    public Node reverseRecursive(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        Node newHead = reverseRecursive(head.next);
        head.next.next = head;
        head.next = null;

        return newHead;
    }

    public static void main(String[] args) {
        linkedlist list = new linkedlist();
        list.addFirst("krishna");
        list.printList();
        list.addFirst("hare");
        list.printList();
        list.removeFirst();
        list.printList();
        list.removeLast();
        list.printList();
        list.addLast("hare");
        list.addLast("rama");

        list.printList();
        System.out.println(list.getSize());

        list.reverseIterate();
        list.printList();

        list.head = list.reverseRecursive(list.head);
        list.printList();

    }
}
