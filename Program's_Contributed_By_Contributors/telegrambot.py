#!/usr/bin/env python3
#simple Telegram Bot To Say Hi Hello 
from telegram.ext import Updater, CommandHandler, MessageHandler
import requests


def start(update, context):
    response = "<b>Hello I am a Test Bot How are you ? 😄😄</b>"
    update.message.reply_text(response, parse_mode= "HTML")
    
def hello(update, context):
    update.message.reply_text(
        '<b>Hello <a href="tg://user?id={}">{}</a>😄😄, How ya been ?</b>'.format(update.message.from_user.id,update.message.from_user.first_name), parse_mode= "HTML")
        
def me (update, context):
    update.message.reply_text(
        '<code>Extracted From Megik Db </code>\n <b>Your name :</b> <a href="tg://user?id={}">{}</a> \n<b>Is a Bot : {}  😶😶\n</b>'.format(update.message.from_user.id,update.message.from_user.full_name,update.message.from_user.is_bot), parse_mode= "HTML")
    
    
    
    
    
#token    
updater = Updater('<Bot_Token>', use_context=True)


updater.dispatcher.add_handler(CommandHandler('hi', start))
updater.dispatcher.add_handler(CommandHandler('hello', hello))
updater.dispatcher.add_handler(CommandHandler('about', me))

updater.start_polling()
updater.idle()
