""" bank accounts"""
import base64
import datetime
import os
import platform
import shelve
import pytz
import tkinter
from tkinter.messagebox import showerror as tmsg

path = None
if platform.system() == "Windows":
    if os.access(f"{os.getenv('USERPROFILE')}/Documents/Bank account "
                 "essentials", os.F_OK) is True:
        path = f"{os.getenv('USERPROFILE')}/Documents/Bank account essentials"
    clearScreen = "cls"
else:
    if os.access(f"{os.getenv('HOME')}/Documents/Bank account essentials",
                 os.F_OK) is True:
        path = f"{os.getenv('HOME')}/Documents/Bank account essentials"
    clearScreen = "clear"

bankMoney = shelve.open(f"{path}/bankMoney")
userNamesDataBase = shelve.open(f"{path}/bankAccountNames")
userAccountNumber = shelve.open(f"{path}/bankAccountNumbers")
accountMoney = shelve.open(f"{path}/accountHolderMoney")
loanAccount = shelve.open(f"{path}/loanAccount")
FD = shelve.open(f"{path}/FD")
ageOfAccount = shelve.open(f"{path}/permissions")
childMoneyMax = 5000
kidWithdrawMax = 2000
minAm = 500
BUILD = 5612
current_Time = datetime.datetime.strftime(datetime.datetime.now(), "%Y %m %d")
if current_Time > "2022 06 24":
    print("THIS VERSION IS NOW OUT OF SUPPORT AND WILL NOT RECEIVE ANY "
          "UPDATES AT ALL. SO, PLEASE RE-CONSIDER USING THIS PROGRAM!")
    conf = input("DO YOU WANT TO STILL USE THIS PROGRAM?")
    if conf.casefold() == "N":
        quit(__name__)


def logger(text):
    """
    Logs activity in the account to `_bank_log.txt`
    :param text: The text in the log
    :return: `text` to log
    """
    if platform.system() == "Windows":
        with open(f"{os.getenv('USERPROFILE')}\\Documents\\"
                  f"_bank_log_v5.txt", "a") as log:
            print(text, file=log)
    else:
        with open(f"{os.getenv('HOME')}/Documents/_bank_log_v5.txt",
                  "a") as log:
            print(text, file=log)


