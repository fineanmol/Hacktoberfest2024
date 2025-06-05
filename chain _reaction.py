import pygame
import sys
from math import *

# Initialization of Pygame
pygame.init()

width = 400
height = 400
display = pygame.display.set_mode((width, height))
clock = pygame.time.Clock()

# Colors
wheat=(245,222,179)

white = (255, 255, 255)
black = (0, 0, 0)
blue = (0,0,255)

red = (200, 0, 0)
light_red = (255, 0, 0)

yellow = (200, 200, 0)
light_yellow = (255, 255, 0)

green = (34, 177, 76)
light_green = (0, 255, 0)

magenta = (255, 0, 255)
purple = (221,160,221)
pink = (242,172,185)
background = (21, 67, 96)
border = (208, 211, 212)
red = (231, 76, 60)
white = (244, 246, 247)
violet = (136, 78, 160)
yellow = (244, 208, 63)
green = (88, 214, 141)


playerColor = [red, green, violet, yellow]

font = pygame.font.SysFont("Times New Roman", 30)
smallfont = pygame.font.SysFont("comicsansms", 25)
medfont = pygame.font.SysFont("comicsansms", 50)
largefont = pygame.font.SysFont("Yu Mincho Demibold", 85)
vsmallfont = pygame.font.SysFont("Yu Mincho Demibold", 25)

def message_to_screen(msg, color, y_displace=0, size="small"):
    textSurf, textRect = text_objects(msg, color, size)
    textRect.center = (int(width / 2), int(height / 2) + y_displace)
    display.blit(textSurf, textRect)

def text_objects(text, color, size="small"):
    if size == "small":
        textSurface = smallfont.render(text, True, color)
    if size == "medium":
        textSurface = medfont.render(text, True, color)
    if size == "large":
        textSurface = largefont.render(text, True, color)
    if size == "vsmall":
        textSurface = vsmallfont.render(text, True, color)

    return textSurface, textSurface.get_rect()

def button(text, x, y, width, height, inactive_color, active_color, action=None,size=" "):
    cur = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()
    # print(click)
    if x + width > cur[0] > x and y + height > cur[1] > y:
        pygame.draw.rect(display, active_color, (x, y, width, height))
        if click[0] == 1 and action != None:
            if action == "quit":
                pygame.quit()
                quit()


            if action == "play":
                gameLoop()

            if action == "main":
                game_intro()

    else:
        pygame.draw.rect(display, inactive_color, (x, y, width, height))

    text_to_button(text, black, x, y, width, height)


def text_to_button(msg, color, buttonx, buttony, buttonwidth, buttonheight, size="vsmall"):
    textSurf, textRect = text_objects(msg, color, size)
    textRect.center = ((buttonx + (buttonwidth / 2)), buttony + (buttonheight / 2))
    display.blit(textSurf, textRect)

def game_intro():
    intro = True

    while intro:
        for event in pygame.event.get():
            # print(event)
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_c:
                    intro = False
                elif event.key == pygame.K_q:

                    pygame.quit()
                    quit()

        display.fill(black)
        message_to_screen("Welcome to Chain Reaction!", white, -100, size="small")
        
        button("Play", width/5, height/2, 100, 50, wheat, light_green, action="play",size="vsmall")
        button("Quit", 3*width/5, height/2, 100, 50, wheat, light_red, action="quit",size="vsmall")

        pygame.display.update()

        clock.tick(15)


blocks = 40
noPlayers = 2

pygame.display.set_caption("Chain Reaction")

score = []
for i in range(noPlayers):
    score.append(0)

players = []
for i in range(noPlayers):
    players.append(playerColor[i])

d = blocks//2 - 2

