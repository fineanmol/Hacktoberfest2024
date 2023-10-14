def fizzbuzz(n):
    for i in range(1, n + 1):
        output = ""
        if i % 3 == 0:
            output += "Fizz"
        if i % 5 == 0:
            output += "Buzz"
        print(output or i)

# Additional feature: Custom range
def fizzbuzz_custom(start, end):
    for i in range(start, end + 1):
        output = ""
        if i % 3 == 0:
            output += "Fizz"
        if i % 5 == 0:
            output += "Buzz"
        print(output or i)

fizzbuzz(100)
fizzbuzz_custom(50, 75)