class Account:
    """
    Bank accounts for the people side.
    """

    def __init__(self, name, password, balance):
        self.name = name
        self.password = password
        self.balance = int(balance)
        print(f"Log in successful for {self.name}")
        currentTime = (pytz.utc.localize(datetime.datetime.now()))
        logger(f"Successful login at {currentTime} By {self.name}")

    def Deposit(self, amount, userName):
        """
        Deposits amount
        :param amount: Amount to be deposited to account
        :param userName: The destination account
        :return:Added money
        """
        amount = int(amount)
        if amount > 0:
            if ageOfAccount[userName] == "Normal Account":
                self.balance += amount
                accountMoney[userName] += amount
                logger(f"Deposit success! Your updated bank balance - "
                       f"{self.balance}")
            elif ageOfAccount[userName] == "Child Account":
                if amount <= kidWithdrawMax and self.balance + amount <= \
                        childMoneyMax:
                    self.balance += amount
                    accountMoney[userName] += amount
                    logger(f"Deposit success! Your updated bank balance - "
                           f"{self.balance}")
                else:
                    logger(
                        f"Unsuccessful deposit of {amount} INR! Child account "
                        f"can't deposit more than {kidWithdrawMax} and the bank"
                        f" balance after deposit shouldn't be more than"
                        f" {childMoneyMax}")
                    tmsg("Account Money Limit",
                         f"Child account cannot deposit more than "
                         f"{kidWithdrawMax} INR and the balance "
                         f"shouldn't cross {childMoneyMax}")
        else:
            print("The deposit amount should be more than 0! Deposit failed")
            logger(f"Unsuccessful deposit of {amount} INR! The amount must be "
                   f"more than 0!")

    def Withdraw(self, total, userName):
        """
        Withdraws amount from total money in account
        :param total:Amount to be taken from the account
        :param userName: The destination account
        :return:Remaining money
        """
        if ageOfAccount[userName] == "Normal Account":
            if self.balance > minAm:
                if self.balance >= total > 0:
                    if (self.balance - total) > minAm:
                        accountMoney[userName] -= total
                        self.balance -= total
                        logger(
                            f"Withdrawal success! Your updated bank balance- "
                            f"{self.balance} ")
                    else:
                        tmsg(
                            "Not enough money!",
                            "The remainder of the withdrawal "
                            f"should be more than {minAm}!")
                        logger(f"Unsuccessful Withdrawal of {total} INR! The "
                               f"balance after the transaction should be more "
                               f"than minAm!")

                else:
                    tmsg("Not enough money!", f"Not enough money to withdraw"
                                              f" {total} INR")
                    logger(f"Unsuccessful Withdrawal of {total} INR! The "
                           f"balance of the account should be more than the "
                           f"transaction amount!")
        elif ageOfAccount[userName] == "Child Account":
            if self.balance > minAm:
                total = int(total)
                if self.balance >= total <= kidWithdrawMax > 0:
                    if self.balance - total >= minAm:
                        accountMoney[userName] -= total
                        self.balance -= total
                        logger(
                            f"Withdrawal success! Your updated bank balance- "
                            f"{self.balance} ")
                    else:
                        print("The remainder of the withdrawal should be more "
                              "than minAm!")
                        logger(f"Unsuccessful Withdrawal of {total} INR! The "
                               f"balance after the transaction should be more "
                               f"than minAm!")

                else:
                    print(f"The specified amount is more than the maximum "
                          f"amount of withdrawal - ({kidWithdrawMax})")
                    logger(f"Unsuccessful Withdrawal of {total} INR! The "
                           f"amount shouldn't be more than the maximum "
                           f"withdrawal amount of {kidWithdrawMax}!")
        else:
            print(f"The balance should be more than minAm to withdraw from "
                  f"account")
            logger(f"Unsuccessful Withdrawal of {total} INR! The "
                   f"balance should be more than minAm!")

    def Transfer(self, username, amount):
        """
        transfer amount from one to another
        :param username:The account which it's going to transfer `amount`
        :param amount:The total money which it's going to send to `account`
        :return:`amount` to `account` in the `accountMoney` shelve
        """
        global minAm
        self.balance = int(self.balance)
        minAm = int(minAm)
        amount = int(amount)
        if username in userNamesDataBase:
            if self.balance > int(amount) > 0:
                if (self.balance - amount) > minAm:
                    if ageOfAccount[username] == "Normal Account":
                        self.balance -= amount
                        accountMoney[self.name] -= amount
                        accountMoney[username] += amount
                        logger(f"Transferred {amount} INR to {username}")
                    else:
                        if (accountMoney[username] + amount) <= minAm:
                            self.balance -= amount
                            accountMoney[username] += amount
                            logger(f"Transferred {amount} INR to {username}")
                            print(f"transfer successful of {amount} to "
                                  f"{username}, a child account")
                        else:
                            logger("The balance amount for the child account "
                                   "is more when deposited. so deposit "
                                   "rejected. try again with a different "
                                   "amount")
                            print("unsuccessful! the reminder in the child "
                                  "account is more when deposited!")
                else:
                    print("The amount left should be more than minAm!")
                    logger(f"Unsuccessful Transfer of {amount} INR to"
                           f" {username}! the remaining balance of the "
                           f"transaction should be more than minAm!")
            else:
                print(f"The amount isn't good enough to transfer {amount}")
                logger(f"Unsuccessful Transfer of {amount} INR to {username}"
                       f"!Insufficient balance to transfer money")
        else:
            print("The specified user doesn't exist! error 404")
            logger(f"Unsuccessful transfer of {amount} INR to {username}! "
                   f"Incorrect Username!")

    def FD(self, principle: int, rate: int, nYears: int, mode) -> str:
        """
        Fixed deposit system
        this uses CI to calculate the interest. in v6, we will change to CI
        :param mode: Use months or years for the FD
        :param principle: The principle
        :param rate: The rate of interest
        :param nYears: The time
        """
        if mode == "Y" and principle > 0:
            Amount = principle * ((1 + rate / 100) ** nYears)
            if self.balance >= minAm and (self.balance - Amount) >= minAm:
                if float(bankMoney["Public Money"]) >= Amount:
                    self.balance -= Amount
                    accountMoney[self.name] -= Amount
                    bankMoney["Public Money"] += Amount
                    FD[self.name] += Amount
            return f"The FD process is finished! {Amount=}"
        else:
            CI = principle * (1 + (rate / 12)) ** (12 * nYears) - principle
            Amount = principle + CI
            if self.balance >= minAm and (self.balance - Amount) >= minAm:
                if float(bankMoney["Public Money"]) >= Amount:
                    self.balance -= Amount
                    accountMoney[self.name] -= Amount
                    bankMoney["Public Money"] += Amount
                    FD[self.name] += Amount
            return f"The FD process is finished! {Amount=}"

    def __str__(self):
        return f"\nYour bank balance - {accountMoney[self.name]}\n" \
               f"Debt - {loanAccount[self.name]}\n" \
               f"Account Type - {ageOfAccount[self.name]}\n" \
               f"Fixed Deposit - {FD[self.name]}\n"


