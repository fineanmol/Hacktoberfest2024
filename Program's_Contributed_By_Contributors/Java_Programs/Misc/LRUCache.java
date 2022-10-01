package com.abhik.lru;

import java.util.Deque;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

/*
 * Implementation of LRU cache using Java8.
 */


public class LRUCache {

	Deque<Integer> dequeue;
	HashSet<Integer> set;
	int cacheSize;
	int CACHE_SIZE = 10;

	LRUCache() {
		dequeue = new LinkedList<Integer>();
		set = new HashSet<Integer>();
		cacheSize = CACHE_SIZE;
	}

	public void refer(int data) {
		if (!set.contains(data)) {
			if (dequeue.size() == cacheSize) {
				int last = dequeue.removeLast();
				set.remove(data);
			}

		} else {
			dequeue.remove(data);
		}

		dequeue.push(data);
		set.add(data);

	}

	public void display() {

		Iterator<Integer> itr = set.iterator();
		while (itr.hasNext()) {
			System.out.println(itr.next());
		}

	}

	public static void main(String[] args) {
		LRUCache cache = new LRUCache();
		cache.refer(2);
		cache.refer(3);
		cache.refer(2);
		cache.refer(3);

		cache.display();
	}

}
