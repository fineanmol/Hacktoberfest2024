import datetime
import time
import sys

# This is the class that holds all users as objects(instances).
class User:

    # The name and pin of each User object instantiated will be added to this class attribute (dictionary).
    accounts = {} 

    #The object initialization
    def __init__(self, name, age, acct_type, pin):
        self.name = name
        self.age = age
        self.acct_type = acct_type
        self.pin = pin
        self.isGranted = False
        #Name and pin added to the 'accounts' dictionary.
        User.accounts["{}".format(self.name)] = self.pin

    #This method accepts inputs from the user, i.e name and pin; and compares them to the records to affirm their validity
    def validate(self):
        while True:
            input_name = input("Welcome. Please enter your name: ")
            if input_name in User.accounts:
                time.sleep(1.5)
                input_pin = int(input("Welcome, {}. Please enter your pin: ".format(input_name)))
                if input_pin == User.accounts[input_name]:
                    time.sleep(2)
                    print("Access Granted")
                    self.isGranted = True
                    break
                elif input_pin != User.accounts[input_name]:
                    time.sleep(1)
                    print("Incorrect pin. Access Denied.")
                    self.validate()
                else:
                    print("Error. Access denied")
                    self.validate()
            elif input_name not in User.accounts:
                print("Sorry. That's an invalid account name. It's not in our records.")
                self.validate()
            else:
                print("Error.")
                self.validate()
        
    #This method simply displays the user's details (attributes).
    def show_details(self):
        time.sleep(1.5)
        print(" ")
        print("These are your bank details- ")
        print(" ")
        print("Account name is: {}.".format(self.name))
        print("Your age is {}.".format(self.age))
        print("This is a {} account.".format(self.acct_type))
        time.sleep(1.5)
        

#This class inherits the User class and further houses the main functionality of the bank program
class Bank(User):
    def __init__(self, name, age, acct_type, pin):
        super().__init__(name, age, acct_type, pin)
        #Every bank user initialized starts with an account balance of zero.
        self.balance = 0
        #A list is created to keep track/record of all future transactions.
        self.record = []

    #A method for depositing money.
    def deposit(self):
        print(" ")
        time.sleep(1.5)
        self.amount = int(input("How much do you want to deposit?: "))
        self.balance += self.amount
        time.sleep(1.5)
        print("TRANSACTION IN PROGRESS.....")
        time.sleep(1.5)
        print("<<<TRANSACTION COMPLETE>>> [${} deposited] | Your balance has been updated: ${}.".format(self.amount, self.balance))
        self.date = datetime.date.today()
        self.record.append("(---{}---) ${} was deposited. Your account balance is {}---".format(self.date, self.amount, self.balance))
            
    #A method for withdrawing money. It withdraws money after it verifies that the current balance is sufficient.
    def withdraw(self):
        print(" ")
        while True:
            self.amount = int(input("How much do you want to withdraw?: "))
            if self.amount > self.balance:
                time.sleep(1.5)
                print("INSUFFICIENT FUNDS...")
                time.sleep(1.5)
                continue
            elif self.amount == 0:
                time.sleep(1.5)
                print("You cannot withdraw that amount. Please try aagain.")
                time.sleep(1.5)
                continue
            elif self.amount < self.balance:
                time.sleep(1.5)
                print("TRANSACTION IN PROGRESS.....")
                self.balance -= self.amount
                time.sleep(2)
                break
            
        print("<<<TRANSACTION COMPLETE>>> [${} withdrawn] | Your balance has been updated: ${}.".format(self.amount, self.balance))
        self.record.append("(---{}---) ${} was withdrawn. Your account balance is {}---".format(self.date, self.amount, self.balance))


    #This method displays the account balance.
    def check_balance(self):
        time.sleep(1.5)
        print("Checking balance...")
        print(" ")
        time.sleep(1.5)
        print("Your balance is ${}.".format(self.balance))
    

    #This method displays all pevious account transactions
    def transactions(self):
        print(" ")
        time.sleep(1.5)
        print("FETCHING TRANSACTIONS.....")
        time.sleep(2)
        print("TRANSACTIONS: \n")
        for i in self.record:
            print(i)
        print(" ")


    #This is the main bank program function.
    def session(self):

        #Returns true if user inputs have been verified.
        self.validate()
        
        while True:
            #Upon verification, bank program proceeds.
            if self.isGranted == True:

                print(" ")
                time.sleep(1.5)

                button_press = input("Welcome to Mickey's Global ATM. What would you like to do?\n>>>Press 'D' to make a deposit\n>>>Press 'W' to make a withdrawal\n>>>Press 'B' to check your balance\n>>>Press 'M' to show your account details\n>>>Press 'T' to show your previous transactions\n>>>Press 'E' to terminate the process\nResponse: ") 

                time.sleep(1.5)
                
                if button_press == 'D':
                    self.deposit()
                elif button_press == 'W':
                    self.withdraw() 
                elif button_press == 'B':
                    self.check_balance()
                elif button_press == 'M':
                    self.show_details()
                elif button_press == 'T':
                    self.transactions()
                elif button_press == "Exit" or "E" or "e" or "exit":
                    time.sleep(1.5)
                    print(" ")
                    print("Thank you for using our services, {}.".format(self.name))
                    sys.exit()
                else:
                    print("invalid command.")
                    print(" ")
    


#This is back-end instantiation. Create your users here.
user1 = Bank("Michael", 21, "Savings", 1234)
user2 = Bank("Admin", 18, "Current", 1111)
user3 = Bank("Guest", 20, "Savings", 1234)


user3.session()