# Sample Input 
# 6
# a b c d e f
# 40 30 20 5 3 2
# Sample Output
# a = 0
# b = 10
# c = 111
# d = 1100
# e = 11011
# f = 11010

from sys import stdin

class Node:
    def __init__(self, freq=None, symbol=None, left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        
    def setLeft(self, node):
        self.left = node        
        
    def setRight(self, node):
        self.right = node

class MinHeap:
    def __init__(self, ):
        self.heap = []
        
    def heapify(self, i):
        smallest = i
        left = 2*i+1
        right = 2*i+2
        if left < len(self.heap) and self.heap[left].freq < self.heap[smallest].freq:
            smallest = left
        if right < len(self.heap) and self.heap[right].freq < self.heap[smallest].freq:
            smallest = right
        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self.heapify(smallest)

    def insert(self, node):
        self.heap.append(node)
        pos = len(self.heap) - 1
        while pos > 0 and self.heap[pos].freq < self.heap[(pos - 1)//2].freq:
            temp = self.heap[pos]
            self.heap[pos] = self.heap[(pos-1)//2]
            self.heap[(pos-1)//2] = temp            
            pos = (pos-1)//2

    def remove(self):
        el = self.heap[0]
        self.heap[0] = self.heap[len(self.heap) - 1]
        self.heap.pop()
        self.heapify(0)
        return el


def traverseHuffmanTree(root, code, arr):
    if root.left == None and root.right == None:
        arr.append((root.symbol, code))
    else:
        traverseHuffmanTree(root.left, code+'0', arr)
        traverseHuffmanTree(root.right, code+'1', arr)

n = int(input())
letters = list(stdin.readline().strip().split())
freq = list(map(int, stdin.readline().strip().split()))
heap = [Node(freq[i], letters[i]) for i in range(n)]
m = MinHeap()
for i in range(n):
    m.insert(Node(freq[i], letters[i]))
    
while len(m.heap) != 1:
    min1 = m.remove()
    min2 = m.remove()
    newInternalNode = Node(min1.freq+min2.freq, 'NA')
    newInternalNode.setLeft(min1)
    newInternalNode.setRight(min2)
    m.insert(newInternalNode)

ar = []
traverseHuffmanTree(m.heap[0], '', ar)
ar.sort(key=lambda el: ord(el[0][0]))
for _,el in enumerate(ar):
    print('{} = {}'.format(el[0],el[1]))