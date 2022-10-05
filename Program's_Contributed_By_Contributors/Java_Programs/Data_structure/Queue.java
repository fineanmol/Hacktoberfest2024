class Queuelink{
    int data;
    Queuelink front,rear,next;
    Queuelink(){
        front=null;
        rear=null;
        next=null;
    }
    Queuelink(int data){
        this.data=data;
        front=null;
        rear=null;
        next=null;
    }

    void enque(int data){
        Queuelink n=new Queuelink(data);
        if(front==null && rear==null){
            front=n;
            rear=front;
        }
        else{
            rear.next=n;
            rear=n;
        }
    }

    void dequeue(){
        if(front==null && rear==null){
            System.out.println("UnderFlow");
            return;
        }
        Queuelink temp=front;
        front=temp.next;
        temp=null;
    }

    void print(){
        if(front==null && rear==null){
            System.out.println("UnderFlow");
            return;
        }
        Queuelink ptr;
        for(ptr=front;ptr!=null;ptr=ptr.next){
            System.out.print(ptr.data+" ");
        }
        System.out.println();
    }
}

class QueueLinkedList {
    public static void main(String[] args) {
        Queuelink q=new Queuelink();
        q.enque(1);
        q.enque(2);
        q.enque(3);
        q.enque(4);
        q.enque(5);
        q.enque(6);
        q.enque(7);
        q.enque(8);
        q.enque(9);
        q.enque(10);
        q.enque(11);
        q.enque(12);
        q.enque(13);
        q.enque(14);
        q.enque(15);
        q.print();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.print();
        q.enque(2);
        q.enque(3);
        q.enque(32);
        q.enque(5);
        q.print();
    }
}
