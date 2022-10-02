# FizzBuzz implementation using sets
# Author: @muhazafasa

from random import randint

all_fizz = {i * 3 for i in range(1, 100 // 3 + 1)}
all_buzz = {i * 5 for i in range(1, 100 // 5 + 1)}
all_fizzbuzz = all_fizz & all_buzz
rest_numbers = set(range(1, 101)) - all_fizz - all_buzz

results = [
    (all_fizzbuzz, lambda x: 'FizzBuzz'),
    (all_fizz, lambda x: 'Fizz'),
    (all_buzz, lambda x: 'Buzz'),
    (rest_numbers, lambda x: x)
]

while True:
    number = randint(1, 100)
    for pair in results:
        kind, solution = pair
        if number in kind:
            print(solution(number))
            break
    input()
