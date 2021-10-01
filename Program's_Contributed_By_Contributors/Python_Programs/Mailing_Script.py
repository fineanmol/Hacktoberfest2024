"""Created By Ashutosh Pandey(DataCrusade1999)"""

import smtplib
import time
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
def Sending_Mail():
    try:
        server=smtplib.SMTP('smtp.gmail.com: 587')
        server.ehlo()
        server.starttls()
        server.ehlo()
        server.login('Your Email','Your_Password')
        msg=MIMEMultipart()
        msg['From']='Your Email'
        msg['To']='Receiver Email'
        msg['Subject']='Automating Mails'
        with open('Mail.txt','r') as f:
            MailText=f.read()
        msg.attach(MIMEText(MailText,'plain'))
        filename='27.jpg'
        attachment=open(filename,'rb')
        payload=MIMEBase('application','octet_stream')
        payload.set_payload(attachment.read())
        encoders.encode_base64(payload)
        payload.add_header('Content-disposition',f'attachment;f{filename}')
        msg.attach(payload)
        text=msg.as_string()
        server.sendmail('Your Mail','Receiver Mail',text)
        server.quit()
    except:
        print("Sorry We Couldn't Send Your Mail")
counter=0
while True:
    if __name__=='__main__':
        time.sleep(1)
        Sending_Mail()
        counter=counter+1
        print('{} Mail Sent'.format(counter))