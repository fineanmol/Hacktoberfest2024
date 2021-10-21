s = 'MXCIV'

result = 0
last = 0
dic = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}

for i in reversed(s):
    if dic[i] >= last:
        result += dic[i]
    else:
        result -= dic[i]
        
    last = dic[i]

print(result)