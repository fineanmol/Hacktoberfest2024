import re  # import regex module

# validate email
def email_validation(self, email):
    if re.fullmatch(r"/[A-Z0-9._%+-]+@[A-Z0-9-]+.+.[A-Z]{2,4}/igm", email):
        return True
    else:
        return False


email_validation("home@gmail.com")  # returns True/False
