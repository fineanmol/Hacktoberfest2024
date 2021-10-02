import re  # import regular expression module

# class for regex snippets
class regex:
    def __init__(self) -> None:
        pass

    # Matching string
    def str_match(self, pattern, string):
        if re.search(pattern, string):
            return True  # match
        else:
            return False  # no match

    # Check the strength of password
    def password_strength(self, password):
        if re.fullmatch(r"[A-Za-z0-9@#$%^&+=]{8,}", password):
            return True  # storng password
        else:
            return False  # weak password


reg = regex()

print(reg.match("[a-z]", "a"))
