import pikepdf
from tqdm import tqdm

def pdfcrack():
    print("\t\t\t Tool: PDF Cracker \n |\t\tCoded By Bishal Aryal Batch30 Ethical Hacking \n | \t\t\t Twitter @C15C01337") #here /t is tab
    print("_"*80+"\n")
    print("Greetings! Welcome to the PDF cracker")
    # Open the file to decrypt
    userpdf = input("[*] Enter the name of password protected pdf: ")

    # Use the wordlist for list of passwords
    PASSlist = input("[*] Enter wordlist: ")

    passwords = [ line.strip() for line in open(PASSlist) ]
    # Run iteration over password list
    for password in tqdm(passwords, "Decrypting the Password Protected PDF"):
        try:
            # open the password protected PDF file
            with pikepdf.open(userpdf, password=password) as pdf:
                print("[+] Congratulations !!! Password decrypted successfully", password)
                break
        except pikepdf._qpdf.PasswordError as e:
            # Loop will continue until the password is found
            continue

if __name__ == "__pdfcrack__":
	pdfcrack()

