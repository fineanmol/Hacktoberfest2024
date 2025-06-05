#from inheritance1 import teacher
class teacher:
    def setname(self,n):
        self.name=n
    def setage(self,a):
        self.age=a
    def setsal(self,sal):
        self.sal=sal
    def getname(self):
        return self.name
    def getage(self):
        return self.age
    def getsal(self):
        return self.sal

class newstudent(teacher):
    def setmark(self,m):
        self.mark=m
    def getmark(self):
        return self.mark
t=newstudent()
t.setname("jhanvi")
t.setage(18)
t.setmark(100)
print(t.getname())
print(t.getage())
print(t.getmark())
#------------------------------------------------------------------------------------------------------------------------------
class father:
    def __init__(self,pr):
        self.pr=pr
    def display(self):
        print(" property:",self.pr)
class son(father):
    def __init__(self,pr1):
        self.pr1=pr1
    def display1(self):
        print("property:",self.pr1)
f=son(30300)
f.display1()
#--------------------------------MULTIPLE INHERITANCE-----------------------------------------------------------------------------------------------
class father:
    def height(self):
        print("i am tall")
class mother:
    def eyes(self):
        print("eyes are brown")
class child(father,mother):
    pass
c=child()
c.height()
c.eyes()
#--------------------------------------CONSTRUCTOR OVERRRIDING---------------------------------------------------------------------
class A:
    def __init__(self):
        print("constructor of class a")
class B:
    def __init__(self):
        print("constructor of class b")
class C(A,B):
    def __init__(self):
        print("constructor of class c")# a,b,c me c ka hi constructor call hoga
obj=C()
#----------------------------------------------------------------------------------------------------------------------------------

class A1:
    def __init__(self):
        print("constructor of class a1")
class B1:
    def __init__(self):
        super().__init__()
        print("constructor of class b1")
class C1(B1,A1):
    def __init__(self):
        super().__init__() # is line m aayga to MRO (method resolution order)follow karega to left side s searching start hogi left me A hoga and thenn A ka constructor call hoga 
        print("constructor of class c1")
obj=C1()



    


    

        
    
    

