"""
Multiplication of 2 - matrices

Sample I/O:

Example 1:
Enter the dimensions of Matrix 1(separated by a space): 3 3
Enter the elements of Matrix 1
1 1 1
2 2 2 
3 3 3
Enter the dimensions of Matrix 2(separated by a space): 3 4
Enter the elements of Matrix 2
1 1 1 1
2 2 2 2
3 3 3 3
Multiplication of Matrix 1 and Matrix 2 is: 
6 6 6 6
12 12 12 12
18 18 18 18

Example 2:
Enter the dimensions of Matrix 1(separated by a space): 3 2
Enter the elements of Matrix 1
1 2
3 4
5 6
Enter the dimensions of Matrix 2(separated by a space): 1 5
Enter the elements of Matrix 2
9 8 7 4 6
Matrices cannot be multiplied
"""

r1,c1 = map(int,input("Enter the dimensions of Matrix 1(separated by a space): ").split())
print("Enter the elements of Matrix 1")
m1 = [list(map(int,input().split())) for i in range(r1)]
r2,c2 = map(int,input("Enter the dimensions of Matrix 2(separated by a space): ").split())
print("Enter the elements of Matrix 2")
m2 = [list(map(int,input().split())) for i in range(r2)]

# Creating new matrix for final matrix
m3 = [([0]*c2) for i in range(r1)]

# Checking whether matrix m1 can be multiplied with matrix m2
if c1 != r1:
    print("Matrices cannot be multiplied")
else:
    # Multiplication process
    # iterating by row of Matrix m1
    for i in range(r1):
        # iterating by column of Matrix m2
        for j in range(c2):
            # iterating by row of Matrix m2
            for k in range(r2):
                m3[i][j] += m1[i][k] * m2[k][j]     

    # printing the resultant matrix
    print("Multiplication of Matrix 1 and Matrix 2 is: ")
    for row in m3:
        print(*row)
