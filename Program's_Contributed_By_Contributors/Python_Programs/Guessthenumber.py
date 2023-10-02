import random
input('==================PRESS ENTER TO START THE GAME==================',end='\n\n\n\n\n')





print('    |          |||||||||||   |       |  ||||||||  |||||||||       |||||||||   =================')
print('    |          |             |       |  \\         \\             \\                 ===============           ===============')
print('    |          |     /||||   |       |   ||||||     \\              \\                                       ======================')
print('    |          |_____|___|   |      /    //          \\\\            \\\\=      ---KHUSHANK                           ===================')
print('    |          |_________    ||||||/    ||||||||  |||||||||    ||||||||||               ==================================   ', end='\n\n')

points = 0
while True:
	Guess = int(input('Guess a number between 1 and 60 :', end='\r'))
	num = int(random.random()*61)
	points+=abs(Guess - num)
	print(f'Actual number is {num}. You are off by {abs(Guess-num)}\nyour current score is {points}'end='\r')
	ask = input('do you want to play more(y/n): ', end='\r')
	if ask == 'n':break

#HIGH SCORE
HIGH = open("HIGH SCORE.txt")
highscore = HIGH.readlines()
highscore.append('0')
HIGH.close()

highscore = max(int(highscore[0]), points)

HIGH = open("HIGH SCORE.txt", "w")
HIGH.write(highscore)
HIGH.close()
print(f'Your score is: {points}\nHIGH SCORE: {highscore}')
