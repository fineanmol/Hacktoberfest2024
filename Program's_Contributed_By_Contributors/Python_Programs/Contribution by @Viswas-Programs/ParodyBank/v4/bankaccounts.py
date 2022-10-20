"""
Bank account
"""
import datetime
import shelve
import pytz
import os
import platform
import base64

if platform.system() == "Windows":
    if os.access(f"{os.getenv('USERPROFILE')}\\Documents\\Bank account "
                 "essentials", os.F_OK) is True:
        path = f"{os.getenv('USERPROFILE')}\\Documents\\Bank account essentials"
        bankMoney = shelve.open(f"{path}\\bankMoney")
        userNamesDataBase = shelve.open(f"{path}\\bankAccountNames")
        userAccountNumber = shelve.open(f"{path}\\bankAccountNumbers")
        accountMoney = shelve.open(f"{path}\\accountHolderMoney")
        loanAccount = shelve.open(f"{path}\\loanAccount")
        ageOfAccount = shelve.open(f"{path}\\permissions")
else:
    if os.access(f"{os.getenv('HOME')}/Documents/Bank account essentials",
                 os.F_OK) is True:
        path = f"{os.getenv('HOME')}/Documents/Bank account essentials"
        bankMoney = shelve.open(f"{path}/bankMoney")
        userNamesDataBase = shelve.open(f"{path}/bankAccountNames")
        userAccountNumber = shelve.open(f"{path}/bankAccountNumbers")
        accountMoney = shelve.open(f"{path}/accountHolderMoney")
        loanAccount = shelve.open(f"{path}/loanAccount")
        ageOfAccount = shelve.open(f"{path}/permissions")
childMoneyMax = 5000
kidWithdrawMax = 2000
CT = datetime.datetime.strftime(datetime.datetime.now(), "%Y %m %d")
if CT > "2022 05 22":
    print("THIS VERSION IS NOW OUT OF SUPPORT AND WILL NOT RECEIVE ANY "
          "UPDATES AT ALL. SO, PLEASE CONSIDER USING THIS PROGRAM!")
    conf = input("DO YOU WANT TO STILL USE THIS PROGRAM?")
    if conf == "N" or conf == "n":
        quit(__name__)


