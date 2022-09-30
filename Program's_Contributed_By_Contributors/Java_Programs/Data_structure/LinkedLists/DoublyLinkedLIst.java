package LinkedLists;

public class DoublyLinkedLIst {
    private static class Node{
        int data;
        Node prev;
        Node next;

        public Node(int data){
            this.data = data;
        }
        public Node(int data, Node prev, Node next){
            this.data = data;
            this.prev = prev;
            this.next = next;
        }
    }

    private Node head;
    private int length;

    public DoublyLinkedLIst(){
        this.length = 0;
    }

    public void insertAtFirst(int data){
        Node node = new Node(data);
        if(head == null){
            head = node;
            length++;
            return;
        }
        node.next = head;
        head.prev = node;
        head = node;
        length++;
    }

    public void insertAtLast(int data){
        Node node = new Node(data);
        if (head == null){
            head = node;
            length++;
            return;
        }

        // curr will stop at last node of linked list
        Node curr = head;
        while (curr.next != null){
            curr = curr.next;
        }
        curr.next = node;
        node.prev = curr;
        length++;
    }

    public void insert(int data, int pos){
        Node node = new Node(data);
        if (pos == 0){
            insertAtFirst(data);
            return;
        }
        if (pos == length){
            insertAtLast(data);
            return;
        }
        Node curr = head;
        for (int i = 1; i < pos; i++) {
            curr = curr.next;
        }
        node.next = curr.next;
        if (node.next.prev != null){
            node.next.prev = node;
        }
        curr.next = node;
        node.prev = curr;
        length++;
    }

    // returns removed node.data
    public int removeFromStart(){
        int tmp = head.data;
        head = head.next;
        if (head != null){
            head.prev = null;
        }
        length--;
        return tmp;
    }

    public int removeFromLast(){
        Node curr = head;
        while (curr.next != null){
            curr = curr.next;
        }
        int tmp = curr.data;
        if (curr.prev == null){
            head = null;
            length--;
            return tmp;
        }
        curr.prev.next = null;
        curr.prev = null;
        length--;
        return tmp;
    }

    public int delete(int index){
        if (index == 0){
            return removeFromStart();
        }
        if (index == length-1){
            return removeFromLast();
        }

        Node curr = head;
        for (int i = 1; i <=index; i++) {
            curr = curr.next;
        }
        int tmp = curr.data;
        curr.prev.next = curr.next;
        curr.next.prev = curr.prev;
        curr.next = null;
        curr.prev = null;
        length--;
        return tmp;
    }

    public void display(){
        Node curr = head;
        while (curr != null){
            System.out.print(curr.data + " --> ");
            curr = curr.next;
        }
        System.out.print("NULL");
        System.out.println();
    }
}
