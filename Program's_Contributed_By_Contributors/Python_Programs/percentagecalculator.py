import time

num1 = int(input('What is the number that you want to find a percentage of? '))

time.sleep(.35)

num2 = int(input('What is the percentage you would like to find of that number? '))

def findpercent():
    time.sleep(.35)
    result = num1 / num2 * 100
    print(+ result + ' is ' + num2 + ' percent of ' + num1)
    time.sleep(.35)
    print('program shutdown in 15 seconds')
    time.sleep(15)

findpercent()
