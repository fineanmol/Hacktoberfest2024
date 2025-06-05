from email.mime import audio
import sounddevice as sd
import wavio as wv
import speech_recognition as sr

def speech_to_text(duration:int, freq = 44100) :
    print(f"Listening for {duration} sec...")
    recording = sd.rec(int(duration * freq), 
                        samplerate=freq, channels=2)
    sd.wait()
    print("Please Wait...")
    wv.write("recording1.wav", recording, freq, sampwidth=2)
    r = sr.Recognizer()
    with sr.AudioFile('./recording1.wav') as source:
        audio_data = r.record(source)
        text = r.recognize_google(audio_data)
        return text

if __name__ == "__main__":
    
    # duration = int(input("Durations in seconds : "))
    duration = 5  # You can change the duration here
    audio_text = speech_to_text(duration)
    print("Text : ",audio_text)