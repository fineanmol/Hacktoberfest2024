#Slack Notifier//

import requests
import json

# Your Slack webhook URL (replace with your actual URL)
slack_webhook_url = 'https://hooks.slack.com/services/T00000000/B00000000/XXXXXXXXXXXXXXXXXXXXXXXX'

def send_slack_notification(message):
    # Payload to send
    payload = {
        "text": message  # The message you want to send
    }

    # Sending the POST request to the webhook URL
    response = requests.post(slack_webhook_url, data=json.dumps(payload), headers={'Content-Type': 'application/json'})

    # Check for successful request
    if response.status_code == 200:
        print("Notification sent successfully!")
    else:
        print(f"Failed to send notification. Status code: {response.status_code}, Response: {response.text}")

# Example usage
send_slack_notification("Hello! This is a test notification from your Python script.")
