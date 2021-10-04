list = []
print("Make a list")
while(True):
    a= input("do you want to enter some thing(Y/N) : ")
    if a=="N":
        print("These are the items you entered:")
        for item in list:
            print(item)
        break
    elif a=="Y":
        b=input("Enter an item for your list: ")
        list.append(b)
        continue
    #this is the code for a list ap