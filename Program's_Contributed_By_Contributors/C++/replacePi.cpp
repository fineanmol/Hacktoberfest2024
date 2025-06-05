#include <iostream>
using namespace std;

void replacePi(char str[], int start);
int strlen(char str[]);

int main() {

    char c[1000];

    cin.getline(c,1000);

    replacePi(c,0);

    for(int i=0; i<strlen(c); i++){
        cout<<c[i];
    }
    return 0;
}

int strlen(char str[]){
    int size = 0;
    
    while(str[size] != '\0'){
        size++;
    }
    
    return size;
}


void replacePi(char str[], int start){

    if (str[start] == '\0' || str[start + 1] == '\0') {
        return;
    }
 
    replacePi(str, start + 1);
 
    if (str[start] == 'p' && str[start + 1] == 'i') {
        for (int i = strlen(str); i >= start + 2; i--) {
            str[i + 2] = str[i];
        }
        str[start] = '3';
        str[start + 1] = '.';
        str[start + 2] = '1';
        str[start + 3] = '4';
    }
}