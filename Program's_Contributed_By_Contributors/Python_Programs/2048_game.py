
import numpy, random
import pygame, time

WON_VALUE = 2048

ADD_SCALE = 1
MERGE_SCALE = 2

# move directions
DIR_LEFT = 0
DIR_UP = 1
DIR_RIGHT = 2
DIR_DOWN = 3

# font and alignments
DEFAULT_FONT = 'microsoftsansserif'
ALIGN_LEFT = 0
ALIGN_RIGHT = 1
ALIGN_CENTER = 2

ANIM_TIME = 0.4

# animation directions
DIR_VECTOR = [
    (-1, 0),
    (0, -1),
    (1, 0),
    (0, 1),
]

# keymappping
KEYMAP = {
    'w': DIR_UP, # up
    'a': DIR_LEFT, # left
    's': DIR_DOWN, # down
    'd': DIR_RIGHT, # right
}

PALETTE_1 = {
    -3    : '#776E65', # small text (for 2, 4 and game over text)
    -2    : '#F9F6F2', # big text
    -1    : '#BBADA0', # grid color
     0    : '#CCC0B3',
     2    : '#EEE4DA', # also in game over overlay
     4    : '#EDE0C8',
     8    : '#F2B179',
     16   : '#F59563',
     32   : '#F67C5F',
     64   : '#F65E3B',
     128  : '#EDCF72',
     256  : '#EDCC61',
     512  : '#EDC850',
     1024 : '#EDC53F',
     2048 : '#EDC22E',
     4096 : '#3E3933',
}

def get_color(elm):
    return pygame.Color(PALETTE_1[elm if elm in PALETTE_1 else 4096])

def get_grid_layout(screen_rect, cell_count):
        padding = 10
        size = min(screen_rect.size) - padding*2

        # background square rect
        bg_rect = pygame.Rect(0, 0, size, size)
        bg_rect.midbottom = screen_rect.midbottom
        bg_rect.bottom = screen_rect.bottom - padding

        # cell_rect_list
        cell_size = (size - padding*(cell_count + 1)) / cell_count
        cell_rect = pygame.Rect(0, 0, cell_size, cell_size)
        cell_size += padding
        px, py = bg_rect[0] + padding, bg_rect[1] + padding

        cell_rect_list = [ cell_rect.move(x*cell_size + px, y*cell_size + py) \
                            for y in range(cell_count) for x in range(cell_count) ]
        
        return bg_rect, cell_rect_list

class Grid:
    
    def __init__(self, size):
        self.size = size
        self.reset()
    
    def __iter__(self):
        return iter(self.grid)

    def __len__(self):
        return len(self.grid)


    def reset(self):
        size = self.size

        self.grid = numpy.zeros((size, size), dtype=int)

        self.score = 0
        self.won = False
        self.play_on = False
        self.game_over = False

        # for animation
        self.previous = None    # holds previous grid
        self.translation = numpy.zeros_like(self.grid)    # info where tiles moved
        self.scale = numpy.zeros_like(self.grid)  # info which tiles merged or added

        # adds 2 elements first time
        self.add_element(2)
    

    def add_element(self, count=1):
        # get empty cells
        empties = list(zip(*numpy.nonzero(self.grid == 0)))
        # empties = list(numpy.transpose(numpy.nonzero(self.grid == 0)))

        # chose random cell from empties
        for r, c in random.sample(empties, k=count):
            # assign 2 or 4 randomly
            self.grid[r][c] = random.sample((2, 4), counts=(8,2), k=1)[0]
            self.scale[r][c] = ADD_SCALE
    

    def is_compressible(self):
        # check for zeros, same pair in original and transpose
        return numpy.any(self.grid == 0) \
            or numpy.any(numpy.diff(self.grid) == 0) \
            or numpy.any(numpy.diff(self.grid.T) == 0)


    def compress(self):
        
        self.translation = numpy.zeros_like(self.grid)    # info where tiles moved
        self.scale = numpy.zeros_like(self.grid)  # info which tiles merged or added
        
        new_grid = numpy.zeros_like(self.grid)   # new grid
        
        for r, row in enumerate(self.grid):
            inr, iprev, prev = 0, 0, None    # stores previous index and element
            for c, elm in enumerate(row):
                if elm == 0: continue

                if not prev:
                    iprev, prev = c, elm

                elif elm == prev:   # merge
                    elm *= 2

                    self.translation[r][c] = c - inr
                    self.translation[r][iprev] = iprev - inr
                    self.scale[r][inr] = MERGE_SCALE
                    self.score += elm   # update score

                    new_grid[r][inr] = elm; inr += 1    # append
                    iprev, prev = c, None

                else:
                    self.translation[r][iprev] = iprev - inr
                    new_grid[r][inr] = prev; inr += 1    # append
                    iprev, prev = c, elm

            if prev:    # add remaining
                self.translation[r][iprev] = iprev - inr
                new_grid[r][inr] = prev; inr += 1    # append

        compressed = numpy.any(self.grid != new_grid)

        self.grid = new_grid

        return compressed
        
    
    def move(self, dir):
        if  not self.is_compressible():
            return False
        
        if not self.play_on and self.won:
            self.play_on = True
        
        self.previous = numpy.copy(self.grid)
        self.grid = numpy.rot90(self.grid, k=dir)
        
        compressed = self.compress()
        
        dir = -dir
        self.grid = numpy.rot90(self.grid, k=dir)
        self.translation = numpy.rot90(self.translation, k=dir)
        self.scale = numpy.rot90(self.scale, k=dir)
        
        if compressed:
            if not self.won:
                self.won = numpy.any(self.grid >= WON_VALUE)  # checks for WON_VALUE

            game_over = numpy.all(self.grid != 0)

            if not game_over:
                self.add_element()

            game_over |= not self.is_compressible()

            self.game_over = game_over

        return compressed

