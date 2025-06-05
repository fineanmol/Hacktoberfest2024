import os
import time


def shutdown():
    os.system("shutdown /s /t 1")


set_time = input("Shutdown After ----> ")


set_time = int(set_time)

sec = 60

print('Computer Will Now Shutdown in ' + str(set_time) + ' Minutes')
time.sleep(set_time * sec)
print('\n')
print('Computer Will Now Shutdown!')
time.sleep(3)
shutdown()