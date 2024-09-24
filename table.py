import pyotp
import time


def generate_time_based_otp(secret):
    totp = pyotp.TOTP(secret)
    return totp.now()

def generate_event_based_otp(secret, counter):
    hotp = pyotp.HOTP(secret)
    return hotp.at(counter)


secret = pyotp.random_base32()
print("Time-based OTP:", generate_time_based_otp(secret))
print("Event-based OTP:", generate_event_based_otp(secret, 0))  
