#include <iostream>
using namespace std;

void removeX(char input[]);

int main() {

    char s[100];
    cin.getline(s,100);

    removeX(s);

    int i=0;
    while(s[i] != '\0'){
        cout<<s[i];
        i++;
    }

    return 0;
}

void removeX(char input[]) {
    // Write your code here
	if(input[0]=='\0'){
        return;
    }
    
    removeX(input+1);
    
    if(input[0] == 'x'){
        int i=0;
        while(input[i] != '\0'){
            input[i] = input[i+1];
            i++;
        }
    }
}