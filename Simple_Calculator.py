import os
import math


def add(n1, n2):
    return n1 + n2


def subtract(n1, n2):
    return n1 - n2


def multiply(n1, n2):
    return n1 * n2


def divide(n1, n2):
    return n1 / n2


def remainder(n1, n2):
    return n1 % n2


def permutation(n1, n2):
    n1 = int(n1)
    n2 = int(n2)
    return math.perm(n1, n2)


def combination(n1, n2):
    n1 = int(n1)
    n2 = int(n2)
    return math.comb(n1, n2)


def square(n):
    return n ** 2


def cube(n):
    return n ** 3


def factorial(n):
    n = int(n)
    if n < 0:
        print("INVALID OUTPUT")
        return
    return math.factorial(n)


def square_root(n):
    n = int(n)
    if n < 0:
        print("INVALID OUTPUT")
        return
    return math.sqrt(n)


def absolute_value(n):
    return math.fabs(n)


def log_with_base10(n):
    n = math.fabs(n)
    return math.log10(n)


def log_with_base2(n):
    n = math.fabs(n)
    return math.log2(n)


def log(n1, n2):  # First one is numberic value and second one is base
    n1 = math.fabs(n1)
    n2 = math.fabs(n2)
    return math.log(n1, n2)


def power(n1, n2):
    return math.pow(n1, n2)


def exponential(n):
    return math.exp(n)


def sum_of_numbers(n):
    n = int(n)
    sum = 0
    for item in range(n + 1):
        sum += item
    return sum


def sum_of_square_number(n):
    n = int(n)
    sum = 0
    for item in range(n + 1):
        sum += item ** 2
    return sum


def sum_of_cube_number(n):
    n = int(n)
    sum = 0
    for item in range(n + 1):
        sum += item ** 3
    return sum


def gamma_function(n):
    return math.gamma(n)


def log_gamma_function(n):
    return math.lgamma(n)


def convert_to_degree(n):
    return math.degrees(n)


def convert_to_radian(n):
    return math.radians(n)


def sine(n):
    return math.sin(n)


def cosine(n):
    return math.cos(n)


def tangent(n):
    return math.tan(n)


def inverse_sine(n):
    return math.asin(n)


def inverse_cosine(n):
    return math.acos(n)


def inverse_tangent(n):
    return math.atan(n)


def ceil(n):
    return math.ceil(n)


def floor(n):
    return math.floor(n)


def copysign(n1, n2):
    return math.copysign(n2, n1)


def greatest_common_divisor(n1, n2):
    n1 = int(n1)
    n2 = int(n2)
    return math.gcd(n1, n2)


def least_common_multiple(n1, n2):
    n1 = int(n1)
    n2 = int(n2)
    return math.lcm(n1, n2)


def round_off(n):
    return round(n)


def natural_logarithm(n):
    return math.log(n)


operations_with_single_opr = {
    "**": square,
    "***": cube,
    "!": factorial,
    "sqrt": square_root,
    "abs": absolute_value,
    "log10": log_with_base10,
    "log2": log_with_base2,
    "loge": natural_logarithm,
    "exp": exponential,
    "sum": sum_of_numbers,
    "squaresum": sum_of_square_number,
    "cubesum": sum_of_cube_number,
    "gamma": gamma_function,
    "loggamma": log_gamma_function,
    "todegree": convert_to_degree,
    "toradian": convert_to_radian,
    "sin": sine,
    "cos": cosine,
    "tan": tangent,
    "isin": inverse_sine,
    "icos": inverse_cosine,
    "itan": inverse_tangent,
    "ceil": ceil,
    "floor": floor,
    "round": round_off
}

operations_with_double_opr = {
    "+": add,
    "-": subtract,
    "*": multiply,
    "/": divide,
    "%": remainder,
    "perm": permutation,
    "comb": combination,
    "pow": power,
    "log": log,
    "copysign": copysign,
    "gcd": greatest_common_divisor,
    "lcm": least_common_multiple
}

mathematical_constants = {
    "pi": math.pi,
    "e": math.e,
    "tau": math.tau
}

logo = """
 _____________________
|  _________________  |
| | Pythonista   0. | |  .----------------.  .----------------.  .----------------.  .----------------.
| |_________________| | | .--------------. || .--------------. || .--------------. || .--------------. |
|  ___ ___ ___   ___  | | |     ______   | || |      __      | || |   _____      | || |     ______   | |
| | 7 | 8 | 9 | | + | | | |   .' ___  |  | || |     /  \     | || |  |_   _|     | || |   .' ___  |  | |
| |___|___|___| |___| | | |  / .'   \_|  | || |    / /\ \    | || |    | |       | || |  / .'   \_|  | |
| | 4 | 5 | 6 | | - | | | |  | |         | || |   / ____ \   | || |    | |   _   | || |  | |         | |
| |___|___|___| |___| | | |  \ `.___.'\  | || | _/ /    \ \_ | || |   _| |__/ |  | || |  \ `.___.'\  | |
| | 1 | 2 | 3 | | x | | | |   `._____.'  | || ||____|  |____|| || |  |________|  | || |   `._____.'  | |
| |___|___|___| |___| | | |              | || |              | || |              | || |              | |
| | . | 0 | = | | / | | | '--------------' || '--------------' || '--------------' || '--------------' |
| |___|___|___| |___| |  '----------------'  '----------------'  '----------------'  '----------------'
|_____________________|
"""