class Renderer:

    screen = None
    scene = None
    default_font = None

    redraw = True
    previous_t, delta_t = 0, 0

    def init(title, size):
        pygame.init()
        Renderer.screen = pygame.display.set_mode(size)
        pygame.display.set_caption(title)

        Renderer.default_font = pygame.font.SysFont(DEFAULT_FONT, 30)
    
    def delta():
        return Renderer.delta_t

    def invalid():
        Renderer.redraw = True

    def set_scene(scene):
        Renderer.scene = scene
        Renderer.scene.layout(Renderer.screen)
        Renderer.invalid()
    
    def loop():
        Renderer.previous_t = time.time()

        while True:

            events = pygame.event.get() if Renderer.redraw \
                else ([pygame.event.wait()] + pygame.event.get())

            for event in events:
                if event.type == pygame.QUIT:
                    return
                
                if Renderer.scene:
                    Renderer.scene.event(event)
            
            cur_t = time.time()
            Renderer.delta_t = cur_t - Renderer.previous_t
            Renderer.previous_t = time.time()
            
            if Renderer.scene and Renderer.redraw:
                Renderer.redraw = False
                Renderer.scene.draw(Renderer.screen)
                pygame.display.flip()

    def draw_text(text, pos, color, align=ALIGN_CENTER, font=None):
        if not font:
            font = Renderer.default_font
        
        surface = font.render(text, True, color)

        x, y = pos
        size = surface.get_size()

        if align == ALIGN_CENTER:
            x -= size[0]/2
            y -= size[1]/2

        elif align == ALIGN_RIGHT:
            x -= size[0]
        
        Renderer.screen.blit(surface, (x, y))


    def draw_roundrect(rect, color, radius=0.5):
        
        rect         = pygame.Rect(rect)
        color        = pygame.Color(*color)
        alpha        = color.a
        color.a      = 0
        pos          = rect.topleft
        rect.topleft = 0,0
        rectangle    = pygame.Surface(rect.size,pygame.SRCALPHA)

        circle       = pygame.Surface([min(rect.size)*3]*2,pygame.SRCALPHA)
        pygame.draw.ellipse(circle,(0,0,0),circle.get_rect(),0)
        circle       = pygame.transform.smoothscale(circle,[int(min(rect.size)*radius)]*2)

        radius              = rectangle.blit(circle,(0,0))
        radius.bottomright  = rect.bottomright
        rectangle.blit(circle,radius)
        radius.topright     = rect.topright
        rectangle.blit(circle,radius)
        radius.bottomleft   = rect.bottomleft
        rectangle.blit(circle,radius)

        rectangle.fill((0,0,0),rect.inflate(-radius.w,0))
        rectangle.fill((0,0,0),rect.inflate(0,-radius.h))

        rectangle.fill(color,special_flags=pygame.BLEND_RGBA_MAX)
        rectangle.fill((255,255,255,alpha),special_flags=pygame.BLEND_RGBA_MIN)

        return Renderer.screen.blit(rectangle,pos)

