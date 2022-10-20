"""
Used to create dictionaries in shelves for each user data
"""
import base64
import shelve

bankMoney = shelve.open("C:\\Users\\viswa\\PycharmProjects\\OOP\\"
                        "Bankaccountfiles\\bankMoney")
location = shelve.open("C:\\Users\\viswa\\PycharmProjects\\OOP\\"
                       "Bankaccountfiles\\bankAccountNames")
bankAccountNumbers = shelve.open("C:\\Users\\viswa\\PycharmProjects\\OOP\\"
                                 "Bankaccountfiles\\bankAccountNumbers")
accountMoney = shelve.open("C:\\Users\\viswa\\PycharmProjects\\OOP\\"
                           "Bankaccountfiles\\accountHolderMoney")
loanAccount = shelve.open("C:\\Users\\viswa\\PycharmProjects\\OOP\\"
                          "Bankaccountfiles\\loanAccount")
permissions = shelve.open("C:\\Users\\viswa\\PycharmProjects\\OOP\\"
                          "Bankaccountfiles\\permissions")


def setupAccount(account, password, accountnum, money, permission, loan=0):
    """
    Setup accounts
    :param account: The name of the account
    :param password: The password of `account`
    :param accountnum: The account number for `account`
    :param money: The money to be initialized for `account`
    :param permission: The permissions to be setup (Normal Account or Child
    Account)
    :param loan: The loan for `account`. defaults to 0 when not defined
    :return: None
    """
    location[account] = base64.standard_b64encode(bytes(password,
                                                        encoding='utf8'))
    bankAccountNumbers[account] = base64.standard_b64encode(
        bytes(accountnum))
    accountMoney[account] = money
    loanAccount[account] = loan
    if permission == "N":
        permissions[account] = "Normal Account"
    else:
        permissions[account] = "Child Account"


def delAccount(account):
    """
    Setup accounts
    :param account: The name of the account
    :return: None
    """
    bankMoney["Public Money"] += accountMoney[account]
    del location[account]
    del bankAccountNumbers[account]
    del accountMoney[account]
    del loanAccount[account]
    del permissions[account]


if __name__ == "__main__":
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
                             moneyAccountHolder, "N")
            elif userName != Password and age <= 13:
                print("The money shouldn't be more than 5000!")
                bankAccountNumber = int(input(f"Account number for {userName}"))
                moneyAccountHolder = int(input(f"Money for {userName}"))
                if moneyAccountHolder <= 5000:
                    setupAccount(userName, Password, bankAccountNumber,
                                 moneyAccountHolder, "C")
                else:
                    print("Re-initialize the account properly! program exits")
                    break
            else:
                print("The account & password is matching! please separate"
                      "them!\nRerun the program please!")
                break
    elif confirmation == "DU":
        for value in location:
            print(f"{value}")
        nUsers = int(input("How much users do you want to delete?"))
        for user in range(nUsers):
            username = input("Username of the user to delete")
            delAccount(username)
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
        print(f"""{bankMoney["Public Money"]}, {bankMoney["Reserve Money"]}""")
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
