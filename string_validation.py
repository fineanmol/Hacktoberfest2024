if __name__ == '__main__':
    s = input("Enter The Letter :")
    alpha_num = False
    alpha_bet = False
    dig_it = False 
    lower = False
    upper = False
    
    for c in s :
        if c.isalnum():
            alpha_num = True
        if c.isalpha():
            alpha_bet = True
        if c.isdigit():
            dig_it = True
        if c.islower():
            lower = True
        if c.isupper():
            upper = True

print(alpha_num)
print(alpha_bet)
print(dig_it)
print(lower)
print(upper)