def logger(text):
    """
    Logs activity in the account to `_bank_log.txt`
    :param text: The text in the log
    :return: `text` to log
    """
    if platform.system() == "Windows":
        if os.access(f"{os.getenv('USERPROFILE')}\\Documents\\_bank_log_v5.txt",
                     os.R_OK and os.W_OK):
            with open(f"{os.getenv('USERPROFILE')}\\Documents\\_bank_log_v5.txt"
                    , "a") as log:
                print(text, file=log)
    else:
        if os.access(f"{os.getenv('HOME')}/Documents/_bank_log_v5.txt",
                     os.R_OK and os.W_OK):
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
        self.balance = balance
        print(f"Log in successful for {self.name}")
        currentTime = (pytz.utc.localize(datetime.datetime.utcnow())
                       .astimezone())
        logger(f"Successful login at {currentTime} By {accountName}")

    def Deposit(self, amount, userName):
        """
        Deposits amount
        :param amount: Amount to be deposited to account
        :param userName: The destination account
        :return:Added money
        """
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
                    print(
                        f"Child account cannot deposit more than "
                        f"{kidWithdrawMax} INR and the balance shouldn't "
                        f"cross {childMoneyMax}")
        else:
            print("The deposit amount should be more than 0! Deposit failed")
            logger(f"Unsuccessful deposit of {amount} INR! The amount must be "
                   f"more than 0!")
        print(self.__str__())

    def Withdraw(self, total, userName):
        """
        Withdraws amount from total money in account
        :param total:Amount to be withdrawed from the account
        :param userName: The destination account
        :return:Remaining money
        """
        if ageOfAccount[userName] == "Normal Account":
            if self.balance > 500:
                if self.balance >= total > 0:
                    if (self.balance - total) > 500:
                        accountMoney[userName] -= total
                        self.balance -= total
                        logger(
                            f"Withdrawal success! Your updated bank balance- "
                            f"{self.balance} ")
                    else:
                        print("The remainder of the withdrawal should be more "
                              "than 500!")
                        logger(f"Unsuccessful Withdrawal of {total} INR! The "
                               f"balance after the transaction should be more "
                               f"than 500!")

                else:
                    print(f"Not enough money to withdraw {total} INR")
                    logger(f"Unsuccessful Withdrawal of {total} INR! The "
                           f"balance of the account should be more than the "
                           f"transaction amount!")
        elif ageOfAccount[userName] == "Child Account":
            if self.balance > 500:
                if self.balance >= total <= kidWithdrawMax:
                    if self.balance - total >= 500:
                        accountMoney[userName] -= total
                        self.balance -= total
                        logger(
                            f"Withdrawal success! Your updated bank balance- "
                            f"{self.balance} ")
                    else:
                        print("The remainder of the withdrawal should be more "
                              "than 500!")
                        logger(f"Unsuccessful Withdrawal of {total} INR! The "
                               f"balance after the transaction should be more "
                               f"than 500!")

                else:
                    print(f"The specified amount is more than the maximum "
                          f"amount of withdrawal - ({kidWithdrawMax})")
                    logger(f"Unsuccessful Withdrawal of {total} INR! The "
                           f"amount shouldn't be more than the maximum "
                           f"withdrawal amount of {kidWithdrawMax}!")
        else:
            print(f"The balance should be more than 500 to withdraw from "
                  f"account")
            logger(f"Unsuccessful Withdrawal of {total} INR! The "
                   f"balance should be more than 500!")

    def Transfer(self, username, amount):
        """
        transfer amount from one to another
        :param username:The account which it's going to transfer `amount`
        :param amount:The total money which it's going to send to `account`
        :return:`amount` to `account` in the `accountMoney` shelve
        """
        if username in userNamesDataBase:
            if self.balance > amount:
                if (self.balance - amount) > 500:
                    if ageOfAccount[username] == "Normal Account":
                        self.balance -= amount
                        accountMoney[accountName] -= amount
                        accountMoney[username] += amount
                        logger(f"Transferred {amount} INR to {username}")
                    else:
                        if (accountMoney[username] + amount) <= 5000:
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
                            print("unsuccesful! the reminder in the child "
                                  "account is more when deposited!")
                else:
                    print("The amount left should be more than 500!")
                    logger(f"Unsuccessful Transfer of {amount} INR to"
                           f" {username}! the remaining balance of the "
                           f"transaction should be more than 500!")
            else:
                print(f"The amount isn't good enough to transfer {amount}")
                logger(f"Unsuccessful Transfer of {amount} INR to {username}"
                       f"!Insufficient balance to transfer money")
        else:
            print("The specified user doesn't exist! error 404")
            logger(f"Unsuccessful transfer of {amount} INR to {username}! "
                   f"Incorrect Username!")

    def __str__(self):
        return f"Your credentials- \n\tUsername - \n\t\t{accountName}\n " \
               f"\tPassword - \n\t\t{accountPassword}\n" \
               f"Your bank balance - \n\t{accountMoney[accountName]}\n" \
               f"Debt - \n\t{loanAccount[accountName]}\n" \
               f"Account Type - \n\t{ageOfAccount[accountName]}"


print("Bank accounts program v4")
accountName = input("What is your account name?")
accountPassword = input(f"What is your password for {accountName}?")
accountNumber = int(input("What is your account number ?"))

