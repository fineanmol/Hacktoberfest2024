package com.company;

public class BinaryHeap {
    public static class MinHeap{
        int[] arr;
        int size, capacity;

        MinHeap(int capacity){
            size=0;
            this.capacity=capacity;
            arr=new int[capacity];
        }
    }

    int left(int i){ return (2*i+1);}
    int right(int i){ return (2*i+2);}
    int parent(int i){ return (i-1)/2;}

    public static void main(String[] args) {
        MinHeap h = new MinHeap(11);


    }
}
