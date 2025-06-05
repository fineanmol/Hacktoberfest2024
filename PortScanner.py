import socket
import re


ip_model = re.compile("^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$")
port_model = re.compile("([0-9]+)-([0-9]+)")

min_port = 0
max_port = 65535

open_ports = []

while True:
    ip = input("Please enter IP adress (or localhost): ")
    if ip_model.search(ip):
        print(f"{ip} is a IP address to scan")
        break

while True:
    print("Please enter the range of ports in format: (example would be 10-30)")
    port_range = input("Enter desired port range: ")
    port_range_valid = port_model.search(port_range.replace(" ",""))
    if port_range_valid:
        min_port = int(port_range_valid.group(1))
        max_port = int(port_range_valid.group(2))
        break

for port in range(min_port, max_port + 1):
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.settimeout(0.8)
            s.connect((ip, port))
            open_ports.append(port)

    except:
        pass

for port in open_ports:
        print(f"Port {port} is OPEN on {ip}.")