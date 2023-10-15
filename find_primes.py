def find_primes(num):
  primes = []
  for n in range(2, num):
    is_prime = True
    for x in range(2, n):
      if n % x == 0:
        is_prime = False
        break
    if is_prime:    
      primes.append(n)             
  return primes

number = int(input("Enter a number: "))
print(find_primes(number))
