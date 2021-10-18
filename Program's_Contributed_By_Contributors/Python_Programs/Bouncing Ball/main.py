#python program simulate bouncing ball in Pygame
#Pygame is a cross-platform set of Python modules consists of computer graphics and sound libraries designed to be used with the Python programming language.
import sys, pygame
pygame.init()
size = width, height = 800, 400
speed = [1, 1]
background = 255, 255, 255
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Bouncing ball")
ball = pygame.image.load("ball.png")
ballrect = ball.get_rect()
while 1:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()
	ballrect = ballrect.move(speed)
	if ballrect.left < 0 or ballrect.right > width:
		speed[0] = -speed[0]
	if ballrect.top < 0 or ballrect.bottom > height:
		speed[1] = -speed[1]
	screen.fill(background)
	screen.blit(ball, ballrect)
	pygame.display.flip()