import pygame
import random

# Initialize Pygame
pygame.init()

# Screen dimensions
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Pong Clone')

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Game variables
ball_speed = [random.choice([-4, 4]), random.choice([-4, 4])]
paddle_speed = 10
player_score = 0
ai_score = 0

# Paddle dimensions
PADDLE_WIDTH, PADDLE_HEIGHT = 10, 100

# Ball dimensions
BALL_RADIUS = 10

# Paddle positions
player_paddle = pygame.Rect(WIDTH - 30, HEIGHT // 2 - PADDLE_HEIGHT // 2, PADDLE_WIDTH, PADDLE_HEIGHT)
ai_paddle = pygame.Rect(20, HEIGHT // 2 - PADDLE_HEIGHT // 2, PADDLE_WIDTH, PADDLE_HEIGHT)

# Ball position
ball = pygame.Rect(WIDTH // 2 - BALL_RADIUS, HEIGHT // 2 - BALL_RADIUS, BALL_RADIUS * 2, BALL_RADIUS * 2)

# Font for displaying the score
font = pygame.font.Font(None, 74)

# Function to reset the ball
def reset_ball():
    ball.center = (WIDTH // 2, HEIGHT // 2)
    ball_speed[0] = random.choice([-4, 4])
    ball_speed[1] = random.choice([-4, 4])

# Main game loop
running = True
while running:
    # Event handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Move player paddle with the mouse
    mouse_y = pygame.mouse.get_pos()[1]
    player_paddle.y = mouse_y - PADDLE_HEIGHT // 2

    # Move AI paddle (basic AI follows the ball)
    if ai_paddle.centery < ball.centery:
        ai_paddle.y += paddle_speed
    elif ai_paddle.centery > ball.centery:
        ai_paddle.y -= paddle_speed

    # Ball movement
    ball.x += ball_speed[0]
    ball.y += ball_speed[1]

    # Collision with top/bottom walls
    if ball.top <= 0 or ball.bottom >= HEIGHT:
        ball_speed[1] = -ball_speed[1]

    # Collision with player paddle
    if ball.colliderect(player_paddle) and ball_speed[0] > 0:
        ball_speed[0] = -ball_speed[0]

    # Collision with AI paddle
    if ball.colliderect(ai_paddle) and ball_speed[0] < 0:
        ball_speed[0] = -ball_speed[0]

    # Scoring
    if ball.left <= 0:
        player_score += 1
        reset_ball()

    if ball.right >= WIDTH:
        ai_score += 1
        reset_ball()

    # Drawing
    screen.fill(BLACK)

    # Draw paddles
    pygame.draw.rect(screen, WHITE, player_paddle)
    pygame.draw.rect(screen, WHITE, ai_paddle)

    # Draw ball
    pygame.draw.ellipse(screen, WHITE, ball)

    # Draw net
    for i in range(0, HEIGHT, 20):
        pygame.draw.line(screen, WHITE, (WIDTH // 2, i), (WIDTH // 2, i + 10))

    # Draw scores
    player_text = font.render(str(player_score), True, WHITE)
    screen.blit(player_text, (WIDTH // 2 + 20, 10))

    ai_text = font.render(str(ai_score), True, WHITE)
    screen.blit(ai_text, (WIDTH // 2 - 60, 10))

    # Update the display
    pygame.display.flip()

    # Cap the frame rate
    pygame.time.Clock().tick(60)

# Quit the game...
pygame.quit()
