/*Monu has created an elevated roof. he wants to know how much water can he save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that he can save.

Explanation for the Sample input Testcase:
Elevation Map
0 2 1  3 0 1 2 1 2 1

So the total units of water he can save is 5 units

Input Format
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints
1 <= N <= 10^6

Output Format
Print a single integer containing the maximum unit of waters he can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int leftmax[n];
    leftmax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(leftmax[i - 1], arr[i]);
    }

    int rightmax[n];
    rightmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(rightmax[i + 1], arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(leftmax[i], rightmax[i]) - arr[i];
    }
    cout << sum;
    return 0;
}
