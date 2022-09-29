import random
dataArray= []
for j in range(0,5):
  dataArray.append(random.randint(1,5))
find_num=int(input('Enter the guess number from list range of number 1 to 15 \n'))
print(dataArray)
flag=False
for i in dataArray:
  if(find_num==i):
    flag=True
    break
 
if(flag):
  print(i, " is found  ")
else:
  print('not found')
