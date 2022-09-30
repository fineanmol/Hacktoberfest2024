package LinkedLists;

public class CircularLinkedList {
    private class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
        }
    }

    Node head;
    Node tail;
    int length;
    public CircularLinkedList(){
        length = 0;
    }

    public void insertAtFirst(int data){
        Node node = new Node(data);
        if (head == null){
            head = node;
            tail = node;
            tail.next = head;
            length++;
            return;
        }
        node.next = head;
        head = node;
        tail.next = head;
        length++;
    }

    public void insertAtLast(int data){
        Node node = new Node(data);
        if (head==null){
            head = node;
            tail = node;
            tail.next = head;
            length++;
            return;
        }
        tail.next = node;
        node.next = head;
        tail = node;
        length++;
    }

    public int removeFromFirst(){
        int tmp = head.data;
        if (tail == head){
            tail = null;
            head = null;
            length--;
            return tmp;
        }
        head = head.next;
        tail.next = head;
        length--;
        return tmp;
    }

    public int removeFromLast(){
        int tmp = tail.data;
        if (tail == head){
            tail = null;
            head = null;
            length--;
            return tmp;
        }
        Node curr = head;
        while (curr.next != tail){
            curr = curr.next;
        }
        curr.next = head;
        tail = curr;
        length--;
        return tmp;
    }

    public int getTail(){
        return tail.data;
    }

    public int getCycleLen(){
        Node slow = head;
        Node fast = head;
        int len = 0;
        while (fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if (fast == slow) break;
        }
        do {
            slow = slow.next;
            len++;
        } while (slow != fast);
        return len;
    }

    public void display(){
        Node curr = head;
        if (head != null){
            do {
                System.out.print(curr.data + " --> ");
                curr = curr.next;
            } while (curr != head);
        }
        System.out.print("TAIL");
        System.out.println();
    }

}
