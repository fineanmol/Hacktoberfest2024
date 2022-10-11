class Bank_Details:
    def __init__(self,custid,name,mobile,address):
        self.__custid = custid
        self.name = name
        self._mobile = mobile
        self._address = address
class Transaction(Bank_Details):
    def __init__(self,custid,name,mobile,address):
        super().__init__(custid,name,mobile,address)
        self.balance = 0
    def withdraw(self,amount):
        if self.balance == 0:
            print("No available balance in bank account.")
            return
        elif amount>self.balance:
            print("Insufficient Balance.")
            return
        self.balance-=amount
        print("Withdrawn Amount :",amount)
        print("Balance Available :",self.balance)
    def deposit(self,amount):
        self.balance+=amount
        print("Deposited Amount :",amount)
        print("Balance Available :",self.balance)
    
class bal(Transaction):
    def __init__(self,custid,name,mobile,address):
        super().__init__(custid,name,mobile,address)
    def display(self):
        print("Customer ID",self.custid)
        print("Name :",self.name)
        print("Mobile Number :",self._mobile)
        print("Address :",self._address)
        print("Balance :",self.balance)
obj = bal(26,'Alex',123456,'Chennai')
print("Enter Details :")
obj.custid = int(input("Enter Customer ID :"))
obj.name = input("Enter Name :")
obj._mobile = int(input("Enter Mobile :"))
obj._address = input("Address :")

n = 0
while(n!=4):
    print()
    print("1. Deposit Amount")
    print("2. Withdraw Amount")
    print("3. View Details")
    print("4. Exit")
    n=int(input("What do you want to do :"))
    if n == 1:
        m = int(input("Enter Amount :"))
        obj.deposit(m)
    elif n == 2:
        m = int(input("Enter Amount :"))
        obj.withdraw(m)
    elif n == 3:
        obj.display()
    elif n==4:
        print("Function Ended.")
    else:
        print("Invalid Input.")
