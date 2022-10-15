#include <bits/stdc++.h>
using namespace std;
class process
{
public:
    int PNO, BT, WT, TT;
};
bool compare(process p1, process p2)
{
    return p1.BT < p2.BT;
}
int main()
{
    int n;
    cout << "Enter the number of processes:" << endl;
    cin >> n;
    process p[n];

    cout << "Enter the burst for each processes:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "PNO " << i << ": ";
        cin >> p[i].BT;
    }

    sort(p, p + n, compare);
    int sum = 0;

    p[0].WT = 0;
    for (int i = 1; i < n; i++)
    {
        p[i].WT = p[i - 1].BT + p[i - 1].WT;
        sum += p[i].WT;
    }
    int TT = 0;
    cout << "ProcessNum."
         << " "
         << "BurrTime"
         << " "
         << "WaitTime"
         << " "
         << "TurnAroundTime" << endl;
    for (int i = 0; i < n; i++)
    {
        p[i].TT = p[i].BT + p[i].WT;
        TT += p[i].TT;
        cout << i + 1 << "    " << p[i].BT << "    " << p[i].WT << "    " << p[i].TT << endl;
    }

    cout << "Average waiting time:" << (double)sum / n << endl;
    cout << "Average turn around time:" << (double)TT / n << endl;
}