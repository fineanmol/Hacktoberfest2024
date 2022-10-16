#include <iostream>
using namespace std;

// membuat class kotak
class Kotak {
	public:
		// Atribut
		double panjang;
		double lebar;
		double tinggi;
		
		// Konstruktor
		Kotak(){
			panjang=10;
			lebar=5;
			tinggi=5;
		}
		// Parameter
		Kotak(int p,int l, int t){
			panjang=p;
			lebar=l;
			tinggi=t;
		}
		
		// Method, bukan constructor
		int hitungVolume(){
			return panjang*lebar*tinggi;
		}
		
		int hitungLuas(){
			return panjang*lebar;
		}
		
		int hitungKeliling(){
			return 2*(panjang+lebar);
		}
};

int main(){
	// Kelas objek parameter
	Kotak kotakku(10,10,5);
	
	cout << "Luas kotak adalah: " << kotakku.hitungLuas() << endl;
	cout << "Keliling kotak adalah: " << kotakku.hitungKeliling() << endl;
	cout << "Volume kotak adalah: " << kotakku.hitungVolume() << endl;
}
