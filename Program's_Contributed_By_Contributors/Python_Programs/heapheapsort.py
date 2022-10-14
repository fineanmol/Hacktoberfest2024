from math import floor

class MaxHeap:
    def __init__(self):
        self.heap = [None]
        self.size = 0

    def push(self, ele):
        self.size += 1
        if len(self.heap) > self.size:
            self.heap[self.size] = ele
        else:
            self.heap.append(ele)
        self.perculate_up()

    def perculate_up(self):
        if self.size <= 1: return
        cur = self.size
        parent = floor(cur / 2)
        while parent > 0:
            if self.heap[parent] < self.heap[cur]:
                self.heap[parent], self.heap[cur] = self.heap[cur], self.heap[parent]
            cur = parent
            parent = floor(cur / 2)

    def pop(self):
        if self.size < 1: return
        self.heap[1], self.heap[self.size] = self.heap[self.size], self.heap[1]
        self.size -= 1
        self.perculate_down()
        return self.heap[self.size + 1]

    def perculate_down(self):
        if self.size < 2: return
        cur = 1
        c1 = cur * 2
        c2 = cur * 2 + 1
        while c1 <= self.size or c2<= self.size:
            if self.heap[c1] > self.heap[cur]:
                self.heap[c1], self.heap[cur] = self.heap[cur], self.heap[c1]
                cur = c1
                c1 = cur * 2
                c2 = cur * 2 + 1
            elif c2 <= self.size and self.heap[c2] > self.heap[cur]:
                self.heap[c2], self.heap[cur] = self.heap[cur], self.heap[c2]
                cur = c2
                c1 = cur * 2
                c2 = cur * 2 + 1
            else:
                break
class HeapSort:
    def __init__(self):
        self.max_heap_obj = MaxHeap()

    def sort(self, elements):
        reverse_sorted_elements = []
        for ele in elements:
            self.max_heap_obj.push(ele)

        for _ in range(len(elements)):
            reverse_sorted_elements.append(self.max_heap_obj.pop())

        sorted_elements =  self.max_heap_obj.heap[1:]

        return sorted_elements, reverse_sorted_elements

HeapSort().sort([10, 8, 1, 2, 6, 7, 8, 4, 5, 1, 2, 3, 19])
