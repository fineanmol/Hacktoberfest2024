# Python3 code to demonstrate working of
# Sort Dictionary ignoring Key
# Using next() + sorted() + insert()

# initializing dictionary
test_dict = {45 : 'is', 12 : 'gfg', 100 : 'best',
			"*-*" : "stray", 150 : 'geeks', 120 : 'for'}

# printing original dictionary
print("The original dictionary is : " + str(test_dict))

# strary key
stray_key = '*-*'

# Sort Dictionary ignoring Key
# Using next() + sorted() + insert()
temp = next(idx for idx, val in enumerate(test_dict) if val == stray_key)
idx = sorted(ele for ele in test_dict if ele != stray_key)
idx.insert(temp, stray_key)
res = {ele: test_dict[ele] for ele in idx}

# printing result
print("The dictionary after sorting : " + str(res))