cols = int(width//blocks)
rows = int(height//blocks)

grid = []

# Quit or Close the Game Window
def close():
    pygame.quit()
    sys.exit()

# Class for Each Spot in Grid
class Spot():
    def __init__(self):
        self.color = border
        self.neighbors = []
        self.noAtoms = 0

    def addNeighbors(self, i, j):
        if i > 0:
            self.neighbors.append(grid[i - 1][j])
        if i < rows - 1:
            self.neighbors.append(grid[i + 1][j])
        if j < cols - 1:
            self.neighbors.append(grid[i][j + 1])
        if j > 0:
            self.neighbors.append(grid[i][j - 1])

# Initializing the Grid with "Empty or 0"
def initializeGrid():
    global grid, score, players
    score = []
    for i in range(noPlayers):
        score.append(0)

    players = []
    for i in range(noPlayers):
        players.append(playerColor[i])

    grid = [[]for _ in range(cols)]
    for i in range(cols):
        for j in range(rows):
            newObj = Spot()
            grid[i].append(newObj)
    for i in range(cols):
        for j in range(rows):
            grid[i][j].addNeighbors(i, j)

# Draw the Grid in Pygame Window   
def drawGrid(currentIndex):
    r = 0
    c = 0
    for i in range(width//blocks):
        r += blocks
        c += blocks
        pygame.draw.line(display, players[currentIndex], (c, 0), (c, height))
        pygame.draw.line(display, players[currentIndex], (0, r), (width, r))

# Draw the Present Situation of Grid
def showPresentGrid(vibrate = 1):
    r = -blocks
    c = -blocks
    padding = 2
    for i in range(cols):
        r += blocks
        c = -blocks 
        for j in range(rows):
            c += blocks
            if grid[i][j].noAtoms == 0:
                grid[i][j].color = border
            elif grid[i][j].noAtoms == 1:
                pygame.draw.ellipse(display, grid[i][j].color, (r + blocks/2 - d/2 + vibrate, c + blocks/2 - d/2, d, d))
            elif grid[i][j].noAtoms == 2:
                pygame.draw.ellipse(display, grid[i][j].color, (r + 5, c + blocks/2 - d/2 - vibrate, d, d))
                pygame.draw.ellipse(display, grid[i][j].color, (r + d/2 + blocks/2 - d/2 + vibrate, c + blocks/2 - d/2, d, d))
            elif grid[i][j].noAtoms == 3:
                angle = 90
                x = r + (d/2)*cos(radians(angle)) + blocks/2 - d/2
                y = c + (d/2)*sin(radians(angle)) + blocks/2 - d/2
                pygame.draw.ellipse(display, grid[i][j].color, (x - vibrate, y, d, d))
                x = r + (d/2)*cos(radians(angle + 90)) + blocks/2 - d/2
                y = c + (d/2)*sin(radians(angle + 90)) + 5
                pygame.draw.ellipse(display, grid[i][j].color, (x + vibrate, y, d, d))
                x = r + (d/2)*cos(radians(angle - 90)) + blocks/2 - d/2
                y = c + (d/2)*sin(radians(angle - 90)) + 5
                pygame.draw.ellipse(display, grid[i][j].color, (x - vibrate, y, d, d))

    pygame.display.update()

# Increase the Atom when Clicked
def addAtom(i, j, color):
    grid[i][j].noAtoms += 1
    grid[i][j].color = color
    if grid[i][j].noAtoms >= len(grid[i][j].neighbors):
        overFlow(grid[i][j], color)
    
# Split the Atom when it Increases the "LIMIT"
def overFlow(cell, color):
    showPresentGrid()
    cell.noAtoms = 0
    for m in range(len(cell.neighbors)):
        cell.neighbors[m].noAtoms += 1
        cell.neighbors[m].color = color
        if cell.neighbors[m].noAtoms >= len(cell.neighbors[m].neighbors):
            overFlow(cell.neighbors[m], color)

# Checking if Any Player has WON!
def isPlayerInGame():
    global score
    playerScore = []
    for i in range(noPlayers):
        playerScore.append(0)
    for i in range(cols):
        for j in range(rows):
            for k in range(noPlayers):
                if grid[i][j].color == players[k]:
                    playerScore[k] += grid[i][j].noAtoms
    score = playerScore[:]

# GAME OVER
def gameOver(playerIndex):
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                close()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    close()
                if event.key == pygame.K_r:
                    gameLoop()

        text = font.render("Player %d Won!" % (playerIndex + 1), True, white)
        text2 = font.render("Press \'r\' to Reset!", True, white)

        display.blit(text, (width/3, height/3))
        display.blit(text2, (width/3, height/2 ))

        pygame.display.update()
        clock.tick(60)


def checkWon():
    num = 0
    for i in range(noPlayers):
        if score[i] == 0:
            num += 1
    if num == noPlayers - 1:
        for i in range(noPlayers):
            if score[i]:
                return i

    return 9999

# Main Loop
def gameLoop():
    initializeGrid()
    loop = True

    turns = 0
    
    currentPlayer = 0

    vibrate = .5

    while loop:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                close()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    close()
            if event.type == pygame.MOUSEBUTTONDOWN:
                x, y = pygame.mouse.get_pos()
                i = int(x/blocks)
                j = int(y/blocks)
                if grid[i][j].color == players[currentPlayer] or grid[i][j].color == border:
                    turns += 1
                    addAtom(i, j, players[currentPlayer])
                    currentPlayer += 1
                    if currentPlayer >= noPlayers:
                        currentPlayer = 0
                if turns >= noPlayers:
                    isPlayerInGame()
                
        
        display.fill(background)
        # Vibrate the Atoms in their Cells
        vibrate *= -1
        
        drawGrid(currentPlayer)
        showPresentGrid(vibrate)
        
        pygame.display.update()

        res = checkWon()
        if res < 9999:
            gameOver(res)

        clock.tick(20)
game_intro()
gameLoop()
