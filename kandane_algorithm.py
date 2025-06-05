# defining the function to find the maximum subarray sum  
def max_Subarray_Sum(my_array, array_size):  
    # assigning the variables  
    maxTillNow = my_array[0]  
    maxEnding = 0  
      
    # using the for-loop  
    for n in range(0, array_size):  
        maxEnding = maxEnding + my_array[n]  
        # using the if-elif-else statement  
        if maxEnding < 0:  
            maxEnding = 0  
          
        elif (maxTillNow < maxEnding):  
            maxTillNow = maxEnding  
              
    return maxTillNow  
# defining the array  
my_array = [-2, -3, 4, -1, -2, 5, -3]  
# printing the maximum subarray sum for the users  
print("Maximum Subarray Sum:", max_Subarray_Sum(my_array, len(my_array)))  
