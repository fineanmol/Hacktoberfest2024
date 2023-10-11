"""
Description: This scripts send email to single as well as multiple users.

Author: Ahtesham Zaidi
"""

import smtplib
import logging
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

def send_email(subject, body, to_email):
    try:
        # Email configuration
        sender_email = 'sender@gmail.com' # add your email
        sender_password = 'sender_password' # add your password
        smtp_server = 'smtp.gmail.com'
        smtp_port = 587

        # Create a MIMEText object
        message = MIMEMultipart()
        message['From'] = sender_email
        message['To'] = ",".join(to_email)
        message['Subject'] = subject

        # Attach the email body
        message.attach(MIMEText(body, 'plain'))

        # Establish a secure connection with the SMTP server
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.starttls()
        server.login(sender_email, sender_password)

        # Send the email
        logging.info(f"Sending email to :: {to_email}")
        server.sendmail(sender_email, to_email, message.as_string())

        # Close the SMTP server connection
        server.quit()

        logging.info("Email sent successfully.")
    except Exception as e:
        # Log the error
        logging.error(f"Error sending email: {str(e)}")

if __name__ == "__main__":
    try:
        # Example usage to send mail to multiple users
        recipient_email = ['test1@gmail.com', 'test2@gmail.com']
        email_subject = 'Notification'
        email_body = """ This is a test notification"""

        send_email(email_subject, email_body, recipient_email)
    except KeyboardInterrupt:
        print("Email notification script terminated.")
    except Exception as e:
        print(f"An error occurred: {str(e)}")
