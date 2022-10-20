"""
Used to create dictionaries in shelves for each user data
"""
import os
import platform
import shelve
import base64
import sqlite3

if platform.system() == "Windows":
    if os.access(f"{os.getenv('USERPROFILE')}\\Documents\\Bank account "
                 "essentials", os.F_OK) is True:
        path = f"{os.getenv('USERPROFILE')}\\Documents\\Bank account essentials"
    else:
        os.mkdir(f"{os.getenv('USERPROFILE')}\\Documents\\Bank account "
                 f"essentials")
        path = f"{os.getenv('USERPROFILE')}\\Documents\\Bank account essentials"
else:
    if os.access(f"{os.getenv('HOME')}/Documents/Bank account essentials",
                 os.F_OK) is True:
        path = f"{os.getenv('HOME')}/Documents/Bank account essentials"
    else:
        os.mkdir(f"{os.getenv('HOME')}/Documents/Bank account essentials")
        path = f"{os.getenv('HOME')}/Documents/Bank account essentials"
bankMoney = sqlite3.connect(f"{path}/bankMoney.sqlite")
bankMoney.execute("CREATE TABLE IF NOT EXISTS bank_balance (money_type "
                  "TEXT PRIMARY KEY NOT NULL, balance INTEGER NOT NULL)")
names = sqlite3.connect(f"{path}/bankAccountNames.sqlite")
names.execute("CREATE TABLE IF NOT EXISTS account_name (name TEXT "
              "PRIMARY KEY NOT NULL, password TEXT NOT NULL)")
bankAccountNumbers = sqlite3.connect(f"{path}/bankAccountNumbers.sqlite")
bankAccountNumbers.execute("CREATE TABLE IF NOT EXISTS account_number ("
                           "name TEXT PRIMARY KEY NOT NULL, number INTEGER NOT"
                           " NULL)")
accountMoney = sqlite3.connect(f"{path}/accountHolderMoney.sqlite")
accountMoney.execute("CREATE TABLE IF NOT EXISTS account_money (name "
                     "TEXT PRIMARY KEY NOT NULL, balance INTEGER NOT NULL)")
loanAccount = sqlite3.connect(f"{path}/loanAccount.sqlite")
loanAccount.execute("CREATE TABLE IF NOT EXISTS account_loan (name TEXT "
                    "PRIMARY KEY NOT NULL, loan_amount INTEGER NOT NULL)")
FD = sqlite3.connect(f"{path}/FD.sqlite")
FD.execute("CREATE TABLE IF NOT EXISTS account_FD (name TEXT "
           "PRIMARY KEY NOT NULL, fd_amount INTEGER NOT NULL)")
permissions = sqlite3.connect(f"{path}/permissions.sqlite")
permissions.execute("CREATE TABLE IF NOT EXISTS permissions (name TEXT "
                    "PRIMARY KEY NOT NULL, permission TEXT NOT NULL)")


def setupAccount(account, password, accountNum, money, permission, mode,
                 loan=0, fd=0):
    """
    Setup accounts
    :param fd: Fixed deposit amount
    :param account: The name of the account
    :param password: The password of `account`
    :param accountNum: The account number for `account`
    :param money: The money to be initialized for `account`
    :param permission: The permissions to be setup (Normal Account or Child
    Account)
    :param mode: the mode to set up accounts. Delete or Setup
    :param loan: The loan for `account`. defaults to 0 when not defined
    :return: None
    """
    # bankMoney_cursor = bankMoney.cursor()
    bankAccountNumbers_cursor = bankAccountNumbers.cursor()
    names_cursor = names.cursor()
    accountMoney_cursor = accountMoney.cursor()
    loanAccount_cursor = loanAccount.cursor()
    FD_cursor = FD.cursor()
    permissions_cursor = permissions.cursor()
    if mode == "AE":
        acc_password = base64.b64encode(bytes(password, encoding='utf8'))
        names_cursor.execute("INSERT INTO account_name VALUES(?, ?)",
                             (account, acc_password))
        account_num = base64.b64encode(bytes(str(accountNum), encoding="utf-8"))
        bankAccountNumbers_cursor.execute("INSERT INTO account_number VALUES(?,"
                                          "?)", (account, account_num))
        accountMoney_cursor.execute("INSERT INTO account_money VALUES(?, ?)",
                                    (account, money))
        loanAccount_cursor.execute("INSERT INTO account_loan VALUES(?, ?)",
                                   (account, loan))
        if permission == "N":
            permission = "Normal Account"
            SET_FD = True
        else:
            permission = "Child Account"
            SET_FD = False
        permissions_cursor.execute("INSERT INTO permissions VALUES(?, ?)",
                                   (account, permission))

        if SET_FD:
            FD_cursor.execute("INSERT INTO account_fd VALUES(?, ?)",
                              (account, fd))
        elif SET_FD is False:
            print("NO FD FOR CHILDREN!")
        else:
            raise TypeError(f"The SET_FD var isn't a bool!(DEBUG->{SET_FD=})")
        cursors = ['FD_cursor', 'permissions_cursor',
                   'accountMoney_cursor', 'bankAccountNumbers_cursor',
                   'names_cursor', 'loanAccount_cursor']
        dbs = ['FD', 'permissions', 'accountMoney', 'bankAccountNumbers',
               'names', 'loanAccount']
        cursors = list(set(cursors))
        for cursor in cursors:
            for db in dbs:
                exec(f"{db}.commit()")
            exec(f"{cursor}.close()")

        print("Created user successfully")
    else:
        bankMoney["Public Money"] += accountMoney[account]
        del names[account]
        del bankAccountNumbers[account]
        del accountMoney[account]
        del loanAccount[account]
        if FD[account]:
            del FD[account]
        del permissions[account]


