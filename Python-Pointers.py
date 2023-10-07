import ctypes as ct

value_1 = ct.c_int(10)

# print(value_1)
# print(value_1.value)

ptr = ct.pointer(value_1)

# print(id(value_1))

# print(value_1)
# print(value_1.value)
# print(id(value_1.value))
# print(ptr.contents)
# print(ptr.contents.value)
# print(id(ptr.contents.value))

# print(value_1)
# print(value_1.value)

# float_value = ct.c_float(15.25)
# double_value = ct.c_double(85.69845)
#
# print(float_value,double_value)
# print(float_value.value,double_value.value)

ptr2 = ct.POINTER(ct.c_int)
print("Contents of Void Pointer : ",ptr2.contents)
ptr2.contents = value_1
print("Contents of void pointer after pointing it to a variable : ",ptr2.contents)
print("Value stored by Void Pointer : ",ptr2.contents.value)
# print("Boolean Value of Void Pointer",bool(void_ptr))


# null_ptr = ct.POINTER(ct.c_long)()

# print("Boolean Value of Null Pointer",bool(null_ptr))

# value_1 = ct.c_long(10)

# # Creating a void pointer
# # Not pointing to any ctypes variable using ptr 
# ptr = ct.pointer(value_1)

# # Printing to see what the void pointer currently holds
# print("Value before Changing : " ,value_1.value)

# # storing a value in ptr variable
# ptr.contents.value = 25

# # 
# print("Value after Changing : ", value_1.value)
