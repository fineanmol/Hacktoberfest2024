import time

print('Press ENTER to begin, Press Ctrl + C to stop')
while True:
    try:
        input() #For ENTER
        starttime = time.time()
        print('Started')
    except KeyboardInterrupt:
        print('Stopped')
        endtime = time.time()
        print('Total Time:', round(endtime - starttime, 2),'secs')
        break
# Press enter to start and stop the watch
"""
import time

print('Press Enter to begin, Press Enter again to stop')
if input()=='':
    starttime = time.time()
    print('Started')
    while True:
            val=input() #For ENTER
            if val=='':
                print('Stopped')
                endtime = time.time()
                print('Total Time:', round(endtime - starttime, 2),'secs')
                break
                          
"""

"""
Output:
Press Enter to begin, Press Enter again to stop

Started

Stopped
Total Time: 1.05 secs

"""