#include <bits/stdc++.h>
using namespace std;

struct MST
{
    int vertex;	// the point with parent
    bool visit;
};
int matrix[n][n];	// store initial graph
MST point[n];		// answer
int dis[n];		// store the minimum side

// initial(with the start vertex 3)
void set(int v){
    for(int i=0; i<n; i++)
        fill_n(matrix[i], n, inf);
    matrix[1][3] = matrix[3][1] = 4;
    /*...etc...*/

    // start from vertex 3
    for(int i=0; i<n; i++)
        point[i].vertex = v, point[i].visit = true;

    // initial other array to infinite
    fill(dis, dis+n, inf);
}

void solve(int now){
    // if all the point are finished
    int check = n;
    while(!point[--check].visit);
    if(!check)
        return;

    // else recursive
    dis[now] = inf;
    point[now].visit = false;
    int next = 0;
   for(int i=1; i<n; i++)
        if(point[i].visit){
            if(dis[i] > matrix[now][i])
                dis[i] = matrix[now][i], point[i].vertex = now;
            next = dis[next] > dis[i] ? i : next;
        }
    solve(next);
}

int main(){
    int start = 3;  // start vertex
    set(start);     // initial
    solve(start);   // prim's algorithm

    return 0;
}
