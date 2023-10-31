import threading

def square(num):
    ans=num*num
    print("The square of the number the entered number is : {}".format(ans))

def cube(num):
    print("The cube od the enetered number is : {}".format(num*num*num))

if __name__ == "__main__":
    number = int(input("Enter a number to find its cube and square :"))
    t1=threading.Thread(target=square(number),name="Thread1")
    t2=threading.Thread(target=cube(number),name="thread2")
    t1.start()
    t2.start()
    t1.join()
    t2.join()


