""" bank accounts"""
import base64
import sqlite3
from tkinter.messagebox import showerror as tmsg
from account_old import *
import pytz

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

bankMoneySQL = sqlite3.connect(f"{path}/bankMoney.sqlite")
userNamesDataBaseSQL = sqlite3.connect(f"{path}/bankAccountNames.sqlite")
userAccountNumberSQL = sqlite3.connect(f"{path}/bankAccountNumbers.sqlite")
accountMoneySQL = sqlite3.connect(f"{path}/accountHolderMoney.sqlite")
loanAccountSQL = sqlite3.connect(f"{path}/loanAccount.sqlite")
FDSQL = sqlite3.connect(f"{path}/FD.sqlite")
ageOfAccountSQL = sqlite3.connect(f"{path}/permissions.sqlite")
childMoneyMax = 5000
kidWithdrawMax = 2000
minAm = 500
BUILD = 5783
current_Time = datetime.datetime.strftime(datetime.datetime.now(), "%Y %m %d")
root = tkinter.Tk()
root.title(f"Bank accounts program v5 BUILD- {BUILD}")


def start_app():
    """ the app itself"""
    accountName = str(accountName1.get())
    accountPassword = accountPassword1.get()
    accountNumber = int(accountNumber1.get())
    name_cursor = userNamesDataBaseSQL.execute("SELECT name, password FROM "
                                               "account_name WHERE name = ? AND "
                                               "password = ?",
                                               (accountName,
                                                accountPassword))
    account_number = userAccountNumberSQL.execute(
                                                "SELECT number FROM "
                                                "account_number WHERE name ="
                                                " ? AND number = ?",
                                                (accountName, accountNumber))
    account_money = accountMoneySQL.execute("SELECT balance FROM "
                                            "account_money WHERE name ="
                                            " ?", (accountName,))
    permission = ageOfAccountSQL.execute(
        "SELECT permission FROM permissions"
        " WHERE name = ?", (accountName,))
    loans = loanAccountSQL.execute("SELECT loan_amount FROM account_loan "
                                   "WHERE name = ?", (accountName,))
    ageOfAccount = permission.fetchone()
    loanAccount = loans.fetchone()
    accountNum = account_number.fetchone()
    print(name_cursor.fetchone())
    username, password = name_cursor.fetchone()
    money = account_money.fetchone()
    accountName = str(accountName1.get())
    accountPassword = accountPassword1.get()
    accountNumber = int(accountNumber1.get())
    if str(accountName) == username:
        print(accountPassword)
        passwords = bytes.decode(password,
                                 encoding='utf8')
        if bytes(accountPassword, encoding='utf-8') == base64.b64decode(
                passwords):
            accountNumber2 = base64.b64decode(accountNum)
            accountNumber2 = accountNumber2.decode(encoding="utf-8")
            if accountNumber == accountNumber2:
                def withdrawer():
                    """ withdrawer"""
                    nonlocal info
                    info.destroy()
                    howMuch = toModifyMoney.get()
                    account.Withdraw(howMuch, accountName)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=6, column=0)

                def depositer():
                    """ depositer"""
                    nonlocal info
                    info.destroy()
                    depositMoney = toModifyMoney.get()
                    account.Deposit(depositMoney, accountName)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=6, column=0)

                def transfer():
                    """ transfer money"""
                    nonlocal info
                    info.destroy()
                    transferMoneyAccount = transferAccountName.get()
                    transferMoney = toModifyMoney.get()
                    account.Transfer(transferMoneyAccount, transferMoney)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=6, column=0)

                def payback():
                    """ pay back loans GUI"""
                    msgText = "Cash or account money"
                    msgBody = "Do you want to pay in Account " \
                              "Money?"
                    msg = tkinter.messagebox.askyesno(msgText, msgBody)
                    if msg:
                        accountMoneySQL.execute("UPDATE account_money SET "
                                                "balance = ? WHERE (name = "
                                                "?)",
                                                (account.balance -
                                                 int(loanAccount),
                                                 account.name))
                        account.balance -= loanAccount
                        bankMoney["Public Money"] += loanAccount
                        # TODO: RESET TO 0
                        logger(f"Pay backed "
                               f"{loanAccount} by "
                               f"{accountName} by balance")
                        TextMSG = "returned the loan with account money!"
                        tkinter.messagebox.showinfo("Successful loan payback!",
                                                    TextMSG)
                    else:
                        bankMoney["Public Money"] += loanAccount
                        logger(f"Pay backed "
                               f"{loanAccount} by "
                               f"{accountName} by cash")
                        # TODO: RESET TO 0
                        TextMSG = "returned the loan with cash!"
                        tkinter.messagebox.showinfo("Successful loan payback!",
                                                    TextMSG)

                money = float(money)
                account = Account(str(accountName), accountPassword,
                                  money)
                info = tkinter.Label(root, text=account.__str__())
                info.grid(row=6, column=0)
                accountName1.configure(state="disabled")
                accountPassword1.configure(state="disabled")
                accountNumber1.configure(state="disabled")
                login.configure(state='disabled')
                if __name__ == "__main__":
                    mainFrame = tkinter.Frame(root)
                    mainFrame.grid(row=6, column=0)
                    toModifyMoney = tkinter.Entry(mainFrame)
                    toModifyMoney.grid(row=0, column=0, padx=20)
                    withdraw = tkinter.Button(mainFrame, text="Withdraw",
                                              command=withdrawer)
                    withdraw.grid(row=1, column=0)
                    deposit = tkinter.Button(mainFrame, text="Deposit",
                                             command=depositer)
                    deposit.grid(row=1, column=1, padx=10)
                    transfer = tkinter.Button(mainFrame, text="Transfer",
                                              command=transfer)
                    transfer.grid(row=1, column=2)
                    if loanAccount > 0:
                        paybackLoan = tkinter.Button(mainFrame,
                                                     text="PayBack "
                                                          "loans",
                                                     command=payback)
                        paybackLoan.grid(row=1, column=3, padx=10)
                        loaner = loanAccount
                        if not account.balance > loaner and account.balance \
                                - loaner > minAm:
                            paybackLoan.configure(state="disabled")
                            logger(f"The balance of "
                                   f"{money} is less"
                                   f"than the amount of debt! or the "
                                   f"remainder is less than 500!")
                            tmsg("Not enough money",
                                 "The balance should be more than the "
                                 "amount of debt! or the remainder after "
                                 "payback should be more than 500")
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
        tmsg("User not found",
             "The user doesn't exist! login with a user from the database")
        logger(
            f"Tried to logon with a user that doesn't exist ({accountName}) at "
            f"{(pytz.utc.localize(datetime.datetime.now()))}")

    logger(f"exited program at {pytz.utc.localize(datetime.datetime.now())}")


