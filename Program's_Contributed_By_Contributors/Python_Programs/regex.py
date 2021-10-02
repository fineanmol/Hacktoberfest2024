# simple string matching and other normal validation using regular expressions

import re  # import regular expression module

# class for regex snippets
class regex:
    def __init__(self) -> None:
        pass

    # Matching string
    def str_match(self, pattern, string):
        if re.search(pattern, string):
            return True
        else:
            return False
