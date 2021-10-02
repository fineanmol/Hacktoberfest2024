import re  # import regex module

# Check the strength of password
def password_strength(self, password):
    if re.fullmatch(r"[A-Za-z0-9@#$%^&+=]{8,}", password):
        return True
    else:
        return False


password_strength("sdlfjd203")  # returns True/False
