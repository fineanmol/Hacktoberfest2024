#include<iostream>
using namespace std;

float Area(float r){
    const pi = 3.143;
    return pi*r*r;
}

int main() {
    float r, Area;
    cin>>r;
    Area = areaFind(r);
    cout << "Area of Circle is :" << Area;
    return 0;
}
