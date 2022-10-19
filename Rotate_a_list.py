# Rotating a list using python
test_list = [52,78,36,4,2]
print ("Original list : " + str(test_list))
test_list = [test_list[(i + 3) % len(test_list)]
			for i, x in enumerate(test_list)]
print ("List after left rotate by 3 : " + str(test_list))
test_list = [test_list[(i - 3) % len(test_list)]
			for i, x in enumerate(test_list)]
print ("List after right rotate by 3(back to original) : "+ str(test_list))
