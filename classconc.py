"""
class student:
    name="abhinav"
print(student.name)
#---------------------------------------------------------------------------------------------------------------------------------------------------------
self is a default variable That contains the memory address of the instance of the current  class (or) in my words it is used to initialize the class variable

class student:
    def __init__(self):
        self.name="shubham"                     #name and age are class variables and self is used to initialize it
        self.age=21
    def talk(self):
        print("hello",self.name)
        print("your age",self.age)
s1=student()
s1.talk()
#-------------------------------------------------------------------------------------------------------------------------------------------------------
class student:
    def __init__(self,n,a):                     #this is just like constructor in java
        self.name=n
        self.age=a
    def talk(self):
        print("hello",self.name)
        print("your age",self.age)
n=input("enter the name")                       #we can also do this next 4 line code in another file by writing from file_name import student
a=int(input("enter the age"))
s1=student(n,a)                                 #s1 is the object of class student
s1.talk()
-------------------------------------------------------------------------------------------------------------------------------------------------------
class student:
    def talk(self):                            #one argument is must,if you are making object if you not pass self it will not run, you can use anything instead of self
        print("hello janvi")
        print("are you good")
s1=student()                                                          
s1.talk()
----------------------------------------------------------------------------------------------------------------------------------------------------
class student:
    def talk():                            
        print("hello janvi")
        print("are you good")
student.talk()
#---------------------------------------------------------------------------------------------------------------------------------------------------
class student:
    name="abhinav"
    age=21
s1=student()
print(s1.age)                          #21
s1.age=45
print(s1.age)                          #45
s2=student()
print(s2.age)                          #21
#-------------------------------------------------------------------------------------------------------------------------------------------

class student:
    n=20
print(student.n)                      #20
student.n=9
print(student.n)                      #9
s1=student()
print(s1.n)                          #9
#------------------------------------------------------------------------------------------------------------------------------------------------
"""
"""
class student:
    def __init__(self,n,m):
        self.name=n
        self.marks=m
    def display(self):
        print("hi",self.name)
        print("your marks  are:",self.marks)
    def calculate(self):
        if self.marks>90:
            print("grade A")
        elif self.marks>70:
            print("grade B")

        elif self.marks>50:
            print("grade C")

        elif self.marks>33:
            print("grade D")
        else:
            print("you are fail")
n=int(input("enter the no. o students"))
i=0
while i<=n:
    name=input("enter the name")
    marks=int(input("enter the marks"))
    s1=student(name,marks)
    s1.display()
    s1.calculate()
    i=i+1
    """

#--------------------------------------------------------NAME MANGLING---------------------------------------------------------------
#NAME MANGLING-IT IS USED FOR INITIALIZING LOCAL VARIABLE WITH TWO LEADING UNDERSCORE AND ONE TRAILING UNDERSCORE
"""
class dawn:
    def __init__(self):
        self.__a=20                                     #local variable
d=dawn()
print(d._dawn__a)                                       #calling
"""
"""
#------------------------------------------------------------------------------------------------------------------------------------
class student():
    n="janvi"
    def __init__(self):
        self.__m="anamika"
    def intro(self):
        print("hello",self.n)
        print("hello",self._student__m) #goes wrong when you write only self.m 
d=student()
d.intro()
"""
#------------------------------------------------------------------------------------------------------------------------------------
"""
class student():
    def __init__(self):
        self.n=20
    def modify(self):
        self.n+=1
s1=student()
s1.modify()
s1.modify()
print("first object",s1.n)
s2=student()
s2.modify()
s2.modify()
print("second object",s2.n)
"""
#_-------------------------------------------------------------------------------------------------------------------
#--------------------------------------------HOW TO CALL ANOTHER CLASS VARIABLE IN OTHER CLASS------------------------------------------
"""
class student():
    def __init__(self,n,a,s):
        self.name=n
        self.age=a
        self.sal=s
    def display(self):
        print("name is" ,self.name)
        print("age is" ,self.age)
        print("salary is",self.sal)
class salary:
    @staticmethod
    def incremenet(emp):
        emp.sal+=10000
        emp.display()

n=input("enter the name")
m=int(input("enter the age"))
s=int(input("enter the salary"))
s1=student(n,m,s)
salary.incremenet(s1)
"""
#----------------------------------------------INNER CLASSES----------------------------------------------------------------------
"""
class intro():
    def __init__(self):
        self.name="jhanvi"
        self.age=21
    def display(self):
        print("name  ",self.name,"  age",self.age)
    class dob():
        def __init__(self):
            self.d=6
            self.m="jan"
            self.y=2002
        def display1(self):
            print(self.d,self.m,self.y)
i=intro()
i.display()
p=i.dob()       #or we can write p=intro.dob()
p.display1()
"""
#-----------------------------------------------------------------------------------------------
class bank:
    cash=1000
    @classmethod
    def checkbalance(cls):
        print(cls.cash)
class sbi:
    cash=2000
    @classmethod
    def check(cls):
        print(cls.cash+bank.cash)#cls.cash or sbi.cash kuch bhi chalega
s=sbi()
s.check()



    



    
        
        
