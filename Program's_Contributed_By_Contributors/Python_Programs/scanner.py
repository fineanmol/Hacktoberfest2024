#! bin/python3


import socket
import sys
from datetime import datetime

#define our target
if len(sys.argv) == 2:
	target = socket.gethostbyname(sys.argv[1]) #Transulate hostname to IPv4
else:
	print("Invaid Argument")

# add a pretty banner

print("-" *50)
print("Scanning target "+ target)
print("Time started : " +str(datetime.now()))
print("-"*50)

try:
	for port in range(1,65535):
		s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		socket.setdefaulttimeout(1)
		result = s.connect_ex((target,port)) #returns an Error Indicator
		print("Checking port{}" .format(port))
		if result == 0:
			print("Port {} is open" .format(port))
		s.close()
except KeyboardInterrupt:
	print("\n Exiting Program")
	sys.exit()
except socket.gaierror:
	print("hostname could not be resolved")
	sys.exit()
	
except socket.error:
	print("couldn't connect to server")
	sys.exit()
