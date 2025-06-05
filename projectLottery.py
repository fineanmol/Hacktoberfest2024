#IMPORT RANDOM MODULE
import random

#CREATE VARIABLE
user_list = []
random_list = []
user_value = 0
random_value = 0
count = 0
matches = 0

#GET VALUES FROM THE USER INTO A LIST
user_list.append(int(input("Insert number 1 : ")))
user_list.append(int(input("Insert number 2 : ")))
user_list.append(int(input("Insert number 3 : ")))
user_list.append(int(input("Insert number 4 : ")))
user_list.append(int(input("Insert number 5 : ")))
print("\n")

#GET RANDOM NUMBERS INTO A LIST
random_list.append(random.randrange(1,50))
random_list.append(random.randrange(1,50))
random_list.append(random.randrange(1,50))
random_list.append(random.randrange(1,50))
random_list.append(random.randrange(1,50))

#DISPLAY THE USER ENTRIES
print("User number :",end = " ")
for user_value in user_list:
    print(user_value,end = "  ")
print("\n") 

#DISPLAY THE LOTTERY NUMBERS
print("Lottery numbers : ",end = " ")
for random_value in random_list:
    print(random_value,end = "  " )

#LOOK FOR MATCHING VALUES IN BOTH LISTS
for count in range (5):
    if user_list[count] == random_list[count]:
        matches +=1

#DISPLAY NUMBER OF MATCHES
print("\n\nYou have",matches,"matches")  
