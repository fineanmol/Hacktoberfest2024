import PIL.Image as img
import numpy as np

BLOCKS = [' ', '.', '"', '=', 'r', 'o', 'n', 's', 'm']
SCALE = 2

inp = img.open('in.png')

inp = inp.convert('L').resize((inp.width//SCALE, inp.height//SCALE), img.BICUBIC)
inp = np.array(inp)

out = [[BLOCKS[px%len(BLOCKS)]*2 for px in row] for row in inp]


with open('out.txt', 'w', encoding="utf-8") as fd:
    fd.write('\n'.join([''.join(map(str, row)) for row in out]))


