def flood_fill(image, start, new_color):
    height, width = len(image), len(image[0])
    original_color = image[start[0]][start[1]]
    
    def recursive_fill(x, y):
        if (
            x < 0 or x >= height or
            y < 0 or y >= width or
            image[x][y] != original_color or
            image[x][y] == new_color
        ):
            return

        image[x][y] = new_color

        recursive_fill(x+1, y)
        recursive_fill(x-1, y)
        recursive_fill(x, y+1)
        recursive_fill(x, y-1)

    recursive_fill(start[0], start[1])

# Example usage
image = [
    [1, 1, 1, 1, 1],
    [1, 1, 1, 0, 0],
    [1, 0, 0, 1, 0],
    [1, 1, 0, 1, 0],
    [1, 1, 1, 1, 1]
]

start_point = (2, 2)
new_color = 2

flood_fill(image, start_point, new_color)

# Print the filled image
for row in image:
    print(row)
