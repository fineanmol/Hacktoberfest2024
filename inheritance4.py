from inheritance1 import teacher
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


        
    
    

