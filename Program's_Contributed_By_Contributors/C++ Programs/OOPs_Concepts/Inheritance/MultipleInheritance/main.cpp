#include <iostream>
using namespace std;

/*            
          Multiple Inheritance 


    - It is type of Inheritance in which child/derived class get inherited by multiple base/parent classes.

    eg :- 

      Mammal  WinngedAnimal
          \  /
          Bat


      - Bat is A Mammal 
      - Bat is a WinngedAnimal
*/

// class A : base class
class Mammal{
  public:
    Mammal(){
      cout << "Mammal's constructor has been called.\n";
    }
};


// class B : base class
class WinngedAnimal{
  public:
  WinngedAnimal(){
    cout << "WinngedAnimal's constructor has been called.\n";
  }
};


// Class C : derives from A and B 
class Bat : public Mammal, public WinngedAnimal{
  public:
  Bat(){
    cout << "Bat constructor has been called.\n";
  }
};


int main(int argc, char *argv[]){
  // When we create object of c than A and B cal
  cout << "Multiple Inheritance : ";
  Bat batObj;
  return 0;
}
