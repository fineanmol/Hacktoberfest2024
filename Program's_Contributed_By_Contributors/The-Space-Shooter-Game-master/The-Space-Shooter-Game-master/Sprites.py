import pygame as pg
from Settings import *
import random
import os



#loads player's images
PLAYER=[PGIMLOAD(path+'player.png'),PGIMLOAD(path+'playerLeft.png'),PGIMLOAD(path+'playerRight.png'),PGIMLOAD(path+'playerDamaged.png')]
#loads images of meteorites and enemy
MOBS=[PGIMLOAD(path+'enemyShip.png'),PGIMLOAD(path+'enemyUFO.png'),PGIMLOAD(path+'meteorBig.png'),PGIMLOAD(path+'meteorSmall.png')]
#loads images for explosion of meteorites and enemies
ExplosionList=[pg.image.load(f'Explosion{os.sep}explosion{int(x)}.png') for x in range(1,15)]
#loads images for explosion of player
SelfExplosionList=[pg.image.load(f'Qexplosion{os.sep}{int(x)}.png') for x in range(1,21)]

class Player(pg.sprite.Sprite):
    """This class extends Sprite class of pygame that is in sprite module of pygame library and overrides update method of Sprite class.
       And adds move method for player's movements."""
    def __init__(self,all_sprites,bullets,shoot_sound,explosion_sound):
        """This method initializes player's initial state. Takes all_sprites and bullets for all_sprite group & bullets group of Game class.
            Takes shoot_sound and explosion_sound for player's shooting sound and Explosion sound rescpectively."""
        pg.sprite.Sprite.__init__(self,all_sprites)#calls super class constructor with groups to be added in those groups
        self.image=PLAYER[0]  #loads player's initial image
        self.all_sprites=all_sprites  #sets all_sprites group to Game class's all_sprites group
        self.bullets=bullets  #sets bullets group to Game class's bullets group
        self.rect=self.image.get_rect() #gets rect from image for player's position
        self.rect.center=(WIDTH/2,HEIGHT-self.rect.height)  #sets initial position of player
        self.isLeft=False #sets player's left state to false
        self.isRight=False  #sets player's right state to false
        self.isDamaged=False #sets player's dammaged state to false
        self.health=100 #sets player's health to 100 units
        self.now=pg.time.get_ticks()  #sets now to current sysytem ticks
        self.damageCount=0  #sets damamgeCount to 0 ,it checks player's damage state
        self.score=0  #sets player's core to zero
        self.lives=0  #sets player's lives to 3
        self.shoot_Sound=shoot_sound  #sets player's hoot sound
        self.explosion_sound=explosion_sound  #sets player's explosion sound
        self.killed=False  #sets player's killed state to false

    def move(self, dx=0):
        """This method is called from Game class's event method to control player's movements."""
        if self.rect.x+dx >= 0 and self.rect.x + dx + self.rect.width <= WIDTH:
              #checks if player is in the visible area and moves player only if it is in visible area
            self.rect.x += dx  #move splayer by dx units
        if dx < 0:  #if player is to move left
            self.isLeft = True  #sets player's left state to true
            self.isRight = False  #sets player's right state to False
        elif dx > 0:  #if player is to move right
            self.isRight = True  #sets player's right state to True
            self.isLeft = False  #sets player's left state to False
        else:  #if player is not moved
            self.isLeft = False  #sets player's left state to False
            self.isRight = False  #sets player's right state to False

    def shoot(self):
        """This method is used to shoot bullets by player."""
        if pg.time.get_ticks()-self.now>300 and not(self.killed):#checks if last bullet has been shot before 300 system ticks
            self.shoot_Sound.play()#plays shooting sound
            self.now=pg.time.get_ticks()#sets now to current system ticks
            Bullet(self.bullets,self.all_sprites,self.rect) #new Bullet is shot (comes on the screen)

    def update(self):
        """This method overrides update method of Sprite class.Sets player's image and checks player's health and life."""
        if self.isLeft:
            self.image=PLAYER[1]#sets player's left image
        elif self.isRight:
            self.image=PLAYER[2]#sets player's right image
        else:
            self.image=PLAYER[0] #sets player's still image

        if self.isDamaged :#checks if player's damamged or not
            self.damageCount+=1 #increases damamgecount
            self.image=PLAYER[3] #sets player's damaged image
            if self.damageCount==15:#if damamge count =15
                self.isDamaged=False#sets player's damaged state to False
                self.damageCount=0 #sets dmamgeCount=0

        if self.health<=0:#if health <=0
            self.explosion_sound.play()#plays explosion sound
            self.lives-=1#reduces life by one
            self.health=100 #sets health to 0
            Explosion(self.all_sprites,self.rect,True) #Explosion comes on the screen
            self.killed=True #sets payer's killed state to True
            self.rect.y=HEIGHT+200 #hides player
            self.now=pg.time.get_ticks()  #gets current sysytem ticks

        if self.killed and pg.time.get_ticks()-self.now>2000:#checks if player's killed
            self.killed=False#sets player's killed state to false
            self.rect.center = (WIDTH / 2, HEIGHT - self.rect.height) #unhides the player

