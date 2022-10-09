try:
    import nmap
except ImportError:
    raise ImportError('Try: pip install python-nmap')
# initialize the port scanner
nmScan = nmap.PortScanner()

# scan localhost for ports in range 21-443
ip = input("Enter IP address: ")
nmScan.scan(ip, '21-443')

# run a loop to print all the found result about the ports
for host in nmScan.all_hosts():
     print('Host : %s (%s)' % (host, nmScan[host].hostname()))
     print('State : %s' % nmScan[host].state())
     for proto in nmScan[host].all_protocols():
         print('----------')
         print('Protocol : %s' % proto)
 
         lport = nmScan[host][proto].keys()
         lport.sort()
         for port in lport:
             print ('port : %s\tstate : %s' % (port, nmScan[host][proto][port]['state']))