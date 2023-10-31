red = input('Insert red value: ')
green = input('Insert green value: ')
blue = input('Insert blue value: ')

hex_str = "#"

for component in [red, green, blue]:
  hex_str += hex(int(component))[2:]
 
print(hex_str)
