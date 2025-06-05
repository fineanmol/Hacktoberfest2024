#Program to find a pair of numbers with given sum.
def pairSum(lst, S):
    lst1 = lst.copy()
    a = False
    for i in lst:
        x = S-i
        lst1.remove(i)
        if x in lst1:
            print(i, ',', x)
            a = True
            break
    if a != True:
        print('Not found')


def pairSumDict(array, S):
    dict = {}
    for i in array:
        x = S-i
        if (x in dict):
            return [i, x]
        else:
            dict[i] = True
    return []

#Example:
lst = [3, 4, 5, -6, 12, 11, 10, 14]
S = 4
pairSum(lst, S)
print(pairSumDict(lst, S))
