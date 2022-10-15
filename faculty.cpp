#include <iostream>

int faculty(int b){
if(b==0 || b==1){
return 1;}
int d = 1;
for(int i = 1; i<=b; i++){
d = d*i;
}
return d;
}

int main(){
int a;
std::cout << "Number: ";
std::cin >> a;

std::cout << faculty(a) << std::endl;
return 0;
}
