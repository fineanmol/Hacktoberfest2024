File Handling through C++ Classes
In C++, files are mainly dealt by using three classes fstream, ifstream, ofstream available in fstream headerfile. 
ofstream: Stream class to write on files 
ifstream: Stream class to read from files 
fstream: Stream class to both read and write from/to files. 

1. passing file name in constructor at the time of object creation 
2. using the open method 

For e.g.  
Open File by using constructor 
ifstream (const char* filename, ios_base::openmode mode = ios_base::in); 
ifstream fin(filename, openmode) by default openmode = ios::in 
ifstream fin(“filename”);

Open File by using open method 
Calling of default constructor 
ifstream fin;
fin.open(filename, openmode) 
fin.open(“filename”); 
 

Modes :  

Member Constant	Stands For	Access
in *	input	File open for reading: the internal stream buffer supports input operations.
out	output	File open for writing: the internal stream buffer supports output operations.
binary	binary	Operations are performed in binary mode rather than text.
ate	at end	The output position starts at the end of the file.
app	append	All output operations happen at the end of the file, appending to its existing contents.
trunc	truncate	Any contents that existed in the file before it is open are discarded.
Default Open Modes :  

ifstream	ios::in
ofstream	ios::out
fstream	ios::in | ios::out
Problem Statement : To read and write a File in C++. 
Examples: 

Input : 
Welcome in Manishkumar. Best way to learn things.
-1
Output : 
Welcome in Manishkumar. Best way to learn things.
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Below is the implementation by using ifsream & ofstream classes.  


/* File Handling with C++ using ifstream & ofstream class object*/
/* To write the Content in File*/
/* Then to read the content of file*/
#include <iostream>
 
/* fstream header file for ifstream, ofstream,
  fstream classes */
#include <fstream>
 
using namespace std;
 
// Driver Code
int main()
{
    // Creation of ofstream class object
    ofstream fout;
 
    string line;
 
    // by default ios::out mode, automatically deletes
    // the content of file. To append the content, open in ios:app
    // fout.open("sample.txt", ios::app)
    fout.open("sample.txt");
 
    // Execute a loop If file successfully opened
    while (fout) {
 
        // Read a Line from standard input
        getline(cin, line);
 
        // Press -1 to exit
        if (line == "-1")
            break;
 
        // Write line in file
        fout << line << endl;
    }
 
    // Close the File
    fout.close();
 
    // Creation of ifstream class object to read the file
    ifstream fin;
 
    // by default open mode = ios::in mode
    fin.open("sample.txt");
 
    // Execute a loop until EOF (End of File)
    while (fin) {
 
        // Read a Line from File
        getline(fin, line);
 
        // Print line in Console
        cout << line << endl;
    }
 
    // Close the file
    fin.close();
 
    return 0;
}
Below is the implementation by using fstream class. 


/* File Handling with C++ using fstream class object */
/* To write the Content in File */
/* Then to read the content of file*/
#include <iostream>
 
/* fstream header file for ifstream, ofstream,
   fstream classes */
#include <fstream>
 
using namespace std;
 
// Driver Code
int main()
{
    // Creation of fstream class object
    fstream fio;
 
    string line;
 
    // by default openmode = ios::in|ios::out mode
    // Automatically overwrites the content of file, To append
    // the content, open in ios:app
    // fio.open("sample.txt", ios::in|ios::out|ios::app)
    // ios::trunc mode delete all content before open
    fio.open("sample.txt", ios::trunc | ios::out | ios::in);
 
    // Execute a loop If file successfully Opened
    while (fio) {
 
        // Read a Line from standard input
        getline(cin, line);
 
        // Press -1 to exit
        if (line == "-1")
            break;
 
        // Write line in file
        fio << line << endl;
    }
 
    // Execute a loop until EOF (End of File)
    // point read pointer at beginning of file
    fio.seekg(0, ios::beg);
 
    while (fio) {
 
        // Read a Line from File
        getline(fio, line);
 
        // Print line in Console
        cout << line << endl;
    }
 
    // Close the file
    fio.close();
 
    return 0;
}

//end of program
