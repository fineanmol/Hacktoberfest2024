'''
Program for morse code transnlator using python
'''


import sys
import string


CODE = {
    # ----------Alphabets----------
    'A': '.-',
    'B': '-...',
    'C': '-.-.',
    'D': '-..',
    'E': '.',
    'F': '..-.',
    'G': '--.',
    'H': '....',
    'I': '..',
    'J': '.---',
    'K': '-.-',
    'L': '.-..',
    'M': '--',
    'N': '-.',
    'O': '---',
    'P': '.--.',
    'Q': '--.-',
    'R': '.-.',
    'S': '...',
    'T': '-',
    'U': '..-',
    'V': '...-',
    'W': '.--',
    'X': '-..-',
    'Y': '-.--',
    'Z': '--..',
    # ----------Numbers----------
    '0': '-----',
    '1': '.----',
    '2': '..---',
    '3': '...--',
    '4': '....-',
    '5': '.....',
    '6': '-....',
    '7': '--...',
    '8': '---..',
    '9': '----.',
    # ----------Punctuations/Symbols----------
    '.': '.-.-.-',
    ',': '--..--',
    '?': '..--..',
    "'": '.----.',
    '!': '-.-.--',
    '/': '-..-.',
    '(': '-.--.',
    ')': '-.--.-',
    '&': '.-...',
    ':': '---...',
    ';': '-.-.-.',
    '=': '-...-',
    '+': '.-.-.',
    '-': '-....-',
    '_': '..--.-',
    '"': '.-..-.',
    '$': '...-..-',
    '@': '.--.-.',
    '¿': '..-.-',
    '¡': '--...-'
}


def display():
    '''
    Displays the menu
    '''
    print('\n', ''.center(80, '='), sep='\n')
    print('WELCOME TO MORSE CODE TRANSLATOR'.center(80, '-'))
    print(''.center(80, '='))
    print('\n', 'MENU'.center(80, '-'), sep='\n')
    print('1. MORSE CODE TO ENGLISH')
    print('2. ENGLISH TO MORSE CODE')
    print('ELSE : EXIT')


def ret_code(val: string) -> string:
    '''
    returns the decoded meanings (Keys) from the morse (values) stored in CODE dictionary
    '''
    for dec, morse in CODE.items():
        if morse == val:
            return dec

    return -1


def decode(inp_str: string) -> string:
    '''
    Converts the morse code recieved to english using decoded.py
    '''
    answer = ''
    inp_lst = inp_str.strip().split()
    for char in inp_lst:
        if char != '/':
            try:
                answer += ret_code(char)
            except TypeError:
                sys.exit(
                    '\n' + 'UNKNOWN MORSE AS INPUT'.center(80, '*') + '\n')
        else:
            answer += ' '

    return answer


def encode(inp_str: string) -> string:
    '''
    Converts the english statement recieved to morse code
    '''
    answer = ''
    for char in inp_str:
        if char != ' ':
            try:
                answer += CODE[char.upper() if char.isalpha() else char] + ' '
            except KeyError:
                sys.exit(
                    '\n' + 'UNKNOWN CHARACTER AS INPUT'.center(80, '*') + '\n')
        else:
            answer += ' / '
    return answer.strip()


def main():
    '''
    Main function of the program
    '''
    choice = 1
    while choice <= 2:
        display()
        try:
            choice = int(input('Enter: '))
        except ValueError:
            choice = -1
        if choice in [1, 2]:
            input_string = input("Enter the string to be converted : ")
        if choice == 1:
            english = decode(input_string)
            print('\nENGLISH TRANSLATION : ', english, sep='  ')
        elif choice == 2:
            morse_code = encode(input_string)
            print('\nMORSE CODE EQUIVALENT : ', morse_code, sep='  ')
    sys.exit('\n' + '!!!PROGRAM ENDED!!!'.center(80, '*') + '\n')


if __name__ == '__main__':
    main()
