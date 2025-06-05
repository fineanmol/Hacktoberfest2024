 Basic infrastructure for Bubble Shooter

import simplegui
import random
import math

# Global constants
WIDTH = 800
HEIGHT = 600
FIRING_POSITION = [WIDTH // 2, HEIGHT]
FIRING_LINE_LENGTH = 60
FIRING_ANGLE_VEL_INC = 0.02
BUBBLE_RADIUS = 20
COLOR_LIST = ["Red", "Green", "Blue", "White"]

# global variables
firing_angle = math.pi / 2
firing_angle_vel = 0
bubble_stuck = True

# firing sound
firing_sound = simplegui.load_sound("http://commondatastorage.googleapis.com/codeskulptor-assets/Collision8-Bit.ogg")


# helper functions to handle transformations
def angle_to_vector(ang):
    return [math.cos(ang), math.sin(ang)]

def dist(p,q):
    return math.sqrt((p[0]-q[0])**2+(p[1]-q[1])**2)


# class defintion for Bubbles
class Bubble:
    
    def __init__(self, sound = None):
        self.pos = list(FIRING_POSITION)
        self.vel = [0, 0]
        self.color = random.choice(COLOR_LIST)
        self.sound = sound
        
    def update(self):
        self.pos[0] += self.vel[0]
        self.pos[1] += self.vel[1]
        if self.pos[0] <= BUBBLE_RADIUS or self.pos[0] >= WIDTH - BUBBLE_RADIUS:
            self.vel[0] = - self.vel[0]
            
    def fire_bubble(self, vel):
        self.vel = vel
        if self.sound:
            self.sound.play()
            
                
    def is_stuck(self, bubble_group): 
        if self.pos[1] <= BUBBLE_RADIUS:
            return True
        for b in bubble_group:
            if self.collide(b):
                return True
        return False

    def collide(self, bubble):
        return dist(self.pos, bubble.pos) <= 2 * BUBBLE_RADIUS
            
    def draw(self, canvas):
        canvas.draw_circle(self.pos, BUBBLE_RADIUS, 1, "White", self.color)
           

# define keyhandlers to control firing_angle
def keydown(key):
    global a_bubble, firing_angle_vel, bubble_stuck
    if simplegui.KEY_MAP["space"] == key and bubble_stuck:
        bubble_stuck = False
        vel = angle_to_vector(firing_angle)
        a_bubble.fire_bubble([4 * vel[0], -4 * vel[1]])
    elif simplegui.KEY_MAP["left"] == key:
        firing_angle_vel += FIRING_ANGLE_VEL_INC
    elif simplegui.KEY_MAP["right"] == key:
        firing_angle_vel -= FIRING_ANGLE_VEL_INC

def keyup(key):
    global firing_angle_vel
    if simplegui.KEY_MAP["left"] == key:
        firing_angle_vel -= FIRING_ANGLE_VEL_INC
    elif simplegui.KEY_MAP["right"] == key:
        firing_angle_vel += FIRING_ANGLE_VEL_INC
    
# define draw handler
def draw(canvas):
    global firing_angle, a_bubble, bubble_stuck
    
    # update firing angle
    firing_angle += firing_angle_vel
    
    #draw firing line
    orient = angle_to_vector(firing_angle)
    upper_endpoint = [FIRING_POSITION[0] + FIRING_LINE_LENGTH * orient[0], 
                      FIRING_POSITION[1] - FIRING_LINE_LENGTH * orient[1]]
    canvas.draw_line(FIRING_POSITION, upper_endpoint, 4, "White")
    
    # update a_bubble and check for sticking
    a_bubble.update()
    if a_bubble.is_stuck(stuck_bubbles):
        bubble_stuck = True
        stuck_bubbles.add(a_bubble)
        a_bubble = Bubble(firing_sound)
    
    # draw a bubble and stuck bubbles
    a_bubble.draw(canvas)
    for b in stuck_bubbles:
        b.draw(canvas)
 
# create frame and register handlers
frame = simplegui.create_frame("Bubble Shooter", WIDTH, HEIGHT)
frame.set_keydown_handler(keydown)
frame.set_keyup_handler(keyup)
frame.set_draw_handler(draw)

# create initial buble and start frame
a_bubble = Bubble(firing_sound)
stuck_bubbles = set([])
frame.start()
