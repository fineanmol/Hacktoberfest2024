import speech_recognition as sr

def SpeechRecognition():
        r = sr.Recognizer()
        with sr.Microphone() as source:
            print('Say something...')
            r.pause_threshold = 1
            r.adjust_for_ambient_noise(source, duration=1)
            audio = r.listen(source)
        try:
            outputFile = open("speechOutput.txt","a")
            userSpeech = r.recognize_google(audio).lower()
            print('You said: ' + userSpeech + '\n')
            outputFile.write(userSpeech + '\n')
            outputFile.close()

        except sr.UnknownValueError:
            print('....')
        
while True:
    SpeechRecognition()

