def fibonacci(n):
  if n <= 0:
    return

  if n == 1:
    return 0

  if n == 2:
    return 1

  return fibonacci(n - 1) + fibonacci(n - 2)

n = int(input("Enter the nth element: "))
print(fibonacci(n))