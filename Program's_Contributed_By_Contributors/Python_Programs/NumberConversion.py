# First, we will define the function to convert decimal to binary  
def decimal_into_binary(decimal_1):  
    decimal = int(decimal_1)  
    
    # then, print the equivalent decimal  
    print ("The given decimal number", decimal, "in Binary number is: ", bin(decimal))  
# we will define the function to convert decimal to octal  
def decimal_into_octal(decimal_1):  
    decimal = int(decimal_1)  
    
    # Then, print the equivalent decimal  
    print ("The given decimal number", decimal, "in Octal number is: ", oct(decimal))  
# we will define the function to convert decimal to hexadecimal  
def decimal_into_hexadecimal(decimal_1):  
    decimal = int(decimal_1)  
    
    # Then, print the equivalent decimal  
    print ("The given decimal number", decimal, " in Hexadecimal number is: ", hex(decimal))  
    
# Driver program  
decimal_1 = int (input (" Enter the Decimal Number: "))  
decimal_into_binary(decimal_1)  
decimal_into_octal(decimal_1)  
decimal_into_hexadecimal(decimal_1)  
