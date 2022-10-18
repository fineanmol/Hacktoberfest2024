def swap_case(s):
    string = ""
    for i in range(len(s)):
        if s[i].isupper():
            string = string + s[i].lower()
        else:
            string = string + s[i].upper()
    
    return string
    #return s.swapcase()

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