def start_app():
    """ the app itself"""
    accountName = str(accountName1.get())
    accountPassword = accountPassword1.get()
    accountNumber = accountNumber1.get()
    if str(accountName) in userNamesDataBase:
        print(accountPassword)
        passwords = bytes.decode(userNamesDataBase[accountName],
                                 encoding='utf8')
        if bytes(accountPassword, encoding='utf-8') == base64.b64decode(
                passwords):
            accountNumber2 = base64.b64decode(userAccountNumber[accountName])
            accountNumber2 = accountNumber2.decode(encoding="utf-8")
            if accountNumber == accountNumber2:
                def withdrawer():
                    """ wothdrawer"""
                    nonlocal info
                    info.destroy()
                    howMuch = toModifyMoney.get()
                    account.Withdraw(howMuch, accountName)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=5, column=0)

                def depositer():
                    """ depositer"""
                    nonlocal info
                    info.destroy()
                    depositMoney = toModifyMoney.get()
                    account.Deposit(depositMoney, accountName)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=5, column=0)

                def transfer():
                    """ transfer money"""
                    nonlocal info
                    info.destroy()
                    transferMoneyAccount = transferAccountName.get()
                    transferMoney = toModifyMoney.get()
                    account.Transfer(transferMoneyAccount, transferMoney)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=5, column=0)

                money = int(accountMoney[accountName])
                account = Account(str(accountName), accountPassword,
                                  money)
                info = tkinter.Label(root, text=account.__str__())
                info.grid(row=5, column=0)
                accountName1.configure(state="disabled")
                accountPassword1.configure(state="disabled")
                accountNumber1.configure(state="disabled")
                login.configure(state='disabled')
                if __name__ == "__main__":
                    toModifyMoney = tkinter.Entry(root)
                    toModifyMoney.grid(row=6, column=0, padx=20)
                    withdraw = tkinter.Button(root, text="Withdraw",
                                              command=withdrawer)
                    withdraw.grid(row=7, column=0)
                    deposit = tkinter.Button(root, text="Deposit",
                                             command=depositer)
                    deposit.grid(row=7, column=1)
                    transfer = tkinter.Button(root, text="Transfer",
                                              command=transfer)
                    transfer.grid(row=7, column=2)
                    if toModifyMoney == "P":
                        if loanAccount[accountName] > 0:
                            if account.balance > loanAccount[accountName]:
                                loaner = loanAccount[accountName]
                                if account.balance - loaner > minAm:
                                    cashOrAcc = input("Cash or Account Money\n "
                                                      "AM-Account Money\n"
                                                      "C-Cash")
                                    if cashOrAcc == "AM":
                                        accountMoney[accountName] -= \
                                            loanAccount[
                                                accountName]
                                        account.balance -= loanAccount[
                                            accountName]
                                        bankMoney["Public Money"] += \
                                            loanAccount[
                                                accountName]
                                        logger(f"Pay backed "
                                               f"{loanAccount[accountName]} by "
                                               f"{accountName} by balance")
                                        loanAccount[accountName] = 0
                                        os.system(clearScreen)
                                        print("returned the loan with account")
                                    else:
                                        bankMoney["Public Money"] += \
                                            loanAccount[
                                                accountName]
                                        logger(f"Pay backed "
                                               f"{loanAccount[accountName]} by "
                                               f"{accountName} by cash")
                                        loanAccount[accountName] = 0
                                        print("Pay backed the loan with cash")
                                else:
                                    logger("Unsuccessfully payback The balance "
                                           f"should be more than {minAm}!")
                                    print(
                                        "The remainder after the payback is"
                                        "less than 500 and that's not allowed")
                            else:
                                logger(f"The balance of "
                                       f"{accountMoney[accountName]} is less"
                                       f"than the amount of debt!")
                                print(
                                    "The balance should be more than the amount"
                                    " of debt!")
                        else:
                            logger(f"No debt to pay off now by {accountName}!")
                            os.system(clearScreen)
                            print("NO debt to pay off here\n")
                        print(account.__str__())
                    if toModifyMoney == "FD":
                        confi = input("[M]months or [Y]ears?")
                        if FD[accountName] == 0 and confi == "Y":
                            p = int(input("How much money? (interest is 5%)"))
                            tableOfSIYear = {
                                1: p * 5 * 1 // 100,
                                5: p * 5 * 5 // 100,
                                10: p * 5 * 10 // 100,
                            }
                            for keys, values in tableOfSIYear.items():
                                print(
                                    f"{keys} Year has the interest of {values}")
                            choice = int(
                                input("How many years?refer table above!"))
                            if choice in tableOfSIYear.keys():
                                account.FD(p, 5, choice, 'Y')
                                os.system(clearScreen)
                                print("SUCCESSFUL FD!")
                                print(account.__str__())
                        if FD[accountName] == 0 and conf == "M":
                            p = int(input("How much money? (interest is 5%)"))
                            tableOfSIMonth = {
                                1: 5 * 1,
                                5: 5 * 5,
                                10: 5 * 10,
                            }
                            for keys, values in tableOfSIMonth.items():
                                print(
                                    f"{keys} Year has the interest of {values}")
                            choice = int(
                                input("How many years?refer table above!"))
                            if choice in tableOfSIMonth.keys():
                                account.FD(p, 5, choice, 'M')
                                os.system(clearScreen)
                                print("SUCCESSFUL FD!")
                        if FD[accountName] != 0:
                            confir = input("Do you want to [D]delete your FD?")
                            if confir == "D":
                                del FD[accountName]

                    if toModifyMoney == "L":
                        time = (pytz.utc.localize(datetime.datetime.now()))
                        logger(f"Successful logout at {time} By {accountName}")
                        exit()
        else:
            time = (pytz.utc.localize(datetime.datetime.now()))
            logger(f"Unsuccessful login at {time} By {accountName}! Incorrect "
                   f"Password!")
            print("The password is wrong! try again!")
    else:
        print(
            "The user doesn't exist! login with a user from the database")
        logger(
            f"Tried to logon with a user that doesn't exist ({accountName}) at "
            f"{(pytz.utc.localize(datetime.datetime.now()))}")

    logger(f"exited program at {pytz.utc.localize(datetime.datetime.now())}")


