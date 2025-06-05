import pygame
import random
import os

pygame.mixer.init()
pygame.init()

# colors
# RGB-red,green,blue
# 255 is value of RGB
green=(0,255,0)
red=(255,0,0)
black=(0,0,0)
# blue=(0,0,255)
white=(255,255,255)
yellow=(255,0,255)


# for creating game window
screen_Width=800
screen_height=500
gamewindow = pygame.display.set_mode((screen_Width, screen_height))
pygame.display.set_caption("MY GAME")
pygame.display.update()

# background pic
back_img=pygame.image.load("bggame.png")
back_img=pygame.transform.scale(back_img,(screen_Width,screen_height)).convert_alpha()

# game starting pic
game_start=pygame.image.load("gamestart.png")
game_start=pygame.transform.scale(game_start,(screen_Width,screen_height)).convert_alpha()

# game over pic
game_over=pygame.image.load("gameover.png")
game_over=pygame.transform.scale(game_over,(screen_Width,screen_height)).convert_alpha()
clock=pygame.time.Clock()
font=pygame.font.SysFont(None,55)

def screen_score(text, color, x, y):
    screen_text=font.render(text, True, color)
    gamewindow.blit(screen_text, [x, y])

def plot_snake(gamewindow, color, snk_list, snake_size):
    for x,y in snk_list:
        pygame.draw.rect(gamewindow,color,[x,y,snake_size,snake_size])

def welcome():
    exit_game=False
    while not exit_game:
        gamewindow.fill(black)
        gamewindow.blit(game_start,(0,0))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit_game=True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    pygame.mixer.music.load("backmusic.mp3")
                    pygame.mixer.music.play()

                    gameloop()

        pygame.display.update()
        clock.tick(60)

# game loop
def gameloop():
    # game specific variables
    exit_game = False
    over_game = False
    snake_x = 40
    snake_y = 50
    snake_size = 30
    velocity_x = 0
    velocity_y = 0
    food_x = random.randint(20, screen_Width / 2)
    food_y = random.randint(20, screen_height / 2)
    fps = 50
    score = 0
    snk_list = []
    snk_length = 1

    # check if highscore file is exists
    if (not os.path.exists("highscore.txt")):
        with open("highscore.txt","w")as f:
            f.write("0")

    with open("highscore.txt", "r") as f:
        high_score = f.read()

    while not exit_game:
        if over_game :
            with open("highscore.txt", "w") as f:
                f.write(str(high_score))
            gamewindow.fill(black)
            gamewindow.blit(game_over,(0,0))
            # screen_score("Opps,Game over ! press enter to start again", red, 0, 200)

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    exit_game = True

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RETURN:
                        welcome()
        else:

            for event in pygame.event.get():

                if event.type == pygame.QUIT:
                    exit_game=True
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_RIGHT:
                        velocity_x = 5
                        velocity_y=0

                    if event.key == pygame.K_LEFT:
                        velocity_x = -5
                        velocity_y = 0

                    if event.key == pygame.K_UP:
                        velocity_y = -5
                        velocity_x = 0

                    if event.key == pygame.K_DOWN:
                        velocity_y = 5
                        velocity_x = 0

                    if event.key == pygame.K_q:
                        score += 10


            snake_x = snake_x+velocity_x
            snake_y = snake_y+velocity_y

    # score
            if abs(snake_x-food_x)<6 and abs(snake_y-food_y)<6:
               score += 10
               # print("score:",score*10)
               food_x = random.randint(20, screen_Width / 2)
               food_y = random.randint(20, screen_height / 2)
               snk_length += 3
               print(high_score)

            # fill colour in window
            gamewindow.fill(green)
            gamewindow.blit(back_img,(0,0))
            screen_score("score:" + str(score) + " High score:"+ str(high_score), black, 2, 2)

            # creating head of snake
            head=[]
            head.append(snake_x)
            head.append(snake_y)
            snk_list.append(head)

            if score > int(high_score):
                high_score=score

            if len(snk_list)>snk_length:
                del snk_list[0]

            if head in snk_list[:-1]:
                over_game=True
                pygame.mixer.music.load("gameovermusic.mp3")
                pygame.mixer.music.play()

            if snake_x<0 or snake_x>screen_Width or snake_y<0 or snake_y>screen_height:
                over_game=True
                print("game over")
                pygame.mixer.music.load("gameovermusic.mp3")
                pygame.mixer.music.play()
            # pygame.draw.rect(gamewindow,black,[snake_x,snake_y,snake_size,snake_size])
            plot_snake(gamewindow,random.randint(000,233),snk_list,snake_size)
            # creating food for snake
            pygame.draw.rect(gamewindow,red,[food_x,food_y,snake_size,snake_size])
        pygame.display.update()
        clock.tick(fps)

    pygame.quit()
    quit()

welcome()

gameloop()

input()




