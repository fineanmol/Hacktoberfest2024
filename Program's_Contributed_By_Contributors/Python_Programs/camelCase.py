# python program to format string to camel case
a = input().replace('.', ' ').replace('(', ' ').split()
camel = []
for word in a:
    firstChar = True
    for index in range(len(word)):
        if (word[index] >= 'A' and word[index] <= 'Z') or (word[index] >= 'a' and word[index] <= 'z') or (word[index] >= '0' and word[index] <= '9'):
            if firstChar:
                camel.append(word[index].upper())
                firstChar = False
            else:
                camel.append(word[index].lower())
camel = ''.join(camel)
print(camel.replace(camel[0], camel[0].lower(), 1))
