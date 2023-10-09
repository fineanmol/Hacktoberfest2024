# WAP to swap the first n characters of two strings.

test1 = input("enter the first string \n")
test2 = input("enter the second string \n")
to_swap = int(input("enter the number of characters to swap \n"))
if len(test1) < to_swap or len(test2) < to_swap:
    print("please enter a valid value :(")
else:
    x = test1[0:to_swap]
    test1 = test1.replace(test1[0: to_swap], test2[0: to_swap])
    test2 = test2.replace(test2[0: to_swap], x)
    print('first swapped string is ' + test1)
    print('second swapped string is ' + test2)
