# Functions to get system values:
from psutil import cpu_percent, net_io_counters
# Functions to take a break:
from time import sleep
# Package for email services:
import smtplib
import string
MAX_NET_USAGE = 400000 # bytes per seconds
MAX_ATTACKS = 4
attack = 0
while attack <= MAX_ATTACKS:
    sleep(4)

    # Check the net usage wit named tuples
    neti1 = net_io_counters().bytes_recv
    neto1 = net_io_counters().bytes_sent
    sleep(1)
    neti2 = net_io_counters().bytes_recv
    neto2 = net_io_counters().bytes_sent

    # Calculate the bytes per second
    net = ((neti2+neto2) - (neti1+neto1))/2

    # Check the net and cpu usage
    if (net > MAX_NET_USAGE) or (cpu_percent(interval = 1) > 70):
        attack+=1
    elif attack > 1:
        attack-=1

# Write a very important email if attack is higher than 4
TO = "you@your_email.com"
FROM = "webmaster@your_domain.com"
SUBJECT = "Your domain is out of system resources!"
text = "Go and fix your server!"
string="\r\n"
BODY = string.join(("From: %s" %FROM,"To: %s" %TO,
                    "Subject: %s" %SUBJECT, "",text))
server = smtplib.SMTP('127.0.0.1')
server.sendmail(FROM, [TO], BODY)
server.quit()