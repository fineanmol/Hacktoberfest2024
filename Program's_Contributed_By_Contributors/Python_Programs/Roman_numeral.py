rom_num = input("Enter the Roman numeral:")
num = [1, 5, 10, 50, 100, 500, 1000 ]
roman = ["I", "V", "X", "L", "C", "D", "M"]
res = 0 

for i in range(len(rom_num)):
    j = num[roman.index(rom_num[i])]
    if i != len(rom_num)-1 :
        if j < num[roman.index(rom_num[i+1])]:
            res -=  j
        else:
            res += j
    else:
        res += j

print(res)
