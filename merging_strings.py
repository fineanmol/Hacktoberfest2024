n = int(input())

for i in range(n):
    m = int(input())
    s1 = input()
    s2 = input()
    ans = ''
    i_s1 = 0
    i_s2 = 0
    while True:

        if i_s1 == m or i_s2 == m:
            break

        if int(s1[i_s1]) > int(s2[i_s2]):
            ans = ans + s2[i_s2]
            i_s2 += 1
        elif int(s1[i_s1]) < int(s2[i_s2]):
            ans = ans + s1[i_s1]
            i_s1 += 1
        else :
            ans = ans + s1[i_s1]
            i_s1 += 1
            ans = ans + s2[i_s2]
            i_s2 += 1

    if i_s1 < m :
        ans = ans + s1[i_s1:]
    elif i_s2 < m:
        ans = ans + s2[i_s2:]
    print(ans)
