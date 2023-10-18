import random
import string

def generate_password(length=12, use_digits=True, use_special_chars=True):
    """Generate a random password of the specified length."""
    characters = string.ascii_letters
    if use_digits:
        characters += string.digits
    if use_special_chars:
        characters += string.punctuation

    if length < 1:
        return "Password length must be at least 1"
    elif not (use_digits or use_special_chars):
        return "Password must contain digits or special characters for security"

    password = ''.join(random.choice(characters) for _ in range(length))
    return password

if __name__ == "__main__":
    length = 12
    include_digits = True
    include_special_chars = True

    password = generate_password(length, include_digits, include_special_chars)
    print(f"Generated Password: {password}")
