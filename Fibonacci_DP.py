FibArray = [0, 1]
 
def fibonacci(n):

    if n < 0:
        print("Incorrect input")
       
    elif n < len(FibArray):
        return FibArray[n]
    else:       
        FibArray.append(fibonacci(n - 1) + fibonacci(n - 2))
        return FibArray[n]
 
print(fibonacci(9))
