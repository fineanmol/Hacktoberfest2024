import math, random
def genrateOTP():
    digits = "0123456789"
    OTP = ""
    for i in range(4):
        OTP += digits[math.floor(random.random()*10)]
    return OTP
print("Your 4 digit OTp is:",genrateOTP())