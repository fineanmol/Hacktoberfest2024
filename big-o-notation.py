# O(1) complete in constant time
def func_constant(values):
    print(values[0])

# O(n) linear time


def func_lin(lst):
    for val in lst:
        print(val)

# O(n^2) quadratic time


def func_quad(lst):
    for item_1 in lst:
        for item_2 in lst:
            print(item_1, item_2)