root = tkinter.Tk()
root.title(f"Bank accounts program v5 BUILD- {BUILD}")
try:
    b = tkinter.Label(root, text="Enter your account name! ->")
    b.grid(row=0, column=0)
    accountName1 = tkinter.Entry(root)
    accountName1.grid(row=0, column=1, padx=10)
    d = tkinter.Label(root, text="Enter your money transfer name ->")
    d.grid(row=1, column=0, pady=10)
    transferAccountName = tkinter.Entry(root)
    transferAccountName.grid(row=1, column=1, padx=10)
    a = tkinter.Label(root, text="What's you account password? ->")
    a.grid(row=2, column=0, pady=10)
    accountPassword1 = tkinter.Entry(root, show="*")
    accountPassword1.grid(row=2, column=1, padx=10)
    c = tkinter.Label(root, text="What is your account number? ->")
    c.grid(row=3, column=0, pady=10)
    accountNumber1 = tkinter.Entry(root)
    accountNumber1.grid(row=3, column=1, padx=10, pady=10)
    logger(f"program started at {pytz.utc.localize(datetime.datetime.now())}")
    login = tkinter.Button(root, text="Login with these credentials!",
                           command=start_app)
    login.grid(row=4, column=0)

    root.mainloop()
except KeyboardInterrupt:
    logger(f"program crashed on {pytz.utc.localize(datetime.datetime.now())}")

finally:
    userNamesDataBase.close()
    userAccountNumber.close()
    accountMoney.close()
    loanAccount.close()
    ageOfAccount.close()
    FD.close()
