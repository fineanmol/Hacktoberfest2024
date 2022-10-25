num1 = int(input())
num2 = int(input())
num3 = int(input())

def resultado100(num1, num2, num3):
  soma = num1 + num2 + num3
  if(soma == 100):
    return print("*")
  else:
    return print(soma)

if(num1 < 0):
  print("0")
elif(num2 < 0):
  resultado100(num1,0,0)
elif(num3 < 0):
  resultado100(num1,num2,0)
else:
  resultado100(num1,num2,num3)
  