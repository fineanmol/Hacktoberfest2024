num = [40,32,55,21,90,33,15,31] #input your number here

i = 0
while (i<len(num)-1):
    if num[i] > num[i+1]:
        temp = num[i]
        num[i] = num[i+1]
        num[i+1] = temp
        i=0
    else:
        i = i+1
print (num)
