import pygame
import random
from pygame import mixer

pygame.init()
screen = pygame.display.set_mode((800, 600))
bg = pygame.image.load('bg.png')

pygame.display.set_caption("Space Invaders")
icon = pygame.image.load('space.png')
pygame.display.set_icon(icon)

score = 0
font = pygame.font.Font('freesansbold.ttf', 32)
scoreX = 15
scoreY = 15

overfont = pygame.font.Font('freesansbold.ttf', 100)

mixer.music.load("background.wav")
mixer.music.play(-1)
# mixer.music.load("explosion.wav")

playimg = pygame.image.load('si.png')
playerX = 368
playerY = 500
c = 0
d = 0

enemyimg = []
enemyX = []
enemyY = []
e = []
numofenemy = 8
for i in range(numofenemy):
    enemyimg.append(pygame.image.load('alien.png'))
    enemyX.append(random.randint(0, 736))
    enemyY.append(random.randint(0, 250))
    e.append(1.2)

bulletimg = pygame.image.load('bullet.png')
bulletX = 0
bulletY = 480
f = 15
bulstate = "ready"


def showscore():
    scoreobj = font.render("Score: " + str(score), True, (255, 255, 255))
    screen.blit(scoreobj, (scoreX, scoreY))


def player():
    screen.blit(playimg, (playerX, playerY))


def enemy():
    for b in range(numofenemy):
        screen.blit(enemyimg[b], (enemyX[b], enemyY[b]))


def bulletfire():
    global bulstate
    bulstate = "fire"
    screen.blit(bulletimg, (bulletX + 16, bulletY + 10))


def gameover():
    overobj = overfont.render("GAME OVER", True, (255, 255, 255))
    screen.blit(overobj, (90, 250))
    restartobj = font.render("Press Enter to Restart", True, (255, 255, 255))
    screen.blit(restartobj, (230, 400))


rn = True
while rn:
    screen.fill((0, 0, 0))
    screen.blit(bg, (0, 0))
    for ev in pygame.event.get():
        if ev.type == pygame.QUIT:
            rn = False
        if ev.type == pygame.KEYDOWN:
            if ev.key == pygame.K_LEFT:
                c = -3
            if ev.key == pygame.K_RIGHT:
                c = 3
            if ev.key == pygame.K_UP:
                d = -3
            if ev.key == pygame.K_DOWN:
                d = 3
            if ev.key == pygame.K_SPACE and bulstate == "ready":
                bulletsound = mixer.Sound('laser.wav')
                bulletsound.play()
                bulletX = playerX
                bulletY = playerY
                bulletfire()
            if ev.key == pygame.K_RETURN and enemyY[0] == 2000:
                score = 0
                enemyY = []
                for i in range(numofenemy):
                    enemyY.append(random.randint(0, 250))

        if ev.type == pygame.KEYUP:
            if ev.key == pygame.K_LEFT or ev.key == pygame.K_RIGHT:
                c = 0
            if ev.key == pygame.K_UP or ev.key == pygame.K_DOWN:
                d = 0
    playerX += c
    if playerX > 736:
        playerX = 736
    elif playerX < 0:
        playerX = 0
    playerY += d
    if playerY > 536:
        playerY = 536
    elif playerY < 0:
        playerY = 0
    player()
    enemy()

    for i in range(numofenemy):
        enemyX[i] += e[i]
        if enemyX[i] > 736 or enemyX[i] < 0:
            e[i] = -e[i]
            enemyY[i] += 40
        if enemyY[i] > 420 or (abs(enemyX[i] - playerX) < 22 and abs(enemyY[i] - playerY) < 22):
            for j in range(numofenemy):
                enemyY[j] = 2000
            gameover()
            break

    if bulstate == "fire":
        bulletY -= f
        bulletfire()

    if bulletY < 0:
        bulstate = "ready"

    for i in range(numofenemy):
        if abs(enemyX[i] - bulletX) < 20 and abs(enemyY[i] - bulletY) < 20:
            scoresound = mixer.Sound('explosion.wav')
            scoresound.play()
            bulstate = "ready"
            score += 1
            enemyX[i] = random.randint(0, 736)
            enemyY[i] = random.randint(0, 350)
    showscore()
    pygame.display.update()
