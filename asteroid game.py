a#!/usr/bin/env python
import pyglet
import random

pyglet.resource.path = ["resources"]
pyglet.resource.reindex()

class AsteroidsWindow(pyglet.window.Window):
    def __init__(self):
        super(AsteroidsWindow, self).__init__()

        #Set key handler.
        self.keys = pyglet.window.key.KeyStateHandler()
        self.push_handlers(self.keys)

        self.set_caption("Asteroid Racer")

        self.ship_image = pyglet.resource.image("alienblaster.png")
        self.asteroid_image = pyglet.resource.image("asteroid.png")
        
        self.center_image(self.ship_image)
        self.center_image(self.asteroid_image)
        
        self.explosion_sound = pyglet.resource.media("bigbomb.wav", streaming=False)
        self.background_music = pyglet.resource.media("cyber-soldier.wav", streaming=False)

        self.ship = pyglet.sprite.Sprite(img=self.ship_image, x=30, y=30)
        self.ship.scale = 0.3
        self.ship.rotation = 180

        self.score_label = pyglet.text.Label(text="Score:0 Highscore:0", x=10, y=10)
        self.score = 0
        self.highscore = 0

        self.asteroids = []
        self.stars = []

        pyglet.clock.schedule_interval(self.game_tick, 0.005)
        self.background_music.play()
        pyglet.clock.schedule_interval(lambda x: self.background_music.play(), 13.8)

    def game_tick(self, dt):
        self.update_stars()
        self.update_asteroids()
        self.update_ship()
        self.update_score()
        self.draw_elements()

    def draw_elements(self):
        self.clear()
        for star in self.stars:
            star.draw()
        for asteroid in self.asteroids:
            asteroid.draw()
        self.ship.draw()
        self.score_label.draw()

    def update_stars(self):
        if self.score % 8 == 0:
            self.stars.append(pyglet.text.Label(text="*", x=random.randint(0, 800), y=600))
        for star in self.stars:
            star.y -= 20
            if star.y < 0:
                self.stars.remove(star)

    def update_asteroids(self):
        if random.randint(0, 45) == 3:
            ast = pyglet.sprite.Sprite(img=self.asteroid_image, x=random.randint(0, 800), y=600)
            ast.scale = 0.3
            self.asteroids.append(ast)
        for asteroid in self.asteroids:
            asteroid.y -= 7
            if asteroid.y < 0:
                self.asteroids.remove(asteroid)
        for asteroid in self.asteroids:
            if self.sprites_collide(asteroid, self.ship):
                self.asteroids.remove(asteroid)
                self.score = 0
                self.explosion_sound.play()

    def update_ship(self):
        if self.keys[pyglet.window.key.LEFT] and not self.ship.x < 0:
            self.ship.x -= 4
        elif self.keys[pyglet.window.key.RIGHT] and not self.ship.x > 625:
            self.ship.x += 4
#brought to you by code-projects.org
    def update_score(self):
        self.score += 1
        if self.score > self.highscore:
            self.highscore = self.score
        self.score_label.text = "Score: %s Highscore: %s" % (self.score, self.highscore)
    
    def center_image(self, image):
        image.anchor_x = image.width/2
        image.anchor_y = image.height/2

    def sprites_collide(self, spr1, spr2):
        return (spr1.x-spr2.x)**2 + (spr1.y-spr2.y)**2 < (spr1.width/2 + spr2.width/2)**2

game_window = AsteroidsWindow()
pyglet.app.run()
