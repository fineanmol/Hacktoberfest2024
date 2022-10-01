l, u, p, d = 0, 0, 0, 0
s = "we_lov3_h@ct0ber"
if (len(s) >= 8):
	for i in s:

		# counting lowercase alphabets in the given password
		if (i.islower()):
			l+=1		

		# counting uppercase alphabets in the given password
		if (i.isupper()):
			u+=1		

		# counting digits in the given password
		if (i.isdigit()):
			d+=1		

		# counting the mentioned special characters
		if(i=='@'or i=='$' or i=='_'):
			p+=1		
if (l>=1 and u>=1 and p>=1 and d>=1 and l+p+u+d==len(s)):
	print("Valid Password!")
else:
	print("Invalid Password")
