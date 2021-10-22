# NO LICENSE!!!!
# 
# MY LOVE FOR OPEN SOURCE!!!
# 
# @v1s1t0r999
# 
# #hacktoberfest21


#imports
import base64
import binascii
import codecs
import hashlib
import random
import webbrowser
import os
import sys


banner=random.choice(
	["""
 ____                               __                                   
/\  _`\                            /\ \                                  
\ \ \L\_\    ___     ___    ___    \_\ \     __   _ __   ____    ____    
 \ \  _\L  /' _ `\  /'___\ / __`\  /'_` \  /'__`\/\`'__\/\_ ,`\ /\_ ,`\  
  \ \ \L\ \/\ \/\ \/\ \__//\ \L\ \/\ \L\ \/\  __/\ \ \/ \/_/  /_\/_/  /_ 
   \ \____/\ \_\ \_\ \____\ \____/\ \___,_\ \____\\ \_\   /\____\ /\____\
    \/___/  \/_/\/_/\/____/\/___/  \/__,_ /\/____/ \/_/   \/____/ \/____/
	""",
	 """
___________                       .___                           
\_   _____/ ____   ____  ____   __| _/___________________________
 |    __)_ /    \_/ ___\/  _ \ / __ |/ __ \_  __ \___   /\___   /
 |        \   |  \  \__(  <_> ) /_/ \  ___/|  | \//    /  /    / 
/_______  /___|  /\___  >____/\____ |\___  >__|  /_____ \/_____ \
        \/     \/     \/           \/    \/            \/      \/
	 """,
	 """
_______                   _                   
|  ___|                  | |                  
| |__ _ __   ___ ___   __| | ___ _ __ ________
|  __| '_ \ / __/ _ \ / _` |/ _ \ '__|_  /_  /
| |__| | | | (_| (_) | (_| |  __/ |   / / / / 
\____/_| |_|\___\___/ \__,_|\___|_|  /___/___
	 """,
	 """
_|_|_|_|                                      _|                                          
_|        _|_|_|      _|_|_|    _|_|      _|_|_|    _|_|    _|  _|_|  _|_|_|_|  _|_|_|_|  
_|_|_|    _|    _|  _|        _|    _|  _|    _|  _|_|_|_|  _|_|          _|        _|    
_|        _|    _|  _|        _|    _|  _|    _|  _|        _|          _|        _|      
_|_|_|_|  _|    _|    _|_|_|    _|_|      _|_|_|    _|_|_|  _|        _|_|_|_|  _|_|_|_|
	 """]
)



enc_types="""\
0. TYPE    |
1. Base64  |
2. Base32  |
3. Base85  |
4. Ascii85 |
5. Rot13   |
6. Hex Code|
7. Morse   |
8. MD5     |
9. SHA256  |
10. SHA512 |
"""


def b32(txt):
	return base64.b32encode(txt.encode("UTF-8"))

def b64(txt):
	return base64.b64encode(txt.encode("UTF-8"))

def sha256(txtinput):
	return hashlib.sha256(bytes(txtinput.encode("utf-8"))).hexdigest()

def sha512(txtinput):
	return hashlib.sha512(bytes(txtinput.encode("utf-8"))).hexdigest()

def md5(txtinput):
	return hashlib.md5(bytes(txtinput.encode("utf-8"))).hexdigest()

def a85(txtinput):
	return base64.a85encode(txtinput.encode("UTF-8"))

def b85(txtinput):
	return base64.b85encode(txtinput.encode("UTF-8"))

def _hex(txtinput):
	return binascii.hexlify(txtinput.encode("UTF-8"))

def rot13(txtinput):
	return codecs.encode(txtinput, "rot_13")

def main():
	os.system("cls" if sys.platform=="win32" else "clear")
	i = input(f"""
	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	{banner}
	    ~ By the Open-Source Lovers!!
		~ For #Hacktoberfest21
	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	[1] Base64
	[2] Base32
	[3] Base85
	[4] Ascii85
	[5] Rot13
	[6] Hex Code
	[7] Morse
	[8] MD5
	[9] SHA256
	[10] SHA512
	---
	[11] Visit GitHub (do star the repo!!)
	---
	[?] Choice Number: """)
	return str(i)


if __name__=="__main__":
	i=main()
	if i="11":
		webbrowser.open("https://github.com/fineanmol/Hacktoberfest2021")
		main()
	elif i=="1":
		o=input("[=] String to convert into base64: ")
		print(f"[+] BASE64: {b64(o)}")
		input("\n[ENTER] to continue")
		main()
	elif i=="2":
		o=input("[=] String to convert into base32: ")
		print(f"[+] BASE32: {b32(o)}")
		input("\n[ENTER] to continue")
		main()
	elif i=="3":
		o=input("[=] String to convert into base85: ")
		print(f"[+] BASE85: {b85(o)}")
		input("\n[ENTER] to continue")
		main()
	elif i=="4":
		o=input("[=] String to convert into ascii85: ")
		print(f"[+] ASCII85: {a85(o)}")
		input("\n[ENTER] to continue")
		main()
	elif i=="5":
		o=input("[=] String to convert into rot13: ")
		print(f"[+] ROT13: {r13(o)}")
		input("\n[ENTER] to continue")
		main()
	elif i=="6":
		o=input("[=] String to convert into Hex digits: ")
		print(f"[+] HEX: {_hex(o)}")
		input("\n[ENTER] to continue")
		main()
	elif i=="7":
		print("NOT YET SUPPORTED!!")
# 		o=input("[=] String to convert into Morse Codes: ")
# 		print(f"[+] MORSE: {morse(o)}")
		input("\n[ENTER] to continue")
		main()
		
	elif i=="8":
		o=input("[=] String to convert into md5: ")
		print(f"[+] MD5: {md5(o)}")
		input("\n[ENTER] to continue")
		main()
	elif i=="9":
		o=input("[=] String to convert into sha256: ")
		print(f"[+] SHA256: {sha256(o)}")
		input("\n[ENTER] to continue")
		main()
	elif i=="10":
		o=input("[=] String to convert into sha512: ")
		print(f"[+] SHA512: {sha512(o)}")
		input("\n[ENTER] to continue")
		main()
	else:
		print(f"\"{i}\" is a wrong choice!!")
		input("\n[ENTER] to continue")
		main()
	

