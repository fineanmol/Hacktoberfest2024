"""
Used to create dictionaries in shelves for each user data
"""
import os
import platform
import shelve
import base64

if platform.system() == "Windows":
    if os.access(f"{os.getenv('USERPROFILE')}\\Documents\\Bank account "
                 "essentials", os.F_OK) is True:
        path = f"{os.getenv('USERPROFILE')}\\Documents\\Bank account essentials"
        bankMoney = shelve.open(f"{path}\\bankMoney")
        location = shelve.open(f"{path}\\bankAccountNames")
        bankAccountNumbers = shelve.open(f"{path}\\bankAccountNumbers")
        accountMoney = shelve.open(f"{path}\\accountHolderMoney")
        loanAccount = shelve.open(f"{path}\\loanAccount")
        FD = shelve.open(f"{path}\\FD")
        permissions = shelve.open(f"{path}\\permissions")
    else:
        os.mkdir(f"{os.getenv('USERPROFILE')}\\Documents\\Bank account "
                 f"essentials")
        path = f"{os.getenv('USERPROFILE')}\\Documents\\Bank account essentials"
        bankMoney = shelve.open(f"{path}\\bankMoney")
        location = shelve.open(f"{path}\\bankAccountNames")
        bankAccountNumbers = shelve.open(f"{path}\\bankAccountNumbers")
        accountMoney = shelve.open(f"{path}\\accountHolderMoney")
        loanAccount = shelve.open(f"{path}\\loanAccount")
        FD = shelve.open(f"{path}\\FD")
        permissions = shelve.open(f"{path}\\permissions")
else:
    if os.access(f"{os.getenv('HOME')}/Documents/Bank account essentials",
                 os.F_OK) is True:
        path = f"{os.getenv('HOME')}/Documents/Bank account essentials"
        bankMoney = shelve.open(f"{path}/bankMoney")
        location = shelve.open(f"{path}/bankAccountNames")
        bankAccountNumbers = shelve.open(f"{path}/bankAccountNumbers")
        accountMoney = shelve.open(f"{path}/accountHolderMoney")
        loanAccount = shelve.open(f"{path}/loanAccount")
        FD = shelve.open(f"{path}/FD")
        permissions = shelve.open(f"{path}/permissions")
    else:
        os.mkdir(f"{os.getenv('HOME')}/Documents/Bank account essentials")
        path = f"{os.getenv('HOME')}/Documents/Bank account essentials"
        bankMoney = shelve.open(f"{path}/bankMoney")
        location = shelve.open(f"{path}/bankAccountNames")
        bankAccountNumbers = shelve.open(f"{path}/bankAccountNumbers")
        accountMoney = shelve.open(f"{path}/accountHolderMoney")
        loanAccount = shelve.open(f"{path}/loanAccount")
        FD = shelve.open(f"{path}/FD")
        permissions = shelve.open(f"{path}/permissions")


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
    if mode == "AE":
        location[account] = base64.b64encode(bytes(password, encoding='utf8'))
        bankAccountNumbers[account] = base64.b64encode(bytes(accountNum))
        accountMoney[account] = money
        loanAccount[account] = loan
        FD[account] = fd
        if permission == "N":
            permissions[account] = "Normal Account"
        else:
            permissions[account] = "Child Account"
        print("Created user successfully")
    else:
        bankMoney["Public Money"] += accountMoney[account]
        del location[account]
        del bankAccountNumbers[account]
        del accountMoney[account]
        del loanAccount[account]
        del FD[account]
        del permissions[account]


if __name__ == "__main__":
    print("bank account set up program v5 RTM")
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
location.close()
bankAccountNumbers.close()
accountMoney.close()
loanAccount.close()
permissions.close()