class StartScene:

    GRID_SIZES = [
        "3x3",
        "4x4",
        "6x6",
        "8x8",
    ]

    def __init__(self):
        self.title = "Select Grid Size"
        self.hovered = [0] * len(StartScene.GRID_SIZES)
    
    def layout(self, screen):
        padding = 10

        bg_rect, cell_rect_list = get_grid_layout(screen.get_rect(), 2)

        # title rect
        title = self.title
        sx, sy = Renderer.default_font.size(title)
        title_rect = pygame.Rect(0, 0, sx + 2*padding, sy + 2*padding)
        title_rect.center = bg_rect.center
        title_rect.bottom = bg_rect.top - padding

        self.title_rect = title_rect
        self.bg_rect = bg_rect
        self.cell_rect_list = cell_rect_list

    def draw(self, screen):
        
        screen.fill(-1)
        
        # bg rect
        Renderer.draw_roundrect(self.bg_rect, get_color(-1), 0.03)

        # title
        Renderer.draw_roundrect(self.title_rect, get_color(2), 0.2)
        Renderer.draw_text(self.title, self.title_rect.center, get_color(-3))

        # cells
        for cell_rect, text, hovered in zip(self.cell_rect_list, StartScene.GRID_SIZES, self.hovered):
            Renderer.draw_roundrect(cell_rect, get_color(4 if hovered else 2), 0.1)
            Renderer.draw_text(text, cell_rect.center, get_color(-3))

    def event(self, event):
        if event.type == pygame.MOUSEMOTION:
            self.hovered = [ rect.collidepoint(event.pos) for rect in self.cell_rect_list]
            Renderer.invalid()
        
        elif event.type == pygame.MOUSEBUTTONUP and event.button == pygame.BUTTON_LEFT:
            idx = next((i for i, rect in enumerate(self.cell_rect_list) if rect.collidepoint(event.pos)), -1)
            
            if idx != -1:
                size = int(StartScene.GRID_SIZES[idx][0])
                Renderer.set_scene(GameScene(size))

