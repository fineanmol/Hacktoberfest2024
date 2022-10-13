size = int(input('Enter size of memory: '))

l = []
for x in range(0, size):
    l.append(0)

print('Enter Y -> Memory Allocation, M -> View Choices, N -> Exit')
while True:
    choice = input('Do You want allocate memory: ')
    if choice == 'Y' or choice == 'y':
        a, b = map(int, input('Enter memory range: ').split())
        for x in range(a, b):
            l[x] = 1
    elif choice == 'M' or choice == 'm':
        print('Enter Y -> Memory Allocation, M -> View Choices, N -> Exit')
    else:
        break

p = int(input('Enter process size: '))
m = []
index = 0
a = -1
b = -1
for x in l:
    if x == 0:
        if a == -1:
            a = index
    elif x == 1:
        if a != -1:
            m.append([a, index])
        a = -1
    index += 1

minimum = size
for x in m:
    s = x[1] - x[0]
    if p <= s < minimum:
        minimum = s

for x in m:
    if minimum == (x[1] - x[0]):
        print(f'Process can be executed in range {x[0]} and {x[1]}')
