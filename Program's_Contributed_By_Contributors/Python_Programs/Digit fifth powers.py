#Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
sum=0
final_sum=0
for x in range(2,1000000):
    sum=0
    a=str(x)
    for y in a:
        b=int(y)**5
        sum+=b
    if x == sum:
        final_sum+=x
        print(x)
print(final_sum)
