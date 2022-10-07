s = input()
rom_val = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
int_val = 0
for i in range(len(s)):
    if i > 0 and rom_val[s[i]] > rom_val[s[i - 1]]: #Checking for subtraction cases. Ex: IX = 9.
        int_val += rom_val[s[i]] - 2 * rom_val[s[i - 1]] # Add the subtracted correspoding number to the answer. Ex: int_val = 9 if IX
    else:
        int_val += rom_val[s[i]] # Just add the corresponding number. Ex: int_val = 100 if C
print(int_val)
