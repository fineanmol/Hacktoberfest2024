def sort_array(source_array):
    odd_val = sorted([i for i in source_array if i %2 != 0])
    

        
    odd_sort = [ odd_val[(len(odd_val)-1) - odd_val.index(y)]  if y in odd_val else y for y in source_array  ]

        
    return odd_sort
    
print(sort_array([11,10,9, 8, 7, 6, 5, 4, 3, 2, 1, 0]))