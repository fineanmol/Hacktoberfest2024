#include <iostream>
#include <string>
using namespace std;

class Employee
{
    private:
        int id;
        string name;
        int age;
        float basicSalary, grossSalary;
    public:
        void getDetails();
        void displayDetails();
};

void Employee::getDetails()
{
    cout << "Enter iD: ";
    cin >> id;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter salary: ";
    cin >> basicSalary;
    grossSalary = basicSalary + 0.9*basicSalary;
}

void Employee::displayDetails()
{
    cout << "iD: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Basic Salary: " << basicSalary << endl;
    cout << "Gross Salary: " << grossSalary << endl;
    cout << endl;
}

int main()
{
    int numOfEmployees;
    cout << "Enter number of employees: ";
    cin >> numOfEmployees;

    if(numOfEmployees > 0){
        Employee emp[numOfEmployees];
        for(int i=0; i<numOfEmployees; i++){
            cout << "\nEnter details of employee " << i+1 << ":" << endl;
            emp[i].getDetails();
        }

        cout << "\n\nDetails of all employees: " << endl;
        for(int i=0; i<numOfEmployees; i++){
            emp[i].displayDetails();
        }
    }
    else{
        cout << "Please enter a valid number." << endl;
    }

    return 0;
}