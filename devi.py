tugas = int(input("Masukkan Nilai Tugas: "))

mid = int(input("Masukkan Nilai Mid: "))

uas = int(input("Masukkan Nilai Uas: "))

nilai_akhir = 0.2 * tugas + 0.3 * mid + 0.5 * uas

# Menampilkan hasil operasi
print(f"Nilai akhir : {nilai_akhir}")

if nilai_akhir > 85:
    print("Nilai anda = A")
elif nilai_akhir > 70 and nilai_akhir < 86:
    print("Nilai anda = B")
elif nilai_akhir > 55 and nilai_akhir < 71:
    print("Nilai anda = C")
elif nilai_akhir > 40 and nilai_akhir < 56 :
    print("Nilai anda = D")
else :
    print("Nilai anda = E")