def start_old_app():
    """ the old version of the app, for migrating from old to new system!"""
    global loanAccount
    username = str(accountName1.get())
    accountPassword = accountPassword1.get()
    accountNumber = int(accountNumber1.get())
    money = accountMoney[username]
    loan_account = loanAccount[username]
    if username in userNamesDataBase:
        passwords = bytes(userNamesDataBase[username])
        accountPassword = bytes(str(accountPassword), encoding='utf8')
        if accountPassword in base64.standard_b64decode(passwords):
            accountNumbers = base64.standard_b64decode(
                bytes.decode(userAccountNumber[username]))
            if bytes(accountNumber) == accountNumbers:
                account = Account(username, accountPassword,
                                  money)

                def withdrawer():
                    """ withdrawer"""
                    nonlocal info
                    info.destroy()
                    howMuch = toModifyMoney.get()
                    account.Withdraw(howMuch, username)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=6, column=0)

                def depositer():
                    """ depositer"""
                    nonlocal info
                    info.destroy()
                    depositMoney = toModifyMoney.get()
                    account.Deposit(depositMoney, username)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=6, column=0)

                def transfer():
                    """ transfer money"""
                    nonlocal info
                    info.destroy()
                    transferMoneyAccount = transferAccountName.get()
                    transferMoney = toModifyMoney.get()
                    account.Transfer(transferMoneyAccount, transferMoney)
                    info = tkinter.Label(root, text=account.__str__())
                    info.grid(row=6, column=0)

                def payback():
                    """ pay back loans GUI"""
                    nonlocal money
                    nonlocal loan_account
                    msgText = "Cash or account money"
                    msgBody = "Do you want to pay in Account " \
                              "Money?"
                    msg = tkinter.messagebox.askyesno(
                        msgText, msgBody)
                    if msg:
                        money -= int(loan_account)
                        account.balance -= loan_account
                        bankMoney["Public Money"] += loan_account
                        logger(f"Pay backed "
                               f"{loan_account} by "
                               f"{username} by balance")
                        loanAccount[username] = 0
                        TextMSG = "returned the loan with " \
                                  "account money!"
                        tkinter.messagebox.showinfo(
                            "Successful loan payback!", TextMSG)
                    else:
                        bankMoney["Public Money"] += int(loan_account)
                        logger(f"Pay backed {loan_account} by "
                               f"{username} by cash")
                        loanAccount[username] = 0
                        TextMSG = "returned the loan with cash!"
                        tkinter.messagebox.showinfo("Successful loan payback!",
                                                    TextMSG)

                money = float(money)
                account = Account(str(username), accountPassword,
                                  money)
                info = tkinter.Label(root, text=account.__str__())
                info.grid(row=6, column=0)
                accountName1.configure(state="disabled")
                accountPassword1.configure(state="disabled")
                accountNumber1.configure(state="disabled")
                backwards_compatibility.configure(state="disabled")
                login.configure(state='disabled')
                if __name__ == "__main__":
                    mainFrame = tkinter.Frame(root)
                    mainFrame.grid(row=7, column=0)
                    toModifyMoney = tkinter.Entry(mainFrame)
                    toModifyMoney.grid(row=0, column=0, padx=20)
                    withdraw = tkinter.Button(mainFrame, text="Withdraw",
                                              command=withdrawer)
                    withdraw.grid(row=1, column=0)
                    deposit = tkinter.Button(mainFrame, text="Deposit",
                                             command=depositer)
                    deposit.grid(row=1, column=1, padx=10)
                    transfer = tkinter.Button(mainFrame, text="Transfer",
                                              command=transfer)
                    transfer.grid(row=1, column=2)
                    if loanAccount > 0:
                        paybackLoan = tkinter.Button(mainFrame,
                                                     text="PayBack "
                                                          "loans",
                                                     command=payback)
                        paybackLoan.grid(row=1, column=3, padx=10)
                        loaner = loanAccount
                        if not account.balance > loaner and account.balance \
                                - loaner > minAm:
                            paybackLoan.configure(state="disabled")
                            logger(f"The balance of "
                                   f"{money} is less"
                                   f"than the amount of debt! or the "
                                   f"remainder is less than 500!")
                            tmsg("Not enough money",
                                 "The balance should be more than the "
                                 "amount of debt! or the remainder after "
                                 "payback should be more than 500")
                    if toModifyMoney == "FD":
                        confi = input("[M]months or [Y]ears?")
                        if FD[username] == 0 and confi == "Y":
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

                                print("SUCCESSFUL FD!")
                                print(account.__str__())
                        if FD[username] == 0 and conf == "M":
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

                                print("SUCCESSFUL FD!")
                        if FD[username] != 0:
                            confir = input("Do you want to [D]delete your FD?")
                            if confir == "D":
                                del FD[username]

                    if toModifyMoney == "L":
                        time = (pytz.utc.localize(datetime.datetime.now()))
                        logger(f"Successful logout at {time} By "
                               f"{username}")
                        exit()
            else:
                tmsg('wrong account number', 'account number error!')
        else:
            time = (pytz.utc.localize(datetime.datetime.now()))
            logger(f"Unsuccessful login at {time} By {username}! "
                   f"Incorrect Password!")
            tmsg("Password Incorrect", "The password is wrong! try again!")
    else:
        tmsg("User doesn't exist!",
             "The user doesn't exist! login with a user from the database")
        logger(
            f"Tried to logon with a user that doesn't exist "
            f"({username}) at "
            f"{(pytz.utc.localize(datetime.datetime.now()))}")

    logger(f"exited program at {pytz.utc.localize(datetime.datetime.now())}")


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
    value = tkinter.IntVar()
    textMsg = "Optimize for old accounts (Standard base64)"
    backwards_compatibility = tkinter.Checkbutton(master=root, text=textMsg,
                                                  variable=value)
    backwards_compatibility.grid(row=4, column=1)


    def starter():
        # global start_app
        if value.get() == 0:
            start_app()
        else:
            start_old_app()


    login = tkinter.Button(root, text="Login with these credentials!",
                           command=starter)
    login.grid(row=4, column=0)

    root.mainloop()
