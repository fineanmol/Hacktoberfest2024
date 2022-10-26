'''
Author: smit-sms
'pip install pyfiglet' to see the ascii banner

USAGE
 - Run the script by 'python port_scanner.py <url>'
 - Replace the <url> with the URL of your choice, for eg. 'python port_scanner.py 127.0.0.1'
'''

# Importing the libraries
import pyfiglet
import sys
import socket
from datetime import datetime

# Printing the Ascii Banner
ascii_banner = pyfiglet.figlet_format("PORT SCANNER")
print(ascii_banner)

# Defining a target
if len(sys.argv) == 2:
	# Translate hostname to IPv4 Address
	target = socket.gethostbyname(sys.argv[1])
else:
	print("Invalid amount of Argument")

print(" -" * 50)
print(" Scanning Target: " + target)
print(" Scanning started at: " + str(datetime.now()))
print(" -" * 50)

try:
	# Recursively scan ports between 1 to 65,535
	for port in range(1, 65535):
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		socket.setdefaulttimeout(1)
		
		# Returns an error indicator
		result = s.connect_ex((target,port))
		if result == 0:
			print("\nPort {} is open.".format(port))
		s.close()
		
except KeyboardInterrupt:
		print("\n Exiting Program.")
		sys.exit()
except socket.gaierror:
		print("\n Hostname Could Not Be Resolved. Please try again with other Hostname.")
		sys.exit()
except socket.error:
		print("\n Server not responding. Please try again after sometime.")
		sys.exit()
