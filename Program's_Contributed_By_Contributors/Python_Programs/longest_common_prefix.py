"""
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string ""
"""
class Node:
    def __init__(self):
        self.children = defaultdict(Node)
        self.count = 0
class Trie:
    def __init__(self):
       self.t = Node()
    def add(self,st):
        temp = self.t
        for i in st:
            temp = temp.children[i]
            temp.count += 1
        return temp.count
    def traverse(self,st,n):
        temp = self.t
        ct = 0
        if temp.count == n : ct += 1
        for i in st:
            temp = temp.children[i]
            # print(temp.count)
            if temp.count == n : ct += 1
        return ct
        
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        head = Trie()
        ans =0
        for st in strs:
            ma = head.add(st)
        ans = head.traverse(strs[0],len(strs))
        print(ans)
        return strs[0][:ans]


#Changes proposed in this Pull Request :
# 1. Added a new python program for finding the longest common prefix in a list of strings

#Other changes :
#none
