s = input()
d = {}
l = 0
r = 0
c = 0
maxi = 0

while l < len(s):
    if s[l] not in d:
        d[s[l]] = 1  
        c += 1
        l += 1 
    else:
        r += 1  
        l = r  
        d = {}  
        c = 0 
    
    maxi = max(maxi, c)  

print(maxi)

