import sys


def main():
    a = get_num("Enter a Number: ")
    m = get_num("Enter the last Multiple: ")
    for i in range(1, m + 1):
        print( a , " * " , i , " = " , a * i, )


# creating a function "get_num " to get user inputs which takes an argument s to be displayed on the terminal as a prompt


def get_num(s):
    try:
        x = float(input(s))
        # if input number is an integer then printing the number in the table removing .0 in the output

        if x.is_integer():
            x = int(x)
        return x

    except ValueError:
        # if user enters wrong type like a string then program will end

        print("\n Please Enter a integer or real number! \n")
        sys.exit()


if __name__ == "__main__":
    main()
