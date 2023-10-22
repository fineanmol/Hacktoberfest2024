/*
Problem statement: There are N people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.
Given the total number of persons N and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. The task is to choose the person in the initial circle that survives.
*/

#include <bits/stdc++.h>
using namespace std;

int Josephus(int N, int k)
{
    int i = 1, ans = 0;
    while (i <= N)
    {
        ans = (ans + k) % i;
        i++;
    }
    return ans + 1;
}

int main()
{
    int N = 14, k = 2;
    cout << Josephus(N, k) << endl;
    return 0;
}
