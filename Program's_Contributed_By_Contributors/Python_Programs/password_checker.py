s = "we_lov3_h@ct0ber"

has_lower, has_upper, has_special, has_digit = False, False, False, False

if len(s) < 8:
    print("Invalid Password")
else:
    for char in s:
        if char.islower():
            has_lower = True
        elif char.isupper():
            has_upper = True
        elif char.isdigit():
            has_digit = True
        elif char in '@$_':
            has_special = True

    if all([has_lower, has_upper, has_digit, has_special]):
        print("Valid Password!")
    else:
        print("Invalid Password")
