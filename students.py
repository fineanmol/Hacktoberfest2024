
n=input("Name of the student 1: ")
M=input("Name of the student 2: ")
J=input("Name of the student 3: ")
K=input("Name of the student 4: ")
L=input("Name of the student 5: ")
class Student:
    def __init__(self,n,a,**m):
        self.name = n
        self.age = a
        self.mark = m

    def display(self):
        print("Name of the student is  ", self.name)
        print("Age is  ", self.age)
        print("Marks obtained  ", self.mark)

s1=Student(n, 20, DSA=100, OOP=90, DBMS=80)
s2=Student(M, 20, DSA=80, OOP=67, DBMS=70)      
s3=Student(J, 20, DSA=90, OOP=80, DBMS=70)
s4=Student(K, 20, DSA=80, OOP=70, DBMS=60)
s5=Student(L, 20, DSA=70, OOP=60, DBMS=50)

s1.display()
s2.display()
s3.display()
s4.display()
s5.display()

