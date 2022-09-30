package LinkedLists;

public class testing {
    public static void main(String[] args) {
//        DoublyLinkedLIst dll = new DoublyLinkedLIst();
//        dll.insertAtFirst(1);
//        dll.insertAtFirst(2);
//        dll.insertAtFirst(3);
//        dll.insertAtLast(4);
//        dll.insert(5,0);
//        dll.display();
//        dll.delete(0);
//        dll.delete(3);
//        dll.delete(1);
//        dll.display();
            CircularLinkedList cll = new CircularLinkedList();
            cll.insertAtFirst(40);
            cll.insertAtFirst(10);
            cll.insertAtFirst(20);
            cll.insertAtLast(5);
            cll.insertAtLast(8);
            cll.insertAtFirst(80);
            cll.insertAtFirst(90);
//            cll.display();
//            System.out.println(cll.removeFromFirst());
//        System.out.println(cll.removeFromLast());
//            cll.display();
//            System.out.println(cll.length);
//
//        LinkedList ll = new LinkedList();
//        ll.insertAtStart(new Node(1));
////        ll.insertAtStart(new Node(9));
////        ll.insertAtStart(new Node(5));
////        ll.insertAtStart(new Node(3));
//        ll.insertRec(7, 1, ll.getHead());
//        ll.display();
//        System.out.println(ll.getLength());
        System.out.println(cll.getCycleLen());

    }
}
