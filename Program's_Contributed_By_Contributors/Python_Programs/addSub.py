import threading
import os

def Addition(num1,num2):
    print("The  ID of thread in which Addition function is running : {} ".format(threading.get_ident()))
    print("The  ID of Process in which Addition function is running : {} ".format(os.getpid()))
    print("The sum of the entered number is : {}".format(num1+num2))

def Substraction(num1,num2):
    print("The  ID of thread in which substraction function is running : {} ".format(threading.get_ident()))
    print("The  ID of Process in which substraction function is running : {} ".format(os.getpid()))
    print("The sum of the entered number is : {}".format(num1-num2))

if __name__ == '__main__':
    n1=int(input("Enter the first number :" ))
    n2=int(input("Enter the Second number :" ))
    print("The Main Process ID".format(os.getppid()))
    t1 = threading.Thread(target=Addition,args=(n1,n2,))
    t2 = threading.Thread(target=Substraction,args=(n1,n2,))
    t1.start()
    t2.start()
    t1.join()
    t2.join()