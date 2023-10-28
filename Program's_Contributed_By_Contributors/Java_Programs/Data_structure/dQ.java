// Double-ended Queue
public class dQ {
    static class QueueOperations {
        int MAX = 10;
        int FRONT = -1;
        int REAR = -1;
        int QUEUE[] = new int[MAX];

        // Insert at front
        void insertFront(int item) {
            if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1)) {
                System.out.println("Queue is full");
            } else {
                if (FRONT == -1) {
                    FRONT = 0;
                    REAR = 0;
                } else if (FRONT == 0) {
                    FRONT = MAX - 1;
                } else {
                    FRONT--;
                }
                QUEUE[FRONT] = item;
                System.out.println("Item pushed(FRONT): " + item);
            }
        }

        // Insert at rear
        void insertRear(int item) {
            if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1)) {
                System.out.println("Queue is full");
            } else {
                if (FRONT == -1) {
                    FRONT = 0;
                    REAR = 0;
                } else if (REAR == MAX - 1) {
                    REAR = 0;
                } else {
                    REAR++;
                }
                QUEUE[REAR] = item;
                System.out.println("Item pushed(REAR): " + item);
            }
        }

        // Delete at front
        void deleteFront() {
            if (FRONT == -1) {
                System.out.println("Queue is in Underflow condition");
            } else {
                System.out.println("Item popped(FRONT): " + QUEUE[FRONT]);
                if (FRONT == REAR) {
                    FRONT = -1;
                    REAR = -1;
                } else if (FRONT == MAX - 1) {
                    FRONT = 0;
                } else {
                    FRONT++;
                }
            }
        }

        // Delete at rear
        void deleteRear() {
            if (FRONT == -1) {
                System.out.println("Queue is in Underflow condition");
            } else {
                System.out.println("Item popped(REAR): " + QUEUE[REAR]);
                if (FRONT == REAR) {
                    FRONT = -1;
                    REAR = -1;
                } else if (REAR == 0) {
                    REAR = MAX - 1;
                } else {
                    REAR--;
                }
            }
        }

        // Print the items in the de-queue
        void printQueue() {
            if (FRONT == -1) {
                System.out.println("Queue is empty");
                return;
            }

            System.out.print("Queue items: ");
            int i = FRONT;
            do {
                System.out.print(QUEUE[i] + " ");
                if (i == MAX - 1) {
                    i = 0;
                } else {
                    i++;
                }
            } while (i != (REAR + 1) % MAX);
            System.out.println();
        }
    }

    public static void main(String[] args) {
        QueueOperations Q = new QueueOperations();

        // Insertion at front
        Q.insertFront(5);
        Q.insertFront(10);
        Q.insertFront(15);
        Q.insertFront(25);
        Q.insertFront(45);

        System.out.println(); // Gap
        Q.printQueue(); // Print

        Q.deleteFront();
        System.out.println(); // Gap
        Q.printQueue(); // Print

        // Insertion at rear
        Q.insertRear(50);
        Q.insertRear(60);

        System.out.println(); // Gap
        Q.printQueue(); // Print

        // Delete from Front
        Q.deleteFront();
        Q.deleteFront();

        System.out.println(); // Gap
        Q.printQueue(); // Print

        // Delete at rear
        Q.deleteRear();
        Q.deleteRear();

        System.out.println(); // Gap
        Q.printQueue(); // Print
    }
}


