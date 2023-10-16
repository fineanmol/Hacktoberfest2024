# Merge Sort in Python
def merge_sort(lst):
    size = len(lst)  # size of array
    if size > 1:
        mid = size // 2  # middle index

        # Splitting into two sub-lists
        left_lst = lst[:mid]  # left sub_list
        right_lst = lst[mid:]  # right sub_list

        # recursive call in both sub-lists
        merge_sort(left_lst)
        merge_sort(right_lst)

        i = 0  # index of left sub-list
        j = 0  # index of right sub-list
        k = 0  # index of merged list

        # Sorting & Merging when both sub-lists are non-empty
        while i < len(left_lst) and j < len(right_lst):
            if left_lst[i] < right_lst[j]:
                lst[k] = left_lst[i]
                i += 1

            else:
                lst[k] = right_lst[j]
                j += 1
            k += 1

        while i < len(left_lst):  # if right sub-list is empty
            lst[k] = left_lst[i]
            i += 1
            k += 1

        while j < len(right_lst):  # if left sub-list is empty
            lst[k] = right_lst[j]
            j += 1
            k += 1


# __main__

lst1 = []  # defining empty list
n = int(input("Enter Array Size : "))
print("Enter", n, "elements for array.......")
for y in range(n):
    x = int(input())
    lst1.append(x)

print("Before Sorting : ", lst1)
merge_sort(lst1)
print("After Sorting : ", lst1)
