
my_host1 = "myFTPserver.com"
my_user1 = "FTP_USER"
my_password1 = "myPassword"


import ftplib

ftp = ftplib.FTP(my_host1)
ftp.login(my_user1,my_password1)

files = []

try:
    files = ftp.nlst()

except ftplib.error_perm:
    raise

for f in files:
    print (f)