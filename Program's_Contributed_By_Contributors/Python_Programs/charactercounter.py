import time

word = input('What word or phrase do you want to count? ')
time.sleep(.35)
def result():
    numcount = len(word)
    print('Your word/phrase is ' + numcount + ' characters long.')
    time.sleep(.35)
    print('shutdown in 15 seconds')
    time.sleep(15)

result()
