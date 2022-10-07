def main():

    print("This program translates words to morse code\n")

    words = input("Enter a word or phrase to be encoded: ")
    words = words.upper()

    codeDict = createDict()

    i = 0

    try:
        while (i < len(words)):
            if (words[i] != " "):
                print(codeDict[words[i]], end = " ")
            else:
                print("/", end = " ")
            i += 1
    except:
        print("\nInvalid characters found - refer to morse code alphabet")


def createDict():
    code = {'A': '.-',
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
            '1': '.----',
            '2': '..---',
            '3': '...--',
            '4': '....-',
            '5': '.....',
            '6': '-....',
            '7': '--...',
            '8': '---..',
            '9': '----.',
            '0': '-----'}

    return code


main()