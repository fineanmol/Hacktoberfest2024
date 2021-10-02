import re  # import regex module


# check if the username is valid
def username_validation(self, username):
    if re.fullmatch(r"^(?=[a-zA-Z0-9._]{8,20}$)(?!.*[_.]{2})[^_.].*[^_.]$", username):
        return True
    else:
        return False


username_validation("youlot44")  # True/False