class GameScene:

    BUTTONS = [
        "Home",
        "Retry",
    ]

    def __init__(self, grid_size=4):
        self.grid = Grid(grid_size)

        self.is_animating = False
        self.anim_time = 0
        self.direction = None

        self.msg = None # to dispaly won or game over
    
    def layout(self, screen):
        padding = 10

        bg_rect, cell_rect_list = get_grid_layout(screen.get_rect(), self.grid.size)

        self.buttons = []

        left = bg_rect.left + padding
        for text in GameScene.BUTTONS:
            sx, sy = Renderer.default_font.size(text)
            button = pygame.Rect(0, 0, sx + 2*padding, sy + 2*padding)
            button.left = left
            button.bottom = bg_rect.top - padding
            left += button.width + padding

            self.buttons.append(button)

        self.hovered = [0] * len(self.buttons)
        self.bg_rect = bg_rect
        self.cell_rect_list = cell_rect_list
        self.cell_offset = cell_rect_list[0].width + padding
    
    def start_animation(self):
        self.is_animating = True
        self.anim_time = 0

        # convert 2d arrays to 1d (once for each move)
        self.element_list = numpy.ravel(self.grid.grid)
        self.prev_element_list = numpy.ravel(self.grid.previous)
        self.translation_list = numpy.ravel(self.grid.translation)
        self.scale_list = numpy.ravel(self.grid.scale)

        Renderer.invalid()


    def stop_animation(self):
        self.is_animating = False
        Renderer.invalid()

    def draw(self, screen):
        padding = 10
        
        screen.fill(-1)
        
        bg_rect = self.bg_rect
        Renderer.draw_roundrect(bg_rect, get_color(-1), 0.03)

        # draw buttons
        for text, rect, hover in zip(GameScene.BUTTONS, self.buttons, self.hovered):
            Renderer.draw_roundrect(rect, get_color(4 if hover else 2), 0.2)
            Renderer.draw_text(text, rect.center, get_color(-3))
        
        # draw score
        score_text = "Score: " + str(self.grid.score)
        sx, sy = Renderer.default_font.size(score_text)
        score_rect = pygame.Rect(0, 0, sx + 20, sy + 20)
        score_rect.right = bg_rect.right - padding
        score_rect.bottom = bg_rect.top - padding
        Renderer.draw_roundrect(score_rect, get_color(2), 0.2)
        Renderer.draw_text(score_text, score_rect.center, get_color(-3))

        if self.is_animating:
            
            # draw cell backgrounds
            for cell_rect in self.cell_rect_list:
                Renderer.draw_roundrect(cell_rect, get_color(0), 0.1)

            trans_time_fact = 0.7
            total_time = self.anim_time

            if total_time <= trans_time_fact:
                anim_time = total_time / trans_time_fact
                if anim_time > 1.0: anim_time = 1.0

                for elm, cell_rect, delta in zip(self.prev_element_list, self.cell_rect_list, self.translation_list):
                    if not elm: continue

                    dx, dy = DIR_VECTOR[self.direction]
                    delta = delta * self.cell_offset * anim_time
                    
                    cell = cell_rect.move(dx*delta, dy*delta)
                    Renderer.draw_roundrect(cell, get_color(elm), 0.1)
                    Renderer.draw_text(str(elm), cell.center, get_color(-3 if elm in (2,4) else -2))
                
            else:
                anim_time = (total_time - trans_time_fact) / (1.0 - trans_time_fact)
                if anim_time > 1.0: anim_time = 1.0

                for elm, cell_rect, scale in zip(self.element_list, self.cell_rect_list, self.scale_list):
                    if not elm: continue

                    if scale == ADD_SCALE:
                        scale = anim_time - 1.0

                    elif scale == MERGE_SCALE:
                        scale = anim_time*0.1
                    
                    else:
                        scale = 0.0

                    scale *= cell_rect.width

                    cell = cell_rect.inflate(scale, scale)
                    Renderer.draw_roundrect(cell, get_color(elm), 0.1)
                    Renderer.draw_text(str(elm), cell.center, get_color(-3 if elm in (2,4) else -2))

        else:
            grid = self.grid
            element_list = [i for row in grid for i in row]
            for elm, cell_rect in zip(element_list, self.cell_rect_list):
                Renderer.draw_roundrect(cell_rect, get_color(elm), 0.1)
                if elm:
                    Renderer.draw_text(str(elm), cell_rect.center, get_color(-3 if elm in (2,4) else -2))


            if self.msg:
                surface = pygame.Surface(bg_rect.size)
                surface.set_alpha(186)
                surface.fill(get_color(2))
                screen.blit(surface, bg_rect.topleft)
                Renderer.draw_text(self.msg, bg_rect.center, get_color(-3))
        
        # update animation time
        if self.is_animating:
            Renderer.invalid()

            if self.anim_time == 1.0:
                self.stop_animation()
            else:
                self.anim_time += Renderer.delta() / ANIM_TIME
                if self.anim_time > 1.0:
                    self.anim_time = 1.0

    
    def event(self, event):
        Renderer.invalid()

        if event.type == pygame.MOUSEMOTION:
            self.hovered = [rect.collidepoint(event.pos) for rect in self.buttons]
            return
        
        if event.type == pygame.MOUSEBUTTONUP \
            and event.button == pygame.BUTTON_LEFT:
            idx = next((i for i, rect in enumerate(self.buttons) if rect.collidepoint(event.pos)), -1)
            
            if idx != -1:
                if idx == 0:    # home
                    Renderer.set_scene(StartScene())

                elif idx == 1:
                    self.grid.reset()
                    self.msg = None

            elif self.msg and self.bg_rect.collidepoint(event.pos):
                self.msg = None

            return
        
        if self.msg:    # consume events untill KEYUP
            if event.type == pygame.KEYUP:
                self.msg = None
            return

        if self.is_animating or self.grid.game_over or event.type != pygame.KEYUP:
            return
        
        key = event.unicode.lower()
        
        if key not in KEYMAP:
            return
        
        dir = KEYMAP[key]

        self.direction = dir
        
        if self.grid.move(dir):
            self.start_animation()

            if self.grid.won and not self.grid.play_on:
                self.msg = "You Won!"
            
            elif self.grid.game_over:
                self.msg = "Game Over!"
            


if __name__ == '__main__':

    Renderer.init("2048", (500,580))
    Renderer.set_scene(StartScene())
    Renderer.loop()
