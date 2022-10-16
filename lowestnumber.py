def lowest_number():
    a=list(map(int,input("Input the 3 numbers with spaces - ").split(' ')))
    if len(a)==3:
        flag=a[0]
        for i in a[1:]:
            if i<flag:
                flag=i
            else:
                continue
        print("The lowest number is",flag)
    else:
        print('You were supposed to enter 3 numbers.')
        
        
lowest_number()
        