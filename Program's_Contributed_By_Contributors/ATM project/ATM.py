import os
import json 
import datetime

current_directory = os.getcwd()
filename = "atmdb.json"
full_path = os.path.join(current_directory, filename)


class Method:
    def __init__(self,user):
        temp = []
        with open(full_path, 'r') as f:
            db = json.load(f)
        for userCred in db :
            if(userCred["userName"] != user["userName"]):
                temp.append(userCred)
            else:
                temp.append(user)
        with open(full_path, 'w') as fW:
            json.dump(temp, fW, indent=4)

class UserLogin:
    def __init__(self, userName, pin):
        self.userName = userName
        self.pin = pin

    def checkCredentials(self):
        with open(full_path, 'r') as f:
            db = json.load(f)
        for userCred in db:
            if userCred["userName"] == self.userName:
                if (userCred["pin"] == self.pin):
                    print("Login Successful")
                    return userCred
                else:
                    print("Invalid Password")
                    exit()
            else:
                print("Invalid Credentials")
                exit()


class TransactionsHistory:
    def __init__(self, transactionHistory):
        print("TRANSID\tTYPE\tAMOUNT\tDATE\tBALANCE")
        for data in transactionHistory.get("transactions"):
            print(f"{data['transID']}\t{data['type']}\t{data['amt']}\t{data['dateOfTrans']}\t{data['currentBal']}")


class Withdraw:
    def __init__(self, amt,user):
        newData = {}
        currAmt = user["Balance"] - amt
        newData["transID"] = 124578
        newData["type"] = "debit"
        newData["amt"] = amt
        newData["dateOfTrans"] = f"{datetime.datetime.now()}"
        newData["currentBal"] = currAmt
        user["Balance"] = currAmt
        user["transactions"].append(newData)
        Method(user)
        print("Data Saved Successfully!")




class Deposit:
    def __init__(self, amt,user):
        newData = {}
        currAmt = user["Balance"] + amt
        newData["transID"] = 124578
        newData["type"] = "credit"
        newData["amt"] = amt
        newData["dateOfTrans"] = f"{datetime.datetime.now()}"
        newData["currentBal"] = currAmt
        user["Balance"] = currAmt
        user["transactions"].append(newData)
        Method(user)
        print("Data Saved Successfully!")


class Transfer:
    def __init__(self,user):
        self.user = user
    def sendMoney(self):
        amt = int(input("Enter the amount: "))
        upi = input("Enter UPI ID: ")
        newData = {}
        currAmt = user["Balance"] - amt
        newData["transID"] = 124578
        newData["upiID"] = upi
        newData["type"] = "debit"
        newData["amt"] = amt
        newData["dateOfTrans"] = f"{datetime.datetime.now()}"
        newData["currentBal"] = currAmt
        user["Balance"] = currAmt
        user["transactions"].append(newData)
        Method(user)
        print("Data Saved Successfully!")





# Driver's code
print("\n********** Welcome to our ATM **********")
userName = input("Enter your user ID: ")
pin = int(input("Enter your PIN : "))

userLogin = UserLogin(userName, pin)
user = userLogin.checkCredentials()
print("MENU List:- ")
print("\n[1]. View Transaction History\n[2]. Make a withdrawal \n[3]. Make deposit \n[4]. Transaction history \n[5]. Exit the program.\n")
while (True):
    op = int(input("\nEnter your choice: "))
    match(op):
        case 1:
            TransactionsHistory(user)
        case 2:
            amt = int(input("Enter the amount you want to withdraw: "))
            Withdraw(amt,user)
        case 3:
            amt = int(input("Enter the amount you want to deposite: "))
            Deposit(amt,user)
        case 4:
            Transfer(user).sendMoney()
        case 5:
            print("Thanks for using our ATM service.\n")
            break
