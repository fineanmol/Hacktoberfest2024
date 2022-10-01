#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#define MAX_N 5001
#define MAX_E 25000001
#define INF 987654321
using namespace std;
typedef long long lld;

int v, e;
//Code_by_Aman1109
int dist[MAX_N];
struct Edge
{
    int x, y, weight;
};
Edge E[MAX_N];

inline int BellmanFord(int source)
{
    for (int i=0;i<v;i++)
    {
        if (i == source) dist[i]=0;
        else dist[i] = INF;
    }
    bool done = false;
    for (int i=0;!done&&i<v;i++)
    {
        done = true;
        for (int j=0;j<e;j++)
        {
            int so = E[j].x;
            int de = E[j].y;
            if (dist[so] + E[j].weight < dist[de])
            {   
                dist[de] = dist[so] + E[j].weight;
                done=false;
            }
        }
    }
    if (!done) return -1; 
    return 0;
}

int main()
{
    v = 4, e = 8;
    
    E[0].x = 0, E[0].y = 1, E[0].weight = 5;
    E[1].x = 1, E[1].y = 0, E[1].weight = 5;
    
    E[2].x = 1, E[2].y = 2, E[2].weight = 5;
    E[3].x = 2, E[3].y = 1, E[3].weight = 5;
    
    E[4].x = 2, E[4].y = 3, E[4].weight = 5;
    E[5].x = 3, E[5].y = 2, E[5].weight = 5;
    
    E[6].x = 3, E[6].y = 1, E[6].weight = 6;
    E[7].x = 1, E[7].y = 3, E[7].weight = 6;
    BellmanFord(0);
    printf("Code_by_Aman1109");
    cout<<endl;
    printf("%d\n",dist[3]);
    
    return 0;
}
