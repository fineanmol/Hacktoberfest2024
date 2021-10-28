public class LinkedList {

    public Node head = new Node();

    public Node getHead() {
        return head;
    }

    public void setHead(Node head) {
        this.head = head;
    }

    class Node {
        private int value;
        private Node next;

        public int getValue() {
            return value;
        }

        public void setValue(int value) {
            this.value = value;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node next) {
            this.next = next;
        }

        public Node(int value, Node next){
            this.value = value;
            this.next = next;
        }

        public Node(int value){
            this.value = value;
        }

        public Node(){}
    }
}
