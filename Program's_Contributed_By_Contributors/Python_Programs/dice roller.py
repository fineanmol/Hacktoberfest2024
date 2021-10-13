import random
while True:
 start=input('Type ROLL to start rolling the dice:')
 if start=='ROLL':
      print('Rolling dice..')
      print(f"The value is ", random.randint(1,6))

 again=input("to close the program type CLOSE and to continue the program press anything:")
 if again =='CLOSE':
     break
