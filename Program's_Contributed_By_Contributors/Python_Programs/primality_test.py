from numba import jit
import sys
@jit(nopython=True)
def isprime(n):
	if n==2:return 1
	if n%2==0:return 0
	for i in range(3,int(n**0.5)+1,2):
		if n%i==0:return 0
	return 1
def main():
	n=float(sys.argv[1])
	print(isprime(n))
if __name__=="__main__":main()
