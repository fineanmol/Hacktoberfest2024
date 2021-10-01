# Here we will make a Zoom automation system
# Replace all the url with the appropriate url of the images in your file explorer.

import os
import pyautogui
import pandas as pd
import time
from datetime import datetime



def signIn(meeting_id, password):

    #Opening Zoom application
    os.startfile(r"C:\Users\ratul\Desktop\PICS\Zoom")
    time.sleep(2)


    # Now we operate the button to join a meeting
    join = pyautogui.locateCenterOnScreen("Zoom-Automation\zoom_join1.png") #Replace the zoom button url with the url in your machine.
    pyautogui.moveTo(join)
    pyautogui.click()
    
    


    # meeting id
    meetingidbtn = pyautogui.locateCenterOnScreen("Zoom-Automation\meetingid.jpg")
    pyautogui.moveTo(meetingidbtn)
    pyautogui.write(meeting_id)
    time.sleep(1)

    #enter
    pyautogui.press('enter')


    #passcode blank
    passcode= pyautogui.locateCenterOnScreen("Zoom-Automation\passcode.jpg")
    pyautogui.moveTo(passcode)
    pyautogui.write(password)
    time.sleep(1)

    #enter
    pyautogui.press('enter')
    

#Read excel sheet
df = pd.read_excel('Zoom-Automation\zoom1.xlsx') #df stands for data frame


while True:
    # Would be checking the date time continiusly in an infinite loop

    now = datetime.now().strftime("%H:%M") #will be looking at the Date and only hours and minutes.

    if now in str(df['Timings']):

        # for iterating
        mylist=df["Timings"]
        mylist=[i.strftime("%H:%M") for i in mylist]
        c= [i for i in range(len(mylist)) if mylist[i]==now]
        row = df.loc[c] 

        # row = df.loc[df['Timings'] == now]  #loc used to locate specific rows

        id = str(row.iloc[0,1])
        password = str(row.iloc[0,2])

        signIn(id, password)
        time.sleep(50)
        print('signed in !!')
    
repeat(password)