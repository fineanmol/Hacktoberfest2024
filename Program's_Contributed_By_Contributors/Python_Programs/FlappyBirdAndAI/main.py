import pygame.display
from sys import exit
from settings import *
from game import *
from random import randint
import neat
import pickle
class Main:
    """
    This class will be used to run the event loop
    """
    def __init__(self):

        pygame.init()

        #player type either ai or player
        self.player_type = 'player'

        self.screen = pygame.display.set_mode((WIDTH, HEIGHT))
        # active state
        self.game_state = 0
        # importing background for day and night
        background_day = pygame.image.load('assets/sprites/background-day.png').convert()
        background_night = pygame.image.load('assets/sprites/background-night.png').convert()
        self.background_frames = [background_day,background_night]
        self.background_index = 0
        # scaling the background to the size of window
        self.background = pygame.transform.smoothscale(self.background_frames[self.background_index], (WIDTH,HEIGHT))

        self.start_time = pygame.time.get_ticks()
        self.elapsed_time = 0

        # text
        self.font = pygame.font.Font('assets/fonts/flappy-font.ttf',80)

        #ground
        ground = pygame.image.load('assets/sprites/base.png').convert()

        self.ground = pygame.transform.smoothscale(ground, (WIDTH,ground.get_height()))
        self.ground_rect = self.ground.get_rect(topleft=(0, GROUND_POSITION_Y))
        self.ground_repeat = pygame.transform.smoothscale(ground, (WIDTH, ground.get_height()))
        self.ground_repeat_rect = self.ground_repeat.get_rect(topleft=(-WIDTH, GROUND_POSITION_Y))

        # title of game
        pygame.display.set_caption("Flappy Bird")
        # icon for game
        icon = pygame.image.load('assets/sprites/yellowbird-midflap.png').convert_alpha()
        pygame.display.set_icon(icon)
        # screen to render the game

        #bird
        self.player = pygame.sprite.GroupSingle()
        self.player.add(Bird())

        # obstacles
        self.obstacles = pygame.sprite.Group()


        # buttons
        self.human_button = Button(type='player', pos=(WIDTH // 2, HEIGHT // 2 + 200))
        self.ai_button = Button(type='ai', pos=(WIDTH // 2, self.human_button.rect[1] + 100))

        self.clock = pygame.time.Clock()



        # timer for obstacle
        self.obstacle_timer = pygame.USEREVENT + 1
        pygame.time.set_timer(self.obstacle_timer, 2500)


    def render_score(self, pos):
        font = pygame.font.Font('assets/fonts/flappy-font.ttf', 80)
        font_2 =  pygame.font.Font('assets/fonts/flappy-font.ttf', 90)
        score_message_border = font_2.render(f'{self.player.sprite.score}', False, 'black')
        score_message_border_rect = score_message_border.get_rect(center=pos)

        self.screen.blit(score_message_border, score_message_border_rect)
        score_message = font.render(f'{self.player.sprite.score}', False, 'white')
        score_message_rect = score_message.get_rect(center=pos)
        self.screen.blit(score_message, score_message_rect)
        # border

    def collision(self):
        if pygame.sprite.spritecollide(self.player.sprite, self.obstacles, False) or self.player.sprite.rect.bottom >= GROUND_POSITION_Y or self.player.sprite.rect.top <= -5:
            # game over state
            self.game_state = 2

    def step(self):
        """
        Render single frame
        """
        # set the background

        self.screen.blit(self.background, (0, 0))

        # render the obstacles
        self.obstacles.draw(self.screen)

        # set the ground
        self.screen.blit(self.ground, self.ground_rect)
        self.screen.blit(self.ground_repeat, self.ground_repeat_rect)

        if self.game_state == 0:

            initial_screen = pygame.image.load('assets/sprites/message_2.png').convert_alpha()
            initial_screen = pygame.transform.smoothscale(initial_screen, (WIDTH - 200, HEIGHT - 200))
            initial_screen_rect = initial_screen.get_rect(center=(WIDTH // 2, HEIGHT // 2))


            # displaying buttons
            self.screen.blit(initial_screen, initial_screen_rect)
            self.screen.blit(self.human_button.image, self.human_button.rect)
            self.screen.blit(self.ai_button.image, self.ai_button.rect)


        # update logics when game state is active
        elif self.game_state == 1:

            self.obstacles.update()

            # checking if the ground went out of screen and re-rendering based on it
            if self.ground_rect.right < 2:
                self.ground_rect.left = WIDTH
            if self.ground_repeat_rect.right < 2:
                self.ground_repeat_rect.left = WIDTH

            self.ground_rect.x -= 2
            self.ground_repeat_rect.x -= 2

            # check collision
            self.collision()

            # score points
            if self.game_state == 1:
                self.player.sprite.score_point(self.obstacles)

            # render score
            self.render_score((WIDTH // 2, 100))

            # render the player/bird
            self.player.draw(self.screen)
            # update the player
            self.player.update()
        else:
            # render the player/bird
            self.player.draw(self.screen)
            self.render_score((WIDTH // 2, HEIGHT // 2 - 100))
            game_over = pygame.transform.rotozoom(pygame.image.load('assets/sprites/gameover.png').convert_alpha(), 0,
                                                  2)
            game_over_rect = game_over.get_rect(center=((WIDTH // 2, HEIGHT // 2)))
            self.screen.blit(game_over, game_over_rect)
            font = pygame.font.Font('assets/fonts/flappy-font.ttf', 30)
            restart_message = font.render('Press space or click to restart', False, 'black')
            restart_rect = restart_message.get_rect(center=(WIDTH // 2, HEIGHT // 2 + 100))
            self.screen.blit(restart_message,restart_rect)
    def get_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit()

            # spawn obstacle
            if self.game_state == 0:
                if event.type == pygame.MOUSEBUTTONDOWN:
                    # get mouse position
                    mouse_pos = pygame.mouse.get_pos()
                    # checking button collision
                    if self.human_button.rect.collidepoint(mouse_pos):
                        self.player_type = 'player'
                        self.game_state = 1
                    if self.ai_button.rect.collidepoint(mouse_pos):
                        self.player_type = 'ai'
                        self.game_state = 1


            elif self.game_state == 1:
                if event.type == self.obstacle_timer:
                    bottom_center_position = randint(500, HEIGHT)
                    self.obstacles.add(Pipe('bottom', bottom_center_position))
                    top_center_position = bottom_center_position - 800
                    self.obstacles.add(Pipe('top', top_center_position))
            else:
                if (event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE) or event.type == pygame.MOUSEBUTTONDOWN:
                    # setting the player type
                    self.player_type = 'player'
                    self.game_state = 0
                    self.obstacles.empty()
                    self.player.sprite.reset()

    def run(self):

        """
        Event loop will be initiated here
        """
        # loading the best model and setting the nerural net
        genome, config = self.load_saved_model('best_ai.pkl')
        net = neat.nn.FeedForwardNetwork.create(genome, config)
        while(True):

            self.get_events()

            self.step()

            #update the screen
            pygame.display.update()
            self.clock.tick(60)

            if self.player_type == 'ai':
                # Get the game states and use the neural network to decide the action
                game_states = self.get_game_states()
                # print(game_states)
                output = net.activate(game_states)


                # Decide action based on the output of the neural network
                # This part will depend on how you've structured the output of your network

                action = self.neat_decide_action_based_on_output(output)
                self.neat_perform_action(action)


    # methods for training neaat algorithm
    def get_game_states(self):
        """
        Method to get game states each frame
        """
        bird_y = self.player.sprite.rect.centery
        distance_to_obstacle = 0
        pipe_y = 0

        if len(self.obstacles) == 0:
            distance_to_obstacle = WIDTH // 2
            pipe_y = HEIGHT //2
            # print('hello')

        for obstacle in self.obstacles:
            if not obstacle.scored and (obstacle.type=='bottom'):
                pipe_y = obstacle.rect.top
                distance_to_obstacle = obstacle.rect.left - self.player.sprite.rect.right
                break
        return bird_y, distance_to_obstacle, pipe_y
    def evaluate_fitness(self):
        """
        Method to calculate fitness for neat algorithm
        """
        fitness = 0
        if self.player.sprite.score>0:
            fitness = self.player.sprite.score*10
        if self.game_state==2:
            fitness -= 1
        fitness = fitness + self.elapsed_time / 1000 * 2
        return fitness

    def neat_decide_action_based_on_output(self, output):
        """
        Method to let AI make move either jump or do_nothing
        """
        if output[0] > 0.8:
            return 'jump'
        else:
            return 'do_nothing'

    def neat_perform_action(self, action):
        """
        Method to perform action based on neat decision
        """
        if action == 'jump':
            self.player.sprite.gravity = - BIRD_JUMP_GRAVITY

    def train_ai(self):
        """
        Method to train ai using neat algorithm
        """

        # neat config
        config = neat.Config(neat.DefaultGenome, neat.DefaultReproduction,
                             neat.DefaultSpeciesSet, neat.DefaultStagnation,
                             'config-feedforward.txt')

        # Create the population
        population = neat.Population(config)

        # Add reporters if you want statistics
        population.add_reporter(neat.StdOutReporter(True))
        stats = neat.StatisticsReporter()
        population.add_reporter(stats)

        # define fitness function
        def eval_genomes(genomes, config):
            max_score = 0
            for genome_id, genome in genomes:
                genome.fitness = 0  # Start with fitness level of 0
                net = neat.nn.FeedForwardNetwork.create(genome, config)

                self.game_state = 1

                """
                Event loop will be initiated here
                """
                while(True):

                    # get events like mouse click, keyboard events
                    self.get_events()

                    self.step()


                    #update the screen
                    pygame.display.update()
                    self.clock.tick(60)

                    # Get the game states and use the neural network to decide the action
                    game_states = self.get_game_states()
                    output = net.activate(game_states)


                    # Decide action based on the output of the neural network

                    action = self.neat_decide_action_based_on_output(output)
                    self.neat_perform_action(action)

                    # If the game ends or you want to evaluate the fitness at this point, break
                    if self.game_state == 2 or self.player.sprite.score >= 150:
                        # Assign fitness based on some evaluation criteria
                        self.elapsed_time = pygame.time.get_ticks() - self.start_time
                        genome.fitness += self.evaluate_fitness()
                        print(f'Game Over!: Elapsed Time {self.elapsed_time/1000} seconds')
                        if self.player.sprite.score > max_score:
                            max_score = self.player.sprite.score
                        self.game_state = 1
                        self.obstacles.empty()
                        self.player.sprite.reset()
                        self.start_time = pygame.time.get_ticks()
                        self.elapsed_time = 0
                        break

            print(f'Max Score Achieved: {max_score}')

        winner = population.run(eval_genomes,50)

        # saving the best model
        with open('best_ai.pkl', 'wb') as output:
            pickle.dump(winner, output, 1)

    def load_saved_model(self,model_name):
        "load the saved model"
        with open(model_name, 'rb') as input_file:
            genome = pickle.load(input_file)
        # neat config
        config = neat.Config(neat.DefaultGenome, neat.DefaultReproduction,
                             neat.DefaultSpeciesSet, neat.DefaultStagnation,
                             'config-feedforward.txt')
        return genome, config

if __name__ =="__main__":
    main = Main()
    # main.train_ai()
    main.run()