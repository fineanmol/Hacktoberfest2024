import time

count = int(input('What number do you want to count down from? '))

while count > 0:
    count =- 1
    import sys
    sys.stdout.write(count)
    sys.stdout.flush()
    time.sleep(1)

print('auto shutdown in 10 seconds')
time.sleep(10)