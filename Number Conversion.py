def decimal_to_other_bases(decimal_number):

    binary_value = bin(decimal_number)[2:]

    octal_value = oct(decimal_number)[2:] 
  
    hexadecimal_value = hex(decimal_number)[2:].upper() 
    
    print(f"Decimal: {decimal_number}")
    print(f"Hexadecimal: {hexadecimal_value}")
    print(f"Binary: {binary_value}")
    print(f"Octal: {octal_value}")

decimal_input = int(input("Enter a decimal number: "))
decimal_to_other_bases(decimal_input)
