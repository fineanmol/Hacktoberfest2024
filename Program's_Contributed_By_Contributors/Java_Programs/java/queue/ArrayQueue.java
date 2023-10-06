/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package queue;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class ArrayQueue implements Queue {

private int size;
private Object array[];

public ArrayQueue(int capacity) {
    array = new Object[capacity];
}

@Override
public Object first() {
    if (this.isEmpty()) {
        throw new IllegalStateException("Queue is empty!");
    }
    return array[0];
}

@Override
public Object remove() {
    if (this.isEmpty()) {
        throw new IllegalStateException("Queue is empty!");
    }
    Object obj = array[0];
    System.arraycopy(array, 1, array, 0, size);
    array[--size] = null;
    return obj;
}

@Override
public void add(Object obj) {
    if (size == this.array.length) {
        resizeArray();
    }
    array[size++] = obj;
}

@Override
public int size() {
    return size;
}

@Override
public boolean isEmpty() {
    return size == 0;
}

public void resizeArray() {
    Object[] array2 = this.array;
    this.array = new Object[2 * size];
    System.arraycopy(array2, 0, this.array, 0, array2.length);
}

public static void main(String[] args) {
    ArrayQueue queue = new ArrayQueue(2);
    queue.add(5);
    queue.add(50);
    queue.add("Hello!");
    System.out.println(queue.remove());
    System.out.println(queue.remove());
    System.out.println(queue.first());
}

}
