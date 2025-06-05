import string
import random
lower=string.ascii_uppercase
upper=string.ascii_lowercase
digits=string.digits
punct=string.punctuation

pwd_len=int(input("Enter password length:"))
print()
ch=int(input('''Enter complexity of password 
1 for Easy 
2 for Medium 
3.for Hard
:'''))


if ch==1: #easy => upper+lowercase letters only 
    pwd=[]
    pwd.extend(list(lower))
    pwd.extend(list(upper))
    key=random.sample(pwd,pwd_len)
    password=''.join(key)
    print(f'Generated password is {password}')

if ch==2: #medium => upper+loowercase+digits letters only 
    pwd=[]
    pwd.extend(list(lower))
    pwd.extend(list(upper))
    pwd.extend(list(digits))
    key=random.sample(pwd,pwd_len)
    password=''.join(key)
    print(f'Generated password is {password}')

if ch==3: #hard => upper+loowercase letters+digits+ punctutation  
    pwd=[]
    pwd.extend(list(lower))
    pwd.extend(list(upper))
    pwd.extend(list(digits))
    pwd.extend(list(punct))

    key=random.sample(pwd,pwd_len)
    password=''.join(key)
    print(f'Generated password is {password}')

