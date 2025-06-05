from __future__ import print_function
import dotenv
from dotenv import load_dotenv, find_dotenv
import sys
from instagrapi import Client

url = 'https://www.instagram.com/daraz.lk/'
load_dotenv(find_dotenv())

cl = Client()
cl.login("username", "password")


res = url.split('/')[-2]
followers = cl.user_info_by_username(res)
print(followers.follower_count)
cl.logout()