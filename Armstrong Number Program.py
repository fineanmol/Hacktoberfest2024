
# Python Program to identify that it is a Armstrong Number or not

num = int(input('enter the nuber'))
s = 0
temp = num
while temp &amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;amp;gt; 0:
c = temp % 10
s += c**3
temp //= 10
if s == num:
print('armstrong number')
else:
print('not an armstrong number')

