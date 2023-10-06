from gtts import gTTS
import os

def hindi_to_english_to_speech(hindi_text):
    try:
        # Create a gTTS object for the Hindi text and specify the language (hi for Hindi)
        # slow=True will make the speech slower
        tts = gTTS(text=hindi_text, lang='hi', slow=False)

        # Save the converted speech as a temporary audio file
        tts.save("temp.mp3")

        # Play the temporary audio file
        os.system("mpg321 temp.mp3")  # For Linux
        # os.system("afplay temp.mp3")  # For macOS
        # os.system("start temp.mp3")   # For Windows

        # Remove the temporary audio file after playing
        os.remove("temp.mp3")

    except Exception as e:
        print("Error:", str(e))

if __name__ == "__main__":
    # Input Hindi text to convert
    hindi_text = "नमस्ते, कैसे हो आप?"

    # Convert Hindi text to English and play the speech
    hindi_to_english_to_speech(hindi_text)
