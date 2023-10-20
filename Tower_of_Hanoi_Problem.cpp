#include <iostream>
using namespace std;


void tower_of_hanoi(int n, char Source, char Auxillar, char Destination)
{
    if (n == 1) {
        cout << "Move Disk " << n << " from " << Sourcd << " to " << Destination << endl;
        return;
    }

    tower_of_hanoi(n - 1, Source, Destination, Auxillary);
    cout << "Move Disk " << n << " from " << Source << " to " << Destination << endl;
    tower_of_hanoi(n - 1, Auxillary, Source, Destination);
}

//main program
int main()
{
    int n;

    cout << "Enter no. of disks:";
    cin >> n;
    //calling the TOH
   tower_of_hanoi(n, 'A', 'B', 'C');

    return 0;
}
