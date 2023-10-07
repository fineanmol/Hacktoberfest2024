import logging
import time
from aiogram import Bot, Dispatcher, executor, types
import openai
import tiktoken
bot_token = ''
api_key = ''

logging.basicConfig(level=logging.INFO)

bot = Bot(token=bot_token)
dp = Dispatcher(bot)
enc = tiktoken.encoding_for_model("gpt-3.5-turbo")

openai.api_key = api_key

systemMessage = ""
messages = {}


@dp.message_handler(commands=['start'])
async def start_cmd(message: types.Message):
    try:
        username = message.from_user.username
        messages[username] = []
        messages[username].append({"role": "system", "content": systemMessage})

        await message.answer("Welcome to the chatbot!")
    except Exception as e:
        await message.answer(f'Error in start_cmd: {e}')
        logging.error(f'Error in start_cmd: {e}')


@dp.message_handler(commands=['newtopic'])
async def new_topic_cmd(message: types.Message):
    try:
        username = message.from_user.username
        messages[username] = []        
        messages[username].append({"role": "system", "content": systemMessage})

        await message.answer("New topic created")
    except Exception as e:
        await message.answer(f'Error in new_topic_cmd: {e}')
        logging.error(f'Error in new_topic_cmd: {e}')


@dp.message_handler()
async def echo_msg(message: types.Message):
    try:
        user_message = message.text
        username = message.from_user.id

        if username not in messages:
            messages[username] = []
        messages[username].append({"role": "user", "content": user_message})
        logging.info(f'{username}: {user_message}')

        should_respond = not message.reply_to_message or message.reply_to_message.from_user.id == bot.id

        if should_respond:
            processing_message = await message.reply("Processing...")

            tokenCount = 0
            for msg in messages[username]:
                tokenCount += len(enc.encode(msg['content']))
            
            while tokenCount > 5000:
                tokenCount -= len(enc.encode(messages[username][1]['content']))
                del messages[username][1]

            completion = openai.ChatCompletion.create(
                model="gpt-3.5-turbo-0301",
                messages=messages[username],
                max_tokens=2000,
                temperature=0.9,
                frequency_penalty=0,
                presence_penalty=0,
                user=str(username)
            )
            chatgpt_response = completion.choices[0]['message']
            messages[username].append({"role": "assistant", "content": chatgpt_response['content']})
            logging.info(f'ChatGPT response: {chatgpt_response["content"]}')
            await message.reply(chatgpt_response['content'])
            await bot.delete_message(chat_id=processing_message.chat.id, message_id=processing_message.message_id)
    except Exception as e:
        await message.answer(f'Error in echo_msg: {e}')
        logging.error(f'Error in echo_msg: {e}')


if __name__ == '__main__':
    executor.start_polling(dp)
