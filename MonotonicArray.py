# Check if given array is Monotonic
def isMonotonic(A):
    x, y = [], []
    x.extend(A)
    y.extend(A)
    x.sort()
    y.sort(reverse=True)
    if(x == A or y == A):
        return True
    return False


# Driver program
A = [6, 5, 4, 4]

# Print required result
print(isMonotonic(A))