logger(f"program started at {pytz.utc.localize(datetime.datetime.now())}")
if accountName in userNamesDataBase:
    passwords = bytes(userNamesDataBase[accountName])
    accountPassword = bytes(accountPassword, encoding='utf8')
    if accountPassword in base64.standard_b64decode(passwords):
        accountNumbers = bytes(userAccountNumber[accountName])
        accountNumber = bytes(accountNumber)
        if accountNumber == base64.standard_b64decode(accountNumbers):
            money = accountMoney[accountName]
            account = Account(accountName, accountPassword, money)
            print(account)
            while __name__ == "__main__":
                print(f"\nUPDATED BANK BALANCE -> {account.balance}")
                confirmation = input("Withdraw or deposit?\n [W for withdrawal "
                                     "\n D for deposit\n T for transfer\n P "
                                     "for Paybacking the loan\n"
                                     " L for log out].(Casing matters)>_")
                if confirmation == "W":
                    howMuch = int(input(f"How much you wanted to withdraw from "
                                        f"the balance of "
                                        f"{account.balance}?"))

                    account.Withdraw(howMuch, accountName)
                    os.system("cls")
                    print(account)

                if confirmation == "D":
                    depositMoney = int(input(f"How much you want to deposit to "
                                             f"the balance?"))
                    account.Deposit(depositMoney, accountName)
                    os.system("cls")
                    print(account)
                if confirmation == "T":
                    transferMoney = int(input(f"How much money you want to "
                                              f"transfer"))
                    transferMoneyAccount = input("What account are you going "
                                                 "to transfer to")
                    account.Transfer(transferMoneyAccount, transferMoney)
                    os.system("cls")
                    print(account)
                if confirmation == "P":
                    if loanAccount[accountName] > 0:
                        if account.balance > loanAccount[accountName]:
                            if account.balance - loanAccount[accountName] > 500:
                                cashOrAcc = input("Cash or Account Money\n "
                                                  "AM-Account Money\n"
                                                  "C-Cash")
                                if cashOrAcc == "AM":
                                    accountMoney[accountName] -= loanAccount[
                                        accountName]
                                    account.balance -= loanAccount[accountName]
                                    bankMoney["Public Money"] += loanAccount[
                                        accountName]
                                    logger(f"Pay backed "
                                           f"{loanAccount[accountName]} by "
                                           f"{accountName} by account balance")
                                    loanAccount[accountName] = 0
                                    print("Paybacked the loan with account")
                                else:
                                    bankMoney["Public Money"] += loanAccount[
                                        accountName]
                                    logger(f"Pay backed "
                                           f"{loanAccount[accountName]} by "
                                           f"{accountName} by cash")
                                    loanAccount[accountName] = 0
                                    print("Pay backed the loan with cash")
                            else:
                                logger("Unsuccessfull payback The amount after "
                                       "the payback should be more than 500!")
                                print("The remainder after the payback will "
                                      "be less than 500 and that's not allowed")
                        else:
                            logger(f"The balance of "
                                   f"{accountMoney[accountName]} is less than"
                                   f"the amount of debt!")
                            print("The balance should be more than the amount"
                                  " of debt!")
                    else:
                        logger(f"No debt to pay off now by {accountName}!")
                        print("NO debt to pay off here\n")
                    os.system("cls")
                    print(account)
                if confirmation == "L":
                    time = (pytz.utc.localize(datetime.datetime.utcnow())
                            .astimezone())
                    logger(f"Successful logout at {time} By {accountName}")
                    break
    else:
        time = (pytz.utc.localize(datetime.datetime.utcnow()).astimezone())
        logger(f"Unsuccessful login at {time} By {accountName}! Incorrect "
               f"Password!")
        print("The password is wrong! try again!")
else:
    print("The user doesn't exist! please login with a user from the database")
    logger(f"Tried to logon with a user that doesn't exist (Error 404) at "
           f"{(pytz.utc.localize(datetime.datetime.utcnow()).astimezone())}")

logger(f"exited the program at {pytz.utc.localize(datetime.datetime.now())}")
userNamesDataBase.close()
userAccountNumber.close()
accountMoney.close()
loanAccount.close()
ageOfAccount.close()
