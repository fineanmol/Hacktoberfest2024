class stack:
    def __init__(self,maxsize):
        self.list=[]
        self.maxsize=maxsize
    def __str__(self):
        t=[str(i) for i in self.list]
        t.reverse()
        return "\n".join(t)
    def isEmpty(self):
        if self.list==[]:
            return True
        return False
    def push(self,val):
        self.list.append(val)
    def pop(self):
        if self.isEmpty():
            return "Stack is empty"
        return self.list.pop()
    def isFull(self):
        if self.maxsize==len(self.list):
            return True
        return False
    def delete(self):
        self.list=None
    def peek(self):
        if self.isEmpty():
            return "Stack is empty"
        return self.list[len(self.list)-1]

ss=stack(10)
ss.push(2)
ss.push(3)
ss.push(4)
print(ss)
print(ss.pop())
print("-",ss)
print(ss.peek())

