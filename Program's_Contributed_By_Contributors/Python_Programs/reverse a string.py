def reverse(input_string):
    reversed_list = []
    for i in reversed(range(len(input_string))):

        reversed_list.append(input_string[i])
    return ''.join(reversed_list)


Input = input("Please Enter a String: ")
print(reverse(list(Input)))
