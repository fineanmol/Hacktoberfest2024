#include <iostream>
using namespace std;

class bfs
{
private:
    int a[10][10];
    int n, *visit;

public:
    bfs();
    void read();
    void searchfrom();
    void print();
};
bfs::bfs()
{
    cout << "Breadth first Search" << endl;
    cout << "Enter the no of node:";
    cin >> n;
    visit = new int[n];
    for (int i = 0; i <= n; i++)
    {
        visit[i] = 0;
        for (int j = 0; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
}
void bfs::read()
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                cout << "\n Enter the valuesof:" << i << "," << j << "->";
                cin >> a[i][j];
            }
        }
    }
}
void bfs::print()
{
    cout << "\n Nodes are visited inthe order:" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == 0)
        {
            cout << i << "->";
            visit[i] = 1;
            searchfrom();
        }
    }
}

void bfs::searchfrom()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = k + 1; i <= n; i++)
        {
            if (visit[i] == 0 && a[k][i] != 0)
            {
                cout << i << "->";
                visit[i] = 1;
            }
        }
    }
}
int main()
{
    bfs b1;
    b1.read();
    b1.print();

    return 0;
}