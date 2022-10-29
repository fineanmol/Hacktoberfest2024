 # a decimal number to
# octal number
  
# function to convert
# decimal to octal
  
  
def decToOctal(n):
  
    # array to store
    # octal number
    octalNum = [0] * 100
  
    # counter for octal
    # number array
    i = 0
    while (n != 0):
  
        # storing remainder
        # in octal array
        octalNum[i] = n % 8
        n = int(n / 8)
        i += 1
  
    # printing octal number
    # array in reverse order
    for j in range(i - 1, -1, -1):
        print(octalNum[j], end="")
  
  
# Driver Code
n = 33
