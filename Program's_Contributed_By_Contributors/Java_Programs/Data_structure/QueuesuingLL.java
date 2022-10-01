public class QueueusingLL<T>{

   private Node<T> front;
   private Node<T> rear;
   private int size;

    public QueueusingLL() {
        front = null;
        rear = null;
        size =0;
    }

    int size(){
        return size;
    }

    boolean isEmpty(){
        return (size==0);
    }

    T front(){
        if (size==0){
            System.out.println("Queue is Empty");
        }
        return front.data;
    }

    void enqueue(T input){
        Node<T> temp = new Node<>(input);
        if (size==0){
            front = temp;
            rear = temp;
            size++;
        }else{
            rear.next = temp;
             rear = rear.next;
             rear.next = null;
             size++;
        }
    }

    T dequeue() {
        if (size==0){
            System.out.println("Queue is Empty");
        }
        T temp = front.data;
        front = front.next;
        if (size==1){
            rear = null;
        }
        size--;
        return temp;
    }
}
