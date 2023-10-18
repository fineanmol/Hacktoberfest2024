#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    
    // map order elements in ascending order
    // if we want to use without sorting then we should use unordered map
    // key of the map needs to be unique
    map <string, string> mydict;
    mydict.insert(pair<string, string>("apple", "der Apfel"));
    mydict.insert(pair<string, string>("banana", "Banane"));    
    mydict.insert(pair<string, string>("orange", "die Orange, die Apfelsine"));      
    mydict.insert(pair<string, string>("strawberry", "Die Erdbeere"));

    mydict["strawberry"]= "die Erdbeere";
   // mydict.clear();  // clears elements from the map
    cout << mydict.size()<< endl;

    for(auto pair: mydict){
        cout << pair.first  << "-" << pair.second << endl;
    }
    system("pause>0");
}