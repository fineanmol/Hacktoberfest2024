def right_rotate(lst, k):
   
  rotated_lst = []
  
  for i in range (len(lst) - k, len(lst)):
    rotated_lst.append(lst[i])
    
  for i in range(len(lst) - k):
    rotated_lst.append(lst[i])
    
  return rotated_lst


lst = [56, 89, 90, 43, 67, 44]
print(right_rotate(lst, 2))
