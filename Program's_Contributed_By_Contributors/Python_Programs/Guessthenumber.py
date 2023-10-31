import random
input('==================PRESS ENTER TO START THE GAME==================')
print('\n\n\n')


print('    |          |||||||||||   |       |  ||||||||  |||||||||  |||||||||   ===============')
print('    |          |             |       |  \\          \\          \\         ===============')
print('    |          |     /||||   |       |   ||||||     \\\\         \\\\        ===============')
print('    |          |_____|___|   |       |   //           \\\\\\\      \\\\\\\    ===============')
print('    |          |||||||||||    \|||||/   ||||||||  |||||||||  |||||||||   ===============')
print('\n\n')

points = 0
while True:
	Guess = int(input('\rGuess a number between 1 and 60 :'))
	num = int(random.random()*61)
	points+=abs(Guess - num)
	print(f'\rActual number is {num}. You are off by {abs(Guess-num)}\nyour current score is {points}')
	ask = input('\rdo you want to play more(y/n): ')
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
