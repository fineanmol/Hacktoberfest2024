import threading
import os

def task1():
    print("\nName of the thread executing task1:{} ".format(threading.current_thread().name))
    print("\nID of process executing task1:{}".format(os.getpid()))
    print("ID of thread executing Task1:{}".format(threading.get_ident()))
    
def task2():
    print("\nName of the thread executing task2:{} ".format(threading.current_thread().name))
    print("\nID of process executing task2:{}".format(os.getpid()))
    print("\nID of thread executing Task2:{}".format(threading.get_ident()))

if __name__ == "__main__":
    print("ID of process running main program : {}".format(os.getpid()))
    print("Name of main thread : {}".format(threading.main_thread().name))
    

    t1=threading.Thread(target=task1,name='t1')
    t2=threading.Thread(target=task2,name='t2')
    
    t1.start()
    t2.start()
    t1.join()
    t2.join()

          