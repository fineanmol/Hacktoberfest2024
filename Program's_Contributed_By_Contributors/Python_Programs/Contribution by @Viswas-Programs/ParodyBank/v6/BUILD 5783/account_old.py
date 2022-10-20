""" account class, but with SQL!"""
import pytz
import datetime
import tkinter
import tkinter.messagebox
import platform
import os
from tkinter.messagebox import showerror as tmsg
import shelve

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
            if ageOfAccount[userName] == "Normal Account":
                self.balance += amount
                accountMoney[userName] += amount
                logger(f"Deposit success! Your updated bank balance - "
                       f"{self.balance}")
                msg = f"deposit successful of {amount = }"
                tkinter.messagebox.showinfo("Success!", msg)
            elif ageOfAccount[userName] == "Child Account":
                if amount <= kidWithdrawMax and self.balance + amount <= \
                        childMoneyMax:
                    self.balance += amount
                    accountMoney[userName] += amount
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
        if ageOfAccount[userName] == "Normal Account":
            if self.balance > minAm:
                if self.balance >= total > 0:
                    if (self.balance - total) > minAm:
                        accountMoney[userName] -= total
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
        elif ageOfAccount[userName] == "Child Account":
            if self.balance > minAm:
                total = float(total)
                if self.balance >= total <= kidWithdrawMax > 0:
                    if self.balance - total >= minAm:
                        accountMoney[userName] -= total
                        self.balance -= total
                        logger(
                            f"Withdrawal success! Your updated bank balance- "
                            f"{self.balance} ")
                    else:
                        print("The remainder of the withdrawal should be more "
                              f"than {minAm}!")
                        logger(f"Unsuccessful Withdrawal of {total} INR! The "
                               f"balance after the transaction should be more "
                               f"than minAm!")

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
                   f"balance should be more than minAm!")

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
                    if ageOfAccount[username] == "Normal Account":
                        self.balance -= amount
                        accountMoney[self.name] -= amount
                        accountMoney[username] += amount
                        logger(f"Transferred {amount} INR to {username}")
                        msg = f"transfer successful of {amount} to "\
                              f"{username}"
                        tkinter.messagebox.showinfo("Success!", msg)
                    else:
                        if (float(accountMoney[username]) + amount) <= \
                                childMoneyMax:
                            self.balance -= amount
                            accountMoney[username] += amount
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
                           f"transaction should be more than minAm!")
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

