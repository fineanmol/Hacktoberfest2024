import statistics
import numpy as np

# fungsi untuk mengurutkan bilangan
def sort(num):
	num.sort()
	print("Urutkan angka: ", end = "")
	for i in num:
		if i < len(num):
			print(i, end=", ")
		else:
			print(i)

# fungsi untuk menghitung rata-rata
def average(num):
	result = sum(num) / len(num)
	print("Rata-rata: ", round(result, 2))

# fungsi untuk menghitung median
def median(num):
	print("Median: ", statistics.median(num))

# fungsi untuk menghitung prekalian semua bilangan
def multiply(num):
	result = np.prod(num)
	print("Hasil kali semua bilangan: ", result)

num = []
i = 0;

print("============= PROGRAM INPUT BILANGAN ===============")
amount_num = int(input("Berapa banyak bilangan yang ingin dihitung?: "))

while i < amount_num :
	num_input = int(input("Bilangan ke - %d: " %(i+1)))
	num.append(num_input)
	i += 1

print("====================================================")
sort(num)
average(num)
median(num)
multiply(num)
