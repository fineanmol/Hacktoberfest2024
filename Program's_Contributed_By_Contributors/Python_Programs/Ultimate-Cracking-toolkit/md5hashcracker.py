import hashlib

def hashCrack():
        print("\t\t\t Tool: Md5hashcracker \n | \t\tCoded By Bishal Aryal Batch30 Ethical Hacking \n | \t\t\t Twitter @C15C01337") #here /t is tab
        print("_"*80+"\n")
        print("")
        print("Greetings! Welcome to the md5 hash Cracker")
        print("")
        HASH = input('[*] Enter MD5 hash: ')
        passwordlist = []
        print("")
        wordlist = input("[*] Enter wordlist: ")
        with open (wordlist, 'r') as file:
                for line in file:
                        line = line.strip()
                        passwordlist.append(line)

        for word in passwordlist:
                guess = hashlib.md5(word.encode('utf-8')).hexdigest()
                if guess.upper() == HASH or guess.lower() == HASH:
                        print(f'[+] Password found: {word} cooresponds to the hash: {guess}')
                        
        print('If it is unable to crack the password :( Please generate another wordlist...')    

if __name__ == '__main__':
        hashCrack()