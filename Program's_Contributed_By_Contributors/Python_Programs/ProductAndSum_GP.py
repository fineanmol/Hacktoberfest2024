def productOfGP(a, r, n):
    return pow(a, n) * pow(r, n * (n - 1) // 2)
 
def sumOfGP(a, r, n):
    return (a*(1-pow(r,n)))/(1-r)

a = 1; r = 2
N = 5
 
print(productOfGP(a, r, N))
print(sumOfGP(a, r, N))

 