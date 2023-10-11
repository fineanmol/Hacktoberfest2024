import os
import time




def enter_funk():
    print("\v"
    "\t\t\t  RULES\n"
    "Must be greater than twelve (12) characters and less than 20 character \n"
    "Must have atleast four (4) digits and less than eight numbers \n")
    x=input("Set a password:")
    print("")
    b=len(x)
    count1=0
    
    
    for i in x:
        if(i.isdigit()):
            count1=count1+1
            
    if b<12:
        print("Must atleast be twelve (12) characters long \n")
        print("Only ",b," characters are there")
        print("Wait for 5 seconds")
        time.sleep(5)
        os.system("clear")
        enter_funk()
        
    elif count1<4:
        print("Must be atleast four (4) digits long \n")
        print("Only ",b," characters are there")
        print("Wait for 5 seconds")
        time.sleep(5)
        os.system("clear")
        enter_funk()
        
    elif count1>7:
        print("Must be less than seven (7) digits long \n")
        print("There are ",b," digits")
        print("Wait for 5 seconds")
        time.sleep(5)
        os.system("clear")
        enter_funk()   
        
    elif b>19:
        print("Too long\n")
        print("There are ",b," characters")
        print("Wait for 5 seconds")
        time.sleep(5)
        os.system("clear")
        enter_funk()     
        
    else:
         y=input("Confirm password:")
         
         if x!=y:
             print("Password not matching. Type again\n")
             enter_funk()
             
         else:
             os.system('clear')
             f=("Initiating password checking sequance")
             
             for i in f:
                 print(i,end="",flush=True)
                 time.sleep(0.1)
             m=5
             
             while True:
                 m*=2
                 o=input("\nWhat is your password:")
                 
                 if o==x:
                     os.system("clear")
                     words=("welcome to your computer")
                     
                     for i in words:
                         time.sleep(0.1)
                         print(i, end='', flush=True)
                     break   
                                  
                 elif o!=x:                
                     print("Wait for ",m," seconds")
                     time.sleep(m)
                     os.system("clear")
                     continue
                     
                 else:
                     print("ERROR")
                     time.sleep(2)
                     os.system('clear')
                     enter_funk()
                     
                                  
enter_funk()

#second area


words=("""
01. Clock
02. Store
03. Games
04. Calculator 
05. Story generator
06. Essay generator
07. Music
08. Movies
09. Settings
10. Power off""")
for i in words:
    time.sleep(0.001)
    print(i, end='', flush=True)
print()
h=input("Choose an application:")
if h=="1" or h=="01" or h=="01." or h=="1.":
    print('''
1. Clock
2. Stop Watch
    ''')
    you=int(input("choose one of the application:"))
    if you==1:
        import time
        print(time.localtime)
        t=time.asctime(time.localtime(time.time()))
        print(t)
    
    elif you==2:
        import time
        r=int(input("Type timer in sec:"))
        for i in range (r):
            r-=1
            time.sleep(1)
            print(r)
    else:
        print("Choose a number with the provided numbers")
        

elif h=="2" or h=="02" or h=="02." or h=="2.":
    print('''
1. Apps
2. Games
''')
    your=int(input("choose one of the application:"))
    if your=="1" or h=="01" or h=="01." or h=="1.":
        print("Select one.")
        print('''
1. randomator
2. Number of number
''')
    elif your=="2" or h=="02" or h=="02." or h=="2.":
        print("Select one.")
        print('''
1. wordder
2. guess the number
''')

elif h=="3" or h=="03" or h=="03." or h=="3.":
    print('''
    1. The faster you do it
    ''')
    
elif h=="4" or h=="04" or h=="04." or h=="4.":
    print()
    
elif h=="5" or h=="05" or h=="05." or h=="5.":
    print()
    import random
    import time
    
    character=['raj','rekha','mahesh','maya','couper']
    age=[' is 12',' is 13',' is 14',' is 15']
    andd=[' and']
    emotions=[' happy',' sad',' angry',' exited',' anxious',' disgusted',' amused',' relived']
    because=[' because of']
    gender1=[' his',' her',' a','']
    reason=[' bombing nearby.','  party.',' birthday.',' SpiderMan: No Way Home.',' bear like habbits.',' physicopathic behaviour.', ' you dont wanna know(I know breaking the fourth wall is terrible).',' who knows what.']
    gender2=[' He',' She']
    next=[' Had just woken up',' Had just commited a crime',' Had just come out of college',' Had just come out of school',' Had just come out of jail',' Had just come out of mental asilum',' Had just come out of trauma',' Had just completed his breakfast',' Had just completed his lunch',' Had just completed his dinner',' Had just completed her breakfast',' Had just completed her lunch',' Had just completed her dinner',' Had just finished watching youtube']
    next_reason=[' and after freshening up']
    gender3=[', the same person']
    doing_after_next=[' started writing a diary',' started clearing the evidence',' started sleeping',' started eating',' started watching youtube']
    after_that=[' and after that,']
    after__after_that=[' he went back to',' she went back to',' it went back to',' went back to']
    doing_the_after_that=[' killing.',' helping.',' murdering.',' brutally murdering people.',' playing.',' crying.',' sneezing.',' tricking.',' trecking.',' meditate.',' annoy people.']
    end=[' the end',' The End',' Ended',' Ending',' Error',' Loading']

    x=0
    # a person woke up, age, goes somewhere, does a crime, police search, killed, woke up, age... 
    while True:
        time.sleep(0.00000000000000001)
        print(random.choice(character)+random.choice(age)+random.choice(andd)+random.choice(emotions)+random.choice(because)+random.choice(gender1)+random.choice(reason)+random.choice(gender2)+random.choice(next)+random.choice(next_reason)+random.choice(gender3)+random.choice(doing_after_next)+random.choice(after_that)+random.choice(after__after_that)+random.choice(doing_the_after_that)+random.choice(end))
        x+=1
        if(x>1):
            break
    
      
elif h=="10" or h=="10" or h=="10." or h=="10.":
    print()