if __name__ == "__main__":
    print("bank account set up program v5 BUILD- 5043")
    confirmation = input(
        "Add users or update bank's money?\n[AU for Users\n BM "
        "for Bank money update\n DU for deleting users\n L for "
        "Loan.](CASING MATTERS)\t>_")
    if confirmation == "AU":
        nUsers = int(input("How much users do you want to add"))
        for user in range(nUsers):
            userName = input("=-=-=-=-=-=-=-=-=-=-=-=-=-=\nUser name?")
            Password = input(f"Password for {userName}")
            age = int(input(f"Age for {userName}. must fill out"))
            if userName != Password and age > 13:
                bankAccountNumber = int(input(f"Account number for {userName}"))
                moneyAccountHolder = int(input(f"Money for {userName}"))
                setupAccount(userName, Password, bankAccountNumber,
                             moneyAccountHolder, "N", "AE")
            elif userName != Password and age <= 13:
                print("The money shouldn't be more than 5000!")
                bankAccountNumber = int(input(f"Account number for {userName}"))
                moneyAccountHolder = int(input(f"Money for {userName}"))
                if moneyAccountHolder <= 5000:
                    setupAccount(userName, Password, bankAccountNumber,
                                 moneyAccountHolder, "C", "AE")
                else:
                    print("Re-initialize the account properly! program exits")
                    break
            else:
                print("The account & password is matching! please separate"
                      "them!\nRerun the program please!")
                break
    elif confirmation == "DU":
        for key, value in accountMoney.items():
            print(f"{key} -> {value} INR")
        nUsers = int(input("How much users do you want to delete?"))
        for user in range(nUsers):
            username = input(f"Username of the user to delete(user {user + 1})")
            setupAccount(username, None, None, None, None, "D")
        print(f"{nUsers} users has been deleted successfully!")
    elif confirmation == "L":
        name = input("What is the account?")
        if permissions[name] == "Child Account":
            loanMax = 3000
            print(f"the maximum money of loan shouldn't be more than {loanMax}")
            loanAmount = int(input("What is the loan amount?"))
            if loanAmount <= loanMax:
                bankMoney["Public Money"] -= loanAmount
                loanAccount[name] = loanAmount
            else:
                print(f"the amount is more than {loanMax}! re-initialize loan "
                      f"if needed")
        else:
            loanAmount = int(input("What is the loan amount?"))
            bankMoney["Public Money"] -= loanAmount
            loanAccount[name] = loanAmount
            print(f"Successfully loaned {name} {loanAmount} INR")
    else:
        if ("Public Money" and "Reserve Money") in bankMoney.keys():
            print(f"{bankMoney['Public Money']}, {bankMoney['Reserve Money']}")
        else:
            print("the money has not been initialized yet! please initialize!")
        bankVaultMoney = int(input("How much public money would you like to be "
                                   "updated?"))
        bankReserveMoney = int(input("How much reserve money would like to be "
                                     "updated?"))
        bankMoney["Public Money"] = bankVaultMoney
        bankMoney["Reserve Money"] = bankReserveMoney

bankMoney.close()
names.close()
bankAccountNumbers.close()
accountMoney.close()
loanAccount.close()
permissions.close()
FD.close()
