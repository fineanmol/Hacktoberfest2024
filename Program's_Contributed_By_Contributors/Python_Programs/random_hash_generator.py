import secrets

def gen_one_hash():
    try:
        length = int(input("Enter The Length Of Hash: "))
        print(f"Hash: {secrets.token_hex(nbytes=length)}")
    except Exception as error:
        print(error)

def gen_multi_hash():
    try:
        txt = ""
        length = int(input("Enter The Length Of Hash: "))
        no = int(input("Enter How many Of Hash you want: "))
        for i in range(no):
            txt += f"{secrets.token_hex(nbytes=length)}\n"
        with open("hash.txt", "w") as f:
            f.write(txt)
        print("Successfully Generated Check hash.txt in the current folder")
    except Exception as error:
        print(error)

gen_one_hash()
gen_multi_hash()
