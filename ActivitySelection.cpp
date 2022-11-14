#include <iostream>
#include <algorithm>
using namespace std;
struct Activitiy
{
    int start, end;
};
bool comp(Activitiy act1, Activitiy act2)
{
    return (act1.end < act2.end);
}
void maxActivity(Activitiy act[], int n)
{
    sort(act, act + n, comp); // sort activities using compare function

    cout << "Selected Activities are: " << endl;
    int i = 0; // first activity as 0 is selected
    cout << "Activity: " << i << " , Start: " << act[i].start << " End: " << act[i].end << endl;
    for (int j = 1; j < n; j++)
    { // for all other activities
        if (act[j].start >= act[i].end)
        { // when start time is >= endtime, print the activity
            cout << "Activity: " << j << " , Start: " << act[j].start << " End: " << act[j].end << endl;
            i = j;
        }
    }
}
int main()
{
    Activitiy actArr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = 6;
    maxActivity(actArr, n);
    return 0;
}