def max_sum_subarray(arr):
    size=len(arr)
    curr_sum=0
    max_so_far=arr[0]
    
    for i in range(0,size):
        curr_sum=curr_sum+arr[i]

        if(max_so_far<curr_sum):
            max_so_far=curr_sum
            
        if(curr_sum<0):
            curr_sum = 0
            

    print("Maximum sum Subarray is",max_so_far)
    

arr = [4,-3,-2,2,3,1,-2,3,1,-2,-3,6,-6,-6,-4,2,1]
max_sum_subarray(arr)    
