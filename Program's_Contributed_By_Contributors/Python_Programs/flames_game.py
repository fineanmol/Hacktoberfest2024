def flames_game(name1, name2):
    # Convert names to uppercase and remove spaces
    name1 = name1.upper().replace(" ", "")
    name2 = name2.upper().replace(" ", "")

    # Create a dictionary to count the frequency of each letter in both names
    letter_count = {}

    for letter in name1:
        if letter in letter_count:
            letter_count[letter] += 1
        else:
            letter_count[letter] = 1

    for letter in name2:
        if letter in letter_count:
            letter_count[letter] += 1
        else:
            letter_count[letter] = 1

    # Calculate the total count of letters that are not common
    not_common_count = 0
    for count in letter_count.values():
        if count % 2 != 0:
            not_common_count += 1

    # Define the FLAMES words and their meanings
    flames = ["Friendship", "Love", "Affection", "Marriage", "Enemy", "Siblings"]

    # Perform the FLAMES calculations
    while len(flames) > 1:
        index = (not_common_count % len(flames)) - 1
        flames.pop(index)

    # The result is the remaining word in the flames list
    result = flames[0]

    return result

# Input two names
name1 = input("Enter the first name: ")
name2 = input("Enter the second name: ")

# Calculate and display the result
result = flames_game(name1, name2)
print("Result of the FLAMES game:", result)
