## UPDATE 2021 : Thought of changing this with better variables and optimizations 
## but left it as it is , as a memoir for old *Me Coder*

# import all the necesary libraries
import os
import shutil
import math
import itertools

# the welcome function to be displayed at the beginning of the file
def welcome():
    # usig ascii color code
    print("\033[40m")
    print("\t\t\033[91m PyForCe")
    print("\n\n\t\t\033[92m An \"Intelligent\" Dictionary Creation Tool")
    print("\n\n\t\t\033[96m V1.0")

def calculateBytes(x,r):    
    bytes = x * (r + 1)
    # dividing bytes by 1000 to get kb
    # kbs = bytes / 1000
    # print("Calculated Size in kbs : ",kbs)
    return bytes

def sizeOnhardDisk(freekb):
    # size_on_disk = 0
    if freekb < 4096:
        sze = 1
    else:
        sze = round((freekb / 4096), 1)
        szplit = str(sze).split(".")
        sze = int(sze)
        if int(szplit[1]) > 0:
            sze = sze + 1
        size_on_disk = ((sze * 4096) // 1000)
    return size_on_disk

# math function to calculate nCr
def nCr(n,r):
    f = math.factorial
    x = f(n) / f(r) / f(n-r)
    return x

# the actual function that crates combinations
def createcombs(words,i):
    global f
    # pass the string to be combined and length of password
    for c in itertools.combinations(words,i):
        t = "".join(c)
        f.write(t + "\n")
        # print(t)


 # the function to check for available and empty disk space
def checkdiskspace(passfilelength):
    # returns a tuple
    total, used, free = shutil.disk_usage("/")
    # calculate the size in gigabits
    freeGb = (free // (2**30)) - 1
    pass_file_length_GB = (((passfilelength // 1024) // 1024) // 1024)
    # just log codes
    # print(freeGb," GB")
    # print("length of pass file ", pass_file_length_GB, " GB")
    # print(freeGb)
    # print(pass_file_length_GB)
    if freeGb - pass_file_length_GB > 1:
        print(" \n\nEnough Available Disk Space\n Creating Password Dictionary...")
    else:
        print("\033[91m Your Device Doesn't Have Enough Disk Space..\n Quitting...")
        # code to reset the color changes
        print("\033[0m")
        exit(0)

# the function to check for valid Characters
# feel free to add or remove characters as per requirements
# if you don't want to check go to the main function and disable the function call
def checkForCharacters(kword):
    chars = "!@#$%^&*()_+-=?></\"';|~`,'"
    for k in kword:
        if k in chars:
            print("\033[91m Alert Invalid Characters Found")
            # code to reset the color changes
            print("\033[0m")
            # any special charcter found
            # need to exit the code
            return False
        else:
            pass
            # print("ok")
    return True


# start the execution
# only if this file is executed
if __name__ == "__main__":
    global f
    # clear the console according to the OS
    # didn't check it on windows yet
    # :p
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")
    # call the welcome function to show the welcome screen
    welcome()

    kwords = input("\n\n\033[34m Enter Keywords Related To victim Seperated By Commas \n > ")
    klist = kwords.split(",")
    kwords = "".join(klist)
    # to change the minimum length change the value here
    if len(kwords) <= 7:
        # to less characters to create combinations
        print("\033[91m Too Less Characters...")
        # code to reset the color changes
        print("\033[0m")
        # hence exit
        exit(0)
    if checkForCharacters(kwords):
        # every char is valid
        # ask the length of password
        password_Length = input("\n\n\033[34m Enter Password Length\n For More Values Seperate Them By Spaces > ")
        # re assign the values to password_Length but as a list seperated
        password_Length = password_Length.split(" ")
        # check the list for any value to be less than 6 and greater than 12
        # you can change the values in the loop below to achieve your desired length
        # assuming that you will not flood the list with unneed values
        # no checking for length or for duplicate values in the list
        # -----
        # converting the values of list (password_Length) to string
        for i in range(0, len(password_Length)):
            try:
                password_Length[i] = int(password_Length[i])
            except ValueError:
                print("\033[91m Invalid Characters Found For \"Password Length\"")
                # code to reset the color changes
                print("\033[0m")
                exit(0)
        # after successfuly converting the values of list to integer
        # check if each  value is less than 12 and greater than 6
        for i in password_Length:
            if int(i) < 6 or int(i) > 12:
                print("\033[91m Enter Password Length To be less Than 12 And greater Than 6..")
                # code to reset the color changes
                print("\033[0m")
                exit(0)
        # now check for the no of possible combinations
        temp = 0
        tempkb = 0
        for i in password_Length:
            x = nCr(len(kwords), i)
            kbs = calculateBytes(x,i)
            temp = temp + x
            tempkb = tempkb + kbs
            # print(tempkb)
        tempkb = int(tempkb)
        print("\033[33m\n\n",int(temp)," Possible Items")
        print("\033[33m Size It Will Take On HardDisk is ", sizeOnhardDisk(int(tempkb)), " Kb")
        choice = input("\033[33m Would You Like To Continue (y/n) : ")
        if choice == "y":
        # createcombs(kwords)
            checkdiskspace(tempkb)
            f = open("passwords.txt", "w")
            for i in password_Length:
                createcombs(kwords,i)
            print(" Created..")
            # code to reset the color changes
            print("\033[0m")
        else:
            exit(0)
