def isPalindrome(s):
	return s == s[::-1]

s = input("Enter the string: \n")
ans = isPalindrome(s)

if ans:
	print("Yes")
else:
	print("No")
