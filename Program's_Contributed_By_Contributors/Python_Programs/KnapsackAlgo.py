###########################################################################################################
Knapsack Problem implemention in pythong-Pragati
###########################################################################################################
def knapsack(value, weight, capacity):
    """Return the maximum value of items that doesn't exceed capacity.
 
    value[i] is the value of item i and weight[i] is the weight of item i
    for 1 <= i <= n where n is the number of items.
 
    capacity is the maximum weight.
    """
    n = len(value) - 1
 
    # m[i][w] will store the maximum value that can be attained with a maximum
    # capacity of w and using only the first i items
    m = [[-1]*(capacity + 1) for _ in range(n + 1)]
 
    return knapsack_helper(value, weight, m, n, capacity)
 
 
def knapsack_helper(value, weight, m, i, w):
    """Return maximum value of first i items attainable with weight <= w.
 
    m[i][w] will store the maximum value that can be attained with a maximum
    capacity of w and using only the first i items
    This function fills m as smaller subproblems needed to compute m[i][w] are
    solved.
 
    value[i] is the value of item i and weight[i] is the weight of item i
    for 1 <= i <= n where n is the number of items.
    """
    if m[i][w] >= 0:
        return m[i][w]
 
    if i == 0:
        q = 0
    elif weight[i] <= w:
        q = max(knapsack_helper(value, weight,
                                m, i - 1 , w - weight[i])
                + value[i],
                knapsack_helper(value, weight,
                                m, i - 1 , w))
    else:
        q = knapsack_helper(value, weight,
                            m, i - 1 , w)
    m[i][w] = q
    return q
 
 
n = int(input('Enter number of items: '))
value = input('Enter the values of the {} item(s) in order: '
              .format(n)).split()
value = [int(v) for v in value]
value.insert(0, None) # so that the value of the ith item is at value[i]
weight = input('Enter the positive weights of the {} item(s) in order: '
               .format(n)).split()
weight = [int(w) for w in weight]
weight.insert(0, None) # so that the weight of the ith item is at weight[i]
capacity = int(input('Enter maximum weight: '))
 
ans = knapsack(value, weight, capacity)
print('The maximum value of items that can be carried:', ans)
