#use to record voice
# pip install sounddevice
# pip install scipy

import sounddevice
from scipy.io.wavfile import write

fs = 44100  # Sample rate

seconds = int(input("Enter the time duration: "))
print("Recording...")
myrecording = sounddevice.rec(int(seconds * fs), samplerate=fs, channels=2)
sounddevice.wait()
write('output.wav', fs, myrecording)  # Save as WAV file
print("Done")
