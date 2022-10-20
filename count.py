# given string
string = "python1234"
 
# initialized value
total_digits = 0
total_letters = 0
 
# iterate through all characters
for s in string:
 
    # if character is digit (return True)
    if s.isnumeric():
        total_digits += 1
 
    # if character is letter (return False)
    else:
        total_letters += 1
 
print("Total letters found :-", total_letters)
print("Total digits found :-", total_digits)
