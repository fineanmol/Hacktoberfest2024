from twilio.rest import Client
import time

# Twilio account SID and auth token
account_sid = "YOUR_TWILIO_ACCOUNT_SID"
auth_token = "YOUR_TWILIO_AUTH_TOKEN"

# Twilio phone number and recipient's phone number
twilio_number = "YOUR_TWILIO_PHONE_NUMBER"
recipient_number = "RECIPIENT_PHONE_NUMBER"

def send_whatsapp_message(message):
    client = Client(account_sid, auth_token)
    message = client.messages.create(
        body=message,
        from_=f"whatsapp:{twilio_number}",
        to=f"whatsapp:{recipient_number}"
    )
    print("WhatsApp message sent successfully!")

def water_reminder():
    water_interval = 60  # Interval in minutes
    total_reminders = 5  # Total number of reminders

    for i in range(total_reminders):
        send_whatsapp_message("Reminder: Drink water!")
        time.sleep(water_interval * 60)  # Convert minutes to seconds

water_reminder()
