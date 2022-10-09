import zipfile
from tqdm import tqdm 

def zipcrack():
    print("\t\t\t Tool: Zip Cracker \n |\t\tCoded By Bishal Aryal Batch30 Ethical Hacking \n | \t\t\t Twitter @C15C01337") #here /t is tab
    print("_"*80+"\n")

    print("Greetings! Welcome to the Zip Cracker")

    # Specify the  file to decrypt
    userzip = input("[*] Enter the name of zip: ")

    # Use the wordlist for list of passwords
    PASSlist = input("[*] Enter wordlist: ")

    # Starting the Zip File object
    zip_file = zipfile.ZipFile(userzip)

    with open(PASSlist, "rb") as wordlist:
        for word in tqdm(wordlist):
            try:
                zip_file.extractall(pwd=word.strip())
            except:
                continue
            else:
                print("[+] Congratulations !!! Password decrypted successfully:", word.decode().strip())
    print("[!] If Password not found :) Try generating other password wordlist.")

if __name__ == "__zipcrack__":
	zipcrack()