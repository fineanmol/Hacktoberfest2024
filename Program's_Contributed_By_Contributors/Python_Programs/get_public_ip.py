# This script allows to display your IPv4 or your IPv6 public address
# It uses the ipify API and uses the requests library in python

from requests import get

choice = input("Do you want to know your public ipv4 or public ipv6 address? (`ipv4`/`ipv6`)")

if choice.lower() == "ipv4":
    ip = get("https://api.ipify.org").text
elif choice.lower() == "ipv6":
    ip = get('https://api64.ipify.org').text
else:
    print("Invalid choice")
    exit(0)

print("My public IP address is {}".format(ip))
