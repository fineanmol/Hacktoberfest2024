#include <iostream>

// Base class 1
class Base1 {
public:
    void display1() {
        std::cout << "Base1 Display" << std::endl;
    }
};

// Base class 2
class Base2 {
public:
    void display2() {
        std::cout << "Base2 Display" << std::endl;
    }
};

// Derived class inheriting from both Base1 and Base2
class Derived : public Base1, public Base2 {
public:
    void displayDerived() {
        std::cout << "Derived Display" << std::endl;
    }
};

int main() {
    Derived derivedObj;
    derivedObj.display1(); // Call method from Base1
    derivedObj.display2(); // Call method from Base2
    derivedObj.displayDerived(); // Call method from Derived
    return 0;
}
