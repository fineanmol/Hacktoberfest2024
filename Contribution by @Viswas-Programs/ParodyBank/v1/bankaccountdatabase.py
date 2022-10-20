"""
Used to create dictionaries in shelves for each user data
"""
import shelve
import base64

bankMoney = shelve.open("C:\\Users\\Public\\Documents\\bankMoney")
location = shelve.open("C:\\Users\\Public\\Documents\\bankAccountNames")
bankAccountNumbers = shelve.open(
    "C:\\Users\\Public\\Documents\\bankAccountNumbers")
accountMoney = shelve.open("C:\\Users\\Public\\Documents\\accountHolderMoney")
loanAccount = shelve.open("C:\\Users\\Public\\Documents\\loanAccount")
permissions = shelve.open("C:\\Users\\Public\\Documents\\permissions")
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
                location[userName] = base64.standard_b64encode(bytes(Password,
                                                                     encoding=
                                                                     'utf8'))
                bankAccountNumbers[userName] = base64.standard_b64encode(
                    bytes(bankAccountNumber))
                accountMoney[userName] = moneyAccountHolder
                loanAccount[userName] = 0
                permissions[userName] = "Normal Account"
            elif userName != Password and age < 13:
                print("The money shouldn't be more than 5000!")
                bankAccountNumber = int(input(f"Account number for {userName}"))
                moneyAccountHolder = int(input(f"Money for {userName}"))
                if moneyAccountHolder <= 5000:
                    location[userName] = Password
                    bankAccountNumbers[userName] = bankAccountNumber
                    accountMoney[userName] = moneyAccountHolder
                    loanAccount[userName] = 0
                    permissions[userName] = "Child Account"
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
            bankMoney["Public Money"] += accountMoney[username]
            del location[username]
            del bankAccountNumbers[username]
            del accountMoney[username]
            del loanAccount[username]
            del permissions[username]
        print("The user has been deleted successfully")
    elif confirmation == "L":
        name = input("What is the account?")
        loanAmount = int(input("What is the loan amount?"))
        bankMoney["Public Money"] -= loanAmount
        loanAccount[name] = loanAmount
        print(f"Successfully loaned {name} {loanAmount} INR")
    else:
        # print(f"""{bankMoney["Public Money"]},{bankMoney["Reserve Money"]}""")
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
