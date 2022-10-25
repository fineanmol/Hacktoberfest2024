from user import User

#Child Class
class Bank(User):
    def __init__(self, name, age, gender):
        super().__init__(name, age, gender)
        self.balance = 0

    def deposit(self, amount):
        self.amount = amount
        self.balance = self.balance + self.amount

        print(f'The account balance is update. Deposit amount :  Rupees : {self.amount}. Current balance : Rupees : {self.balance}')

    def withdraw(self,amount):
        self.amount = amount
        if (self.amount > self.balance):
            print(f"Insufficient funds. Balance available {self.balance}")
        else:
            self.balance = self.balance - self.amount
            print(f'You withdrew rupees {self.amount}. The balance has been updated to {self.balance}')

    def view_balance(self):
        self.show_user_details()
        print(f"Current balance : {self.balance}")

# John = Bank("John Rivera", 19, "Male")
# John.deposit(4000)
# John.withdraw(200)
# John.view_balance()