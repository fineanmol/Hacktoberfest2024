def stockprice(price):
    minuptil = [0]*len(price)
    profit = [0]*len(price)
    minuptil[0] = price[0]
    for i in range(1,len(price)):
        minuptil[i] = min(price[i],minuptil[i-1])
        profit[i] = price[i] - minuptil[i]
    return max(profit)
print(stockprice([8,1,2,4,6,3]))
