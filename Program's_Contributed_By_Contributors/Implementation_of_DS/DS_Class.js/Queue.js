// enqueue
// dequeue
// isempty
// peek
// size
class Queue {
    #queue;
    #len;
    #front;
    #rear;
    constructor() {
        this.#queue = [];
        this.#front = -1;
        this.#rear = -1;
        this.#len = 0;
    }
    enqueue(value) {
        this.#queue.push(value);
        this.#rear++;
        this.#len++;
        if (this.#queue.length === 1) {
            this.#front = 0;
        }
    }
    dequeue() {
        if (this.#rear >= 0 && this.#queue[this.#front] !== undefined) {
            this.#len--;
            return this.#queue[this.#front++];
        }
        return null;
    }
    size() {
        return this.#len;
    }
    peek() {
        if (this.#len > 0) {
            return this.#queue[this.#front];
        }
        return null;
    }
    queue() {
        if(this.#front >= this.#rear || this.#len === 0){
            return [];
        }
        let res = [];
        for(let i = this.#front; i<=this.#rear;i++){
            res.push(this.#queue[i]);
        }
        return res;
    }
}
let q = new Queue();
q.enqueue(111);
q.enqueue(112);
q.enqueue(113);
console.log("peek after enqueue:");
console.log(q.peek());
q.enqueue(114);
q.dequeue();
q.dequeue();
console.log("size and peek after dequeue:");
console.log(q.size());
console.log(q.peek());
console.log(q.queue());