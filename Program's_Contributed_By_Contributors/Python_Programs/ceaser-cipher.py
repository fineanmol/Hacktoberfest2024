def ceaser_cipher_encoder(message,shift_num):
    alphabets = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    solution = ''
    for i in message:
        element_index = alphabets.index(i)
        length = len(alphabets)-1
        if (length - element_index >= shift_num):
            new_element_index = element_index + shift_num
        else:
            new_element_index = shift_num - (length - element_index) - 1
        solution = solution + alphabets[new_element_index]
    print("Encoded message is: ",solution)

def ceaser_cipher_decoder(message,shift_num):
    alphabets = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    solution = ''
    for i in message:
        element_index = alphabets.index(i)
        if (element_index >= shift_num):
            new_element_index = element_index - shift_num
        else:
            new_element_index = -1*(shift_num - element_index)
        solution = solution + alphabets[new_element_index]
    print("Decoded message is: ",solution)

cont = 'y'
while(cont.lower() == 'y'):
    print("1. Ceaser Cipher Encoder\n")
    print("2. Ceaser Cipher Decoder")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        message = input("Enter a message encode without spaces: ")
        shift_num = int(input("Enter the shift number: "))
        ceaser_cipher_encoder(message, shift_num)
    elif choice == 2:
        message = input("Enter a message to decode without spaces: ")
        shift_num = int(input("Enter the shift number: "))
        ceaser_cipher_decoder(message, shift_num)
    else:
        print("Invalid Input")
    cont = input("Do you want to continue(y/n): ")
else:
    print("Thank You")
