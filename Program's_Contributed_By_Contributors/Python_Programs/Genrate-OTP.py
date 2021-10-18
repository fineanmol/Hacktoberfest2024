import string, random
def generateOTP(num):
    OTP = ''.join(random.choices(string.digits,k=num))
    return OTP
num=int(input("How many digits OTP: "))
print(generateOTP(num))
