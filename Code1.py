# Compressing a string
# representing repeating characters as a tuple of the character and their frequency
List = list(map(int, input("Enter the string you want to compress : ")))
Listr = []
for i in range(len(List)):
    count = 1
    if i == 0:
        for j in range(i, len(List)-1):
            if List[j] == List[j+1]:
                count += 1
            else:
                break
        Listr.append(str((count, List[i])))
        continue
    if List[i] == List[i-1]:
        continue
    else:
        count = 1
        for j in range(i, len(List)-1):
            if List[j] == List[j+1]:
                count += 1
            else:
                break
        Listr.append(str((count, List[i])))

print("The compressed string is : ", end="")
print(*Listr)