except KeyboardInterrupt:
    logger(f"program crashed on {pytz.utc.localize(datetime.datetime.now())}")
if current_Time > "2022 06 24":
    print("THIS VERSION IS NOW OUT OF SUPPORT AND WILL NOT RECEIVE ANY "
          "UPDATES AT ALL. SO, PLEASE RE-CONSIDER USING THIS PROGRAM!")
    conf = input("DO YOU WANT TO STILL USE THIS PROGRAM?")
    if conf.casefold() == "Y":
        exit()


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
            log.write(text)


class Account:
    """
    Bank accounts for the people side.
    """
    global accountName1
    global accountPassword1
    global accountNumber1

    def __init__(self, name, password, balance):
        self.name = name
        self.password = password
        self.balance = int(balance)
        currentTime = (pytz.utc.localize(datetime.datetime.now()))
        logger(f"Successful login at {currentTime} By {self.name}")

    def Deposit(self, amount, userName):
        """
        Deposits amount
        :param amount: Amount to be deposited to account
        :param userName: The destination account
        :return:Added money
        """
        amount = float(amount)
        if amount > 0:
            if ageOfAccount == "Normal Account":
                self.balance += amount
                accountMoneySQL.execute("UPDATE account_money SET balance = ? "
                                        "WHERE (name = ?)", (self.balance +
                                                             amount, userName))
                logger(f"Deposit success! Your updated bank balance - "
                       f"{self.balance}")
                msg = f"deposit successful of {amount = }"
                tkinter.messagebox.showinfo("Success!", msg)
            elif ageOfAccount == "Child Account":
                if amount <= kidWithdrawMax and self.balance + amount <= \
                        childMoneyMax:
                    self.balance += amount
                    accountMoneySQL.execute("UPDATE account_money SET balance ="
                                            " ? WHERE (name = ?)", (self.balance
                                                                    + amount,
                                                                    userName))
                    logger(f"Deposit success! Your updated bank balance - "
                           f"{self.balance}")
                    msg = f"deposit successful of {amount = }"
                    tkinter.messagebox.showinfo("Success!", msg)
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
            tmsg("Amount is less than 0!", "The deposit amount should be more "
                                           "than 0! Deposit failed")
            logger(f"Unsuccessful deposit of {amount} INR! The amount must be "
                   f"more than 0!")

    def Withdraw(self, total, userName):
        """
        Withdraws amount from total money in account
        :param total:Amount to be taken from the account
        :param userName: The destination account
        :return:Remaining money
        """
        global minAm
        self.balance = float(self.balance)
        total = float(total)
        if ageOfAccount == "Normal Account":
            if self.balance > minAm:
                if self.balance >= total > 0:
                    if (self.balance - total) > minAm:
                        accountMoneySQL.execute("UPDATE account_money SET "
                                                "balance = ? WHERE (name = ?)",
                                                (self.balance - total, userName)
                                                )
                        self.balance -= total
                        logger(
                            f"Withdrawal success! Your updated bank balance- "
                            f"{self.balance} ")
                        msg = f"withdraw successful of {total = }"
                        tkinter.messagebox.showinfo("Success!", msg)
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
        elif ageOfAccount == "Child Account":
            if self.balance > minAm:
                total = float(total)
                if self.balance >= total <= kidWithdrawMax > 0:
                    if self.balance - total >= minAm:
                        accountMoneySQL.execute("UPDATE account_money SET "
                                                "balance = ? WHERE (name = ?)",
                                                (self.balance - total, userName)
                                                )
                        self.balance -= total
                        logger(
                            f"Withdrawal success! Your updated bank balance- "
                            f"{self.balance} ")
                    else:
                        print("The remainder of the withdrawal should be more "
                              f"than {minAm}!")
                        logger(f"Unsuccessful Withdrawal of {total} INR! The "
                               f"balance after the transaction should be more "
                               f"than {minAm}!")

                else:
                    print(f"The specified amount is more than the maximum "
                          f"amount of withdrawal - ({kidWithdrawMax=})")
                    logger(f"Unsuccessful Withdrawal of {total} INR! The "
                           f"amount shouldn't be more than the maximum "
                           f"withdrawal amount of {kidWithdrawMax}!")
        else:
            print(f"The balance should be more than {minAm} to withdraw from "
                  f"account")
            logger(f"Unsuccessful Withdrawal of {total} INR! The "
                   f"balance should be more than {minAm}!")

    def Transfer(self, username, amount):
        """
        transfer amount from one to another
        :param username:The account which it's going to transfer `amount`
        :param amount:The total money which it's going to send to `account`
        :return:`amount` to `account` in the `accountMoney` shelve
        """
        global minAm
        self.balance = float(self.balance)
        minAm = float(minAm)
        amount = float(amount)
        if username in userNamesDataBase:
            if self.balance > amount > 0:
                if (self.balance - amount) >= minAm:
                    if ageOfAccount == "Normal Account":
                        self.balance -= amount
                        money -= amount
                        money += amount
                        logger(f"Transferred {amount} INR to {username}")
                        msg = f"transfer successful of {amount} to " \
                              f"{username}"
                        tkinter.messagebox.showinfo("Success!", msg)
                    else:
                        if (float(money) + amount) <= \
                                childMoneyMax:
                            self.balance -= amount
                            money += amount
                            logger(f"Transferred {amount} INR to {username}")
                            msg = f"transfer successful of {amount} to " \
                                  f"{username}, a child account!"
                            tkinter.messagebox.showinfo("Success!", msg)
                        else:
                            logger("The balance amount for the child account "
                                   "is more when deposited. so deposit "
                                   "rejected. try again with a different "
                                   "amount")
                            tmsg("unsuccessful transfer", "unsuccessful! the "
                                                          "remaining balance "
                                                          "in the child account"
                                                          " is more when "
                                                          f"deposited!("
                                                          f"{childMoneyMax=})")
                else:
                    tmsg("error", f"The amount left should be more than"
                                  f" {minAm}!")
                    logger(f"Unsuccessful Transfer of {amount} INR to"
                           f" {username}! the remaining balance of the "
                           f"transaction should be more than {minAm}!")
            else:
                tmsg("Not enough money", f"The amount isn't good enough to "
                                         f"transfer {amount}")
                logger(f"Unsuccessful Transfer of {amount} INR to {username}"
                       f"!Insufficient balance to transfer money")
        else:
            tmsg("User not found", "The specified user doesn't exist! error "
                                   "404")
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
                    money -= Amount
                    bankMoney["Public Money"] += Amount
                    FD[self.name] += Amount
            return f"The FD process is finished! {Amount=}"
        else:
            CI = principle * (1 + (rate / 12)) ** (12 * nYears) - principle
            Amount = principle + CI
            if self.balance >= minAm and (self.balance - Amount) >= minAm:
                if float(bankMoney["Public Money"]) >= Amount:
                    self.balance -= Amount
                    money -= Amount
                    bankMoney["Public Money"] += Amount
                    FD[self.name] += Amount
            return f"The FD process is finished! {Amount=}"

    def __str__(self):
        return f"\nYour bank balance - {None}\n" \
               f"Debt - {loanAccount}\n" \
               f"Account Type - {ageOfAccount}\n" \
               f"Fixed Deposit - {FD[self.name]}\n"


userNamesDataBaseSQL.close()
userAccountNumberSQL.close()
accountMoneySQL.close()
loanAccountSQL.close()
ageOfAccountSQL.close()
FDSQL.close()
