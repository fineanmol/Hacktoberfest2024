#Check Armstrong number of n digits
number = 1634
order len(str(num))
sum = 0
temp = number
while temp>0:
  digit = temp%10
  sum += digit**order
  temp //= 10
if number == sum:
  print(number,"is  an Armstrong number")
else:
  print(number,"is not an Armstrong number")
