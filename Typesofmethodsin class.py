#---------------------------------------------------------------TYPES OF METHOD------------------------------------------------------------
"""
1)instance method :- the function which contains self keyword
    i) accesssor method(getter)
    ii) mutator mrthod(setter method)
2)class method
3)static method
#_---------------------------------------------------------------INSTANCE METHOD(SELF)----------------------------------------------------------------------

class jan:
    def __init__(self,n,a):
        self.name=n
        self.age=a
    def display(self):
        print("the name is",self.name)
        print("the age is ",self.age)
j=jan("janvi",18)
j.display()
#------------------------------------------------------GETTER AND SETTER METHOD---------------------------------------------------------------

class don():
    def setname(self,n):
        self.name=n
    def setage(self,a):
        self.age=a
    def getname(self):
        print(self.name)
    def getage(self):
        print(self.age)

i=0
while(i<3):
    d=don()
    n=input("enter the name")
    d.setname(n)
    a=int(input("enter the age"))
    d.setage(a)
    d.getname()
    d.getage()
    i=i+1
#_-----------------------------------------------------CLASS METHOD(CLS)------------------------------------------------------------------------------
class bird:
#class methods are called by making objects 
    wing=2
    @classmethod
    def flying(cls,n):
        print("the",n," is flying and has",cls.wing,"wings")
b=bird()
b.flying("sparrow")
b1=bird()
b1.flying("pigeon")
        

class bird:#we can do this in python class method can called by classname like in static method
    wing=2
    @classmethod
    def flying(clss,n):
        print("the",n,"is flying and has" ,clss.wing,"wings");
bird.flying("sparrow")
bird.flying("pigeon")


#----------------------------------------------------------STATIC METHOD(NOTHING)--------------------------------------------------------------
class bird:
    wing=2
    @staticmethod
    def flying(n):
        print("the",n,"is flying who have wings")
bird.flying("sparrow")
"""
"""
class bird:
    wing=2
    @staticmethod                
    def flying(n):
        print("the",n,"is flying who have wings")
b=bird()
b.flying("sparrow")
#classmethod and static are vice versa until when you use decorator
class bird:
    wing=2
    def flying(n):
        print("the",n,"is flying who have wings")#agra hum object bnakr call karenge without using decorator to error dega
bird.flying("sparrow")
"""
"""
#--------------------------------------------HOW TO CALL ANOTHER CLASS VARIABLE IN OTHER CLASS------------------------------------------
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


        



    
    

