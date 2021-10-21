# L-system demonstration https://en.wikipedia.org/wiki/L-system
# Drawing Dragon Curve fractal https://en.wikipedia.org/wiki/Dragon_curve
# Code by Jose Vitor Dutra (https://github.com/zedutra)

import turtle as turtle

ruleInput = ['X', 'Y']
ruleOutput = ["X+YF+", "-FX-Y"]
start = "FX"

front = 5
turn = 90
stack = []
dirstack = []

turtle.tracer(0)
turtle.left(90)


def generate(iteration):
	result = start
	temp = ""
	for i in range(iteration):
		for j in range(len(result)):
			for k in range(len(ruleInput)):
				if result[j] == ruleInput[k]:
					temp += ruleOutput[k]
					break
				if k == len(ruleInput)-1:
					temp += result[j]
		result = temp
		temp = ""
	return result


def draw(input):
	for x in input:
		if x == 'F':
			turtle.forward(front)
		elif x == '-':
			turtle.left(turn)
		elif x == '+':
			turtle.right(turn)
	turtle.hideturtle()
	turtle.done()


draw(generate(14))  # number of recursions
