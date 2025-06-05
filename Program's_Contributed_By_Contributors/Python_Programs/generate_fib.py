# Simple Program to generate Fibonacci series upto n terms
def generateFib(n):
    ft = 0
    st = 1 
    count = 1 
    while count <= n:
        print(f'Term {count} : {ft}')
        nt = ft + st
        ft = st
        st = nt 
        count = count + 1

if __name__ == '__main__':
    n = int(input("Enter the value of n to generate fibonacci series: "))
    generateFib(n)
