# check if the string matches with the given pattern

import re  # import regular expression module

# Matching string
def str_match(pattern, string):
    if re.search(pattern, string):
        return True
    else:
        return False


str_match("[a-z]", "a")  # True/False
