import re  # import regular expression module

# class for regex snippets
class regex:
    def __init__(self) -> None:
        pass

    # Matching string
    def match(self, pattern, string):
        if re.search(pattern, string):
            return True
        else:
            return False


reg = regex()

print(reg.match("[a-z]", "a"))
