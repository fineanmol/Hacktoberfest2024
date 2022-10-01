// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
private:
    vector<int> queue;
    int size;
    int front=-1,rear=-1;
public:
    MyCircularQueue(int k) {
        queue = vector<int>(k);
        size = k;
    }
    
    bool enQueue(int value) {
        if (front==-1){
            queue[0] = value;
            front = rear = 0;
            return true;
        }
        
        if ((rear+1)%size==front){
            return false;
        }
        
        queue[(rear+1)%size] = value;
        rear = (rear+1)%size;
        return true;
    }
    
    bool deQueue() {
        
        if (front == -1){
            return false;
        }
        
        if (front == rear){
            front = rear = -1;
            return true;
        } else {
            front = (front+1)%size;
            return true;
        }
    }
    
    int Front() {
        if (isEmpty()){
            return -1;
        }
        return queue[front];
    }
    
    int Rear() {
        if (isEmpty()){
            return -1;
        }
        return queue[rear];
    }
    
    bool isEmpty() {
        return (front==-1);
    }
    
    bool isFull() {
        return (rear+1)%size==front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */