import math

from graphics import *

win = GraphWin("PolygonClipping", 500, 500)


def main():
    print("Enter number of points")
    n = int(input())
    arr=[]
    for i in range(n):
        print("Enter x co-ordinate of point")
        x = int(input())
        print("Enter y co-ordinate of point")
        y = int(input())
        print("Enter z co-ordinate of point")
        z = int(input())
        arr.append([x, y, z])
    print(arr)
    

main()
