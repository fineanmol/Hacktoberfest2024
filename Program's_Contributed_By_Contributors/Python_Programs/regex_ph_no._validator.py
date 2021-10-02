import re  # import regular expression module

# check if the phone number is valid
def phone_validation(self, phone):
    if re.fullmatch(r"/^\d{10}$/", phone):
        return True
    else:
        return False


phone_validation("9888888888")  # True/False
