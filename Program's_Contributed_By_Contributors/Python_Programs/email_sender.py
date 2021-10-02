import smtplib
import ssl
import getpass
import datetime as dt


class SendEmail:

    def __init__(self, sender_address, mail_provider,  subject, body, receiver_address):
        self.sender_address = sender_address
        self.mail_provider = mail_provider
        self.subject = subject
        self.body = body
        self.receiver_address = receiver_address
        self.smtp_server = self.get_smtp_server(mail_provider)
        self.receivers = self.get_receivers_list(receiver_address)

    def send_email(self):
        context = ssl.create_default_context()
        password = self.get_password()
        smptp_server = self.smtp_server
        content = self.get_content(self.subject, self.body)
        print(content)
        port_for_ssl = 465
        port_for_tls = 587
        receiver_addresses = self.receivers
        with smtplib.SMTP(smptp_server, port_for_tls) as server:
            server.starttls(context=context)
            try:
                server.login(self.sender_address, password=password)
                for i in range(len(receiver_addresses)):
                    server.sendmail(self.sender_address,
                                    receiver_addresses[i], content)
            except Exception:
                print(Exception)

    def get_smtp_server(self, smtp_server_):
        switcher = {
            'gmail': 'smtp.gmail.com',
            'yahoo': 'smtp.yahoo.com',
            'hotmail': 'smtp-mail.outlook.com',
            'live': 'smtp-mail.outlook.com'
        }
        return switcher.get(smtp_server_, 'Invalid provider')

    def get_receivers_list(self, receiver_address):
        if not isinstance(receiver_address, list):
            return [receiver_address]
        else:
            return receiver_address

    def get_password(self):
        try:
            password = getpass.getpass()
        except:
            password = None
            print('Password error')
        finally:
            return password

    def get_content(self, subject, body):
        time = dt.datetime.now()
        return "Subject:{Subject}\n\n{Body} \n\nSent on {year}-{date}-{month} at {hour}:{minute}:{second}.".format(Subject=subject, Body=body, year=time.year, date=time.day, month=time.month, hour=time.hour, minute=time.minute, second=time.second)



