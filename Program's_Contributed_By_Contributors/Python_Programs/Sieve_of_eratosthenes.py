'''Python program to print all primes smaller than or equal to n using Sieve of Eratosthenes
T.C. = O(n*log(log(n)))'''

def SieveOfEratosthenes(n, l):

	'''Create a boolean array "prime[0..n]" and initialize all entries it as true.
	A value in prime[i] will finally be false if i is Not a prime, else true.'''
 
	prime = [True for i in range(n)]
	p = 2
	while (p * p <=n):

		# If prime[p] is not
		# changed, then it is a prime
		if (prime[p] == True):

			# Update all multiples of p
			for i in range(p * p, n, p):
				prime[i] = False
		p += 1

	# Print all prime numbers
	for p in range(2, n):
		if prime[p]:
			l.append(p)
	print(l)


if __name__ == '__main__':
	n = int(input())
	print(f"Following are the prime numbers smaller than {n}"),
	l = []
	SieveOfEratosthenes(n, l)
