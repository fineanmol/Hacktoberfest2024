from socket import gethostbyname, gethostname
ip_add = gethostbyname(gethostname())
print(f'Your IP Address is - {ip_add}')
