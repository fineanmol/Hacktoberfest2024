#include <iostream>

int main(){

    // float month1 = 100;
    // float month2 = 200;
    // float month3 = 10;
    // float month4 = 300;
    // float month5 = 250;
    // float month6 = 100;
    
    // Array stores data in continuous chunks of memory ie we cannot add elements in arrays 
    // so we have to make bigger array and store data according to our need which is required by us or we can use dynamic arrays
    // it is very fast data structure
    
    int month;
    std::cin >> month;
    float monthsArray[100], total=0;

    for(int i=0; i<month; i++){
        std::cout << "Enter amount for month " << i+1 << ":";
        std::cin >> monthsArray[i];
        total+= monthsArray[i]; 
    }


    //float total = monthsArray[0] + monthsArray[1] + monthsArray[2]  + monthsArray[3] + monthsArray[4] + monthsArray[5];
    float avg =  total/month;
    float inTwoYears = avg * 24;

    std::cout << "total: " << total << std:: endl; 
    std::cout << "Average: " << avg << std:: endl; 
    std::cout << "in 2 years: " << inTwoYears << std:: endl; 


    
    system("pause>0");
}