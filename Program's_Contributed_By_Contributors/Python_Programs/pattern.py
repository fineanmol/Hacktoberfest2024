val = int(input("Give your value in stars: "))
#for square
def square(num):
    num = val
    for i in range(num):
        for j in range(num):
            print("*", end = " ")
        print()
#increasing triangle
def increasing_triangle(num):
    num = val
    for i in range(num):
        for j in range(i+1):
            print("*", end = " ")
        print()      
#decreasing triangle
def decreasing_triangle(num):
    num = val
    for i in range(num):
        for j in range(i,n):
            print("*", end = " ")
        print()
#right sided triangle (increasing star)
def right_sided_triangle_inc(num):
    num = val
    for i in range(num):
        for j in range(i,num):
            print("",end = " ")
        for j in range(i+1):
            print("*", end = " ")    
        print()        
#right sided triangle (decreasing star)        
def right_sided_triangle_dec(num):
    num = val
    for i in range(num):
        for j in range(i+1):
            print("",end = " ")
        for j in range(i,num):
            print("*", end = " ")    
        print()      
#hill pattern
def hill_pattern(num):
    num = val
    for i in range(num):
        for j in range(i,num):
            print(" ", end = " ")
        for j in range(i):
            print("*",end = " ")
        for j in range(i+1):
            print("*",end = " ")    
        print()
#reverse hill pattern
def reverse_hill_pattern(num):
    num = val
    for i in range(num):
        for j in range(i+1):
            print(" ", end = " ")
        for j in range(i,n-1):
            print("*",end = " ")
        for j in range(i,n):
            print("*",end = " ")    
        print()      
#diamond pattern
def diamond(num):
    num = val
    for i in range(num):
        print(" " * (num - i), "*" * (2*i + 1))
    for i in range(num - 2, -1, -1):
        print(" " * (num - i), "*" * (2*i + 1))    

#comment out other lines below here while printing one funnction
square(val)    #square
increasing_triangle(val)       #increasing triangle
decreasing_triangle(val)   #decreasing triangle
right_sided_triangle_inc(val) #right sided triangle (increasing star)
right_sided_triangle_dec(val) #right sided triangle (decreasing star)
hill_pattern(val) #hill pattern
reverse_hill_pattern(val) #reverse hill pattern
diamond(val) #diamond pattern