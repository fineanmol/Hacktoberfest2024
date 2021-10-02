def quick_sort(array):
    if len(array) < 2:
        return array
    pivot_element = array[int(len(array)/2)]
    lower_elements = [i for i in array if i < pivot_element]
    higher_elements = [i for i in array if i > pivot_element]
    return quick_sort(lower_elements)+[pivot_element]+quick_sort(higher_elements)
