import pygame.sprite

from settings import *

class Bird(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        bird_1 = pygame.transform.rotozoom(pygame.image.load('assets/sprites/yellowbird-midflap.png').convert_alpha(), 0, 1.5)
        bird_2 = pygame.transform.rotozoom(pygame.image.load('assets/sprites/yellowbird-upflap.png').convert_alpha(), 0, 1.5)
        bird_3 = pygame.transform.rotozoom(pygame.image.load('assets/sprites/yellowbird-downflap.png').convert_alpha(), 0, 1.5)

        self.score_sound = pygame.mixer.Sound('assets/audio/point.wav')
        self.score_sound.set_volume(0.3)
        self.bird_frames = [bird_1, bird_2, bird_3]
        self.bird_frame_index = 0
        self.image = self.bird_frames[self.bird_frame_index]
        self.rect = self.image.get_rect(midbottom=(WIDTH//2-40, HEIGHT//2))
        self.gravity = 0
        self.score = 0
    def animate_state(self):
        if self.rect.bottom >= GROUND_POSITION_Y:
            self.image = self.bird_frames[0]
            self.image = pygame.transform.rotate(self.image, -45)
        else:
            self.bird_frame_index += 0.1
            if self.bird_frame_index >= len(self.bird_frames): self.bird_frame_index = 0


            self.image = self.bird_frames[int(self.bird_frame_index)]

            if self.gravity < 0:
                self.image = pygame.transform.rotate(self.image , 15)
            elif self.gravity >5 and self.gravity<15:
                self.image = pygame.transform.rotate(self.image, -15)
            elif self.gravity>=15 and self.gravity<=30:
                self.image = pygame.transform.rotate(self.image, -45)


    def apply_gravity(self):
        self.gravity += 1
        if self.rect.bottom >GROUND_POSITION_Y:
            self.gravity = 0
        self.rect.y += self.gravity

        if self.rect.bottom >= GROUND_POSITION_Y:
            self.rect.bottom = GROUND_POSITION_Y

        if self.rect.top <= -50:
            self.rect.top = -50

    def user_input(self):
        keys = pygame.key.get_pressed()
        # Check the state of the mouse buttons
        left_button, middle_button, right_button = pygame.mouse.get_pressed()
        if keys[pygame.K_SPACE] or left_button:
            self.gravity = -BIRD_JUMP_GRAVITY


    def score_point(self, obstacles):
        for obstacle in obstacles:
            if not obstacle.scored and obstacle.type == 'bottom':
                if self.rect.left >= obstacle.rect.right:
                    self.score += 1
                    obstacle.scored = True
                    self.score_sound.play()

    def reset(self):
        self.rect.center = (WIDTH//2-40, HEIGHT//2)
        self.score = 0

    def update(self):
        self.animate_state()
        self.apply_gravity()
        self.user_input()




class Pipe(pygame.sprite.Sprite):
    def __init__(self, type, height):
        super().__init__()
        pipe = pygame.image.load('assets/sprites/pipe-green.png').convert_alpha()
        self.type = type
        self.scored = False
        if self.type == 'bottom':
            self.image = pygame.transform.rotozoom(pipe,0, 2)
            self.rect = self.image.get_rect(center=(WIDTH+100, height))
        else:
            self.image = pygame.transform.rotozoom(pipe, 180, 2)
            self.image = pygame.transform.flip(self.image, True, False)
            self.rect = self.image.get_rect(center=(WIDTH+100, height))

    def destroy(self):
        if self.rect.x <= -100:
            self.kill()


    def update(self):
        self.rect.x -= 2
        self.destroy()



class Button(pygame.sprite.Sprite):
    def __init__(self, type, pos):
        super().__init__()
        if type=='player':
            button_image = pygame.image.load('assets/sprites/human_play.png').convert_alpha()
        else:
            button_image = pygame.image.load('assets/sprites/ai_play.png').convert_alpha()
        self.image = pygame.transform.rotozoom(button_image, 0, 2)
        self.rect = self.image.get_rect(center=pos)