class Bullet(pg.sprite.Sprite):
    """This class inherits Sprite class of pygame and overrides it's update and kill methods."""
    def __init__(self,bullets,all_sprites,rect,dir=1,color='Red'):
        """This method initializes Bullet object.bullets and all_sprites are groups . rect is player's(or enemy's) rect
            for initial position of bullet. dir is for bullet's direction(up/down).color for bullet's color."""
        pg.sprite.Sprite.__init__(self,bullets,all_sprites)#calls super class constructor
        self.image=PGIMLOAD(path+'laser'+color+'.png')#sets bullet's image
        self.rect=self.image.get_rect()  #gets rect from image for position of bullet
        self.rect.center=rect.center  #sets initial position bullet
        self.dir=dir  #sets direction
        self.all_sprites=all_sprites  #sets all_sprite
        self.color=color #sets color

    def update(self):
        """This method overrides Sprite class's update method and sets new position of bullet. """
        self.rect.y-=8*self.dir #moves bullet
        if self.rect.y >HEIGHT or self.rect.y+self.rect.height < 0: #if bullet is out of vivible area kill the bullet
            self.kill()#kill bullet

    def kill(self):
        """This method ovevrrides kill method of Sprite class."""
        super().kill()#calls super class's kill method
        if not(self.rect.y > HEIGHT or self.rect.y + self.rect.height < 0):#if bullet is out of vivible area kill the bullet and hits
            BulletHit(self.all_sprites,self.rect,self.color)  #BulletHit comes on the screen

class BulletHit(pg.sprite.Sprite):
    """This class inherits Sprite class of pygame and overrides it's update method."""
    def __init__(self,all_sprites,rect,color):
        """This method initializes BulletHit object that comes whenever a bullet hits other sprites.
            rect is for it's initial position and all_sprites is group and color is it's color."""
        pg.sprite.Sprite.__init__(self,all_sprites)  #calls super class constructor
        self.image=PGIMLOAD(path+'laser'+color+'Shot.png')  #sets image
        self.rect=self.image.get_rect() #gets rect from image for position
        self.rect.center=(rect.x,rect.y)  #sets initial position
        self.now=pg.time.get_ticks()  #sets now to current system ticks

    def update(self):
        """This method overrides update method of Sprite class."""
        if pg.time.get_ticks()-self.now>300:  #checks if 300 sysytem ticks have been done since it's start
            self.kill()  #kills self



class Mob(pg.sprite.Sprite):
    """This class overrides Sprite class of pygame library and overrides it's update and kill method.
       Mob class is for meteorites."""
    def __init__(self,mobs,meteorites,all_sprites,sound):
        """This method initializes Mob class object.mobs and meteorites and all_sprites are groups.
           sound is for it's explosion sound."""
        pg.sprite.Sprite.__init__(self,mobs,meteorites,all_sprites)  #calls super class constructor
        self.image=MOBS[random.randrange(2,4)]  #sets image of meteorite
        self.rect=self.image.get_rect()  #gets rect from image for position
        self.rect.x=random.randrange(0,WIDTH)  #sets initial position
        self.speed_X=random.randrange(-2,2)  #sets speed in X-direction
        self.speed_Y=random.randrange(1,3)  #sets speed in Y-direction
        self.name='meteor'  #sets name to meteor
        self.all_sprites=all_sprites  #sets all_sprites group
        self.sound=sound  #sets explosion sound
        if self.rect.width>44:  #checks if meteor is big
            self.isBig=True  #sets meteor's Big state to True
            self.health=100  #sets meteor's health = 100 units
            self.stealth=40  #sets meteor's stealth = 40 units
        else:  # if meteor is small
            self.isBig=False  #sets meteor's Big state to True
            self.health=40  #sets meteor's health = 40 units
            self.stealth=10  #sets meteor's stealth = 20 units


    def update(self):
        """This method overrides Sprite class's update method for object's movements."""
        self.rect.x+=self.speed_X  #moves in X-direction
        self.rect.y+=self.speed_Y  #moves in Y-direction

        if (self.speed_X<0 and self.rect.x<=0) or (self.speed_X>0 and self.rect.x+self.rect.width>=WIDTH):
            # ckecks if it hits boundaries in X-direction
            self.speed_X*=-1  #sets speed to negative of current speed.

        if self.rect.y==HEIGHT:  #if meteorite crosses game screen in Y-direction
            self.rect.y=0-self.rect.height  #sets it's position to start of screen

    def kill(self):
        """This method overrides kill method of Sprite class."""
        super().kill()  #calls super class kill method
        self.sound.play()  #plays explosion sound
        Explosion(self.all_sprites,self.rect)  #Explsoion sprite comes on screen.


