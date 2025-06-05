def fizz_buzz_tricky(n):
    # Iterate from 1 to n (inclusive)
    for i in range(1, n + 1):
        output = ""

        # Check if the current number is a multiple of 3
        if i % 3 == 0:
            output += "Fizz"  # If yes, add "Fizz" to the output

        # Check if the current number is a multiple of 5
        if i % 5 == 0:
            output += "Buzz"  # If yes, add "Buzz" to the output

        # If the current number is not a multiple of 3 or 5, output the number itself
        if not output:
            output = i

        # Print the result (either "Fizz", "Buzz", "FizzBuzz", or the number)
        print(output)

if __name__ == "__main__":
    # Take user input for the upper limit of the FizzBuzz sequence
    n = int(input("Enter a number: "))

    # Call the fizz_buzz_tricky function with the user-provided input
    fizz_buzz_tricky(n)
