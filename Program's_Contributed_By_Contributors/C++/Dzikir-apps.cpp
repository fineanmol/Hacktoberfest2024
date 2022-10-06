/*
 اللَّهُمَّ رَبَّ النَّاسِ أَذْهِبِ الْبَأْسَ اشْفِ أَنْتَ الشَّافِي لَا شَافِيَ إلَّا أَنْتَ شِفَاءً لَا يُغَادِرُ سَقْمًا
 Luhud trisnyawati bin fulan.
----


*/

#include <iostream>
#include <string>
#include <iomanip>

void HeadProg(){ 
std::cout<<R"(
██████╗░███████╗██╗██╗░░██╗██╗██████╗░
██╔══██╗╚════██║██║██║░██╔╝██║██╔══██╗
██║░░██║░░███╔═╝██║█████═╝░██║██████╔╝
██║░░██║██╔══╝░░██║██╔═██╗░██║██╔══██╗
██████╔╝███████╗██║██║░╚██╗██║██║░░██║
╚═════╝░╚══════╝╚═╝╚═╝░░╚═╝╚═╝╚═╝░░╚═╝
)"<<std::endl;
}

std::string checkValiInput(){
  std::string numForLooping;
  std::cout<<"Ingin berapa Dzikir hari ini\t: ";
  std::cin>>numForLooping;
  for (int i=0; i<numForLooping.length(); i++){
    if ((numForLooping[i]>='a' && numForLooping[i]<='z')
        || (numForLooping[i]>='A' && numForLooping[i]<='Z')) {
      std::cout<<"Input harus berupa Angka!"<<std::endl;
      return checkValiInput();
    }
  }
  return numForLooping;
}

int StringToInteger(const std::string& str) {
  int tempConverter = 0;
  int valueChar;
  for (int i=0; i<str.length(); i++) {
    tempConverter *= 10;
    valueChar = str[i] - '0';
    tempConverter = (tempConverter + valueChar);
  }
  return tempConverter;
}

int main() {
 Op:
	HeadProg();
	char u;
	std::string input;
  std::string ResultValidation;
  system("clear");
  int finalOutput;
  ResultValidation = checkValiInput();
  finalOutput = StringToInteger(ResultValidation);
  for(int i=0; i<finalOutput; i++){
    std::cout<<(i+1)<<". Masukan kalimat Dzikir\t: ";
    std::cin>>input;
  }
  std::cout<<"Dzikir selesai dengan kalimat "<<input<<" dengan total sejumlah "<<finalOutput<<std::endl;
	std::cout<<"Apakah anda ingin mengulang kembali [Y/n]: ";
	std::cin>> u;
	if(u=='y' || u=='Y'){
		goto Op;
	}
	else{
		std::cout<<"Program berhenti, semoga selalu dalam lindungan-Nya.";	
	}
}

