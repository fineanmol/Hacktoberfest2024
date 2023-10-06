#include <iostream>  
using namespace std;  
  
// create base class1  
class student_detail   
{  
    // access specifier   
    protected:  
        int rno, sum = 0, i, marks[5];  
      
    // access specifier   
    public:  
        void detail()  
        {  
              
              
            cout << " Enter the Roll No: " << endl;  
            cin >> rno;  
  
            cout << " Enter the marks of five subjects " << endl;  
            // use for loop  
            for (i = 0; i < 5; i++)  
            {  
                cin >> marks[i];  
            }  
              
              
            for ( i = 0; i < 5; i++)  
            {  
                // store the sum of five subject  
            sum = sum + marks[i];  
            }  
        }  
              
};  
  
// create base class2  
class sports_mark   
{  
    protected:  
        int s_mark;   
      
    public:  
          
        void get_mark()  
        {  
            cout << "\n Enter the sports mark: ";  
            cin >> s_mark;  
            }     
};  
  
/* create a result as the child class to inherit functions of the parent class: student_detail and sports_mark.*/  
class result: public student_detail, public sports_mark  
{  
    int tot, avg;  
    public:  
          
        // create member function of child class  
        void disp ()  
        {  
            tot = sum + s_mark;  
            avg = tot / 6; // total marks of six subject / 6  
            cout << " \n \n \t Roll No: " << rno << " \n \t Total: " << tot << endl;  
            cout << " \n \t Average Marks: " << avg;  
        }  
};  
  
int main ()  
{  
    result obj; // create an object of the derived class  
  
    // call the member function of the base class  
    obj.detail();  
    obj.get_mark();  
    obj.disp();  
}  