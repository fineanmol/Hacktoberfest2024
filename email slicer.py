


def email_slicer(email):
    username, _, domain = email.strip().partition("@")
    return f"Your username is {username} & domain is {domain}"
user_input = input("Enter Your Email: ")
print(email_slicer(user_input))
