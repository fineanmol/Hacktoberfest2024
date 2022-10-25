# Github username: sahilsync07
# Aim: My program's aim is to print IP address
# Date: 25th October 2022

# start coding:

import socket   
hostname=socket.gethostname()   
IPAddr=socket.gethostbyname(hostname)   
print("Your Computer Name is:"+hostname)   
print("Your Computer IP Address is:"+IPAddr)  
