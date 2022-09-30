package LinkedLists;

public class LinkedList {
    private int length;
    public LinkedList(){
        this.length = 0;
    }
    Node head;

    public Node getHead(){
        return this.head;
    }

    public void insertAtStart(Node node){
        node.next = head;
        head = node;
        length++;
    }

    public void insertAtEnd(Node node){
        // if list is empty
        if (head == null) head = node;
        else{
            // if
            Node curr = head;
            while (curr.next != null){
                curr = curr.next;
            }
            curr.next = node;
            node.next = null;
            length++;
        }

    }

    public void insert(Node node, int pos){
        if (pos > this.length) pos = this.length;
        if (pos < 0) pos = 0;
        if (head == null){
            head = node;
        } else if (pos == 0){
            node.next = head;
            head = node;
        } else {
            Node curr = head;
            for (int i = 1; i < pos; i++) {
                curr = curr.next;
            }
            Node tmp = curr.next;
            curr.next = node;
            node.next = tmp;
        }
        length++;
    }

    public void insertRec(int data, int idx, Node prev){
        if (idx == 0){
            Node node = new Node(data);
            node.next = head;
            head = node;
            length++;
            return;
        }
        if (idx == 1){
            Node node = new Node(data);
            Node tmp = prev.next;
            prev.next = node;
            node.next = tmp;
            length++;
            return;
        }
        insertRec(data, idx-1, prev.next);
    }

    public Node removeFromFirst(){
        Node node = head;
        if (node != null){
            head = node.next;
            node.next = null;
            length--;
        }
        return node;
    }

    public Node removeFromEnd(){
        if (head == null) return null;
        Node curr = head;
        Node p = head;
        while (curr.next != null){
            p = curr;
            curr = curr.next;
        }
        p.next = null;
        length--;
        return curr;
    }

    public Node delete(int pos){
        if (head==null) return head;
        if (pos == 0){
            Node tmp = head;
            head = tmp.next;
            length--;
            return tmp;
        }
        Node curr = head;
        for (int i = 1; i < pos; i++) {
            curr = curr.next;
        }
        Node tmp = curr.next;
        curr.next = tmp.next;
        length--;
        return tmp;
    }

    public void display(){
        Node curr = head;
        if (curr == null) System.out.println("List is Empty");
        else {
            while (curr != null){
                System.out.print(curr.getData() + " -> ");
                curr = curr.next;
            }
            System.out.print(" Null \n");
        }
    }
    //this function temporarialy reverses linkedlist
    public void reverseDisplay(Node node){
        if (node ==null) return;
        reverseDisplay(node.next);
        System.out.print(node.getData() + "-->");
    }

    // this function permanently reverse the likedlist
    public void reverse(){
        Node p = null;
        Node curr = head;
        Node next;
        while (curr != null){
            next = curr.next;
            curr.next = p;
            p = curr;
            curr = next;
        }
        head = p;
    }

    public int getLength(){
       return length;
    }
}

