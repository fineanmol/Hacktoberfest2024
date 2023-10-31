from cryptography.fernet import Fernet

def generate_key():
    return Fernet.generate_key()

def encrypt_file(file_path, key):
    with open(file_path, 'rb') as file:
        data = file.read()
    fernet = Fernet(key)
    encrypted_data = fernet.encrypt(data)
    with open(file_path, 'wb') as file:
        file.write(encrypted_data)

def decrypt_file(file_path, key):
    with open(file_path, 'rb') as file:
        data = file.read()
    fernet = Fernet(key)
    decrypted_data = fernet.decrypt(data)
    with open(file_path, 'wb') as file:
        file.write(decrypted_data)

if __name__ == "__main__":
    key = generate_key()
    file_path = "example.txt"
    
    encrypt_file(file_path, key)
    print("File encrypted.")
    
    decrypt_file(file_path, key)
    print("File decrypted.")
