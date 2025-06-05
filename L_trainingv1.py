# defing the function to return the nth element of the Fibonacci Series  
def Fibonacci_series(x):   
    # assiging the variables  
    m = 0  
    n = 1  
    # using the if-elif-else conditional statements  
    if x < 0:  
        print("Wrong input")   
    elif x == 0:  
        return m   
    elif x == 1:   
        return n  
    else:  
        # using the for-loop   
        for i in range(2, x + 1):   
            o = m + n  
            m = n   
            n = o   
        return n   
# printing the twelveth term of the Fibonacci Series  
print("12th element of the Fibonacci Series:", Fibonacci_series(12))  
