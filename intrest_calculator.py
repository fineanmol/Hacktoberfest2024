# This is the code to calculate intrest in python either it is Simple Intrest or Compound Intrest 
# and print the result in output

principleAmount = int(input("Enter the principle money: "))
rate = int(input("Enter the rate of intrest: "))
time = int(input("Enter the time in years: "))
r = rate/100
ti = time + 2
t = time+1
si = principleAmount*r
amount = principleAmount+si
while(True):

    t = t-1
    if(t==1):
        print("Total Amount after intrest:-",amount)
        break
    if(t>1):
        amount = amount + amount*r
        print("your principle money",principleAmount," after",ti-t,"years:", amount)
        continue

print("total intrest = ", amount-principleAmount)

# GitHub Account "https://github.com/the-sleepingfox"