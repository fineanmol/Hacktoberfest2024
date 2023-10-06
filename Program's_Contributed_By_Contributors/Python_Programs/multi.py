import threading
import pandas as pd

# Load the Iris dataset
iris_df = pd.read_csv('Iris.csv')

# Locks for synchronization
largest_lock = threading.Lock()
smallest_lock = threading.Lock()

# Output file paths
output_file1 = 'largest_flowers.txt'
output_file2 = 'smallest_flowers.txt'

# Function for Thread 1 - Writing details of largest three flowers to output file 1
def write_largest_flowers():
    # Acquire the lock
    largest_lock.acquire()

    # Open output file 1 in append mode
    with open(output_file1, 'a') as f:
        # Find the largest three flowers based on petal length for each variant
        largest_flowers = iris_df.groupby('Species').apply(lambda x: x.nlargest(1, 'PetalLengthCm')).reset_index(drop=True)
        # Write the details of largest flowers to the file
        f.write(largest_flowers.to_string(index=False))
        f.write('\n\n')

    # Release the lock
    largest_lock.release()

# Function for Thread 2 - Writing details of smallest three flowers to output file 2
def write_smallest_flowers():
    # Acquire the lock
    smallest_lock.acquire()

    # Open output file 2 in append mode
    with open(output_file2, 'a') as f:
        # Find the smallest three flowers based on petal length for each variant
        smallest_flowers = iris_df.groupby('Species').apply(lambda x: x.nsmallest(1, 'PetalLengthCm')).reset_index(drop=True)
        # Write the details of smallest flowers to the file
        f.write(smallest_flowers.to_string(index=False))
        f.write('\n\n')

    # Release the lock
    smallest_lock.release()

# Create and start Thread 1
thread1 = threading.Thread(target=write_largest_flowers)
thread1.start()

# Create and start Thread 2
thread2 = threading.Thread(target=write_smallest_flowers)
thread2.start()

# Join both threads to wait for their completion
thread1.join()
thread2.join()

print("Details of largest and smallest flowers written to the output files.")