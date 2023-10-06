import threading
R= int(4)
C= int(4)

iMatrix = []
print("Enter the number for the matrix in row wise order:\n")
for i in range(R):
    a=[]
    for j in range(C):
        a.append(int(input()))
    iMatrix.append(a)

for i in range(R):
    for j in range(C):
        print(iMatrix[i][j],end=" ")
        print()
min_value = float("inf")
max_value = float("-inf")


min_pool_matrix = [[0,0],[0,0]]
max_pool_matrix = [[0,0],[0,0]]

min_lock = threading.Lock()
max_lock = threading.Lock()

def min_pooling(matrix):
    global min_value
    for i in range(0,R-1,2):
        for j in range(0,C-1,2):
            min_val = min(matrix[i][j],matrix[ i + 1][j],matrix[i][j + 1],matrix[i + 1][ j + 1])
            min_pool_matrix[i//2][j//2]=min_val
            with min_lock:
                min_value = min(min_val,min_value)

def max_pooling(matrix):
    global max_value
    for i in range(0,R-1,2):
        for j in range(0,C-1,2):
            max_val = max(matrix[i][j],matrix[ i + 1][j],matrix[i][j + 1],matrix[i + 1][j + 1])
            max_pool_matrix[i//2][j//2]=max_val
            with max_lock:
                max_value = max(max_val,max_value)

t1 = threading.Thread(target=min_pooling,args=(iMatrix,))
t2=threading.Thread(target=max_pooling,args=(iMatrix,))

t1.start()
t2.start()
t1.join()
t2.join()

print("Intermediate min pool :")
for row in min_pool_matrix:
    print(row)

print('\n')

print("Intermediate max pool :")
for row in max_pool_matrix:
    print(row)


print("The min value is : ",min_value)
print("the max value is :  ",max_value)
        