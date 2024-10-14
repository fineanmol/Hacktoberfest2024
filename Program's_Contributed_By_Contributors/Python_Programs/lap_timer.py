import time
 
 
#Start the timer
starttime = time.time()
lasttime = starttime
lap = 1
 
print("Press ENTER to count laps.\nPress Q to stop")
 

while True:
 
    # Input for the ENTER key press
    x=input()
 
    # The current lap-time
    laptime = round((time.time() - lasttime), 2)
 
    # Total time elapsed
    # since the timer started
    totaltime = round((time.time() - starttime), 2)
 
    # Printing the lap number,
    # lap-time and total time
    print("Lap No. "+str(lap))
    print("Total Time: "+str(totaltime))
    print("Lap Time: "+str(laptime))
 
    print("*"*20)
 
        # Updating the previous total time
        # and lap number
    lasttime = time.time()
    lap += 1
 
    if x=="Q" or x=="q":
        break
print("Done")
