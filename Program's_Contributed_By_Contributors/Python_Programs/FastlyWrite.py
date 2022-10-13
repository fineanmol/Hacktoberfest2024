import time, cv2, re, os
from telethon import TelegramClient, events
from pytesseract import pytesseract

pytesseract.tesseract_cmd = "C:\\Program Files\\Tesseract-OCR\\tesseract.exe"

api_id = 1290162
api_hash = 'c23c9f52441ee4bdb82dca04111060de'
sesi_file = 'yourname'

group = 'yourgroup'

if __name__ == '__main__':
    
    client = TelegramClient(sesi_file, api_id, api_hash, sequential_updates=True)
        
    @client.on(events.NewMessage(chats=group))
    async def handler(event):

        if '🌐 Kata baru!' in event.raw_text or '🌐 New word!' in event.raw_text:
            if event.photo:
                gambar = await event.download_media()
                img = cv2.imread(gambar)
                words_in_image = pytesseract.image_to_string(img)
                cari = (re.findall(r'\w+',words_in_image)[re.findall(r'\w+',words_in_image).index('By')-1])
                await client.send_message(group, cari)
                os.remove(gambar)
                print(cari)
            return

    client.start()
    print(time.asctime(), '-', 'Starting...')
    client.run_until_disconnected()
    print(time.asctime(), '-', 'Stopped...')