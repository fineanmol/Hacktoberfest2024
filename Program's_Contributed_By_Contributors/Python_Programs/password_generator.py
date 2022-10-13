#The program below simply generates strongest password will all types of length we want. We just have to type password lenghth and passwprd will be generated  
import string
import random
import time
#                   
if __name__ == "__main__":
    # s1 = string.ascii_lowercase
    # s2 = string.ascii_uppercase
    s3 = string.digits
    s4 = string.punctuation
    s5 = random.randint(1,10)
    # print(s5)
    i = 1
    while True:
        while i==1:
            plen=int(input("\n Enter password length : "))
            s = []
            # s.extend(s1)#extend is use add elements of list in list 
            # s.extend(s2)
            s.extend(s3)
            s.extend(s4)
            s.extend(str(s5))
            # print(s)
            random.shuffle(s)
            print("Your password is : ")
            print("".join(s[0:plen]))
        a=input("Do you want new password [Y/N]: ")
        if a == "y" or "Y":
            continue
        elif a == "n" or "N":
            break
