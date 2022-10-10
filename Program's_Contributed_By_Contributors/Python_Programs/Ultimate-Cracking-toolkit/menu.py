import dictionaryGenerator
import pdfcracker
import zipcracker
from md5hashcracker import *
import sys


print("\t\t\t Tool: Ultimate Cracking Toolkit \n |\t\tCoded By Bishal Aryal Batch30 Ethical Hacking \n | \t\t\t Twitter @C15C01337") #here /t is tab
print("_"*80+"\n")

user = str(input("Enter your username : "))
print(f"Welcome {user} in Ultimate Cracking Toolkit")


def toolselection():
    print(f"""
    -----------------------------------------------------
    |\t{user}  Please choose any tool :) \t\t|
    |\t[1]. Wordlist generator for possible passwords.\t|
    |\t[2]. Pdf cracker\t\t\t\t|
    |\t[3]. Zipcracker\t\t\t\t\t|
    |\t[4]. Md5 Hashcracker\t\t\t\t|
    |\t[5]. Exit the program\t\t\t\t|
    -----------------------------------------------------
    """)
    global choice
    choice = int(input("[*] Enter the program you want to use. "))
toolselection()
while True:
    if choice == 1:
        dictionaryGenerator.main()
    elif choice == 2:
        pdfcracker.pdfcrack()
    elif choice == 3:
        zipcracker.zipcrack()
    elif choice == 4:
        hashCrack()
    elif choice == 5:
        sys.exit()
    else:
        print("Please choose correct tool. ")
    toolselection()


	