class Fruit:
    x = 0
    y = 0
    step = 44

    def __init__(self, x, y):
        self.x = x * self.step
        self.y = y * self.step

    def draw(self, surface, image):
        surface.blit(image, (self.x, self.y))

#defining class for player
class Player:
    x = [0]
    y = [0]
    step = 44
    direction = 0
    length = 3

    updateCountMax = 2
    updateCount = 0
    #constructor
    def __init__(self, length):
        self.length = length
        for i in range(0, 2000):
            self.x.append(-100)
            self.y.append(-100)

        # initial positions, no collision.
        self.x[1] = 1 * 44
        self.x[2] = 2 * 44

    def update(self):

        self.updateCount = self.updateCount + 1
        if self.updateCount > self.updateCountMax:

            # update previous positions
            for i in range(self.length - 1, 0, -1):
                self.x[i] = self.x[i - 1]
                self.y[i] = self.y[i - 1]

            # update position of head of snake
            if self.direction == 0:
                self.x[0] = self.x[0] + self.step
            if self.direction == 1:
                self.x[0] = self.x[0] - self.step
            if self.direction == 2:
                self.y[0] = self.y[0] - self.step
            if self.direction == 3:
                self.y[0] = self.y[0] + self.step

            self.updateCount = 0

    def moveRight(self):
        self.direction = 0

    def moveLeft(self):
        self.direction = 1

    def moveUp(self):
        self.direction = 2

    def moveDown(self):
        self.direction = 3

    def draw(self, surface, image):
        for i in range(0, self.length):
            surface.blit(image, (self.x[i], self.y[i]))

#defining class for game
class Game:
    def isCollision(self, x1, y1, x2, y2, bsize):
        if x1 >= x2 and x1 <= x2 + bsize:
            if y1 >= y2 and y1 <= y2 + bsize:
                return True
        return False


class Application:
    winWidth = 700
    winHeight = 700
    player = 0
    fruit = 0

    def __init__(self):
        self._running = True
        self.displaySurface = None
        self.imgSurface = None
        self.fruitSurface = None
        self.game = Game()
        self.player = Player(1)
        self.fruit = Fruit(5, 5)

    def on_init(self):
        pygame.init()
        self.displaySurface = pygame.display.set_mode((self.winWidth, self.winHeight), pygame.HWSURFACE)

        pygame.display.set_caption('KrazyProgrammer')
        self._running = True
        #set an image  of size 30x30 for snake
        self.imgSurface = pygame.image.load("snake.png").convert()
        # set an image  of size 30x30 for fruit
        self.fruitSurface = pygame.image.load("fruit.png").convert()

    def on_event(self, event):
        if event.type == QUIT:
            self._running = False

    def on_loop(self):
        self.player.update()

        # does snake eat fruit?
        for i in range(0, self.player.length):
            if self.game.isCollision(self.fruit.x, self.fruit.y, self.player.x[i], self.player.y[i], 44):
                self.fruit.x = randint(2, 9) * 44
                self.fruit.y = randint(2, 9) * 44
                self.player.length = self.player.length + 1

        # does snake collide with itself?
        for i in range(2, self.player.length):
            if self.game.isCollision(self.player.x[0], self.player.y[0], self.player.x[i], self.player.y[i], 40):
                print("Snake Collision: ")
                exit(0)

        pass

    def on_render(self):
        #set background color
        self.displaySurface.fill((0,0,0))
        self.player.draw(self.displaySurface, self.imgSurface)
        self.fruit.draw(self.displaySurface, self.fruitSurface)
        pygame.display.flip()

    def on_cleanup(self):
        pygame.quit()

    def on_execute(self):
        if self.on_init() == False:
            self._running = False

        while (self._running):
            pygame.event.pump()
            keys = pygame.key.get_pressed()

            if (keys[K_RIGHT]):
                self.player.moveRight()

            if (keys[K_LEFT]):
                self.player.moveLeft()

            if (keys[K_UP]):
                self.player.moveUp()

            if (keys[K_DOWN]):
                self.player.moveDown()
            #press esc button to terminate the application
            if (keys[K_ESCAPE]):
                self._running = False
            self.on_loop()
            self.on_render()
            time.sleep(50.0 / 1000.0);
        self.on_cleanup()

#running application
if __name__ == "__main__":
    objApp = Application()
    objApp.on_execute()
