import random
import string

def generate_password(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for _ in range(length))
    return password

if __name__ == "__main__":
    print("Password Generator")

    while True:
        try:
            length = int(input("Enter the desired password length: "))
            if length < 6:
                print("Password length should be at least 6 characters.")
            else:
                break
        except ValueError:
            print("Please enter a valid number.")

    password = generate_password(length)
    print(f"Generated Password: {password}")
