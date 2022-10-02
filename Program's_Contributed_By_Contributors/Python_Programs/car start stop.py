import time

print("\t\t\t\t\t\tWelcome to the RedBull F1 racing program : ")

time.sleep(1)

stop = 1
start =0 

while True:
    print()
    print("\nPress 1. to start the car and move" 
    "\nPress 2. to stop the car and"
    "\nPress 3. to rest at pit lane  "
    "\nPress 4. to quit the car and")
    command = input("= ")


    if command == "1":
        if start == 0:
            if start ==1:
                time.sleep(1)
                print("The car is already in pace try stopping or quiting.")
            start+=1
            stop-=1
            time.sleep(1)
            print("You have successfully started the car and you are moving .")
        

    if command == "2":
        if start ==1:
            time.sleep(0.5)
            print("The car is stopped ")
            stop+=1
            start-=1 

        elif stop ==1:
            time.sleep(0.5)
            print("The car is already stopped , use other commands.")
            
    if command == "3":
        if start == 1:
            time.sleep(0.5)
            print("The car is brought back the pit lane and is been stopped.")
            start-=1
            stop+=1
        elif stop ==1:
            time.sleep(0.5)
            print("The car is back for some tire check")
            

    if command == "4":
        if start == 1:
            time.sleep(0.5)
            print("You have left the car...")
            break
        if stop ==1:
            time.sleep(0.5)
            print("You have left the car...")    
            break