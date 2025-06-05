"""
Returns second largest number in a list
"""

int_list = [10, 20, 45, 99, 9]
 
mx = max(int_list[0], int_list[1])
sec_max = min(int_list[0], int_list[1])
n = len(int_list)
for i in range(2,n):
    if int_list[i] > mx:
        sec_max = mx
        mx = int_list[i]
    elif int_list[i] > sec_max and \
        mx != int_list[i]:
        sec_max = int_list[i]
    elif mx == sec_max and \
        sec_max != int_list[i]:
          sec_max = int_list[i]
 
print("Second largest : ",sec_max)