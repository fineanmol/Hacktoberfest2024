
import webbrowser
import pyttsx3
import speech_recognition as sr
import pywhatkit
import os

assistant = pyttsx3.init('sapi5')
voices = assistant.getProperty('voices')
assistant.setProperty('voices',voices[0].id)
assistant.setProperty('rate',170)

def speak(audio):
    print("  ")
    assistant.say(audio)
    print(f":  {audio}  ")
    assistant.runAndWait()
    
    
def takecommand():
    command =  sr.Recognizer() 
    with sr.Microphone() as source:
        print('Listening ...  ')
        command.pause_threshold = 1
        audio = command.listen(source)
        
        try:
            print("Recongnizing......")
            query = command.recognize_google(audio,language='en-in')
            print("You said: {query}")
        
        except Exception as Error:
            return "none"
        return query.lower()  
 
               
def taskxe():
    
    def music():
        speak("Tell me the name of your song ! ")
        musicname = takecommand()
    
        if 'seven rings' in musicname :
            os.startfile('Music\\Ariana Grande - 7 rings.mp3')
        
        else:
            pywhatkit.playonyt(musicname)
        speak(" Song , STarted , Enjoy sir")         
            
        
    
    while True:
        query = takecommand()   
        
        if 'hello ' in query:
                speak('Hello I am Jarvis')
                speak('Your personal AI assistance , How may I help YOU ')
                
        elif 'how are you' in query:
                speak('I am fine ma\'am , how are you ')
                
        elif 'i am good' in query:
                speak('Glad to hear maam ' )
                
        elif 'good morning jarvis ':
              speak('very good morning maam ' )   
              break
        elif 'youtube search' in query:
                speak('Okay sir , This is what I found for your search! ')
                query  = query.replace("Jarvis" , "" )
                query = query.replace("youtube search","")
            
                web='https://www.youtube.com/results?search_query='+ query
                webbrowser.open(web)
                speak("done maam")                
                
        elif 'you need a break' in query:
                speak('Okay maam you can call me any time , have a good day ') 
                break  
                 
        elif 'bye jarvis':
               speak('Bye maam  ')
               break
        
            
          

        elif 'google search ' in query:
            speak('this is what i found')
            query = query.replace('jarvis',"")
            query = query.replace('google search'," ")
            pywhatkit.search(query)
            speak('done, sir')
            
        elif 'website' in query:
            speak('okay sir launching .....')
            query = query.replace('jarvis',"")
            query = query.replace('website',"")
            web1 = query.replace('open',"")
            web2 = 'https://www.'+web1+'.com'
            webbrowser.open(web2)
            speak('Launched ! ')
         
        elif "music" in query:
            music() 
            
       # elif 'wikipedia' in query:
          
speak("jarvis , ACTIVATED ")       
taskxe()
#on hold 
