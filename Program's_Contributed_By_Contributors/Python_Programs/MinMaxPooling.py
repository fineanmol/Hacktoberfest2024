import threading

R = int(input("Enter the number of rows:"))
C = int(input("Enter the number of columns:"))
 
# Initialize matrix
matrix1 = []
print("Enter the entries rowwise:")
 
# For user input
for i in range(R):          
    a = []
    for j in range(C):      
         a.append(int(input()))
    matrix1.append(a)
 
# For printing the matrix
for i in range(R):
    for j in range(C):
        print(matrix1[i][j], end=" ")
    print()

min_lock = threading.Lock()
max_lock = threading.Lock()

min_value = float('inf')
max_value = float('-inf')

def min_pooling(matrix):
    global min_value 
    for i in range(0, R - 1, 2):
        for j in range(0, C - 1, 2):
            min_val = min(matrix[i][j], matrix[i][j+1], matrix[i+1][j], matrix[i+1][j+1])
            with min_lock:
                min_value = min(min_value, min_val)

def max_pooling(matrix):
    global max_value 
    for i in range(0, R - 1, 2):
        for j in range(0, C - 1, 2):
            max_val = max(matrix[i][j], matrix[i][j+1], matrix[i+1][j], matrix[i+1][j+1])
            with max_lock:
                max_value = max(max_value, max_val)

t1 = threading.Thread(target=min_pooling, args=(matrix1,))
t2 = threading.Thread(target=max_pooling, args=(matrix1,))
t1.start()
t2.start()
t1.join()
t2.join()

min_val_from_threads = min_value
max_val_from_threads = max_value

print("Min value from the threads:", min_val_from_threads)
print("Max value from the threads:", max_val_from_threads)
