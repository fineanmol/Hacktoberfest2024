



print('Enter the expression: ')

express = input()
# print(express)
post = []
e = []

expressions = ['^', '/', '*', '+', '-']

for exp in express:
    if exp.isalnum():
        post.append(exp)
    elif exp in expressions:
        if len(e) == 0 or e[-1] == '(' or expressions.index(e[-1]) > expressions.index(exp):
            e.append(exp)
        else:
            while e[-1] != '(' and expressions.index(e[-1]) <= expressions.index(exp):
                post.append(e.pop())
            e.append(exp)
    elif exp == '(':
        e.append(exp)
    elif exp == ')':
        while e[-1] != '(':
            post.append(e.pop())
        e.pop()

    # print(post)
    # print(e)
print('Required postfix expression: ', end='')
for exp in post:
    print(exp, end='')