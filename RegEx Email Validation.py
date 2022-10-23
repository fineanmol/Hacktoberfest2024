import re
print ("Email Validator")
email = input("Input the email address to be validated: ")

#RegEx can be modified as user need
#for more RegEx visit https://regexr.com/

if not re.match("^[A-Za-z0-9\.\+_-]+@[A-Za-z0-9\._-]+\.[a-zA-Z]*$", email):
    print ("Email is not valid.")
else:
    print ("Email is valid.")