def findNumberOfTriangles(arr, n):
 
    # Count of triangles
    count = 0
 
    # The three loops select three
    # different values from array
    for i in range(n):
        for j in range(i + 1, n):
 
            # The innermost loop checks for
            # the triangle property
            for k in range(j + 1, n):
 
                # Sum of two sides is greater
                # than the third
                if (arr[i] + arr[j] > arr[k] and
                    arr[i] + arr[k] > arr[j] and
                        arr[k] + arr[j] > arr[i]):
                    count += 1
    return count
 
 
# Driver code
if __name__ == "__main__":
    arr = [10, 21, 22, 100, 101, 200, 300]
    size = len(arr)
 
    # Function call
    print("Total number of triangles possible is",
          findNumberOfTriangles(arr, size))
