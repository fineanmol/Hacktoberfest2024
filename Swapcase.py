def swap_case(s):
    new_s = ""
    for letter in range(len(s)):    
        if s[letter].islower():
            new_s += str(s[letter].upper())
        else:            
            new_s += str(s[letter].lower())
    return new_s