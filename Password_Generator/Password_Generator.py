import random
import string
import secrets

def generate_password(length=8, include_digits=True, include_special=True):
    if length < 8:
        raise ValueError("Password length should be at least 8 characters for security.")
    
    lower = string.ascii_lowercase
    upper = string.ascii_uppercase
    digits = string.digits if include_digits else ""
    special = "!@#$%^&*()_+-=[]{}|;:,.<>?" if include_special else ""
    
    all_chars = lower + upper + digits + special
    
    while True:
        password = ''.join(secrets.choice(all_chars) for _ in range(length))
        if (any(c.islower() for c in password)
            and any(c.isupper() for c in password)
            and (sum(c.isdigit() for c in password) >= 2 if include_digits else True)
            and (sum(c in special for c in password) >= 1 if include_special else True)):
            return password

def strengthen_password(base_password):
    if len(base_password) < 8:
        raise ValueError("Base password should be at least 8 characters long.")
    
    lower = string.ascii_lowercase
    upper = string.ascii_uppercase
    digits = string.digits
    special = "!@#$%^&*()_+-=[]{}|;:,.<>?"
    
    password = list(base_password)
    
    if not any(c.islower() for c in password):
        password.append(secrets.choice(lower))
    if not any(c.isupper() for c in password):
        password.append(secrets.choice(upper))
    if sum(c.isdigit() for c in password) < 2:
        password.extend(secrets.choice(digits) for _ in range(2 - sum(c.isdigit() for c in password)))
    if sum(c in special for c in password) < 1:
        password.append(secrets.choice(special))
    
    random.shuffle(password)
    return ''.join(password)

def password_strength(password):
    strength = 0
    if len(password) >= 12:
        strength += 1
    if any(c.islower() for c in password):
        strength += 1
    if any(c.isupper() for c in password):
        strength += 1
    if any(c.isdigit() for c in password):
        strength += 1
    if any(c in "!@#$%^&*()_+-=[]{}|;:,.<>?" for c in password):
        strength += 1
    return strength

def save_password_to_file(password):
    with open("generated_passwords.txt", "a") as f:
        f.write(password + "\n")

if __name__ == "__main__":
    choice = input("Do you want to (g)enerate a new password or (s)trengthen an existing password? (g/s): ").strip().lower()
    
    if choice == 'g':
        user_input = input("Enter desired password length (at least 8): ")
        include_digits = input("Include digits? (y/n): ").strip().lower() == 'y'
        include_special = input("Include special characters? (y/n): ").strip().lower() == 'y'
        
        try:
            password_length = int(user_input)
            strong_password = generate_password(password_length, include_digits, include_special)
            print(f"Your generated password is: {strong_password}")
            print(f"Password Strength: {password_strength(strong_password)}/5")
            save_password_to_file(strong_password)
        except ValueError as e:
            print(f"Error: {e}")
    
    elif choice == 's':
        user_input = input("Enter a base password to strengthen: ")
        
        try:
            strengthened_password = strengthen_password(user_input)
            print(f"Your strengthened password is: {strengthened_password}")
            print(f"Password Strength: {password_strength(strengthened_password)}/5")
            save_password_to_file(strengthened_password)
        except ValueError as e:
            print(f"Error: {e}")
    
    else:
        print("Invalid choice. Please enter 'g' or 's'.")