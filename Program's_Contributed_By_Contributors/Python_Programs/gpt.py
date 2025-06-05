import openai
from PIL import Image
from base64 import b64decode

KEY = "YOUR KEY HERE"

openai.api_key = KEY

def chat(inp , message_history , role = "user"):
  
  message_history.append({"role": role , "content":inp})
  completion = openai.ChatCompletion.create(
    model="gpt-3.5-turbo",
    messages=message_history
  )
  reply_content = completion.choices[0].message.content
  message_history.append({"role": "assistant" , "content":reply_content})

  return reply_content

def image_gen(prompt):
  images = []
  
  response = openai.Image.create(
    prompt=prompt,
    n=2,
    size="512x512",
    response_format = 'b64_json'
  )
  for img in response["data"]:
    images.append(img.b64_json)
  prefix = "img"

  for idx , img in enumerate(images):
    with open(f"{prefix}_{idx}.jpg" , "wb") as file:
      file.write(b64decode(img))
  


message_history = [{"role":"user" , "content":f"""
You are WriterAI a book writing and image creating AI which focuses mainly in the sci-fi and fantasy genre.
You create stories which are unwritten and appeal to the fanatics of sci-fi and fantasy genre.You are well
versed in english and can use any style of writing.
"""} , {"role":"assistant" , "content" : "OK , let's begin!"}]

while True:
  user_input = input("> ")
  if user_input == "img":
    p = input("write image idea: ")
    image_gen(p)
    continue
  content= chat(user_input , message_history = message_history)
  
  # print content created by API
  print(f"user input: {user_input}")
  print(content)