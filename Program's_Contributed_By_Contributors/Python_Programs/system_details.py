#Printouts and redirect the output to a log file of the details about the system.

import platform, os
import datetime, time

#platform information
plat = "Platform: " + platform.platform()

a = platform.system() #platform type extract

if (a == "Linux"): #check the platform type

    #initialize , sort and print the system time and year
    x = datetime.datetime.now()
    timeL  = x.strftime("%a %b %m %H:%M:%S")
    timezone = time.strftime(str(time.timezone))
    year = x.strftime("%Y")

    path = os.path.expanduser("~/Desktop/Entries_Lin.log") #path to the file

    f1 = open(path, "w") #create a log file to write details

    f1.write(plat + "\n \n" + timeL + " " + timezone + " " + year + "\n \n") #write the platform date and time details in the log file
    
    #access folders and subfolders in /usr/lib path -> write into the log file
    os.system('find /usr/lib/ -name "*.bin" -type f >>'+path)

    print("Log file is created at: " + path)

elif (a == "Windows"): #check the platform type

    #initialize , sort and print the system time
    x = datetime.datetime.now()
    timeW1 = x.strftime("%d" "-" "%b" "-" "%y")
    timeW2 = x.strftime("%I" ":" "%M" " " "%p")

    path = os.path.expanduser("~\Desktop\Entries_Win10.log") #path to the file

    f2 = open(path, "w") #create a log file to write details

    f2.write(plat + "\n" + timeW1 + "\n" + timeW2 + "\n") #write the platform, date and time details in the log file
    f2.close()

    #run the shell command for sort out .exe files and redirect them to the log file
    os.system('dir C:\Windows\system32\*.exe >>' + path)

    print("Log file is created at: " + path)