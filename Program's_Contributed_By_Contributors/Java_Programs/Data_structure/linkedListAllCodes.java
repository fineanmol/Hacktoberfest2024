public class linkedListAllCodes {

    public static class Node{
        int data;
        Node next;

        public Node(int data){
            this.data = data;
            this.next = null;
        }

    }
    public static Node head;
    public static Node tail;
    public static int size;


    //print Last
    public static void printll(){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    //ADD ELEMENT
    //Add Element At First
    public static void addFirst(int data){

        Node newNode = new Node(data);
        size++;
        if(head == null){
            head = tail = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }
    //Add Element at Last
    public static void addLast(int data){

        Node newNode = new Node(data);
        size++;
        if(head == null){
            head = tail = newNode;
            return;
        }
        tail.next = newNode;
        tail = newNode; 
    }
    //Add in the middle
    public static void add(int idx , int data){
        if(idx == 0){
            addFirst(data);
            return;
        }
        Node newNode = new Node(data);
        size++;       
        Node temp = head;
        int i = 0;
        while(i < idx -1){
            temp = temp.next;
            i++;
        }
        newNode.next = temp.next;
        temp.next = newNode;  
    }

    // REMOVE ELEMENT
    //Remove From First
    public static Node removeFirst(){
        if(size == 0){
            System.out.println("LinkedList is Empty");
            return null;
        }else if(size == 1){
            Node val = head;
            head = tail = null;
            size = 0;
            return val;
        }
        Node val = head;
        head = head.next;
        size--;
        return val;
    }

    //Remove From Last;
    public static Node removeLast(){
        if(size == 0){
            System.out.println("LinkedList is Empty");
            return null;
        }else if(size == 1){
            Node val = tail;
            head = tail = null;
            size = 0;
            return val;
        }

        
        Node temp = head;
        int i = 0;
        while( i < size-2){
            temp = temp.next;
            i++;
        }
        Node val = tail;
        temp.next = null;
        size--;
        return val;
        
    }

    public static int iterativesearch(int key){
        Node temp = head;
        int i = 0;
        while(temp != null){
            if( temp.data == key){
                System.out.print("Key is Found :");
                return i;
            }
            i++;
            temp = temp.next;
        }
        System.out.print("Key is not found : ");
        return -1;
    }
    
    // Reverse Nodes
    public static void reverse(){
        Node prev = null;
        Node curr = head;
        Node next;

        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    //Find and Remove Nth Node From End;
    public static void deleteNthNodeFromEnd(int n){
        // size - n + 1 ===== Nth Node and size- n ===== Previous node of that nth node
        if(n == linkedListAllCodes.size){
            head = head.next;
            return;
        }

        Node prev = head;
        int i = 1;
        while(i < size-n){
            prev = prev.next;
            i++;
        }
        prev.next = prev.next.next;
        return;
    }

    //check palindrome
    //Step 1 : find mid - slow-fast method
    public static Node findmid(Node head){
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    //Step 2 : 2nd half reverse and Step 3 : check left and right
    public static boolean palindrome(){

        //step 2 : second half reverse
        Node midnNode = findmid(head);
        Node prev =null;
        Node curr = midnNode;
        Node next;

        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next; 
        }
        Node right = prev;
        Node left  = head;

        //step 3:
        while(right != null){
            if(left.data != right.data){
                return false;
            }
            left = left.next;
            right = right.next;
        }

        return true;
    }

    public static boolean floydsCycleFinding(){
        Node slow = head;
        Node fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }

    public static void removeCycle(){
       
        //Detect Cycle
        Node slow = head;
        Node fast = head;
        boolean cyclefound = false;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                cyclefound = true;
                break;
            }
        }

        //Remove Cycle
        if(cyclefound == false){
            return;
        }else{
            slow = head;
            Node prev = null;
            while(slow != fast){
                prev = fast;
                slow = slow.next;
                fast = fast.next;

            }
            //remove Cycle
            prev.next  = null;
        }
        

    }



    public static void main(String[] args) {
        
        //LinkedList l1 = new LinkedList();
        //LinkedList<Integer> li = new LinkedList<>();
        //linke li = new linke();
        // addFirst(2);
        // addFirst(1);
        // addLast(2);
        // addLast(1);
        //add(2, 9);
        // printll();
        // removeFirst();
        // removeLast();
        //printll();
        //reverse();
        //printll();
        //System.out.println("Size of LinkedList : " + linke.size);
        //System.out.print(iterativesearch(9));
        // deleteNthNodeFromEnd(1);
        // printll();
        //System.out.println("plaindrome or not : " + palindrome());

        //Floyds Cycle Find Linkedlist
        head = new Node(1);
        Node temp = new Node(2);
        head.next = temp;
        head.next.next = new Node(3);
        head.next.next.next = temp;
        System.out.println( " Detect Loop true or false : " + floydsCycleFinding());      
        
        removeCycle();
        System.out.println(floydsCycleFinding());

        

    }
}
