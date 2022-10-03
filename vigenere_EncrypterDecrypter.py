alphabets='''ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz[]{}#%^^*+=_\|~<>€0987654321 £¥•- :;()$&@".,?'''
table=[]
spec_char='''[]{}#%^^*+=_\|~<>€0987654321 £¥•- :;()$&@".,?!'''

for n in range(97):
	a=alphabets[n:97]+alphabets[0:n]
	table.append(a)

index={}
for n in range(97):
	index.update({alphabets[n]:n})

def scan(word):
	word=word.lower()
	c=""
	spec_char='''[]{}#%^^*+=_\|~<>€0987654321 £¥•- :;()$&@".,?!'''
	for char in word:
		if char not in spec_char:
			c+=char
	return c



#table letter scanner

def f(x,y):
	x=int(x)
	y=int(y)
	return table[x][y]

#decrypter??????????????
def decrypt(msg,key):
	
	length_msg=len(msg)
	key_length=len(key)
	key*=(length_msg//key_length)+1
	key=key[:length_msg]
	
	c=""
	
	k=[]
	
	for n in range(length_msg):
		k.append(index[key[n]])
	
	res=[]
		
	for n in range(length_msg):
		for i in range(97):
			if table[k[n]][i] == msg[n]:
				res.append(table[i][0])
				
	result="".join(res)
	# print(result)
	return result



#encrypter???????????????

def encrypt(msg,key):
	spec_char='''[]{}#%^^*+=_\|~<>€0987654321 £¥•- :;()$&@".,?!'''
	length_msg=len(msg)
	key_length=len(key)
	key*=(length_msg//key_length)+1
	key=key[:length_msg]
	
	c=""
	
	m=[]
	k=[]
	
	for n in range(length_msg):
		m.append(index[msg[n]])
		k.append(index[key[n]])
	
	for n in range(length_msg):
		c+=f(m[n],k[n])
		
	# print(c)
	return c


a = encrypt("my name is mohammed ansah","mak")
print(a)
c = decrypt(a,"mak")
print(c)