import random
import string

def generate_password(length=12, use_digits=True, use_special_chars=True):
    # Define character sets for the password
    letters = string.ascii_letters
    digits = string.digits if use_digits else ''
    special_chars = '!@#$%^&*()_+-=[]{}|;:,.<>?/' if use_special_chars else ''
    
    # Combine character sets based on user preferences
    characters = letters + digits + special_chars
    
    # Ensure the length of the password is valid
    if length < 6:
        length = 6
    
    # Generate the password
    password = ''.join(random.choice(characters) for _ in range(length))
    
    return password

if __name__ == "__main__":
    length = int(input("Enter the desired password length: "))
    use_digits = input("Include digits (yes/no): ").lower() == 'yes'
    use_special_chars = input("Include special characters (yes/no): ").lower() == 'yes'

    password = generate_password(length, use_digits, use_special_chars)
    print("Generated Password:", password)
