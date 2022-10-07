class A:
    def __init__(self):
        print("This is class A")

class B(A):
    def __init__(self):
        super().__init__()
        print("This is class B")

class C(B):
    def __init__(self):
        super().__init__()
        print("This is class C")

#creating an object of class C
obj=C()