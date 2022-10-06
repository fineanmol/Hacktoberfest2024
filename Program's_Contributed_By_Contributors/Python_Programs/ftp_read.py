my_host = "Your.FTPServer.com"
my_user = "FtpUserName"
my_password = "SecretPassword"


import ftplib

ftp = ftplib.FTP(my_host)
ftp.login(my_user,my_password)

files = []

try:
    files = ftp.nlst()

except ftplib.error_perm:
    raise

for f in files:
    print (f)