class Enemy(pg.sprite.Sprite):
    """This class inherits Sprite class of pygame library.Overrides it's update and kill methods.
       Enemy class is for Enemy."""
    def __init__(self,mobs,bullets,all_sprites,sound):
        """This method is used to initialize Enemy object, mobs and bullets and all_sprites are groups.
           sound is for explosion sound."""
        pg.sprite.Sprite.__init__(self,mobs,all_sprites)  #calls super class constructor
        self.image=MOBS[random.randrange(0,2)]  #sets enemy image
        self.rect=self.image.get_rect()  #gets rect from image for Enemy's position
        self.bullets=bullets  #sets bullets group
        self.all_sprites=all_sprites  #sets all_sprites group
        self.stealth= 20#sets stealth to 20 units
        self.rect.x=random.randrange(0,WIDTH)  #sets initial position
        self.speed_X=random.randrange(-3,3)  #sets speed in X-direction
        self.speed_Y=2  #sets speed in Y-direction = 2units/second
        self.health=100  #sets health to 100 units
        self.now=pg.time.get_ticks()  #sets now to current system ticks
        self.name='enemy' #sets name to enenmy
        self.sound=sound  #sets explosion sound
    def shoot(self):
        """This method is used to shoot bullets."""
        if pg.time.get_ticks()-self.now>500:#checks if last bullet was shooted before 500 system ticks
            self.now=pg.time.get_ticks()  #sets now to current system ticks
            Bullet(self.bullets,self.all_sprites,self.rect,-1,'Green')  #Bullet object comes on the screen

    def update(self):
        """This method overrides update method of Sprite class and moves Object on game screen."""
        self.rect.x+=self.speed_X  #moves object in X-direction
        self.rect.y+=self.speed_Y  #moves object in Y-direction
        self.shoot()  #calls shoot method to shoot bullets

        """ ckecks if it hits boundaries in X-direction and if hits then sets speed to negative of current speed."""
        if self.speed_X<0 and self.rect.x<=0:
            self.speed_X*=-1
        elif self.speed_X>0 and self.rect.x+self.rect.width>=WIDTH:
            self.speed_X*=-1

        if self.rect.y==HEIGHT:#if meteorite crosses game screen in Y-direction
            self.rect.y=0-self.rect.height  #sets it's poition to start of screen

    def kill(self):
        """This method overrides kill method of Sprite class.It removes self from all groups and Explsoion object
           is initialized when called."""
        super().kill()#calls super class's kill method
        self.sound.play() #plays explosion sound
        Explosion(self.all_sprites,self.rect) ##Explosion object comes on screen

class Explosion(pg.sprite.Sprite):
    """This class inherits Sprite class from pygame library and overrides it's update method.
       Explosion class."""
    def __init__(self,all_sprites,rect,player=False):
        """This method initializes Explosion class object, all_sprites is group,rect is for position .
           player is boolean variable ,is used to see whether called by Player class or Enemy (or Mob) class."""
        pg.sprite.Sprite.__init__(self,all_sprites)  #calls super class constructor
        if player:  #if player class called
            self.EXX=SelfExplosionList  #sets player's explosion image list
            self.lim=19  #sets image count
        else:
            self.EXX=ExplosionList  #sets Enemy(or Mob)'s explsoion image list
            self.lim=13  #sets image count
        self.image=ExplosionList[0]  #sets initial explosion image
        self.rect=self.image.get_rect()  #gets rect from image
        self.rect.center=(rect.x,rect.y)  #sets position
        self.count=0  #count for explosion images

    def update(self):
        """This method overrides update method of Sprite class, and updates explosion's image one by one .
            once all images are shown,it is killed by calling kill method."""
        self.count+=1  #increases count for new image
        self.image=self.EXX[self.count]  #updates the image of explosion
        if self.count>=self.lim: #checks if all images are shown
            self.kill()  #kills self


