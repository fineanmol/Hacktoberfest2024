#include <iostream>
#include <map>
#include <string>
#include <list>

using namespace std;

int main(){

    map<string, list<string>> pokedex;

    // adding elements

    list<string> pikaAttacks {"thunder", "iron tail", "quick attack"};
    list<string> charAttacks {"ember", "flame wheel", "tackle"};
    list<string> bulbaAttacks {"razor leaf", "wine whip", "solar beam"};

    pokedex.insert(pair<string, list<string>>("Pikachu", pikaAttacks));
    pokedex.insert(pair<string, list<string>>("Charmander", charAttacks));
    pokedex.insert(pair<string, list<string>>("Bulbasaur", bulbaAttacks));

    for(auto pair : pokedex){
        cout << pair.first << ": " ;
        for(auto attack : pair.second){
            cout << attack << ", ";
        }
        cout << endl;
    }   


    system("pause>0");
}

