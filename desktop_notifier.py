import time
from plyer import notification

while True:
    notification.notify(
        title="Please Take Break",
        message='''Doctors recommend rest of 15 minutes after 2 hours of work on digital device to prevent eye strain.Digital eye strain is a problem caused by extended digital device use.Symptoms include eye discomfort and fatigue,dry eye,blurry vision,and headaches.''',
        timeout=10
    )
    time.sleep(60*120)
    
