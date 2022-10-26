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
public class LinkedQueue implements Queue {

private int size;
private Node head = new Node(null);

private class Node {

private Object object;
private Node previous = this;
private Node next = this;

public Node(Object obj) {
    this.object = obj;
}

public Node(Object object, Node previous, Node next) {
    this.object = object;
    this.previous = previous;
    this.next = next;
}

}

@Override
public Object first() {
    if (this.isEmpty()) {
        throw new IllegalStateException("Queue is empty!");
    }
    return head.next.object;
}

@Override
public Object remove() {
    if (this.isEmpty()) {
        throw new IllegalStateException("Queue is empty!");
    }
    Object firstElement = head.next.object;
    head.next = head.next.next;
    head.next.previous = head;
    size--;
    return firstElement;
}

@Override
public void add(Object obj) {
    head.previous = head.previous.next = new Node(obj, head.previous, head);
    size++;
}

@Override
public int size() {
    return size;
}

@Override
public boolean isEmpty() {
    return size == 0;
}

public static void main(String[] args) {
    LinkedQueue carsBought = new LinkedQueue();
    LinkedQueue carsSold = new LinkedQueue();
    carsBought.add(1000);
    carsBought.add(2000);
    carsBought.add(500);
    carsSold.add(1100);
    carsSold.add(1999);
    carsSold.add(600);
    int totalProfit = 0;
    int size = carsBought.size();
    for (int i = 0; i < size; i++) {
        totalProfit += (int) carsSold.remove() - (int) carsBought.remove();
    }
    System.out.println("Total Profit On these Three Cars: "+totalProfit);
}
}
