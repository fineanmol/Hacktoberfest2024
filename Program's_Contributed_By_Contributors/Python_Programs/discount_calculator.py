print("==============================")
print("Discount Calculator")
print("==============================")
hargaasli = int(input('Enter original price: '))
persendiskon = int(input('Enter discount percentage (%): '))

hitungdiskon = hargaasli * (persendiskon/100)
setelahdiskon = hargaasli - hitungdiskon

print("Total Price After discount" ,persendiskon,"% is",setelahdiskon)
