def prime(n):
    flag = 0
    for i in range(2, (n // 2) + 1):
        if n % i == 0:
            flag = 1
            break
    return flag


t_range = int(input("Enter Range : "))

print("Twin Prime between : ")
for i in range(1, t_range + 1):
    if prime(i) == 0 and prime(i + 2) == 0:
        print(i, " ", i + 2)