guide = """Welcome to the Python Calculator guide
There are certain mathematical functions in the Calculator that uses two operands, others single operand... So choose accordingly

n1=First number
n2=Second number

ARITHEMATIC FUNCTIONS:
+ : Add two numbers
- : Subtract n2 from n1
* : Multiply two numbers
/ : Divide n2 by n1
% : Returns the remainder after dividing n2 by n1
** : Square of the number
*** : Cube of the numnber

ALGEBRAIC FUNCTIONS:
! : Factorial of the given number
sqrt : Square root of the number
abs: Returns the Absolute value of the number
ceil : Return the value of the "Least Integer Function" value of the number
floor : Return the value of the "Greatest Integer Function" value of the number
round : Round off the number
perm : Return n1 P n2 , P is permutation
comb : Return n1 C n2 , C is combination
sum : Return the sum of all the natural numbers upto that number
squaresum : Return the sum of squares of all the natural numbers upto that number
cubesum: Return the sum of cubes of all the natural numbers upto that number
gcd: Return the Greatest Common Divisor among the two numbers
lcm: Return the Least Common Multiple among the two numbers

POWERS AND LOGARITHMS:
log10 : Returns Logarithm with base 10 of the number
log2 : Returns Logarithm with base 2 of the number
loge : Returns Logarithm with base e of the number
log : Returns Logarithm with base n2 of the n1
exp : Return e raised to the power of the number
pow : Return n1 raised to the power of n2

TRIGNOMETRIC FUNCTIONS:
todegree: Converts radians into degrees
toradian: Converts degrees into radians

NOTE: PYTHON TAKES INPUT OF FOLLOWING TRIGNOMETRIC FUNCTIONS AS RADIANS 
sin: Sine of the given number
cos: Cosine of the given number
tan: Tangent of the given number
isin: Inverse Sine of the given number
icos: Inverse Cosine of the given number
itan: Inverse Tangent of the given number

MISCELLANEOUS FUNCTIONS:
copysign : Copies the sign of the n1 to n2
gamma : Returns the gamma function of the number
loggamma : Returns the logarithm of the gamma function of the number 



"""


def choose_operation():
    print("WELCOME TO THE PYTHON CALCULATOR!!!!!")
    print(logo)
    if input("Do you want the Calculator Guide? Type 'y' to see else press enter: ") == 'y':
        print(guide)
    incorrect_operation = True
    while incorrect_operation:
        operation_choice = input(
            "Do you want a single operand operation or a double operand operation ? Type 's' for single and 'd' for double: ").lower()
        if operation_choice == "s":
            calculator_with_single_opr(prev_answer=None)
            incorrect_operation = False
        elif operation_choice == "d":
            calculator_with_double_opr(prev_answer=None)
            incorrect_operation = False
        else:
            print("WRONG INPUT TRY AGAIN")


def calculator_with_single_opr(prev_answer):
    if prev_answer != None:
        num = prev_answer
    else:
        for key in mathematical_constants:
            print(f'{key} : {mathematical_constants[key]}')
        constant = input(
            "Do you want to use a constant from above ? Enter the constant name as specified for use or enter 'n' for using your entered number: ").lower()

        if constant in mathematical_constants:
            num = mathematical_constants[constant]
            print(num)
        else:
            num = float(input("What's the first number: "))

    should_continue = True
    print("\n")
    while should_continue:

        for symbol in operations_with_single_opr:
            print(symbol)

        operation_symbol = input("Pick a operation from the above: ")

        calculation_function = operations_with_single_opr[operation_symbol]
        answer = calculation_function(num)
        print("\n")
        print(f"{num} {operation_symbol}  = {answer}")
        print("\n")
        direction = input(
            f"Type 'y' to continue calculating with {answer}, or 'd' to continue this calculation with double operand, or type 'n' to start a new calculation ,  or 'exit' to exit the calculator. ").lower()
        if direction == 'y':
            num = answer
            should_continue = True
        elif direction == 'n':
            should_continue = False
            os.system("cls")
            choose_operation()
        elif direction == 'd':
            should_continue = False
            prev_answer = answer
            calculator_with_double_opr(prev_answer)

        else:
            should_continue = False


def calculator_with_double_opr(prev_answer):
    if prev_answer != None:
        num1 = prev_answer
    else:
        for key in mathematical_constants:
            print(f'{key} : {mathematical_constants[key]}')
        constant = input(
            "Do you want to use a constant from above ? Enter the constant name as specified for use or enter 'n' for using your entered number: ").lower()
        if constant in mathematical_constants:
            num1 = mathematical_constants[constant]
            print(num1)
        else:
            num1 = float(input("What's the number: "))

    should_continue = True
    print("\n")

    while should_continue:
        for symbol in operations_with_double_opr:
            print(symbol)
        operation_symbol = input("Pick a operation from the above: ")
        print("\n")

        for key in mathematical_constants:
            print(f'{key} : {mathematical_constants[key]}')
        constant = input(
            "Do you want to use a constant from above ? Enter the constant name as specified for use or enter 'n' for using your entered number: ").lower()
        if constant in mathematical_constants:
            num2 = mathematical_constants[constant]
            print(num2)
        else:
            num2 = float(input("What's the second number: "))

        calculation_function = operations_with_double_opr[operation_symbol]
        answer = calculation_function(num1, num2)
        print("\n")
        print(f"{num1} {operation_symbol} {num2} = {answer}")
        print("\n")

        direction = input(
            f"Type 'y' to continue calculating with {answer}, or 's' continue this calculation with single operand, or type 'n' to start a new calculation,or 'exit' to exit the calculator. ").lower()
        if direction == 'y':
            num1 = answer
            should_continue = True
        elif direction == 'n':
            should_continue = False
            os.system("cls")
            choose_operation()
        elif direction == 's':
            should_continue = False
            prev_answer = answer
            calculator_with_single_opr(prev_answer)
        else:
            should_continue = False


choose_operation()

print(logo, "\nTHANK YOU FOR USING PYTHON CALCULATOR")
