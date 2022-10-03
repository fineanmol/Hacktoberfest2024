#create a class name is employee
class Empolyee:
  #parameterized constructor
  def __init__ (self,name,age,salary,gender): 
    self.name=name
    self.age=age
    self.salary=salary
    self.gender=gender
    
#creating new method to print details on Empolyee    
  def empolyee_details(self):
    print("Name of Empolyee :",self.name)
    print("age of Empolyee  :",self.age)
    print("salary of Employee :",self.salary)
    print("gender of Employee :",self.gender)
#creating object of the class
#this will invoke  parameterized

e1=Empolyee("Yastha",20,25000,"Female")
#display result
e1.empolyee_details()
