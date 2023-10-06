import threading

# Function to get a 4x4 matrix input from the user
def get_matrix_input():
    matrix = []
    print("Enter the 4x4 matrix entries:")
    for _ in range(4):
        row = []
        for _ in range(4):
            entry = int(input())
            row.append(entry)
        matrix.append(row)
    return matrix

matrix = get_matrix_input()

min_lock = threading.Lock()
max_lock = threading.Lock()

min_value = float('inf')
max_value = float('-inf')

min_pooling_matrix = [[0, 0], [0, 0]]  # Intermediate matrix after min pooling
max_pooling_matrix = [[0, 0], [0, 0]]  # Intermediate matrix after max pooling

def min_pooling():
    global min_value, min_pooling_matrix
    for i in range(0, 4, 2):
        for j in range(0, 4, 2):
            min_val = min(matrix[i][j], matrix[i][j+1], matrix[i+1][j], matrix[i+1][j+1])
            min_pooling_matrix[i//2][j//2] = min_val  # Store intermediate min value
            with min_lock:
                min_value = min(min_value, min_val)

def max_pooling():
    global max_value, max_pooling_matrix
    for i in range(0, 4, 2):
        for j in range(0, 4, 2):
            max_val = max(matrix[i][j], matrix[i][j+1], matrix[i+1][j], matrix[i+1][j+1])
            max_pooling_matrix[i//2][j//2] = max_val  # Store intermediate max value
            with max_lock:
                max_value = max(max_value, max_val)

t1 = threading.Thread(target=min_pooling)
t2 = threading.Thread(target=max_pooling)
t1.start()
t2.start()
t1.join()
t2.join()

min_val_from_threads = min_value
max_val_from_threads = max_value

print("Intermediate 2x2 matrix after min pooling:")
for row in min_pooling_matrix:
    print(row)

print("\nIntermediate 2x2 matrix after max pooling:")
for row in max_pooling_matrix:
    print(row)

print("\nFinal Min value after min pooling:", min_val_from_threads)
print("Final Max value after max pooling:", max_val_from_threads)
