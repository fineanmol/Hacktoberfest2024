import requests
import smtplib
from datetime import datetime

#Enter your email here
EMAIL=""
#Enter your password here
PASS=""

def on_my_head():
    data=requests.get(url="http://api.open-notify.org/iss-now.json")
    iss_lat=int(float(data.json()["iss_position"]["latitude"]))
    iss_lon=int(float(data.json()["iss_position"]["longitude"]))

    my_lat=int(30.893890)
    my_lon=int(76.409859)

    if my_lat-5<=iss_lat<=my_lat+5 and my_lon-5<=iss_lon<=my_lon+5:
        return True

my_time=datetime.now()
k=int(str(my_time).split(" ")[1].split(":")[0])

dataa=requests.get(url="https://api.sunrise-sunset.org/json?lat=30.893890&lng=76.409859&formatted=0")
sunset=int(dataa.json()["results"]["sunset"].split("T")[1].split(":")[0])+5
sunrise=int(dataa.json()["results"]["sunrise"].split("T")[1].split(":")[0])+5
min=int(dataa.json()["results"]["sunset"].split("T")[1].split(":")[1])

if min>=30:
    sunset+=1
    sunrise+=1
def is_night():
 if k>sunset or k<sunrise:
     return True


with smtplib.SMTP("smtp.gmail.com",587) as smtp:
        smtp.starttls()
        smtp.login(EMAIL,PASS)
        smtp.sendmail(from_addr=EMAIL,to_addrs=EMAIL,msg="LOOK ISS IS ABOVE YOU\n\n Auto generated mail!")

    










