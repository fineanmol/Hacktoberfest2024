#input
x=int(input("Masukkan Nilai Pertama : "))
y=int(input("Masukkan Nilai Kedua : "))

#bitwise AND
z = x & y
print("\nBitwise AND")
print("Nilai :",x)
print("Nilai :",y)
print("----------(&)")
print("Hasil :",z)

#bitwise OR
z = x | y
print("\nBitwise OR")
print("Nilai :",x)
print("Nilai :",y)
print("----------(|)")
print("Hasil :",z)

#bitwise NOT
z = ~x
print("\nBitwise NOT")
print("Nilai :",x)
print("----------(~)")
print("Hasil :",z)

#bitwise XOR
z = x ^ y
print("\nBitwise XOR")
print("Nilai :",x)
print("Nilai :",y)
print("----------(^)")
print("Hasil :",z)

#bitwise Right Shift
z = x >> y
print("\nBitwise Right Shift")
print("Nilai :",x)
print("Nilai :",y)
print("----------(>>)")
print("Hasil :",z)

#bitwise Left Shift
z = x << y
print("\nBitwise Left Shift")
print("Nilai :",x)
print("Nilai :",y)
print("----------(<<)")
print("Hasil :",z)