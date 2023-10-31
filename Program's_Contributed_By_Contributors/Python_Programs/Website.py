
"""A website requires the users to input username and password to register.
Write a program to check the validity of password input by users.
Following are the criteria for checking the password:
1. At least 1 letter between [a-z]
2. At least 1 number between [0-9]
1. At least 1 letter between [A-Z]
3. At least 1 character from [$#@]
4. Minimum length of transaction password: 6
5. Maximum length of transaction password: 12
Your program should accept a sequence of comma separated passwords and will check them
according to the above criteria. Passwords that match the criteria are to be printed,
each separated by a comma.
Example
If the following passwords are given as input to the program:
ABd1234@1,a F1#,2w3E*,2We3345
Then, the output of the program should be:
ABd1234@1
"""

import re
value = []
items=[x for x in raw_input("enter the password ").split(',')]
print items
for p in items:
     print "length is ",len(p)
     if len(p)<6 or len(p)>12:
               continue
     if not re.search("[a-z]",p):
                print " a-z characters  not in the password"
                continue
     elif not re.search("[0-9]",p):
                print "0-9 letters are not in password"
                continue
     elif not re.search("[A-Z]",p):
                print "A-Z alphabets are not in password"
                continue
     elif not re.search("[$#@]",p):
                print "symbols are not in password"
                continue
     else:
               value.append(p)
print " , ".join(value)

"""
output:
enter the password Udac!@323, @Fhguwewh123,Lalit@123
Udac!@323,Lalit@123
"""
