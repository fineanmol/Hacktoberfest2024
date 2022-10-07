# Python program to validate an Email
 
# import re module
import re
  
# Make a regular expression
email_condition="^[a-z]+[\._]?[a-z 0-9]+[@]\w+[.]\w{2,3}$"
 
# taking input the Email
 
user_email=input('Enter user email ID : ')
 
# Validating Email 
# We will use the search method from re module
 
if re.search(email_condition,user_email) : 
    print('Valid Email')
else : 
    print('Invalid Email')