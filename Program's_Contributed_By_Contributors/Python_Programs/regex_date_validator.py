import re # import regex module

# check if date is valid (yyyy-mm-dd)
def date_validation(self, date):
    if re.fullmatch(r"/^\d{4}-\d{2}-\d{2}$/", date):
        return True
    else:
        return False
        
date_validation(2022-02-29) # False/True