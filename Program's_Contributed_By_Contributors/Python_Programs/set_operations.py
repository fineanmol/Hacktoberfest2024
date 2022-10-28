ls = []
elements = 0
while(1):
    print("a.Create Empty Set \nb.Insert \nc.Delete \nd.Search \ne.Print \nf.Union \ng.Intersection \nh.Set Difference \ni.Symmetric Difference \nj.Exit")
    print("Enter your choice: ")
    c = input()
    if (c == 'a'):
        s = set()
        ls.append(s)
        print(f"Set number of new set is: {elements}")
        elements += 1
    elif(c == 'b'):
        print(f"Enter the set number less than {elements} to insert Elemnts: ")
        setnum = int(input())
        if(setnum >= 0 and setnum < elements):
            print("Enter the elements of the set to insert: ")
            ele = set(input().strip().split())
            ls[setnum].update(ele)
            print(ls[setnum])
        else:
            print("Invalid set number")
    elif(c == 'c'):
        print(f"Enter the set number less than {elements} to delete Elemnts: ")
        setnum = int(input())
        if(setnum >= 0 and setnum < elements):
            print("Enter the Element you want to delete from the set:")
            ele = input()
            if ele in ls[setnum]:
                ls[setnum].discard(ele)
                print("Element is successfully deleted.")
            else:
                print("Element is not in set.")
        else:
            print("Invalid set number")
    elif(c == 'd'):
        print(f"Enter the set number less than {elements} to search Elemnts: ")
        setnum = int(input())
        if(setnum >= 0 and setnum < elements):
            print(f"Enter the element to search in set: ")
            ele = input()
            if ele in ls[setnum]:
                print("Element found.")
            else:
                print("Element not found.")
        else:
            print("Invalid set number")
    elif(c == 'e'):
        print(f"Enter the set number less than {elements} to print Elemnts: ")
        setnum = int(input())
        if(setnum >= 0 and setnum < elements):
            print(ls[setnum])
        else:
            print("Invalid set number")
    elif(c == 'f'):
        print(f"Enter the 1st set number less than {elements} for union: ")
        setnum = int(input())
        print(f"Enter the 2nd set number less than {elements} for union: ")
        setnum2 = int(input())
        if(setnum >= 0 and setnum < elements and setnum2 >= 0 and setnum2 < elements):
            s = ls[setnum].union(ls[setnum2])
            ls.append(s)
            print(s)
            print("Union set is added to list.")
            elements += 1
        else:
            print("Invalid set number")
    elif(c == 'g'):
        print(
            f"Enter the 1st set number less than {elements} for Intersection: ")
        setnum = int(input())
        print(
            f"Enter the 2nd set number less than {elements} for Intersection: ")
        setnum2 = int(input())
        if(setnum >= 0 and setnum < elements and setnum2 >= 0 and setnum2 < elements):
            s = ls[setnum].intersection(ls[setnum2])
            ls.append(s)
            print(s)
            print("Intersection set is added to list.")
            elements += 1
        else:
            print("Invalid set number")
    elif(c == 'h'):
        print(
            f"Enter the 1st set number less than {elements} for Set_difference: ")
        setnum = int(input())
        print(
            f"Enter the 2nd set number less than {elements} for Set_difference: ")
        setnum2 = int(input())
        if(setnum >= 0 and setnum < elements and setnum2 >= 0 and setnum2 < elements):
            s = ls[setnum].difference(ls[setnum2])
            ls.append(s)
            print(s)
            print("Set_difference set is added to list.")
            elements += 1
        else:
            print("Invalid set number")
    elif(c == 'i'):
        print(
            f"Enter the 1st set number less than {elements} for Symmetric_difference: ")
        setnum = int(input())
        print(
            f"Enter the 2nd set number less than {elements} for Symmetric_difference: ")
        setnum2 = int(input())
        if(setnum >= 0 and setnum < elements and setnum2 >= 0 and setnum2 < elements):
            s = ls[setnum].symmetric_difference(ls[setnum2])
            ls.append(s)
            print(s)
            print("Symmetric_difference set is added to list.")
            elements += 1
        else:
            print("Invalid set number")
    elif(c == 'j'):
        break
    else:
        print("Invalid input")
