# the GUI part of the sudoku solver
import pygame
import time
pygame.font.init()


class Grid:
    board = [
        [3, 0, 6, 5, 0, 8, 4, 0, 0],
        [5, 2, 0, 0, 0, 0, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 0, 3, 1],
        [0, 0, 3, 0, 1, 0, 0, 8, 0],
        [9, 0, 0, 8, 6, 3, 0, 0, 5],
        [0, 5, 0, 0, 9, 0, 6, 0, 0],
        [1, 3, 0, 0, 0, 0, 2, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 7, 4],
        [0, 0, 5, 2, 0, 6, 3, 0, 0]
    ]

    def __init__(self, rows, cols, width, height,win):
        self.rows = rows
        self.cols = cols
        self.cubes = [[Cube(self.board[i][j], i, j, width, height) for j in range(cols)] for i in range(rows)]
        self.width = width
        self.height = height
        self.model = None
        self.update_model()
        self.selected = None
        self.win = win

    def update_model(self):
        self.model = [[self.cubes[i][j].value for j in range(
            self.cols)] for i in range(self.rows)]

    def place(self, val):
        row, col = self.selected
        if self.cubes[row][col].value == 0:
            self.cubes[row][col].set(val)
            self.update_model()

            if check_validity(self.model, val, (row, col)) and self.solve_board():
                return True
            else:
                self.cubes[row][col].set(0)
                self.cubes[row][col].set_temp(0)
                self.update_model()
                return False

    def sketch(self, val):
        row, col = self.selected
        self.cubes[row][col].set_temp(val)

    def draw(self):

        # drawing the grid lines on the board

        gap = self.width / 9
        for i in range(self.rows+1):
            if i % 3 == 0 and 1 != 0:
                thick = 4
            else:
                thick = 1
            pygame.draw.line(self.win, (0, 0, 0), (0, i*gap), (self.width, i*gap), thick)
            pygame.draw.line(self.win, (0, 0, 0), (i*gap, 0), (i*gap, self.height), thick)

            # drawing the cubes
        for i in range(self.rows):
            for j in range(self.cols):
                self.cubes[i][j].draw(self.win)

    def select(self, row, col):
        # reset all other values
        for i in range(self.rows):
            for j in range(self.cols):
                self.cubes[i][j].selected = False
                
            self.cubes[row][col].selected = True
            self.selected = (row, col)

    def clear(self):
        row, col = self.selected
        if self.cubes[row][col].value == 0:
            self.cubes[row][col].set_temp(0)

    def click(self, posi):
        """
        :param: posi
        :return: (row, col)
        """
        if posi[0] < self.width and posi[1] < self.height:
            gap = self.width / 9
            x = posi[0] // gap
            y = posi[1] // gap
            return (int(y), int(x))
        else:
            return None

    def is_finished(self):
        for i in range(self.rows):
            for j in range(self.cols):
                if self.cubes[i][j].value == 0:
                    return False
        return True

    def solve_board(self):

        find = find_empty_spaces(self.model)
        if not find:
            return True
        else:
            row, col = find

        for i in range(1, 10):
            if check_validity(self.model, i, (row, col)):
                self.model[row][col] = i

                if self.solve_board():
                    return True

                self.model[row][col] = 0

        return False

    def solve_gui(self):
        find = find_empty_spaces(self.model)
        if not find:
            return True
        else:
            row, col = find

        for i in range(1, 10):
            if check_validity(self.model, i, (row, col)):
                self.model[row][col] = i
                self.cubes[row][col].set(i)
                self.cubes[row][col].draw_new(self.win, True)
                self.update_model()
                pygame.display.update()
                pygame.time.delay(100)

            if self.solve_gui():
                return True

            self.model[row][col] = 0
            self.cubes[row][col].set(0)
            self.update_model()
            self.cubes[row][col].draw_new(self.win, False)
            pygame.display.update()
            pygame.time.delay(100)

        return False


