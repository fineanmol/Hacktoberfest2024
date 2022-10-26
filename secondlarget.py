nums=[]
b=int(input("Total Numbers You Want To Enter : "))
for x in range(0,b):
    en=input()
    nums.append(en)
print(nums)
nums.sort()
final=set(nums)
highest=max(nums)
final.remove(highest)
print("Second Largest Number Is : ",max(final))
