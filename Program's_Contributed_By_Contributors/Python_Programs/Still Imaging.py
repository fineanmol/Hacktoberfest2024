import arcade
import random

win_width = 800
win_height = 600

# Drawing the background Screen :
def screen():
    arcade.draw_rectangle_filled(
        win_width / 2,
        win_height * 2 / 3,
        win_width - 1,
        win_height * 2 / 3,
        arcade.color.SKY_BLUE,
    )
    arcade.draw_rectangle_filled(
        win_width / 2,
        win_height / 6,
        win_width - 1,
        win_height / 3,
        arcade.color.LIGHT_GREEN,
    )


def birds(x, y):
    # Left Curve :
    arcade.draw_arc_outline(x, y, 40, 40, arcade.color.BLACK, 0, 90, 3)
    # Right Curve :
    arcade.draw_arc_outline(x + 40, y, 40, 40, arcade.color.BLACK, 90, 180, 3)


def trees(a, b):
    # The Bark of the Tree :
    arcade.draw_rectangle_filled(a, b, 20, 40, arcade.color.BROWN)
    # Drawing the Top of the Tree :
    line = b + 20
    list = ((a - 40, line), (a, line + 100), (a + 40, line))
    arcade.draw_polygon_filled(list, arcade.color.DARK_GREEN)


def sun():
    arcade.draw_circle_filled(600, 500, 50, arcade.color.SUNGLOW)


if __name__ == "__main__":
    arcade.open_window(win_width, win_height, "Still Imaging")
    arcade.start_render()
    screen()
    sun()

    for i in range(10):
        x = random.randrange(0, win_width)
        y = random.randrange(win_height / 2, win_height - 20)
        birds(x, y)

    for a in range(45, win_width, 90):
        trees(a, win_height / 3)

    for a in range(65, win_width, 90):
        trees(a, (win_height / 3) - 120)

    arcade.finish_render()
    arcade.run()
