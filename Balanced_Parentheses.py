# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if brackets are closed in the correct order.

def is_valid(s):
    stack = []
    brackets = {')': '(', '}': '{', ']': '['}

    for char in s:
        if char in brackets.values():
            stack.append(char)
        elif char in brackets.keys():
            if not stack or stack.pop() != brackets[char]:
                return False
        else:
            return False

    return not stack

# Example usage:
input_str = "{[()]}"

if is_valid(input_str):
    print(f"The input string '{input_str}' is valid.")
else:
    print(f"The input string '{input_str}' is not valid.")
