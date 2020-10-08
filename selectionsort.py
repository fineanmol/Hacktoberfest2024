def selection_sort(lst):
    min_no = 0
    n = 0
    while n < len(lst):
        
        for i in range(n , len(lst)-1):
            
            if lst[min_no] > lst[i+1]:
                min_no = i+1
        
        lst[n], lst[min_no] = lst[min_no], lst[n]
       
        n+=1
        min_no = n
    
    print(lst)