class Cube:
    rows = 9
    cols = 9 
    
    def __init__(self, value, row, col, width, height):
        self.value = value
        self.temp = 0
        self.row = row
        self.col = col 
        self.width = width
        self.height = height
        self.selected = False

    def draw(self, win):
        fontt = pygame.font.SysFont("comicsans", 40)

        gap = self.width / 9
        x = self.col * gap
        y = self.row * gap

        if self.temp != 0 and self.value == 0:
            text = fontt.render(str(self.temp), 1, (128, 128, 128))
            win.blit(text, (x + 5, y + 5))
        elif not (self.value == 0):
            text = fontt.render(str(self.value), 1, (0, 0, 0))
            win.blit(text, (x + (gap / 2 - text.get_width() / 2), y + (gap / 2 - text.get_height() / 2)))

        if self.selected:
            pygame.draw.rect(win, (255, 0, 0), (x, y, gap, gap), 3)

    def draw_new(self, win, g=True):
        fontt = pygame.font.SysFont("comicsans", 40)

        gap = self.width / 9
        x = self.col * gap
        y = self.row * gap

        pygame.draw.rect(win, (255, 255, 255), (x, y, gap, gap), 0)

        text = fontt.render(str(self.value), 1, (0, 0, 0))
        win.blit(text, (x + (gap / 2 - text.get_width() / 2), y + (gap / 2 - text.get_height() / 2)))
        if g:
            pygame.draw.rect(win, (0, 255, 0), (x, y, gap, gap), 3)
        else:
            pygame.draw.rect(win, (255, 0, 0), (x, y, gap, gap), 3)

    def set(self, val):
        self.value = val

    def set_temp(self, val):
        self.temp = val


def find_empty_spaces(board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                return (i, j)
    return None


def check_validity(board, num, posi):

    # row checking
    for i in range(len(board[0])):
        # check if any element in all cols. of row are equal to ip but not in the position of recent insertion
        if board[posi[0]][i] == num and posi[1] != i:
            return False

    # column checking
    for i in range(len(board)):
        # check if any element in all rows. of col are equal to ip but not in the position of recent insertion
        if board[i][posi[1]] == num and posi[0] != i:
            return False

    # box checking
    xbox = posi[1] // 3           # integer division, takes us to a certain box
    ybox = posi[0] // 3

# helps us reach an element in the board
    for i in range(ybox*3, ybox*3+3):
        for j in range(xbox*3, xbox*3+3):
            # check if any element in all rows, cols of the box are = to ip but not in the position of recent insertion
            if board[i][j] == num and (i, j) != posi:
                return False

    return True


def redraw_window(win, board, time, strikes):
    win.fill((255, 255, 255))

    # Draw stop clock
    fontt = pygame.font.SysFont("comicsans", 40)
    text = fontt.render("Time: " + format_time(time), 1, (0, 0, 0))
    win.blit(text, (540 - 160, 560))

    # Draw number of wrong attempts
    text = fontt.render("X " * strikes, 1, (255, 0, 0))
    win.blit(text, (20, 560))

    # Draw grid and board
    board.draw()


def format_time(secs):
    sec = secs % 60
    minute = secs // 60
    hour = minute // 60

    mat = " " + str(minute) + ":" + str(sec)
    return mat


def main():
<<<<<<< HEAD
#     win = pygame.display.set_mode((540,600))
#     pygame.display.set_caption("Sudoku")
=======
    win = pygame.display.set_mode((540,600))
    pygame.display.set_caption("Sudoku")
>>>>>>> 01e6a11ecda8e1f32b553a8eae2d2350a1570d7d
    board = Grid(9, 9, 540, 540, win)
    key = None
    run = True
    start = time.time()
    strikes = 0
    while run:

        play_time = round(time.time() - start)  
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_1 or event.key == pygame.K_KP1:
                    key = 1
                if event.key == pygame.K_2 or event.key == pygame.K_KP2:
                    key = 2
                if event.key == pygame.K_3 or event.key == pygame.K_KP3:
                    key = 3
                if event.key == pygame.K_4 or event.key == pygame.K_KP4:
                    key = 4
                if event.key == pygame.K_5 or event.key == pygame.K_KP5:
                    key = 5
                if event.key == pygame.K_6 or event.key == pygame.K_KP6:
                    key = 6
                if event.key == pygame.K_7 or event.key == pygame.K_KP7:
                    key = 7
                if event.key == pygame.K_8 or event.key == pygame.K_KP8:
                    key = 8
                if event.key == pygame.K_9 or event.key == pygame.K_KP9:
                    key = 9
                    
                if event.key == pygame.K_DELETE:
                    board.clear()
                    key = None
                 
                if event.key == pygame.K_SPACE:
                    board.solve_gui()
                    
                if event.key == pygame.K_RETURN or event.key==pygame.K_KP_ENTER:
                    i, j = board.selected
                    if board.cubes[i][j].temp != 0:
                        if board.place(board.cubes[i][j].temp):
                            print("Correct")
                        else:
                            print("Wrong")
                            strikes += 1
                        key = None

                        if board.is_finished():
                            print("Bravo Game Over")
                            # run = False
                
            if event.type == pygame.MOUSEBUTTONDOWN:
                posi = pygame.mouse.get_pos()
                clicked = board.click(posi)
                if clicked:
                    board.select(clicked[0], clicked[1])
                    key = None

        if board.selected and key != None:
            board.sketch(key)

        redraw_window(win, board, play_time, strikes)
        pygame.display.update()


main()
pygame.quit()